#include "PlayerArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "Logger.h"
#include "Player.h"

namespace MaleArmorScan {
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
		Log("<C++ MaleArmorScan> [CurtainCheck] START", Logger::LogType::PlayerArmorScan);

		INT8 Roll = 0;
		INT8 Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Chest) {
			TypeString = "Chest";
			Roll = ChestCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsLow_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsLow_Male];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOdds_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOdds_Male];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsHigh_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsHigh_Male];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsExtreme_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsExtreme_Male];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsUltra_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsUltra_Male];
				}
			}
		}
		else if (Type == FlashRiskType::Pelvic) {
			TypeString = "Pelvic";
			Roll = PelvicCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsLow_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsLow_Male];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOdds_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOdds_Male];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsHigh_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsHigh_Male];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsExtreme_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsExtreme_Male];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsUltra_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsUltra_Male];
				}
			}
		}
		else if (Type == FlashRiskType::Ass) {
			TypeString = "Ass";
			Roll = AssCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsLow_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsLow_Male];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOdds_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOdds_Male];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsHigh_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsHigh_Male];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsExtreme_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsExtreme_Male];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (!IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsUltra_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsUltra_Male];
				}
			}
		}

		Log("<C++ MaleArmorScan> [CurtainCheck] Roll = " + std::to_string(Roll), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [CurtainCheck] Odds = " + std::to_string(Odds), Logger::LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [CurtainCheck] Type = " + TypeString);
		Log("<C++ MaleArmorScan> [CurtainCheck] Is Transparent = " + BoolToString(IsTransparent), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [CurtainCheck] Risk Level = " + FlashRiskToString(Level), Logger::LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), Logger::LogType::PlayerArmorScan);

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
				Odds = Configuration::FlashingOdds[TransparentTopArmorOdds_Low_Male];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentTopArmorOdds_Male];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentTopArmorOdds_High_Male];
			}
		}
		else if (Type == FlashRiskType::Bottom) {
			TypeString = "Bottom";
			Roll = BottomTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentBottomArmorOdds_Low_Male];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentBottomArmorOdds_Male];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentBottomArmorOdds_High_Male];
			}
		}
		else if (Type == FlashRiskType::Bra) {
			TypeString = "Bra";
			Roll = BraTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentBraOdds_Low_Male];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentBraOdds_Male];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentBraOdds_High_Male];
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
				Odds = Configuration::FlashingOdds[TransparentUnderwearOdds_Low_Male];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentUnderwearOdds_Male];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentUnderwearOdds_High_Male];
			}
		}
		else if (Type == FlashRiskType::Hotpants) {
			TypeString = "Hotpants";
			Roll = HotpantsTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentHotpantsOdds_Low_Male];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentHotpantsOdds_Male];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentHotpantsOdds_High_Male];
			}
		}
		else if (Type == FlashRiskType::Himbo) {
			TypeString = "Himbo";
			Roll = ShowgirlTransparentRoll;
			if (Level == FlashRiskLevel::Low) {
				Odds = Configuration::FlashingOdds[TransparentHimboOdds_Low];
			}
			else if (Level == FlashRiskLevel::Normal) {
				Odds = Configuration::FlashingOdds[TransparentHimboOdds];
			}
			else if (Level == FlashRiskLevel::High) {
				Odds = Configuration::FlashingOdds[TransparentHimboOdds_High];
			}
		}

		Log("<C++ MaleArmorScan> [TransparentItemCheck] Roll = " + std::to_string(Roll), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [TransparentItemCheck] Odds = " + std::to_string(Odds), Logger::LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [TransparentItemCheck] Type = " + TypeString, Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [TransparentItemCheck] Risk Level = " + FlashRiskToString(Level), Logger::LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), Logger::LogType::PlayerArmorScan);

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
		case FlashRiskType::Himbo:
			SetPlayerFactionRank(FlashingShowgirlSkirtFaction, !Result);
			break;
		default:
			break;
		}

		return Result;
	}

	bool BananaHammockCheck(bool IsTransparent, UINT8 Level) {
		INT8 Odds = 0;

		if (!IsTransparent) {
			Odds = Configuration::FlashingOdds[BananaHammockOdds];
		}
		else if (Level == FlashRiskLevel::Low) {
			Odds = Configuration::FlashingOdds[TransparentBananaHammockOdds_Low];
		}
		else if (Level == FlashRiskLevel::Normal) {
			Odds = Configuration::FlashingOdds[TransparentBananaHammockOdds];
		}
		else if (Level == FlashRiskLevel::High) {
			Odds = Configuration::FlashingOdds[TransparentBananaHammockOdds_High];
		}

		Log("<C++ MaleArmorScan> [BananaHammockCheck] Roll = " + std::to_string(CStringRoll), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [BananaHammockCheck] Odds = " + std::to_string(Odds), Logger::LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [BananaHammockCheck] IsTransparent = " + BoolToString(IsTransparent), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [BananaHammockCheck] RiskLevel = " + FlashRiskToString(Level), Logger::LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [BananaHammockCheck] Function Return Value: Is Covering? " + BoolToString(CStringRoll > Odds), Logger::LogType::PlayerArmorScan);

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

	void AnalyzeBananaHammock(bool HasBananaHammockT, UINT8 BananaHammockRiskLevel) {
		PlayerCoverage::GenitalCover = BananaHammockCheck(HasBananaHammockT, BananaHammockRiskLevel);
		PlayerCoverage::UnderwearCover = !PlayerCoverage::GenitalCover;
	}

	void AnalyzeUnderwear
	(
		bool HasUnderwear, bool HasUnderwearT, UINT8 UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, UINT8 ThongRiskLevel, bool HasThongNoCover,
		bool HasBananaHammock, bool HasBananaHammockT, UINT8 BananaHammockRiskLevel
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
		else if (HasBananaHammock || HasBananaHammockT) {
			PlayerCoverage::AssCover = false;
			AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
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
		bool HasHimbo, bool HasHimboT, UINT8 HimboRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, UINT8 UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, UINT8 ThongRiskLevel, bool HasThongNoCover,
		bool HasBananaHammock, bool HasBananaHammockT, UINT8 BananaHammockRiskLevel
	) {
		if (HasHotpants && HasHimbo) {
			PlayerCoverage::AssCover = true;
			PlayerCoverage::GenitalCover = true;
			PlayerCoverage::UnderwearCover = true;
		}
		else if (HasHotpants && HasHimboT) {
			PlayerCoverage::GenitalCover = true;

			if (HasUnderwear) {
				PlayerCoverage::AssCover = true;
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
			}
			else if (HasUnderwearT) {
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
				if (PlayerCoverage::UnderwearCover) {
					PlayerCoverage::AssCover = true;
				}
				else {
					PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
			}
			else if (HasUnderwearNoCover) {
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
				PlayerCoverage::AssCover = PlayerCoverage::UnderwearCover;
			}
			else {
				PlayerCoverage::UnderwearCover = true;
				PlayerCoverage::AssCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
			}
		}
		else if (HasHotpantsT && HasHimbo) {
			PlayerCoverage::AssCover = true;

			if (HasUnderwear || HasThong) {
				PlayerCoverage::GenitalCover = true;
				PlayerCoverage::UnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			}
			else if (HasUnderwearT || HasThongT || HasBananaHammock || HasBananaHammockT) {
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
						AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
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
		else if (HasHotpantsT && HasHimboT) {
			bool HotpantsCovering = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			bool HimboCovering = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);

			if (HotpantsCovering && HimboCovering) {
				PlayerCoverage::AssCover = true;
				PlayerCoverage::GenitalCover = true;
				PlayerCoverage::UnderwearCover = true;
			}
			else if (HotpantsCovering && !HimboCovering) {
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
			else if (!HotpantsCovering && HimboCovering) {
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
				else if (HasBananaHammock || HasBananaHammockT) {
					AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
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
					HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
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
		else if (HasHimbo) {
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
			else if (HasBananaHammock || HasBananaHammockT) {
				AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
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
					HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
				);
			}
		}
		else if (HasHimboT) {
			bool HimboCovering = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);

			if (HimboCovering) {
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
				else if (HasBananaHammock || HasBananaHammockT) {
					AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
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
					HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
				);
			}
		}
		else {
			AnalyzeUnderwear
			(
				HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
				HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
				HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
			);
		}
	}

	void AnalyzeBottom
	(
		bool HasPelvicCurtain, bool HasPelvicCurtainT, UINT8 PelvicRiskLevel,
		bool HasAsscurtain, bool HasAssCurtainT, UINT8 AssRiskLevel,
		bool HasArmorBottom, bool HasArmorBottomT, UINT8 BottomRiskLevel,
		bool HasHotpants, bool HasHotpantsT, UINT8 HotpantsRiskLevel,
		bool HasHimbo, bool HasHimboT, UINT8 HimboRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, UINT8 UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, UINT8 ThongRiskLevel, bool HasThongNoCover,
		bool HasBananaHammock, bool HasBananaHammockT, UINT8 BananaHammockRiskLevel
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
					HasHimbo, HasHimboT, HimboRiskLevel,
					HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
					HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
					HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
				);
			}
		}
		else {
			SubAnalyzeBottom
			(
				HasHotpants, HasHotpantsT, HotpantsRiskLevel,
				HasHimbo, HasHimboT, HimboRiskLevel,
				HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
				HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
				HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
			);
		}
	}

	void Finalize() {
		//Top Conditions

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
				if (PlayerWornHasKeyword(MaleKeywords[ArmorTopT_Low_Male]) || PlayerWornHasKeyword(MaleKeywords[ArmorTopT_Male]) || PlayerWornHasKeyword(MaleKeywords[ArmorTopT_High_Male])
					|| PlayerWornHasKeyword(MaleKeywords[ArmorTop_NoCover_Male]) || PlayerWornHasKeyword(MaleKeywords[NipplePasties_Male])) {
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

		//Bottom Conditions

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
					PlayerWornHasKeyword(MaleKeywords[ArmorBottom_NoCover_Male]) ||
					PlayerWornHasKeyword(MaleKeywords[HotpantsT_Low_Male]) || PlayerWornHasKeyword(MaleKeywords[HotpantsT_Male]) || PlayerWornHasKeyword(MaleKeywords[HotpantsT_High_Male]) ||
					PlayerWornHasKeyword(MaleKeywords[HimboSkirtT_Low]) || PlayerWornHasKeyword(MaleKeywords[HimboSkirtT]) || PlayerWornHasKeyword(MaleKeywords[HimboSkirtT_High]) ||
					PlayerWornHasKeyword(MaleKeywords[Microskirt_Male])
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

		if (Player->GetFactionRank(ToplessFaction, true) == 1 && Player->GetFactionRank(BottomlessFaction, true) == 1 && !PlayerWornHasKeyword(MaleKeywords[NearlyNaked_Male])) {
			SetPlayerFactionRank(NudeFaction, 1);
		}
		else {
			SetPlayerFactionRank(NudeFaction, 0);
		}

		Log("<C++ MaleArmorScan> [Finalize] Nude Faction Rank: " + std::to_string(Player->GetFactionRank(NudeFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Topless Faction Rank: " + std::to_string(Player->GetFactionRank(ToplessFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Bottomless Faction Rank: " + std::to_string(Player->GetFactionRank(BottomlessFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Bra Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingBraFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Chest Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingChestFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Underwear Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingUnderwearFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Genitals Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingGenitalsFaction, true)), Logger::LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Ass Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingAssFaction, true)), Logger::LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [Finalize] Player Male Scan Completed", Logger::LogType::PlayerArmorScan);
	}

	bool VanillaArmorCheck() {
		Log("<C++ MaleArmorScan> [VanillaArmorCheck] START", Logger::LogType::PlayerArmorScan);

		RE::TESBoundObject* BodyArmor = Player->GetWornArmor(RE::BIPED_MODEL::BipedObjectSlot::kBody);

		if (BodyArmor) {
			const auto BodyItem = AsKeywordForm(BodyArmor);

			bool HasCurtainKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[ChestCurtain_Male]) || BodyItem->HasKeyword(MaleKeywords[ChestCurtainT_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[PelvicCurtain_Male]) || BodyItem->HasKeyword(MaleKeywords[PelvicCurtainT_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[AssCurtain_Male]) || BodyItem->HasKeyword(MaleKeywords[AssCurtainT_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[Miniskirt_Male]) || BodyItem->HasKeyword(MaleKeywords[MiniskirtT_Male])
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: " + BoolToString(HasCurtainKeyword), Logger::LogType::PlayerArmorScan);

			bool HasTopKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[ArmorTop_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorTopT_Low_Male]) || BodyItem->HasKeyword(MaleKeywords[ArmorTopT_Male]) || BodyItem->HasKeyword(MaleKeywords[ArmorTopT_High_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorTop_NoCover_Male])
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: " + BoolToString(HasTopKeyword), Logger::LogType::PlayerArmorScan);

			bool HasBottomKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[ArmorBottom_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorBottomT_Low_Male]) || BodyItem->HasKeyword(MaleKeywords[ArmorBottomT_Male]) || BodyItem->HasKeyword(MaleKeywords[ArmorBottomT_High_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorBottom_NoCover_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[Hotpants_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[HotpantsT_Low_Male]) || BodyItem->HasKeyword(MaleKeywords[HotpantsT_Male]) || BodyItem->HasKeyword(MaleKeywords[HotpantsT_High_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[HimboSkirt]) ||
					BodyItem->HasKeyword(MaleKeywords[HimboSkirtT_Low]) || BodyItem->HasKeyword(MaleKeywords[HimboSkirtT]) || BodyItem->HasKeyword(MaleKeywords[HimboSkirtT_High])
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: " + BoolToString(HasBottomKeyword), Logger::LogType::PlayerArmorScan);

			bool HasBraKeyword =
				( 
					BodyItem->HasKeyword(MaleKeywords[Bra_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[BraT_Low_Male]) || BodyItem->HasKeyword(MaleKeywords[BraT_Male]) || BodyItem->HasKeyword(MaleKeywords[BraT_High_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[Bra_NoCover_Male])
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: " + BoolToString(HasBraKeyword), Logger::LogType::PlayerArmorScan);

			bool HasUnderwearKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[Underwear_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[UnderwearT_Low_Male]) || BodyItem->HasKeyword(MaleKeywords[UnderwearT_Male]) || BodyItem->HasKeyword(MaleKeywords[UnderwearT_High_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[Underwear_NoCover_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[Thong_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[ThongT_Low_Male]) || BodyItem->HasKeyword(MaleKeywords[ThongT_Male]) || BodyItem->HasKeyword(MaleKeywords[ThongT_High_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[Thong_NoCover_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[BananaHammock]) ||
					BodyItem->HasKeyword(MaleKeywords[BananaHammockT_Low]) || BodyItem->HasKeyword(MaleKeywords[BananaHammockT]) || BodyItem->HasKeyword(MaleKeywords[BananaHammockT_High])
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: " + BoolToString(HasUnderwearKeyword), Logger::LogType::PlayerArmorScan);

			bool HasExtraKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[NearlyNaked_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[NipplePasties_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[Microskirt_Male]) ||
					BodyItem->HasKeyword(MaleKeywords[EffectivelyNaked_Male])
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: " + BoolToString(HasExtraKeyword), Logger::LogType::PlayerArmorScan);

			Log("<C++ MaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? " + BoolToString(!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword), Logger::LogType::PlayerArmorScan);
			return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
		}
		Log("<C++ MaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? False", Logger::LogType::PlayerArmorScan);
		return false;
	}

	bool IsWearingArmorTop() {
		return IsWearingTwoPartObject(Player, TwoPartObject::ArmorTop_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorTop_Male]);
	}

	UINT8 GetArmorTopRiskLevel() {
		if (IsWearingTwoPartObject(Player, TwoPartObject::ArmorTopT_Low_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorTopT_Low_Male])) {
			return FlashRiskLevel::Low;
		}
		else if (IsWearingTwoPartObject(Player, TwoPartObject::ArmorTopT_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorTopT_Male])) {
			return FlashRiskLevel::Normal;
		}
		else if (IsWearingTwoPartObject(Player, TwoPartObject::ArmorTopT_High_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorTopT_High_Male])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	bool IsWearingBra() {
		return IsWearingTwoPartObject(Player, TwoPartObject::Bra_Male) || PlayerWornHasKeyword(MaleKeywords[Bra_Male]);
	}

	UINT8 GetBraRiskLevel() {
		if (IsWearingTwoPartObject(Player, TwoPartObject::BraT_Low_Male) || PlayerWornHasKeyword(MaleKeywords[BraT_Low_Male])) {
			return FlashRiskLevel::Low;
		}
		else if (IsWearingTwoPartObject(Player, TwoPartObject::BraT_Male) || PlayerWornHasKeyword(MaleKeywords[BraT_Male])) {
			return FlashRiskLevel::Normal;
		}
		else if (IsWearingTwoPartObject(Player, TwoPartObject::BraT_High_Male) || PlayerWornHasKeyword(MaleKeywords[BraT_High_Male])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	bool IsWearingArmorBottom() {
		return IsWearingTwoPartObject(Player, TwoPartObject::ArmorBottom_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorBottom_Male]);
	}

	UINT8 GetArmorBottomRiskLevel() {
		if (IsWearingTwoPartObject(Player, TwoPartObject::ArmorBottomT_Low_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorBottomT_Low_Male])) {
			return FlashRiskLevel::Low;
		}
		else if (IsWearingTwoPartObject(Player, TwoPartObject::ArmorBottomT_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorBottomT_Male])) {
			return FlashRiskLevel::Normal;
		}
		else if (IsWearingTwoPartObject(Player, TwoPartObject::ArmorBottomT_High_Male) || PlayerWornHasKeyword(MaleKeywords[ArmorBottomT_High_Male])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	void MaleAnalyze() {
		Log("<C++ MaleArmorScan> [MaleAnalyze] Player Male Analysis Triggered!", Logger::LogType::PlayerArmorScan);

		ResetFlashingFactions();

		bool ShouldEscape = false;

		if (Player == nullptr || Player->IsPlayerRef() == false) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] RE::Actor variable not set!!!", Logger::LogType::PlayerArmorScan, Logger::LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (PlayerBase == nullptr || PlayerBase->IsPlayer() == false) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] RE::TESActorBase variable not set!!!", Logger::LogType::PlayerArmorScan, Logger::LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (ShouldEscape == true) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] Male Analysis Failed! (Escaped)", Logger::LogType::PlayerArmorScan, Logger::LoggingLevel::critical);
			return;
		}

		Log("<C++ MaleArmorScan> [MaleAnalyze] Start analysis...", Logger::LogType::PlayerArmorScan);
		if (PlayerWornHasKeyword(MaleKeywords[CoversAll_Male]) || IsPlayerTransformed()) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] Covers All keyword detected or player is transformed", Logger::LogType::PlayerArmorScan);

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
			bool HasChestCurtain = PlayerWornHasKeyword(MaleKeywords[ChestCurtain_Male]);
			bool HasChestCurtainT = PlayerWornHasKeyword(MaleKeywords[ChestCurtainT_Male]);

			UINT8 ChestRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskLow_Male])) {
				ChestRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[ChestFlashRisk_Male])) {
				ChestRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskHigh_Male])) {
				ChestRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskExtreme_Male])) {
				ChestRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[ChestFlashRiskUltra_Male])) {
				ChestRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasPelvicCurtain = (PlayerWornHasKeyword(MaleKeywords[PelvicCurtain_Male]) || PlayerWornHasKeyword(MaleKeywords[Miniskirt_Male]));
			bool HasPelvicCurtainT = (PlayerWornHasKeyword(MaleKeywords[PelvicCurtainT_Male]) || PlayerWornHasKeyword(MaleKeywords[MiniskirtT_Male]));

			UINT8 PelvicRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskLow_Male])) {
				PelvicRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[PelvicFlashRisk_Male])) {
				PelvicRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskHigh_Male])) {
				PelvicRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskExtreme_Male])) {
				PelvicRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[PelvicFlashRiskUltra_Male])) {
				PelvicRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasAssCurtain = (PlayerWornHasKeyword(MaleKeywords[AssCurtain_Male]) || PlayerWornHasKeyword(MaleKeywords[Miniskirt_Male]));
			bool HasAssCurtainT = (PlayerWornHasKeyword(MaleKeywords[AssCurtainT_Male]) || PlayerWornHasKeyword(MaleKeywords[MiniskirtT_Male]));

			UINT8 AssRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(MaleKeywords[AssFlashRiskLow_Male])) {
				AssRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[AssFlashRisk_Male])) {
				AssRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[AssFlashRiskHigh_Male])) {
				AssRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[AssFlashRiskExtreme_Male])) {
				AssRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(MaleKeywords[AssFlashRiskUltra_Male])) {
				AssRiskLevel = FlashRiskLevel::Ultra;
			}

			Log("<C++ MaleArmorScan> [MaleAnalyze] HasChestCurtain = " + BoolToString(HasChestCurtain), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasChestCurtainT = " + BoolToString(HasChestCurtainT), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] ChestRiskLevel = " + BoolToString(ChestRiskLevel), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasPelvicCurtain = " + BoolToString(HasPelvicCurtain), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasPelvicCurtainT = " + BoolToString(HasPelvicCurtainT), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] PelvicRiskLevel = " + BoolToString(PelvicRiskLevel), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasAssCurtain = " + BoolToString(HasAssCurtain), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasAssCurtainT = " + BoolToString(HasAssCurtainT), Logger::LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] AssRiskLevel = " + BoolToString(AssRiskLevel), Logger::LogType::PlayerArmorScan);

			if (VanillaArmorCheck() == true) {
				Log("<C++ MaleArmorScan> [MaleAnalyze] Armor is considered vanilla", Logger::LogType::PlayerArmorScan);

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
				bool HasArmorTop = IsWearingArmorTop();
				UINT8 TopRiskLevel = GetArmorTopRiskLevel();
				bool HasArmorTopT = TopRiskLevel;

				//Bra
				bool HasBra = IsWearingBra();
				UINT8 BraRiskLevel = GetBraRiskLevel();
				bool HasBraT = BraRiskLevel;
				bool HasBraNoCover = PlayerWornHasKeyword(MaleKeywords[Bra_NoCover_Male]);

				/*
				================
				BOTTOM VARIABLES
				================
				*/

				//Bottom Armor
				bool HasArmorBottom = IsWearingArmorBottom();
				UINT8 BottomRiskLevel = GetArmorBottomRiskLevel();
				bool HasArmorBottomT = BottomRiskLevel;

				//Hotpants
				bool HasHotpants = PlayerWornHasKeyword(MaleKeywords[Hotpants_Male]);
				UINT8 HotpantsRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(MaleKeywords[HotpantsT_Low_Male])) {
					HotpantsRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[HotpantsT_Male])) {
					HotpantsRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[HotpantsT_High_Male])) {
					HotpantsRiskLevel = FlashRiskLevel::High;
				}
				bool HasHotpantsT = HotpantsRiskLevel;

				//Himbo Skirt
				bool HasHimbo = PlayerWornHasKeyword(MaleKeywords[HimboSkirt]);
				UINT8 HimboRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(MaleKeywords[HimboSkirtT_Low])) {
					HimboRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[HimboSkirtT])) {
					HimboRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[HimboSkirtT_High])) {
					HimboRiskLevel = FlashRiskLevel::High;
				}
				bool HasHimboT = HimboRiskLevel;

				//Underwear
				bool HasUnderwear = PlayerWornHasKeyword(MaleKeywords[Underwear_Male]);
				UINT8 UnderwearRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(MaleKeywords[UnderwearT_Low_Male])) {
					UnderwearRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[UnderwearT_Male])) {
					UnderwearRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[UnderwearT_High_Male])) {
					UnderwearRiskLevel = FlashRiskLevel::High;
				}
				bool HasUnderwearT = UnderwearRiskLevel;
				bool HasUnderwearNoCover = PlayerWornHasKeyword(MaleKeywords[Underwear_NoCover_Male]);

				//Thong
				bool HasThong = PlayerWornHasKeyword(MaleKeywords[Thong_Male]);
				UINT8 ThongRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(MaleKeywords[ThongT_Low_Male])) {
					ThongRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[ThongT_Male])) {
					ThongRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[ThongT_High_Male])) {
					ThongRiskLevel = FlashRiskLevel::High;
				}
				bool HasThongT = ThongRiskLevel;
				bool HasThongNoCover = PlayerWornHasKeyword(MaleKeywords[Thong_NoCover_Male]);

				//BananaHammock
				bool HasBananaHammock = PlayerWornHasKeyword(MaleKeywords[BananaHammock]);
				UINT8 BananaHammockRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(MaleKeywords[BananaHammockT_Low])) {
					BananaHammockRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[BananaHammockT])) {
					BananaHammockRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(MaleKeywords[BananaHammockT_High])) {
					BananaHammockRiskLevel = FlashRiskLevel::High;
				}
				bool HasBananaHammockT = BananaHammockRiskLevel;

				//Debug Results
				//Top
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorTop = " + BoolToString(HasArmorTop), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorTopT = " + BoolToString(HasArmorTopT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] TopRiskLevel = " + BoolToString(TopRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBra = " + BoolToString(HasBra), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBraT = " + BoolToString(HasBraT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] BraRiskLevel = " + BoolToString(BraRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBraNoCover = " + BoolToString(HasBraNoCover), Logger::LogType::PlayerArmorScan);

				//Bottom
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorBottom = " + BoolToString(HasArmorBottom), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorBottomT = " + BoolToString(HasArmorBottomT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] BottomRiskLevel = " + BoolToString(BottomRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHotpants = " + BoolToString(HasHotpants), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHotpantsT = " + BoolToString(HasHotpantsT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HotpantsRiskLevel = " + BoolToString(HotpantsRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHimbo = " + BoolToString(HasHimbo), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHimboT = " + BoolToString(HasHimboT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HimboRiskLevel = " + BoolToString(HimboRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwear = " + BoolToString(HasUnderwear), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwearT = " + BoolToString(HasUnderwearT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] UnderwearRiskLevel = " + BoolToString(UnderwearRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwearNoCover = " + BoolToString(HasUnderwearNoCover), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasThong = " + BoolToString(HasThong), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasThongT = " + BoolToString(HasThongT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] ThongRiskLevel = " + BoolToString(ThongRiskLevel), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasThongNoCover = " + BoolToString(HasThongNoCover), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBananaHammock = " + BoolToString(HasBananaHammock), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBananaHammockT = " + BoolToString(HasBananaHammockT), Logger::LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] BananaHammockRiskLevel = " + BoolToString(BananaHammockRiskLevel), Logger::LogType::PlayerArmorScan);

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
					HasHimbo, HasHimboT, HimboRiskLevel,
					HasUnderwear, HasUnderwearT, UnderwearRiskLevel, HasUnderwearNoCover,
					HasThong, HasThongT, ThongRiskLevel, HasThongNoCover,
					HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
				);
			}
		}

		Finalize();

		SLSFRNakedCommentPrecheck();

		Log("<C++ MaleArmorScan> [MaleAnalyze] Analysis Succeeded!", Logger::LogType::PlayerArmorScan);
	}
}

void ExternalMaleAnalyze(RE::StaticFunctionTag*) {
	MaleArmorScan::MaleAnalyze();
}