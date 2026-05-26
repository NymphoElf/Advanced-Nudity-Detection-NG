#include "NPCData.h"
#include "Config.h"
#include "Core.h"
#include "Logger.h"

void ChangeStrictRank(RE::Actor* akFemale, int FemaleID, int Rank)
{
	RegisteredFemales& female = registeredfemales[FemaleID];
	SetActorFactionRank(akFemale, ModestyFaction, HandleInteger(Rank));
	female.CurrentRankStrict = HandleInteger(Rank);

	female.ModestyTimer0 = 0;
	female.ModestyTimer1 = 0;
	female.ModestyTimer2 = 0;
	female.ModestyTimer3 = 0;
	female.ModestyTimer4 = 0;
	female.ModestyTimer5 = 0;
	female.ModestyTimer6 = 0;
}

void ChangeTopRank(RE::Actor* akFemale, int FemaleID, int Rank)
{
	RegisteredFemales& female = registeredfemales[FemaleID];
	SetActorFactionRank(akFemale, TopModestyFaction, HandleInteger(Rank));
	female.CurrentRankTop = HandleInteger(Rank);

	female.TopModestyTimer0 = 0;
	female.TopModestyTimer1 = 0;
	female.TopModestyTimer2 = 0;
	female.TopModestyTimer3 = 0;
}

void ChangeBottomRank(RE::Actor* akFemale, int FemaleID, int Rank)
{
	RegisteredFemales& female = registeredfemales[FemaleID];
	SetActorFactionRank(akFemale, BottomModestyFaction, HandleInteger(Rank));
	female.CurrentRankBottom = HandleInteger(Rank);

	female.BottomModestyTimer0 = 0;
	female.BottomModestyTimer1 = 0;
	female.BottomModestyTimer2 = 0;
	female.BottomModestyTimer3 = 0;
}

void StrictNPCModesty(RE::Actor* akFemale, std::string FemaleName, int FemaleID, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless)
{
	Log("<C++ NPCModesty> [StrictNPCModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{0:#x}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	RegisteredFemales& female = registeredfemales[FemaleID];

	int CurrentRank = female.CurrentRankStrict;
	int MinimumRank = female.MinimumRankStrict;

	bool IsShowingBra = akFemale->GetFactionRank(ShowingBraFaction, false) == 1;
	bool IsShowingChest = akFemale->GetFactionRank(ShowingChestFaction, false) == 1;
	bool IsTopless = akFemale->GetFactionRank(ToplessFaction, false) == 1;

	bool IsShowingUnderwear = akFemale->GetFactionRank(ShowingUnderwearFaction, false) == 1;
	bool IsShowingGenitals = akFemale->GetFactionRank(ShowingGenitalsFaction, false) == 1;
	bool IsBottomless = akFemale->GetFactionRank(BottomlessFaction, false) == 1;

	bool IsNude = akFemale->GetFactionRank(NudeFaction, false) == 1;

	if (MinimumRank > CurrentRank) {
		ChangeStrictRank(akFemale, FemaleID, MinimumRank);
	}

	if (CurrentRank == StrictModestyLevel::Modest) {
		if (IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			female.ModestyTimer0 += HoursPassed;
			
			if (female.ModestyTimer0 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					female.ModestyTimer0 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			if (female.ModestyTimer0 > 0) {
				female.ModestyTimer0 -= HoursPassed;
			}

			if (female.ModestyTimer0 < 0) {
				female.ModestyTimer0 = 0;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Reasonable) {
		if (IsShowingUnderwear && IsShowingBra && !IsShowingGenitals && !IsShowingChest) {
			female.ModestyTimer1 += HoursPassed;

			if (female.ModestyTimer1 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					female.ModestyTimer1 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			female.ModestyTimer1 -= HoursPassed;

			if (!Corruption && female.ModestyTimer1 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (female.ModestyTimer1 < -UpgradeTime) {
				female.ModestyTimer1 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Relaxed) {
		if (IsShowingChest && IsShowingUnderwear && !IsTopless && !IsShowingGenitals) {
			female.ModestyTimer2 += HoursPassed;

			if (female.ModestyTimer2 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					female.ModestyTimer2 = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingBra && !IsShowingChest) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			female.ModestyTimer2 -= HoursPassed;

			if (!Corruption && female.BottomModestyTimer2 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (female.ModestyTimer2 < -UpgradeTime) {
				female.ModestyTimer2 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Comfortable) {
		if (IsShowingGenitals && IsShowingChest && !IsTopless && !IsBottomless) {
			female.ModestyTimer3 += HoursPassed;

			if (female.ModestyTimer3 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					female.ModestyTimer3 = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingChest && !IsTopless) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			female.ModestyTimer3 -= HoursPassed;

			if (!Corruption && female.ModestyTimer3 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (female.ModestyTimer3 < -UpgradeTime) {
				female.ModestyTimer3 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Tease) {
		if (IsTopless && IsShowingGenitals && !IsBottomless) {
			female.ModestyTimer4 += HoursPassed;

			if (female.ModestyTimer4 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					female.ModestyTimer4 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingChest || !IsShowingGenitals) {
			female.ModestyTimer4 -= HoursPassed;

			if (!Corruption && female.ModestyTimer4 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (female.ModestyTimer4 < -UpgradeTime) {
				female.ModestyTimer4 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Brazen) {
		if (IsTopless && IsBottomless) {
			female.ModestyTimer5 += HoursPassed;

			if (female.ModestyTimer5 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					female.ModestyTimer5 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingGenitals || !IsTopless) {
			female.ModestyTimer5 -= HoursPassed;

			if (!Corruption && female.ModestyTimer5 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (female.ModestyTimer5 < -UpgradeTime) {
				female.ModestyTimer5 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Immodest) {
		if (IsNude) {
			female.ModestyTimer6 += HoursPassed;
			
			if (AllowShameless && female.ModestyTimer6 >= UpgradeTime * 2) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					female.ModestyTimer6 = UpgradeTime * 2;
				}
			}
			else if (female.ModestyTimer6 > UpgradeTime) {
				female.ModestyTimer6 = UpgradeTime;
			}
		}
		else if (!IsTopless || !IsBottomless) {
			female.ModestyTimer6 -= HoursPassed;

			if (!Corruption && female.ModestyTimer6 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (female.ModestyTimer6 < -UpgradeTime) {
				female.ModestyTimer6 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank >= StrictModestyLevel::Shameless && !AllowShameless) {
		ChangeStrictRank(akFemale, FemaleID, StrictModestyLevel::Immodest);
	}
}

void NPCTopModesty(RE::Actor* akFemale, std::string FemaleName, int FemaleID, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless) {
	Log("<C++ NPCModesty> [NPCTopModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{0:#x}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	RegisteredFemales& female = registeredfemales[FemaleID];

	int CurrentTopRank = female.CurrentRankTop;
	int MinimumTopRank = female.MinimumRankTop;

	bool IsShowingBra = akFemale->GetFactionRank(ShowingBraFaction, false) == 1;
	bool IsShowingChest = akFemale->GetFactionRank(ShowingChestFaction, false) == 1;
	bool IsTopless = akFemale->GetFactionRank(ToplessFaction, false) == 1;

	if (MinimumTopRank > CurrentTopRank) {
		ChangeTopRank(akFemale, FemaleID, MinimumTopRank);
	}

	//Modest (Previously 'Shy')
	if (CurrentTopRank == SimpleModestyLevel::Modest && IsShowingBra && !IsShowingChest) {
		female.TopModestyTimer0 += HoursPassed;
	}
	//Comfortable
	else if (CurrentTopRank <= SimpleModestyLevel::Comfortable && IsShowingChest && !IsTopless) {
		female.TopModestyTimer1 += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable && IsShowingBra && !IsShowingChest) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentTopRank <= SimpleModestyLevel::Brazen && IsTopless) {
		female.TopModestyTimer2 += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen && IsShowingChest && !IsTopless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentTopRank == SimpleModestyLevel::Immodest && IsTopless) {
		female.TopModestyTimer3 += HoursPassed;
	}
	else if (CurrentTopRank > SimpleModestyLevel::Immodest) {
		if (!AllowShameless) {
			ChangeTopRank(akFemale, FemaleID, SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {

		if (CurrentTopRank <= SimpleModestyLevel::Modest) {
			female.TopModestyTimer0 -= HoursPassed;
			female.TopModestyTimer1 -= HoursPassed;
			female.TopModestyTimer2 -= HoursPassed;

			if (female.TopModestyTimer0 <= 0) {
				female.TopModestyTimer0 = 0;
			}

			if (female.TopModestyTimer1 <= 0) {
				female.TopModestyTimer1 = 0;
			}

			if (female.TopModestyTimer2 <= 0) {
				female.TopModestyTimer2 = 0;
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Comfortable) {
			female.TopModestyTimer1 -= HoursPassed;
			female.TopModestyTimer2 -= HoursPassed;

			if (female.TopModestyTimer2 <= 0) {
				female.TopModestyTimer2 = 0;
			}

			if (female.TopModestyTimer1 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, FemaleID, CurrentTopRank - 1);
				}
				else {
					female.TopModestyTimer1 = -UpgradeTime;
				}
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Brazen) {
			female.TopModestyTimer2 -= HoursPassed;

			if (female.TopModestyTimer2 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, FemaleID, CurrentTopRank - 1);
				}
				else {
					female.TopModestyTimer2 = -UpgradeTime;
				}
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Immodest) {
			female.TopModestyTimer3 -= HoursPassed;

			if (female.TopModestyTimer3 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, FemaleID, CurrentTopRank - 1);
				}
				else {
					female.TopModestyTimer3 = -UpgradeTime;
				}
			}
		}

		return;
	}

	if (CurrentTopRank == SimpleModestyLevel::Modest) {
		if ((female.TopModestyTimer0 + (female.TopModestyTimer1 / 2) + (female.TopModestyTimer2 / 4)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				if (female.TopModestyTimer0 > UpgradeTime) {
					female.TopModestyTimer0 = UpgradeTime;
				}

				if (female.TopModestyTimer1 > (UpgradeTime * 2)) {
					female.TopModestyTimer1 = (UpgradeTime * 2);
				}

				if (female.TopModestyTimer2 > (UpgradeTime * 4)) {
					female.TopModestyTimer2 = (UpgradeTime * 4);
				}
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable) {
		if ((female.TopModestyTimer1 + (female.TopModestyTimer2 / 2)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				if (female.TopModestyTimer1 > UpgradeTime) {
					female.TopModestyTimer1 = UpgradeTime;
				}

				if (female.TopModestyTimer2 > (UpgradeTime * 2)) {
					female.TopModestyTimer2 = (UpgradeTime * 2);
				}
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen) {
		if (female.TopModestyTimer2 >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				female.TopModestyTimer2 = UpgradeTime;
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Immodest) {
		if (AllowShameless && female.TopModestyTimer3 >= (UpgradeTime * 2)) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				female.TopModestyTimer3 = (UpgradeTime * 2);
			}
		}
		else if (female.TopModestyTimer3 > UpgradeTime) {
			female.TopModestyTimer3 = UpgradeTime;
		}
	}
}

void NPCBottomModesty(RE::Actor* akFemale, std::string FemaleName, int FemaleID, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless) {
	Log("<C++ NPCModesty> [NPCBottomModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{0:#x}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	RegisteredFemales& female = registeredfemales[FemaleID];

	int CurrentBottomRank = female.CurrentRankBottom;
	int MinimumBottomRank = female.MinimumRankBottom;

	bool IsShowingUnderwear = akFemale->GetFactionRank(ShowingUnderwearFaction, false) == 1;
	bool IsShowingGenitals = akFemale->GetFactionRank(ShowingGenitalsFaction, false) == 1;
	bool IsBottomless = akFemale->GetFactionRank(BottomlessFaction, false) == 1;

	if (MinimumBottomRank > CurrentBottomRank) {
		ChangeBottomRank(akFemale, FemaleID, MinimumBottomRank);
	}

	//Modest (Previously 'Shy')
	if (CurrentBottomRank == SimpleModestyLevel::Modest && IsShowingUnderwear && !IsShowingGenitals) {
		female.BottomModestyTimer0 += HoursPassed;
	}
	//Comfortable
	else if (CurrentBottomRank <= SimpleModestyLevel::Comfortable && IsShowingGenitals && !IsBottomless) {
		female.BottomModestyTimer1 += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable && IsShowingUnderwear && !IsShowingGenitals) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentBottomRank <= SimpleModestyLevel::Brazen && IsBottomless) {
		female.BottomModestyTimer2 += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen && IsShowingGenitals && !IsBottomless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest && IsBottomless) {
		female.BottomModestyTimer3 += HoursPassed;
	}
	else if (CurrentBottomRank > SimpleModestyLevel::Immodest) {
		if (!AllowShameless) {
			ChangeBottomRank(akFemale, FemaleID, SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {

		if (CurrentBottomRank <= SimpleModestyLevel::Modest) {
			female.BottomModestyTimer0 -= HoursPassed;
			female.BottomModestyTimer1 -= HoursPassed;
			female.BottomModestyTimer2 -= HoursPassed;

			if (female.BottomModestyTimer0 <= 0) {
				female.BottomModestyTimer0 = 0;
			}

			if (female.BottomModestyTimer1 <= 0) {
				female.BottomModestyTimer1 = 0;
			}

			if (female.BottomModestyTimer2 <= 0) {
				female.BottomModestyTimer2 = 0;
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Comfortable) {
			female.BottomModestyTimer1 -= HoursPassed;
			female.BottomModestyTimer2 -= HoursPassed;

			if (female.BottomModestyTimer2 <= 0) {
				female.BottomModestyTimer2 = 0;
			}

			if (female.BottomModestyTimer1 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank - 1);
				}
				else {
					female.BottomModestyTimer1 = -UpgradeTime;
				}
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Brazen) {
			female.BottomModestyTimer2 -= HoursPassed;

			if (female.BottomModestyTimer2 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank - 1);
				}
				else {
					female.BottomModestyTimer2 = -UpgradeTime;
				}
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Immodest) {
			female.BottomModestyTimer3 -= HoursPassed;

			if (female.BottomModestyTimer3 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank - 1);
				}
				else {
					female.BottomModestyTimer3 = -UpgradeTime;
				}
			}
		}

		return;
	}

	if (CurrentBottomRank == SimpleModestyLevel::Modest) {
		if ((female.BottomModestyTimer0 + (female.BottomModestyTimer1 / 2) + (female.BottomModestyTimer2 / 4)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				if (female.BottomModestyTimer0 > UpgradeTime) {
					female.BottomModestyTimer0 = UpgradeTime;
				}

				if (female.BottomModestyTimer1 > (UpgradeTime * 2)) {
					female.BottomModestyTimer1 = (UpgradeTime * 2);
				}

				if (female.BottomModestyTimer2 > (UpgradeTime * 4)) {
					female.BottomModestyTimer2 = (UpgradeTime * 4);
				}
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable) {
		if ((female.BottomModestyTimer1 + (female.BottomModestyTimer2 / 2)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				if (female.BottomModestyTimer1 > UpgradeTime) {
					female.BottomModestyTimer1 = UpgradeTime;
				}

				if (female.BottomModestyTimer2 > (UpgradeTime * 2)) {
					female.BottomModestyTimer2 = (UpgradeTime * 2);
				}
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen) {
		if (female.BottomModestyTimer2 >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				female.BottomModestyTimer2 = UpgradeTime;
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest) {
		if (AllowShameless && female.BottomModestyTimer3 >= (UpgradeTime * 2)) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				female.BottomModestyTimer3 = (UpgradeTime * 2);
			}
		}
		else if (female.BottomModestyTimer3 > UpgradeTime) {
			female.BottomModestyTimer3 = UpgradeTime;
		}
	}
}

void ProcessNPCModesty(RE::Actor* akFemale, int FemaleID, float CurrentGameTime) {
	
	std::string FemaleName = akFemale->GetName();

	Log("<C++ NPCModesty> [ProcessNPCModesty] Actor is: " + FemaleName + " | FormID: (" + std::format("{0:08X}", akFemale->GetFormID()) + ")" + " | Internal ID: " + std::to_string(FemaleID), LogType::NPCModesty);

	RegisteredFemales& female = registeredfemales[FemaleID];

	bool Corruption = female.AllowCorruption;
	bool Blocked = female.UpgradeBlocked;

	int HoursPassed = static_cast<int>((CurrentGameTime - female.LastUpdateTime) / 0.041666);

	Log("<C++ NPCModesty> [ProcessNPCModesty] RAW Hours passed for this actor: " + std::to_string(((CurrentGameTime - female.LastUpdateTime) / 0.041666)), LogType::NPCModesty);

	if (HoursPassed < 1) 
	{
		Log("<C++ NPCModesty> [ProcessNPCModesty] Less than an hour has passed for this actor. Skipping update...", LogType::NPCModesty);
		return;
	}

	int UpgradeTime = Configuration::ImmodestyTimeNeeded * 24;
	
	bool AllowShameless = female.AllowShameless[FemaleID];
	
	bool StrictRules = female.StrictRules[FemaleID];

	if (StrictRules) {
		StrictNPCModesty(akFemale, FemaleName, FemaleID, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
	}
	else {
		NPCTopModesty(akFemale, FemaleName, FemaleID, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
		NPCBottomModesty(akFemale, FemaleName, FemaleID, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
	}

	female.LastUpdateTime[FemaleID] = CurrentGameTime;
}