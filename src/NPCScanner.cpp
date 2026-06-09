#include "NPCScanner.h"
#include "NPCArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "NPCData.h"
#include "Logger.h"
#include "ArousedStats.h"
#include "SexlabStats.h"

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
	std::vector<RE::Actor*> nearbyActors;

	if (!Player || !Player->parentCell) {
		Log("<C++ ActorScanner> [GetActorsInRadiusOfPlayer] Warning: Source (Player or Player's Parent Cell) is null", LogType::Core, LoggingLevel::warning);
		return nearbyActors;
	}

	ForEachReferenceInRange(Player, radius, [&](RE::TESObjectREFR& ref) {
		//auto refBase = ref.GetBaseObject();
		auto actor = ref.As<RE::Actor>();
		if (actor && actor != Player && !actor->IsDisabled() && !actor->IsDead()) {
			nearbyActors.push_back(actor);
		}
		return RE::BSContainer::ForEachResult::kContinue;
		});

	return nearbyActors;
}

void ProcessActors(std::vector<RE::Actor*> ScannedActors) {
	for (int Index = 0; Index < ScannedActors.size(); ++Index) {
		if (ScannedActors[Index] == nullptr) {
			Log("<C++ NPCScanner> [ProcessActor] Received a NONE/Null Actor!", LogType::Core, LoggingLevel::error);
			return;
		}

		int index = 0;
		while (index < TotalFactions) {
			if (ScannedActors[Index]->IsInFaction(AllFactions[index]) == false) {
				ScannedActors[Index]->AddToFaction(AllFactions[index], 0);
			}
			index++;
		}

		std::string akName = ScannedActors[Index]->GetName();

		if (ScannedActors[Index]->GetActorBase()->IsFemale() == false) {
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
			ScannedActors[Index]->AddToFaction(ArousalFaction, arousalValue > 0.0f ? static_cast<std::int8_t>(arousalValue) : std::int8_t{ 0 });
			
			NPCFemaleScan::NPCFemaleAnalyze(ScannedActors[Index]);

			auto* calendar = RE::Calendar::GetSingleton();
			float currentGameTime = calendar ? calendar->GetCurrentGameTime() : 0.0f;

			if (RegisteredFemaleMap.count(ScannedActors[Index]->GetFormID()))
			{
				Log("<C++ NPCScanner> [ProcessActor] Female " + akName + " already exists in registered actor list.", LogType::Core);
				if (Configuration::DynamicModestyEnabled) {
					ProcessNPCModesty(ScannedActors[Index], currentGameTime);
				}
			}
			else {
				
				RE::FormID FemaleFormID = ScannedActors[Index]->GetFormID();

				if (InstalledMods::RosaRoundBottom && ScannedActors[Index] == Rosa) {
					Sexlab::RequestSexuality(ScannedActors[Index], [currentGameTime](int SexualityScore) {
						SKSE::GetTaskInterface()->AddTask([currentGameTime, SexualityScore] {
							RegisterRosa(currentGameTime, SexualityScore);
						});
					});
					
					//RegisterRosa(currentGameTime, SexualityScore);
				}
				else {
					Log("<C++ NPCScanner> [ProcessActor] Registering New Female " + akName + " (" + std::format("{:08X}", ScannedActors[Index]->GetFormID()) + ")", LogType::Core);
					Sexlab::RequestSexuality(ScannedActors[Index], [currentGameTime, FemaleFormID](int SexualityScore) {
						SKSE::GetTaskInterface()->AddTask([currentGameTime, FemaleFormID, SexualityScore] {
							RE::Actor* thisActor = RE::TESForm::LookupByID<RE::Actor>(FemaleFormID);
							RegisterFemale(thisActor, currentGameTime, SexualityScore);
						});
					});
					
					//RegisterFemale(ScannedActors[Index], currentGameTime, SexualityScore);
				}
			}
		}
	}
}

/*
void ProcessNPC(RE::StaticFunctionTag*, RE::Actor* akActor, float CurrentGameTime, int SexualityScore) {
	if (akActor == nullptr) {
		Log("<C++ NPCScanner> [ProcessActor] Received a NONE/Null Actor!", LogType::Core, LoggingLevel::error);
		return;
	}
	
	int index = 0;
	while (index < TotalFactions) {
		if (akActor->IsInFaction(AllFactions[index]) == false) {
			akActor->AddToFaction(AllFactions[index], 0);
		}
		index++;
	}

	std::string akName = akActor->GetName();

	// Cache OSLAroused's arousal into AND's ArousalFaction rank, mirroring the old
	// Papyrus AND_Core.UpdateArousalValue. We pull from OSLAroused (it owns the value)
	// rather than push, so the two systems don't fight. Runs on the main thread, so
	// the GetArousalExt first-query init path and AddToFaction are both safe here.
	// GetArousal returns -1 if OSLAroused is present but its Ext export can't be
	// resolved (older build); fall back to 0 rather than writing a negative rank.
	float arousalValue = InstalledMods::OSLAroused ? Aroused::GetArousal(akActor) : 0.0f;
	akActor->AddToFaction(ArousalFaction, arousalValue > 0.0f ? static_cast<std::int8_t>(arousalValue) : std::int8_t{ 0 });

	if (akActor->GetActorBase()->IsFemale() == false) {
		NPCMaleScan::NPCMaleAnalyze(akActor);
	}
	else {
		NPCFemaleScan::NPCFemaleAnalyze(akActor);

		auto* calendar = RE::Calendar::GetSingleton();
		float currentGameTime = calendar ? calendar->GetCurrentGameTime() : 0.0f;
            
		if (RegisteredFemaleMap.count(akActor->GetFormID()))
		{
			Log("<C++ NPCScanner> [ProcessActor] Female " + akName + " already exists in registered actor list.", LogType::Core);
			if (Configuration::DynamicModestyEnabled) {
				ProcessNPCModesty(akActor, currentGameTime);
			}
		}
		else {
			if (InstalledMods::RosaRoundBottom && akActor == Rosa) {
				RegisterRosa(currentGameTime, SexualityScore);
			}
			else {
				Log("<C++ NPCScanner> [ProcessActor] Registering New Female " + akName + " (" + std::format("{:08X}", akActor->GetFormID()) + ")", LogType::Core);
				RegisterFemale(akActor, currentGameTime, SexualityScore);
			}
		}
	}
}
*/