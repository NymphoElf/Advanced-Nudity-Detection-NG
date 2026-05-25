#pragma once

enum FlashingIndex {
	//Curtain Odds
	
	ChestCurtainOddsLow,
	ChestCurtainOdds,
	ChestCurtainOddsHigh,
	ChestCurtainOddsExtreme,
	ChestCurtainOddsUltra,

	PelvicCurtainOddsLow,
	PelvicCurtainOdds,
	PelvicCurtainOddsHigh,
	PelvicCurtainOddsExtreme,
	PelvicCurtainOddsUltra,

	AssCurtainOddsLow,
	AssCurtainOdds,
	AssCurtainOddsHigh,
	AssCurtainOddsExtreme,
	AssCurtainOddsUltra,

	TransparentChestCurtainOddsLow,
	TransparentChestCurtainOdds,
	TransparentChestCurtainOddsHigh,
	TransparentChestCurtainOddsExtreme,
	TransparentChestCurtainOddsUltra,

	TransparentPelvicCurtainOddsLow,
	TransparentPelvicCurtainOdds,
	TransparentPelvicCurtainOddsHigh,
	TransparentPelvicCurtainOddsExtreme,
	TransparentPelvicCurtainOddsUltra,

	TransparentAssCurtainOddsLow,
	TransparentAssCurtainOdds,
	TransparentAssCurtainOddsHigh,
	TransparentAssCurtainOddsExtreme,
	TransparentAssCurtainOddsUltra,

	//Armor Piece Odds

	TransparentTopArmorOdds_Low,
	TransparentTopArmorOdds,
	TransparentTopArmorOdds_High,

	TransparentBottomArmorOdds_Low,
	TransparentBottomArmorOdds,
	TransparentBottomArmorOdds_High,

	TransparentBraOdds_Low,
	TransparentBraOdds,
	TransparentBraOdds_High,

	TransparentUnderwearOdds_Low,
	TransparentUnderwearOdds,
	TransparentUnderwearOdds_High,

	TransparentHotpantsOdds_Low,
	TransparentHotpantsOdds,
	TransparentHotpantsOdds_High,

	TransparentShowgirlOdds_Low,
	TransparentShowgirlOdds,
	TransparentShowgirlOdds_High,

	//CString Odds

	CStringOdds,
	TransparentCStringOdds_Low,
	TransparentCStringOdds,
	TransparentCStringOdds_High,

	//Curtain Odds MALE

	ChestCurtainOddsLow_Male,
	ChestCurtainOdds_Male,
	ChestCurtainOddsHigh_Male,
	ChestCurtainOddsExtreme_Male,
	ChestCurtainOddsUltra_Male,

	PelvicCurtainOddsLow_Male,
	PelvicCurtainOdds_Male,
	PelvicCurtainOddsHigh_Male,
	PelvicCurtainOddsExtreme_Male,
	PelvicCurtainOddsUltra_Male,

	AssCurtainOddsLow_Male,
	AssCurtainOdds_Male,
	AssCurtainOddsHigh_Male,
	AssCurtainOddsExtreme_Male,
	AssCurtainOddsUltra_Male,

	TransparentChestCurtainOddsLow_Male,
	TransparentChestCurtainOdds_Male,
	TransparentChestCurtainOddsHigh_Male,
	TransparentChestCurtainOddsExtreme_Male,
	TransparentChestCurtainOddsUltra_Male,

	TransparentPelvicCurtainOddsLow_Male,
	TransparentPelvicCurtainOdds_Male,
	TransparentPelvicCurtainOddsHigh_Male,
	TransparentPelvicCurtainOddsExtreme_Male,
	TransparentPelvicCurtainOddsUltra_Male,

	TransparentAssCurtainOddsLow_Male,
	TransparentAssCurtainOdds_Male,
	TransparentAssCurtainOddsHigh_Male,
	TransparentAssCurtainOddsExtreme_Male,
	TransparentAssCurtainOddsUltra_Male,

	//Armor Piece Odds MALE

	TransparentTopArmorOdds_Low_Male,
	TransparentTopArmorOdds_Male,
	TransparentTopArmorOdds_High_Male,

	TransparentBottomArmorOdds_Low_Male,
	TransparentBottomArmorOdds_Male,
	TransparentBottomArmorOdds_High_Male,

	TransparentBraOdds_Low_Male,
	TransparentBraOdds_Male,
	TransparentBraOdds_High_Male,

	TransparentUnderwearOdds_Low_Male,
	TransparentUnderwearOdds_Male,
	TransparentUnderwearOdds_High_Male,

	TransparentHotpantsOdds_Low_Male,
	TransparentHotpantsOdds_Male,
	TransparentHotpantsOdds_High_Male,

	TransparentHimboOdds_Low,
	TransparentHimboOdds,
	TransparentHimboOdds_High,

	//BananaHammock Odds

	BananaHammockOdds,
	TransparentBananaHammockOdds_Low,
	TransparentBananaHammockOdds,
	TransparentBananaHammockOdds_High,

	//KEEP THIS AS LAST ENUM ENTRY

	FlashingOddsLength
};

//Integers
namespace Configuration {
	inline int FlashingOdds[FlashingOddsLength];

	inline int ImmodestyTimeNeeded;

	inline int MinimumStrictModestyRank;
	inline int MinimumTopModestyRank;
	inline int MinimumBottomModestyRank;

	inline int DefaultNPCShyness;

	inline int SprintingMod;
	inline int RunningMod;

	inline int PlayerConfidenceLevel;

	//Booleans

	inline bool MotionFlashEnabled;
	inline bool DynamicModestyEnabled;

	inline bool AllowPlayerShameless;
	inline bool NPCShamelessByDefault;

	inline bool AllowPlayerCorruption;
	inline bool NPCCorruptionByDefault;

	inline bool StrictModestyRules;
	inline bool NPCStrictRulesByDefault;

	inline bool HardcoreModeEnabled;
	//inline bool HardcoreLockdown;

	inline bool ModestyUpgradeBlocked;

	//Skyrim Global Variables
	inline RE::TESGlobal* DynamicModestyMode;
}

//Functions

void InitializeConfigData();

std::vector<int> GetFlashOddsArray(RE::StaticFunctionTag*);
void UpdateFlashingOdds(RE::StaticFunctionTag*, int FlashOddsIndex, int OddsValue);

std::vector<int> GetFlashRolls(RE::StaticFunctionTag*);

std::vector<int> GetCurtainCoverage(RE::StaticFunctionTag*);

std::vector<RE::BSFixedString> GetRegisteredFemaleNames(RE::StaticFunctionTag*);
std::vector<RE::Actor*> GetRegisteredFemaleActors(RE::StaticFunctionTag*);

std::vector<RE::BSFixedString> GetPermanentFemaleNames(RE::StaticFunctionTag*);
std::vector<RE::Actor*> GetPermanentFemaleActors(RE::StaticFunctionTag*);

std::vector<int> GetFemaleActorData(RE::StaticFunctionTag*, RE::Actor* akFemale);

std::vector<bool> FemaleWornKeywordList(RE::StaticFunctionTag*);
std::vector<bool> MaleWornKeywordList(RE::StaticFunctionTag*);
std::vector<bool> NPCFemaleWornKeywordList(RE::StaticFunctionTag*, RE::Actor* akActor);
std::vector<bool> NPCMaleWornKeywordList(RE::StaticFunctionTag*, RE::Actor* akActor);

std::vector<int> GetPlayerFactionRanks(RE::StaticFunctionTag*);
std::vector<int> GetPlayerStrictModestyTimers(RE::StaticFunctionTag*);
std::vector<int> GetPlayerSimpleModestyTimers(RE::StaticFunctionTag*);

std::vector<bool> GetConfigBoolOptions(RE::StaticFunctionTag*);
void UpdateConfigBoolOptions(RE::StaticFunctionTag*, std::vector<bool> Options);

std::vector<int> GetConfigIntOptions(RE::StaticFunctionTag*);
void UpdateConfigIntOptions(RE::StaticFunctionTag*, std::vector<int> Options);