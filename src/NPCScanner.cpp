#include "NPCScanner.h"
#include "NPCArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "NPCData.h"
#include "Logger.h"

void ProcessNPC(RE::StaticFunctionTag*, RE::Actor* akActor, float CurrentGameTime, int SexualityScore) {
	if (akActor == nullptr) {
		Log("<C++ NPCScanner> [ProcessNPC] Received a NONE/Null Actor!", LogType::Core, LoggingLevel::error);
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

	if (akActor->GetActorBase()->IsFemale() == false) {
		NPCMaleScan::NPCMaleAnalyze(akActor);
	}
	else {
		NPCFemaleScan::NPCFemaleAnalyze(akActor);

		int FemaleID = GetInternalFemaleID(akActor);
		if (FemaleID >= 0) {
			Log("<C++ NPCScanner> [ProcessNPC] Female " + akName + " already exists in registered actor list.", LogType::Core);
			if (Configuration::DynamicModestyEnabled) {
				ProcessNPCModesty(akActor, FemaleID, CurrentGameTime);
			}
		}
		else {
			if (InstalledMods::RosaRoundBottom && akActor == Rosa) {
				RegisterRosa(CurrentGameTime, SexualityScore);
			}
			else {
				Log("<C++ NPCScanner> [ProcessNPC] Registering New Female " + akName + " (" + std::format("{0:#x}", akActor->GetFormID()) + ")", LogType::Core);
				RegisterFemale(akActor, CurrentGameTime, SexualityScore);
			}
		}
	}
}

/*
void ExternalProcessNPC(RE::StaticFunctionTag*, RE::Actor* akActor, float CurrentGameTime, int SexualityScore) {
	ProcessNPC(akActor, CurrentGameTime, SexualityScore);
}
*/