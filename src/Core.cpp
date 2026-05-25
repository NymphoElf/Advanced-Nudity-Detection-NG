#include <algorithm>

#include "Core.h"
#include "Logger.h"
#include "Config.h"
#include "PlayerArmorScan.h"
#include "NPCScanner.h"
#include "Player.h"

/*
int FindInVector(std::vector<std::array<char, 256>> SearchVector, std::string_view SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		std::string_view IndexValue(SearchVector[SearchIndex].data());
		if (IndexValue == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}
*/

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

int FindInVector(std::vector<uint8_t> SearchVector, uint8_t SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (SearchVector[SearchIndex] == SearchTarget) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

uint8_t HandleInteger(int iValue) {
	if (iValue < 0) {
		iValue = 0;
	}
	else if (iValue > 255) {
		iValue = 255;
	}

	return static_cast<uint8_t>(iValue);
}

std::string BoolToString(bool True) {
	if (True) {
		return "True";
	}
	return "False";
}

std::string FlashRiskToString(int RiskLevel) {
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

void CheckMods() {
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	const RE::TESFile* RosaRoundBottom = DataHandler->LookupModByName("RosaFollower.esp");
	const RE::TESFile* Sexlab = DataHandler->LookupModByName("SexLab.esm");
	//const RE::TESFile* SLSFR = DataHandler->LookupModByName("SLSF Reloaded.esp");
	const RE::TESFile* DFFMA = DataHandler->LookupModByName("Modesty_Keyword.esp");
	//const RE::TESFile* OSLAroused = DataHandler->LookupModByName("OSLAroused.esp");

	if (RosaRoundBottom) {
		InstalledMods::RosaRoundBottom = true;
		Rosa = RE::TESForm::LookupByEditorID<RE::Actor>("Rosa");
		Log("<C++ Core> [CheckMods] RosaFollower.esp FOUND", LogType::Core);
	}
	else {
		InstalledMods::RosaRoundBottom = false;
		Rosa = nullptr;
	}

	if (Sexlab) {
		InstalledMods::Sexlab = true;
		Log("<C++ Core> [CheckMods] SexLab.esm FOUND", LogType::Core);
	}
	else {
		InstalledMods::Sexlab = false;
	}

	if (DFFMA) {
		InstalledMods::DFFMA = true;
		Log("<C++ Core> [CheckMods] Modesty_Keyword.esp (aka DFFMA) FOUND", LogType::Core);
	}
	else {
		InstalledMods::DFFMA = false;
	}
}

void InitializeCoreData() {
	Log("<C++ Core> [InitializeCoreData] START");
	
	//Actors
	
	Player = RE::TESForm::LookupByID<RE::Actor>(0x14);

	//Actor Bases

	PlayerBase = RE::TESForm::LookupByID<RE::TESActorBase>(0x7);

	//Races

	VanillaRaces[0] = RE::TESForm::LookupByID<RE::TESRace>(0x13743); //Altmer
	VanillaRaces[1] = RE::TESForm::LookupByID<RE::TESRace>(0x88840); //Altmer Vampire

	VanillaRaces[2] = RE::TESForm::LookupByID<RE::TESRace>(0x13740); //Argonian
	VanillaRaces[3] = RE::TESForm::LookupByID<RE::TESRace>(0x8883A); //Argonian Vampire

	VanillaRaces[4] = RE::TESForm::LookupByID<RE::TESRace>(0x13741); //Breton
	VanillaRaces[5] = RE::TESForm::LookupByID<RE::TESRace>(0x8883C); //Breton Vampire

	VanillaRaces[6] = RE::TESForm::LookupByID<RE::TESRace>(0x13749); //Bosmer
	VanillaRaces[7] = RE::TESForm::LookupByID<RE::TESRace>(0x88884); //Bosmer Vampire

	VanillaRaces[8] = RE::TESForm::LookupByID<RE::TESRace>(0x13742); //Dunmer
	VanillaRaces[9] = RE::TESForm::LookupByID<RE::TESRace>(0x8883D); //Dunmer Vampire

	VanillaRaces[10] = RE::TESForm::LookupByID<RE::TESRace>(0x13744); //Imperial
	VanillaRaces[11] = RE::TESForm::LookupByID<RE::TESRace>(0x88844); //Imperial Vampire

	VanillaRaces[12] = RE::TESForm::LookupByID<RE::TESRace>(0x13745); //Khajiit
	VanillaRaces[13] = RE::TESForm::LookupByID<RE::TESRace>(0x88845); //Khajiit Vampire

	VanillaRaces[14] = RE::TESForm::LookupByID<RE::TESRace>(0x13746); //Nord
	VanillaRaces[15] = RE::TESForm::LookupByID<RE::TESRace>(0x88794); //Nord Vampire

	VanillaRaces[16] = RE::TESForm::LookupByID<RE::TESRace>(0x13747); //Orsimer
	VanillaRaces[17] = RE::TESForm::LookupByID<RE::TESRace>(0xA82B9); //Orsimer Vampire

	VanillaRaces[18] = RE::TESForm::LookupByID<RE::TESRace>(0x13748); //Redguard
	VanillaRaces[19] = RE::TESForm::LookupByID<RE::TESRace>(0x88846); //Redguard Vampire

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

	//FollowerFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("CurrentFollowerFaction");

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

	//Universal Keywords

	Ignore = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Ignore"); //Possibly Unneeded in C++?

	//Female Keywords

	ArmorTop = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop");
	ArmorTop_NoCover = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop_NoCover");
	ArmorTopT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_Low");
	ArmorTopT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT");
	ArmorTopT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_High");

	ArmorBottom = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom");
	ArmorBottom_NoCover = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom_NoCover");
	ArmorBottomT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_Low");
	ArmorBottomT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT");
	ArmorBottomT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_High");

	AssCurtain = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtain");
	AssCurtainT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtainT");

	AssFlashRiskLow = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskLow");
	AssFlashRisk = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRisk");
	AssFlashRiskHigh = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskHigh");
	AssFlashRiskExtreme = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskExtreme");
	AssFlashRiskUltra = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskUltra");

	Bra = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra");
	Bra_NoCover = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra_NoCover");
	BraT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_Low");
	BraT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT");
	BraT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_High");

	ChestCurtain = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtain");
	ChestCurtainT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtainT");

	ChestFlashRiskLow = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskLow");
	ChestFlashRisk = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRisk");
	ChestFlashRiskHigh = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskHigh");
	ChestFlashRiskExtreme = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskExtreme");
	ChestFlashRiskUltra = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskUltra");

	CoversAll = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CoversAll");

	CString = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CString");
	CStringT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CStringT_Low");
	CStringT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CStringT");
	CStringT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CStringT_High");

	EffectivelyNaked = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_EffectivelyNaked");

	Hotpants = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Hotpants");
	HotpantsT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_Low");
	HotpantsT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT");
	HotpantsT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_High");

	Microskirt = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Microskirt");

	Miniskirt = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Miniskirt");
	MiniskirtT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_MiniskirtT");

	NearlyNaked = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NearlyNaked");
	NipplePasties = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NipplePasties");

	PelvicCurtain = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtain");
	PelvicCurtainT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtainT");

	PelvicFlashRiskLow = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskLow");
	PelvicFlashRisk = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRisk");
	PelvicFlashRiskHigh = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskHigh");
	PelvicFlashRiskExtreme = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskExtreme");
	PelvicFlashRiskUltra = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskUltra");

	ShowgirlSkirt = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirt");
	ShowgirlSkirtT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirtT_Low");
	ShowgirlSkirtT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirtT");
	ShowgirlSkirtT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ShowgirlSkirtT_High");

	Thong = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong");
	Thong_NoCover = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong_NoCover");
	ThongT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_Low");
	ThongT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT");
	ThongT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_High");

	Underwear = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear");
	Underwear_NoCover = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear_NoCover");
	UnderwearT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_Low");
	UnderwearT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT");
	UnderwearT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_High");

	VaginaPasties = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_VaginaPasties");

	//Male Keywords

	ArmorTop_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop_Male");
	ArmorTop_NoCover_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTop_NoCover_Male");
	ArmorTopT_Low_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_Low_Male");
	ArmorTopT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_Male");
	ArmorTopT_High_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorTopT_High_Male");

	ArmorBottom_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom_Male");
	ArmorBottom_NoCover_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottom_NoCover_Male");
	ArmorBottomT_Low_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_Low_Male");
	ArmorBottomT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_Male");
	ArmorBottomT_High_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ArmorBottomT_High_Male");

	AssCurtain_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtain_Male");
	AssCurtainT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssCurtainT_Male");

	AssFlashRiskLow_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskLow_Male");
	AssFlashRisk_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRisk_Male");
	AssFlashRiskHigh_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskHigh_Male");
	AssFlashRiskExtreme_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskExtreme_Male");
	AssFlashRiskUltra_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_AssFlashRiskUltra_Male");

	Bra_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra_Male");
	Bra_NoCover_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Bra_NoCover_Male");
	BraT_Low_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_Low_Male");
	BraT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_Male");
	BraT_High_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BraT_High_Male");

	ChestCurtain_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtain_Male");
	ChestCurtainT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestCurtainT_Male");

	ChestFlashRiskLow_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskLow_Male");
	ChestFlashRisk_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRisk_Male");
	ChestFlashRiskHigh_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskHigh_Male");
	ChestFlashRiskExtreme_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskExtreme_Male");
	ChestFlashRiskUltra_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ChestFlashRiskUltra_Male");

	CoversAll_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_CoversAll_Male");

	BananaHammock = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammock");
	BananaHammockT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammockT_Low");
	BananaHammockT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammockT");
	BananaHammockT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_BananaHammockT_High");

	EffectivelyNaked_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_EffectivelyNaked_Male");

	Hotpants_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Hotpants_Male");
	HotpantsT_Low_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_Low_Male");
	HotpantsT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_Male");
	HotpantsT_High_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HotpantsT_High_Male");

	Microskirt_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Microskirt_Male");

	Miniskirt_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Miniskirt_Male");
	MiniskirtT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_MiniskirtT_Male");

	NipplePasties_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NipplePasties_Male");
	NearlyNaked_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NearlyNaked_Male");

	PelvicCurtain_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtain_Male");
	PelvicCurtainT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicCurtainT_Male");

	PelvicFlashRiskLow_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskLow_Male");
	PelvicFlashRisk_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRisk_Male");
	PelvicFlashRiskHigh_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskHigh_Male");
	PelvicFlashRiskExtreme_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskExtreme_Male");
	PelvicFlashRiskUltra_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_PelvicFlashRiskUltra_Male");

	HimboSkirt = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirt");
	HimboSkirtT_Low = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirtT_Low");
	HimboSkirtT = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirtT");
	HimboSkirtT_High = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_HimboSkirtT_High");

	Thong_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong_Male");
	Thong_NoCover_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Thong_NoCover_Male");
	ThongT_Low_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_Low_Male");
	ThongT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_Male");
	ThongT_High_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_ThongT_High_Male");

	Underwear_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear_Male");
	Underwear_NoCover_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_Underwear_NoCover_Male");
	UnderwearT_Low_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_Low_Male");
	UnderwearT_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_Male");
	UnderwearT_High_Male = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_UnderwearT_High_Male");

	//Spells
	
	//NPCScanSpell = RE::TESForm::LookupByEditorID<RE::SpellItem>("AND_NPCScan");

	//Globals

	Configuration::DynamicModestyMode = RE::TESForm::LookupByEditorID<RE::TESGlobal>("AND_DynamicModesty");

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
		return arrowForm->AsKeywordForm();
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

int Randomizer(int MinRoll, int MaxRoll) {
	std::random_device RandomEngine;
	std::mt19937_64 gen(RandomEngine());
	std::uniform_int_distribution<int> Result(MinRoll, MaxRoll);
	return Result(gen);
}

/*
int GetCurtainOdds(float BaseRisk, float RiskModifier) {
	//Base + ((100 - Base) * RiskModifier)
	float RawOdds = BaseRisk + ((100 - BaseRisk) * (RiskModifier / 100));
	int FinalOdds = std::round(RawOdds);
	return FinalOdds;
}
*/

int GetRandomizedModesty(RE::Actor* akActor, bool IsPlayer) {
	int ModestyRoll = Randomizer(1, 100);
	int Confidence = ConfidenceLevel::Average;

	int BaseModesty;
	int FinalModesty;

	RE::TESRace* akRace = akActor->GetRace();

	//CONFIDENCE

	if (!IsPlayer) {
		Confidence = static_cast<int>(akActor->GetActorBase()->GetActorValue(RE::ActorValue::kConfidence));
		Log("<C++ Core> [GetRandomizedModesty] Actor is NPC", LogType::Core);
	} 
	else if (Configuration::PlayerConfidenceLevel == ConfidenceLevel::Randomized) {
		Confidence = Randomizer(0, 4);
		Configuration::PlayerConfidenceLevel = Confidence;
		Log("<C++ Core> [GetRandomizedModesty] Actor is PLAYER", LogType::Core);
	}
	else {
		Confidence = Configuration::PlayerConfidenceLevel;
		Log("<C++ Core> [GetRandomizedModesty] Actor is PLAYER", LogType::Core);
	}

	Log("<C++ Core> [GetRandomizedModesty] Modesty Roll is: " + std::to_string(ModestyRoll), LogType::Core);

	//RACE

	if (akRace == VanillaRaces[VanillaRaceIndex::Altmer] || akRace == VanillaRaces[VanillaRaceIndex::AltmerVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Altmer", LogType::Core);
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
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Argonian", LogType::Core);
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
	else if (akRace == VanillaRaces[VanillaRaceIndex::Breton] || akRace == VanillaRaces[VanillaRaceIndex::BretonVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Breton", LogType::Core);
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
	else if (akRace == VanillaRaces[VanillaRaceIndex::Bosmer] || akRace == VanillaRaces[VanillaRaceIndex::BosmerVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Bosmer", LogType::Core);
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
	else if (akRace == VanillaRaces[VanillaRaceIndex::Dunmer] || akRace == VanillaRaces[VanillaRaceIndex::DunmerVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Dunmer", LogType::Core);
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
	else if (akRace == VanillaRaces[VanillaRaceIndex::Imperial] || akRace == VanillaRaces[VanillaRaceIndex::ImperialVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Imperial", LogType::Core);
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
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Khajiit", LogType::Core);
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
	else if (akRace == VanillaRaces[VanillaRaceIndex::Nord] || akRace == VanillaRaces[VanillaRaceIndex::NordVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Nord", LogType::Core);
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
	else if (akRace == VanillaRaces[VanillaRaceIndex::Orsimer] || akRace == VanillaRaces[VanillaRaceIndex::OrsimerVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is an Orsimer", LogType::Core);
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
	else if (akRace == VanillaRaces[VanillaRaceIndex::Redguard] || akRace == VanillaRaces[VanillaRaceIndex::RedguardVampire]) {
		Log("<C++ Core> [GetRandomizedModesty] Actor is a Redguard", LogType::Core);
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
		Log("<C++ Core> [GetRandomizedModesty] CRITICAL ERROR: Actor Race is NONE!", LogType::Core, LoggingLevel::critical);

		BaseModesty = StrictModestyLevel::Modest;
	}
	else {
		//Unrecognized Race - Maybe add system to add custom races?

		Log("<C++ Core> [GetRandomizedModesty] Actor is a Non-Vanilla Race", LogType::Core);

		BaseModesty = StrictModestyLevel::Modest;
	}

	Log("<C++ Core> [GetRandomizedModesty] Base Modesty is: " + std::to_string(BaseModesty), LogType::Core);
	Log("<C++ Core> [GetRandomizedModesty] Confidence is: " + std::to_string(Confidence), LogType::Core);

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

	Log("<C++ Core> [GetRandomizedModesty] Final Modesty is: " + std::to_string(FinalModesty), LogType::Core);

	return FinalModesty;
}

/*
void NPCMotionDiceRoll(RE::StaticFunctionTag*, RE::Actor* akActor, bool IsSprinting) {
	Log("<C++ Core> [MotionDiceRoll] START", info);

	bool WearingChestCurtain = (PlayerWornHasKeyword(ChestCurtain) || PlayerWornHasKeyword(ChestCurtainT));
	bool WearingPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain) || PlayerWornHasKeyword(PelvicCurtainT));
	bool WearingAssCurtain = (PlayerWornHasKeyword(AssCurtain) || PlayerWornHasKeyword(AssCurtainT));

	if (!WearingChestCurtain && !WearingPelvicCurtain && !WearingAssCurtain) {
		Log("<C++ Core> [MotionDiceRoll] Not wearing any curtains. Check Skipepd.", info);
		return;
	}

	int MaxRoll = 100;

	if (IsSprinting) {
		MaxRoll -= SprintingMod;
	}
	else {
		MaxRoll -= RunningMod;
	}

	if (WearingChestCurtain) {
		NPCChestCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (WearingPelvicCurtain) {
		NPCPelvicCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (WearingAssCurtain) {
		NPCAssCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (PlayerBase->IsFemale()) {
		FemaleAnalyze();
	}

	Log("<C++ Core> [MotionDiceRoll] END", info);
}
*/

void MotionDiceRoll(RE::StaticFunctionTag*, bool IsSprinting) {
	Log("<C++ Core> [MotionDiceRoll] START");

	if (!IsWearingChestCurtain && !IsWearingPelvicCurtain && !IsWearingAssCurtain) {
		Log("<C++ Core> [MotionDiceRoll] Not wearing any curtains. Check Skipepd.", LogType::Core);
		return;
	}

	int MaxRoll = 100;

	if (IsSprinting) {
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

void DiceRoll(RE::StaticFunctionTag*, bool IsSprinting, bool IsRunning) {
	Log("<C++ Core> [DiceRoll] START");

	int MaxRoll = 100;

	if (Configuration::MotionFlashEnabled == true) {
		if (IsSprinting == true) {
			MaxRoll -= Configuration::SprintingMod;
		}
		else if (IsRunning == true) {
			MaxRoll -= Configuration::RunningMod;
		}
	}

	std::random_device RandomEngine;
	std::mt19937_64 gen(RandomEngine());

	std::uniform_int_distribution<int> FixedDistribute(1, 100);
	std::uniform_int_distribution<int> DynamicDistribute(1, MaxRoll);

	//Player Rolls
	ChestCurtainRoll = DynamicDistribute(gen);
	PelvicCurtainRoll = DynamicDistribute(gen);
	AssCurtainRoll = DynamicDistribute(gen);

	CStringRoll = FixedDistribute(gen);
	TopTransparentRoll = FixedDistribute(gen);
	BottomTransparentRoll = FixedDistribute(gen);
	BraTransparentRoll = FixedDistribute(gen);
	UnderwearTransparentRoll = FixedDistribute(gen);
	HotpantsTransparentRoll = FixedDistribute(gen);
	ShowgirlTransparentRoll = FixedDistribute(gen);

	//NPC Rolls
	NPCChestCurtainRoll = FixedDistribute(gen);
	NPCPelvicCurtainRoll = FixedDistribute(gen);
	NPCAssCurtainRoll = FixedDistribute(gen);

	NPCCStringRoll = FixedDistribute(gen);
	NPCTopTransparentRoll = FixedDistribute(gen);
	NPCBottomTransparentRoll = FixedDistribute(gen);
	NPCBraTransparentRoll = FixedDistribute(gen);
	NPCUnderwearTransparentRoll = FixedDistribute(gen);
	NPCHotpantsTransparentRoll = FixedDistribute(gen);
	NPCShowgirlTransparentRoll = FixedDistribute(gen);

	Log("<C++ Main> [DiceRoll] ChestCurtainRoll " + std::to_string(ChestCurtainRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] PelvicCurtainRoll " + std::to_string(PelvicCurtainRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] AssCurtainRoll " + std::to_string(AssCurtainRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] CStringRoll " + std::to_string(CStringRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] TopTransparentRoll " + std::to_string(TopTransparentRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] BottomTransparentRoll " + std::to_string(BottomTransparentRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] BraTransparentRoll " + std::to_string(BraTransparentRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] UnderwearTransparentRoll " + std::to_string(UnderwearTransparentRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] HotpantsTransparentRoll " + std::to_string(HotpantsTransparentRoll), LogType::Core);
	Log("<C++ Main> [DiceRoll] ShowgirlTransparentRoll " + std::to_string(ShowgirlTransparentRoll), LogType::Core);

	Log("<C++ Core> [DiceRoll] END");

	if (PlayerBase->IsFemale()) {
		FemaleArmorScan::FemaleAnalyze();
	}
	else {
		MaleArmorScan::MaleAnalyze();
	}
}

int ExternalGetRandomizedModesty(RE::StaticFunctionTag*, RE::Actor* akActor) {
	return GetRandomizedModesty(akActor, akActor == Player);
}

void OverrideCurtainRoll(RE::StaticFunctionTag*, int CurtainType, int RollOverride) {
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