#include "PlayerModesty.h"
#include "Core.h"
#include "Config.h"

void TopRankJump(int8_t factionRank) {
	SetPlayerFactionRank(TopModestyFaction, factionRank);

	int index = 0;
	while (index < std::size(TopModestyTimer)) {
		TopModestyTimer[index] = 0;
		index++;
	}
}

void BottomRankJump(int8_t factionRank) {
	SetPlayerFactionRank(BottomModestyFaction, factionRank);

	int index = 0;
	while (index < std::size(BottomModestyTimer)) {
		BottomModestyTimer[index] = 0;
		index++;
	}
}

void RankJump(int8_t factionRank) {
	SetPlayerFactionRank(ModestyFaction, factionRank);

	int index = 0;
	while (index < std::size(StrictModestyTimer)) {
		StrictModestyTimer[index] = 0;
		index++;
	}
}

void TopModestyDowngrade(int Rank, int HoursPassed) {
	int DowngradeTime = ImmodestyTimeNeeded * -24;

	if (MinimumTopModestyRank < Rank) {
		TopModestyTimer[Rank] -= HoursPassed;
		if (Corruption && TopModestyTimer[Rank] < 0) {
			TopModestyTimer[Rank] = 0;
		}
		else if (TopModestyTimer[Rank] <= DowngradeTime) {
			TopRankJump((Rank - 1));
		}
	}
	else if (MinimumTopModestyRank == Rank) {
		TopModestyTimer[Rank] -= HoursPassed;
		if (TopModestyTimer[Rank] < 0) {
			TopModestyTimer[Rank] = 0;
		}
	}
}

void BottomModestyDowngrade(int Rank, int HoursPassed) {
	int DowngradeTime = ImmodestyTimeNeeded * -24;

	if (MinimumBottomModestyRank < Rank) {
		BottomModestyTimer[Rank] -= HoursPassed;
		if (Corruption && BottomModestyTimer[Rank] < 0) {
			BottomModestyTimer[Rank] = 0;
		}
		else if (BottomModestyTimer[Rank] <= DowngradeTime) {
			BottomRankJump((Rank - 1));
		}
	}
	else if (MinimumBottomModestyRank == Rank) {
		BottomModestyTimer[Rank] -= HoursPassed;
		if (BottomModestyTimer[Rank] < 0) {
			BottomModestyTimer[Rank] = 0;
		}
	}
}

void StrictModestyDowngrade(int Rank, int HoursPassed) {
	int DowngradeTime = ImmodestyTimeNeeded * -24;

	if (MinimumModestyRank < Rank) {
		StrictModestyTimer[Rank] -= HoursPassed;
		if (Corruption && StrictModestyTimer[Rank] < 0) {
			StrictModestyTimer[Rank] = 0;
		}
		else if (StrictModestyTimer[Rank] <= DowngradeTime) {
			RankJump((Rank - 1));
		}
	}
	else if (MinimumModestyRank == Rank) {
		StrictModestyTimer[Rank] -= HoursPassed;
		if (StrictModestyTimer[Rank] < 0) {
			StrictModestyTimer[Rank] = 0;
		}
	}
}

void StrictModesty(float CurrentGameTime) {
	int HoursPassed = ((CurrentGameTime - LastTimeChecked) / 0.041666);
	logs::critical("<C++ PlayerModesty> [StrictModesty] Hours Passed: {}", HoursPassed);
	logs::critical("<C++ PlayerModesty> [StrictModesty] RAW Hours Passed: {}", ((CurrentGameTime - LastTimeChecked) / 0.041666));

	int CurrentRank = Player->GetFactionRank(ModestyFaction, true);

	if (MinimumModestyRank > CurrentRank) {
		RankJump(MinimumModestyRank);
	}

	if (HoursPassed < 1) {
		return;
	}

	int UpgradeTime = ImmodestyTimeNeeded * 24;

	bool IsShowingBra = Player->GetFactionRank(ShowingBraFaction, true) == 1;
	bool IsShowingChest = Player->GetFactionRank(ShowingChestFaction, true) == 1;
	bool IsTopless = Player->GetFactionRank(ToplessFaction, true) == 1;

	bool IsShowingUnderwear = Player->GetFactionRank(ShowingUnderwearFaction, true) == 1;
	bool IsShowingGenitals = Player->GetFactionRank(ShowingGenitalsFaction, true) == 1;
	bool IsBottomless = Player->GetFactionRank(BottomlessFaction, true) == 1;

	bool IsNude = Player->GetFactionRank(NudeFaction, true) == 1;
	
	//Modest
	if (CurrentRank == 0) {
		if (IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			StrictModestyTimer[0] += HoursPassed;
			if (StrictModestyTimer[0] >= UpgradeTime) {
				RankJump(1);
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			StrictModestyDowngrade(0, HoursPassed);
		}
	}
	//Reasonable
	else if (CurrentRank == 1) {
		if (IsShowingUnderwear && IsShowingBra && !IsShowingGenitals && !IsShowingChest) {
			StrictModestyTimer[1] += HoursPassed;
			if (StrictModestyTimer[1] >= UpgradeTime) {
				RankJump(2);
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			StrictModestyDowngrade(1, HoursPassed);
		}
	}
	//Relaxed
	else if (CurrentRank == 2) {
		if (IsShowingChest && IsShowingUnderwear && !IsTopless && !IsShowingGenitals) {
			StrictModestyTimer[2] += HoursPassed;
			if (StrictModestyTimer[2] >= UpgradeTime) {
				RankJump(3);
			}
		}
		else if ((!IsShowingBra && !IsShowingChest) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			StrictModestyDowngrade(2, HoursPassed);
		}
	}
	//Comfortable
	else if (CurrentRank == 3) {
		if (IsShowingGenitals && IsShowingChest && !IsTopless && !IsBottomless) {
			StrictModestyTimer[3] += HoursPassed;
			if (StrictModestyTimer[3] >= UpgradeTime) {
				RankJump(4);
			}
		}
		else if ((!IsShowingChest && !IsTopless) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			StrictModestyDowngrade(3, HoursPassed);
		}
	}
	//Tease
	else if (CurrentRank == 4) {
		if (IsTopless && IsShowingGenitals && !IsBottomless) {
			StrictModestyTimer[4] += HoursPassed;
			if (StrictModestyTimer[4] >= UpgradeTime) {
				RankJump(5);
			}
		}
		else if (!IsShowingChest || !IsShowingGenitals) {
			StrictModestyDowngrade(4, HoursPassed);
		}
	}
	//Brazen
	else if (CurrentRank == 5) {
		if (IsTopless && IsBottomless) {
			StrictModestyTimer[5] += HoursPassed;
			if (StrictModestyTimer[5] >= UpgradeTime) {
				RankJump(6);
			}
		}
		else if (!IsShowingGenitals || !IsTopless) {
			StrictModestyDowngrade(5, HoursPassed);
		}
	}
	//Shameless
	else if (CurrentRank == 6) {
		if (IsNude) {
			StrictModestyTimer[6] += HoursPassed;
			if (PermanentShameless && StrictModestyTimer[6] >= UpgradeTime * 2) {
				RankJump(7);
			}
			else if (StrictModestyTimer[6] > UpgradeTime) {
				StrictModestyTimer[6] = UpgradeTime;
			}
		}
		else if (!IsTopless || !IsBottomless) {
			StrictModestyDowngrade(6, HoursPassed);
		}
	}
	//Permanently Shameless
	else if (CurrentRank > 6 && !PermanentShameless) {
		RankJump(6);
	}
}

void TopModesty(int CurrentTopRank, int HoursPassed, int UpgradeTime) {
	bool IsShowingBra = Player->GetFactionRank(ShowingBraFaction, true) == 1;
	bool IsShowingChest = Player->GetFactionRank(ShowingChestFaction, true) == 1;
	bool IsTopless = Player->GetFactionRank(ToplessFaction, true) == 1;

	//Shy
	if (CurrentTopRank == 0 && IsShowingBra && !IsShowingChest) {
		TopModestyTimer[0] += HoursPassed;
	}
	//Comfortable
	else if (CurrentTopRank <= 1 && IsShowingChest && !IsTopless) {
		TopModestyTimer[1] += HoursPassed;
	}
	else if (CurrentTopRank == 1 && IsShowingBra && !IsShowingChest) {
		//Do Nothing
	}
	//Bold
	else if (CurrentTopRank <= 2 && IsTopless) {
		TopModestyTimer[2] += HoursPassed;
	}
	else if (CurrentTopRank == 2 && IsShowingChest && !IsTopless) {
		//Do Nothing
	}
	//Shameless
	else if (CurrentTopRank == 3 && IsTopless) {
		TopModestyTimer[3] += HoursPassed;
	}
	else if (CurrentTopRank > 3) {
		if (!PermanentShameless) {
			TopRankJump(3);
		}
		return;
	}
	else {
		TopModestyDowngrade(CurrentTopRank, HoursPassed);
		return;
	}

	if (CurrentTopRank == 0) {
		if ((TopModestyTimer[0] + (TopModestyTimer[1] / 2) + (TopModestyTimer[2] / 4)) >= UpgradeTime) {
			TopRankJump(1);
		}
	}
	else if (CurrentTopRank == 1) {
		if ((TopModestyTimer[1] + (TopModestyTimer[2] / 2)) >= UpgradeTime) {
			TopRankJump(2);
		}
	}
	else if (CurrentTopRank == 2) {
		if (TopModestyTimer[2] >= UpgradeTime) {
			TopRankJump(3);
		}
	}
	else if (CurrentTopRank == 3) {
		if (PermanentShameless && TopModestyTimer[3] >= UpgradeTime * 2) {
			TopRankJump(4);
		}
		else if (TopModestyTimer[3] > UpgradeTime) {
			TopModestyTimer[3] = UpgradeTime;
		}
	}
}

void BottomModesty(int CurrentBottomRank, int HoursPassed, int UpgradeTime) {
	bool IsShowingUnderwear = Player->GetFactionRank(ShowingUnderwearFaction, true) == 1;
	bool IsShowingGenitals = Player->GetFactionRank(ShowingGenitalsFaction, true) == 1;
	bool IsBottomless = Player->GetFactionRank(BottomlessFaction, true) == 1;
	
	//Shy
	if (CurrentBottomRank == 0 && IsShowingUnderwear && !IsShowingGenitals) {
		BottomModestyTimer[0] += HoursPassed;
	}
	//Comfortable
	else if (CurrentBottomRank <= 1 && IsShowingGenitals && !IsBottomless) {
		BottomModestyTimer[1] += HoursPassed;
	}
	else if (CurrentBottomRank == 1 && IsShowingUnderwear && !IsShowingGenitals) {
		//Do Nothing
	}
	//Bold
	else if (CurrentBottomRank <= 2 && IsBottomless) {
		BottomModestyTimer[2] += HoursPassed;
	}
	else if (CurrentBottomRank == 2 && IsShowingGenitals && !IsBottomless) {
		//Do Nothing
	}
	//Shameless
	else if (CurrentBottomRank == 3 && IsBottomless) {
		BottomModestyTimer[3] += HoursPassed;
	}
	else if (CurrentBottomRank > 3) {
		if (!PermanentShameless) {
			BottomRankJump(3);
		}
		return;
	}
	else {
		BottomModestyDowngrade(CurrentBottomRank, HoursPassed);
		return;
	}

	if (CurrentBottomRank == 0) {
		if ((BottomModestyTimer[0] + (BottomModestyTimer[1] / 2) + (BottomModestyTimer[2] / 4)) >= UpgradeTime) {
			BottomRankJump(1);
		}
	}
	else if (CurrentBottomRank == 1) {
		if ((BottomModestyTimer[1] + (BottomModestyTimer[2] / 2)) >= UpgradeTime) {
			BottomRankJump(2);
		}
	}
	else if (CurrentBottomRank == 2) {
		if (BottomModestyTimer[2] >= UpgradeTime) {
			BottomRankJump(3);
		}
	}
	else if (CurrentBottomRank == 3) {
		if (PermanentShameless && BottomModestyTimer[3] >= UpgradeTime * 2) {
			BottomRankJump(4);
		}
		else if (BottomModestyTimer[3] > UpgradeTime) {
			BottomModestyTimer[3] = UpgradeTime;
		}
	}
}

void SimpleModesty(float CurrentGameTime) {
	int HoursPassed = ((CurrentGameTime - LastTimeChecked) / 0.041666);
	logs::critical("<C++ PlayerModesty> [SimpleModesty] Hours Passed: {}", HoursPassed);
	logs::critical("<C++ PlayerModesty> [SimpleModesty] RAW Hours Passed: {}", ((CurrentGameTime - LastTimeChecked) / 0.041666));

	int CurrentTopRank = Player->GetFactionRank(TopModestyFaction, true);
	int CurrentBottomRank = Player->GetFactionRank(BottomModestyFaction, true);

	if (MinimumTopModestyRank > CurrentTopRank) {
		TopRankJump(MinimumTopModestyRank);
	}

	if (MinimumBottomModestyRank > CurrentBottomRank) {
		BottomRankJump(MinimumBottomModestyRank);
	}

	if (HoursPassed < 1) {
		return;
	}

	int UpgradeTime = ImmodestyTimeNeeded * 24;

	TopModesty(CurrentTopRank, HoursPassed, UpgradeTime);
	BottomModesty(CurrentBottomRank, HoursPassed, UpgradeTime);
}

void ExternalStrictModesty(RE::StaticFunctionTag*, float CurrentGameTime) {
	StrictModesty(CurrentGameTime);
}

void ExternalSimpleModesty(RE::StaticFunctionTag*, float CurrentGameTime) {
	SimpleModesty(CurrentGameTime);
}