#include "Core.h"
#include "Player.h"
#include "Logger.h"

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

	Log("<C++ Player> [InitializePlayerFactions] COMPLETE");
}

void CheckWearingCurtains(RE::StaticFunctionTag*) {
	if (Player->GetActorBase()->IsFemale()) {
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

void ClosedMenuEvent(RE::StaticFunctionTag*, std::string MenuName) {
	Log("<C++ Player> [ClosedMenuEvent] Closed Menu: " + MenuName, LogType::Core);
	if (MenuName == "RaceSex Menu") {
		InitializePlayerFactions();
	}
}
