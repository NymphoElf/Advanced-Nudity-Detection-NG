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
	
	bool CurtainCheck(UINT8 Type, bool IsTransparent, UINT8 Level) {
		INT8 Roll = 0;
		INT8 Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Chest) {
			TypeString = "Chest";
			Roll = ChestCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsLow];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsLow];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOdds];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOdds];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsHigh];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsHigh];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsExtreme];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsExtreme];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (!IsTransparent) {
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
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsLow];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsLow];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOdds];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOdds];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsHigh];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsHigh];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsExtreme];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsExtreme];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (!IsTransparent) {
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
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsLow];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsLow];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOdds];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOdds];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsHigh];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsHigh];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsExtreme];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsExtreme];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsUltra];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsUltra];
				}
			}
		}

		Log("<C++ FemaleArmorScan> [CurtainCheck] Roll = " + std::to_string(Roll), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CurtainCheck] Odds = " + std::to_string(Odds), Logger::LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CurtainCheck] Type = " + TypeString, Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CurtainCheck] Is Transparent = " + BoolToString(IsTransparent), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CurtainCheck] Risk Level = " + FlashRiskToString(Level), Logger::LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), Logger::LogType::PlayerArmorScan);

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

	bool TransparentItemCheck(UINT8 Type, UINT8 Level) {
		INT8 Roll = 0;
		INT8 Odds = 0;

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

		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Roll = " + std::to_string(Roll), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Odds = " + std::to_string(Odds), Logger::LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Type = " + TypeString, Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [TransparentItemCheck] RiskLevel = " + FlashRiskToString(Level), Logger::LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), Logger::LogType::PlayerArmorScan);

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

	bool CStringCheck(bool IsTransparent, UINT8 Level) {
		INT8 Odds = 0;

		if (!IsTransparent) {
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

		Log("<C++ FemaleArmorScan> [CStringCheck] Roll = " + std::to_string(CStringRoll), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CStringCheck] Odds = " + std::to_string(Odds), Logger::LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CStringCheck] IsTransparent = " + BoolToString(IsTransparent), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [CStringCheck] RiskLevel = " + FlashRiskToString(Level), Logger::LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [CStringCheck] Function Return Value: Is Covering? " + BoolToString(CStringRoll > Odds), Logger::LogType::PlayerArmorScan);

		bool Result = (CStringRoll > Odds);

		SetPlayerFactionRank(FlashingCStringFaction, !Result);

		return Result;
	}

	void AnalyzeBra(bool HasBra, bool HasBraT, UINT8 BraRiskLevel, bool HasBraNoCover) {
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
		bool HasChestCurtain, bool HasChestCurtainT, UINT8 ChestRiskLevel, 
		bool HasArmorTop, bool HasArmorTopT, UINT8 TopRiskLevel, 
		bool HasBra, bool HasBraT, UINT8 BraRiskLevel, bool HasBraNoCover
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

	void AnalyzeCString(bool HasCStringT, UINT8 CStringRiskLevel) {
		PlayerCoverage::GenitalCover = CStringCheck(HasCStringT, CStringRiskLevel);
		PlayerCoverage::UnderwearCover = !PlayerCoverage::GenitalCover;
	}

	void AnalyzeUnderwear
	(
		bool HasUnderwear, bool HasUnderwearT, UINT8 UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, UINT8 ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, UINT8 CStringRiskLevel
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
		bool HasHotpants, bool HasHotpantsT, UINT8 HotpantsRiskLevel,
		bool HasShowgirl, bool HasShowgirlT, UINT8 ShowgirlRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, UINT8 UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, UINT8 ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, UINT8 CStringRiskLevel
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
		bool HasPelvicCurtain, bool HasPelvicCurtainT, UINT8 PelvicRiskLevel,
		bool HasAsscurtain, bool HasAssCurtainT, UINT8 AssRiskLevel,
		bool HasArmorBottom, bool HasArmorBottomT, UINT8 BottomRiskLevel,
		bool HasHotpants, bool HasHotpantsT, UINT8 HotpantsRiskLevel,
		bool HasShowgirl, bool HasShowgirlT, UINT8 ShowgirlRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, UINT8 UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, UINT8 ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, UINT8 CStringRiskLevel
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
		//Top Coverage
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
				if (PlayerIsWearing(FemaleKeywords[ArmorTopT_Low]) || PlayerIsWearing(FemaleKeywords[ArmorTopT]) || PlayerIsWearing(FemaleKeywords[ArmorTopT_High])
					|| PlayerIsWearing(FemaleKeywords[ArmorTop_NoCover]) || PlayerIsWearing(FemaleKeywords[NipplePasties])) {
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

		//Bottom Coverage
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

			if (PlayerCoverage::UnderwearCover && PlayerCoverage::GenitalCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 0);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && PlayerCoverage::GenitalCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 0);
			}
			else if (!PlayerCoverage::UnderwearCover && !PlayerCoverage::GenitalCover) {
				SetPlayerFactionRank(ShowingUnderwearFaction, 1);
				SetPlayerFactionRank(ShowingGenitalsFaction, 1);
			}
			else if (PlayerCoverage::UnderwearCover && !PlayerCoverage::GenitalCover) {
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
					PlayerIsWearing(FemaleKeywords[ArmorBottom_NoCover]) ||
					PlayerIsWearing(FemaleKeywords[HotpantsT_Low]) || PlayerIsWearing(FemaleKeywords[HotpantsT]) || PlayerIsWearing(FemaleKeywords[HotpantsT_High]) ||
					PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT_Low]) || PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT]) || PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT_High]) ||
					PlayerIsWearing(FemaleKeywords[Microskirt]) || PlayerIsWearing(FemaleKeywords[VaginaPasties])
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

		if (Player->GetFactionRank(ToplessFaction, true) == 1 && Player->GetFactionRank(BottomlessFaction, true) == 1 && !PlayerIsWearing(FemaleKeywords[NearlyNaked])) {
			SetPlayerFactionRank(NudeFaction, 1);
		}
		else {
			SetPlayerFactionRank(NudeFaction, 0);
		}

		Log("<C++ FemaleArmorScan> [Finalize] Nude Faction Rank: " + std::to_string(Player->GetFactionRank(NudeFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Topless Faction Rank: " + std::to_string(Player->GetFactionRank(ToplessFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Bottomless Faction Rank: " + std::to_string(Player->GetFactionRank(BottomlessFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Bra Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingBraFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Chest Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingChestFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Underwear Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingUnderwearFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Genitals Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingGenitalsFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ FemaleArmorScan> [Finalize] Showing Ass Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingAssFaction, true)), Logger::LogType::PlayerArmorScan);

		Log("<C++ FemaleArmorScan> [Finalize] Player Female Scan Completed", Logger::LogType::PlayerArmorScan);
	}

	bool VanillaArmorCheck() {
		Log("<C++ FemaleArmorScan> [VanillaArmorCheck] START", Logger::LogType::PlayerArmorScan);
	
		RE::TESBoundObject* BodyArmor = Player->GetWornArmor(RE::BIPED_MODEL::BipedObjectSlot::kBody);

		if (BodyArmor) {
			const auto BodyItem = AsKeywordForm(BodyArmor);

			bool HasCurtainKeyword =
				(
					BodyItem->HasKeyword(FemaleKeywords[ChestCurtain]) || BodyItem->HasKeyword(FemaleKeywords[ChestCurtainT]) ||
					BodyItem->HasKeyword(FemaleKeywords[PelvicCurtain]) || BodyItem->HasKeyword(FemaleKeywords[PelvicCurtainT]) ||
					BodyItem->HasKeyword(FemaleKeywords[AssCurtain]) || BodyItem->HasKeyword(FemaleKeywords[AssCurtainT]) ||
					BodyItem->HasKeyword(FemaleKeywords[Miniskirt]) || BodyItem->HasKeyword(FemaleKeywords[MiniskirtT])
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: " + BoolToString(HasCurtainKeyword), Logger::LogType::PlayerArmorScan);
			if (HasCurtainKeyword) {
				return false;
			}

			bool HasTopKeyword =
				(
					BodyItem->HasKeyword(FemaleKeywords[ArmorTop]) ||
					BodyItem->HasKeyword(FemaleKeywords[ArmorTopT_Low]) || BodyItem->HasKeyword(FemaleKeywords[ArmorTopT]) || BodyItem->HasKeyword(FemaleKeywords[ArmorTopT_High]) ||
					BodyItem->HasKeyword(FemaleKeywords[ArmorTop_NoCover])
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: " + BoolToString(HasTopKeyword), Logger::LogType::PlayerArmorScan);
			if (HasTopKeyword) {
				return false;
			}

			bool HasBottomKeyword =
				(
					BodyItem->HasKeyword(FemaleKeywords[ArmorBottom]) ||
					BodyItem->HasKeyword(FemaleKeywords[ArmorBottomT_Low]) || BodyItem->HasKeyword(FemaleKeywords[ArmorBottomT]) || BodyItem->HasKeyword(FemaleKeywords[ArmorBottomT_High]) ||
					BodyItem->HasKeyword(FemaleKeywords[ArmorBottom_NoCover]) ||
					BodyItem->HasKeyword(FemaleKeywords[Hotpants]) ||
					BodyItem->HasKeyword(FemaleKeywords[HotpantsT_Low]) || BodyItem->HasKeyword(FemaleKeywords[HotpantsT]) || BodyItem->HasKeyword(FemaleKeywords[HotpantsT_High]) ||
					BodyItem->HasKeyword(FemaleKeywords[ShowgirlSkirt]) ||
					BodyItem->HasKeyword(FemaleKeywords[ShowgirlSkirtT_Low]) || BodyItem->HasKeyword(FemaleKeywords[ShowgirlSkirtT]) || BodyItem->HasKeyword(FemaleKeywords[ShowgirlSkirtT_High])
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: " + BoolToString(HasBottomKeyword), Logger::LogType::PlayerArmorScan);
			if (HasBottomKeyword) {
				return false;
			}

			bool HasBraKeyword =
				(
					BodyItem->HasKeyword(FemaleKeywords[Bra]) ||
					BodyItem->HasKeyword(FemaleKeywords[BraT_Low]) || BodyItem->HasKeyword(FemaleKeywords[BraT]) || BodyItem->HasKeyword(FemaleKeywords[BraT_High]) ||
					BodyItem->HasKeyword(FemaleKeywords[Bra_NoCover])
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: " + BoolToString(HasBraKeyword), Logger::LogType::PlayerArmorScan);
			if (HasBraKeyword) {
				return false;
			}

			bool HasUnderwearKeyword =
				(
					BodyItem->HasKeyword(FemaleKeywords[Underwear]) ||
					BodyItem->HasKeyword(FemaleKeywords[UnderwearT_Low]) || BodyItem->HasKeyword(FemaleKeywords[UnderwearT]) || BodyItem->HasKeyword(FemaleKeywords[UnderwearT_High]) ||
					BodyItem->HasKeyword(FemaleKeywords[Underwear_NoCover]) ||
					BodyItem->HasKeyword(FemaleKeywords[Thong]) ||
					BodyItem->HasKeyword(FemaleKeywords[ThongT_Low]) || BodyItem->HasKeyword(FemaleKeywords[ThongT]) || BodyItem->HasKeyword(FemaleKeywords[ThongT_High]) ||
					BodyItem->HasKeyword(FemaleKeywords[Thong_NoCover]) ||
					BodyItem->HasKeyword(FemaleKeywords[CString]) ||
					BodyItem->HasKeyword(FemaleKeywords[CStringT_Low]) || BodyItem->HasKeyword(FemaleKeywords[CStringT]) || BodyItem->HasKeyword(FemaleKeywords[CStringT_High])
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: " + BoolToString(HasUnderwearKeyword), Logger::LogType::PlayerArmorScan);
			if (HasUnderwearKeyword) {
				return false;
			}

			bool HasExtraKeyword =
				(
					BodyItem->HasKeyword(FemaleKeywords[NearlyNaked]) ||
					BodyItem->HasKeyword(FemaleKeywords[NipplePasties]) ||
					BodyItem->HasKeyword(FemaleKeywords[VaginaPasties]) ||
					BodyItem->HasKeyword(FemaleKeywords[Microskirt]) ||
					BodyItem->HasKeyword(FemaleKeywords[EffectivelyNaked])
					);
			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: " + BoolToString(HasExtraKeyword), Logger::LogType::PlayerArmorScan);
			if (HasExtraKeyword) {
				return false;
			}

			Log("<C++ FemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? True - No A.N.D. Keywords were found on the Body Armor", Logger::LogType::PlayerArmorScan);
			return true;
		}

		Log("<C++ FemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? False - Not Wearing Body Armor", Logger::LogType::PlayerArmorScan);
		return false;
	}

	UINT8 GetChestCurtainRiskLevel() {
		if (PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskLow])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[ChestFlashRisk])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskHigh])) {
			return FlashRiskLevel::High;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskExtreme])) {
			return FlashRiskLevel::Extreme;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[ChestFlashRiskUltra])) {
			return FlashRiskLevel::Ultra;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetPelvicCurtainRiskLevel() {
		if (PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskLow])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRisk])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskHigh])) {
			return FlashRiskLevel::High;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskExtreme])) {
			return FlashRiskLevel::Extreme;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[PelvicFlashRiskUltra])) {
			return FlashRiskLevel::Ultra;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetAssCurtainRiskLevel() {
		if (PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskLow])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[AssFlashRisk])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskHigh])) {
			return FlashRiskLevel::High;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskExtreme])) {
			return FlashRiskLevel::Extreme;
		}
		else if (PlayerWornHasKeyword(FemaleKeywords[AssFlashRiskUltra])) {
			return FlashRiskLevel::Ultra;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetArmorTopRiskLevel() {
		if (PlayerIsWearing(FemaleKeywords[ArmorTopT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerIsWearing(FemaleKeywords[ArmorTopT])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerIsWearing(FemaleKeywords[ArmorTopT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetBraRiskLevel() {
		if (PlayerIsWearing(FemaleKeywords[BraT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerIsWearing(FemaleKeywords[BraT])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerIsWearing(FemaleKeywords[BraT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetUnderwearRiskLevel(UnderwearType::UnderwearTypes Type) {
		switch (Type) {
			case UnderwearType::Underwear:
				if (PlayerIsWearing(FemaleKeywords[UnderwearT_Low])) {
					return FlashRiskLevel::Low;
				}
				else if (PlayerIsWearing(FemaleKeywords[UnderwearT])) {
					return FlashRiskLevel::Normal;
				}
				else if (PlayerIsWearing(FemaleKeywords[UnderwearT_High])) {
					return FlashRiskLevel::High;
				}
				break;
			case UnderwearType::Thong:
				if (PlayerIsWearing(FemaleKeywords[ThongT_Low])) {
					return FlashRiskLevel::Low;
				}
				else if (PlayerIsWearing(FemaleKeywords[ThongT])) {
					return FlashRiskLevel::Normal;
				}
				else if (PlayerIsWearing(FemaleKeywords[ThongT_High])) {
					return FlashRiskLevel::High;
				}
				break;
			case UnderwearType::CString:
				if (PlayerIsWearing(FemaleKeywords[CStringT_Low])) {
					return FlashRiskLevel::Low;
				}
				else if (PlayerIsWearing(FemaleKeywords[CStringT])) {
					return FlashRiskLevel::Normal;
				}
				else if (PlayerIsWearing(FemaleKeywords[CStringT_High])) {
					return FlashRiskLevel::High;
				}
				break;
			default:
				break;
		}
		return FlashRiskLevel::None;
	}

	UINT8 GetArmorBottomRiskLevel() {
		if (PlayerIsWearing(FemaleKeywords[ArmorBottomT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerIsWearing(FemaleKeywords[ArmorBottomT])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerIsWearing(FemaleKeywords[ArmorBottomT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetHotpantsRiskLevel() {
		if (PlayerIsWearing(FemaleKeywords[HotpantsT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerIsWearing(FemaleKeywords[HotpantsT])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerIsWearing(FemaleKeywords[HotpantsT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetShowgirlRiskLevel() {
		if (PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT])) {
			return FlashRiskLevel::Normal;
		}
		else if (PlayerIsWearing(FemaleKeywords[ShowgirlSkirtT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	void FemaleAnalyze() {
		Log("<C++ FemaleArmorScan> [FemaleAnalyze] Player Female Analysis Triggered!", Logger::LogType::PlayerArmorScan);
		
		ResetFlashingFactions();

		bool ShouldEscape = false;

		if (Player == nullptr || Player->IsPlayerRef() == false) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] RE::Actor variable not set!!!", Logger::LogType::PlayerArmorScan, Logger::LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (PlayerBase == nullptr || PlayerBase->IsPlayer() == false) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] RE::TESActorBase variable not set!!!", Logger::LogType::PlayerArmorScan, Logger::LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (ShouldEscape == true) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] Female Analysis Failed! (Escaped)", Logger::LogType::PlayerArmorScan, Logger::LoggingLevel::critical);
			return;
		}
	
		Log("<C++ FemaleArmorScan> [FemaleAnalyze] Start analysis...", Logger::LogType::PlayerArmorScan);
		if (PlayerIsWearing(FemaleKeywords[CoversAll]) || IsPlayerTransformed()) {
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] Covers All keyword detected or player is transformed", Logger::LogType::PlayerArmorScan);

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
			bool HasChestCurtain = PlayerIsWearing(FemaleKeywords[ChestCurtain]);
			bool HasChestCurtainT = PlayerIsWearing(FemaleKeywords[ChestCurtainT]);

			UINT8 ChestRiskLevel = GetChestCurtainRiskLevel();

			bool HasPelvicCurtain = (PlayerIsWearing(FemaleKeywords[PelvicCurtain]) || PlayerIsWearing(FemaleKeywords[Miniskirt]));
			bool HasPelvicCurtainT = (PlayerIsWearing(FemaleKeywords[PelvicCurtainT]) || PlayerIsWearing(FemaleKeywords[MiniskirtT]));

			UINT8 PelvicRiskLevel = GetPelvicCurtainRiskLevel();

			bool HasAssCurtain = (PlayerIsWearing(FemaleKeywords[AssCurtain]) || PlayerIsWearing(FemaleKeywords[Miniskirt]));
			bool HasAssCurtainT = (PlayerIsWearing(FemaleKeywords[AssCurtainT]) || PlayerIsWearing(FemaleKeywords[MiniskirtT]));

			UINT8 AssRiskLevel = GetAssCurtainRiskLevel();

			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasChestCurtain = " + BoolToString(HasChestCurtain), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasChestCurtainT = " + BoolToString(HasChestCurtainT), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] ChestRiskLevel = " + BoolToString(ChestRiskLevel), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasPelvicCurtain = " + BoolToString(HasPelvicCurtain), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasPelvicCurtainT = " + BoolToString(HasPelvicCurtainT), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] PelvicRiskLevel = " + BoolToString(PelvicRiskLevel), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasAssCurtain = " + BoolToString(HasAssCurtain), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasAssCurtainT = " + BoolToString(HasAssCurtainT), Logger::LogType::PlayerArmorScan);
			Log("<C++ FemaleArmorScan> [FemaleAnalyze] AssRiskLevel = " + BoolToString(AssRiskLevel), Logger::LogType::PlayerArmorScan);

			if (VanillaArmorCheck() == true) {
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] Armor is considered vanilla", Logger::LogType::PlayerArmorScan);

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
				bool HasArmorTop = PlayerIsWearing(FemaleKeywords[ArmorTop]);

				UINT8 TopRiskLevel = GetArmorTopRiskLevel();
				bool HasArmorTopT = TopRiskLevel;

				//Bra
				bool HasBra = PlayerIsWearing(FemaleKeywords[Bra]);

				UINT8 BraRiskLevel = GetBraRiskLevel();
				bool HasBraT = BraRiskLevel;

				bool HasBraNoCover = PlayerIsWearing(FemaleKeywords[Bra_NoCover]);

				/*
				================
				BOTTOM VARIABLES
				================
				*/

				//Bottom Armor
				bool HasArmorBottom = PlayerIsWearing(FemaleKeywords[ArmorBottom]);
				
				UINT8 BottomRiskLevel = GetArmorBottomRiskLevel();
				bool HasArmorBottomT = BottomRiskLevel;

				//Hotpants
				bool HasHotpants = PlayerIsWearing(FemaleKeywords[Hotpants]);
				
				UINT8 HotpantsRiskLevel = GetHotpantsRiskLevel();
				bool HasHotpantsT = HotpantsRiskLevel;

				//Showgirl Skirt
				bool HasShowgirl = PlayerIsWearing(FemaleKeywords[ShowgirlSkirt]);
				
				UINT8 ShowgirlRiskLevel = GetShowgirlRiskLevel();
				bool HasShowgirlT = ShowgirlRiskLevel;

				//Underwear
				bool HasUnderwear = PlayerIsWearing(FemaleKeywords[Underwear]);

				UINT8 UnderwearRiskLevel = GetUnderwearRiskLevel(UnderwearType::Underwear);
				bool HasUnderwearT = UnderwearRiskLevel;

				bool HasUnderwearNoCover = PlayerIsWearing(FemaleKeywords[Underwear_NoCover]);

				//Thong
				bool HasThong = PlayerIsWearing(FemaleKeywords[Thong]);

				UINT8 ThongRiskLevel = GetUnderwearRiskLevel(UnderwearType::Thong);
				bool HasThongT = ThongRiskLevel;
				
				bool HasThongNoCover = PlayerIsWearing(FemaleKeywords[Thong_NoCover]);

				//CString
				bool HasCString = PlayerIsWearing(FemaleKeywords[CString]);

				UINT8 CStringRiskLevel = GetUnderwearRiskLevel(UnderwearType::CString);
				bool HasCStringT = CStringRiskLevel;
			
				//Debug Results
				//Top
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorTop = " + BoolToString(HasArmorTop), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorTopT = " + BoolToString(HasArmorTopT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] TopRiskLevel = " + BoolToString(TopRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasBra = " + BoolToString(HasBra), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasBraT = " + BoolToString(HasBraT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] BraRiskLevel = " + BoolToString(BraRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasBraNoCover = " + BoolToString(HasBraNoCover), Logger::LogType::PlayerArmorScan);

				//Bottom
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorBottom = " + BoolToString(HasArmorBottom), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorBottomT = " + BoolToString(HasArmorBottomT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] BottomRiskLevel = " + BoolToString(BottomRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasHotpants = " + BoolToString(HasHotpants), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasHotpantsT = " + BoolToString(HasHotpantsT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HotpantsRiskLevel = " + BoolToString(HotpantsRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasShowgirl = " + BoolToString(HasShowgirl), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasShowgirlT = " + BoolToString(HasShowgirlT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] ShowgirlRiskLevel = " + BoolToString(ShowgirlRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwear = " + BoolToString(HasUnderwear), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwearT = " + BoolToString(HasUnderwearT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] UnderwearRiskLevel = " + BoolToString(UnderwearRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwearNoCover = " + BoolToString(HasUnderwearNoCover), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasThong = " + BoolToString(HasThong), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasThongT = " + BoolToString(HasThongT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] ThongRiskLevel = " + BoolToString(ThongRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasThongNoCover = " + BoolToString(HasThongNoCover), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasCString = " + BoolToString(HasCString), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] HasCStringT = " + BoolToString(HasCStringT), Logger::LogType::PlayerArmorScan);
				Log("<C++ FemaleArmorScan> [FemaleAnalyze] CStringRiskLevel = " + BoolToString(CStringRiskLevel), Logger::LogType::PlayerArmorScan);

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

		SLSFRNakedCommentPrecheck();

		Log("<C++ FemaleArmorScan> [FemaleAnalyze] Analysis Succeeded!", Logger::LogType::PlayerArmorScan);
	}
}

void ExternalFemaleAnalyze(RE::StaticFunctionTag*) {
	FemaleArmorScan::FemaleAnalyze();
}