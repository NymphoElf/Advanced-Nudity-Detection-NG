#include "NPCData.h"
#include "Config.h"
#include "Core.h"
#include "Logger.h"

void ChangeStrictRank(RE::Actor* akFemale, int Rank)
{
	RegisteredFemales& ThisFemale = RegisteredFemaleMap[akFemale->GetFormID()];
	SetActorFactionRank(akFemale, ModestyFaction, HandleInteger(Rank));
	ThisFemale.CurrentRankStrict = HandleInteger(Rank);

	ThisFemale.ModestyTimer0 = 0;
	ThisFemale.ModestyTimer1 = 0;
	ThisFemale.ModestyTimer2 = 0;
	ThisFemale.ModestyTimer3 = 0;
	ThisFemale.ModestyTimer4 = 0;
	ThisFemale.ModestyTimer5 = 0;
	ThisFemale.ModestyTimer6 = 0;
}

void ChangeTopRank(RE::Actor* akFemale, int Rank)
{
	RegisteredFemales& ThisFemale = RegisteredFemaleMap[akFemale->GetFormID()];
	SetActorFactionRank(akFemale, TopModestyFaction, HandleInteger(Rank));
	ThisFemale.CurrentRankTop = HandleInteger(Rank);

	ThisFemale.TopModestyTimer0 = 0;
	ThisFemale.TopModestyTimer1 = 0;
	ThisFemale.TopModestyTimer2 = 0;
	ThisFemale.TopModestyTimer3 = 0;
}

void ChangeBottomRank(RE::Actor* akFemale, int Rank)
{
	RegisteredFemales& ThisFemale = RegisteredFemaleMap[akFemale->GetFormID()];
	SetActorFactionRank(akFemale, BottomModestyFaction, HandleInteger(Rank));
	ThisFemale.CurrentRankBottom = HandleInteger(Rank);

	ThisFemale.BottomModestyTimer0 = 0;
	ThisFemale.BottomModestyTimer1 = 0;
	ThisFemale.BottomModestyTimer2 = 0;
	ThisFemale.BottomModestyTimer3 = 0;
}

void StrictNPCModesty(RE::Actor* akFemale, std::string FemaleName, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless)
{
	Log("<C++ NPCModesty> [StrictNPCModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{:08X}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	RegisteredFemales& ThisFemale = RegisteredFemaleMap[akFemale->GetFormID()];

	int CurrentRank = ThisFemale.CurrentRankStrict;
	int MinimumRank = ThisFemale.MinimumRankStrict;

	bool IsShowingBra = akFemale->GetFactionRank(ShowingBraFaction, false) == 1;
	bool IsShowingChest = akFemale->GetFactionRank(ShowingChestFaction, false) == 1;
	bool IsTopless = akFemale->GetFactionRank(ToplessFaction, false) == 1;

	bool IsShowingUnderwear = akFemale->GetFactionRank(ShowingUnderwearFaction, false) == 1;
	bool IsShowingGenitals = akFemale->GetFactionRank(ShowingGenitalsFaction, false) == 1;
	bool IsBottomless = akFemale->GetFactionRank(BottomlessFaction, false) == 1;

	bool IsNude = akFemale->GetFactionRank(NudeFaction, false) == 1;

	if (MinimumRank > CurrentRank) {
		ChangeStrictRank(akFemale, MinimumRank);
	}

	if (CurrentRank == StrictModestyLevel::Modest) {
		if (IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			ThisFemale.ModestyTimer0 += HoursPassed;
			
			if (ThisFemale.ModestyTimer0 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, CurrentRank + 1);
				}
				else {
					ThisFemale.ModestyTimer0 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			if (ThisFemale.ModestyTimer0 > 0) {
				ThisFemale.ModestyTimer0 -= HoursPassed;
			}

			if (ThisFemale.ModestyTimer0 < 0) {
				ThisFemale.ModestyTimer0 = 0;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Reasonable) {
		if (IsShowingUnderwear && IsShowingBra && !IsShowingGenitals && !IsShowingChest) {
			ThisFemale.ModestyTimer1 += HoursPassed;

			if (ThisFemale.ModestyTimer1 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, CurrentRank + 1);
				}
				else {
					ThisFemale.ModestyTimer1 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			ThisFemale.ModestyTimer1 -= HoursPassed;

			if (!Corruption && ThisFemale.ModestyTimer1 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, CurrentRank - 1);
			}
			else if (ThisFemale.ModestyTimer1 < -UpgradeTime) {
				ThisFemale.ModestyTimer1 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Relaxed) {
		if (IsShowingChest && IsShowingUnderwear && !IsTopless && !IsShowingGenitals) {
			ThisFemale.ModestyTimer2 += HoursPassed;

			if (ThisFemale.ModestyTimer2 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, CurrentRank + 1);
				}
				else {
					ThisFemale.ModestyTimer2 = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingBra && !IsShowingChest) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			ThisFemale.ModestyTimer2 -= HoursPassed;

			if (!Corruption && ThisFemale.BottomModestyTimer2 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, CurrentRank - 1);
			}
			else if (ThisFemale.ModestyTimer2 < -UpgradeTime) {
				ThisFemale.ModestyTimer2 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Comfortable) {
		if (IsShowingGenitals && IsShowingChest && !IsTopless && !IsBottomless) {
			ThisFemale.ModestyTimer3 += HoursPassed;

			if (ThisFemale.ModestyTimer3 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, CurrentRank + 1);
				}
				else {
					ThisFemale.ModestyTimer3 = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingChest && !IsTopless) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			ThisFemale.ModestyTimer3 -= HoursPassed;

			if (!Corruption && ThisFemale.ModestyTimer3 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, CurrentRank - 1);
			}
			else if (ThisFemale.ModestyTimer3 < -UpgradeTime) {
				ThisFemale.ModestyTimer3 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Tease) {
		if (IsTopless && IsShowingGenitals && !IsBottomless) {
			ThisFemale.ModestyTimer4 += HoursPassed;

			if (ThisFemale.ModestyTimer4 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, CurrentRank + 1);
				}
				else {
					ThisFemale.ModestyTimer4 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingChest || !IsShowingGenitals) {
			ThisFemale.ModestyTimer4 -= HoursPassed;

			if (!Corruption && ThisFemale.ModestyTimer4 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, CurrentRank - 1);
			}
			else if (ThisFemale.ModestyTimer4 < -UpgradeTime) {
				ThisFemale.ModestyTimer4 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Brazen) {
		if (IsTopless && IsBottomless) {
			ThisFemale.ModestyTimer5 += HoursPassed;

			if (ThisFemale.ModestyTimer5 >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, CurrentRank + 1);
				}
				else {
					ThisFemale.ModestyTimer5 = UpgradeTime;
				}
			}
		}
		else if (!IsShowingGenitals || !IsTopless) {
			ThisFemale.ModestyTimer5 -= HoursPassed;

			if (!Corruption && ThisFemale.ModestyTimer5 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, CurrentRank - 1);
			}
			else if (ThisFemale.ModestyTimer5 < -UpgradeTime) {
				ThisFemale.ModestyTimer5 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Immodest) {
		if (IsNude) {
			ThisFemale.ModestyTimer6 += HoursPassed;
			
			if (AllowShameless && ThisFemale.ModestyTimer6 >= UpgradeTime * 2) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, CurrentRank + 1);
				}
				else {
					ThisFemale.ModestyTimer6 = UpgradeTime * 2;
				}
			}
			else if (ThisFemale.ModestyTimer6 > UpgradeTime) {
				ThisFemale.ModestyTimer6 = UpgradeTime;
			}
		}
		else if (!IsTopless || !IsBottomless) {
			ThisFemale.ModestyTimer6 -= HoursPassed;

			if (!Corruption && ThisFemale.ModestyTimer6 <= -UpgradeTime) {
				ChangeStrictRank(akFemale, CurrentRank - 1);
			}
			else if (ThisFemale.ModestyTimer6 < -UpgradeTime) {
				ThisFemale.ModestyTimer6 = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank >= StrictModestyLevel::Shameless && !AllowShameless) {
		ChangeStrictRank(akFemale, StrictModestyLevel::Immodest);
	}
}

void NPCTopModesty(RE::Actor* akFemale, std::string FemaleName, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless) {
	Log("<C++ NPCModesty> [NPCTopModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{:08X}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	RegisteredFemales& ThisFemale = RegisteredFemaleMap[akFemale->GetFormID()];

	int CurrentTopRank = ThisFemale.CurrentRankTop;
	int MinimumTopRank = ThisFemale.MinimumRankTop;

	bool IsShowingBra = akFemale->GetFactionRank(ShowingBraFaction, false) == 1;
	bool IsShowingChest = akFemale->GetFactionRank(ShowingChestFaction, false) == 1;
	bool IsTopless = akFemale->GetFactionRank(ToplessFaction, false) == 1;

	if (MinimumTopRank > CurrentTopRank) {
		ChangeTopRank(akFemale, MinimumTopRank);
	}

	//Modest (Previously 'Shy')
	if (CurrentTopRank == SimpleModestyLevel::Modest && IsShowingBra && !IsShowingChest) {
		ThisFemale.TopModestyTimer0 += HoursPassed;
	}
	//Comfortable
	else if (CurrentTopRank <= SimpleModestyLevel::Comfortable && IsShowingChest && !IsTopless) {
		ThisFemale.TopModestyTimer1 += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable && IsShowingBra && !IsShowingChest) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentTopRank <= SimpleModestyLevel::Brazen && IsTopless) {
		ThisFemale.TopModestyTimer2 += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen && IsShowingChest && !IsTopless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentTopRank == SimpleModestyLevel::Immodest && IsTopless) {
		ThisFemale.TopModestyTimer3 += HoursPassed;
	}
	else if (CurrentTopRank > SimpleModestyLevel::Immodest) {
		if (!AllowShameless) {
			ChangeTopRank(akFemale, SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {

		if (CurrentTopRank <= SimpleModestyLevel::Modest) {
			ThisFemale.TopModestyTimer0 -= HoursPassed;
			ThisFemale.TopModestyTimer1 -= HoursPassed;
			ThisFemale.TopModestyTimer2 -= HoursPassed;

			if (ThisFemale.TopModestyTimer0 <= 0) {
				ThisFemale.TopModestyTimer0 = 0;
			}

			if (ThisFemale.TopModestyTimer1 <= 0) {
				ThisFemale.TopModestyTimer1 = 0;
			}

			if (ThisFemale.TopModestyTimer2 <= 0) {
				ThisFemale.TopModestyTimer2 = 0;
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Comfortable) {
			ThisFemale.TopModestyTimer1 -= HoursPassed;
			ThisFemale.TopModestyTimer2 -= HoursPassed;

			if (ThisFemale.TopModestyTimer2 <= 0) {
				ThisFemale.TopModestyTimer2 = 0;
			}

			if (ThisFemale.TopModestyTimer1 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, CurrentTopRank - 1);
				}
				else {
					ThisFemale.TopModestyTimer1 = -UpgradeTime;
				}
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Brazen) {
			ThisFemale.TopModestyTimer2 -= HoursPassed;

			if (ThisFemale.TopModestyTimer2 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, CurrentTopRank - 1);
				}
				else {
					ThisFemale.TopModestyTimer2 = -UpgradeTime;
				}
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Immodest) {
			ThisFemale.TopModestyTimer3 -= HoursPassed;

			if (ThisFemale.TopModestyTimer3 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, CurrentTopRank - 1);
				}
				else {
					ThisFemale.TopModestyTimer3 = -UpgradeTime;
				}
			}
		}

		return;
	}

	if (CurrentTopRank == SimpleModestyLevel::Modest) {
		if ((ThisFemale.TopModestyTimer0 + (ThisFemale.TopModestyTimer1 / 2) + (ThisFemale.TopModestyTimer2 / 4)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, CurrentTopRank + 1);
			}
			else {
				if (ThisFemale.TopModestyTimer0 > UpgradeTime) {
					ThisFemale.TopModestyTimer0 = UpgradeTime;
				}

				if (ThisFemale.TopModestyTimer1 > (UpgradeTime * 2)) {
					ThisFemale.TopModestyTimer1 = (UpgradeTime * 2);
				}

				if (ThisFemale.TopModestyTimer2 > (UpgradeTime * 4)) {
					ThisFemale.TopModestyTimer2 = (UpgradeTime * 4);
				}
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable) {
		if ((ThisFemale.TopModestyTimer1 + (ThisFemale.TopModestyTimer2 / 2)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, CurrentTopRank + 1);
			}
			else {
				if (ThisFemale.TopModestyTimer1 > UpgradeTime) {
					ThisFemale.TopModestyTimer1 = UpgradeTime;
				}

				if (ThisFemale.TopModestyTimer2 > (UpgradeTime * 2)) {
					ThisFemale.TopModestyTimer2 = (UpgradeTime * 2);
				}
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen) {
		if (ThisFemale.TopModestyTimer2 >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, CurrentTopRank + 1);
			}
			else {
				ThisFemale.TopModestyTimer2 = UpgradeTime;
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Immodest) {
		if (AllowShameless && ThisFemale.TopModestyTimer3 >= (UpgradeTime * 2)) {
			if (!Blocked) {
				ChangeTopRank(akFemale, CurrentTopRank + 1);
			}
			else {
				ThisFemale.TopModestyTimer3 = (UpgradeTime * 2);
			}
		}
		else if (ThisFemale.TopModestyTimer3 > UpgradeTime) {
			ThisFemale.TopModestyTimer3 = UpgradeTime;
		}
	}
}

void NPCBottomModesty(RE::Actor* akFemale, std::string FemaleName, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless) {
	Log("<C++ NPCModesty> [NPCBottomModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{:08X}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	RegisteredFemales& ThisFemale = RegisteredFemaleMap[akFemale->GetFormID()];

	int CurrentBottomRank = ThisFemale.CurrentRankBottom;
	int MinimumBottomRank = ThisFemale.MinimumRankBottom;

	bool IsShowingUnderwear = akFemale->GetFactionRank(ShowingUnderwearFaction, false) == 1;
	bool IsShowingGenitals = akFemale->GetFactionRank(ShowingGenitalsFaction, false) == 1;
	bool IsBottomless = akFemale->GetFactionRank(BottomlessFaction, false) == 1;

	if (MinimumBottomRank > CurrentBottomRank) {
		ChangeBottomRank(akFemale, MinimumBottomRank);
	}

	//Modest (Previously 'Shy')
	if (CurrentBottomRank == SimpleModestyLevel::Modest && IsShowingUnderwear && !IsShowingGenitals) {
		ThisFemale.BottomModestyTimer0 += HoursPassed;
	}
	//Comfortable
	else if (CurrentBottomRank <= SimpleModestyLevel::Comfortable && IsShowingGenitals && !IsBottomless) {
		ThisFemale.BottomModestyTimer1 += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable && IsShowingUnderwear && !IsShowingGenitals) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentBottomRank <= SimpleModestyLevel::Brazen && IsBottomless) {
		ThisFemale.BottomModestyTimer2 += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen && IsShowingGenitals && !IsBottomless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest && IsBottomless) {
		ThisFemale.BottomModestyTimer3 += HoursPassed;
	}
	else if (CurrentBottomRank > SimpleModestyLevel::Immodest) {
		if (!AllowShameless) {
			ChangeBottomRank(akFemale, SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {

		if (CurrentBottomRank <= SimpleModestyLevel::Modest) {
			ThisFemale.BottomModestyTimer0 -= HoursPassed;
			ThisFemale.BottomModestyTimer1 -= HoursPassed;
			ThisFemale.BottomModestyTimer2 -= HoursPassed;

			if (ThisFemale.BottomModestyTimer0 <= 0) {
				ThisFemale.BottomModestyTimer0 = 0;
			}

			if (ThisFemale.BottomModestyTimer1 <= 0) {
				ThisFemale.BottomModestyTimer1 = 0;
			}

			if (ThisFemale.BottomModestyTimer2 <= 0) {
				ThisFemale.BottomModestyTimer2 = 0;
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Comfortable) {
			ThisFemale.BottomModestyTimer1 -= HoursPassed;
			ThisFemale.BottomModestyTimer2 -= HoursPassed;

			if (ThisFemale.BottomModestyTimer2 <= 0) {
				ThisFemale.BottomModestyTimer2 = 0;
			}

			if (ThisFemale.BottomModestyTimer1 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, CurrentBottomRank - 1);
				}
				else {
					ThisFemale.BottomModestyTimer1 = -UpgradeTime;
				}
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Brazen) {
			ThisFemale.BottomModestyTimer2 -= HoursPassed;

			if (ThisFemale.BottomModestyTimer2 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, CurrentBottomRank - 1);
				}
				else {
					ThisFemale.BottomModestyTimer2 = -UpgradeTime;
				}
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Immodest) {
			ThisFemale.BottomModestyTimer3 -= HoursPassed;

			if (ThisFemale.BottomModestyTimer3 <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, CurrentBottomRank - 1);
				}
				else {
					ThisFemale.BottomModestyTimer3 = -UpgradeTime;
				}
			}
		}

		return;
	}

	if (CurrentBottomRank == SimpleModestyLevel::Modest) {
		if ((ThisFemale.BottomModestyTimer0 + (ThisFemale.BottomModestyTimer1 / 2) + (ThisFemale.BottomModestyTimer2 / 4)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, CurrentBottomRank + 1);
			}
			else {
				if (ThisFemale.BottomModestyTimer0 > UpgradeTime) {
					ThisFemale.BottomModestyTimer0 = UpgradeTime;
				}

				if (ThisFemale.BottomModestyTimer1 > (UpgradeTime * 2)) {
					ThisFemale.BottomModestyTimer1 = (UpgradeTime * 2);
				}

				if (ThisFemale.BottomModestyTimer2 > (UpgradeTime * 4)) {
					ThisFemale.BottomModestyTimer2 = (UpgradeTime * 4);
				}
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable) {
		if ((ThisFemale.BottomModestyTimer1 + (ThisFemale.BottomModestyTimer2 / 2)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, CurrentBottomRank + 1);
			}
			else {
				if (ThisFemale.BottomModestyTimer1 > UpgradeTime) {
					ThisFemale.BottomModestyTimer1 = UpgradeTime;
				}

				if (ThisFemale.BottomModestyTimer2 > (UpgradeTime * 2)) {
					ThisFemale.BottomModestyTimer2 = (UpgradeTime * 2);
				}
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen) {
		if (ThisFemale.BottomModestyTimer2 >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, CurrentBottomRank + 1);
			}
			else {
				ThisFemale.BottomModestyTimer2 = UpgradeTime;
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest) {
		if (AllowShameless && ThisFemale.BottomModestyTimer3 >= (UpgradeTime * 2)) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, CurrentBottomRank + 1);
			}
			else {
				ThisFemale.BottomModestyTimer3 = (UpgradeTime * 2);
			}
		}
		else if (ThisFemale.BottomModestyTimer3 > UpgradeTime) {
			ThisFemale.BottomModestyTimer3 = UpgradeTime;
		}
	}
}

void ProcessNPCModesty(RE::Actor* akFemale, float CurrentGameTime) {
	std::string FemaleName = akFemale->GetName();

	Log("<C++ NPCModesty> [ProcessNPCModesty] Actor is: " + FemaleName + " | FormID: (" + std::format("{0:08X}", akFemale->GetFormID()) + ")", LogType::NPCModesty);

	RegisteredFemales& ThisFemale = RegisteredFemaleMap[akFemale->GetFormID()];

	bool Corruption = ThisFemale.AllowCorruption;
	bool Blocked = ThisFemale.UpgradeBlocked;

	int HoursPassed = static_cast<int>((CurrentGameTime - ThisFemale.LastUpdateTime) / 0.041666);

	Log("<C++ NPCModesty> [ProcessNPCModesty] RAW Hours passed for this actor: " + std::to_string(((CurrentGameTime - ThisFemale.LastUpdateTime) / 0.041666)), LogType::NPCModesty);

	if (HoursPassed < 1) 
	{
		Log("<C++ NPCModesty> [ProcessNPCModesty] Less than an hour has passed for this actor. Skipping update...", LogType::NPCModesty);
		return;
	}

	int UpgradeTime = Configuration::ImmodestyTimeNeeded * 24;
	
	bool AllowShameless = ThisFemale.AllowShameless;
	
	bool StrictRules = ThisFemale.StrictRules;

	if (StrictRules) {
		StrictNPCModesty(akFemale, FemaleName, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
	}
	else {
		NPCTopModesty(akFemale, FemaleName, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
		NPCBottomModesty(akFemale, FemaleName, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
	}

	ThisFemale.LastUpdateTime = CurrentGameTime;
}

void ProcessAllNPCModesty(RE::StaticFunctionTag*) {
	if (InstalledMods::DFFMA && Configuration::DynamicModestyEnabled) {
		float CurrentGameTime = GameCalendar->GetCurrentGameTime();

		CleanFemaleList();

		RE::Actor* FemaleActor;
		for (auto& [ID, Female] : RegisteredFemaleMap) {
			FemaleActor = RE::TESForm::LookupByID<RE::Actor>(ID);

			Log("<C++ NPCModesty> [ProcessAllNPCModesty] Female Map ID is: " + std::format("{0:08X}", ID), LogType::NPCModesty, LoggingLevel::info);
			Log("<C++ NPCModesty> [ProcessAllNPCModesty] Female Registered ID is: " + std::format("{0:08X}", Female.FemaleFormID), LogType::NPCModesty, LoggingLevel::info);

			if (FemaleActor == nullptr) {
				Log("<C++ NPCModesty> [ProcessAllNPCModesty] CRITICAL ERROR - Female Actor is NULL despite Female List being cleaned of Null Actors!!! Something is terribly wrong!", LogType::NPCModesty, LoggingLevel::critical);
				continue;
			}

			ProcessNPCModesty(FemaleActor, CurrentGameTime);
		}
	}
}