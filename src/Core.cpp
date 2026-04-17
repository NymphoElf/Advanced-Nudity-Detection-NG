#include <algorithm>

#include "Core.h"
#include "Logger.h"
#include "Config.h"
#include "PlayerArmorScan.h"
#include "NPCScanner.h"

void InitializeCoreData() {
	//Actors
	
	Player = RE::TESForm::LookupByID<RE::Actor>(0x00000014);

	//Actor Bases

	PlayerBase = RE::TESForm::LookupByID<RE::TESActorBase>(0x00000007);

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

	FollowerFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("CurrentFollowerFaction");

	ArousalFaction = RE::TESForm::LookupByEditorID<RE::TESFaction>("AND_ArousalFaction");

	AllFactions[Nude] = NudeFaction;
	AllFactions[Topless] = ToplessFaction;
	AllFactions[Bottomless] = BottomlessFaction;
	AllFactions[ShowingAss] = ShowingAssFaction;
	AllFactions[ShowingBra] = ShowingBraFaction;
	AllFactions[ShowingChest] = ShowingChestFaction;
	AllFactions[ShowingGenitals] = ShowingGenitalsFaction;
	AllFactions[ShowingUnderwear] = ShowingUnderwearFaction;

	AllFactions[Arousal] = ArousalFaction;

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

	NipplePasties = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NipplePasties");
	NearlyNaked = RE::TESForm::LookupByEditorID<RE::BGSKeyword>("AND_NearlyNaked");

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
		NPCTopCurtainRoll = Randomizer(1, MaxRoll);
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
		TopCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (WearingPelvicCurtain) {
		PelvicCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (WearingAssCurtain) {
		AssCurtainRoll = Randomizer(1, MaxRoll);
	}

	if (PlayerBase->IsFemale()) {
		FemaleAnalyze();
	}
	else {
		MaleAnalyze();
	}

	Log("<C++ Core> [MotionDiceRoll] END", info);
}

void DiceRoll(RE::StaticFunctionTag*, bool IsSprinting, bool IsRunning) {
	//logs::info("<C++ Core> [DiceRoll] START");
	Log("<C++ Core> [DiceRoll] START", info);

	int MaxRoll = 100;

	if (MotionFlashEnabled == true) {
		if (IsSprinting == true) {
			MaxRoll -= SprintingMod;
		}
		else if (IsRunning == true) {
			MaxRoll -= RunningMod;
		}
	}

	std::random_device RandomEngine;
	std::mt19937_64 gen(RandomEngine());

	std::uniform_int_distribution<int> FixedDistribute(1, 100);
	std::uniform_int_distribution<int> DynamicDistribute(1, MaxRoll);

	//Player Rolls
	TopCurtainRoll = DynamicDistribute(gen);
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
	NPCTopCurtainRoll = FixedDistribute(gen);
	NPCPelvicCurtainRoll = FixedDistribute(gen);
	NPCAssCurtainRoll = FixedDistribute(gen);

	NPCCStringRoll = FixedDistribute(gen);
	NPCTopTransparentRoll = FixedDistribute(gen);
	NPCBottomTransparentRoll = FixedDistribute(gen);
	NPCBraTransparentRoll = FixedDistribute(gen);
	NPCUnderwearTransparentRoll = FixedDistribute(gen);
	NPCHotpantsTransparentRoll = FixedDistribute(gen);
	NPCShowgirlTransparentRoll = FixedDistribute(gen);

	logs::critical("{} {}", "<C++ Main> [DiceRoll] TopCurtainRoll ", std::to_string(TopCurtainRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] PelvicCurtainRoll ", std::to_string(PelvicCurtainRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] AssCurtainRoll ", std::to_string(AssCurtainRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] CStringRoll ", std::to_string(CStringRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] TopTransparentRoll ", std::to_string(TopTransparentRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] BottomTransparentRoll ", std::to_string(BottomTransparentRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] BraTransparentRoll ", std::to_string(BraTransparentRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] UnderwearTransparentRoll ", std::to_string(UnderwearTransparentRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] HotpantsTransparentRoll ", std::to_string(HotpantsTransparentRoll));
	logs::critical("{} {}", "<C++ Main> [DiceRoll] ShowgirlTransparentRoll ", std::to_string(ShowgirlTransparentRoll));

	if (PlayerBase->IsFemale()) {
		FemaleAnalyze();
	}
	else {
		MaleAnalyze();
	}

	Log("<C++ Core> [DiceRoll] END", info);
}