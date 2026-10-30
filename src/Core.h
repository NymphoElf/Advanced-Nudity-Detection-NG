#pragma once

namespace FlashRiskLevel {
	enum FlashRiskLevel {
		None,
		Low,
		Normal,
		High,
		Extreme,
		Ultra
	};
}

namespace FlashRiskType {
	enum FlashRiskType {
		Chest,
		Pelvic,
		Ass,
		Top,
		Bottom,
		Bra,
		Underwear,
		Thong,
		Hotpants,
		Showgirl,
		Himbo
	};
}

namespace StrictModestyLevel {
	enum StrictModestyLevel {
		Modest,
		Reasonable,
		Relaxed,
		Comfortable,
		Tease,
		Brazen,
		Immodest,
		Shameless
	};
}

namespace SimpleModestyLevel {
	enum SimpleModestyLevel {
		Modest,
		Comfortable,
		Brazen,
		Immodest,
		Shameless
	};
}

namespace TwoPartObject {
	enum TwoPartObject {
		ArmorTop,
		ArmorTopT_High,
		ArmorTopT,
		ArmorTopT_Low,
		ArmorBottom,
		ArmorBottomT_High,
		ArmorBottomT,
		ArmorBottomT_Low,
		Bra,
		BraT_High,
		BraT,
		BraT_Low,
		ArmorTop_Male,
		ArmorTopT_High_Male,
		ArmorTopT_Male,
		ArmorTopT_Low_Male,
		ArmorBottom_Male,
		ArmorBottomT_High_Male,
		ArmorBottomT_Male,
		ArmorBottomT_Low_Male,
		Bra_Male,
		BraT_High_Male,
		BraT_Male,
		BraT_Low_Male,

		TotalObjectTypes
	};

	inline std::array<std::string, TotalObjectTypes> TypeStrings;
}

enum ConfidenceLevel {
	Cowardly,
	Cautious,
	Average,
	Brave,
	Foolhardy,
	Randomized
};

enum VanillaRaceIndex {
	Altmer,
	AltmerVampire,
	Argonian,
	ArgonianVampire,
	Bosmer,
	BosmerVampire,
	Breton,
	BretonVampire,
	Dunmer,
	DunmerVampire,
	Imperial,
	ImperialVampire,
	Khajiit,
	KhajiitVampire,
	Nord,
	NordVampire,
	Orsimer,
	OrsimerVampire,
	Redguard,
	RedguardVampire
};

//Actors

inline RE::Actor* Player;
inline RE::Actor* Rosa;

//Actor Bases

inline RE::TESActorBase* PlayerBase;

//Calendar
inline RE::Calendar* GameCalendar;

//Data Handler
inline RE::TESDataHandler* GameDataHandler;

//Races

inline RE::TESRace* VanillaRaces[20];

inline RE::TESRace* PlayerBaseRace;
inline std::array<RE::TESRace*, 2> DefaultTransformations;
inline std::vector<RE::TESRace*> CustomTransformations;

//Factions

inline RE::TESFaction* NudeFaction;
inline RE::TESFaction* ToplessFaction;
inline RE::TESFaction* BottomlessFaction;
inline RE::TESFaction* ShowingChestFaction;
inline RE::TESFaction* ShowingGenitalsFaction;
inline RE::TESFaction* ShowingAssFaction;
inline RE::TESFaction* ShowingBraFaction;
inline RE::TESFaction* ShowingUnderwearFaction;

inline RE::TESFaction* ModestyFaction;
inline RE::TESFaction* TopModestyFaction;
inline RE::TESFaction* BottomModestyFaction;

inline RE::TESFaction* ShyWithMale;
inline RE::TESFaction* ShyWithFemale;

inline RE::TESFaction* ArousalFaction;

inline RE::TESFaction* FlashingChestCurtainFaction;
inline RE::TESFaction* FlashingPelvicCurtainFaction;
inline RE::TESFaction* FlashingAssCurtainFaction;

inline RE::TESFaction* FlashingTopArmorFaction;
inline RE::TESFaction* FlashingBottomArmorFaction;
inline RE::TESFaction* FlashingBraFaction;
inline RE::TESFaction* FlashingUnderwearFaction;
inline RE::TESFaction* FlashingCStringFaction;
inline RE::TESFaction* FlashingHotpantsFaction;
inline RE::TESFaction* FlashingShowgirlSkirtFaction;

/*================
UNIVERSAL KEYWORDS
================*/

//inline RE::BGSKeyword* Ignore;

/*=============
FEMALE KEYWORDS
=============*/

//Single-Part Objects

/*
inline RE::BGSKeyword* ArmorTop;
inline RE::BGSKeyword* ArmorTop_NoCover;
inline RE::BGSKeyword* ArmorTopT_Low;
inline RE::BGSKeyword* ArmorTopT;
inline RE::BGSKeyword* ArmorTopT_High;

inline RE::BGSKeyword* ArmorBottom;
inline RE::BGSKeyword* ArmorBottom_NoCover;
inline RE::BGSKeyword* ArmorBottomT_Low;
inline RE::BGSKeyword* ArmorBottomT;
inline RE::BGSKeyword* ArmorBottomT_High;

inline RE::BGSKeyword* AssCurtain;
inline RE::BGSKeyword* AssCurtainT;

inline RE::BGSKeyword* AssFlashRiskLow;
inline RE::BGSKeyword* AssFlashRisk;
inline RE::BGSKeyword* AssFlashRiskHigh;
inline RE::BGSKeyword* AssFlashRiskExtreme;
inline RE::BGSKeyword* AssFlashRiskUltra;

inline RE::BGSKeyword* Bra;
inline RE::BGSKeyword* Bra_NoCover;
inline RE::BGSKeyword* BraT_Low;
inline RE::BGSKeyword* BraT;
inline RE::BGSKeyword* BraT_High;

inline RE::BGSKeyword* ChestCurtain;
inline RE::BGSKeyword* ChestCurtainT;

inline RE::BGSKeyword* ChestFlashRiskLow;
inline RE::BGSKeyword* ChestFlashRisk;
inline RE::BGSKeyword* ChestFlashRiskHigh;
inline RE::BGSKeyword* ChestFlashRiskExtreme;
inline RE::BGSKeyword* ChestFlashRiskUltra;

inline RE::BGSKeyword* CoversAll;

inline RE::BGSKeyword* CString;
inline RE::BGSKeyword* CStringT_Low;
inline RE::BGSKeyword* CStringT;
inline RE::BGSKeyword* CStringT_High;

inline RE::BGSKeyword* EffectivelyNaked;

inline RE::BGSKeyword* Hotpants;
inline RE::BGSKeyword* HotpantsT_Low;
inline RE::BGSKeyword* HotpantsT;
inline RE::BGSKeyword* HotpantsT_High;

inline RE::BGSKeyword* Microskirt;

inline RE::BGSKeyword* Miniskirt;
inline RE::BGSKeyword* MiniskirtT;

inline RE::BGSKeyword* NipplePasties;
inline RE::BGSKeyword* NearlyNaked;

inline RE::BGSKeyword* PelvicCurtain;
inline RE::BGSKeyword* PelvicCurtainT;

inline RE::BGSKeyword* PelvicFlashRiskLow;
inline RE::BGSKeyword* PelvicFlashRisk;
inline RE::BGSKeyword* PelvicFlashRiskHigh;
inline RE::BGSKeyword* PelvicFlashRiskExtreme;
inline RE::BGSKeyword* PelvicFlashRiskUltra;

inline RE::BGSKeyword* ShowgirlSkirt;
inline RE::BGSKeyword* ShowgirlSkirtT_Low;
inline RE::BGSKeyword* ShowgirlSkirtT;
inline RE::BGSKeyword* ShowgirlSkirtT_High;

inline RE::BGSKeyword* Thong;
inline RE::BGSKeyword* Thong_NoCover;
inline RE::BGSKeyword* ThongT_Low;
inline RE::BGSKeyword* ThongT;
inline RE::BGSKeyword* ThongT_High;

inline RE::BGSKeyword* Underwear;
inline RE::BGSKeyword* Underwear_NoCover;
inline RE::BGSKeyword* UnderwearT_Low;
inline RE::BGSKeyword* UnderwearT;
inline RE::BGSKeyword* UnderwearT_High;

inline RE::BGSKeyword* VaginaPasties;
*/

enum FemaleKeyword {
	 ArmorTop,
	 ArmorTop_NoCover,
	 ArmorTopT_Low,
	 ArmorTopT,
	 ArmorTopT_High,

	 ArmorBottom,
	 ArmorBottom_NoCover,
	 ArmorBottomT_Low,
	 ArmorBottomT,
	 ArmorBottomT_High,

	 AssCurtain,
	 AssCurtainT,

	 AssFlashRiskLow,
	 AssFlashRisk,
	 AssFlashRiskHigh,
	 AssFlashRiskExtreme,
	 AssFlashRiskUltra,

	 Bra,
	 Bra_NoCover,
	 BraT_Low,
	 BraT,
	 BraT_High,

	 ChestCurtain,
	 ChestCurtainT,

	 ChestFlashRiskLow,
	 ChestFlashRisk,
	 ChestFlashRiskHigh,
	 ChestFlashRiskExtreme,
	 ChestFlashRiskUltra,

	 CoversAll,

	 CString,
	 CStringT_Low,
	 CStringT,
	 CStringT_High,

	 EffectivelyNaked,

	 Hotpants,
	 HotpantsT_Low,
	 HotpantsT,
	 HotpantsT_High,

	 Microskirt,

	 Miniskirt,
	 MiniskirtT,

	 NipplePasties,
	 NearlyNaked,

	 PelvicCurtain,
	 PelvicCurtainT,

	 PelvicFlashRiskLow,
	 PelvicFlashRisk,
	 PelvicFlashRiskHigh,
	 PelvicFlashRiskExtreme,
	 PelvicFlashRiskUltra,

	 ShowgirlSkirt,
	 ShowgirlSkirtT_Low,
	 ShowgirlSkirtT,
	 ShowgirlSkirtT_High,

	 Thong,
	 Thong_NoCover,
	 ThongT_Low,
	 ThongT,
	 ThongT_High,

	 Underwear,
	 Underwear_NoCover,
	 UnderwearT_Low,
	 UnderwearT,
	 UnderwearT_High,

	 VaginaPasties,

	 TotalFemaleKeywords
};

inline std::array<RE::BGSKeyword*, TotalFemaleKeywords> FemaleKeywords;

//Multi-Part Objects
/*
inline RE::BGSKeyword* TwoPart_ArmorTop;
inline RE::BGSKeyword* ArmorTop_Part1;
inline RE::BGSKeyword* ArmorTop_Part2;

inline RE::BGSKeyword* TwoPart_ArmorTopT_Low;
inline RE::BGSKeyword* ArmorTopT_Low_Part1;
inline RE::BGSKeyword* ArmorTopT_Low_Part2;

inline RE::BGSKeyword* TwoPart_ArmorTopT;
inline RE::BGSKeyword* ArmorTopT_Part1;
inline RE::BGSKeyword* ArmorTopT_Part2;

inline RE::BGSKeyword* TwoPart_ArmorTopT_High;
inline RE::BGSKeyword* ArmorTopT_High_Part1;
inline RE::BGSKeyword* ArmorTopT_High_Part2;

inline RE::BGSKeyword* TwoPart_ArmorBottom;
inline RE::BGSKeyword* ArmorBottom_Part1;
inline RE::BGSKeyword* ArmorBottom_Part2;

inline RE::BGSKeyword* TwoPart_ArmorBottomT_Low;
inline RE::BGSKeyword* ArmorBottomT_Low_Part1;
inline RE::BGSKeyword* ArmorBottomT_Low_Part2;

inline RE::BGSKeyword* TwoPart_ArmorBottomT;
inline RE::BGSKeyword* ArmorBottomT_Part1;
inline RE::BGSKeyword* ArmorBottomT_Part2;

inline RE::BGSKeyword* TwoPart_ArmorBottomT_High;
inline RE::BGSKeyword* ArmorBottomT_High_Part1;
inline RE::BGSKeyword* ArmorBottomT_High_Part2;

inline RE::BGSKeyword* TwoPart_Bra;
inline RE::BGSKeyword* Bra_Part1;
inline RE::BGSKeyword* Bra_Part2;

inline RE::BGSKeyword* TwoPart_BraT_Low;
inline RE::BGSKeyword* BraT_Low_Part1;
inline RE::BGSKeyword* BraT_Low_Part2;

inline RE::BGSKeyword* TwoPart_BraT;
inline RE::BGSKeyword* BraT_Part1;
inline RE::BGSKeyword* BraT_Part2;

inline RE::BGSKeyword* TwoPart_BraT_High;
inline RE::BGSKeyword* BraT_High_Part1;
inline RE::BGSKeyword* BraT_High_Part2;
*/

/*===========
MALE KEYWORDS
===========*/

/*
inline RE::BGSKeyword* ArmorTop_Male;
inline RE::BGSKeyword* ArmorTop_NoCover_Male;
inline RE::BGSKeyword* ArmorTopT_Low_Male;
inline RE::BGSKeyword* ArmorTopT_Male;
inline RE::BGSKeyword* ArmorTopT_High_Male;

inline RE::BGSKeyword* ArmorBottom_Male;
inline RE::BGSKeyword* ArmorBottom_NoCover_Male;
inline RE::BGSKeyword* ArmorBottomT_Low_Male;
inline RE::BGSKeyword* ArmorBottomT_Male;
inline RE::BGSKeyword* ArmorBottomT_High_Male;

inline RE::BGSKeyword* AssCurtain_Male;
inline RE::BGSKeyword* AssCurtainT_Male;

inline RE::BGSKeyword* AssFlashRiskLow_Male;
inline RE::BGSKeyword* AssFlashRisk_Male;
inline RE::BGSKeyword* AssFlashRiskHigh_Male;
inline RE::BGSKeyword* AssFlashRiskExtreme_Male;
inline RE::BGSKeyword* AssFlashRiskUltra_Male;

inline RE::BGSKeyword* Bra_Male;
inline RE::BGSKeyword* Bra_NoCover_Male;
inline RE::BGSKeyword* BraT_Low_Male;
inline RE::BGSKeyword* BraT_Male;
inline RE::BGSKeyword* BraT_High_Male;

inline RE::BGSKeyword* ChestCurtain_Male;
inline RE::BGSKeyword* ChestCurtainT_Male;

inline RE::BGSKeyword* ChestFlashRiskLow_Male;
inline RE::BGSKeyword* ChestFlashRisk_Male;
inline RE::BGSKeyword* ChestFlashRiskHigh_Male;
inline RE::BGSKeyword* ChestFlashRiskExtreme_Male;
inline RE::BGSKeyword* ChestFlashRiskUltra_Male;

inline RE::BGSKeyword* CoversAll_Male;

inline RE::BGSKeyword* BananaHammock;
inline RE::BGSKeyword* BananaHammockT_Low;
inline RE::BGSKeyword* BananaHammockT;
inline RE::BGSKeyword* BananaHammockT_High;

inline RE::BGSKeyword* EffectivelyNaked_Male;

inline RE::BGSKeyword* Hotpants_Male;
inline RE::BGSKeyword* HotpantsT_Low_Male;
inline RE::BGSKeyword* HotpantsT_Male;
inline RE::BGSKeyword* HotpantsT_High_Male;

inline RE::BGSKeyword* Microskirt_Male;

inline RE::BGSKeyword* Miniskirt_Male;
inline RE::BGSKeyword* MiniskirtT_Male;

inline RE::BGSKeyword* NipplePasties_Male;
inline RE::BGSKeyword* NearlyNaked_Male;

inline RE::BGSKeyword* PelvicCurtain_Male;
inline RE::BGSKeyword* PelvicCurtainT_Male;

inline RE::BGSKeyword* PelvicFlashRiskLow_Male;
inline RE::BGSKeyword* PelvicFlashRisk_Male;
inline RE::BGSKeyword* PelvicFlashRiskHigh_Male;
inline RE::BGSKeyword* PelvicFlashRiskExtreme_Male;
inline RE::BGSKeyword* PelvicFlashRiskUltra_Male;

inline RE::BGSKeyword* HimboSkirt;
inline RE::BGSKeyword* HimboSkirtT_Low;
inline RE::BGSKeyword* HimboSkirtT;
inline RE::BGSKeyword* HimboSkirtT_High;

inline RE::BGSKeyword* Thong_Male;
inline RE::BGSKeyword* Thong_NoCover_Male;
inline RE::BGSKeyword* ThongT_Low_Male;
inline RE::BGSKeyword* ThongT_Male;
inline RE::BGSKeyword* ThongT_High_Male;

inline RE::BGSKeyword* Underwear_Male;
inline RE::BGSKeyword* Underwear_NoCover_Male;
inline RE::BGSKeyword* UnderwearT_Low_Male;
inline RE::BGSKeyword* UnderwearT_Male;
inline RE::BGSKeyword* UnderwearT_High_Male;
*/

enum MaleKeyword {
	 ArmorTop_Male,
	 ArmorTop_NoCover_Male,
	 ArmorTopT_Low_Male,
	 ArmorTopT_Male,
	 ArmorTopT_High_Male,

	 ArmorBottom_Male,
	 ArmorBottom_NoCover_Male,
	 ArmorBottomT_Low_Male,
	 ArmorBottomT_Male,
	 ArmorBottomT_High_Male,

	 AssCurtain_Male,
	 AssCurtainT_Male,

	 AssFlashRiskLow_Male,
	 AssFlashRisk_Male,
	 AssFlashRiskHigh_Male,
	 AssFlashRiskExtreme_Male,
	 AssFlashRiskUltra_Male,

	 Bra_Male,
	 Bra_NoCover_Male,
	 BraT_Low_Male,
	 BraT_Male,
	 BraT_High_Male,

	 ChestCurtain_Male,
	 ChestCurtainT_Male,

	 ChestFlashRiskLow_Male,
	 ChestFlashRisk_Male,
	 ChestFlashRiskHigh_Male,
	 ChestFlashRiskExtreme_Male,
	 ChestFlashRiskUltra_Male,

	 CoversAll_Male,

	 BananaHammock,
	 BananaHammockT_Low,
	 BananaHammockT,
	 BananaHammockT_High,

	 EffectivelyNaked_Male,

	 Hotpants_Male,
	 HotpantsT_Low_Male,
	 HotpantsT_Male,
	 HotpantsT_High_Male,

	 Microskirt_Male,

	 Miniskirt_Male,
	 MiniskirtT_Male,

	 NipplePasties_Male,
	 NearlyNaked_Male,

	 PelvicCurtain_Male,
	 PelvicCurtainT_Male,

	 PelvicFlashRiskLow_Male,
	 PelvicFlashRisk_Male,
	 PelvicFlashRiskHigh_Male,
	 PelvicFlashRiskExtreme_Male,
	 PelvicFlashRiskUltra_Male,

	 HimboSkirt,
	 HimboSkirtT_Low,
	 HimboSkirtT,
	 HimboSkirtT_High,

	 Thong_Male,
	 Thong_NoCover_Male,
	 ThongT_Low_Male,
	 ThongT_Male,
	 ThongT_High_Male,

	 Underwear_Male,
	 Underwear_NoCover_Male,
	 UnderwearT_Low_Male,
	 UnderwearT_Male,
	 UnderwearT_High_Male,

	 TotalMaleKeywords
};

inline std::array<RE::BGSKeyword*, TotalMaleKeywords> MaleKeywords;

enum UniversalKeyword {
	Ignore,

	TotalUniversalKeywords
};

inline std::array<RE::BGSKeyword*, TotalUniversalKeywords> UniversalKeywords;

//Multi-Part Objects
/*
inline RE::BGSKeyword* TwoPart_ArmorTop_Male;
inline RE::BGSKeyword* ArmorTop_Part1_Male;
inline RE::BGSKeyword* ArmorTop_Part2_Male;

inline RE::BGSKeyword* TwoPart_ArmorTopT_Low_Male;
inline RE::BGSKeyword* ArmorTopT_Low_Part1_Male;
inline RE::BGSKeyword* ArmorTopT_Low_Part2_Male;

inline RE::BGSKeyword* TwoPart_ArmorTopT_Male;
inline RE::BGSKeyword* ArmorTopT_Part1_Male;
inline RE::BGSKeyword* ArmorTopT_Part2_Male;

inline RE::BGSKeyword* TwoPart_ArmorTopT_High_Male;
inline RE::BGSKeyword* ArmorTopT_High_Part1_Male;
inline RE::BGSKeyword* ArmorTopT_High_Part2_Male;

inline RE::BGSKeyword* TwoPart_ArmorBottom_Male;
inline RE::BGSKeyword* ArmorBottom_Part1_Male;
inline RE::BGSKeyword* ArmorBottom_Part2_Male;

inline RE::BGSKeyword* TwoPart_ArmorBottomT_Low_Male;
inline RE::BGSKeyword* ArmorBottomT_Low_Part1_Male;
inline RE::BGSKeyword* ArmorBottomT_Low_Part2_Male;

inline RE::BGSKeyword* TwoPart_ArmorBottomT_Male;
inline RE::BGSKeyword* ArmorBottomT_Part1_Male;
inline RE::BGSKeyword* ArmorBottomT_Part2_Male;

inline RE::BGSKeyword* TwoPart_ArmorBottomT_High_Male;
inline RE::BGSKeyword* ArmorBottomT_High_Part1_Male;
inline RE::BGSKeyword* ArmorBottomT_High_Part2_Male;

inline RE::BGSKeyword* TwoPart_Bra_Male;
inline RE::BGSKeyword* Bra_Part1_Male;
inline RE::BGSKeyword* Bra_Part2_Male;

inline RE::BGSKeyword* TwoPart_BraT_Low_Male;
inline RE::BGSKeyword* BraT_Low_Part1_Male;
inline RE::BGSKeyword* BraT_Low_Part2_Male;

inline RE::BGSKeyword* TwoPart_BraT_Male;
inline RE::BGSKeyword* BraT_Part1_Male;
inline RE::BGSKeyword* BraT_Part2_Male;

inline RE::BGSKeyword* TwoPart_BraT_High_Male;
inline RE::BGSKeyword* BraT_High_Part1_Male;
inline RE::BGSKeyword* BraT_High_Part2_Male;
*/

//Creature Type Keywords

inline RE::BGSKeyword* ActorType_Creature;

//Multi-Part Object Vectors
inline std::vector<std::string_view> TwoPart_Object_PartA;
inline std::vector<std::string_view> TwoPart_Object_PartB;
inline std::vector<UINT8> TwoPart_Object_Type;

inline std::vector<RE::TESBoundObject*> TwoPart_ObjectA;
inline std::vector<RE::TESBoundObject*> TwoPart_ObjectB;
inline std::vector<RE::BGSKeyword*> TwoPart_Object_Keyword;

//Globals
inline RE::TESGlobal* WINakedCommentChance;

//Player Rolls

inline INT8 ChestCurtainRoll;
inline INT8 PelvicCurtainRoll;
inline INT8 AssCurtainRoll;
inline INT8 CStringRoll;

inline INT8 TopTransparentRoll;
inline INT8 BottomTransparentRoll;
inline INT8 BraTransparentRoll;
inline INT8 UnderwearTransparentRoll;
inline INT8 HotpantsTransparentRoll;
inline INT8 ShowgirlTransparentRoll;

//NPC Rolls

inline INT8 NPCChestCurtainRoll;
inline INT8 NPCPelvicCurtainRoll;
inline INT8 NPCAssCurtainRoll;
inline INT8 NPCCStringRoll;

inline INT8 NPCTopTransparentRoll;
inline INT8 NPCBottomTransparentRoll;
inline INT8 NPCBraTransparentRoll;
inline INT8 NPCUnderwearTransparentRoll;
inline INT8 NPCHotpantsTransparentRoll;
inline INT8 NPCShowgirlTransparentRoll;

//Convering States
namespace PlayerCoverage {
	
	inline bool ChestCurtainCoverage;
	inline bool PelvicCurtainCover;
	inline bool AssCurtainCover;

	inline bool ChestCover;
	inline bool BraCover;

	inline bool AssCover;
	inline bool GenitalCover;
	inline bool UnderwearCover;

}

//Functions

bool PlayerRaceIsRecognized(RE::StaticFunctionTag*);

RE::TESRace* ExternalGetPlayerBaseRace(RE::StaticFunctionTag*);
bool ValidatePlayerBaseRace(RE::StaticFunctionTag*);
void ExternalSetPlayerBaseRace(RE::StaticFunctionTag*, RE::TESRace* NewRace);

void AddCustomTransform(RE::StaticFunctionTag*, RE::TESRace* NewTransform);

bool IsPlayerTransformed();

void InitializeCoreData();
RE::BGSKeywordForm* AsKeywordForm(RE::TESForm* tesForm);

UINT8 RegisterTwoPartObject(std::string_view ObjectA, std::string_view ObjectB, UINT8 ObjectType);
UINT8 UnregisterTwoPartObject(std::string_view ObjectA, std::string_view ObjectB);

std::vector<std::string> GetPlayerWornObjectNameList();
std::vector<std::string_view> GetPlayerWornObjectEditorIDList();
std::vector<RE::TESBoundObject*> GetPlayerWornObjectList();

bool IsWearingTwoPartObject(RE::Actor* akActor, UINT8 ObjectType);
//UINT8 TwoPartTransparentObjectRiskLevel(RE::Actor* akActor, UINT8 ObjectType, bool Female);

bool PlayerWornHasKeyword(RE::BSFixedString keywordString);
bool PlayerWornHasKeyword(RE::BGSKeyword* Keyword);

bool ActorWornHasKeyword(RE::Actor* akActor, RE::BSFixedString keywordString);
bool ActorWornHasKeyword(RE::Actor* akActor, RE::BGSKeyword* Keyword);

void SetActorFactionRank(RE::Actor* akActor, RE::TESFaction* akFaction, int8_t factionRank);
void SetPlayerFactionRank(RE::TESFaction* akFaction, int8_t factionRank);

UINT8 GetRandomizedModesty(RE::Actor* akActor, bool IsPlayer);
int ExternalGetRandomizedModesty(RE::StaticFunctionTag*, RE::Actor* akActor);

UINT8 Randomizer(INT8 MinRoll, INT8 MaxRoll);

int FindInVector(std::vector<int> SearchVector, int SearchTarget);
int FindInVector(std::vector<UINT8> SearchVector, UINT8 SearchTarget);

int FindInVector(std::vector<bool> SearchVector, bool SearchTarget);

int FindInVector(std::vector<RE::FormID> SearchVector, RE::FormID SearchTarget);

int FindInVector(std::vector<std::string> SearchVector, std::string SearchTarget);
int FindInVector(std::vector<std::string_view> SearchVector, std::string_view SearchTarget);

uint8_t HandleInteger(int iValue);

std::string BoolToString(bool True);
std::string FlashRiskToString(UINT8 RiskLevel);

void CheckMods();

INT8 NakedCommentChance(bool IsMCMRequest);
void SLSFRNakedCommentPrecheck();

void CleanTransformList();

//Static Functions (Papyrus calls)

void DiceRoll(RE::StaticFunctionTag*);
void MotionDiceRoll(RE::StaticFunctionTag*);

void OverrideCurtainRoll(RE::StaticFunctionTag*, UINT8 CurtainType, INT8 RollOverride);

bool PlayerIsWearingChestCurtain(RE::StaticFunctionTag*);
bool PlayerIsWearingPelvicCurtain(RE::StaticFunctionTag*);
bool PlayerIsWearingAssCurtain(RE::StaticFunctionTag*);

int ExternalNakedCommentChance(RE::StaticFunctionTag*, bool IsMCMRequest);