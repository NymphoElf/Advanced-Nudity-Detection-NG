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
		IsWearingChestCurtain = (PlayerWornHasKeyword(ChestCurtain) || PlayerWornHasKeyword(ChestCurtainT));
		IsWearingPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain) || PlayerWornHasKeyword(PelvicCurtainT) || PlayerWornHasKeyword(Miniskirt) || PlayerWornHasKeyword(MiniskirtT));
		IsWearingAssCurtain = (PlayerWornHasKeyword(AssCurtain) || PlayerWornHasKeyword(AssCurtainT) || PlayerWornHasKeyword(Miniskirt) || PlayerWornHasKeyword(MiniskirtT));
	}
	else {
		IsWearingChestCurtain = (PlayerWornHasKeyword(ChestCurtain_Male) || PlayerWornHasKeyword(ChestCurtainT_Male));
		IsWearingPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain_Male) || PlayerWornHasKeyword(PelvicCurtainT_Male) || PlayerWornHasKeyword(Miniskirt_Male) || PlayerWornHasKeyword(MiniskirtT_Male));
		IsWearingAssCurtain = (PlayerWornHasKeyword(AssCurtain_Male) || PlayerWornHasKeyword(AssCurtainT_Male) || PlayerWornHasKeyword(Miniskirt_Male) || PlayerWornHasKeyword(MiniskirtT_Male));
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
		IsWearingChestCurtain = (PlayerWornHasKeyword(ChestCurtain) || PlayerWornHasKeyword(ChestCurtainT));
		IsWearingPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain) || PlayerWornHasKeyword(PelvicCurtainT) || PlayerWornHasKeyword(Miniskirt) || PlayerWornHasKeyword(MiniskirtT));
		IsWearingAssCurtain = (PlayerWornHasKeyword(AssCurtain) || PlayerWornHasKeyword(AssCurtainT) || PlayerWornHasKeyword(Miniskirt) || PlayerWornHasKeyword(MiniskirtT));
		
		Log("<C++ Player> [ProcessEquipmentChange] Send Female Scan...");
		FemaleArmorScan::FemaleAnalyze();
	}
	else {
		Log("<C++ Player> [ProcessEquipmentChange] Checking Curtains...");
		IsWearingChestCurtain = (PlayerWornHasKeyword(ChestCurtain_Male) || PlayerWornHasKeyword(ChestCurtainT_Male));
		IsWearingPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain_Male) || PlayerWornHasKeyword(PelvicCurtainT_Male) || PlayerWornHasKeyword(Miniskirt_Male) || PlayerWornHasKeyword(MiniskirtT_Male));
		IsWearingAssCurtain = (PlayerWornHasKeyword(AssCurtain_Male) || PlayerWornHasKeyword(AssCurtainT_Male) || PlayerWornHasKeyword(Miniskirt_Male) || PlayerWornHasKeyword(MiniskirtT_Male));
		
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
			for (int Index = 0; Index < 20 && FoundRace == false; ++Index) {
				if (VanillaRaces[Index] == arPlayer) {
					switch (Index) {
						//Check if contracted vampirism without being Vampire lord, and if so, set base race to non-vampire version
						case 1:
							PlayerBaseRace = VanillaRaces[0];
							break;
						case 3:
							PlayerBaseRace = VanillaRaces[2];
							break;
						case 5:
							PlayerBaseRace = VanillaRaces[4];
							break;
						case 7:
							PlayerBaseRace = VanillaRaces[6];
							break;
						case 9:
							PlayerBaseRace = VanillaRaces[8];
							break;
						case 11:
							PlayerBaseRace = VanillaRaces[10];
							break;
						case 13:
							PlayerBaseRace = VanillaRaces[12];
							break;
						case 15:
							PlayerBaseRace = VanillaRaces[14];
							break;
						case 17:
							PlayerBaseRace = VanillaRaces[16];
							break;
						case 19:
							PlayerBaseRace = VanillaRaces[18];
							break;
						default:
							PlayerBaseRace = VanillaRaces[Index];
							break;
					}
				}
			}
		}
	}
}