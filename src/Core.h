#pragma once

enum RiskLevel {
	RiskNone,
	RiskLow,
	RiskNormal,
	RiskHigh,
	RiskExtreme,
	RiskUltra
};

enum Type {
	ChestType,
	PelvicType,
	AssType,
	TopType,
	BottomType,
	BraType,
	UnderwearType,
	ThongType,
	HotpantsType,
	ShowgirlType,
	HimboType
};

//Actors

inline RE::Actor* Player;

//Actor Bases

inline RE::TESActorBase* PlayerBase;

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

inline RE::TESFaction* FollowerFaction;

inline RE::TESFaction* ArousalFaction;

//Universal Keywords

inline RE::BGSKeyword* Ignore;

//Female Keywords

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

//Male Keywords

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

//Player Rolls

inline int TopCurtainRoll;
inline int PelvicCurtainRoll;
inline int AssCurtainRoll;
inline int CStringRoll;

inline int TopTransparentRoll;
inline int BottomTransparentRoll;
inline int BraTransparentRoll;
inline int UnderwearTransparentRoll;
inline int HotpantsTransparentRoll;
inline int ShowgirlTransparentRoll;

//NPC Rolls

inline int NPCTopCurtainRoll;
inline int NPCPelvicCurtainRoll;
inline int NPCAssCurtainRoll;
inline int NPCCStringRoll;

inline int NPCTopTransparentRoll;
inline int NPCBottomTransparentRoll;
inline int NPCBraTransparentRoll;
inline int NPCUnderwearTransparentRoll;
inline int NPCHotpantsTransparentRoll;
inline int NPCShowgirlTransparentRoll;

//Convering States
namespace PlayerCoverage {
	
	inline bool TopCurtainCover;
	inline bool PelvicCurtainCover;
	inline bool AssCurtainCover;

	inline bool ChestCover;
	inline bool BraCover;

	inline bool AssCover;
	inline bool GenitalCover;
	inline bool UnderwearCover;

}

//Functions

void InitializeCoreData();
RE::BGSKeywordForm* AsKeywordForm(RE::TESForm* tesForm);
bool PlayerWornHasKeyword(RE::BSFixedString keywordString);
bool PlayerWornHasKeyword(RE::BGSKeyword* Keyword);

bool ActorWornHasKeyword(RE::Actor* akActor, RE::BSFixedString keywordString);
bool ActorWornHasKeyword(RE::Actor* akActor, RE::BGSKeyword* Keyword);

void SetActorFactionRank(RE::Actor* akActor, RE::TESFaction* akFaction, int8_t factionRank);
void SetPlayerFactionRank(RE::TESFaction* akFaction, int8_t factionRank);

//Static Functions (Papyrus calls)

void DiceRoll(RE::StaticFunctionTag*, bool IsSprinting, bool IsRunning);
void MotionDiceRoll(RE::StaticFunctionTag*, bool IsSprinting);