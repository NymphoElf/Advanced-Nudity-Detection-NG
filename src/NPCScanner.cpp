#include "NPCScanner.h"
#include "NPCArmorScan.h"
#include "Core.h"
#include "Config.h"

void ProcessNPC(RE::Actor* akActor) {
	if (akActor == nullptr) {
		logs::error("<C++ NPCScanner> [ProcessNPC] Received a NONE/Null Actor!");
		return;
	}
	
	int index = 0;
	while (index < TotalFactions) {
		if (akActor->IsInFaction(AllFactions[index]) == false) {
			akActor->AddToFaction(AllFactions[index], 0);
		}
		index++;
	}

	RE::TESActorBase akBase = *akActor->GetActorBase();
	std::string akName = akActor->GetName();

	if (akBase.IsFemale() == false) {
		NPCMaleAnalyze(akActor);
	}
	else {
		NPCFemaleAnalyze(akActor);

		if (DynamicModestyEnabled) {

		}
	}
}

void ExternalProcessNPC(RE::StaticFunctionTag*, RE::Actor* akActor) {
	ProcessNPC(akActor);
}