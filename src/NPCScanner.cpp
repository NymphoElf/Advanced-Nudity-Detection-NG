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
		//auto refBase = ref.GetBaseObject();
		auto actor = ref.As<RE::Actor>();
		if (actor && actor != Player && !actor->IsDisabled() && !actor->IsDead() && !actor->IsChild() && !actor->HasKeyword(ActorType_Creature)) {
			nearbyActors.push_back(actor);
		}
		return RE::BSContainer::ForEachResult::kContinue;
		});

	Log("<C++ ActorScanner> [GetActorsInRadiusOfPlayer] Finished Gathering Actors. Sending " + std::to_string((int)nearbyActors.size()) + " actors to be processed!");

	return nearbyActors;
}

void ScanForNewActors(std::vector<RE::Actor*> ScannedActors) {
	Log("<C++ NPCScanner> [ProcessActors] Beginning to process actors! Processing " + std::to_string((int)ScannedActors.size()) + " actors!");
	
	for (int Index = 0; Index < ScannedActors.size(); ++Index) {
		if (ScannedActors[Index] == nullptr) {
			Log("<C++ NPCScanner> [ProcessActors] Received a NONE/Null Actor!", Logger::LogType::Core, Logger::LoggingLevel::error);
			continue;
		}

		int index = 0;
		while (index < TotalFactions) {
			if (ScannedActors[Index]->IsInFaction(AllFactions[index]) == false) {
				ScannedActors[Index]->AddToFaction(AllFactions[index], 0);
			}
			index++;
		}

		std::string akName = ScannedActors[Index]->GetName();

		auto* actorBase = ScannedActors[Index]->GetActorBase();
		if (actorBase == nullptr) {
			Log("<C++ NPCScanner> [ProcessActors] Actor " + akName + " (" + std::format("{:08X}", ScannedActors[Index]->GetFormID()) + ") has no actor base; skipping.", Logger::LogType::Core, Logger::LoggingLevel::warning);
			continue;
		}

		if (actorBase->IsFemale() == false) {
			NPCMaleScan::NPCMaleAnalyze(ScannedActors[Index]);
		}
		else {
			// Cache OSLAroused's arousal into AND's ArousalFaction rank, mirroring the old
			// Papyrus AND_Core.UpdateArousalValue. We pull from OSLAroused (it owns the value)
			// rather than push, so the two systems don't fight. Runs on the main thread, so
			// the GetArousalExt first-query init path and AddToFaction are both safe here.
			// GetArousal returns -1 if OSLAroused is present but its Ext export can't be
			// resolved (older build); fall back to 0 rather than writing a negative rank.
			float arousalValue = InstalledMods::OSLAroused ? Aroused::GetArousal(ScannedActors[Index]) : 0.0f;
			const std::int8_t arousalRank = arousalValue > 0.0f ? static_cast<std::int8_t>(arousalValue) : std::int8_t{ 0 };
			
			//Only write to the faction if the rank has actually changed. (try and avoid potential data races from game ai/job threads accessing factions)
			if (ScannedActors[Index]->GetFactionRank(ArousalFaction, false) != arousalRank) {
				ScannedActors[Index]->AddToFaction(ArousalFaction, arousalRank);
			}

			NPCFemaleScan::NPCFemaleAnalyze(ScannedActors[Index]);

			float currentGameTime = GameCalendar->GetCurrentGameTime();

			if (RegisteredFemaleMap.count(ScannedActors[Index]->GetFormID()))
			{
				Log("<C++ NPCScanner> [ProcessActors] Female " + akName + " already exists in registered actor list.", Logger::LogType::Core);
			}
			else {
				
				RE::FormID FemaleFormID = ScannedActors[Index]->GetFormID();

				if (InstalledMods::RosaRoundBottom && ScannedActors[Index] == Rosa) {
					if (InstalledMods::Sexlab && Configuration::DefaultNPCShyness == ShySex::Sexuality) {
						Sexlab::RequestSexuality(ScannedActors[Index], [currentGameTime](int SexualityScore) {
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
					Log("<C++ NPCScanner> [ProcessActors] Registering New Female: " + akName + " (" + std::format("{:08X}", ScannedActors[Index]->GetFormID()) + ")", Logger::LogType::Core);
					
					if (InstalledMods::Sexlab && Configuration::DefaultNPCShyness == ShySex::Sexuality) {
						Sexlab::RequestSexuality(ScannedActors[Index], [currentGameTime, FemaleFormID](int SexualityScore) {
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
						RegisterFemale(ScannedActors[Index], currentGameTime, 100);
					}
				}
			}
		}
	}

	Log("<C++ NPCScanner> [ProcessActors] Finished processing actors!");
}