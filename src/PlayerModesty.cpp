#include "PlayerModesty.h"
#include "Core.h"
#include "Config.h"
#include "Logger.h"

void TopRankJump(int factionRank) {
	SetPlayerFactionRank(TopModestyFaction, HandleInteger(factionRank));

	int index = 0;
	while (index < std::size(TopModestyTimer)) {
		TopModestyTimer[index] = 0;
		index++;
	}
}

void BottomRankJump(int factionRank) {
	SetPlayerFactionRank(BottomModestyFaction, HandleInteger(factionRank));

	int index = 0;
	while (index < std::size(BottomModestyTimer)) {
		BottomModestyTimer[index] = 0;
		index++;
	}
}

void RankJump(int factionRank) {
	SetPlayerFactionRank(ModestyFaction, HandleInteger(factionRank));

	int index = 0;
	while (index < std::size(StrictModestyTimer)) {
		StrictModestyTimer[index] = 0;
		index++;
	}
}

void TopModestyDowngrade(int Rank, int HoursPassed) {
	int DowngradeTime = Configuration::ImmodestyTimeNeeded * -24;

	if (Configuration::MinimumTopModestyRank < Rank) {
		TopModestyTimer[Rank] -= HoursPassed;
		if (Configuration::AllowPlayerCorruption && TopModestyTimer[Rank] < DowngradeTime) {
			TopModestyTimer[Rank] = DowngradeTime;
		}
		else if (TopModestyTimer[Rank] <= DowngradeTime) {
			TopRankJump((Rank - 1));
		}
	}
	else if (Configuration::MinimumTopModestyRank == Rank) {
		TopModestyTimer[Rank] -= HoursPassed;
		if (TopModestyTimer[Rank] < 0) {
			TopModestyTimer[Rank] = 0;
		}
	}
}

void BottomModestyDowngrade(int Rank, int HoursPassed) {
	int DowngradeTime = Configuration::ImmodestyTimeNeeded * -24;

	if (Configuration::MinimumBottomModestyRank < Rank) {
		BottomModestyTimer[Rank] -= HoursPassed;
		if (Configuration::AllowPlayerCorruption && BottomModestyTimer[Rank] < DowngradeTime) {
			BottomModestyTimer[Rank] = DowngradeTime;
		}
		else if (BottomModestyTimer[Rank] <= DowngradeTime) {
			BottomRankJump((Rank - 1));
		}
	}
	else if (Configuration::MinimumBottomModestyRank == Rank) {
		BottomModestyTimer[Rank] -= HoursPassed;
		if (BottomModestyTimer[Rank] < 0) {
			BottomModestyTimer[Rank] = 0;
		}
	}
}

void StrictModestyDowngrade(int Rank, int HoursPassed) {
	int DowngradeTime = Configuration::ImmodestyTimeNeeded * -24;

	if (Configuration::MinimumStrictModestyRank < Rank) {
		StrictModestyTimer[Rank] -= HoursPassed;
		if (Configuration::AllowPlayerCorruption && StrictModestyTimer[Rank] < DowngradeTime) {
			StrictModestyTimer[Rank] = DowngradeTime;
		}
		else if (StrictModestyTimer[Rank] <= DowngradeTime) {
			RankJump((Rank - 1));
		}
	}
	else if (Configuration::MinimumStrictModestyRank == Rank) {
		StrictModestyTimer[Rank] -= HoursPassed;
		if (StrictModestyTimer[Rank] < 0) {
			StrictModestyTimer[Rank] = 0;
		}
	}
}

void StrictModesty(float CurrentGameTime) {
	if (InstalledMods::DFFMA == false) {
		Log("<C++ PlayerModesty> [StrictModesty] DFFMA is not detected!", LogType::PlayerModesty, LoggingLevel::warning);
		return;
	}
	else if (Configuration::DynamicModestyEnabled == false) {
		Log("<C++ PlayerModesty> [StrictModesty] Dynamic Modesty is Disabled!", LogType::PlayerModesty);
		return;
	}
	
	int HoursPassed = static_cast<int>((CurrentGameTime - LastTimeChecked) / 0.041666);
	Log("<C++ PlayerModesty> [StrictModesty] Hours Passed: " + std::to_string(HoursPassed), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [StrictModesty] RAW Hours Passed: " + std::to_string(((CurrentGameTime - LastTimeChecked) / 0.041666)), LogType::PlayerModesty);

	int CurrentRank = Player->GetFactionRank(ModestyFaction, true);

	if (Configuration::MinimumStrictModestyRank > CurrentRank) {
		RankJump(Configuration::MinimumStrictModestyRank);
	}

	if (HoursPassed < 1) {
		return;
	}

	int UpgradeTime = Configuration::ImmodestyTimeNeeded * 24;

	bool IsShowingBra = Player->GetFactionRank(ShowingBraFaction, true) == 1;
	bool IsShowingChest = Player->GetFactionRank(ShowingChestFaction, true) == 1;
	bool IsTopless = Player->GetFactionRank(ToplessFaction, true) == 1;

	bool IsShowingUnderwear = Player->GetFactionRank(ShowingUnderwearFaction, true) == 1;
	bool IsShowingGenitals = Player->GetFactionRank(ShowingGenitalsFaction, true) == 1;
	bool IsBottomless = Player->GetFactionRank(BottomlessFaction, true) == 1;

	bool IsNude = Player->GetFactionRank(NudeFaction, true) == 1;

	LastTimeChecked = CurrentGameTime;
	
	//Modest
	if (CurrentRank == StrictModestyLevel::Modest) {
		if (IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			StrictModestyTimer[CurrentRank] += HoursPassed;
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			StrictModestyDowngrade(CurrentRank, HoursPassed);
		}
	}
	//Reasonable
	else if (CurrentRank == StrictModestyLevel::Reasonable) {
		if (IsShowingUnderwear && IsShowingBra && !IsShowingGenitals && !IsShowingChest) {
			StrictModestyTimer[CurrentRank] += HoursPassed;
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			StrictModestyDowngrade(CurrentRank, HoursPassed);
		}
	}
	//Relaxed
	else if (CurrentRank == StrictModestyLevel::Relaxed) {
		if (IsShowingChest && IsShowingUnderwear && !IsTopless && !IsShowingGenitals) {
			StrictModestyTimer[CurrentRank] += HoursPassed;
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingBra && !IsShowingChest) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			StrictModestyDowngrade(CurrentRank, HoursPassed);
		}
	}
	//Comfortable
	else if (CurrentRank == StrictModestyLevel::Comfortable) {
		if (IsShowingGenitals && IsShowingChest && !IsTopless && !IsBottomless) {
			StrictModestyTimer[CurrentRank] += HoursPassed;
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingChest && !IsTopless) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			StrictModestyDowngrade(CurrentRank, HoursPassed);
		}
	}
	//Tease
	else if (CurrentRank == StrictModestyLevel::Tease) {
		if (IsTopless && IsShowingGenitals && !IsBottomless) {
			StrictModestyTimer[CurrentRank] += HoursPassed;
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingChest || !IsShowingGenitals) {
			StrictModestyDowngrade(CurrentRank, HoursPassed);
		}
	}
	//Brazen
	else if (CurrentRank == StrictModestyLevel::Brazen) {
		if (IsTopless && IsBottomless) {
			StrictModestyTimer[CurrentRank] += HoursPassed;
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingGenitals || !IsTopless) {
			StrictModestyDowngrade(CurrentRank, HoursPassed);
		}
	}
	//Immodest (previously 'Shameless')
	else if (CurrentRank == StrictModestyLevel::Immodest) {
		if (IsNude) {
			StrictModestyTimer[CurrentRank] += HoursPassed;
			if (Configuration::AllowPlayerShameless && StrictModestyTimer[CurrentRank] >= UpgradeTime * 2) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime * 2;
				}
			}
			else if (StrictModestyTimer[CurrentRank] > UpgradeTime) {
				StrictModestyTimer[CurrentRank] = UpgradeTime;
			}
		}
		else if (!IsTopless || !IsBottomless) {
			StrictModestyDowngrade(CurrentRank, HoursPassed);
		}
	}
	//Shameless (previously 'Permanently Shameless')
	else if (CurrentRank > StrictModestyLevel::Immodest && !Configuration::AllowPlayerShameless) {
		RankJump(StrictModestyLevel::Immodest);
	}
}

void TopModesty(int CurrentTopRank, int HoursPassed, int UpgradeTime) {
	bool IsShowingBra = Player->GetFactionRank(ShowingBraFaction, true) == 1;
	bool IsShowingChest = Player->GetFactionRank(ShowingChestFaction, true) == 1;
	bool IsTopless = Player->GetFactionRank(ToplessFaction, true) == 1;

	//Modest (Previously 'Shy')
	if (CurrentTopRank == SimpleModestyLevel::Modest && IsShowingBra && !IsShowingChest) {
		TopModestyTimer[SimpleModestyLevel::Modest] += HoursPassed;
	}
	//Comfortable
	else if (CurrentTopRank <= SimpleModestyLevel::Comfortable && IsShowingChest && !IsTopless) {
		TopModestyTimer[SimpleModestyLevel::Comfortable] += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable && IsShowingBra && !IsShowingChest) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentTopRank <= SimpleModestyLevel::Brazen && IsTopless) {
		TopModestyTimer[SimpleModestyLevel::Brazen] += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen && IsShowingChest && !IsTopless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentTopRank == SimpleModestyLevel::Immodest && IsTopless) {
		TopModestyTimer[SimpleModestyLevel::Immodest] += HoursPassed;
	}
	else if (CurrentTopRank > SimpleModestyLevel::Immodest) {
		if (!Configuration::AllowPlayerShameless) {
			TopRankJump(SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {
		TopModestyDowngrade(CurrentTopRank, HoursPassed);
		return;
	}

	if (CurrentTopRank == SimpleModestyLevel::Modest) {
		if ((TopModestyTimer[SimpleModestyLevel::Modest] + (TopModestyTimer[SimpleModestyLevel::Comfortable] / 2) + (TopModestyTimer[SimpleModestyLevel::Brazen] / 4)) >= UpgradeTime) {
			TopRankJump(SimpleModestyLevel::Comfortable);
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable) {
		if ((TopModestyTimer[SimpleModestyLevel::Comfortable] + (TopModestyTimer[SimpleModestyLevel::Brazen] / 2)) >= UpgradeTime) {
			TopRankJump(SimpleModestyLevel::Brazen);
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen) {
		if (TopModestyTimer[SimpleModestyLevel::Brazen] >= UpgradeTime) {
			TopRankJump(SimpleModestyLevel::Immodest);
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Immodest) {
		if (Configuration::AllowPlayerShameless && TopModestyTimer[SimpleModestyLevel::Immodest] >= UpgradeTime * 2) {
			TopRankJump(SimpleModestyLevel::Shameless);
		}
		else if (TopModestyTimer[SimpleModestyLevel::Immodest] > UpgradeTime) {
			TopModestyTimer[SimpleModestyLevel::Immodest] = UpgradeTime;
		}
	}
}

void BottomModesty(int CurrentBottomRank, int HoursPassed, int UpgradeTime) {
	bool IsShowingUnderwear = Player->GetFactionRank(ShowingUnderwearFaction, true) == 1;
	bool IsShowingGenitals = Player->GetFactionRank(ShowingGenitalsFaction, true) == 1;
	bool IsBottomless = Player->GetFactionRank(BottomlessFaction, true) == 1;
	
	//Modest (Previously 'Shy')
	if (CurrentBottomRank == SimpleModestyLevel::Modest && IsShowingUnderwear && !IsShowingGenitals) {
		BottomModestyTimer[SimpleModestyLevel::Modest] += HoursPassed;
	}
	//Comfortable
	else if (CurrentBottomRank <= SimpleModestyLevel::Comfortable && IsShowingGenitals && !IsBottomless) {
		BottomModestyTimer[SimpleModestyLevel::Comfortable] += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable && IsShowingUnderwear && !IsShowingGenitals) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentBottomRank <= SimpleModestyLevel::Brazen && IsBottomless) {
		BottomModestyTimer[SimpleModestyLevel::Brazen] += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen && IsShowingGenitals && !IsBottomless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest && IsBottomless) {
		BottomModestyTimer[SimpleModestyLevel::Immodest] += HoursPassed;
	}
	else if (CurrentBottomRank > SimpleModestyLevel::Immodest) {
		if (!Configuration::AllowPlayerShameless) {
			BottomRankJump(SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {
		BottomModestyDowngrade(CurrentBottomRank, HoursPassed);
		return;
	}

	if (CurrentBottomRank == SimpleModestyLevel::Modest) {
		if ((BottomModestyTimer[SimpleModestyLevel::Modest] + (BottomModestyTimer[SimpleModestyLevel::Comfortable] / 2) + (BottomModestyTimer[SimpleModestyLevel::Brazen] / 4)) >= UpgradeTime) {
			BottomRankJump(SimpleModestyLevel::Comfortable);
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable) {
		if ((BottomModestyTimer[SimpleModestyLevel::Comfortable] + (BottomModestyTimer[SimpleModestyLevel::Brazen] / 2)) >= UpgradeTime) {
			BottomRankJump(SimpleModestyLevel::Brazen);
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen) {
		if (BottomModestyTimer[SimpleModestyLevel::Brazen] >= UpgradeTime) {
			BottomRankJump(SimpleModestyLevel::Immodest);
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest) {
		if (Configuration::AllowPlayerShameless && BottomModestyTimer[SimpleModestyLevel::Immodest] >= UpgradeTime * 2) {
			BottomRankJump(SimpleModestyLevel::Shameless);
		}
		else if (BottomModestyTimer[SimpleModestyLevel::Immodest] > UpgradeTime) {
			BottomModestyTimer[SimpleModestyLevel::Immodest] = UpgradeTime;
		}
	}
}

void SimpleModesty(float CurrentGameTime) {
	int HoursPassed = static_cast<int>((CurrentGameTime - LastTimeChecked) / 0.041666);
	Log("<C++ PlayerModesty> [SimpleModesty] Hours Passed: " + std::to_string(HoursPassed), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [SimpleModesty] RAW Hours Passed: " + std::to_string(((CurrentGameTime - LastTimeChecked) / 0.041666)), LogType::PlayerModesty);

	int CurrentTopRank = Player->GetFactionRank(TopModestyFaction, true);
	int CurrentBottomRank = Player->GetFactionRank(BottomModestyFaction, true);

	if (Configuration::MinimumTopModestyRank > CurrentTopRank) {
		TopRankJump(Configuration::MinimumTopModestyRank);
	}

	if (Configuration::MinimumBottomModestyRank > CurrentBottomRank) {
		BottomRankJump(Configuration::MinimumBottomModestyRank);
	}

	if (HoursPassed < 1) {
		return;
	}

	int UpgradeTime = Configuration::ImmodestyTimeNeeded * 24;

	TopModesty(CurrentTopRank, HoursPassed, UpgradeTime);
	BottomModesty(CurrentBottomRank, HoursPassed, UpgradeTime);

	LastTimeChecked = CurrentGameTime;
}

/*
FUNCTION CALLS FROM PAPYRUS
*/

void ExternalStrictModesty(RE::StaticFunctionTag*, float CurrentGameTime) {
	StrictModesty(CurrentGameTime);
}

void ExternalSimpleModesty(RE::StaticFunctionTag*, float CurrentGameTime) {
	SimpleModesty(CurrentGameTime);
}

void ExternalRankJump(RE::StaticFunctionTag*, int RankValue) {
	RankJump(RankValue);
}

void ExternalTopRankJump(RE::StaticFunctionTag*, int RankValue) {
	TopRankJump(RankValue);
}

void ExternalBottomRankJump(RE::StaticFunctionTag*, int RankValue) {
	BottomRankJump(RankValue);
}