#include "NPCData.h"
#include "Config.h"
#include "Core.h"
#include "Logger.h"

void ChangeStrictRank(RE::Actor* akFemale, int FemaleID, int Rank) {
	SetActorFactionRank(akFemale, ModestyFaction, HandleInteger(Rank));
	RegisteredFemales::CurrentRankStrict[FemaleID] = HandleInteger(Rank);

	RegisteredFemales::ModestyTimer0[FemaleID] = 0;
	RegisteredFemales::ModestyTimer1[FemaleID] = 0;
	RegisteredFemales::ModestyTimer2[FemaleID] = 0;
	RegisteredFemales::ModestyTimer3[FemaleID] = 0;
	RegisteredFemales::ModestyTimer4[FemaleID] = 0;
	RegisteredFemales::ModestyTimer5[FemaleID] = 0;
	RegisteredFemales::ModestyTimer6[FemaleID] = 0;
}

void ChangeTopRank(RE::Actor* akFemale, int FemaleID, int Rank) {
	SetActorFactionRank(akFemale, TopModestyFaction, HandleInteger(Rank));
	RegisteredFemales::CurrentRankTop[FemaleID] = HandleInteger(Rank);

	RegisteredFemales::TopModestyTimer0[FemaleID] = 0;
	RegisteredFemales::TopModestyTimer1[FemaleID] = 0;
	RegisteredFemales::TopModestyTimer2[FemaleID] = 0;
	RegisteredFemales::TopModestyTimer3[FemaleID] = 0;
}

void ChangeBottomRank(RE::Actor* akFemale, int FemaleID, int Rank) {
	SetActorFactionRank(akFemale, BottomModestyFaction, HandleInteger(Rank));
	RegisteredFemales::CurrentRankBottom[FemaleID] = HandleInteger(Rank);

	RegisteredFemales::BottomModestyTimer0[FemaleID] = 0;
	RegisteredFemales::BottomModestyTimer1[FemaleID] = 0;
	RegisteredFemales::BottomModestyTimer2[FemaleID] = 0;
	RegisteredFemales::BottomModestyTimer3[FemaleID] = 0;
}

void StrictNPCModesty(RE::Actor* akFemale, std::string FemaleName, int FemaleID, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless) {
	Log("<C++ NPCModesty> [StrictNPCModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{:08X}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	int CurrentRank = RegisteredFemales::CurrentRankStrict[FemaleID];
	int MinimumRank = RegisteredFemales::MinimumRankStrict[FemaleID];

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
			RegisteredFemales::ModestyTimer0[FemaleID] += HoursPassed;
			
			if (RegisteredFemales::ModestyTimer0[FemaleID] >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					RegisteredFemales::ModestyTimer0[FemaleID] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			if (RegisteredFemales::ModestyTimer0[FemaleID] > 0) {
				RegisteredFemales::ModestyTimer0[FemaleID] -= HoursPassed;
			}

			if (RegisteredFemales::ModestyTimer0[FemaleID] < 0) {
				RegisteredFemales::ModestyTimer0[FemaleID] = 0;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Reasonable) {
		if (IsShowingUnderwear && IsShowingBra && !IsShowingGenitals && !IsShowingChest) {
			RegisteredFemales::ModestyTimer1[FemaleID] += HoursPassed;

			if (RegisteredFemales::ModestyTimer1[FemaleID] >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					RegisteredFemales::ModestyTimer1[FemaleID] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingBra && !IsShowingChest && !IsShowingUnderwear && !IsShowingGenitals) {
			RegisteredFemales::ModestyTimer1[FemaleID] -= HoursPassed;

			if (!Corruption && RegisteredFemales::ModestyTimer1[FemaleID] <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (RegisteredFemales::ModestyTimer1[FemaleID] < -UpgradeTime) {
				RegisteredFemales::ModestyTimer1[FemaleID] = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Relaxed) {
		if (IsShowingChest && IsShowingUnderwear && !IsTopless && !IsShowingGenitals) {
			RegisteredFemales::ModestyTimer2[FemaleID] += HoursPassed;

			if (RegisteredFemales::ModestyTimer2[FemaleID] >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					RegisteredFemales::ModestyTimer2[FemaleID] = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingBra && !IsShowingChest) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			RegisteredFemales::ModestyTimer2[FemaleID] -= HoursPassed;

			if (!Corruption && RegisteredFemales::ModestyTimer2[FemaleID] <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (RegisteredFemales::ModestyTimer2[FemaleID] < -UpgradeTime) {
				RegisteredFemales::ModestyTimer2[FemaleID] = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Comfortable) {
		if (IsShowingGenitals && IsShowingChest && !IsTopless && !IsBottomless) {
			RegisteredFemales::ModestyTimer3[FemaleID] += HoursPassed;

			if (RegisteredFemales::ModestyTimer3[FemaleID] >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					RegisteredFemales::ModestyTimer3[FemaleID] = UpgradeTime;
				}
			}
		}
		else if ((!IsShowingChest && !IsTopless) || (!IsShowingUnderwear && !IsShowingGenitals)) {
			RegisteredFemales::ModestyTimer3[FemaleID] -= HoursPassed;

			if (!Corruption && RegisteredFemales::ModestyTimer3[FemaleID] <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (RegisteredFemales::ModestyTimer3[FemaleID] < -UpgradeTime) {
				RegisteredFemales::ModestyTimer3[FemaleID] = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Tease) {
		if (IsTopless && IsShowingGenitals && !IsBottomless) {
			RegisteredFemales::ModestyTimer4[FemaleID] += HoursPassed;

			if (RegisteredFemales::ModestyTimer4[FemaleID] >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					RegisteredFemales::ModestyTimer4[FemaleID] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingChest || !IsShowingGenitals) {
			RegisteredFemales::ModestyTimer4[FemaleID] -= HoursPassed;

			if (!Corruption && RegisteredFemales::ModestyTimer4[FemaleID] <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (RegisteredFemales::ModestyTimer4[FemaleID] < -UpgradeTime) {
				RegisteredFemales::ModestyTimer4[FemaleID] = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Brazen) {
		if (IsTopless && IsBottomless) {
			RegisteredFemales::ModestyTimer5[FemaleID] += HoursPassed;

			if (RegisteredFemales::ModestyTimer5[FemaleID] >= UpgradeTime) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					RegisteredFemales::ModestyTimer5[FemaleID] = UpgradeTime;
				}
			}
		}
		else if (!IsShowingGenitals || !IsTopless) {
			RegisteredFemales::ModestyTimer5[FemaleID] -= HoursPassed;

			if (!Corruption && RegisteredFemales::ModestyTimer5[FemaleID] <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (RegisteredFemales::ModestyTimer5[FemaleID] < -UpgradeTime) {
				RegisteredFemales::ModestyTimer5[FemaleID] = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank == StrictModestyLevel::Immodest) {
		if (IsNude) {
			RegisteredFemales::ModestyTimer6[FemaleID] += HoursPassed;
			
			if (AllowShameless && RegisteredFemales::ModestyTimer6[FemaleID] >= UpgradeTime * 2) {
				if (!Blocked) {
					ChangeStrictRank(akFemale, FemaleID, CurrentRank + 1);
				}
				else {
					RegisteredFemales::ModestyTimer6[FemaleID] = UpgradeTime * 2;
				}
			}
			else if (RegisteredFemales::ModestyTimer6[FemaleID] > UpgradeTime) {
				RegisteredFemales::ModestyTimer6[FemaleID] = UpgradeTime;
			}
		}
		else if (!IsTopless || !IsBottomless) {
			RegisteredFemales::ModestyTimer6[FemaleID] -= HoursPassed;

			if (!Corruption && RegisteredFemales::ModestyTimer6[FemaleID] <= -UpgradeTime) {
				ChangeStrictRank(akFemale, FemaleID, CurrentRank - 1);
			}
			else if (RegisteredFemales::ModestyTimer6[FemaleID] < -UpgradeTime) {
				RegisteredFemales::ModestyTimer6[FemaleID] = -UpgradeTime;
			}
		}
	}
	else if (CurrentRank >= StrictModestyLevel::Shameless && !AllowShameless) {
		ChangeStrictRank(akFemale, FemaleID, StrictModestyLevel::Immodest);
	}
}

void NPCTopModesty(RE::Actor* akFemale, std::string FemaleName, int FemaleID, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless) {
	Log("<C++ NPCModesty> [NPCTopModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{:08X}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	int CurrentTopRank = RegisteredFemales::CurrentRankTop[FemaleID];
	int MinimumTopRank = RegisteredFemales::MinimumRankTop[FemaleID];

	bool IsShowingBra = akFemale->GetFactionRank(ShowingBraFaction, false) == 1;
	bool IsShowingChest = akFemale->GetFactionRank(ShowingChestFaction, false) == 1;
	bool IsTopless = akFemale->GetFactionRank(ToplessFaction, false) == 1;

	if (MinimumTopRank > CurrentTopRank) {
		ChangeTopRank(akFemale, FemaleID, MinimumTopRank);
	}

	//Modest (Previously 'Shy')
	if (CurrentTopRank == SimpleModestyLevel::Modest && IsShowingBra && !IsShowingChest) {
		RegisteredFemales::TopModestyTimer0[FemaleID] += HoursPassed;
	}
	//Comfortable
	else if (CurrentTopRank <= SimpleModestyLevel::Comfortable && IsShowingChest && !IsTopless) {
		RegisteredFemales::TopModestyTimer1[FemaleID] += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable && IsShowingBra && !IsShowingChest) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentTopRank <= SimpleModestyLevel::Brazen && IsTopless) {
		RegisteredFemales::TopModestyTimer2[FemaleID] += HoursPassed;
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen && IsShowingChest && !IsTopless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentTopRank == SimpleModestyLevel::Immodest && IsTopless) {
		RegisteredFemales::TopModestyTimer3[FemaleID] += HoursPassed;
	}
	else if (CurrentTopRank > SimpleModestyLevel::Immodest) {
		if (!AllowShameless) {
			ChangeTopRank(akFemale, FemaleID, SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {

		if (CurrentTopRank <= SimpleModestyLevel::Modest) {
			RegisteredFemales::TopModestyTimer0[FemaleID] -= HoursPassed;
			RegisteredFemales::TopModestyTimer1[FemaleID] -= HoursPassed;
			RegisteredFemales::TopModestyTimer2[FemaleID] -= HoursPassed;

			if (RegisteredFemales::TopModestyTimer0[FemaleID] <= 0) {
				RegisteredFemales::TopModestyTimer0[FemaleID] = 0;
			}

			if (RegisteredFemales::TopModestyTimer1[FemaleID] <= 0) {
				RegisteredFemales::TopModestyTimer1[FemaleID] = 0;
			}

			if (RegisteredFemales::TopModestyTimer2[FemaleID] <= 0) {
				RegisteredFemales::TopModestyTimer2[FemaleID] = 0;
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Comfortable) {
			RegisteredFemales::TopModestyTimer1[FemaleID] -= HoursPassed;
			RegisteredFemales::TopModestyTimer2[FemaleID] -= HoursPassed;

			if (RegisteredFemales::TopModestyTimer2[FemaleID] <= 0) {
				RegisteredFemales::TopModestyTimer2[FemaleID] = 0;
			}

			if (RegisteredFemales::TopModestyTimer1[FemaleID] <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, FemaleID, CurrentTopRank - 1);
				}
				else {
					RegisteredFemales::TopModestyTimer1[FemaleID] = -UpgradeTime;
				}
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Brazen) {
			RegisteredFemales::TopModestyTimer2[FemaleID] -= HoursPassed;

			if (RegisteredFemales::TopModestyTimer2[FemaleID] <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, FemaleID, CurrentTopRank - 1);
				}
				else {
					RegisteredFemales::TopModestyTimer2[FemaleID] = -UpgradeTime;
				}
			}
		}
		else if (CurrentTopRank == SimpleModestyLevel::Immodest) {
			RegisteredFemales::TopModestyTimer3[FemaleID] -= HoursPassed;

			if (RegisteredFemales::TopModestyTimer3[FemaleID] <= -UpgradeTime) {
				if (!Corruption) {
					ChangeTopRank(akFemale, FemaleID, CurrentTopRank - 1);
				}
				else {
					RegisteredFemales::TopModestyTimer3[FemaleID] = -UpgradeTime;
				}
			}
		}

		return;
	}

	if (CurrentTopRank == SimpleModestyLevel::Modest) {
		if ((RegisteredFemales::TopModestyTimer0[FemaleID] + (RegisteredFemales::TopModestyTimer1[FemaleID] / 2) + (RegisteredFemales::TopModestyTimer2[FemaleID] / 4)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				if (RegisteredFemales::TopModestyTimer0[FemaleID] > UpgradeTime) {
					RegisteredFemales::TopModestyTimer0[FemaleID] = UpgradeTime;
				}

				if (RegisteredFemales::TopModestyTimer1[FemaleID] > (UpgradeTime * 2)) {
					RegisteredFemales::TopModestyTimer1[FemaleID] = (UpgradeTime * 2);
				}

				if (RegisteredFemales::TopModestyTimer2[FemaleID] > (UpgradeTime * 4)) {
					RegisteredFemales::TopModestyTimer2[FemaleID] = (UpgradeTime * 4);
				}
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Comfortable) {
		if ((RegisteredFemales::TopModestyTimer1[FemaleID] + (RegisteredFemales::TopModestyTimer2[FemaleID] / 2)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				if (RegisteredFemales::TopModestyTimer1[FemaleID] > UpgradeTime) {
					RegisteredFemales::TopModestyTimer1[FemaleID] = UpgradeTime;
				}

				if (RegisteredFemales::TopModestyTimer2[FemaleID] > (UpgradeTime * 2)) {
					RegisteredFemales::TopModestyTimer2[FemaleID] = (UpgradeTime * 2);
				}
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Brazen) {
		if (RegisteredFemales::TopModestyTimer2[FemaleID] >= UpgradeTime) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				RegisteredFemales::TopModestyTimer2[FemaleID] = UpgradeTime;
			}
		}
	}
	else if (CurrentTopRank == SimpleModestyLevel::Immodest) {
		if (AllowShameless && RegisteredFemales::TopModestyTimer3[FemaleID] >= (UpgradeTime * 2)) {
			if (!Blocked) {
				ChangeTopRank(akFemale, FemaleID, CurrentTopRank + 1);
			}
			else {
				RegisteredFemales::TopModestyTimer3[FemaleID] = (UpgradeTime * 2);
			}
		}
		else if (RegisteredFemales::TopModestyTimer3[FemaleID] > UpgradeTime) {
			RegisteredFemales::TopModestyTimer3[FemaleID] = UpgradeTime;
		}
	}
}

void NPCBottomModesty(RE::Actor* akFemale, std::string FemaleName, int FemaleID, int UpgradeTime, int HoursPassed, bool Corruption, bool Blocked, bool AllowShameless) {
	Log("<C++ NPCModesty> [NPCBottomModesty] Analysis Started for " + FemaleName + " FormID: (" + std::format("{:08X}", akFemale->GetFormID()) + ")", LogType::NPCModesty);
	
	int CurrentBottomRank = RegisteredFemales::CurrentRankBottom[FemaleID];
	int MinimumBottomRank = RegisteredFemales::MinimumRankBottom[FemaleID];

	bool IsShowingUnderwear = akFemale->GetFactionRank(ShowingUnderwearFaction, false) == 1;
	bool IsShowingGenitals = akFemale->GetFactionRank(ShowingGenitalsFaction, false) == 1;
	bool IsBottomless = akFemale->GetFactionRank(BottomlessFaction, false) == 1;

	if (MinimumBottomRank > CurrentBottomRank) {
		ChangeBottomRank(akFemale, FemaleID, MinimumBottomRank);
	}

	//Modest (Previously 'Shy')
	if (CurrentBottomRank == SimpleModestyLevel::Modest && IsShowingUnderwear && !IsShowingGenitals) {
		RegisteredFemales::BottomModestyTimer0[FemaleID] += HoursPassed;
	}
	//Comfortable
	else if (CurrentBottomRank <= SimpleModestyLevel::Comfortable && IsShowingGenitals && !IsBottomless) {
		RegisteredFemales::BottomModestyTimer1[FemaleID] += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable && IsShowingUnderwear && !IsShowingGenitals) {
		//Do Nothing
	}
	//Brazen (Previously 'Bold')
	else if (CurrentBottomRank <= SimpleModestyLevel::Brazen && IsBottomless) {
		RegisteredFemales::BottomModestyTimer2[FemaleID] += HoursPassed;
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen && IsShowingGenitals && !IsBottomless) {
		//Do Nothing
	}
	//Immodest (Previously 'Shameless')
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest && IsBottomless) {
		RegisteredFemales::BottomModestyTimer3[FemaleID] += HoursPassed;
	}
	else if (CurrentBottomRank > SimpleModestyLevel::Immodest) {
		if (!AllowShameless) {
			ChangeBottomRank(akFemale, FemaleID, SimpleModestyLevel::Immodest);
		}
		return;
	}
	else {

		if (CurrentBottomRank <= SimpleModestyLevel::Modest) {
			RegisteredFemales::BottomModestyTimer0[FemaleID] -= HoursPassed;
			RegisteredFemales::BottomModestyTimer1[FemaleID] -= HoursPassed;
			RegisteredFemales::BottomModestyTimer2[FemaleID] -= HoursPassed;

			if (RegisteredFemales::BottomModestyTimer0[FemaleID] <= 0) {
				RegisteredFemales::BottomModestyTimer0[FemaleID] = 0;
			}

			if (RegisteredFemales::BottomModestyTimer1[FemaleID] <= 0) {
				RegisteredFemales::BottomModestyTimer1[FemaleID] = 0;
			}

			if (RegisteredFemales::BottomModestyTimer2[FemaleID] <= 0) {
				RegisteredFemales::BottomModestyTimer2[FemaleID] = 0;
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Comfortable) {
			RegisteredFemales::BottomModestyTimer1[FemaleID] -= HoursPassed;
			RegisteredFemales::BottomModestyTimer2[FemaleID] -= HoursPassed;

			if (RegisteredFemales::BottomModestyTimer2[FemaleID] <= 0) {
				RegisteredFemales::BottomModestyTimer2[FemaleID] = 0;
			}

			if (RegisteredFemales::BottomModestyTimer1[FemaleID] <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank - 1);
				}
				else {
					RegisteredFemales::BottomModestyTimer1[FemaleID] = -UpgradeTime;
				}
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Brazen) {
			RegisteredFemales::BottomModestyTimer2[FemaleID] -= HoursPassed;

			if (RegisteredFemales::BottomModestyTimer2[FemaleID] <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank - 1);
				}
				else {
					RegisteredFemales::BottomModestyTimer2[FemaleID] = -UpgradeTime;
				}
			}
		}
		else if (CurrentBottomRank == SimpleModestyLevel::Immodest) {
			RegisteredFemales::BottomModestyTimer3[FemaleID] -= HoursPassed;

			if (RegisteredFemales::BottomModestyTimer3[FemaleID] <= -UpgradeTime) {
				if (!Corruption) {
					ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank - 1);
				}
				else {
					RegisteredFemales::BottomModestyTimer3[FemaleID] = -UpgradeTime;
				}
			}
		}

		return;
	}

	if (CurrentBottomRank == SimpleModestyLevel::Modest) {
		if ((RegisteredFemales::BottomModestyTimer0[FemaleID] + (RegisteredFemales::BottomModestyTimer1[FemaleID] / 2) + (RegisteredFemales::BottomModestyTimer2[FemaleID] / 4)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				if (RegisteredFemales::BottomModestyTimer0[FemaleID] > UpgradeTime) {
					RegisteredFemales::BottomModestyTimer0[FemaleID] = UpgradeTime;
				}

				if (RegisteredFemales::BottomModestyTimer1[FemaleID] > (UpgradeTime * 2)) {
					RegisteredFemales::BottomModestyTimer1[FemaleID] = (UpgradeTime * 2);
				}

				if (RegisteredFemales::BottomModestyTimer2[FemaleID] > (UpgradeTime * 4)) {
					RegisteredFemales::BottomModestyTimer2[FemaleID] = (UpgradeTime * 4);
				}
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Comfortable) {
		if ((RegisteredFemales::BottomModestyTimer1[FemaleID] + (RegisteredFemales::BottomModestyTimer2[FemaleID] / 2)) >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				if (RegisteredFemales::BottomModestyTimer1[FemaleID] > UpgradeTime) {
					RegisteredFemales::BottomModestyTimer1[FemaleID] = UpgradeTime;
				}

				if (RegisteredFemales::BottomModestyTimer2[FemaleID] > (UpgradeTime * 2)) {
					RegisteredFemales::BottomModestyTimer2[FemaleID] = (UpgradeTime * 2);
				}
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Brazen) {
		if (RegisteredFemales::BottomModestyTimer2[FemaleID] >= UpgradeTime) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				RegisteredFemales::BottomModestyTimer2[FemaleID] = UpgradeTime;
			}
		}
	}
	else if (CurrentBottomRank == SimpleModestyLevel::Immodest) {
		if (AllowShameless && RegisteredFemales::BottomModestyTimer3[FemaleID] >= (UpgradeTime * 2)) {
			if (!Blocked) {
				ChangeBottomRank(akFemale, FemaleID, CurrentBottomRank + 1);
			}
			else {
				RegisteredFemales::BottomModestyTimer3[FemaleID] = (UpgradeTime * 2);
			}
		}
		else if (RegisteredFemales::BottomModestyTimer3[FemaleID] > UpgradeTime) {
			RegisteredFemales::BottomModestyTimer3[FemaleID] = UpgradeTime;
		}
	}
}

void ProcessNPCModesty(RE::Actor* akFemale, int FemaleID, float CurrentGameTime) {
	
	std::string FemaleName = akFemale->GetName();

	Log("<C++ NPCModesty> [ProcessNPCModesty] Actor is: " + FemaleName + " | FormID: (" + std::format("{0:08X}", akFemale->GetFormID()) + ")" + " | Internal ID: " + std::to_string(FemaleID), LogType::NPCModesty);

	bool Corruption = RegisteredFemales::AllowCorruption[FemaleID];
	bool Blocked = RegisteredFemales::UpgradeBlocked[FemaleID];

	int HoursPassed = static_cast<int>((CurrentGameTime - RegisteredFemales::LastUpdateTime[FemaleID]) / 0.041666);

	Log("<C++ NPCModesty> [ProcessNPCModesty] RAW Hours passed for this actor: " + std::to_string(((CurrentGameTime - RegisteredFemales::LastUpdateTime[FemaleID]) / 0.041666)), LogType::NPCModesty);

	if (HoursPassed < 1) {
		Log("<C++ NPCModesty> [ProcessNPCModesty] Less than an hour has passed for this actor. Skipping update...", LogType::NPCModesty);
		return;
	}

	int UpgradeTime = Configuration::ImmodestyTimeNeeded * 24;
	
	bool AllowShameless = RegisteredFemales::AllowShameless[FemaleID];
	
	bool StrictRules = RegisteredFemales::StrictRules[FemaleID];

	if (StrictRules) {
		StrictNPCModesty(akFemale, FemaleName, FemaleID, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
	}
	else {
		NPCTopModesty(akFemale, FemaleName, FemaleID, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
		NPCBottomModesty(akFemale, FemaleName, FemaleID, UpgradeTime, HoursPassed, Corruption, Blocked, AllowShameless);
	}

	RegisteredFemales::LastUpdateTime[FemaleID] = CurrentGameTime;
}