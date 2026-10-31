#include <algorithm>

#include "Core.h"
#include "Logger.h"
#include "Config.h"
#include "PlayerArmorScan.h"
#include "NPCScanner.h"
#include "Player.h"
#include "NPCData.h"
#include "ArousedStats.h"
#include "ModIntegration.h"

int FindInVector(std::vector<std::string_view> SearchVector, std::string_view SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (SearchVector[SearchIndex] == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

int FindInVector(std::vector<int> SearchVector, int SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (SearchVector[SearchIndex] == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

int FindInVector(std::vector<RE::FormID> SearchVector, RE::FormID SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (SearchVector[SearchIndex] == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

int FindInVector(std::vector<std::string> SearchVector, std::string SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (SearchVector[SearchIndex] == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

int FindInVector(std::vector<UINT8> SearchVector, UINT8 SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (SearchVector[SearchIndex] == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

int FindInVector(std::vector<bool> SearchVector, bool SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (SearchVector[SearchIndex] == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

UINT8 HandleInteger(int iValue) {
	if (iValue < 0) {
		iValue = 0;
	}
	else if (iValue > 255) {
		iValue = 255;
	}

	return (UINT8)iValue;
}

std::string BoolToString(bool Condition) {
	return Condition ? "True" : "False";
}

std::string FlashRiskToString(UINT8 RiskLevel) {
	if (RiskLevel == FlashRiskLevel::Low) {
		return "Low";
	}
	else if (RiskLevel == FlashRiskLevel::Normal) {
		return "Normal";
	}
	else if (RiskLevel == FlashRiskLevel::High) {
		return "High";
	}
	else if (RiskLevel == FlashRiskLevel::Extreme) {
		return "Extreme";
	}
	else if (RiskLevel == FlashRiskLevel::Ultra) {
		return "Ultra";
	}
	return "None";
}

void InitializeCoreData() {
	Log("<C++ Core> [InitializeCoreData] START");
	
	//Actors
	
	Player = RE::TESForm::LookupByID<RE::Actor>(0x14);

	//Actor Bases

	PlayerBase = RE::TESForm::LookupByID<RE::TESActorBase>(0x7);

	//Calendar

	GameCalendar = RE::Calendar::GetSingleton();

	//Game Data Handler
	GameDataHandler = RE::TESDataHandler::GetSingleton();

	//Races

	VanillaRaces[Altmer] = RE::TESForm::LookupByID<RE::TESRace>(0x13743); //Altmer
	VanillaRaces[AltmerVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x88840); //Altmer Vampire

	VanillaRaces[Argonian] = RE::TESForm::LookupByID<RE::TESRace>(0x13740); //Argonian
	VanillaRaces[ArgonianVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x8883A); //Argonian Vampire

	VanillaRaces[Bosmer] = RE::TESForm::LookupByID<RE::TESRace>(0x13749); //Bosmer
	VanillaRaces[BosmerVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x88884); //Bosmer Vampire

	VanillaRaces[Breton] = RE::TESForm::LookupByID<RE::TESRace>(0x13741); //Breton
	VanillaRaces[BretonVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x8883C); //Breton Vampire

	VanillaRaces[Dunmer] = RE::TESForm::LookupByID<RE::TESRace>(0x13742); //Dunmer
	VanillaRaces[DunmerVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x8883D); //Dunmer Vampire

	VanillaRaces[Imperial] = RE::TESForm::LookupByID<RE::TESRace>(0x13744); //Imperial
	VanillaRaces[ImperialVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x88844); //Imperial Vampire

	VanillaRaces[Khajiit] = RE::TESForm::LookupByID<RE::TESRace>(0x13745); //Khajiit
	VanillaRaces[KhajiitVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x88845); //Khajiit Vampire

	VanillaRaces[Nord] = RE::TESForm::LookupByID<RE::TESRace>(0x13746); //Nord
	VanillaRaces[NordVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x88794); //Nord Vampire

	VanillaRaces[Orsimer] = RE::TESForm::LookupByID<RE::TESRace>(0x13747); //Orsimer
	VanillaRaces[OrsimerVampire] = RE::TESForm::LookupByID<RE::TESRace>(0xA82B9); //Orsimer Vampire

	VanillaRaces[Redguard] = RE::TESForm::LookupByID<RE::TESRace>(0x13748); //Redguard
	VanillaRaces[RedguardVampire] = RE::TESForm::LookupByID<RE::TESRace>(0x88846); //Redguard Vampire

	DefaultTransformations[0] = RE::TESForm::LookupByID<RE::TESRace>(0x0200283A); //Vampire Lord
	DefaultTransformations[1] = RE::TESForm::LookupByID<RE::TESRace>(0x000CDD84); //Werewolf

	//Factions
	
	NudeFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_NudeActorFaction");
	ToplessFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ToplessFaction");
	BottomlessFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_BottomlessFaction");
	ShowingChestFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ShowingChestFaction");
	ShowingGenitalsFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ShowingGenitalsFaction");
	ShowingAssFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ShowingAssFaction");
	ShowingBraFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ShowingBraFaction");
	ShowingUnderwearFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ShowingUnderwearFaction");

	ModestyFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ModestyFaction");
	TopModestyFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_TopModestyFaction");
	BottomModestyFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_BottomModestyFaction");

	ShyWithFemale = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ShyWithFemales");
	ShyWithMale = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ShyWithMales");

	ArousalFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ArousalFaction");

	FlashingChestCurtainFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingChestCurtain");
	FlashingPelvicCurtainFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingPelvicCurtain");
	FlashingAssCurtainFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingAssCurtain");
	FlashingTopArmorFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingTop");
	FlashingBottomArmorFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingBottom");
	FlashingBraFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingBra");
	FlashingUnderwearFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingUnderwear");
	FlashingCStringFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingCString");
	FlashingHotpantsFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingHotpants");
	FlashingShowgirlSkirtFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_FlashingSkirt");

	//Fill Faction Array for NPC Scanner

	AllFactions[Nude] = NudeFaction;
	AllFactions[Topless] = ToplessFaction;
	AllFactions[Bottomless] = BottomlessFaction;
	AllFactions[ShowingAss] = ShowingAssFaction;
	AllFactions[ShowingBra] = ShowingBraFaction;
	AllFactions[ShowingChest] = ShowingChestFaction;
	AllFactions[ShowingGenitals] = ShowingGenitalsFaction;
	AllFactions[ShowingUnderwear] = ShowingUnderwearFaction;

	AllFactions[Arousal] = ArousalFaction;

	AllFactions[StrictModesty] = ModestyFaction;
	AllFactions[TopModesty] = TopModestyFaction;
	AllFactions[BottomModesty] = BottomModestyFaction;

	/*=============
	Female Keywords
	=============*/

	FemaleKeywords[ArmorTop] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop");
	FemaleKeywords[ArmorTop_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop_NoCover");
	FemaleKeywords[ArmorTopT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_Low");
	FemaleKeywords[ArmorTopT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT");
	FemaleKeywords[ArmorTopT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_High");

	FemaleKeywords[ArmorBottom] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom");
	FemaleKeywords[ArmorBottom_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom_NoCover");
	FemaleKeywords[ArmorBottomT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_Low");
	FemaleKeywords[ArmorBottomT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT");
	FemaleKeywords[ArmorBottomT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_High");

	FemaleKeywords[AssCurtain] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtain");
	FemaleKeywords[AssCurtainT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtainT");

	FemaleKeywords[AssFlashRiskLow] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskLow");
	FemaleKeywords[AssFlashRisk] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRisk");
	FemaleKeywords[AssFlashRiskHigh] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskHigh");
	FemaleKeywords[AssFlashRiskExtreme] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskExtreme");
	FemaleKeywords[AssFlashRiskUltra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskUltra");

	FemaleKeywords[Bra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra");
	FemaleKeywords[Bra_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra_NoCover");
	FemaleKeywords[BraT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_Low");
	FemaleKeywords[BraT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT");
	FemaleKeywords[BraT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_High");

	FemaleKeywords[ChestCurtain] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtain");
	FemaleKeywords[ChestCurtainT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtainT");

	FemaleKeywords[ChestFlashRiskLow] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskLow");
	FemaleKeywords[ChestFlashRisk] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRisk");
	FemaleKeywords[ChestFlashRiskHigh] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskHigh");
	FemaleKeywords[ChestFlashRiskExtreme] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskExtreme");
	FemaleKeywords[ChestFlashRiskUltra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskUltra");

	FemaleKeywords[CoversAll] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CoversAll");

	FemaleKeywords[CString] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CString");
	FemaleKeywords[CStringT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CStringT_Low");
	FemaleKeywords[CStringT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CStringT");
	FemaleKeywords[CStringT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CStringT_High");

	FemaleKeywords[EffectivelyNaked] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_EffectivelyNaked");

	FemaleKeywords[Hotpants] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Hotpants");
	FemaleKeywords[HotpantsT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_Low");
	FemaleKeywords[HotpantsT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT");
	FemaleKeywords[HotpantsT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_High");

	FemaleKeywords[Microskirt] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Microskirt");

	FemaleKeywords[Miniskirt] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Miniskirt");
	FemaleKeywords[MiniskirtT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_MiniskirtT");

	FemaleKeywords[NearlyNaked] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NearlyNaked");
	FemaleKeywords[NipplePasties] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NipplePasties");

	FemaleKeywords[PelvicCurtain] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtain");
	FemaleKeywords[PelvicCurtainT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtainT");

	FemaleKeywords[PelvicFlashRiskLow] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskLow");
	FemaleKeywords[PelvicFlashRisk] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRisk");
	FemaleKeywords[PelvicFlashRiskHigh] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskHigh");
	FemaleKeywords[PelvicFlashRiskExtreme] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskExtreme");
	FemaleKeywords[PelvicFlashRiskUltra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskUltra");

	FemaleKeywords[ShowgirlSkirt] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirt");
	FemaleKeywords[ShowgirlSkirtT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirtT_Low");
	FemaleKeywords[ShowgirlSkirtT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirtT");
	FemaleKeywords[ShowgirlSkirtT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirtT_High");

	FemaleKeywords[Thong] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong");
	FemaleKeywords[Thong_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong_NoCover");
	FemaleKeywords[ThongT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_Low");
	FemaleKeywords[ThongT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT");
	FemaleKeywords[ThongT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_High");

	FemaleKeywords[Underwear] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear");
	FemaleKeywords[Underwear_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear_NoCover");
	FemaleKeywords[UnderwearT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_Low");
	FemaleKeywords[UnderwearT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT");
	FemaleKeywords[UnderwearT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_High");

	FemaleKeywords[VaginaPasties] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_VaginaPasties");

	/*===========
	Male Keywords
	===========*/

	MaleKeywords[ArmorTop] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop_Male");
	MaleKeywords[ArmorTop_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop_NoCover_Male");
	MaleKeywords[ArmorTopT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_Low_Male");
	MaleKeywords[ArmorTopT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_Male");
	MaleKeywords[ArmorTopT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_High_Male");

	MaleKeywords[ArmorBottom] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom_Male");
	MaleKeywords[ArmorBottom_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom_NoCover_Male");
	MaleKeywords[ArmorBottomT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_Low_Male");
	MaleKeywords[ArmorBottomT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_Male");
	MaleKeywords[ArmorBottomT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_High_Male");

	MaleKeywords[AssCurtain] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtain_Male");
	MaleKeywords[AssCurtainT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtainT_Male");

	MaleKeywords[AssFlashRiskLow] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskLow_Male");
	MaleKeywords[AssFlashRisk] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRisk_Male");
	MaleKeywords[AssFlashRiskHigh] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskHigh_Male");
	MaleKeywords[AssFlashRiskExtreme] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskExtreme_Male");
	MaleKeywords[AssFlashRiskUltra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskUltra_Male");

	MaleKeywords[Bra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra_Male");
	MaleKeywords[Bra_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra_NoCover_Male");
	MaleKeywords[BraT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_Low_Male");
	MaleKeywords[BraT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_Male");
	MaleKeywords[BraT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_High_Male");

	MaleKeywords[ChestCurtain] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtain_Male");
	MaleKeywords[ChestCurtainT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtainT_Male");

	MaleKeywords[ChestFlashRiskLow] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskLow_Male");
	MaleKeywords[ChestFlashRisk] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRisk_Male");
	MaleKeywords[ChestFlashRiskHigh] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskHigh_Male");
	MaleKeywords[ChestFlashRiskExtreme] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskExtreme_Male");
	MaleKeywords[ChestFlashRiskUltra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskUltra_Male");

	MaleKeywords[CoversAll] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CoversAll_Male");

	MaleKeywords[BananaHammock] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammock");
	MaleKeywords[BananaHammockT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammockT_Low");
	MaleKeywords[BananaHammockT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammockT");
	MaleKeywords[BananaHammockT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammockT_High");

	MaleKeywords[EffectivelyNaked] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_EffectivelyNaked_Male");

	MaleKeywords[Hotpants] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Hotpants_Male");
	MaleKeywords[HotpantsT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_Low_Male");
	MaleKeywords[HotpantsT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_Male");
	MaleKeywords[HotpantsT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_High_Male");

	MaleKeywords[Microskirt] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Microskirt_Male");

	MaleKeywords[Miniskirt] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Miniskirt_Male");
	MaleKeywords[MiniskirtT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_MiniskirtT_Male");

	MaleKeywords[NipplePasties] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NipplePasties_Male");
	MaleKeywords[NearlyNaked] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NearlyNaked_Male");

	MaleKeywords[PelvicCurtain] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtain_Male");
	MaleKeywords[PelvicCurtainT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtainT_Male");

	MaleKeywords[PelvicFlashRiskLow] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskLow_Male");
	MaleKeywords[PelvicFlashRisk] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRisk_Male");
	MaleKeywords[PelvicFlashRiskHigh] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskHigh_Male");
	MaleKeywords[PelvicFlashRiskExtreme] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskExtreme_Male");
	MaleKeywords[PelvicFlashRiskUltra] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskUltra_Male");

	MaleKeywords[HimboSkirt] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirt");
	MaleKeywords[HimboSkirtT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirtT_Low");
	MaleKeywords[HimboSkirtT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirtT");
	MaleKeywords[HimboSkirtT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirtT_High");

	MaleKeywords[Thong] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong_Male");
	MaleKeywords[Thong_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong_NoCover_Male");
	MaleKeywords[ThongT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_Low_Male");
	MaleKeywords[ThongT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_Male");
	MaleKeywords[ThongT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_High_Male");

	MaleKeywords[Underwear] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear_Male");
	MaleKeywords[Underwear_NoCover] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear_NoCover_Male");
	MaleKeywords[UnderwearT_Low] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_Low_Male");
	MaleKeywords[UnderwearT] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_Male");
	MaleKeywords[UnderwearT_High] = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_High_Male");

	//Other Keywords
	
	ActorType_Creature = RE::TESForm::LookupByID<RE::BGSKeyword>(0x00013795);

	//Globals

	Configuration::DynamicModestyMode = RE::TESForm::LookupByEditorID<RE::TESGlobal>("AND_DynamicModesty");
	WINakedCommentChance = RE::TESForm::LookupByID<RE::TESGlobal>(0x000A8656);

	//Flash Rolls (before first roll)

	ChestCurtainRoll = -1;
	PelvicCurtainRoll = -1;
	AssCurtainRoll = -1;
	CStringRoll = -1;

	TopTransparentRoll = -1;
	BottomTransparentRoll = -1;
	BraTransparentRoll = -1;
	UnderwearTransparentRoll = -1;
	HotpantsTransparentRoll = -1;
	ShowgirlTransparentRoll = -1;

	NPCChestCurtainRoll = -1;
	NPCPelvicCurtainRoll = -1;
	NPCAssCurtainRoll = -1;
	NPCCStringRoll = -1;

	NPCTopTransparentRoll = -1;
	NPCBottomTransparentRoll = -1;
	NPCBraTransparentRoll = -1;
	NPCUnderwearTransparentRoll = -1;
	NPCHotpantsTransparentRoll = -1;
	NPCShowgirlTransparentRoll = -1;

	PlayerFactionsInitialized = false;
	PermanentFemalesImported = false;

	Log("<C++ Core> [InitializeCoreData] COMPLETE");
}

void SetActorFactionRank(RE::Actor* akActor, RE::TESFaction* akFaction, int8_t factionRank) {
	akActor->RemoveFromFaction(akFaction);
	akActor->AddToFaction(akFaction, factionRank);
}

void SetPlayerFactionRank(RE::TESFaction* akFaction, int8_t factionRank) {
	Player->RemoveFromFaction(akFaction);
	Player->AddToFaction(akFaction, factionRank);
}

RE::BGSKeywordForm* AsKeywordForm(RE::TESForm* tesForm)
{
	if (const auto arrowForm = tesForm->As<RE::TESAmmo>()) {
		return arrowForm->As<RE::BGSKeywordForm>();
	}
	else {
		return tesForm->As<RE::BGSKeywordForm>();
	}
}

bool ActorWornHasKeyword(RE::Actor* akActor, RE::BSFixedString keywordString) {
	const auto actorInventory = akActor->GetInventory([](RE::TESBoundObject& BoundObject) {return BoundObject.IsArmor(); });
	for (const auto& [item, inventoryData] : actorInventory) {
		const auto& [count, entry] = inventoryData;
		if (count <= 0 || !entry->IsWorn())
			continue;
		const auto keywordItem = AsKeywordForm(item);
		if (!keywordItem) {
			continue;
		}

		if (keywordItem->HasKeywordString(keywordString)) {
			return true;
		}
	}
	return false;
}

bool ActorWornHasKeyword(RE::Actor* akActor, RE::BGSKeyword* Keyword) {
	const auto actorInventory = akActor->GetInventory([](RE::TESBoundObject& BoundObject) {return BoundObject.IsArmor(); });
	for (const auto& [item, inventoryData] : actorInventory) {
		const auto& [count, entry] = inventoryData;
		if (count <= 0 || !entry->IsWorn())
			continue;
		const auto keywordItem = AsKeywordForm(item);
		if (!keywordItem) {
			continue;
		}

		if (keywordItem->HasKeyword(Keyword)) {
			return true;
		}
	}
	return false;
}

bool PlayerWornHasKeyword(RE::BSFixedString keywordString) {
	const auto PlayerInventory = Player->GetInventory([](RE::TESBoundObject& BoundObject) {return BoundObject.IsArmor(); });
	for (const auto& [item, inventoryData] : PlayerInventory) {
		const auto& [count, entry] = inventoryData;
		if (count <= 0 || !entry->IsWorn())
			continue;
		const auto keywordItem = AsKeywordForm(item);
		if (!keywordItem) {
			continue;
		}

		if (keywordItem->HasKeywordString(keywordString)) {
			return true;
		}
	}
	return false;
}

bool PlayerWornHasKeyword(RE::BGSKeyword* Keyword) {
	const auto PlayerInventory = Player->GetInventory([](RE::TESBoundObject& BoundObject) {return BoundObject.IsArmor(); });
	for (const auto& [item, inventoryData] : PlayerInventory) {
		const auto& [count, entry] = inventoryData;
		if (count <= 0 || !entry->IsWorn())
			continue;
		const auto keywordItem = AsKeywordForm(item);
		if (!keywordItem) {
			continue;
		}

		if (keywordItem->HasKeyword(Keyword)) {
			return true;
		}
	}
	return false;
}

bool IsFlashRiskKeyword(RE::BGSKeyword* Keyword) {
	for (UINT8 Index = 0; Index < TotalFlashRiskKeywords; ++Index) {
		if (Keyword == FemaleKeywords[Index] || Keyword == MaleKeywords[Index]) {
			switch (Index) {
				case AssFlashRiskLow:
					return true;
				case AssFlashRisk:
					return true;
				case AssFlashRiskHigh:
					return true;
				case AssFlashRiskExtreme:
					return true;
				case AssFlashRiskUltra:
					return true;
				case ChestFlashRiskLow:
					return true;
				case ChestFlashRisk:
					return true;
				case ChestFlashRiskHigh:
					return true;
				case ChestFlashRiskExtreme:
					return true;
				case ChestFlashRiskUltra:
					return true;
				case PelvicFlashRiskLow:
					return true;
				case PelvicFlashRisk:
					return true;
				case PelvicFlashRiskHigh:
					return true;
				case PelvicFlashRiskExtreme:
					return true;
				case PelvicFlashRiskUltra:
					return true;
				default:
					return false;
			}
		}
	}

	return false;
}

TwoPartObject GetTwoPartObject(RE::TESBoundObject* ObjectA, RE::TESBoundObject* ObjectB) {
	for (UINT16 Index = 0; Index < TwoPartObjects.size(); ++Index) {
		if (ObjectA == TwoPartObjects[Index].ObjectA && ObjectB == TwoPartObjects[Index].ObjectB) {
			return TwoPartObjects[Index];
		}
		else if (ObjectA == TwoPartObjects[Index].ObjectB && ObjectB == TwoPartObjects[Index].ObjectA) {
			return TwoPartObjects[Index];
		}
	}

	TwoPartObject EmptyObject = {nullptr, nullptr, nullptr};

	return EmptyObject;
}

std::vector<UINT16> CollectTwoPartObjectIndices(bool ObjectListA, RE::TESBoundObject* akObject) {
	std::vector<UINT16> IndexVector = {};

	for (UINT16 Index = 0; Index < TwoPartObjects.size(); ++Index) {
		if (ObjectListA && TwoPartObjects[Index].ObjectA == akObject) {
			IndexVector.emplace_back(Index);
		}
		else if (!ObjectListA && TwoPartObjects[Index].ObjectB == akObject) {
			IndexVector.emplace_back(Index);
		}
	}

	return IndexVector;
}

UINT8 RegisterTwoPartObject(RE::TESBoundObject* ObjectA, RE::TESBoundObject* ObjectB, RE::BGSKeyword* TreatedAs) {
	enum ReturnCodes {
		Success,
		AlreadyExists,
		TooManyObjects,
		InvalidSelection
	};

	if (!ObjectA || !ObjectB || !TreatedAs) {
		return InvalidSelection;
	}

	TwoPartObject NewTwoPartObject = GetTwoPartObject(ObjectA, ObjectB);

	if (NewTwoPartObject.ObjectA) {
		return AlreadyExists;
	}
	
	if (TwoPartObjectA.size() >= 65000) {
		Log("<C++ Core> [RegisterTwoPartObject] Too many objects registered. 65000 Two-Part Objects reached. Further registration would risk 16-bit Integer overflow.", Logger::Core, Logger::warning);
		return TooManyObjects;
	}

	NewTwoPartObject.ObjectA = ObjectA;
	NewTwoPartObject.ObjectB = ObjectB;
	NewTwoPartObject.Keyword = TreatedAs;

	TwoPartObjects.emplace_back(NewTwoPartObject);

	//TwoPartObjectA.emplace_back(ObjectA);
	//TwoPartObjectB.emplace_back(ObjectB);
	//TwoPartObjectKeyword.emplace_back(TreatedAs);

	return Success;
}

UINT8 UnregisterTwoPartObject(RE::TESBoundObject* ObjectA, RE::TESBoundObject* ObjectB) {
	enum ReturnCodes {
		Success,
		DoesNotExist
	};

	TwoPartObject ObjectToRemove = GetTwoPartObject(ObjectA, ObjectB);

	if (!ObjectToRemove.ObjectA) {
		return DoesNotExist;
	}

	for (UINT16 Index = 0; Index < TwoPartObjects.size(); ++Index) {
		if (ObjectToRemove.ObjectA == TwoPartObjects[Index].ObjectA && ObjectToRemove.ObjectB == TwoPartObjects[Index].ObjectB) {
			TwoPartObjects.erase(TwoPartObjects.begin() + Index);
			return Success;
		}
		else if (ObjectToRemove.ObjectA == TwoPartObjects[Index].ObjectB && ObjectToRemove.ObjectB == TwoPartObjects[Index].ObjectA) {
			TwoPartObjects.erase(TwoPartObjects.begin() + Index);
			return Success;
		}
	}

	Log("<C++ Core> [UnregisterTwoPartObject] Two Part Object consisting of " + GetFormLogData(ObjectA) + " and " + GetFormLogData(ObjectB) + " does not exist.", Logger::Core, Logger::info);
	return DoesNotExist;
}

bool IsTwoPartObjectPiece(bool ObjectListA, RE::TESBoundObject* akObject, RE::BGSKeyword* TreatedAs) {
	for (UINT16 Index = 0; Index < TwoPartObjects.size(); ++Index) {
		if (ObjectListA && TwoPartObjects[Index].ObjectA == akObject && TwoPartObjects[Index].Keyword == TreatedAs) {
			return true;
		}
		else if (!ObjectListA && TwoPartObjects[Index].ObjectB == akObject && TwoPartObjects[Index].Keyword == TreatedAs) {
			return true;
		}
	}

	return false;
}

bool IsWearingTwoPartObject(RE::Actor* akActor, RE::BGSKeyword* TreatedAs) {
	if (!akActor) {
		Log("<C++ Core> [IsWearingTwoPartObject] ERROR - Actor is NULL!", Logger::Core, Logger::error);
		return false;
	}

	const auto ActorInventory = akActor->GetInventory([](RE::TESBoundObject& BoundObject) {return BoundObject.IsArmor(); });

	std::vector<UINT16> PartOneObjectIndices = {};
	std::vector<UINT16> PartTwoObjectIndices = {};

	for (const auto& [ItemA, InventoryDataA] : ActorInventory) {
		const auto& [CountA, EntryA] = InventoryDataA;
		if (CountA <= 0 || !EntryA->IsWorn())
			continue;

		if (IsTwoPartObjectPiece(true, ItemA, TreatedAs)) {
			PartOneObjectIndices = CollectTwoPartObjectIndices(true, ItemA);
		}

		if (PartOneObjectIndices.size()) {
			for (const auto& [ItemB, InventoryDataB] : ActorInventory) {
				const auto& [CountB, EntryB] = InventoryDataB;
				if (CountB <= 0 || !EntryB->IsWorn())
					continue;

				if (IsTwoPartObjectPiece(false, ItemB, TreatedAs)) {
					PartOneObjectIndices = CollectTwoPartObjectIndices(false, ItemB);
				}

				if (PartTwoObjectIndices.size()) {
					for (UINT16 Index = 0; Index < PartOneObjectIndices.size() && Index < PartTwoObjectIndices.size(); ++Index) {
						if (PartOneObjectIndices[Index] == PartTwoObjectIndices[Index] && TreatedAs == TwoPartObjectKeyword[PartOneObjectIndices[Index]]) {
							return true;
						}
					}

					PartTwoObjectIndices.clear();
				}
			}

			PartOneObjectIndices.clear();
		}
	}

	return false;
}

std::vector<RE::TESBoundObject*> GetPlayerWornObjectList() {
	const auto PlayerInventory = Player->GetInventory([](RE::TESBoundObject& BoundObject) {return BoundObject.IsArmor(); });

	std::vector<RE::TESBoundObject*> BoundObjectVector;

	for (const auto& [item, inventoryData] : PlayerInventory) {

		const auto& [count, entry] = inventoryData;
		if (count <= 0 || !entry->IsWorn())
			continue;
		const RE::BGSKeywordForm* keywordItem = AsKeywordForm(item);
		if (!keywordItem) {
			continue;
		}

		BoundObjectVector.emplace_back(item);
	}

	return BoundObjectVector;
}

bool PlayerIsWearing(RE::BGSKeyword* Keyword) {
	return PlayerWornHasKeyword(Keyword) || IsWearingTwoPartObject(Player, Keyword);
}

bool ActorIsWearing(RE::Actor* akActor, RE::BGSKeyword* Keyword) {
	return ActorWornHasKeyword(akActor, Keyword) || IsWearingTwoPartObject(akActor, Keyword);
}

UINT8 Randomizer(INT8 MinRoll, INT8 MaxRoll) {
	MinRoll = std::clamp(MinRoll, (INT8)0, (INT8)100);
	MaxRoll = std::clamp(MaxRoll, (INT8)0, (INT8)100);
	
	std::random_device RandomEngine;
	std::mt19937_64 gen(RandomEngine());
	std::uniform_int_distribution<int> Result(MinRoll, MaxRoll);
	
	return (UINT8)Result(gen);
}

UINT8 GetRandomizedModesty(RE::Actor* akActor, bool IsPlayer) {
	UINT8 ModestyRoll = Randomizer(1, 100);
	UINT8 Confidence = ConfidenceLevel::Average;

	UINT8 BaseModesty;
	UINT8 FinalModesty;

	RE::TESRace* akRace = akActor->GetRace();

	//CONFIDENCE

	if (!IsPlayer) {
		Confidence = static_cast<INT8>(akActor->GetActorBase()->GetActorValue(RE::ActorValue::kConfidence));
		Log("<C++ Core> [GetRandomizedModesty] Actor is NPC", Logger::LogType::Core);
	} 
	else if (Configuration::PlayerConfidenceLevel == ConfidenceLevel::Randomized) {
		Confidence = Randomizer(0, 4);
		Configuration::PlayerConfidenceLevel = Confidence;
		Log("<C++ Core> [GetRandomizedModesty] Actor is PLAYER", Logger::LogType::Core);
	}
	else {
		Confidence = Configuration::PlayerConfidenceLevel;
		Log("<C++ Core> [GetRandomizedModesty] Actor is PLAYER", Logger::LogType::Core);
	}

	Log("<C++ Core> [GetRandomizedModesty] Modesty Roll is: " + std::to_string(ModestyRoll), Logger::LogType::Core);

	//RACE

	if (
		akRace == VanillaRaces[VanillaRaceIndex::Altmer] || akRace == VanillaRaces[VanillaRaceIndex::AltmerVampire]
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Altmer] || akRace == UBE::UBERaces[UBE::AltmerVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Altmer", Logger::LogType::Core);
		if (ModestyRoll <= 35) {
			BaseModesty = StrictModestyLevel::Modest;
		}
		else if (ModestyRoll <= 80) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 95) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
	}
	else if (akRace == VanillaRaces[VanillaRaceIndex::Argonian] || akRace == VanillaRaces[VanillaRaceIndex::ArgonianVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Argonian", Logger::LogType::Core);
		if (ModestyRoll <= 10) {
			BaseModesty = StrictModestyLevel::Modest;
		}
		else if (ModestyRoll <= 40) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 80) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else if (ModestyRoll <= 95) {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
		else {
			BaseModesty = StrictModestyLevel::Tease;
		}
	}
	else if (
		akRace == VanillaRaces[VanillaRaceIndex::Breton] || akRace == VanillaRaces[VanillaRaceIndex::BretonVampire]
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Breton] || akRace == UBE::UBERaces[UBE::BretonVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Breton", Logger::LogType::Core);
		if (ModestyRoll <= 5) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 15) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else if (ModestyRoll <= 55) {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
		else if (ModestyRoll <= 85) {
			BaseModesty = StrictModestyLevel::Tease;
		}
		else {
			BaseModesty = StrictModestyLevel::Brazen;
		}
	}
	else if (
		akRace == VanillaRaces[VanillaRaceIndex::Bosmer] || akRace == VanillaRaces[VanillaRaceIndex::BosmerVampire]
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Bosmer] || akRace == UBE::UBERaces[UBE::BosmerVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Bosmer", Logger::LogType::Core);
		if (ModestyRoll <= 35) {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
		else if (ModestyRoll <= 80) {
			BaseModesty = StrictModestyLevel::Tease;
		}
		else {
			BaseModesty = StrictModestyLevel::Brazen;
		}
	}
	else if (
		akRace == VanillaRaces[VanillaRaceIndex::Dunmer] || akRace == VanillaRaces[VanillaRaceIndex::DunmerVampire]
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Dunmer] || akRace == UBE::UBERaces[UBE::DunmerVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Dunmer", Logger::LogType::Core);
		if (ModestyRoll <= 30) {
			BaseModesty = StrictModestyLevel::Modest;
		}
		else if (ModestyRoll <= 75) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 90) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
	}
	else if (
		akRace == VanillaRaces[VanillaRaceIndex::Imperial] || akRace == VanillaRaces[VanillaRaceIndex::ImperialVampire]
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Imperial] || akRace == UBE::UBERaces[UBE::ImperialVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Imperial", Logger::LogType::Core);
		if (ModestyRoll <= 25) {
			BaseModesty = StrictModestyLevel::Modest;
		}
		else if (ModestyRoll <= 65) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 90) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
	}
	else if (akRace == VanillaRaces[VanillaRaceIndex::Khajiit] || akRace == VanillaRaces[VanillaRaceIndex::KhajiitVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Khajiit", Logger::LogType::Core);
		if (ModestyRoll <= 5) {
			BaseModesty = StrictModestyLevel::Modest;
		}
		else if (ModestyRoll <= 20) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 60) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else if (ModestyRoll <= 90) {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
		else {
			BaseModesty = StrictModestyLevel::Tease;
		}
	}
	else if (
		akRace == VanillaRaces[VanillaRaceIndex::Nord] || akRace == VanillaRaces[VanillaRaceIndex::NordVampire]
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Nord] || akRace == UBE::UBERaces[UBE::NordVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Nord", Logger::LogType::Core);
		if (ModestyRoll <= 45) {
			BaseModesty = StrictModestyLevel::Modest;
		}
		else if (ModestyRoll <= 80) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 95) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
	}
	else if (
		akRace == VanillaRaces[VanillaRaceIndex::Orsimer] || akRace == VanillaRaces[VanillaRaceIndex::OrsimerVampire]
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Orsimer] || akRace == UBE::UBERaces[UBE::OrsimerVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Orsimer", Logger::LogType::Core);
		if (ModestyRoll <= 10) {
			BaseModesty = StrictModestyLevel::Modest;
		}
		else if (ModestyRoll <= 35) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 65) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else if (ModestyRoll <= 90) {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
		else {
			BaseModesty = StrictModestyLevel::Tease;
		}
	}
	else if (
		akRace == VanillaRaces[VanillaRaceIndex::Redguard] || akRace == VanillaRaces[VanillaRaceIndex::RedguardVampire] 
		|| (InstalledMods::UBE && (akRace == UBE::UBERaces[UBE::Redguard] || akRace == UBE::UBERaces[UBE::RedguardVampire]))
		) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Redguard", Logger::LogType::Core);
		if (ModestyRoll <= 5) {
			BaseModesty = StrictModestyLevel::Reasonable;
		}
		else if (ModestyRoll <= 15) {
			BaseModesty = StrictModestyLevel::Relaxed;
		}
		else if (ModestyRoll <= 65) {
			BaseModesty = StrictModestyLevel::Comfortable;
		}
		else if (ModestyRoll <= 90) {
			BaseModesty = StrictModestyLevel::Tease;
		}
		else {
			BaseModesty = StrictModestyLevel::Brazen;
		}
	}
	else if (akRace == nullptr) {
		Log("<C++ Core> [GetRandomizedModesty] CRITICAL ERROR: Actor Race is NONE!", Logger::LogType::Core, Logger::LoggingLevel::critical);

		BaseModesty = StrictModestyLevel::Modest;
	}
	else {
		//Unrecognized Race - Maybe add system to add custom races?

		Log("<C++ Core> [GetRandomizedModesty] Actor Race not recognized.", Logger::LogType::Core);

		BaseModesty = StrictModestyLevel::Modest;
	}

	Log("<C++ Core> [GetRandomizedModesty] Base Modesty is: " + std::to_string(BaseModesty), Logger::LogType::Core);
	Log("<C++ Core> [GetRandomizedModesty] Confidence is: " + std::to_string(Confidence), Logger::LogType::Core);

	//CALCULATE FINAL MODESTY

	if (Confidence <= ConfidenceLevel::Cowardly) {
		FinalModesty = BaseModesty - 2;
	}
	else if (Confidence == ConfidenceLevel::Cautious) {
		FinalModesty = BaseModesty - 1;
	}
	else if (Confidence == ConfidenceLevel::Brave) {
		FinalModesty = BaseModesty + 1;
	}
	else if (Confidence >= ConfidenceLevel::Foolhardy) {
		FinalModesty = BaseModesty + 2;
	}
	else {
		FinalModesty = BaseModesty;
	}

	if (FinalModesty < StrictModestyLevel::Modest) {
		FinalModesty = StrictModestyLevel::Modest;
	}
	else if (FinalModesty > StrictModestyLevel::Immodest) {
		FinalModesty = StrictModestyLevel::Immodest;
	}

	Log("<C++ Core> [GetRandomizedModesty] Final Modesty is: " + std::to_string(FinalModesty), Logger::LogType::Core);

	return FinalModesty;
}

void MotionDiceRoll(RE::StaticFunctionTag*) {
	Log("<C++ Core> [MotionDiceRoll] START");

	if (!IsWearingChestCurtain && !IsWearingPelvicCurtain && !IsWearingAssCurtain) {
		Log("<C++ Core> [MotionDiceRoll] Not wearing any curtains. Check Skipepd.", Logger::LogType::Core);
		return;
	}

	INT8 MaxRoll = 100;

	if (Player->IsSprinting()) {
		MaxRoll -= Configuration::SprintingMod;
	}
	else {
		MaxRoll -= Configuration::RunningMod;
	}

	if (IsWearingChestCurtain) {
		ChestCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (IsWearingPelvicCurtain) {
		PelvicCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (IsWearingAssCurtain) {
		AssCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (PlayerBase->IsFemale()) {
		FemaleArmorScan::FemaleAnalyze();
	}
	else {
		MaleArmorScan::MaleAnalyze();
	}

	Log("<C++ Core> [MotionDiceRoll] END");
}

void DiceRoll(RE::StaticFunctionTag*) {
	Log("<C++ Core> [DiceRoll] START");

	INT8 MaxRoll = 100;

	if (Configuration::MotionFlashEnabled == true) {
		if (Player->IsSprinting()) {
			MaxRoll -= Configuration::SprintingMod;
		}
		else if (Player->IsRunning()) {
			MaxRoll -= Configuration::RunningMod;
		}
	}

	//Player Rolls
	ChestCurtainRoll = Randomizer(1, MaxRoll);
	PelvicCurtainRoll = Randomizer(1, MaxRoll);
	AssCurtainRoll = Randomizer(1, MaxRoll);

	CStringRoll = Randomizer(1, 100);
	TopTransparentRoll = Randomizer(1, 100);
	BottomTransparentRoll = Randomizer(1, 100);
	BraTransparentRoll = Randomizer(1, 100);
	UnderwearTransparentRoll = Randomizer(1, 100);
	HotpantsTransparentRoll = Randomizer(1, 100);
	ShowgirlTransparentRoll = Randomizer(1, 100);

	Log("<C++ Core> [DiceRoll] ChestCurtainRoll " + std::to_string(ChestCurtainRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] PelvicCurtainRoll " + std::to_string(PelvicCurtainRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] AssCurtainRoll " + std::to_string(AssCurtainRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] CStringRoll " + std::to_string(CStringRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] TopTransparentRoll " + std::to_string(TopTransparentRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] BottomTransparentRoll " + std::to_string(BottomTransparentRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] BraTransparentRoll " + std::to_string(BraTransparentRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] UnderwearTransparentRoll " + std::to_string(UnderwearTransparentRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] HotpantsTransparentRoll " + std::to_string(HotpantsTransparentRoll), Logger::LogType::Core);
	Log("<C++ Core> [DiceRoll] ShowgirlTransparentRoll " + std::to_string(ShowgirlTransparentRoll), Logger::LogType::Core);

	Log("<C++ Core> [DiceRoll] END");

	float arousalValue = 0.0f;

	if (InstalledMods::OSLAroused)  {
		 arousalValue = OSLAroused::GetArousal(Player);
	}
	else if (InstalledMods::SLOAroused) {
		arousalValue = (float)ModAPI::SLOArousedNG::GetPlayerArousal();
	}

	Player->AddToFaction(ArousalFaction, arousalValue > 0.0f ? static_cast<std::int8_t>(arousalValue) : std::int8_t{ 0 });

	if (PlayerBase->IsFemale()) {
		FemaleArmorScan::FemaleAnalyze();
	}
	else {
		MaleArmorScan::MaleAnalyze();
	}

	ProcessActors(GetActorsInRadiusOfPlayer(2048));
}

int ExternalGetRandomizedModesty(RE::StaticFunctionTag*, RE::Actor* akActor) {
	return GetRandomizedModesty(akActor, akActor == Player);
}

void OverrideCurtainRoll(RE::StaticFunctionTag*, UINT8 CurtainType, INT8 RollOverride) {
	enum CurtainEnum {
		ChestCurtain,
		PelvicCurtain,
		AssCurtain
	};

	switch (CurtainType) {
	case ChestCurtain:
		ChestCurtainRoll = RollOverride;
		break;
	case PelvicCurtain:
		PelvicCurtainRoll = RollOverride;
		break;
	case AssCurtain:
		AssCurtainRoll = RollOverride;
		break;
	default:
		break;
	}
}

bool PlayerIsWearingChestCurtain(RE::StaticFunctionTag*) {
	return IsWearingChestCurtain;
}

bool PlayerIsWearingPelvicCurtain(RE::StaticFunctionTag*) {
	return IsWearingPelvicCurtain;
}

bool PlayerIsWearingAssCurtain(RE::StaticFunctionTag*) {
	return IsWearingAssCurtain;
}

INT8 NakedCommentChance(bool IsMCMRequest) {
	INT8 CommentChance = -1;
	bool UnderwearCounted = false;

	if (!Configuration::DisableNakedComments) {
		if (Player->GetFactionRank(NudeFaction, true) == 1) {
			CommentChance += Configuration::NudeCommentChance;
		}

		if (Player->GetFactionRank(ToplessFaction, true) == 1) {
			CommentChance += Configuration::ToplessCommentChance;
		}

		if (Player->GetFactionRank(BottomlessFaction, true) == 1) {
			CommentChance += Configuration::BottomlessCommentChance;
		}

		if (Player->GetFactionRank(ShowingChestFaction, true) == 1) {
			CommentChance += Configuration::ChestCommentChance;
		}
		else if (Player->GetFactionRank(ShowingBraFaction, true) == 1) {
			CommentChance += Configuration::BraCommentChance;
		}

		if (Player->GetFactionRank(ShowingGenitalsFaction, true) == 1) {
			CommentChance += Configuration::GenitalsCommentChance;
		}
		else if (Player->GetFactionRank(ShowingUnderwearFaction, true) == 1) {
			CommentChance += Configuration::UnderwearCommentChance;
			UnderwearCounted = true;
		}

		if (Player->GetFactionRank(ShowingAssFaction, true) == 1) {
			CommentChance += Configuration::AssCommentChance;
		}
		else if (Player->GetFactionRank(ShowingUnderwearFaction, true) == 1 && !UnderwearCounted) {
			CommentChance += Configuration::UnderwearCommentChance;
		}
	}

	if (IsMCMRequest) {
		CommentChance++; //Add 1 for MCM readability. WINakedCommentChance uses Roll (0 to 99) >= Odds, and we are returning the Odds of a naked comment by NPCs
		CommentChance = std::clamp(CommentChance, (INT8)0, (INT8)100);
	}
	else {
		CommentChance = std::clamp(CommentChance, (INT8)-1, (INT8)99);
	}

	return CommentChance;
}

int ExternalNakedCommentChance(RE::StaticFunctionTag*, bool IsMCMRequest) {
	return NakedCommentChance(IsMCMRequest);
}

RE::TESRace* GetPlayerBaseRace() {
	if (PlayerBaseRace != nullptr) {
		return PlayerBaseRace;
	}
	
	return Player->GetRace();
}

RE::TESRace* ExternalGetPlayerBaseRace(RE::StaticFunctionTag*) {
	return GetPlayerBaseRace();
}

bool ValidatePlayerBaseRace(RE::StaticFunctionTag*) {
	return PlayerBaseRace != nullptr;
}

void CleanTransformList() {
	if (CustomTransformations.size() > 256) {
		while (CustomTransformations.size() > 256) {
			CustomTransformations.erase(CustomTransformations.begin() + 256);
		}
	}
}

void AddCustomTransform(RE::StaticFunctionTag*, RE::TESRace* NewTransform) {
	if (CustomTransformations.size() < 256) {
		CustomTransformations.emplace_back(NewTransform);
	}
	else {
		for (UINT8 ReplaceIndex = 0; ReplaceIndex < 255; ++ReplaceIndex) {
			CustomTransformations[ReplaceIndex] = CustomTransformations[ReplaceIndex + 1];
		}
		CustomTransformations[255] = NewTransform;
	}
}

void SetPlayerBaseRace(RE::TESRace* NewRace) {
	PlayerBaseRace = NewRace;
}

void ExternalSetPlayerBaseRace(RE::StaticFunctionTag*, RE::TESRace* NewRace) {
	SetPlayerBaseRace(NewRace);
}

bool PlayerRaceIsRecognized(RE::StaticFunctionTag*) {
	if (IsPlayerTransformed()) {
		return true;
	}

	RE::TESRace* arPlayer = Player->GetRace();

	if (arPlayer == PlayerBaseRace) {
		return true;
	}

	for (UINT8 Index = 0; Index < 20; ++Index) {
		if (VanillaRaces[Index] == arPlayer) {
			return true;
		}
	}

	return false;
}

bool IsPlayerTransformed() {
	RE::TESRace* arPlayer = Player->GetRace();
	if (arPlayer == DefaultTransformations[0] || arPlayer == DefaultTransformations[1]) {
		return true;
	}

	for (UINT8 Index = 0; Index < CustomTransformations.size(); ++Index) {
		if (arPlayer == CustomTransformations[Index]) {
			return true;
		}
	}

	return false;
}

void SLSFRNakedCommentPrecheck() {
	if (InstalledMods::SLSFR && ModAPI::SLSFR::SuppressNakedComments()) {
		return;
	}
	
	WINakedCommentChance->value = (float)NakedCommentChance(false);
}