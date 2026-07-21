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

void StrictModesty() {
	if (Configuration::DynamicModestyEnabled == false) {
		Log("<C++ PlayerModesty> [StrictModesty] Dynamic Modesty is Disabled!", LogType::PlayerModesty);
		return;
	}
	
	float CurrentGameTime = GameCalendar->GetCurrentGameTime();
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
	bool IsShowingAss = Player->GetFactionRank(ShowingAssFaction, true) == 1;
	bool IsShowingGenitals = Player->GetFactionRank(ShowingGenitalsFaction, true) == 1;
	bool IsBottomless = Player->GetFactionRank(BottomlessFaction, true) == 1;

	bool IsNude = Player->GetFactionRank(NudeFaction, true) == 1;

	Log("<C++ PlayerModesty> [StrictModesty] Is Showing Bra: " + std::to_string(IsShowingBra), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [StrictModesty] Is Showing Chest: " + std::to_string(IsShowingChest), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [StrictModesty] Is Topless: " + std::to_string(IsTopless), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [StrictModesty] Is Showing Underwear: " + std::to_string(IsShowingUnderwear), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [StrictModesty] Is Showing Ass: " + std::to_string(IsShowingAss), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [StrictModesty] Is Showing Genitals: " + std::to_string(IsShowingGenitals), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [StrictModesty] Is Bottomless: " + std::to_string(IsBottomless), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [StrictModesty] Is Nude: " + std::to_string(IsNude), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [StrictModesty] Strict Timer started at: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);

	LastTimeChecked = CurrentGameTime;
	
	//Modest
	if (CurrentRank == StrictModestyLevel::Modest) {
		if (IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingAss && !IsShowingGenitals) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is MODEST. IS Showing Bra. NOT Showing Underwear, Ass, and Gentials - Timer Increase...", LogType::PlayerModesty);
			StrictModestyTimer[CurrentRank] += HoursPassed;
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingAss && !IsShowingGenitals) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is MODEST. NOT Showing Bra, Underwear, Ass, and Gentials - Timer Decrease...", LogType::PlayerModesty);
			StrictModestyDowngrade(CurrentRank, HoursPassed);
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
		}
	}
	//Reasonable
	else if (CurrentRank == StrictModestyLevel::Reasonable) {
		if ((IsShowingUnderwear || IsShowingAss) && IsShowingBra && !IsShowingGenitals && !IsShowingChest) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is REASONABLE. IS Showing Underwear or Ass. IS Showing Bra. NOT Showing Chest and Gentials - Timer Increase...", LogType::PlayerModesty);
			StrictModestyTimer[CurrentRank] += HoursPassed;
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingAss && !IsShowingGenitals) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is MODEST. NOT Showing Bra, Chest, Underwear, Ass, and Gentials - Timer Decrease...", LogType::PlayerModesty);
			StrictModestyDowngrade(CurrentRank, HoursPassed);
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
		}
	}
	//Relaxed
	else if (CurrentRank == StrictModestyLevel::Relaxed) {
		if (IsShowingChest && (IsShowingUnderwear || IsShowingAss) && !IsTopless && !IsShowingGenitals) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is RELAXED. IS Showing Underwear or Ass. IS Showing Chest. NOT Topless and Showing Gentials - Timer Increase...", LogType::PlayerModesty);
			StrictModestyTimer[CurrentRank] += HoursPassed;
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingBra && !IsShowingChest) || (!IsShowingUnderwear && !IsShowingAss && !IsShowingGenitals)) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is RELAXED. NOT Showing Bra and Chest OR NOT Showing Underwear, Ass, and Genitals - Timer Decrease...", LogType::PlayerModesty);
			StrictModestyDowngrade(CurrentRank, HoursPassed);
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
		}
	}
	//Comfortable
	else if (CurrentRank == StrictModestyLevel::Comfortable) {
		if (IsShowingGenitals && IsShowingChest && !IsTopless && !IsBottomless) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is COMFORTABLE. IS Showing Genitals and Chest. NOT Topless and NOT Bottomless - Timer Increase...", LogType::PlayerModesty);
			StrictModestyTimer[CurrentRank] += HoursPassed;
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
			if (StrictModestyTimer[CurrentRank] >= UpgradeTime) {
				if (!Configuration::ModestyUpgradeBlocked) {
					RankJump(CurrentRank + 1);
				}
				else {
					StrictModestyTimer[CurrentRank] = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingChest && !IsTopless) || (!IsShowingUnderwear && !IsShowingAss && !IsShowingGenitals)) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is COMFORTABLE. NOT Showing Chest and NOT Topless. NOT Showing Underwear, Ass, and Genitals - Timer Decrease...", LogType::PlayerModesty);
			StrictModestyDowngrade(CurrentRank, HoursPassed);
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
		}
	}
	//Tease
	else if (CurrentRank == StrictModestyLevel::Tease) {
		if (IsTopless && IsShowingGenitals && !IsBottomless) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is TEASE. IS Showing Genitals and Topless. NOT Bottomless - Timer Increase...", LogType::PlayerModesty);
			StrictModestyTimer[CurrentRank] += HoursPassed;
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
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
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is TEASE. NOT Showing Chest or NOT Showing Genitals. - Timer Decrease...", LogType::PlayerModesty);
			StrictModestyDowngrade(CurrentRank, HoursPassed);
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
		}
	}
	//Brazen
	else if (CurrentRank == StrictModestyLevel::Brazen) {
		if (IsTopless && IsBottomless) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is BRAZEN. IS Topless and Bottomless. - Timer Increase...", LogType::PlayerModesty);
			StrictModestyTimer[CurrentRank] += HoursPassed;
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
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
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is BRAZEN. NOT Showing Genitals or NOT Topless. - Timer Decrease...", LogType::PlayerModesty);
			StrictModestyDowngrade(CurrentRank, HoursPassed);
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
		}
	}
	//Immodest (previously 'Shameless')
	else if (CurrentRank == StrictModestyLevel::Immodest) {
		if (IsNude) {
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is IMMODEST. IS Nude. - Timer Increase...", LogType::PlayerModesty);
			StrictModestyTimer[CurrentRank] += HoursPassed;
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
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
			Log("<C++ PlayerModesty> [StrictModesty] Strict Rank is IMMODEST. NOT Topless or NOT Bottomless. - Timer Decrease...", LogType::PlayerModesty);
			StrictModestyDowngrade(CurrentRank, HoursPassed);
			Log("<C++ PlayerModesty> [StrictModesty] Strict Timer is now: " + std::to_string(StrictModestyTimer[CurrentRank]), LogType::PlayerModesty);
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

	Log("<C++ PlayerModesty> [TopModesty] Current Top Rank: " + std::to_string(CurrentTopRank), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [TopModesty] Showing Bra: " + std::to_string(IsShowingBra), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Showing Chest: " + std::to_string(IsShowingChest), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Topless: " + std::to_string(IsTopless), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [TopModesty] Modest TopModestyTimer started at: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Comfortable TopModestyTimer started at: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Brazen TopModestyTimer started at: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Immodet TopModestyTimer started at: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);

	//Modest (Previously 'Shy')
	if (CurrentTopRank == SimpleModestyLevel::Modest && IsShowingBra && !IsShowingChest) {
		Log("<C++ PlayerModesty> [TopModesty] Current Top Rank is MODET. IS Showing Bra. NOT Showing Chest.", LogType::PlayerModesty);
		TopModestyTimer[SimpleModestyLevel::Modest] += HoursPassed;
		Log("<C++ PlayerModesty> [TopModesty] Modest TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
	}
	//Comfortable
	else if (CurrentTopRank <= SimpleModestyLevel::Comfortable && IsShowingChest && !IsTopless) {
		Log("<C++ PlayerModesty> [TopModesty] Current Top Rank is less than or equal to COMFORTABLE. IS Showing Bra. NOT Topless.", LogType::PlayerModesty);
		TopModestyTimer[SimpleModestyLevel::Comfortable] += HoursPassed;
		Log("<C++ PlayerModesty> [TopModesty] Comfortable TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable && IsShowingBra && !IsShowingChest) {
		Log("<C++ PlayerModesty> [TopModesty] Current Top Rank is COMFORTABLE. IS Showing Bra. NOT Showing Chest. No timer change...", LogType::PlayerModesty);
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentTopRank <= SimpleModestyLevel::Brazen && IsTopless) {
		Log("<C++ PlayerModesty> [TopModesty] Current Top Rank is less than or equal to BRAZEN. IS Topless.", LogType::PlayerModesty);
		TopModestyTimer[SimpleModestyLevel::Brazen] += HoursPassed;
		Log("<C++ PlayerModesty> [TopModesty] Brazen TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen && IsShowingChest && !IsTopless) {
		Log("<C++ PlayerModesty> [TopModesty] Current Top Rank is BRAZEN. IS Showing Chest. NOT Topless. No timer change...", LogType::PlayerModesty);
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentTopRank == SimpleModestyLevel::Immodest && IsTopless) {
		Log("<C++ PlayerModesty> [TopModesty] Current Top Rank is IMMODEST. IS Topless.", LogType::PlayerModesty);
		TopModestyTimer[SimpleModestyLevel::Immodest] += HoursPassed;
		Log("<C++ PlayerModesty> [TopModesty] Immodest TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);
	}
	else if (CurrentTopRank > SimpleModestyLevel::Immodest) {
		if (!Configuration::AllowPlayerShameless) {
			TopRankJump(SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {
		Log("<C++ PlayerModesty> [TopModesty] Top Modesty Downgrade.", LogType::PlayerModesty);

		TopModestyDowngrade(CurrentTopRank, HoursPassed);
		
		Log("<C++ PlayerModesty> [TopModesty] Modest TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
		Log("<C++ PlayerModesty> [TopModesty] Comfortable TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
		Log("<C++ PlayerModesty> [TopModesty] Brazen TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
		Log("<C++ PlayerModesty> [TopModesty] Immodet TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);
		return;
	}

	Log("<C++ PlayerModesty> [TopModesty] Modest TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Comfortable TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Brazen TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [TopModesty] Immodet TopModestyTimer is now: " + std::to_string(TopModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [TopModesty] Required Upgrade Time is: " + std::to_string(UpgradeTime), LogType::PlayerModesty);

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
	bool IsShowingAss = Player->GetFactionRank(ShowingAssFaction, true) == 1;
	bool IsShowingGenitals = Player->GetFactionRank(ShowingGenitalsFaction, true) == 1;
	bool IsBottomless = Player->GetFactionRank(BottomlessFaction, true) == 1;

	Log("<C++ PlayerModesty> [BottomModesty] Current Bottom Rank: " + std::to_string(CurrentBottomRank), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [BottomModesty] Showing Underwear: " + std::to_string(IsShowingUnderwear), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Showing Ass: " + std::to_string(IsShowingAss), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Showing Genitals: " + std::to_string(IsShowingGenitals), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Bottomless: " + std::to_string(IsBottomless), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [BottomModesty] Modest BottomModestyTimer started at: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Comfortable BottomModestyTimer started at: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Brazen BottomModestyTimer started at: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Immodest BottomModestyTimer started at: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);
	
	//Modest (Previously 'Shy')
	if (CurrentBottomRank == SimpleModestyLevel::Modest && (IsShowingUnderwear || IsShowingAss) && !IsShowingGenitals) {
		Log("<C++ PlayerModesty> [BottomModesty] Current Bottom Rank is MODEST. IS Showing Underwear OR Showing Ass. NOT Showing Genitals.", LogType::PlayerModesty);
		BottomModestyTimer[SimpleModestyLevel::Modest] += HoursPassed;
		Log("<C++ PlayerModesty> [BottomModesty] Modest BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
	}
	//Comfortable
	else if (CurrentBottomRank <= SimpleModestyLevel::Comfortable && IsShowingGenitals && !IsBottomless) {
		Log("<C++ PlayerModesty> [BottomModesty] Current Bottom Rank is less than or equal to COMFORTABLE. IS Showing Underwear. NOT Bottomless.", LogType::PlayerModesty);
		BottomModestyTimer[SimpleModestyLevel::Comfortable] += HoursPassed;
		Log("<C++ PlayerModesty> [BottomModesty] Comfortable BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable && (IsShowingUnderwear || IsShowingAss) && !IsShowingGenitals) {
		Log("<C++ PlayerModesty> [BottomModesty] Current Bottom Rank is COMFORTABLE. IS Showing Underwear OR Showing Ass. NOT Showing Genitals. No timer change...", LogType::PlayerModesty);
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentBottomRank <= SimpleModestyLevel::Brazen && IsBottomless) {
		Log("<C++ PlayerModesty> [BottomModesty] Current Bottom Rank is less than or equal to BRAZEN. IS Bottomless.", LogType::PlayerModesty);
		BottomModestyTimer[SimpleModestyLevel::Brazen] += HoursPassed;
		Log("<C++ PlayerModesty> [BottomModesty] Brazen BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen && IsShowingGenitals && !IsBottomless) {
		Log("<C++ PlayerModesty> [BottomModesty] Current Bottom Rank is BRAZEN. IS Showing Genitals. NOT Bottomless. No timer change...", LogType::PlayerModesty);
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest && IsBottomless) {
		Log("<C++ PlayerModesty> [BottomModesty] Current Bottom Rank is IMMODEST. IS Bottomless.", LogType::PlayerModesty);
		BottomModestyTimer[SimpleModestyLevel::Immodest] += HoursPassed;
		Log("<C++ PlayerModesty> [BottomModesty] Immodest BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);
	}
	else if (CurrentBottomRank > SimpleModestyLevel::Immodest) {
		if (!Configuration::AllowPlayerShameless) {
			BottomRankJump(SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {
		Log("<C++ PlayerModesty> [BottomModesty] Bottom Modesty Downgrade.", LogType::PlayerModesty);
		
		BottomModestyDowngrade(CurrentBottomRank, HoursPassed);
		
		Log("<C++ PlayerModesty> [BottomModesty] Modest BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
		Log("<C++ PlayerModesty> [BottomModesty] Comfortable BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
		Log("<C++ PlayerModesty> [BottomModesty] Brazen BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
		Log("<C++ PlayerModesty> [BottomModesty] Immodest BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);
		return;
	}

	Log("<C++ PlayerModesty> [BottomModesty] Modest BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Modest]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Comfortable BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Comfortable]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Brazen BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Brazen]), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [BottomModesty] Immodest BottomModestyTimer is now: " + std::to_string(BottomModestyTimer[SimpleModestyLevel::Immodest]), LogType::PlayerModesty);

	Log("<C++ PlayerModesty> [BottomModesty] Required Upgrade Time is: " + std::to_string(UpgradeTime), LogType::PlayerModesty);

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

void SimpleModesty() {
	if (Configuration::DynamicModestyEnabled == false) {
		Log("<C++ PlayerModesty> [SimpleModesty] Dynamic Modesty is Disabled!", LogType::PlayerModesty, LoggingLevel::warning);
		return;
	}
	
	float CurrentGameTime = GameCalendar->GetCurrentGameTime();
	int HoursPassed = static_cast<int>((CurrentGameTime - LastTimeChecked) / 0.041666);
	Log("<C++ PlayerModesty> [SimpleModesty] Hours Passed: " + std::to_string(HoursPassed), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [SimpleModesty] RAW Hours Passed: " + std::to_string(((CurrentGameTime - LastTimeChecked) / 0.041666)), LogType::PlayerModesty);

	int CurrentTopRank = Player->GetFactionRank(TopModestyFaction, true);
	int CurrentBottomRank = Player->GetFactionRank(BottomModestyFaction, true);

	Log("<C++ PlayerModesty> [SimpleModesty] Curent Top Rank is: " + std::to_string(CurrentTopRank), LogType::PlayerModesty);
	Log("<C++ PlayerModesty> [SimpleModesty] Curent Bottom Rank is: " + std::to_string(CurrentBottomRank), LogType::PlayerModesty);

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

void ExternalStrictModesty(RE::StaticFunctionTag*) {
	StrictModesty();
}

void ExternalSimpleModesty(RE::StaticFunctionTag*) {
	SimpleModesty();
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