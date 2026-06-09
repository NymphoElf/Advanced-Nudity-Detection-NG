#include "NPCScanner.h"
#include "NPCArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "NPCData.h"
#include "Logger.h"
#include "ArousedStats.h"

void ProcessActor(RE::Actor* akActor, int SexualityScore) {
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