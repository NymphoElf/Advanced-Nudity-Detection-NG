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

namespace UnderwearType {
	enum UnderwearTypes {
		Underwear,
		Thong,
		CString
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

enum FlashRiskKeywords {
	AssFlashRiskLow,
	AssFlashRisk,
	AssFlashRiskHigh,
	AssFlashRiskExtreme,
	AssFlashRiskUltra,

	ChestFlashRiskLow,
	ChestFlashRisk,
	ChestFlashRiskHigh,
	ChestFlashRiskExtreme,
	ChestFlashRiskUltra,

	PelvicFlashRiskLow,
	PelvicFlashRisk,
	PelvicFlashRiskHigh,
	PelvicFlashRiskExtreme,
	PelvicFlashRiskUltra,

	TotalFlashRiskKeywords
};

enum RegularKeywords {
	ArmorTop = TotalFlashRiskKeywords,
	ArmorTop_NoCover,
	ArmorTopT_Low,
	ArmorTopT,
	ArmorTopT_High,

	Bra,
	Bra_NoCover,
	BraT_Low,
	BraT,
	BraT_High,

	ChestCurtain,
	ChestCurtainT,

	NipplePasties,
	ArmorBottom,
	ArmorBottom_NoCover,
	ArmorBottomT_Low,
	ArmorBottomT,
	ArmorBottomT_High,

	Hotpants,
	HotpantsT_Low,
	HotpantsT,
	HotpantsT_High,

	ShowgirlSkirt,
	ShowgirlSkirtT_Low,
	ShowgirlSkirtT,
	ShowgirlSkirtT_High,

	HimboSkirt = ShowgirlSkirt,
	HimboSkirtT_Low = ShowgirlSkirtT_Low,
	HimboSkirtT = ShowgirlSkirtT,
	HimboSkirtT_High = ShowgirlSkirtT_High,

	AssCurtain,
	AssCurtainT,

	PelvicCurtain,
	PelvicCurtainT,

	Miniskirt,
	MiniskirtT,

	CString,
	CStringT_Low,
	CStringT,
	CStringT_High,

	BananaHammock = CString,
	BananaHammockT_Low = CStringT_Low,
	BananaHammockT = CStringT,
	BananaHammockT_High = CStringT_High,

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

	Microskirt,

	CoversAll,

	NearlyNaked,
	EffectivelyNaked,

	//NEEDS TO BE LAST IN ENUM - FEMALE ONLY KEYWORD
	VaginaPasties,

	TotalMaleKeywords = 65,
	TotalFemaleKeywords,
	TotalKeywords = TotalFemaleKeywords
};

inline std::array<RE::BGSKeyword*, TotalFemaleKeywords> FemaleKeywords;
inline std::array<RE::BGSKeyword*, TotalMaleKeywords> MaleKeywords;

//Creature Type Keywords

inline RE::BGSKeyword* ActorType_Creature;

//Multi-Part Objects

struct TwoPartObject {
	RE::TESBoundObject* ObjectA;
	RE::TESBoundObject* ObjectB;
	RE::BGSKeyword* Keyword;
};

inline std::vector<TwoPartObject> TwoPartObjects;

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
const RE::TESFile* GetModFileFromFormID(RE::FormID FormID);

bool PlayerRaceIsRecognized(RE::StaticFunctionTag*);

RE::TESRace* ExternalGetPlayerBaseRace(RE::StaticFunctionTag*);
bool ValidatePlayerBaseRace(RE::StaticFunctionTag*);
void ExternalSetPlayerBaseRace(RE::StaticFunctionTag*, RE::TESRace* NewRace);

void AddCustomTransform(RE::StaticFunctionTag*, RE::TESRace* NewTransform);

bool IsPlayerTransformed();

void InitializeCoreData();
RE::BGSKeywordForm* AsKeywordForm(RE::TESForm* tesForm);

bool IsFlashRiskKeyword(RE::BGSKeyword* Keyword);

UINT8 RegisterTwoPartObject(RE::TESBoundObject* ObjectA, RE::TESBoundObject* ObjectB, RE::BGSKeyword* ObjectType);
UINT8 UnregisterTwoPartObject(RE::TESBoundObject* ObjectA, RE::TESBoundObject* ObjectB);

std::vector<RE::TESBoundObject*> GetPlayerWornObjectList();

bool IsWearingTwoPartObject(RE::Actor* akActor, RE::BGSKeyword* TreatedAs);

bool PlayerWornHasKeyword(RE::BSFixedString keywordString);
bool PlayerWornHasKeyword(RE::BGSKeyword* Keyword);
bool PlayerIsWearing(RE::BGSKeyword* Keyword);

bool ActorWornHasKeyword(RE::Actor* akActor, RE::BSFixedString keywordString);
bool ActorWornHasKeyword(RE::Actor* akActor, RE::BGSKeyword* Keyword);
bool ActorIsWearing(RE::Actor* akActor, RE::BGSKeyword* Keyword);

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