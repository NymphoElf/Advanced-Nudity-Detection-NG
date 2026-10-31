#include <vector>

#include "Config.h"
#include "Player.h"
#include "Core.h"
#include "NPCData.h"
#include "PlayerModesty.h"
#include "Logger.h"
#include "ModEventHandler.h"
#include "ModIntegration.h"

enum DefaultOdds {
	DefaultCurtainOddsLow = 20,
	DefaultCurtainOdds = 35,
	DefaultCurtainOddsHigh = 50,
	DefaultCurtainOddsExtreme = 65,
	DefaultCurtainOddsUltra = 80,

	DefaultTransparentCurtainOddsLow = 55,
	DefaultTransparentCurtainOdds = 65,
	DefaultTransparentCurtainOddsHigh = 75,
	DefaultTransparentCurtainOddsExtreme = 85,
	DefaultTransparentCurtainOddsUltra = 95,

	DefaultCStringOdds = 60,

	DefaultTransparentCStringOddsLow = 70,
	DefaultTransparentCStringOdds = 80,
	DefaultTransparentCStringOddsHigh = 90,

	DefaultTransparentItemOddsLow = 30,
	DefaultTransparentItemOdds = 50,
	DefaultTransparentItemOddsHigh = 70
};

void InitializeConfigData() {
	Log("<C++ Config> [InitializeConfigData] START");
	
	//Curtain Odds

	Configuration::FlashingOdds[ChestCurtainOddsLow] = DefaultCurtainOddsLow;
	Configuration::FlashingOdds[ChestCurtainOdds] = DefaultCurtainOdds;
	Configuration::FlashingOdds[ChestCurtainOddsHigh] = DefaultCurtainOddsHigh;
	Configuration::FlashingOdds[ChestCurtainOddsExtreme] = DefaultCurtainOddsExtreme;
	Configuration::FlashingOdds[ChestCurtainOddsUltra] = DefaultCurtainOddsUltra;

	Configuration::FlashingOdds[PelvicCurtainOddsLow] = DefaultCurtainOddsLow;
	Configuration::FlashingOdds[PelvicCurtainOdds] = DefaultCurtainOdds;
	Configuration::FlashingOdds[PelvicCurtainOddsHigh] = DefaultCurtainOddsHigh;
	Configuration::FlashingOdds[PelvicCurtainOddsExtreme] = DefaultCurtainOddsExtreme;
	Configuration::FlashingOdds[PelvicCurtainOddsUltra] = DefaultCurtainOddsUltra;

	Configuration::FlashingOdds[AssCurtainOddsLow] = DefaultCurtainOddsLow;
	Configuration::FlashingOdds[AssCurtainOdds] = DefaultCurtainOdds;
	Configuration::FlashingOdds[AssCurtainOddsHigh] = DefaultCurtainOddsHigh;
	Configuration::FlashingOdds[AssCurtainOddsExtreme] = DefaultCurtainOddsExtreme;
	Configuration::FlashingOdds[AssCurtainOddsUltra] = DefaultCurtainOddsUltra;

	Configuration::FlashingOdds[TransparentChestCurtainOddsLow] = DefaultTransparentCurtainOddsLow;
	Configuration::FlashingOdds[TransparentChestCurtainOdds] = DefaultTransparentCurtainOdds;
	Configuration::FlashingOdds[TransparentChestCurtainOddsHigh] = DefaultTransparentCurtainOddsHigh;
	Configuration::FlashingOdds[TransparentChestCurtainOddsExtreme] = DefaultTransparentCurtainOddsExtreme;
	Configuration::FlashingOdds[TransparentChestCurtainOddsUltra] = DefaultTransparentCurtainOddsUltra;

	Configuration::FlashingOdds[TransparentPelvicCurtainOddsLow] = DefaultTransparentCurtainOddsLow;
	Configuration::FlashingOdds[TransparentPelvicCurtainOdds] = DefaultTransparentCurtainOdds;
	Configuration::FlashingOdds[TransparentPelvicCurtainOddsHigh] = DefaultTransparentCurtainOddsHigh;
	Configuration::FlashingOdds[TransparentPelvicCurtainOddsExtreme] = DefaultTransparentCurtainOddsExtreme;
	Configuration::FlashingOdds[TransparentPelvicCurtainOddsUltra] = DefaultTransparentCurtainOddsUltra;

	Configuration::FlashingOdds[TransparentAssCurtainOddsLow] = DefaultTransparentCurtainOddsLow;
	Configuration::FlashingOdds[TransparentAssCurtainOdds] = DefaultTransparentCurtainOdds;
	Configuration::FlashingOdds[TransparentAssCurtainOddsHigh] = DefaultTransparentCurtainOddsHigh;
	Configuration::FlashingOdds[TransparentAssCurtainOddsExtreme] = DefaultTransparentCurtainOddsExtreme;
	Configuration::FlashingOdds[TransparentAssCurtainOddsUltra] = DefaultTransparentCurtainOddsUltra;

	//Armor Piece Odds

	Configuration::FlashingOdds[TransparentTopArmorOdds_Low] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentTopArmorOdds] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentTopArmorOdds_High] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentBottomArmorOdds_Low] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentBottomArmorOdds] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentBottomArmorOdds_High] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentBraOdds_Low] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentBraOdds] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentBraOdds_High] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentUnderwearOdds_Low] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentUnderwearOdds] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentUnderwearOdds_High] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentHotpantsOdds_Low] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentHotpantsOdds] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentHotpantsOdds_High] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentShowgirlOdds_Low] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentShowgirlOdds] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentShowgirlOdds_High] = DefaultTransparentItemOddsHigh;

	//CString Odds

	Configuration::FlashingOdds[CStringOdds] = DefaultCStringOdds;
	Configuration::FlashingOdds[TransparentCStringOdds_Low] = DefaultTransparentCStringOddsLow;
	Configuration::FlashingOdds[TransparentCStringOdds] = DefaultTransparentCStringOdds;
	Configuration::FlashingOdds[TransparentCStringOdds_High] = DefaultTransparentCStringOddsHigh;
	
	//Curtain Odds - MALE

	Configuration::FlashingOdds[ChestCurtainOddsLow_Male] = DefaultCurtainOddsLow;
	Configuration::FlashingOdds[ChestCurtainOdds_Male] = DefaultCurtainOdds;
	Configuration::FlashingOdds[ChestCurtainOddsHigh_Male] = DefaultCurtainOddsHigh;
	Configuration::FlashingOdds[ChestCurtainOddsExtreme_Male] = DefaultCurtainOddsExtreme;
	Configuration::FlashingOdds[ChestCurtainOddsUltra_Male] = DefaultCurtainOddsUltra;

	Configuration::FlashingOdds[PelvicCurtainOddsLow_Male] = DefaultCurtainOddsLow;
	Configuration::FlashingOdds[PelvicCurtainOdds_Male] = DefaultCurtainOdds;
	Configuration::FlashingOdds[PelvicCurtainOddsHigh_Male] = DefaultCurtainOddsHigh;
	Configuration::FlashingOdds[PelvicCurtainOddsExtreme_Male] = DefaultCurtainOddsExtreme;
	Configuration::FlashingOdds[PelvicCurtainOddsUltra_Male] = DefaultCurtainOddsUltra;

	Configuration::FlashingOdds[AssCurtainOddsLow_Male] = DefaultCurtainOddsLow;
	Configuration::FlashingOdds[AssCurtainOdds_Male] = DefaultCurtainOdds;
	Configuration::FlashingOdds[AssCurtainOddsHigh_Male] = DefaultCurtainOddsHigh;
	Configuration::FlashingOdds[AssCurtainOddsExtreme_Male] = DefaultCurtainOddsExtreme;
	Configuration::FlashingOdds[AssCurtainOddsUltra_Male] = DefaultCurtainOddsUltra;

	Configuration::FlashingOdds[TransparentChestCurtainOddsLow_Male] = DefaultTransparentCurtainOddsLow;
	Configuration::FlashingOdds[TransparentChestCurtainOdds_Male] = DefaultTransparentCurtainOdds;
	Configuration::FlashingOdds[TransparentChestCurtainOddsHigh_Male] = DefaultTransparentCurtainOddsHigh;
	Configuration::FlashingOdds[TransparentChestCurtainOddsExtreme_Male] = DefaultTransparentCurtainOddsExtreme;
	Configuration::FlashingOdds[TransparentChestCurtainOddsUltra_Male] = DefaultTransparentCurtainOddsUltra;

	Configuration::FlashingOdds[TransparentPelvicCurtainOddsLow_Male] = DefaultTransparentCurtainOddsLow;
	Configuration::FlashingOdds[TransparentPelvicCurtainOdds_Male] = DefaultTransparentCurtainOdds;
	Configuration::FlashingOdds[TransparentPelvicCurtainOddsHigh_Male] = DefaultTransparentCurtainOddsHigh;
	Configuration::FlashingOdds[TransparentPelvicCurtainOddsExtreme_Male] = DefaultTransparentCurtainOddsExtreme;
	Configuration::FlashingOdds[TransparentPelvicCurtainOddsUltra_Male] = DefaultTransparentCurtainOddsUltra;

	Configuration::FlashingOdds[TransparentAssCurtainOddsLow_Male] = DefaultTransparentCurtainOddsLow;
	Configuration::FlashingOdds[TransparentAssCurtainOdds_Male] = DefaultTransparentCurtainOdds;
	Configuration::FlashingOdds[TransparentAssCurtainOddsHigh_Male] = DefaultTransparentCurtainOddsHigh;
	Configuration::FlashingOdds[TransparentAssCurtainOddsExtreme_Male] = DefaultTransparentCurtainOddsExtreme;
	Configuration::FlashingOdds[TransparentAssCurtainOddsUltra_Male] = DefaultTransparentCurtainOddsUltra;

	//Armor Piece Odds - MALE

	Configuration::FlashingOdds[TransparentTopArmorOdds_Low_Male] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentTopArmorOdds_Male] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentTopArmorOdds_High_Male] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentBottomArmorOdds_Low_Male] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentBottomArmorOdds_Male] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentBottomArmorOdds_High_Male] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentBraOdds_Low_Male] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentBraOdds_Male] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentBraOdds_High_Male] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentUnderwearOdds_Low_Male] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentUnderwearOdds_Male] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentUnderwearOdds_High_Male] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentHotpantsOdds_Low_Male] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentHotpantsOdds_Male] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentHotpantsOdds_High_Male] = DefaultTransparentItemOddsHigh;

	Configuration::FlashingOdds[TransparentHimboOdds_Low] = DefaultTransparentItemOddsLow;
	Configuration::FlashingOdds[TransparentHimboOdds] = DefaultTransparentItemOdds;
	Configuration::FlashingOdds[TransparentHimboOdds_High] = DefaultTransparentItemOddsHigh;

	//CString Odds - MALE

	Configuration::FlashingOdds[BananaHammockOdds] = DefaultCStringOdds;
	Configuration::FlashingOdds[TransparentBananaHammockOdds_Low] = DefaultTransparentCStringOddsLow;
	Configuration::FlashingOdds[TransparentBananaHammockOdds] = DefaultTransparentCStringOdds;
	Configuration::FlashingOdds[TransparentBananaHammockOdds_High] = DefaultTransparentCStringOddsHigh;

	//Integers
	Configuration::ImmodestyTimeNeeded = 14;

	Configuration::MinimumStrictModestyRank = 0;
	Configuration::MinimumTopModestyRank = 0;
	Configuration::MinimumBottomModestyRank = 0;

	Configuration::DefaultNPCShyness = ShySex::Men;

	Configuration::SprintingMod = 20;
	Configuration::RunningMod = 10;

	Configuration::PlayerConfidenceLevel = ConfidenceLevel::Average;

	Configuration::NudeCommentChance = 10;
	Configuration::ToplessCommentChance = 10;
	Configuration::BottomlessCommentChance = 10;
	Configuration::ChestCommentChance = 20;
	Configuration::GenitalsCommentChance = 25;
	Configuration::AssCommentChance = 15;
	Configuration::BraCommentChance = 5;
	Configuration::UnderwearCommentChance = 5;

	//Booleans
	Configuration::MotionFlashEnabled = true;
	Configuration::DynamicModestyEnabled = InstalledMods::DFFMA;

	Configuration::AllowPlayerShameless = false;
	Configuration::NPCShamelessByDefault = false;

	Configuration::AllowPlayerCorruption = false;
	Configuration::NPCCorruptionByDefault = false;

	Configuration::StrictModestyRules = true;
	Configuration::NPCStrictRulesByDefault = true;

	Configuration::HardcoreModeEnabled = false;

	Configuration::ModestyUpgradeBlocked = false;

	Configuration::DisableNakedComments = false;

	if (InstalledMods::DFFMA && Configuration::StrictModestyRules) {
		Configuration::DynamicModestyMode->value = 1;
	}
	else if (InstalledMods::DFFMA && !Configuration::StrictModestyRules) {
		Configuration::DynamicModestyMode->value = 2;
	}
	else {
		Configuration::DynamicModestyMode->value = 0;
	}

	Log("<C++ Config> [InitializeConfigData] COMPLETE");
}

void UpdateFlashingOdds(RE::StaticFunctionTag*, int FlashOddsIndex, int OddsValue) {
	//Log("<C++ Config> [UpdateFlashingOdds] Updating Flashing Odds Index " + std::to_string(FlashOddsIndex) + " to value " + std::to_string(OddsValue), Logger::Config, Logger::info);
	Configuration::FlashingOdds[FlashOddsIndex] = (UINT8)OddsValue;
	//Log("<C++ Config> [UpdateFlashingOdds] Updating Flashing Odds Index " + std::to_string(FlashOddsIndex) + " value is now " + std::to_string(Configuration::FlashingOdds[FlashOddsIndex]), Logger::Config, Logger::info);
}

std::vector<int> GetFlashOddsArray(RE::StaticFunctionTag*) {
	std::vector<int> FlashArray;
	
	int Index = 0;
	while (Index < FlashingIndex::FlashingOddsLength) {
		FlashArray.emplace_back(Configuration::FlashingOdds[Index]);
		Index++;
	}

	return FlashArray;
}

std::vector<int> GetFlashRolls(RE::StaticFunctionTag*) {
	std::vector<int> FlashRolls;

	FlashRolls.emplace_back(ChestCurtainRoll); //0
	FlashRolls.emplace_back(PelvicCurtainRoll); //1
	FlashRolls.emplace_back(AssCurtainRoll); //2
	FlashRolls.emplace_back(CStringRoll); //3

	FlashRolls.emplace_back(TopTransparentRoll); //4
	FlashRolls.emplace_back(BottomTransparentRoll); //5
	FlashRolls.emplace_back(BraTransparentRoll); //6
	FlashRolls.emplace_back(UnderwearTransparentRoll); //7
	FlashRolls.emplace_back(HotpantsTransparentRoll); //8
	FlashRolls.emplace_back(ShowgirlTransparentRoll); //9

	FlashRolls.emplace_back(NPCChestCurtainRoll); //10
	FlashRolls.emplace_back(NPCPelvicCurtainRoll); //11
	FlashRolls.emplace_back(NPCAssCurtainRoll); //12
	FlashRolls.emplace_back(NPCCStringRoll); //13

	FlashRolls.emplace_back(NPCTopTransparentRoll); //14
	FlashRolls.emplace_back(NPCBottomTransparentRoll); //15
	FlashRolls.emplace_back(NPCBraTransparentRoll); //16
	FlashRolls.emplace_back(NPCUnderwearTransparentRoll); //17
	FlashRolls.emplace_back(NPCHotpantsTransparentRoll); //18
	FlashRolls.emplace_back(NPCShowgirlTransparentRoll); //19

	return FlashRolls;
}

std::vector<int> GetCurtainCoverage(RE::StaticFunctionTag*) {
	enum CurtainState {
		NotWearing,
		Covering,
		Flashing
	};

	std::vector<int> CurtainVector;

	//Chest Curtain
	if (IsWearingChestCurtain == false) {
		CurtainVector.emplace_back(CurtainState::NotWearing);
	}
	else if (Player->GetFactionRank(FlashingChestCurtainFaction, true) == 0) {
		CurtainVector.emplace_back(CurtainState::Covering);
	}
	else if (Player->GetFactionRank(FlashingChestCurtainFaction, true) == 1) {
		CurtainVector.emplace_back(CurtainState::Flashing);
	}
	else {
		CurtainVector.emplace_back(CurtainState::NotWearing);
	}

	//Pelvic Curtain
	if (IsWearingPelvicCurtain == false) {
		CurtainVector.emplace_back(CurtainState::NotWearing);
	}
	else if (Player->GetFactionRank(FlashingPelvicCurtainFaction, true) == 0) {
		CurtainVector.emplace_back(CurtainState::Covering);
	}
	else if (Player->GetFactionRank(FlashingPelvicCurtainFaction, true) == 1) {
		CurtainVector.emplace_back(CurtainState::Flashing);
	}
	else {
		CurtainVector.emplace_back(CurtainState::NotWearing);
	}

	//AssCurtain
	if (IsWearingAssCurtain == false) {
		CurtainVector.emplace_back(CurtainState::NotWearing);
	}
	else if (Player->GetFactionRank(FlashingAssCurtainFaction, true) == 0) {
		CurtainVector.emplace_back(CurtainState::Covering);
	}
	else if (Player->GetFactionRank(FlashingAssCurtainFaction, true) == 1) {
		CurtainVector.emplace_back(CurtainState::Flashing);
	}
	else {
		CurtainVector.emplace_back(CurtainState::NotWearing);
	}

	return CurtainVector;
}

std::vector<bool> FemaleWornKeywordList(RE::StaticFunctionTag*) {
	std::vector<bool> FemaleKeywordList;

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorTop])); //0
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorTop_NoCover])); //1
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorTopT_Low])); //2
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorTopT])); //3
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorTopT_High])); // 4

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorBottom])); //5
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorBottom_NoCover])); //6
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorBottomT_Low])); //7
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorBottomT])); //8
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ArmorBottomT_High])); //9

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[AssCurtain])); //10
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[AssCurtainT])); //11

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskLow])); //12
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[AssFlashRisk])); //13
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskHigh])); //14
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskExtreme])); //15
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskUltra])); //16

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Bra])); //17
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Bra_NoCover])); //18
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[BraT_Low])); //19
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[BraT])); //20
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[BraT_High])); //21

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ChestCurtain])); //22
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ChestCurtainT])); //23

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskLow])); //24
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[ChestFlashRisk])); //25
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskHigh])); //26
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskExtreme])); //27
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskUltra])); //28

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[CoversAll])); //29

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[CString])); //30
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[CStringT_Low])); //31
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[CStringT])); //32
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[CStringT_High])); //33

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[EffectivelyNaked])); //34

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Hotpants])); //35
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[HotpantsT_Low])); //36
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[HotpantsT])); //37
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[HotpantsT_High])); //38

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Microskirt])); //39

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Miniskirt])); //40
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[MiniskirtT])); //41

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[NearlyNaked])); //42
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[NipplePasties])); //43

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[PelvicCurtain])); //44
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[PelvicCurtainT])); //45

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskLow])); //46
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRisk])); //47
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskHigh])); //48
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskExtreme])); //49
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskUltra])); //50

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ShowgirlSkirt])); //51
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT_Low])); //52
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT])); //53
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT_High])); //54

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Thong])); //55
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Thong_NoCover])); //56
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ThongT_Low])); //57
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ThongT])); //58
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[ThongT_High])); //59

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Underwear])); //60
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[Underwear_NoCover])); //61
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[UnderwearT_Low])); //62
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[UnderwearT])); //63
	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[UnderwearT_High])); //64

	FemaleKeywordList.emplace_back(PlayerIsWearing(FemaleKeywords[VaginaPasties])); //65

	return FemaleKeywordList;
}

std::vector<bool> MaleWornKeywordList(RE::StaticFunctionTag*) {
	std::vector<bool> MaleKeywordList;

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorTop])); //0
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorTop_NoCover])); //1
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorTopT_Low])); //2
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorTopT])); //3
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorTopT_High])); // 4

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorBottom])); //5
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorBottom_NoCover])); //6
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorBottomT_Low])); //7
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorBottomT])); //8
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ArmorBottomT_High])); //9

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[AssCurtain])); //10
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[AssCurtainT])); //11

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[AssFlashRiskLow])); //12
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[AssFlashRisk])); //13
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[AssFlashRiskHigh])); //14
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[AssFlashRiskExtreme])); //15
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[AssFlashRiskUltra])); //16

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Bra])); //17
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Bra_NoCover])); //18
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[BraT_Low])); //19
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[BraT])); //20
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[BraT_High])); //21

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ChestCurtain])); //22
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ChestCurtainT])); //23

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskLow])); //24
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[ChestFlashRisk])); //25
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskHigh])); //26
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskExtreme])); //27
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskUltra])); //28

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[CoversAll])); //29

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[BananaHammock])); //30
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[BananaHammockT_Low])); //31
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[BananaHammockT])); //32
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[BananaHammockT_High])); //33

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[EffectivelyNaked])); //34

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Hotpants])); //35
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[HotpantsT_Low])); //36
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[HotpantsT])); //37
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[HotpantsT_High])); //38

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Microskirt])); //39

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Miniskirt])); //40
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[MiniskirtT])); //41

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[NearlyNaked])); //42
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[NipplePasties])); //43

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[PelvicCurtain])); //44
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[PelvicCurtainT])); //45

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskLow])); //46
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[PelvicFlashRisk])); //47
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskHigh])); //48
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskExtreme])); //49
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskUltra])); //50

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[HimboSkirt])); //51
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[HimboSkirtT_Low])); //52
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[HimboSkirtT])); //53
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[HimboSkirtT_High])); //54

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Thong])); //55
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Thong_NoCover])); //56
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ThongT_Low])); //57
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ThongT])); //58
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[ThongT_High])); //59

	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Underwear])); //60
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[Underwear_NoCover])); //61
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[UnderwearT_Low])); //62
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[UnderwearT])); //63
	MaleKeywordList.emplace_back(PlayerIsWearing(MaleKeywords[UnderwearT_High])); //64

	return MaleKeywordList;
}

std::vector<bool> NPCFemaleWornKeywordList(RE::StaticFunctionTag*, RE::Actor* akActor) {
	std::vector<bool> FemaleKeywordList;

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorTop])); //0
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorTop_NoCover])); //1
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorTopT_Low])); //2
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorTopT])); //3
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorTopT_High])); // 4

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorBottom])); //5
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorBottom_NoCover])); //6
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorBottomT_Low])); //7
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorBottomT])); //8
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ArmorBottomT_High])); //9

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[AssCurtain])); //10
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[AssCurtainT])); //11

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[AssFlashRiskLow])); //12
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[AssFlashRisk])); //13
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[AssFlashRiskHigh])); //14
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[AssFlashRiskExtreme])); //15
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[AssFlashRiskUltra])); //16

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Bra])); //17
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Bra_NoCover])); //18
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[BraT_Low])); //19
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[BraT])); //20
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[BraT_High])); //21

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ChestCurtain])); //22
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ChestCurtainT])); //23

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[ChestFlashRiskLow])); //24
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[ChestFlashRisk])); //25
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[ChestFlashRiskHigh])); //26
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[ChestFlashRiskExtreme])); //27
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[ChestFlashRiskUltra])); //28

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[CoversAll])); //29

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[CString])); //30
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[CStringT_Low])); //31
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[CStringT])); //32
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[CStringT_High])); //33

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[EffectivelyNaked])); //34

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Hotpants])); //35
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[HotpantsT_Low])); //36
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[HotpantsT])); //37
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[HotpantsT_High])); //38

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Microskirt])); //39

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Miniskirt])); //40
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[MiniskirtT])); //41

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[NearlyNaked])); //42
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[NipplePasties])); //43

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[PelvicCurtain])); //44
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[PelvicCurtainT])); //45

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[PelvicFlashRiskLow])); //46
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[PelvicFlashRisk])); //47
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[PelvicFlashRiskHigh])); //48
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[PelvicFlashRiskExtreme])); //49
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, FemaleKeywords[PelvicFlashRiskUltra])); //50

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ShowgirlSkirt])); //51
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ShowgirlSkirtT_Low])); //52
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ShowgirlSkirtT])); //53
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ShowgirlSkirtT_High])); //54

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Thong])); //55
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Thong_NoCover])); //56
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ThongT_Low])); //57
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ThongT])); //58
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[ThongT_High])); //59

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Underwear])); //60
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[Underwear_NoCover])); //61
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[UnderwearT_Low])); //62
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[UnderwearT])); //63
	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[UnderwearT_High])); //64

	FemaleKeywordList.emplace_back(ActorIsWearing(akActor, FemaleKeywords[VaginaPasties])); //65

	return FemaleKeywordList;
}

std::vector<bool> NPCMaleWornKeywordList(RE::StaticFunctionTag*, RE::Actor* akActor) {
	std::vector<bool> MaleKeywordList;

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorTop])); //0
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorTop_NoCover])); //1
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorTopT_Low])); //2
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorTopT])); //3
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorTopT_High])); // 4

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorBottom])); //5
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorBottom_NoCover])); //6
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorBottomT_Low])); //7
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorBottomT])); //8
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ArmorBottomT_High])); //9

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[AssCurtain])); //10
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[AssCurtainT])); //11

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[AssFlashRiskLow])); //12
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[AssFlashRisk])); //13
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[AssFlashRiskHigh])); //14
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[AssFlashRiskExtreme])); //15
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[AssFlashRiskUltra])); //16

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Bra])); //17
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Bra_NoCover])); //18
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[BraT_Low])); //19
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[BraT])); //20
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[BraT_High])); //21

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ChestCurtain])); //22
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ChestCurtainT])); //23

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[ChestFlashRiskLow])); //24
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[ChestFlashRisk])); //25
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[ChestFlashRiskHigh])); //26
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[ChestFlashRiskExtreme])); //27
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[ChestFlashRiskUltra])); //28

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[CoversAll])); //29

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[BananaHammock])); //30
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[BananaHammockT_Low])); //31
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[BananaHammockT])); //32
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[BananaHammockT_High])); //33

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[EffectivelyNaked])); //34

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Hotpants])); //35
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[HotpantsT_Low])); //36
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[HotpantsT])); //37
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[HotpantsT_High])); //38

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Microskirt])); //39

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Miniskirt])); //40
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[MiniskirtT])); //41

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[NearlyNaked])); //42
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[NipplePasties])); //43

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[PelvicCurtain])); //44
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[PelvicCurtainT])); //45

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[PelvicFlashRiskLow])); //46
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[PelvicFlashRisk])); //47
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[PelvicFlashRiskHigh])); //48
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[PelvicFlashRiskExtreme])); //49
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MaleKeywords[PelvicFlashRiskUltra])); //50

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[HimboSkirt])); //51
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[HimboSkirtT_Low])); //52
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[HimboSkirtT])); //53
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[HimboSkirtT_High])); //54

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Thong])); //55
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Thong_NoCover])); //56
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ThongT_Low])); //57
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ThongT])); //58
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[ThongT_High])); //59

	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Underwear])); //60
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[Underwear_NoCover])); //61
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[UnderwearT_Low])); //62
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[UnderwearT])); //63
	MaleKeywordList.emplace_back(ActorIsWearing(akActor, MaleKeywords[UnderwearT_High])); //64

	return MaleKeywordList;
}

std::vector<int> GetPlayerFactionRanks(RE::StaticFunctionTag*) {
	std::vector<int> FactionRanks;

	FactionRanks.emplace_back(Player->GetFactionRank(NudeFaction, true)); //0
	FactionRanks.emplace_back(Player->GetFactionRank(ToplessFaction, true)); //1
	FactionRanks.emplace_back(Player->GetFactionRank(BottomlessFaction, true)); //2
	FactionRanks.emplace_back(Player->GetFactionRank(ShowingChestFaction, true)); //3
	FactionRanks.emplace_back(Player->GetFactionRank(ShowingGenitalsFaction, true)); //4
	FactionRanks.emplace_back(Player->GetFactionRank(ShowingAssFaction, true)); //5
	FactionRanks.emplace_back(Player->GetFactionRank(ShowingBraFaction, true)); //6
	FactionRanks.emplace_back(Player->GetFactionRank(ShowingUnderwearFaction, true)); //7

	FactionRanks.emplace_back(Player->GetFactionRank(ModestyFaction, true)); //8
	FactionRanks.emplace_back(Player->GetFactionRank(TopModestyFaction, true)); //9
	FactionRanks.emplace_back(Player->GetFactionRank(BottomModestyFaction, true)); //10

	FactionRanks.emplace_back(Player->GetFactionRank(ShyWithFemale, true)); //11
	FactionRanks.emplace_back(Player->GetFactionRank(ShyWithMale, true)); //12

	FactionRanks.emplace_back(Player->GetFactionRank(ArousalFaction, true)); //13

	return FactionRanks;
}

void UpdatePlayerShySex(RE::StaticFunctionTag*, bool ShyWithMaleRank, bool ShyWithFemaleRank) {
	SetPlayerFactionRank(ShyWithMale, ShyWithMaleRank);
	SetPlayerFactionRank(ShyWithFemale, ShyWithFemaleRank);
}

std::vector<int> GetPlayerStrictModestyTimers(RE::StaticFunctionTag*) {
	std::vector<int> StrictTimers;

	StrictTimers.emplace_back(StrictModestyTimer[0]);
	StrictTimers.emplace_back(StrictModestyTimer[1]);
	StrictTimers.emplace_back(StrictModestyTimer[2]);
	StrictTimers.emplace_back(StrictModestyTimer[3]);
	StrictTimers.emplace_back(StrictModestyTimer[4]);
	StrictTimers.emplace_back(StrictModestyTimer[5]);
	StrictTimers.emplace_back(StrictModestyTimer[6]);

	return StrictTimers;
}

std::vector<int> GetPlayerSimpleModestyTimers(RE::StaticFunctionTag*) {
	std::vector<int> SimpleTimers;

	SimpleTimers.emplace_back(TopModestyTimer[0] + (TopModestyTimer[1] / 2) + (TopModestyTimer[2] / 4)); //0
	SimpleTimers.emplace_back(TopModestyTimer[1] + (TopModestyTimer[2] / 2)); //1
	SimpleTimers.emplace_back(TopModestyTimer[2]); //2
	SimpleTimers.emplace_back(TopModestyTimer[3]); //3

	SimpleTimers.emplace_back(BottomModestyTimer[0] + (BottomModestyTimer[1] / 2) + (BottomModestyTimer[2] / 4)); //4
	SimpleTimers.emplace_back(BottomModestyTimer[1] + (BottomModestyTimer[2] / 2)); //5
	SimpleTimers.emplace_back(BottomModestyTimer[2]); //6
	SimpleTimers.emplace_back(BottomModestyTimer[3]); //7

	return SimpleTimers;
}

int GetRegisteredFemalesPages(RE::StaticFunctionTag*) {
	Log("<C++ Config> [GetRegisteredFemalesPages] Getting Registered Females Pages...");
	return ((int)(RegisteredFemaleMap.size()) - 1) / 128 + 1;
}

int GetPermanentFemalesPages(RE::StaticFunctionTag*) {
	Log("<C++ Config> [GetPermanentFemalesPages] Getting Permanent Females Pages...");
	return ((int)(PermanentFemaleVector.size()) - 1) / 128 + 1;
}

std::vector<RE::BSFixedString> GetRegisteredFemaleNames(RE::StaticFunctionTag*, int PageNumber) {
	std::vector<RE::BSFixedString> FemaleNames;

	for (auto& [ID, Female] : RegisteredFemaleMap)
	{
		FemaleNames.emplace_back(Female.GetName());
	}

	std::vector<RE::BSFixedString> ReturnVector;

	if (PageNumber < 1) {
		PageNumber = 1;
	}

	int MinimumIndex = 128 * (PageNumber - 1);
	int MaximumIndex = 128 + MinimumIndex;

	int CurrentIndex = MinimumIndex;
	for (CurrentIndex; CurrentIndex < MaximumIndex && CurrentIndex < FemaleNames.size(); ++CurrentIndex) {
		ReturnVector.emplace_back(FemaleNames[CurrentIndex]);
	}

	return ReturnVector;
}

std::vector<RE::BSFixedString> GetPermanentFemaleNames(RE::StaticFunctionTag*, int PageNumber) {
	std::vector<RE::BSFixedString> FemaleNames;

	for (auto& Female : PermanentFemaleVector)
	{
		FemaleNames.emplace_back(Female.Name);
	}

	std::vector<RE::BSFixedString> ReturnVector;

	if (PageNumber < 1) {
		PageNumber = 1;
	}

	int MinimumIndex = 128 * (PageNumber - 1);
	int MaximumIndex = 128 + MinimumIndex;

	int CurrentIndex = MinimumIndex;
	for (CurrentIndex; CurrentIndex < MaximumIndex && CurrentIndex < FemaleNames.size(); ++CurrentIndex) {
		ReturnVector.emplace_back(FemaleNames[CurrentIndex]);
	}

	return ReturnVector;
}

std::vector<RE::Actor*> GetRegisteredFemaleActors(RE::StaticFunctionTag*, int PageNumber) {
	std::vector<RE::Actor*> FemaleActors;

	for(auto& [ID, Female] : RegisteredFemaleMap)
	{
		FemaleActors.emplace_back(RE::TESForm::LookupByID<RE::Actor>(Female.FemaleFormID));
	}

	std::vector<RE::Actor*> ReturnVector;

	if (PageNumber < 1) {
		PageNumber = 1;
	}

	int MinimumIndex = 128 * (PageNumber - 1);
	int MaximumIndex = 128 + MinimumIndex;

	int CurrentIndex = MinimumIndex;
	for (CurrentIndex; CurrentIndex < MaximumIndex && CurrentIndex < FemaleActors.size(); ++CurrentIndex) {
		ReturnVector.emplace_back(FemaleActors[CurrentIndex]);
	}

	return ReturnVector;
}

std::vector<RE::Actor*> GetPermanentFemaleActors(RE::StaticFunctionTag*, int PageNumber)
{
	std::vector<RE::Actor*> FemaleActors;

	for(auto& Female : PermanentFemaleVector)
	{
		uint32_t ModIndex = Female.GetModIndex();
		Log("<C++ Config> [GetPermanentFemaleActors] Female " + static_cast<std::string>(Female.GetName()), Logger::LogType::Config, Logger::LoggingLevel::info);

		if (Female.GetPluginFile()->IsLight()) {
			ModIndex += 0xFE000000;
			Log("<C++ Config> [GetPermanentFemaleActors] ModIndex " + std::format("{:08X}", ModIndex), Logger::LogType::Config, Logger::LoggingLevel::info);
			Log("<C++ Config> [GetPermanentFemaleActors] LocalID " + std::format("{:08X}", Female.LocalID), Logger::LogType::Config, Logger::LoggingLevel::info);
			Log("<C++ Config> [GetPermanentFemaleActors] Combined ID " + std::format("{:08X}", ModIndex | Female.LocalID), Logger::LogType::Config, Logger::LoggingLevel::info);
		}
		else {
			Log("<C++ Config> [GetPermanentFemaleActors] ModIndex " + std::format("{:08X}", ModIndex), Logger::LogType::Config, Logger::LoggingLevel::info);
			Log("<C++ Config> [GetPermanentFemaleActors] LocalID " + std::format("{:08X}", Female.LocalID), Logger::LogType::Config, Logger::LoggingLevel::info);
			Log("<C++ Config> [GetPermanentFemaleActors] Combined ID " + std::format("{:08X}", ModIndex | Female.LocalID), Logger::LogType::Config, Logger::LoggingLevel::info);
		}

		RE::Actor* ValidActor = RE::TESForm::LookupByID<RE::Actor>(ModIndex | Female.LocalID);
		if (!ValidActor) { 
			Log("<C++ Config> [GetPermanentFemaleActors] Actor is invalid! Skipping...", Logger::LogType::Config, Logger::LoggingLevel::info);
			continue; 
		}

		FemaleActors.emplace_back(ValidActor);
	}

	std::vector<RE::Actor*> ReturnVector;

	if (PageNumber < 1) {
		PageNumber = 1;
	}

	int MinimumIndex = 128 * (PageNumber - 1);
	int MaximumIndex = 128 + MinimumIndex;

	int CurrentIndex = MinimumIndex;
	for (CurrentIndex; CurrentIndex < MaximumIndex && CurrentIndex < FemaleActors.size(); ++CurrentIndex) {
		ReturnVector.emplace_back(FemaleActors[CurrentIndex]);
	}

	return ReturnVector;
}

std::string GetFemaleActorFormID(RE::StaticFunctionTag*, RE::Actor* akFemale) {
	if (akFemale == nullptr) {
		return "NULL";
	}
	
	RE::FormID FemaleForm = akFemale->GetFormID();
	if (!RegisteredFemaleMap.count(FemaleForm))
	{
		Log("<C++ Config> [GetFemaleActorFormID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", FemaleForm) + ") cannot be found in Registered Female list!", Logger::LogType::Config, Logger::LoggingLevel::error);

		return "UNREGISTERED";
	}

	return std::format("{:08X}", FemaleForm);
}

std::vector<int> GetFemaleActorData(RE::StaticFunctionTag*, RE::Actor* akFemale)
{
	std::vector<int> FemaleActorData;

	RE::FormID FemaleForm = akFemale->GetFormID();
	if(!RegisteredFemaleMap.count(FemaleForm))
	{
		Log("<C++ Config> [GetFemaleActorData] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", FemaleForm) + ") cannot be found in Registered Female list!", Logger::LogType::Config, Logger::LoggingLevel::error);
		
		return FemaleActorData;
	}

	RegisteredFemales& ThisFemale = RegisteredFemaleMap[FemaleForm];
	
	FemaleActorData.emplace_back(ThisFemale.CurrentRankStrict);
	FemaleActorData.emplace_back(ThisFemale.MinimumRankStrict);

	FemaleActorData.emplace_back(ThisFemale.CurrentRankTop);
	FemaleActorData.emplace_back(ThisFemale.MinimumRankTop);

	FemaleActorData.emplace_back(ThisFemale.CurrentRankBottom);
	FemaleActorData.emplace_back(ThisFemale.MinimumRankBottom);

	FemaleActorData.emplace_back(ThisFemale.AllowShameless);
	FemaleActorData.emplace_back(ThisFemale.AllowCorruption);

	FemaleActorData.emplace_back(ThisFemale.ShynessMode);
	FemaleActorData.emplace_back(ThisFemale.StrictRules);
	FemaleActorData.emplace_back(ThisFemale.UpgradeBlocked);

	return FemaleActorData;
}

std::vector<bool> GetConfigBoolOptions(RE::StaticFunctionTag*) {
	std::vector<bool> Options;

	Options.emplace_back(Configuration::MotionFlashEnabled); //0
	Options.emplace_back(Configuration::DynamicModestyEnabled); //1

	Options.emplace_back(Configuration::AllowPlayerShameless); //2
	Options.emplace_back(Configuration::NPCShamelessByDefault); //3
	
	Options.emplace_back(Configuration::AllowPlayerCorruption); //4
	Options.emplace_back(Configuration::NPCCorruptionByDefault); //5
	
	Options.emplace_back(Configuration::StrictModestyRules); //6
	Options.emplace_back(Configuration::NPCStrictRulesByDefault); //7

	Options.emplace_back(Configuration::HardcoreModeEnabled); //8

	Options.emplace_back(Configuration::ModestyUpgradeBlocked); //9
	Options.emplace_back(Configuration::DisableNakedComments); //10

	return Options;
}

void UpdateConfigBoolOptions(RE::StaticFunctionTag*, std::vector<bool> Options) {
	Configuration::MotionFlashEnabled = Options[0];
	Configuration::DynamicModestyEnabled = Options[1];
	if (Configuration::DynamicModestyEnabled == false) {
		Configuration::DynamicModestyMode->value = 0;
	}

	Configuration::AllowPlayerShameless = Options[2];
	Configuration::NPCShamelessByDefault = Options[3];
	
	Configuration::AllowPlayerCorruption = Options[4];
	Configuration::NPCCorruptionByDefault = Options[5];
	
	Configuration::StrictModestyRules = Options[6];
	if (InstalledMods::DFFMA && Configuration::StrictModestyRules) {
		Configuration::DynamicModestyMode->value = 1;
	}
	else if (InstalledMods::DFFMA && !Configuration::StrictModestyRules) {
		Configuration::DynamicModestyMode->value = 2;
	}
	Configuration::NPCStrictRulesByDefault = Options[7];

	Configuration::HardcoreModeEnabled = Options[8];
	Configuration::ModestyUpgradeBlocked = Options[9];
	Configuration::DisableNakedComments = Options[10];
}

std::vector<int> GetConfigIntOptions(RE::StaticFunctionTag*) {
	std::vector<int> Options;

	Options.emplace_back(Configuration::RunningMod); //0
	Options.emplace_back(Configuration::SprintingMod); //1

	Options.emplace_back(Configuration::MinimumStrictModestyRank); //2
	Options.emplace_back(Configuration::MinimumTopModestyRank); //3
	Options.emplace_back(Configuration::MinimumBottomModestyRank); //4

	Options.emplace_back(Configuration::ImmodestyTimeNeeded); //5
	Options.emplace_back(Configuration::PlayerConfidenceLevel); //6

	Options.emplace_back(Configuration::NudeCommentChance); //7
	Options.emplace_back(Configuration::ToplessCommentChance); //8
	Options.emplace_back(Configuration::BottomlessCommentChance); //9
	Options.emplace_back(Configuration::ChestCommentChance); //10
	Options.emplace_back(Configuration::GenitalsCommentChance); //11
	Options.emplace_back(Configuration::AssCommentChance); //12
	Options.emplace_back(Configuration::BraCommentChance); //13
	Options.emplace_back(Configuration::UnderwearCommentChance); //14

	return Options;
}

void UpdateConfigIntOptions(RE::StaticFunctionTag*, std::vector<int> Options) {
	Configuration::RunningMod = (UINT8)Options[0];
	Configuration::SprintingMod = (UINT8)Options[1];

	Configuration::MinimumStrictModestyRank = (UINT8)Options[2];
	Configuration::MinimumTopModestyRank = (UINT8)Options[3];
	Configuration::MinimumBottomModestyRank = (UINT8)Options[4];
	
	Configuration::ImmodestyTimeNeeded = (UINT16)Options[5];
	Configuration::PlayerConfidenceLevel = (UINT8)Options[6];

	Configuration::NudeCommentChance = (UINT8)Options[7];
	Configuration::ToplessCommentChance = (UINT8)Options[8];
	Configuration::BottomlessCommentChance = (UINT8)Options[9];
	Configuration::ChestCommentChance = (UINT8)Options[10];
	Configuration::GenitalsCommentChance = (UINT8)Options[11];
	Configuration::AssCommentChance = (UINT8)Options[12];
	Configuration::BraCommentChance = (UINT8)Options[13];
	Configuration::UnderwearCommentChance = (UINT8)Options[14];
}

bool GetDynamicModestyEnabledByOtherMod(RE::StaticFunctionTag*) {
	for (int Index = 0; Index < RegisteredPlugins::Plugins.size(); ++Index) {
		if (RegisteredPlugins::DynamicModestyEnabled[Index]) {
			return true;
		}
	}
	return false;
}

bool IsPlayerFemale(RE::StaticFunctionTag*) {
	return PlayerBase->IsFemale();
}