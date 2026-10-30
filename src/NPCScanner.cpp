#include "NPCScanner.h"
#include "NPCArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "NPCData.h"
#include "Logger.h"
#include "ArousedStats.h"
#include "SexlabStats.h"
#include "ModIntegration.h"

void ForEachReferenceInRange(RE::TESObjectREFR* origin, float radius, std::function<RE::BSContainer::ForEachResult(RE::TESObjectREFR& ref)> callback) {
	if (origin && radius > 0.0f) {
		const auto originPos = origin->GetPosition();
		auto* tesSingleton = RE::TES::GetSingleton();
		auto* interiorCell = tesSingleton->interiorCell;
		if (interiorCell) {
			interiorCell->ForEachReferenceInRange(originPos, radius, [&](RE::TESObjectREFR* a_ref) {
				return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
				});
		}
		else {
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
	}
	else {
		RE::TES::GetSingleton()->ForEachReference([&](RE::TESObjectREFR* a_ref) {
			return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
			});
	}
}

std::vector<RE::Actor*> GetActorsInRadiusOfPlayer(float radius) {
	Log("<C++ ActorScanner> [GetActorsInRadiusOfPlayer] Gathering Actors. Radius is " + std::to_string(radius));

	std::vector<RE::Actor*> nearbyActors;

	if (!Player || !Player->parentCell) {
		Log("<C++ ActorScanner> [GetActorsInRadiusOfPlayer] Warning: Source (Player or Player's Parent Cell) is null", Logger::LogType::Core, Logger::LoggingLevel::warning);
		return nearbyActors;
	}

	ForEachReferenceInRange(Player, radius, [&](RE::TESObjectREFR& ref) {
		auto actor = ref.As<RE::Actor>();
		if (actor && actor != Player && !actor->IsDisabled() && !actor->IsDead() && !actor->IsChild() && !actor->HasKeyword(ActorType_Creature)) {
			nearbyActors.push_back(actor);
		}
		return RE::BSContainer::ForEachResult::kContinue;
		});

	Log("<C++ ActorScanner> [GetActorsInRadiusOfPlayer] Finished Gathering Actors. Sending " + std::to_string((UINT16)nearbyActors.size()) + " actors to be processed!");

	return nearbyActors;
}

void ProcessActors(std::vector<RE::Actor*> ScannedActors) {
	Log("<C++ NPCScanner> [ProcessActors] Beginning to process actors! Processing " + std::to_string((UINT16)ScannedActors.size()) + " actors!");
	
	for (UINT16 ActorIndex = 0; ActorIndex < ScannedActors.size(); ++ActorIndex) {
		if (ScannedActors[ActorIndex] == nullptr) {
			Log("<C++ NPCScanner> [ProcessActors] Received a NONE/Null Actor!", Logger::LogType::Core, Logger::LoggingLevel::error);
			continue;
		}

		for (UINT8 FactionIndex = 0; FactionIndex < TotalFactions; ++FactionIndex) {
			if (ScannedActors[ActorIndex]->IsInFaction(AllFactions[FactionIndex]) == false) {
				ScannedActors[ActorIndex]->AddToFaction(AllFactions[FactionIndex], 0);
			}
		}

		std::string akName = ScannedActors[ActorIndex]->GetName();

		auto* actorBase = ScannedActors[ActorIndex]->GetActorBase();
		if (actorBase == nullptr) {
			Log("<C++ NPCScanner> [ProcessActors] Actor " + akName + " (" + std::format("{:08X}", ScannedActors[ActorIndex]->GetFormID()) + ") has no actor base; skipping.", Logger::LogType::Core, Logger::LoggingLevel::warning);
			continue;
		}

		INT8 MaxRoll = 100;

		if (Configuration::MotionFlashEnabled) {
			if (ScannedActors[ActorIndex]->IsSprinting()) {
				MaxRoll -= Configuration::SprintingMod;
			}
			else if (ScannedActors[ActorIndex]->IsRunning()) {
				MaxRoll -= Configuration::RunningMod;
			}
		}

		//NPC Rolls
		NPCChestCurtainRoll = Randomizer(1, MaxRoll);
		NPCPelvicCurtainRoll = Randomizer(1, MaxRoll);
		NPCAssCurtainRoll = Randomizer(1, MaxRoll);

		NPCCStringRoll = Randomizer(1, 100);
		NPCTopTransparentRoll = Randomizer(1, 100);
		NPCBottomTransparentRoll = Randomizer(1, 100);
		NPCBraTransparentRoll = Randomizer(1, 100);
		NPCUnderwearTransparentRoll = Randomizer(1, 100);
		NPCHotpantsTransparentRoll = Randomizer(1, 100);
		NPCShowgirlTransparentRoll = Randomizer(1, 100);

		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " ChestCurtainRoll " + std::to_string(ChestCurtainRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " PelvicCurtainRoll " + std::to_string(PelvicCurtainRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " AssCurtainRoll " + std::to_string(AssCurtainRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " CStringRoll " + std::to_string(CStringRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " TopTransparentRoll " + std::to_string(TopTransparentRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " BottomTransparentRoll " + std::to_string(BottomTransparentRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " BraTransparentRoll " + std::to_string(BraTransparentRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " UnderwearTransparentRoll " + std::to_string(UnderwearTransparentRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " HotpantsTransparentRoll " + std::to_string(HotpantsTransparentRoll), Logger::LogType::Core);
		Log("<C++ NPCScanner> [ProcessActors] " + static_cast<std::string>(ScannedActors[ActorIndex]->GetName()) + " ShowgirlTransparentRoll " + std::to_string(ShowgirlTransparentRoll), Logger::LogType::Core);

		if (actorBase->IsFemale() == false) {
			NPCMaleScan::NPCMaleAnalyze(ScannedActors[ActorIndex]);
		}
		else {
			// Cache OSLAroused's arousal into AND's ArousalFaction rank, mirroring the old
			// Papyrus AND_Core.UpdateArousalValue. We pull from OSLAroused (it owns the value)
			// rather than push, so the two systems don't fight. Runs on the main thread, so
			// the GetArousalExt first-query init path and AddToFaction are both safe here.
			// GetArousal returns -1 if OSLAroused is present but its Ext export can't be
			// resolved (older build); fall back to 0 rather than writing a negative rank.

			float arousalValue = 0.0f;

			if (InstalledMods::OSLAroused) {
				arousalValue = OSLAroused::GetArousal(ScannedActors[ActorIndex]);
			}
			else if (InstalledMods::SLOAroused) {
				arousalValue = (float)ModAPI::SLOArousedNG::GetActorArousal(ScannedActors[ActorIndex]);
			}

			const std::int8_t arousalRank = arousalValue > 0.0f ? static_cast<std::int8_t>(arousalValue) : std::int8_t{ 0 };
			
			//Only write to the faction if the rank has actually changed. (try and avoid potential data races from game ai/job threads accessing factions)
			if (ScannedActors[ActorIndex]->GetFactionRank(ArousalFaction, false) != arousalRank) {
				ScannedActors[ActorIndex]->AddToFaction(ArousalFaction, arousalRank);
			}

			NPCFemaleScan::NPCFemaleAnalyze(ScannedActors[ActorIndex]);

			float currentGameTime = GameCalendar->GetCurrentGameTime();

			if (RegisteredFemaleMap.count(ScannedActors[ActorIndex]->GetFormID()))
			{
				Log("<C++ NPCScanner> [ProcessActors] Female " + akName + " already exists in registered actor list.", Logger::LogType::Core);
			}
			else {
				
				RE::FormID FemaleFormID = ScannedActors[ActorIndex]->GetFormID();

				if (InstalledMods::RosaRoundBottom && ScannedActors[ActorIndex] == Rosa) {
					if (InstalledMods::Sexlab && Configuration::DefaultNPCShyness == ShySex::Sexuality) {
						Sexlab::RequestSexuality(ScannedActors[ActorIndex], [currentGameTime](UINT8 SexualityScore) {
							SKSE::GetTaskInterface()->AddTask([currentGameTime, SexualityScore] {
								RegisterRosa(currentGameTime, SexualityScore);
								});
							});
					}
					else {
						RegisterRosa(currentGameTime, 100);
					}
				}
				else {
					Log("<C++ NPCScanner> [ProcessActors] Registering New Female: " + akName + " (" + std::format("{:08X}", ScannedActors[ActorIndex]->GetFormID()) + ")", Logger::LogType::Core);
					
					if (InstalledMods::Sexlab && Configuration::DefaultNPCShyness == ShySex::Sexuality) {
						Sexlab::RequestSexuality(ScannedActors[ActorIndex], [currentGameTime, FemaleFormID](UINT8 SexualityScore) {
							SKSE::GetTaskInterface()->AddTask([currentGameTime, FemaleFormID, SexualityScore] {
								// Async hop: the actor may have unloaded between the scan and this
								// callback. RegisterFemale dereferences the actor on its first line,
								// so bail if the lookup came back null.
								RE::Actor* thisActor = RE::TESForm::LookupByID<RE::Actor>(FemaleFormID);
								if (!thisActor) {
									Log("<C++ NPCScanner> [ProcessActors] Actor " + std::format("{:08X}", FemaleFormID) + " no longer exists when sexuality callback fired; skipping registration.", Logger::LogType::Core, Logger::LoggingLevel::warning);
									return;
								}
								RegisterFemale(thisActor, currentGameTime, SexualityScore);
								});
							});
					}
					else {
						RegisterFemale(ScannedActors[ActorIndex], currentGameTime, 100);
					}
				}
			}
		}
	}

	Log("<C++ NPCScanner> [ProcessActors] Finished processing actors!");
}