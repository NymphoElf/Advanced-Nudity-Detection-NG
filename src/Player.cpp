#include "Core.h"
#include "Player.h"
#include "Logger.h"
#include "NPCData.h"
#include "PlayerArmorScan.h"

void InitializePlayerFactions() {
	Log("<C++ Player> [InitializePlayerFactions] START");
	
	Player->AddToFaction(ShowingAssFaction, 0);
	Player->AddToFaction(ShowingChestFaction, 0);
	Player->AddToFaction(ShowingGenitalsFaction, 0);
	Player->AddToFaction(ShowingBraFaction, 0);
	Player->AddToFaction(ShowingUnderwearFaction, 0);
	Player->AddToFaction(ToplessFaction, 0);
	Player->AddToFaction(BottomlessFaction, 0);
	Player->AddToFaction(NudeFaction, 0);

	Player->AddToFaction(FlashingAssCurtainFaction, 0);
	Player->AddToFaction(FlashingPelvicCurtainFaction, 0);
	Player->AddToFaction(FlashingChestCurtainFaction, 0);

	Player->AddToFaction(FlashingTopArmorFaction, 0);
	Player->AddToFaction(FlashingBraFaction, 0);

	Player->AddToFaction(FlashingBottomArmorFaction, 0);
	Player->AddToFaction(FlashingUnderwearFaction, 0);
	Player->AddToFaction(FlashingCStringFaction, 0);
	Player->AddToFaction(FlashingHotpantsFaction, 0);
	Player->AddToFaction(FlashingShowgirlSkirtFaction, 0);

	Player->AddToFaction(ModestyFaction, 0);
	Player->AddToFaction(TopModestyFaction, 0);
	Player->AddToFaction(BottomModestyFaction, 0);

	Player->AddToFaction(ShyWithMale, 1);
	Player->AddToFaction(ShyWithFemale, 0);

	Player->AddToFaction(ArousalFaction, 0);

	PlayerFactionsInitialized = true;

	Log("<C++ Player> [InitializePlayerFactions] COMPLETE");
}

void CheckWearingCurtains(RE::StaticFunctionTag*) {
	if (PlayerBase->IsFemale()) {
		IsWearingChestCurtain = (PlayerIsWearing(FemaleKeywords[ChestCurtain]) || PlayerIsWearing(FemaleKeywords[ChestCurtainT]));
		IsWearingPelvicCurtain = (PlayerIsWearing(FemaleKeywords[PelvicCurtain]) || PlayerIsWearing(FemaleKeywords[PelvicCurtainT]) || PlayerIsWearing(FemaleKeywords[Miniskirt]) || PlayerIsWearing(FemaleKeywords[MiniskirtT]));
		IsWearingAssCurtain = (PlayerIsWearing(FemaleKeywords[AssCurtain]) || PlayerIsWearing(FemaleKeywords[AssCurtainT]) || PlayerIsWearing(FemaleKeywords[Miniskirt]) || PlayerIsWearing(FemaleKeywords[MiniskirtT]));
	}
	else {
		IsWearingChestCurtain = (PlayerIsWearing(MaleKeywords[ChestCurtain]) || PlayerIsWearing(MaleKeywords[ChestCurtainT]));
		IsWearingPelvicCurtain = (PlayerIsWearing(MaleKeywords[PelvicCurtain]) || PlayerIsWearing(MaleKeywords[PelvicCurtainT]) || PlayerIsWearing(MaleKeywords[Miniskirt]) || PlayerIsWearing(MaleKeywords[MiniskirtT]));
		IsWearingAssCurtain = (PlayerIsWearing(MaleKeywords[AssCurtain]) || PlayerIsWearing(MaleKeywords[AssCurtainT]) || PlayerIsWearing(MaleKeywords[Miniskirt]) || PlayerIsWearing(MaleKeywords[MiniskirtT]));
	}
}

bool ProcessEquipmentChange(RE::StaticFunctionTag*, RE::TESForm* BaseObject, RE::TESObjectREFR* akReference) {
	if (BaseObject == nullptr && akReference == nullptr) {
		Log("<C++ PlayerScript> [ProcessEquipmentChange] Changed Object is NULL", Logger::LogType::Core, Logger::LoggingLevel::info);
		return false;
	}
	else {
		if (BaseObject != nullptr) {
			std::string BaseObjectName = BaseObject->GetName();

			if (BaseObjectName == "") {
				Log("<C++ PlayerScript> [ProcessEquipmentChange] BaseObject (" + std::format("{:08X}", BaseObject->GetFormID()) + ") has no name!", Logger::LogType::Core, Logger::LoggingLevel::warning);
				BaseObjectName = "UnknownObject";
			}

			Log("<C++ PlayerScript> [ProcessEquipmentChange] BaseObject is: " + BaseObjectName + " (" + std::format("{:08X}", BaseObject->GetFormID()) + ")", Logger::LogType::Core, Logger::LoggingLevel::info);
		}

		if (akReference != nullptr) {
			std::string ObjectReferenceName = akReference->GetName();

			if (ObjectReferenceName == "") {
				Log("<C++ PlayerScript> [ProcessEquipmentChange] akReference (" + std::format("{:08X}", akReference->GetFormID()) + ") has no name!", Logger::LogType::Misc, Logger::LoggingLevel::warning);
				ObjectReferenceName = "UnknownObjectRef";
			}

			Log("<C++ Player> [ProcessEquipmentChange] akReference is: " + ObjectReferenceName + " (" + std::format("{:08X}", akReference->GetFormID()), Logger::LogType::Core, Logger::LoggingLevel::info);
		}
	}
	
	if (PlayerBase->IsFemale()) {
		Log("<C++ Player> [ProcessEquipmentChange] Checking Curtains...");
		IsWearingChestCurtain = (PlayerIsWearing(FemaleKeywords[ChestCurtain]) || PlayerIsWearing(FemaleKeywords[ChestCurtainT]));
		IsWearingPelvicCurtain = (PlayerIsWearing(FemaleKeywords[PelvicCurtain]) || PlayerIsWearing(FemaleKeywords[PelvicCurtainT]) || PlayerIsWearing(FemaleKeywords[Miniskirt]) || PlayerIsWearing(FemaleKeywords[MiniskirtT]));
		IsWearingAssCurtain = (PlayerIsWearing(FemaleKeywords[AssCurtain]) || PlayerIsWearing(FemaleKeywords[AssCurtainT]) || PlayerIsWearing(FemaleKeywords[Miniskirt]) || PlayerIsWearing(FemaleKeywords[MiniskirtT]));
		
		Log("<C++ Player> [ProcessEquipmentChange] Send Female Scan...");
		FemaleArmorScan::FemaleAnalyze();
	}
	else {
		Log("<C++ Player> [ProcessEquipmentChange] Checking Curtains...");
		IsWearingChestCurtain = (PlayerIsWearing(MaleKeywords[ChestCurtain]) || PlayerIsWearing(MaleKeywords[ChestCurtainT]));
		IsWearingPelvicCurtain = (PlayerIsWearing(MaleKeywords[PelvicCurtain]) || PlayerIsWearing(MaleKeywords[PelvicCurtainT]) || PlayerIsWearing(MaleKeywords[Miniskirt]) || PlayerIsWearing(MaleKeywords[MiniskirtT]));
		IsWearingAssCurtain = (PlayerIsWearing(MaleKeywords[AssCurtain]) || PlayerIsWearing(MaleKeywords[AssCurtainT]) || PlayerIsWearing(MaleKeywords[Miniskirt]) || PlayerIsWearing(MaleKeywords[MiniskirtT]));
		
		Log("<C++ Player> [ProcessEquipmentChange] Send Male Scan...");
		MaleArmorScan::MaleAnalyze();
	}

	return true;
}

void ClosedMenuEvent(RE::StaticFunctionTag*, std::string MenuName) {
	Log("<C++ Player> [ClosedMenuEvent] Closed Menu: " + MenuName, Logger::LogType::Core);
	if (MenuName == "RaceSex Menu") {
		if (!IsPlayerTransformed()) {
			PlayerBaseRace = Player->GetRace();
		}
		
		if (!PlayerFactionsInitialized) {
			InitializePlayerFactions();
		}

		if (!PermanentFemalesImported) {
			ImportPermanentFemales();
		}
	}

	if (MenuName == "Console") {
		RE::TESRace* arPlayer = Player->GetRace();
		if (arPlayer != PlayerBaseRace && !IsPlayerTransformed()) {
			bool FoundRace = false;
			for (UINT8 Index = 0; Index < 20 && FoundRace == false; ++Index) {
				if (VanillaRaces[Index] == arPlayer) {
					switch (Index) {
						//Check if contracted vampirism without being Vampire lord, and if so, set base race to non-vampire version
						case AltmerVampire:
							PlayerBaseRace = VanillaRaces[Altmer];
							break;
						case ArgonianVampire:
							PlayerBaseRace = VanillaRaces[Argonian];
							break;
						case BosmerVampire:
							PlayerBaseRace = VanillaRaces[Bosmer];
							break;
						case BretonVampire:
							PlayerBaseRace = VanillaRaces[Breton];
							break;
						case DunmerVampire:
							PlayerBaseRace = VanillaRaces[Dunmer];
							break;
						case ImperialVampire:
							PlayerBaseRace = VanillaRaces[Imperial];
							break;
						case KhajiitVampire:
							PlayerBaseRace = VanillaRaces[Khajiit];
							break;
						case NordVampire:
							PlayerBaseRace = VanillaRaces[Nord];
							break;
						case OrsimerVampire:
							PlayerBaseRace = VanillaRaces[Orsimer];
							break;
						case RedguardVampire:
							PlayerBaseRace = VanillaRaces[Redguard];
							break;
						default:
							PlayerBaseRace = VanillaRaces[Index];
							break;
					}
					FoundRace = true;
				}
			}
		}
	}
}