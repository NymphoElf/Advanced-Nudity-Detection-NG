#include <vector>

#include "Config.h"
#include "Player.h"
#include "Core.h"
#include "NPCData.h"
#include "PlayerModesty.h"
#include "Logger.h"

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

	Configuration::DynamicModestyMode->value = InstalledMods::DFFMA;

	Log("<C++ Config> [InitializeConfigData] COMPLETE");
}

void UpdateFlashingOdds(RE::StaticFunctionTag*, int FlashOddsIndex, int OddsValue) {
	Configuration::FlashingOdds[FlashOddsIndex] = OddsValue;
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

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTop)); //0
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTop_NoCover)); //1
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTopT_Low)); //2
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTopT)); //3
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTopT_High)); // 4

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottom)); //5
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottom_NoCover)); //6
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottomT_Low)); //7
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottomT)); //8
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottomT_High)); //9

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(AssCurtain)); //10
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(AssCurtainT)); //11

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskLow)); //12
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRisk)); //13
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskHigh)); //14
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskExtreme)); //15
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskUltra)); //16

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Bra)); //17
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Bra_NoCover)); //18
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(BraT_Low)); //19
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(BraT)); //20
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(BraT_High)); //21

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestCurtain)); //22
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestCurtainT)); //23

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskLow)); //24
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRisk)); //25
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskHigh)); //26
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskExtreme)); //27
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskUltra)); //28

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(CoversAll)); //29

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(CString)); //30
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(CStringT_Low)); //31
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(CStringT)); //32
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(CStringT_High)); //33

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(EffectivelyNaked)); //34

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Hotpants)); //35
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(HotpantsT_Low)); //36
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(HotpantsT)); //37
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(HotpantsT_High)); //38

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Microskirt)); //39

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Miniskirt)); //40
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(MiniskirtT)); //41

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(NearlyNaked)); //42
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(NipplePasties)); //43

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicCurtain)); //44
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicCurtainT)); //45

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskLow)); //46
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRisk)); //47
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskHigh)); //48
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskExtreme)); //49
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskUltra)); //50

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ShowgirlSkirt)); //51
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ShowgirlSkirtT_Low)); //52
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ShowgirlSkirtT)); //53
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ShowgirlSkirtT_High)); //54

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Thong)); //55
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Thong_NoCover)); //56
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ThongT_Low)); //57
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ThongT)); //58
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(ThongT_High)); //59

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Underwear)); //60
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(Underwear_NoCover)); //61
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(UnderwearT_Low)); //62
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(UnderwearT)); //63
	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(UnderwearT_High)); //64

	FemaleKeywordList.emplace_back(PlayerWornHasKeyword(VaginaPasties)); //65

	return FemaleKeywordList;
}

std::vector<bool> MaleWornKeywordList(RE::StaticFunctionTag*) {
	std::vector<bool> MaleKeywordList;

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTop_Male)); //0
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTop_NoCover_Male)); //1
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTopT_Low_Male)); //2
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTopT_Male)); //3
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorTopT_High_Male)); // 4

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottom_Male)); //5
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottom_NoCover_Male)); //6
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottomT_Low_Male)); //7
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottomT_Male)); //8
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ArmorBottomT_High_Male)); //9

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(AssCurtain_Male)); //10
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(AssCurtainT_Male)); //11

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskLow_Male)); //12
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRisk_Male)); //13
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskHigh_Male)); //14
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskExtreme_Male)); //15
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(AssFlashRiskUltra_Male)); //16

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Bra_Male)); //17
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Bra_NoCover_Male)); //18
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(BraT_Low_Male)); //19
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(BraT_Male)); //20
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(BraT_High_Male)); //21

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestCurtain_Male)); //22
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestCurtainT_Male)); //23

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskLow_Male)); //24
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRisk_Male)); //25
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskHigh_Male)); //26
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskExtreme_Male)); //27
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ChestFlashRiskUltra_Male)); //28

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(CoversAll_Male)); //29

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(BananaHammock)); //30
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(BananaHammockT_Low)); //31
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(BananaHammockT)); //32
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(BananaHammockT_High)); //33

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(EffectivelyNaked_Male)); //34

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Hotpants_Male)); //35
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(HotpantsT_Low_Male)); //36
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(HotpantsT_Male)); //37
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(HotpantsT_High_Male)); //38

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Microskirt_Male)); //39

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Miniskirt_Male)); //40
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(MiniskirtT_Male)); //41

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(NearlyNaked_Male)); //42
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(NipplePasties_Male)); //43

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicCurtain_Male)); //44
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicCurtainT_Male)); //45

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskLow_Male)); //46
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRisk_Male)); //47
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskHigh_Male)); //48
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskExtreme_Male)); //49
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(PelvicFlashRiskUltra_Male)); //50

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(HimboSkirt)); //51
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(HimboSkirtT_Low)); //52
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(HimboSkirtT)); //53
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(HimboSkirtT_High)); //54

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Thong_Male)); //55
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Thong_NoCover_Male)); //56
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ThongT_Low_Male)); //57
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ThongT_Male)); //58
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(ThongT_High_Male)); //59

	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Underwear_Male)); //60
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(Underwear_NoCover_Male)); //61
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(UnderwearT_Low_Male)); //62
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(UnderwearT_Male)); //63
	MaleKeywordList.emplace_back(PlayerWornHasKeyword(UnderwearT_High_Male)); //64

	return MaleKeywordList;
}

std::vector<bool> NPCFemaleWornKeywordList(RE::StaticFunctionTag*, RE::Actor* akActor) {
	std::vector<bool> FemaleKeywordList;

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTop)); //0
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTop_NoCover)); //1
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTopT_Low)); //2
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTopT)); //3
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTopT_High)); // 4

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottom)); //5
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottom_NoCover)); //6
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottomT_Low)); //7
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottomT)); //8
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottomT_High)); //9

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssCurtain)); //10
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssCurtainT)); //11

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskLow)); //12
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRisk)); //13
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskHigh)); //14
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskExtreme)); //15
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskUltra)); //16

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Bra)); //17
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Bra_NoCover)); //18
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BraT_Low)); //19
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BraT)); //20
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BraT_High)); //21

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestCurtain)); //22
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestCurtainT)); //23

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskLow)); //24
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRisk)); //25
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskHigh)); //26
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskExtreme)); //27
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskUltra)); //28

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, CoversAll)); //29

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, CString)); //30
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, CStringT_Low)); //31
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, CStringT)); //32
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, CStringT_High)); //33

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, EffectivelyNaked)); //34

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Hotpants)); //35
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HotpantsT_Low)); //36
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HotpantsT)); //37
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HotpantsT_High)); //38

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Microskirt)); //39

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Miniskirt)); //40
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MiniskirtT)); //41

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, NearlyNaked)); //42
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, NipplePasties)); //43

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicCurtain)); //44
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicCurtainT)); //45

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskLow)); //46
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRisk)); //47
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskHigh)); //48
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskExtreme)); //49
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskUltra)); //50

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ShowgirlSkirt)); //51
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ShowgirlSkirtT_Low)); //52
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ShowgirlSkirtT)); //53
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ShowgirlSkirtT_High)); //54

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Thong)); //55
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Thong_NoCover)); //56
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ThongT_Low)); //57
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ThongT)); //58
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ThongT_High)); //59

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Underwear)); //60
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Underwear_NoCover)); //61
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, UnderwearT_Low)); //62
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, UnderwearT)); //63
	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, UnderwearT_High)); //64

	FemaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, VaginaPasties)); //65

	return FemaleKeywordList;
}

std::vector<bool> NPCMaleWornKeywordList(RE::StaticFunctionTag*, RE::Actor* akActor) {
	std::vector<bool> MaleKeywordList;

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTop_Male)); //0
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTop_NoCover_Male)); //1
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTopT_Low_Male)); //2
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTopT_Male)); //3
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorTopT_High_Male)); // 4

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottom_Male)); //5
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottom_NoCover_Male)); //6
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottomT_Low_Male)); //7
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottomT_Male)); //8
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ArmorBottomT_High_Male)); //9

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssCurtain_Male)); //10
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssCurtainT_Male)); //11

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskLow_Male)); //12
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRisk_Male)); //13
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskHigh_Male)); //14
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskExtreme_Male)); //15
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, AssFlashRiskUltra_Male)); //16

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Bra_Male)); //17
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Bra_NoCover_Male)); //18
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BraT_Low_Male)); //19
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BraT_Male)); //20
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BraT_High_Male)); //21

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestCurtain_Male)); //22
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestCurtainT_Male)); //23

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskLow_Male)); //24
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRisk_Male)); //25
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskHigh_Male)); //26
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskExtreme_Male)); //27
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ChestFlashRiskUltra_Male)); //28

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, CoversAll_Male)); //29

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BananaHammock)); //30
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BananaHammockT_Low)); //31
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BananaHammockT)); //32
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, BananaHammockT_High)); //33

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, EffectivelyNaked_Male)); //34

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Hotpants_Male)); //35
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HotpantsT_Low_Male)); //36
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HotpantsT_Male)); //37
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HotpantsT_High_Male)); //38

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Microskirt_Male)); //39

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Miniskirt_Male)); //40
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, MiniskirtT_Male)); //41

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, NearlyNaked_Male)); //42
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, NipplePasties_Male)); //43

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicCurtain_Male)); //44
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicCurtainT_Male)); //45

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskLow_Male)); //46
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRisk_Male)); //47
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskHigh_Male)); //48
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskExtreme_Male)); //49
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, PelvicFlashRiskUltra_Male)); //50

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HimboSkirt)); //51
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HimboSkirtT_Low)); //52
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HimboSkirtT)); //53
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, HimboSkirtT_High)); //54

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Thong_Male)); //55
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Thong_NoCover_Male)); //56
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ThongT_Low_Male)); //57
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ThongT_Male)); //58
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, ThongT_High_Male)); //59

	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Underwear_Male)); //60
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, Underwear_NoCover_Male)); //61
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, UnderwearT_Low_Male)); //62
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, UnderwearT_Male)); //63
	MaleKeywordList.emplace_back(ActorWornHasKeyword(akActor, UnderwearT_High_Male)); //64

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

	SimpleTimers.emplace_back(TopModestyTimer[0]); //0
	SimpleTimers.emplace_back(TopModestyTimer[1]); //1
	SimpleTimers.emplace_back(TopModestyTimer[2]); //2
	SimpleTimers.emplace_back(TopModestyTimer[3]); //3

	SimpleTimers.emplace_back(BottomModestyTimer[0]); //4
	SimpleTimers.emplace_back(BottomModestyTimer[1]); //5
	SimpleTimers.emplace_back(BottomModestyTimer[2]); //6
	SimpleTimers.emplace_back(BottomModestyTimer[3]); //7

	return SimpleTimers;
}

int GetRegisteredFemalesPages(RE::StaticFunctionTag*) {
	Log("<C++ Config> [GetRegisteredFemalesPages] Getting Registered Females Pages...");
	float MapSize = RegisteredFemaleMap.size();
	
	if (MapSize < 1) {
		return 1;
	}
	
	return (int)std::ceil(MapSize / 128);
}

int GetPermanentFemalesPages(RE::StaticFunctionTag*) {
	Log("<C++ Config> [GetPermanentFemalesPages] Getting Permanent Females Pages...");
	float VectorSize = PermanentFemaleVector.size();
	
	if (VectorSize < 1) {
		return 1;
	}

	return (int)std::ceil(VectorSize / 128);
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

		RE::Actor* ValidActor = RE::TESForm::LookupByID<RE::Actor>(ModIndex | Female.LocalID);
		if(!ValidActor) { continue; }

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
		Log("<C++ Config> [GetFemaleActorFormID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", FemaleForm) + ") cannot be found in Registered Female list!", LogType::Config, LoggingLevel::error);

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
		Log("<C++ Config> [GetFemaleActorData] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", FemaleForm) + ") cannot be found in Registered Female list!", LogType::Config, LoggingLevel::error);
		
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
	Configuration::RunningMod = Options[0];
	Configuration::SprintingMod = Options[1];

	Configuration::MinimumStrictModestyRank = Options[2];
	Configuration::MinimumTopModestyRank = Options[3];
	Configuration::MinimumBottomModestyRank = Options[4];
	
	Configuration::ImmodestyTimeNeeded = Options[5];
	Configuration::PlayerConfidenceLevel = Options[6];

	Configuration::NudeCommentChance = Options[7];
	Configuration::ToplessCommentChance = Options[8];
	Configuration::BottomlessCommentChance = Options[9];
	Configuration::ChestCommentChance = Options[10];
	Configuration::GenitalsCommentChance = Options[11];
	Configuration::AssCommentChance = Options[12];
	Configuration::BraCommentChance = Options[13];
	Configuration::UnderwearCommentChance = Options[14];
}