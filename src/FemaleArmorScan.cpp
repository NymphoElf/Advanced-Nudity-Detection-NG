#include "PlayerArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "Logger.h"
#include "Player.h"

namespace FemaleArmorScan {
	void ResetFlashingFactions() {
		SetPlayerFactionRank(FlashingChestCurtainFaction, 0);
		SetPlayerFactionRank(FlashingPelvicCurtainFaction, 0);
		SetPlayerFactionRank(FlashingAssCurtainFaction, 0);

		SetPlayerFactionRank(FlashingTopArmorFaction, 0);
		SetPlayerFactionRank(FlashingBottomArmorFaction, 0);
		SetPlayerFactionRank(FlashingBraFaction, 0);
		SetPlayerFactionRank(FlashingUnderwearFaction, 0);
		SetPlayerFactionRank(FlashingCStringFaction, 0);
		SetPlayerFactionRank(FlashingHotpantsFaction, 0);
		SetPlayerFactionRank(FlashingShowgirlSkirtFaction, 0);
	}
	
	bool CurtainCheck(int Type, bool IsTransparent, int Level) {
		int Roll = 0;
		int Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Chest) {
			TypeString = "Chest";
			Roll = ChestCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsLow];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsLow];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOdds];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOdds];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsHigh];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsHigh];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsExtreme];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsExtreme];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsUltra];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsUltra];
				}
			}
		}
		else if (Type == FlashRiskType::Pelvic) {
			TypeString = "Pelvic";
			Roll = PelvicCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsLow];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsLow];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOdds];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOdds];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsHigh];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsHigh];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsExtreme];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsExtreme];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsUltra];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsUltra];
				}
			}
		}
		else if (Type == FlashRiskType::Ass) {
			TypeString = "Ass";
			Roll = AssCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsLow];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsLow];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOdds];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOdds];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsHigh];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsHigh];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsExtreme];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsExtreme];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsUltra];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsUltra];
				}
			}
		}

		Log("<C++ FemaleArmorScan> [CurtainCheck] Roll = " + std::to_string(Roll), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CurtainCheck] Odds = " + std::to_string(Odds), LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CurtainCheck] Type = " + TypeString, LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CurtainCheck] Is Transparent = " + BoolToString(IsTransparent), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CurtainCheck] Risk Level = " + FlashRiskToString(Level), LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), LogType::PlayerArmorScan);

		bool Result = (Roll > Odds);

		switch (Type) {
			case FlashRiskType::Chest:
				if (IsWearingChestCurtain) {
					SetPlayerFactionRank(FlashingChestCurtainFaction, !Result);
				}
				else {
					SetPlayerFactionRank(FlashingChestCurtainFaction, 0);
				}
				break;
			case FlashRiskType::Pelvic:
				if (IsWearingPelvicCurtain) {
					SetPlayerFactionRank(FlashingPelvicCurtainFaction, !Result);
				}
				else {
					SetPlayerFactionRank(FlashingPelvicCurtainFaction, 0);
				}
				break;
			case FlashRiskType::Ass:
				if (IsWearingAssCurtain) {
					SetPlayerFactionRank(FlashingAssCurtainFaction, !Result);
				}
				else {
					SetPlayerFactionRank(FlashingAssCurtainFaction, 0);
				}
				break;
			default:
				break;
		}

		return Result;
	}

	bool TransparentItemCheck(int Type, int Level) {
		int Roll = 0;
		int Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Top) {
			TypeString = "Top";
			Roll = TopTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentTopArmorOdds_Low];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentTopArmorOdds];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentTopArmorOdds_High];
			}
		}
		else if (Type == FlashRiskType::Bottom) {
			TypeString = "Bottom";
			Roll = BottomTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentBottomArmorOdds_Low];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentBottomArmorOdds];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentBottomArmorOdds_High];
			}
		}
		else if (Type == FlashRiskType::Bra) {
			TypeString = "Bra";
			Roll = BraTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentBraOdds_Low];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentBraOdds];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentBraOdds_High];
			}
		}
		else if (Type == FlashRiskType::Underwear || Type == FlashRiskType::Thong) {
			if (Type == FlashRiskType::Underwear) {
				TypeString = "Underwear";
			}
			else {
				TypeString = "Thong";
			}

			Roll = UnderwearTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentUnderwearOdds_Low];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentUnderwearOdds];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentUnderwearOdds_High];
			}
		}
		else if (Type == FlashRiskType::Hotpants) {
			TypeString = "Hotpants";
			Roll = HotpantsTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentHotpantsOdds_Low];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentHotpantsOdds];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentHotpantsOdds_High];
			}
		}
		else if (Type == FlashRiskType::Showgirl) {
			TypeString = "Showgirl";
			Roll = ShowgirlTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentShowgirlOdds_Low];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentShowgirlOdds];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentShowgirlOdds_High];
			}
		}

		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Roll = " + std::to_string(Roll), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Odds = " + std::to_string(Odds), LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Type = " + TypeString, LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [TransparentItemCheck] RiskLevel = " + FlashRiskToString(Level), LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), LogType::PlayerArmorScan);

		bool Result = (Roll > Odds);

		switch (Type) {
			case FlashRiskType::Top:
				SetPlayerFactionRank(FlashingTopArmorFaction, !Result);
				break;
			case FlashRiskType::Bottom:
				SetPlayerFactionRank(FlashingBottomArmorFaction, !Result);
				break;
			case FlashRiskType::Bra:
				SetPlayerFactionRank(FlashingBraFaction, !Result);
				break;
			case FlashRiskType::Underwear:
				SetPlayerFactionRank(FlashingUnderwearFaction, !Result);
				break;
			case FlashRiskType::Thong:
				SetPlayerFactionRank(FlashingUnderwearFaction, !Result);
				break;
			case FlashRiskType::Hotpants:
				SetPlayerFactionRank(FlashingHotpantsFaction, !Result);
				break;
			case FlashRiskType::Showgirl:
				SetPlayerFactionRank(FlashingShowgirlSkirtFaction, !Result);
				break;
			default:
				break;
		}

		return Result;
	}

	bool CStringCheck(bool IsTransparent, int Level) {
		int Odds = 0;

		if (IsTransparent == false) {
			Odds = Configuration::FlashingOdds[CStringOdds];
		}
		else if (Level == FlashRiskLevel::Low) {
			Odds = Configuration::FlashingOdds[TransparentCStringOdds_Low];
		}
		else if (Level == FlashRiskLevel::Normal) {
			Odds = Configuration::FlashingOdds[TransparentCStringOdds];
		}
		else if (Level == FlashRiskLevel::High) {
			Odds = Configuration::FlashingOdds[TransparentCStringOdds_High];
		}

		Log("<C++ FemaleArmorScan> [CStringCheck] Roll = " + std::to_string(CStringRoll), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CStringCheck] Odds = " + std::to_string(Odds), LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CStringCheck] IsTransparent = " + BoolToString(IsTransparent), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CStringCheck] RiskLevel = " + FlashRiskToString(Level), LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CStringCheck] Function Return Value: Is Covering? " + BoolToString(CStringRoll > Odds), LogType::PlayerArmorScan);

		bool Result = (CStringRoll > Odds);

		SetPlayerFactionRank(FlashingCStringFaction, !Result);

		return Result;
	}

	void AnalyzeBra(bool HasBra, bool HasBraT, int BraRiskLevel, bool HasBraNoCover) {
		if (HasBra) {
			PlayerCoverage::BraCover = false;
			PlayerCoverage::ChestCover = true;
		}
		else if (HasBraT) {
			PlayerCoverage::BraCover = false;
			PlayerCoverage::ChestCover = TransparentItemCheck(FlashRiskType::Bra, BraRiskLevel);
		}
		else if (HasBraNoCover) {
			PlayerCoverage::BraCover = false;
			PlayerCoverage::ChestCover = false;
		}
		else {
			PlayerCoverage::BraCover = true;
			PlayerCoverage::ChestCover = false;
		}
	}

	void AnalyzeTop
	(
		bool HasChestCurtain, bool HasChestCurtainT, int ChestRiskLevel, 
		bool HasArmorTop, bool HasArmorTopT, int TopRiskLevel, 
		bool HasBra, bool HasBraT, int BraRiskLevel, bool HasBraNoCover
	) {
		if (HasChestCurtain || HasChestCurtainT) {
			PlayerCoverage::ChestCurtainCoverage = CurtainCheck(FlashRiskType::Chest, HasChestCurtainT, ChestRiskLevel);
		}
		else {
			PlayerCoverage::ChestCurtainCoverage = false;
		}

		if (HasArmorTop) {
			PlayerCoverage::BraCover = true;
			PlayerCoverage::ChestCover = true;
		}
		else if (HasArmorTopT) {
			bool TopCovering = TransparentItemCheck(FlashRiskType::Top, TopRiskLevel);

			if (TopCovering) {
				PlayerCoverage::BraCover = true;
				PlayerCoverage::ChestCover = true;
			}
			else {
				AnalyzeBra(HasBra, HasBraT, BraRiskLevel, HasBraNoCover);
			}
		}
		else {
			AnalyzeBra(HasBra, HasBraT, BraRiskLevel, HasBraNoCover);
		}
	}

	void AnalyzeCString(bool HasCStringT, int CStringRiskLevel) {
		PlayerCoverage::GenitalCover = CStringCheck(HasCStringT, CStringRiskLevel);
		PlayerCoverage::UnderwearCover = !PlayerCoverage::GenitalCover;
	}

	void AnalyzeUnderwear
	(
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, int CStringRiskLevel
	) {
		if (HasUnderwear) {
			PlayerCoverage::UnderwearCover = false;
			PlayerCoverage::AssCover = true;
			PlayerCoverage::GenitalCover = true;
		}
		else if (HasUnderwearT) {
			PlayerCoverage::UnderwearCover = false;
			PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
			PlayerCoverage::GenitalCover = PlayerCoverage::AssCover;
		}
		else if (HasThong) {
			PlayerCoverage::UnderwearCover = false;
			PlayerCoverage::AssCover = false;
			PlayerCoverage::GenitalCover = true;
		}
		else if (HasThongT) {
			PlayerCoverage::UnderwearCover = false;
			PlayerCoverage::AssCover = false;
			PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
		}
		else if (HasCString || HasCStringT) {
			PlayerCoverage::AssCover = false;
			AnalyzeCString(HasCStringT, CStringRiskLevel);
		}
		else if (HasUnderwearNoCover || HasThongNoCover) {
			PlayerCoverage::UnderwearCover = false;
			PlayerCoverage::AssCover = false;
			PlayerCoverage::GenitalCover = false;
		}
		else {
			PlayerCoverage::UnderwearCover = true;
			PlayerCoverage::AssCover = false;
			PlayerCoverage::GenitalCover = false;
		}
	}

	void SubAnalyzeBottom
	(
		bool HasHotpants, bool HasHotpantsT, int HotpantsRiskLevel,
		bool HasShowgirl, bool HasShowgirlT, int ShowgirlRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, int CStringRiskLevel
	) {
		if (HasHotpants && HasShowgirl) {
			PlayerCoverage::AssCover = true;
			PlayerCoverage::GenitalCover = true;
			PlayerCoverage::UnderwearCover = true;
		}
		else if (HasHotpants && HasShowgirlT) {
			PlayerCoverage::GenitalCover = true;

			if (HasUnderwear) {
				PlayerCoverage::AssCover = true;
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
			}
			else if (HasUnderwearT) {
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
				if (PlayerCoverage::UnderwearCover) {
					PlayerCoverage::AssCover = true;
				}
				else {
					PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
			}
			else if (HasUnderwearNoCover) {
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
				PlayerCoverage::AssCover = PlayerCoverage::UnderwearCover;
			}
			else {
				PlayerCoverage::UnderwearCover = true;
				PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
			}
		}
		else if (HasHotpantsT && HasShowgirl) {
			PlayerCoverage::AssCover = true;

			if (HasUnderwear || HasThong) {
				PlayerCoverage::GenitalCover = true;
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			}
			else if (HasUnderwearT || HasThongT || HasCString || HasCStringT) {
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);

				if (PlayerCoverage::UnderwearCover) {
					PlayerCoverage::GenitalCover = true;
				}
				else {
					if (HasUnderwearT) {
						PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
					}
					else if (HasThongT) {
						PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
					}
					else {
						AnalyzeCString(HasCStringT, CStringRiskLevel);
					}
				}
			}
			else if (HasUnderwearNoCover || HasThongNoCover) {
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
				PlayerCoverage::GenitalCover = PlayerCoverage::UnderwearCover;
			}
			else {
				PlayerCoverage::UnderwearCover = true;
				PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			}
		}
		else if (HasHotpantsT && HasShowgirlT) {
			bool HotpantsCovering = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			bool ShowgirlCovering = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);

			if (HotpantsCovering && ShowgirlCovering) {
				PlayerCoverage::AssCover = true;
				PlayerCoverage::GenitalCover = true;
				PlayerCoverage::UnderwearCover = true;
			}
			else if (HotpantsCovering && !ShowgirlCovering) {
				PlayerCoverage::GenitalCover = true;

				if (HasUnderwear) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::AssCover = true;
				}
				else if (HasUnderwearT) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasUnderwearNoCover) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::AssCover = false;
				}
				else {
					PlayerCoverage::UnderwearCover = true;
					PlayerCoverage::AssCover = false;
				}
			}
			else if (!HotpantsCovering && ShowgirlCovering) {
				PlayerCoverage::AssCover = true;

				if (HasUnderwear || HasThong) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = true;
				}
				else if (HasUnderwearT) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasThongT) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
				}
				else if (HasCString || HasCStringT) {
					AnalyzeCString(HasCStringT, CStringRiskLevel);
				}
				else if (HasUnderwearNoCover || HasThongNoCover) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = false;
				}
				else {
					PlayerCoverage::UnderwearCover = true;
					PlayerCoverage::GenitalCover = false;
				}
			}
			else {
				AnalyzeUnderwear
				(
					HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
					HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
					HasCString, HasCStringT, CStringRiskLevel
				);
			}
		}
		else if (HasHotpants) {
			PlayerCoverage::GenitalCover = true;

			if (HasUnderwear) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::AssCover = true;
			}
			else if (HasUnderwearT) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
			}
			else if (HasUnderwearNoCover) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::AssCover = false;
			}
			else {
				PlayerCoverage::UnderwearCover = true;
				PlayerCoverage::AssCover = false;
			}
		}
		else if (HasShowgirl) {
			PlayerCoverage::AssCover = true;

			if (HasUnderwear || HasThong) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = true;
			}
			else if (HasUnderwearT) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
			}
			else if (HasThongT) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
			}
			else if (HasCString || HasCStringT) {
				AnalyzeCString(HasCStringT, CStringRiskLevel);
			}
			else if (HasUnderwearNoCover || HasThongNoCover) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = false;
			}
			else {
				PlayerCoverage::UnderwearCover = true;
				PlayerCoverage::GenitalCover = false;
			}
		}
		else if (HasHotpantsT) {
			bool HotpantsCovering = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);

			if (HotpantsCovering) {
				PlayerCoverage::GenitalCover = true;

				if (HasUnderwear) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::AssCover = true;
				}
				else if (HasUnderwearT) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasUnderwearNoCover) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::AssCover = false;
				}
				else {
					PlayerCoverage::UnderwearCover = true;
					PlayerCoverage::AssCover = false;
				}
			}
			else {
				AnalyzeUnderwear
				(
					HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
					HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
					HasCString, HasCStringT, CStringRiskLevel
				);
			}
		}
		else if (HasShowgirlT) {
			bool ShowgirlCovering = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);

			if (ShowgirlCovering) {
				PlayerCoverage::AssCover = true;

				if (HasUnderwear || HasThong) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = true;
				}
				else if (HasUnderwearT) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasThongT) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
				}
				else if (HasCString || HasCStringT) {
					AnalyzeCString(HasCStringT, CStringRiskLevel);
				}
				else if (HasUnderwearNoCover || HasThongNoCover) {
					PlayerCoverage::UnderwearCover = false;
					PlayerCoverage::GenitalCover = false;
				}
				else {
					PlayerCoverage::UnderwearCover = true;
					PlayerCoverage::GenitalCover = false;
				}
			}
			else {
				AnalyzeUnderwear
				(
					HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
					HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
					HasCString, HasCStringT, CStringRiskLevel
				);
			}
		}
		else {
			AnalyzeUnderwear
			(
				HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
				HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
				HasCString, HasCStringT, CStringRiskLevel
			);
		}
	}

	void AnalyzeBottom
	(
		bool HasPelvicCurtain, bool HasPelvicCurtainT, int PelvicRiskLevel,
		bool HasAsscurtain, bool HasAssCurtainT, int AssRiskLevel,
		bool HasArmorBottom, bool HasArmorBottomT, int BottomRiskLevel,
		bool HasHotpants, bool HasHotpantsT, int HotpantsRiskLevel,
		bool HasShowgirl, bool HasShowgirlT, int ShowgirlRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, int CStringRiskLevel
	) {
		if (HasPelvicCurtain || HasPelvicCurtainT) {
			PlayerCoverage::PelvicCurtainCover = CurtainCheck(FlashRiskType::Pelvic, HasPelvicCurtainT, PelvicRiskLevel);
		}
		else {
			PlayerCoverage::PelvicCurtainCover = false;
		}

		if (HasAsscurtain || HasAssCurtainT) {
			PlayerCoverage::AssCurtainCover = CurtainCheck(FlashRiskType::Ass, HasAssCurtainT, AssRiskLevel);
		}
		else {
			PlayerCoverage::AssCurtainCover = false;
		}

		if (HasArmorBottom) {
			PlayerCoverage::AssCover = true;
			PlayerCoverage::GenitalCover = true;
			PlayerCoverage::UnderwearCover = true;
		}
		else if (HasArmorBottomT) {
			PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Bottom, BottomRiskLevel);

			if (PlayerCoverage::UnderwearCover) {
				PlayerCoverage::GenitalCover = true;
				PlayerCoverage::AssCover = true;
			}
			else {
				SubAnalyzeBottom
				(
					HasHotpants, HasHotpantsT, HotpantsRiskLevel, 
					HasShowgirl, HasShowgirlT, ShowgirlRiskLevel,
					HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
					HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
					HasCString, HasCStringT, CStringRiskLevel
				);
			}
		}
		else {
			SubAnalyzeBottom
			(
				HasHotpants, HasHotpantsT, HotpantsRiskLevel,
				HasShowgirl, HasShowgirlT, ShowgirlRiskLevel,
				HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
				HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
				HasCString, HasCStringT, CStringRiskLevel
			);
		}
	}

	void Finalize() {
		if (PlayerCoverage::ChestCurtainCoverage) {
			SetPlayerFactionRank(ToplessFaction, 0);
			SetPlayerFactionRank(ShowingChestFaction, 0);
			SetPlayerFactionRank(ShowingBraFaction, 0);
		}
		else {
			if (PlayerCoverage::BraCover && PlayerCoverage::ChestCover) {
				SetPlayerFactionRank(ToplessFaction, 0);
				SetPlayerFactionRank(ShowingBraFaction, 0);
				SetPlayerFactionRank(ShowingChestFaction, 0);
			}
			else if (!PlayerCoverage::BraCover && PlayerCoverage::ChestCover) {
				SetPlayerFactionRank(ToplessFaction, 0);
				SetPlayerFactionRank(ShowingBraFaction, 1);
				SetPlayerFactionRank(ShowingChestFaction, 0);
			}
			else if (!PlayerCoverage::BraCover && !PlayerCoverage::ChestCover) {
				SetPlayerFactionRank(ToplessFaction, 0);
				SetPlayerFactionRank(ShowingBraFaction, 1);
				SetPlayerFactionRank(ShowingChestFaction, 1);
			}
			else if (PlayerCoverage::BraCover && !PlayerCoverage::ChestCover) {
				if (PlayerWornHasKeyword(ArmorTopT_Low) || PlayerWornHasKeyword(ArmorTopT) || PlayerWornHasKeyword(ArmorTopT_High)
					|| PlayerWornHasKeyword(ArmorTop_NoCover) || PlayerWornHasKeyword(NipplePasties)) {
					SetPlayerFactionRank(ToplessFaction, 0);
					SetPlayerFactionRank(ShowingBraFaction, 0);
					SetPlayerFactionRank(ShowingChestFaction, 1);
				}
				else {
					SetPlayerFactionRank(ToplessFaction, 1);
					SetPlayerFactionRank(ShowingBraFaction, 0);
					SetPlayerFactionRank(ShowingChestFaction, 1);
				}
			}
		}

		if (PlayerCoverage::PelvicCurtainCover && PlayerCoverage::AssCurtainCover) {
			SetPlayerFactionRank(BottomlessFaction, 0);
			SetPlayerFactionRank(ShowingAssFaction, 0);
			SetPlayerFactionRank(ShowingGenitalsFaction, 0);
			SetPlayerFactionRank(ShowingUnderwearFaction, 0);
		}
		else if (PlayerCoverage::PelvicCurtainCover && !PlayerCoverage::AssCurtainCover) {
			SetPlayerFactionRank(BottomlessFaction, 0);
			SetPlayerFactionRank(ShowingGenitalsFaction, 0);
			if (PlayerCoverage::UnderwearCover && PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingAssFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingAssFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && !PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingAssFaction, 1);
			}
			else if (PlayerCoverage::UnderwearCover && !PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingAssFaction, 1);
			}
		}
		else if (!PlayerCoverage::PelvicCurtainCover && PlayerCoverage::AssCurtainCover) {
			SetPlayerFactionRank(BottomlessFaction, 0);
			SetPlayerFactionRank(ShowingAssFaction, 0);
			if (PlayerCoverage::UnderwearCover && PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && !PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 1);
			}
			else if (PlayerCoverage::UnderwearCover && !PlayerCoverage::AssCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingGenitalsFaction, 1);
			}
		}
		else {
			if (PlayerCoverage::UnderwearCover && PlayerCoverage::GenitalCover && PlayerCoverage::AssCover) { //True True True
				SetPlayerFactionRank(BottomlessFaction, 0);
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
				SetPlayerFactionRank(ShowingAssFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && PlayerCoverage::GenitalCover && PlayerCoverage::AssCover) { //False True True
				SetPlayerFactionRank(BottomlessFaction, 0);
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
				SetPlayerFactionRank(ShowingAssFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && !PlayerCoverage::GenitalCover && PlayerCoverage::AssCover) { //False False True
				SetPlayerFactionRank(BottomlessFaction, 0);
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 1);
				SetPlayerFactionRank(ShowingAssFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && PlayerCoverage::GenitalCover && !PlayerCoverage::AssCover) { //False True False
				SetPlayerFactionRank(BottomlessFaction, 0);
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
				SetPlayerFactionRank(ShowingAssFaction, 1);
			}
			else if (!PlayerCoverage::UnderwearCover && !PlayerCoverage::GenitalCover && !PlayerCoverage::AssCover) { //False False False
				SetPlayerFactionRank(BottomlessFaction, 0);
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 1);
				SetPlayerFactionRank(ShowingAssFaction, 1);
			}
			else if (PlayerCoverage::UnderwearCover && !PlayerCoverage::GenitalCover && PlayerCoverage::AssCover) { //True False True
				SetPlayerFactionRank(BottomlessFaction, 0);
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingGenitalsFaction, 1);
				SetPlayerFactionRank(ShowingAssFaction, 0);
			}
			else if (PlayerCoverage::UnderwearCover && PlayerCoverage::GenitalCover && !PlayerCoverage::AssCover) { //True True False
				SetPlayerFactionRank(BottomlessFaction, 0);
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
				SetPlayerFactionRank(ShowingAssFaction, 1);
			}
			else if (PlayerCoverage::UnderwearCover && !PlayerCoverage::GenitalCover && !PlayerCoverage::AssCover) { //True False False
				if (
					PlayerWornHasKeyword(ArmorBottom_NoCover) || 
					PlayerWornHasKeyword(HotpantsT_Low) || PlayerWornHasKeyword(HotpantsT) || PlayerWornHasKeyword(HotpantsT_High) ||
					PlayerWornHasKeyword(ShowgirlSkirtT_Low) || PlayerWornHasKeyword(ShowgirlSkirtT) || PlayerWornHasKeyword(ShowgirlSkirtT_High) ||
					PlayerWornHasKeyword(Microskirt) || PlayerWornHasKeyword(VaginaPasties)
					) {
					SetPlayerFactionRank(BottomlessFaction, 0);
					SetPlayerFactionRank(ShowingUnderwearFaction, 0);
					SetPlayerFactionRank(ShowingGenitalsFaction, 1);
					SetPlayerFactionRank(ShowingAssFaction, 1);
				}
				else {
					SetPlayerFactionRank(BottomlessFaction, 1);
					SetPlayerFactionRank(ShowingUnderwearFaction, 0);
					SetPlayerFactionRank(ShowingGenitalsFaction, 1);
					SetPlayerFactionRank(ShowingAssFaction, 1);
				}
			}
		}

		if (Player->GetFactionRank(ToplessFaction, true) == 1 && Player->GetFactionRank(BottomlessFaction, true) == 1 && !PlayerWornHasKeyword(NearlyNaked)) {
			SetPlayerFactionRank(NudeFaction, 1);
		}
		else {
			SetPlayerFactionRank(NudeFaction, 0);
		}

		Log("<C++ FemaleArmorScan> [Finalize] Nude Faction Rank: " + std::to_string(Player->GetFactionRank(NudeFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Topless Faction Rank: " + std::to_string(Player->GetFactionRank(ToplessFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Bottomless Faction Rank: " + std::to_string(Player->GetFactionRank(BottomlessFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Bra Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingBraFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Chest Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingChestFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Underwear Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingUnderwearFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Genitals Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingGenitalsFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Ass Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingAssFaction, true)), LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [Finalize] Player Female Scan Completed", LogType::PlayerArmorScan);
	}

	bool VanillaArmorCheck() {
		Log("<C++ FemaleArmorScan> [VanillaArmorCheck] START", LogType::PlayerArmorScan);
	
		RE::TESBoundObject* BodyArmor = Player->GetWornArmor(RE::BIPED_MODEL::BipedObjectSlot::kBody);

		if (BodyArmor) {
			const auto BodyItem = AsKeywordForm(BodyArmor);

			bool HasCurtainKeyword =
				(
					BodyItem->HasKeyword(ChestCurtain) || BodyItem->HasKeyword(ChestCurtainT) ||
					BodyItem->HasKeyword(PelvicCurtain) || BodyItem->HasKeyword(PelvicCurtainT) ||
					BodyItem->HasKeyword(AssCurtain) || BodyItem->HasKeyword(AssCurtainT) ||
					BodyItem->HasKeyword(Miniskirt) || BodyItem->HasKeyword(MiniskirtT)
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: " + BoolToString(HasCurtainKeyword), LogType::PlayerArmorScan);

			bool HasTopKeyword =
				(
					BodyItem->HasKeyword(ArmorTop) ||
					BodyItem->HasKeyword(ArmorTopT_Low) || BodyItem->HasKeyword(ArmorTopT) || BodyItem->HasKeyword(ArmorTopT_High) ||
					BodyItem->HasKeyword(ArmorTop_NoCover)
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: " + BoolToString(HasTopKeyword), LogType::PlayerArmorScan);

			bool HasBottomKeyword =
				(
					BodyItem->HasKeyword(ArmorBottom) ||
					BodyItem->HasKeyword(ArmorBottomT_Low) || BodyItem->HasKeyword(ArmorBottomT) || BodyItem->HasKeyword(ArmorBottomT_High) ||
					BodyItem->HasKeyword(ArmorBottom_NoCover) ||
					BodyItem->HasKeyword(Hotpants) ||
					BodyItem->HasKeyword(HotpantsT_Low) || BodyItem->HasKeyword(HotpantsT) || BodyItem->HasKeyword(HotpantsT_High) ||
					BodyItem->HasKeyword(ShowgirlSkirt) ||
					BodyItem->HasKeyword(ShowgirlSkirtT_Low) || BodyItem->HasKeyword(ShowgirlSkirtT) || BodyItem->HasKeyword(ShowgirlSkirtT_High)
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: " + BoolToString(HasBottomKeyword), LogType::PlayerArmorScan);

			bool HasBraKeyword =
				(
					BodyItem->HasKeyword(Bra) ||
					BodyItem->HasKeyword(BraT_Low) || BodyItem->HasKeyword(BraT) || BodyItem->HasKeyword(BraT_High) ||
					BodyItem->HasKeyword(Bra_NoCover)
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: " + BoolToString(HasBraKeyword), LogType::PlayerArmorScan);

			bool HasUnderwearKeyword =
				(
					BodyItem->HasKeyword(Underwear) ||
					BodyItem->HasKeyword(UnderwearT_Low) || BodyItem->HasKeyword(UnderwearT) || BodyItem->HasKeyword(UnderwearT_High) ||
					BodyItem->HasKeyword(Underwear_NoCover) ||
					BodyItem->HasKeyword(Thong) ||
					BodyItem->HasKeyword(ThongT_Low) || BodyItem->HasKeyword(ThongT) || BodyItem->HasKeyword(ThongT_High) ||
					BodyItem->HasKeyword(Thong_NoCover) ||
					BodyItem->HasKeyword(CString) ||
					BodyItem->HasKeyword(CStringT_Low) || BodyItem->HasKeyword(CStringT) || BodyItem->HasKeyword(CStringT_High)
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: " + BoolToString(HasUnderwearKeyword), LogType::PlayerArmorScan);

			bool HasExtraKeyword =
				(
					BodyItem->HasKeyword(NearlyNaked) ||
					BodyItem->HasKeyword(NipplePasties) ||
					BodyItem->HasKeyword(VaginaPasties) ||
					BodyItem->HasKeyword(Microskirt) ||
					BodyItem->HasKeyword(EffectivelyNaked)
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: " + BoolToString(HasExtraKeyword), LogType::PlayerArmorScan);

			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? " + BoolToString(!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword), LogType::PlayerArmorScan);
			return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
		}
		Log("<C++ FemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? false", LogType::PlayerArmorScan);
		return false;
	}

	void FemaleAnalyze() {
		Log("<C++ FemaleArmorScan> [FemaleAnalyze] Player Female Analysis Triggered!", LogType::PlayerArmorScan);
		
		ResetFlashingFactions();

		bool ShouldEscape = false;

		if (Player == nullptr || Player->IsPlayerRef() == false) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] RE::Actor variable not set!!!", LogType::PlayerArmorScan, LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (PlayerBase == nullptr || PlayerBase->IsPlayer() == false) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] RE::TESActorBase variable not set!!!", LogType::PlayerArmorScan, LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (ShouldEscape == true) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] Female Analysis Failed! (Escaped)", LogType::PlayerArmorScan, LoggingLevel::critical);
			return;
		}
	
		Log("<C++ FemaleArmorScan> [FemaleAnalyze] Start analysis...", LogType::PlayerArmorScan);
		if (PlayerWornHasKeyword(CoversAll) || IsPlayerTransformed()) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] Covers All keyword detected or player is transformed", LogType::PlayerArmorScan);

			PlayerCoverage::ChestCurtainCoverage = true;
			PlayerCoverage::PelvicCurtainCover = true;
			PlayerCoverage::AssCurtainCover = true;

			PlayerCoverage::ChestCover = true;
			PlayerCoverage::BraCover = true;
			PlayerCoverage::AssCover = true;
			PlayerCoverage::GenitalCover = true;
			PlayerCoverage::UnderwearCover = true;
		}
		else {
			bool HasChestCurtain = PlayerWornHasKeyword(ChestCurtain);
			bool HasChestCurtainT = PlayerWornHasKeyword(ChestCurtainT);

			int ChestRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(ChestFlashRiskLow)) {
				ChestRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(ChestFlashRisk)) {
				ChestRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(ChestFlashRiskHigh)) {
				ChestRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(ChestFlashRiskExtreme)) {
				ChestRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(ChestFlashRiskUltra)) {
				ChestRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain) || PlayerWornHasKeyword(Miniskirt));
			bool HasPelvicCurtainT = (PlayerWornHasKeyword(PelvicCurtainT) || PlayerWornHasKeyword(MiniskirtT));

			int PelvicRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(PelvicFlashRiskLow)) {
				PelvicRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRisk)) {
				PelvicRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRiskHigh)) {
				PelvicRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRiskExtreme)) {
				PelvicRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRiskUltra)) {
				PelvicRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasAssCurtain = (PlayerWornHasKeyword(AssCurtain) || PlayerWornHasKeyword(Miniskirt));
			bool HasAssCurtainT = (PlayerWornHasKeyword(AssCurtainT) || PlayerWornHasKeyword(MiniskirtT));

			int AssRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(AssFlashRiskLow)) {
				AssRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(AssFlashRisk)) {
				AssRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(AssFlashRiskHigh)) {
				AssRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(AssFlashRiskExtreme)) {
				AssRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(AssFlashRiskUltra)) {
				AssRiskLevel = FlashRiskLevel::Ultra;
			}

			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasChestCurtain = " + BoolToString(HasChestCurtain), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasChestCurtainT = " + BoolToString(HasChestCurtainT), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] ChestRiskLevel = " + BoolToString(ChestRiskLevel), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasPelvicCurtain = " + BoolToString(HasPelvicCurtain), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasPelvicCurtainT = " + BoolToString(HasPelvicCurtainT), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] PelvicRiskLevel = " + BoolToString(PelvicRiskLevel), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasAssCurtain = " + BoolToString(HasAssCurtain), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasAssCurtainT = " + BoolToString(HasAssCurtainT), LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] AssRiskLevel = " + BoolToString(AssRiskLevel), LogType::PlayerArmorScan);

			if (VanillaArmorCheck() == true) {
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] Armor is considered vanilla", LogType::PlayerArmorScan);

				PlayerCoverage::ChestCurtainCoverage = CurtainCheck(FlashRiskType::Chest, HasChestCurtainT, ChestRiskLevel);
				PlayerCoverage::PelvicCurtainCover = CurtainCheck(FlashRiskType::Pelvic, HasPelvicCurtainT, PelvicRiskLevel);
				PlayerCoverage::AssCurtainCover = CurtainCheck(FlashRiskType::Ass, HasAssCurtainT, AssRiskLevel);

				PlayerCoverage::ChestCover = true;
				PlayerCoverage::BraCover = true;
				PlayerCoverage::AssCover = true;
				PlayerCoverage::GenitalCover = true;
				PlayerCoverage::UnderwearCover = true;
			}
			else {
				/*
				=============
				TOP VAIRABLES
				=============
				*/

				//Armor Top
				bool HasArmorTop = PlayerWornHasKeyword(ArmorTop);
				int TopRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(ArmorTopT_Low)) {
					TopRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(ArmorTopT)) {
					TopRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(ArmorTopT_High)) {
					TopRiskLevel = FlashRiskLevel::High;
				}
				bool HasArmorTopT = TopRiskLevel > FlashRiskLevel::None;

				//Bra
				bool HasBra = PlayerWornHasKeyword(Bra);
				int BraRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(BraT_Low)) {
					BraRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(BraT)) {
					BraRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(BraT_High)) {
					BraRiskLevel = FlashRiskLevel::High;
				}
				bool HasBraT = BraRiskLevel > FlashRiskLevel::None;
				bool HasBraNoCover = PlayerWornHasKeyword(Bra_NoCover);

				/*
				================
				BOTTOM VARIABLES
				================
				*/

				//Bottom Armor
				bool HasArmorBottom = PlayerWornHasKeyword(ArmorBottom);
				int BottomRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(ArmorBottomT_Low)) {
					BottomRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(ArmorBottomT)) {
					BottomRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(ArmorBottomT_High)) {
					BottomRiskLevel = FlashRiskLevel::High;
				}
				bool HasArmorBottomT = BottomRiskLevel > FlashRiskLevel::None;

				//Hotpants
				bool HasHotpants = PlayerWornHasKeyword(Hotpants);
				int HotpantsRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(HotpantsT_Low)) {
					HotpantsRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(HotpantsT)) {
					HotpantsRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(HotpantsT_High)) {
					HotpantsRiskLevel = FlashRiskLevel::High;
				}
				bool HasHotpantsT = HotpantsRiskLevel > FlashRiskLevel::None;

				//Showgirl Skirt
				bool HasShowgirl = PlayerWornHasKeyword(ShowgirlSkirt);
				int ShowgirlRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(ShowgirlSkirtT_Low)) {
					ShowgirlRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(ShowgirlSkirtT)) {
					ShowgirlRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(ShowgirlSkirtT_High)) {
					ShowgirlRiskLevel = FlashRiskLevel::High;
				}
				bool HasShowgirlT = ShowgirlRiskLevel > FlashRiskLevel::None;

				//Underwear
				bool HasUnderwear = PlayerWornHasKeyword(Underwear);
				int UnderwearRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(UnderwearT_Low)) {
					UnderwearRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(UnderwearT)) {
					UnderwearRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(UnderwearT_High)) {
					UnderwearRiskLevel = FlashRiskLevel::High;
				}
				bool HasUnderwearT = UnderwearRiskLevel > FlashRiskLevel::None;
				bool HasUnderwearNoCover = PlayerWornHasKeyword(Underwear_NoCover);

				//Thong
				bool HasThong = PlayerWornHasKeyword(Thong);
				int ThongRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(ThongT_Low)) {
					ThongRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(ThongT)) {
					ThongRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(ThongT_High)) {
					ThongRiskLevel = FlashRiskLevel::High;
				}
				bool HasThongT = ThongRiskLevel > FlashRiskLevel::None;
				bool HasThongNoCover = PlayerWornHasKeyword(Thong_NoCover);

				//CString
				bool HasCString = PlayerWornHasKeyword(CString);
				int CStringRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(CStringT_Low)) {
					CStringRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(CStringT)) {
					CStringRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(CStringT_High)) {
					CStringRiskLevel = FlashRiskLevel::High;
				}
				bool HasCStringT = CStringRiskLevel > FlashRiskLevel::None;
			
				//Debug Results
				//Top
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorTop = " + BoolToString(HasArmorTop), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorTopT = " + BoolToString(HasArmorTopT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] TopRiskLevel = " + BoolToString(TopRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasBra = " + BoolToString(HasBra), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasBraT = " + BoolToString(HasBraT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] BraRiskLevel = " + BoolToString(BraRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasBraNoCover = " + BoolToString(HasBraNoCover), LogType::PlayerArmorScan);

				//Bottom
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorBottom = " + BoolToString(HasArmorBottom), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorBottomT = " + BoolToString(HasArmorBottomT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] BottomRiskLevel = " + BoolToString(BottomRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasHotpants = " + BoolToString(HasHotpants), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasHotpantsT = " + BoolToString(HasHotpantsT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HotpantsRiskLevel = " + BoolToString(HotpantsRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasShowgirl = " + BoolToString(HasShowgirl), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasShowgirlT = " + BoolToString(HasShowgirlT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] ShowgirlRiskLevel = " + BoolToString(ShowgirlRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwear = " + BoolToString(HasUnderwear), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwearT = " + BoolToString(HasUnderwearT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] UnderwearRiskLevel = " + BoolToString(UnderwearRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwearNoCover = " + BoolToString(HasUnderwearNoCover), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasThong = " + BoolToString(HasThong), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasThongT = " + BoolToString(HasThongT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] ThongRiskLevel = " + BoolToString(ThongRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasThongNoCover = " + BoolToString(HasThongNoCover), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasCString = " + BoolToString(HasCString), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasCStringT = " + BoolToString(HasCStringT), LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] CStringRiskLevel = " + BoolToString(CStringRiskLevel), LogType::PlayerArmorScan);

				AnalyzeTop
				(
					HasChestCurtain, HasChestCurtainT, ChestRiskLevel, 
					HasArmorTop, HasArmorTopT, TopRiskLevel, 
					HasBra, HasBraT, BraRiskLevel, HasBraNoCover
				);

				AnalyzeBottom
				(
					HasPelvicCurtain, HasPelvicCurtainT, PelvicRiskLevel,
					HasAssCurtain, HasAssCurtainT, AssRiskLevel,
					HasArmorBottom, HasArmorBottomT, BottomRiskLevel,
					HasHotpants, HasHotpantsT, HotpantsRiskLevel,
					HasShowgirl, HasShowgirlT, ShowgirlRiskLevel,
					HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
					HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
					HasCString, HasCStringT, CStringRiskLevel
				);
			}
		}

		Finalize();

		Log("<C++ MaleArmorScan> [FemaleAnalyze] Analysis Succeeded!", LogType::PlayerArmorScan);
	}
}

void ExternalFemaleAnalyze(RE::StaticFunctionTag*) {
	FemaleArmorScan::FemaleAnalyze();
}