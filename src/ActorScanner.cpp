#include "ActorScanner.h"

#include <chrono>

#include "Utilities/Ticker.h"
#include "Logger.h"
#include "SexlabStats.h"
#include "NPCScanner.h"
#include "Core.h"
#include "Config.h"
#include "NPCData.h"

namespace
{
    // Guards against stacking scan passes: set when a pass is queued, cleared when
	// it finishes. If a pass is still pending/running when the next tick fires, we
	// skip rather than pile a second pass onto the task queue.
	std::atomic<bool> g_scanInFlight{ false };

	void OnScanTick()
	{
		if (g_scanInFlight.exchange(true)) {
			return;  // previous pass hasn't finished yet
		}
		SKSE::GetTaskInterface()->AddTask([] { ActorScanner::RunScanPass(); });
	}

	// Function-local singleton avoids static init-order issues with the detached thread.
	Utilities::Ticker& ScanTicker()
	{
		static Utilities::Ticker ticker(OnScanTick, std::chrono::milliseconds(5000)); //Scan every 5 seconds
		return ticker;
	}
}

void ActorScanner::ForEachReferenceInRange(
    RE::TESObjectREFR *origin, 
    float radius, 
    std::function<RE::BSContainer::ForEachResult(RE::TESObjectREFR &ref)> callback)
{
    if (origin && radius > 0.0f) {
		const auto originPos = origin->GetPosition();
		auto* tesSingleton = RE::TES::GetSingleton();
		auto* interiorCell = tesSingleton->interiorCell;
		if (interiorCell) {
			interiorCell->ForEachReferenceInRange(originPos, radius, [&](RE::TESObjectREFR* a_ref) {
				return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
			});
		} else {
			if (const auto gridLength = tesSingleton->gridCells ? tesSingleton->gridCells->length : 0; gridLength > 0) {
				const float yPlus = originPos.y + radius;
				const float yMinus = originPos.y - radius;
				const float xPlus = originPos.x + radius;
				const float xMinus = originPos.x - radius;

				std::uint32_t x = 0;
				do {
					std::uint32_t y = 0;
					do {
						if (const auto cell = tesSingleton->gridCells->GetCell(x, y); cell && cell->IsAttached()) {
							if (const auto cellCoords = cell->GetCoordinates(); cellCoords) {
								const RE::NiPoint2 worldPos{ cellCoords->worldX, cellCoords->worldY };
								if (worldPos.x < xPlus && (worldPos.x + 4096.0f) > xMinus && worldPos.y < yPlus &&
									(worldPos.y + 4096.0f) > yMinus) {
									cell->ForEachReferenceInRange(originPos, radius, [&](RE::TESObjectREFR* a_ref) {
										return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
									});
								}
							}
						}
						++y;
					} while (y < gridLength);
					++x;
				} while (x < gridLength);
			}
		}
	} else {
		RE::TES::GetSingleton()->ForEachReference([&](RE::TESObjectREFR* a_ref) {
			return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
		});
	}
}


std::vector<RE::Actor*> ActorScanner::GetNearbyActors(RE::Actor* source, float radius)
{
	std::vector<RE::Actor*> nearbyActors;

	if (!source || !source->parentCell) {
		Log("<C++ ActorScanner> [GetNearbyActors] source cannot be null", LogType::Core, LoggingLevel::warning);
		return nearbyActors;
	}

	ForEachReferenceInRange(source, radius, [&](RE::TESObjectREFR& ref) {
		auto refBase = ref.GetBaseObject();
		auto actor = ref.As<RE::Actor>();
		if (actor && actor != source && !actor->IsDisabled() && !actor->IsChild() && !actor->IsDead() &&
			(ref.Is(RE::FormType::NPC) || (refBase && refBase->Is(RE::FormType::NPC)))) {
			nearbyActors.push_back(actor);
		}
		return RE::BSContainer::ForEachResult::kContinue;
	});

	return nearbyActors;
}

void ActorScanner::StartScanLoop()
{
    ScanTicker().Start();
    Log("<C++ ActorScanner> [StartScanLoop] Native scan loop started", LogType::Core);
}

void ActorScanner::StopScanLoop()
{
    ScanTicker().Stop();
    Log("<C++ ActorScanner> [StopScanLoop] Native scan loop stopped", LogType::Core);
}

static void RequestSexualityResolution(RE::Actor* akActor) {
    if(!akActor) {
        Log("<C++ ActorScanner> [RequestSexualityResolution] Received a NONE/Null Actor!", LogType::Core, LoggingLevel::error);
        return;
    }
    const RE::FormID formId = akActor->GetFormID();
    Sexlab::RequestSexuality(akActor, [formId](int sexualityScore) {
        // Callback fires on the VM thread; ProcessActor touches RegisteredFemaleMap
        // and faction data, so bounce back onto the main thread before doing anything.
        SKSE::GetTaskInterface()->AddTask([formId, sexualityScore] {
            auto* actor = RE::TESForm::LookupByID<RE::Actor>(formId);
            if (actor) {
                ProcessActor(actor, sexualityScore); 
            } else {
                Log("<C++ ActorScanner> [RequestSexualityResolution] Actor with FormID " + std::format("{:08X}", formId) + " no longer exists when sexuality callback was invoked.", LogType::Core, LoggingLevel::warning);
            }
        });
    });
}

void ActorScanner::RunScanPass()
{
    // Scan logic goes here. This is called periodically by the Ticker, which ensures
    // it runs on the main thread and doesn't overlap with itself.
    Log("<C++ ActorScanner> Running scan pass...", LogType::Core, LoggingLevel::info);

    //Always clear in-flight guard when this pass returns (via destructor)
    struct ClearGuard
    {
        ~ClearGuard() {
            g_scanInFlight = false; // Clear the in-flight flag when the pass finishes, even if an exception occurs
        }
    } clearGuard;

    RE::Actor* player = RE::PlayerCharacter::GetSingleton();
    if(!player || !player->parentCell) {
        Log("<C++ ActorScanner> [RunScanPass] Player character or parent cell is null! Aborting scan pass.", LogType::Core, LoggingLevel::warning);
        return;
    }

    if(auto* ui = RE::UI::GetSingleton(); ui && ui->GameIsPaused()) {
        Log("<C++ ActorScanner> [RunScanPass] Game is paused. Skipping scan pass.", LogType::Core, LoggingLevel::info);
        return;
    }

    float radius =  5120.0f; // Scan radius in game units (adjust as needed)

    const auto actors = GetNearbyActors(player, radius);
    for(auto* actor : actors) {
        //If sexlab is enabled, and we are using sexuality, we need to get sexuality score for actor. The callback of that fetch will then process the actor
        if(InstalledMods::Sexlab && Configuration::DefaultNPCShyness == ShySex::Sexuality) {
            RequestSexualityResolution(actor);
        } else {
            ProcessActor(actor, 0); // Pass 0 for sexuality score if not using sexuality-based shyness
        }
    }
}
