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

	bool CurtainCheck(int Type, bool IsTransparent, int Level) {
		Log("<C++ MaleArmorScan> [CurtainCheck] START", LogType::PlayerArmorScan);

		int Roll = 0;
		int Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Chest) {
			TypeString = "Chest";
			Roll = ChestCurtainRoll;
			if (Level == FlashRiskLevel::Low) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsLow_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsLow_Male];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOdds_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOdds_Male];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsHigh_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsHigh_Male];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[ChestCurtainOddsExtreme_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentChestCurtainOddsExtreme_Male];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (IsTransparent) {
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
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsLow_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsLow_Male];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOdds_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOdds_Male];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsHigh_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsHigh_Male];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[PelvicCurtainOddsExtreme_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentPelvicCurtainOddsExtreme_Male];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (IsTransparent) {
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
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsLow_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsLow_Male];
				}
			}
			else if (Level == FlashRiskLevel::Normal) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOdds_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOdds_Male];
				}
			}
			else if (Level == FlashRiskLevel::High) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsHigh_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsHigh_Male];
				}
			}
			else if (Level == FlashRiskLevel::Extreme) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsExtreme_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsExtreme_Male];
				}
			}
			else if (Level == FlashRiskLevel::Ultra) {
				if (IsTransparent) {
					Odds = Configuration::FlashingOdds[AssCurtainOddsUltra_Male];
				}
				else {
					Odds = Configuration::FlashingOdds[TransparentAssCurtainOddsUltra_Male];
				}
			}
		}

		Log("<C++ MaleArmorScan> [CurtainCheck] Roll = " + std::to_string(Roll), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [CurtainCheck] Odds = " + std::to_string(Odds), LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [CurtainCheck] Type = " + TypeString);
		Log("<C++ MaleArmorScan> [CurtainCheck] Is Transparent = " + BoolToString(IsTransparent), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [CurtainCheck] Risk Level = " + FlashRiskToString(Level), LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), LogType::PlayerArmorScan);

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

		Log("<C++ MaleArmorScan> [TransparentItemCheck] Roll = " + std::to_string(Roll), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [TransparentItemCheck] Odds = " + std::to_string(Odds), LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [TransparentItemCheck] Type = " + TypeString, LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [TransparentItemCheck] Risk Level = " + FlashRiskToString(Level), LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), LogType::PlayerArmorScan);

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

	bool BananaHammockCheck(bool IsTransparent, int Level) {
		int Odds = 0;

		if (IsTransparent == false) {
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

		Log("<C++ MaleArmorScan> [BananaHammockCheck] Roll = " + std::to_string(CStringRoll), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [BananaHammockCheck] Odds = " + std::to_string(Odds), LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [BananaHammockCheck] IsTransparent = " + BoolToString(IsTransparent), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [BananaHammockCheck] RiskLevel = " + FlashRiskToString(Level), LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [BananaHammockCheck] Function Return Value: Is Covering? " + BoolToString(CStringRoll > Odds), LogType::PlayerArmorScan);

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

	void AnalyzeBananaHammock(bool HasBananaHammockT, int BananaHammockRiskLevel) {
		PlayerCoverage::GenitalCover = BananaHammockCheck(HasBananaHammockT, BananaHammockRiskLevel);
		PlayerCoverage::UnderwearCover = !PlayerCoverage::GenitalCover;
	}

	void AnalyzeUnderwear
	(
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasBananaHammock, bool HasBananaHammockT, int BananaHammockRiskLevel
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
		bool HasHotpants, bool HasHotpantsT, int HotpantsRiskLevel,
		bool HasHimbo, bool HasHimboT, int HimboRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasBananaHammock, bool HasBananaHammockT, int BananaHammockRiskLevel
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
		bool HasPelvicCurtain, bool HasPelvicCurtainT, int PelvicRiskLevel,
		bool HasAsscurtain, bool HasAssCurtainT, int AssRiskLevel,
		bool HasArmorBottom, bool HasArmorBottomT, int BottomRiskLevel,
		bool HasHotpants, bool HasHotpantsT, int HotpantsRiskLevel,
		bool HasHimbo, bool HasHimboT, int HimboRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasBananaHammock, bool HasBananaHammockT, int BananaHammockRiskLevel
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
				if (PlayerWornHasKeyword(ArmorTopT_Low_Male) || PlayerWornHasKeyword(ArmorTopT_Male) || PlayerWornHasKeyword(ArmorTopT_High_Male)
					|| PlayerWornHasKeyword(ArmorTop_NoCover_Male) || PlayerWornHasKeyword(NipplePasties_Male)) {
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
					PlayerWornHasKeyword(ArmorBottom_NoCover_Male) ||
					PlayerWornHasKeyword(HotpantsT_Low_Male) || PlayerWornHasKeyword(HotpantsT_Male) || PlayerWornHasKeyword(HotpantsT_High_Male) ||
					PlayerWornHasKeyword(HimboSkirtT_Low) || PlayerWornHasKeyword(HimboSkirtT) || PlayerWornHasKeyword(HimboSkirtT_High) ||
					PlayerWornHasKeyword(Microskirt_Male)
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

		Log("<C++ MaleArmorScan> [Finalize] Nude Faction Rank: " + std::to_string(Player->GetFactionRank(NudeFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Topless Faction Rank: " + std::to_string(Player->GetFactionRank(ToplessFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Bottomless Faction Rank: " + std::to_string(Player->GetFactionRank(BottomlessFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Bra Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingBraFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Chest Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingChestFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Underwear Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingUnderwearFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Genitals Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingGenitalsFaction, true)), LogType::PlayerArmorScan);
		Log("<C++ MaleArmorScan> [Finalize] Showing Ass Faction Rank: " + std::to_string(Player->GetFactionRank(ShowingAssFaction, true)), LogType::PlayerArmorScan);

		Log("<C++ MaleArmorScan> [Finalize] Player Female Scan Completed", LogType::PlayerArmorScan);
	}

	bool VanillaArmorCheck() {
		Log("<C++ MaleArmorScan> [VanillaArmorCheck] START", LogType::PlayerArmorScan);

		RE::TESBoundObject* BodyArmor = Player->GetWornArmor(RE::BIPED_MODEL::BipedObjectSlot::kBody);

		if (BodyArmor) {
			const auto BodyItem = AsKeywordForm(BodyArmor);

			bool HasCurtainKeyword =
				(
					BodyItem->HasKeyword(ChestCurtain_Male) || BodyItem->HasKeyword(ChestCurtainT_Male) ||
					BodyItem->HasKeyword(PelvicCurtain_Male) || BodyItem->HasKeyword(PelvicCurtainT_Male) ||
					BodyItem->HasKeyword(AssCurtain_Male) || BodyItem->HasKeyword(AssCurtainT_Male) ||
					BodyItem->HasKeyword(Miniskirt_Male) || BodyItem->HasKeyword(MiniskirtT_Male)
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: " + BoolToString(HasCurtainKeyword), LogType::PlayerArmorScan);

			bool HasTopKeyword =
				(
					BodyItem->HasKeyword(ArmorTop_Male) ||
					BodyItem->HasKeyword(ArmorTopT_Low_Male) || BodyItem->HasKeyword(ArmorTopT_Male) || BodyItem->HasKeyword(ArmorTopT_High_Male) ||
					BodyItem->HasKeyword(ArmorTop_NoCover_Male)
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: " + BoolToString(HasTopKeyword), LogType::PlayerArmorScan);

			bool HasBottomKeyword =
				(
					BodyItem->HasKeyword(ArmorBottom_Male) ||
					BodyItem->HasKeyword(ArmorBottomT_Low_Male) || BodyItem->HasKeyword(ArmorBottomT_Male) || BodyItem->HasKeyword(ArmorBottomT_High_Male) ||
					BodyItem->HasKeyword(ArmorBottom_NoCover_Male) ||
					BodyItem->HasKeyword(Hotpants_Male) ||
					BodyItem->HasKeyword(HotpantsT_Low_Male) || BodyItem->HasKeyword(HotpantsT_Male) || BodyItem->HasKeyword(HotpantsT_High_Male) ||
					BodyItem->HasKeyword(HimboSkirt) ||
					BodyItem->HasKeyword(HimboSkirtT_Low) || BodyItem->HasKeyword(HimboSkirtT) || BodyItem->HasKeyword(HimboSkirtT_High)
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: " + BoolToString(HasBottomKeyword), LogType::PlayerArmorScan);

			bool HasBraKeyword =
				(
					BodyItem->HasKeyword(Bra_Male) ||
					BodyItem->HasKeyword(BraT_Low_Male) || BodyItem->HasKeyword(BraT_Male) || BodyItem->HasKeyword(BraT_High_Male) ||
					BodyItem->HasKeyword(Bra_NoCover_Male)
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: " + BoolToString(HasBraKeyword), LogType::PlayerArmorScan);

			bool HasUnderwearKeyword =
				(
					BodyItem->HasKeyword(Underwear_Male) ||
					BodyItem->HasKeyword(UnderwearT_Low_Male) || BodyItem->HasKeyword(UnderwearT_Male) || BodyItem->HasKeyword(UnderwearT_High_Male) ||
					BodyItem->HasKeyword(Underwear_NoCover_Male) ||
					BodyItem->HasKeyword(Thong_Male) ||
					BodyItem->HasKeyword(ThongT_Low_Male) || BodyItem->HasKeyword(ThongT_Male) || BodyItem->HasKeyword(ThongT_High_Male) ||
					BodyItem->HasKeyword(Thong_NoCover_Male) ||
					BodyItem->HasKeyword(BananaHammock) ||
					BodyItem->HasKeyword(BananaHammockT_Low) || BodyItem->HasKeyword(BananaHammockT) || BodyItem->HasKeyword(BananaHammockT_High)
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: " + BoolToString(HasUnderwearKeyword), LogType::PlayerArmorScan);

			bool HasExtraKeyword =
				(
					BodyItem->HasKeyword(NearlyNaked_Male) ||
					BodyItem->HasKeyword(NipplePasties_Male) ||
					BodyItem->HasKeyword(Microskirt_Male) ||
					BodyItem->HasKeyword(EffectivelyNaked_Male)
					);
			Log("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: " + BoolToString(HasExtraKeyword), LogType::PlayerArmorScan);

			Log("<C++ MaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? " + BoolToString(!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword), LogType::PlayerArmorScan);
			return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
		}
		Log("<C++ MaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? False", LogType::PlayerArmorScan);
		return false;
	}

	void MaleAnalyze() {
		Log("<C++ MaleArmorScan> [MaleAnalyze] Player Male Analysis Triggered!", LogType::PlayerArmorScan);

		ResetFlashingFactions();

		bool ShouldEscape = false;

		if (Player == nullptr || Player->IsPlayerRef() == false) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] RE::Actor variable not set!!!", LogType::PlayerArmorScan, LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (PlayerBase == nullptr || PlayerBase->IsPlayer() == false) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] RE::TESActorBase variable not set!!!", LogType::PlayerArmorScan, LoggingLevel::critical);
			ShouldEscape = true;
		}

		if (ShouldEscape == true) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] Male Analysis Failed! (Escaped)", LogType::PlayerArmorScan, LoggingLevel::critical);
			return;
		}

		Log("<C++ MaleArmorScan> [MaleAnalyze] Start analysis...", LogType::PlayerArmorScan);
		if (PlayerWornHasKeyword(CoversAll_Male)) {
			Log("<C++ MaleArmorScan> [MaleAnalyze] Covers All keyword detected", LogType::PlayerArmorScan);

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
			bool HasChestCurtain = PlayerWornHasKeyword(ChestCurtain_Male);
			bool HasChestCurtainT = PlayerWornHasKeyword(ChestCurtainT_Male);

			int ChestRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(ChestFlashRiskLow_Male)) {
				ChestRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(ChestFlashRisk_Male)) {
				ChestRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(ChestFlashRiskHigh_Male)) {
				ChestRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(ChestFlashRiskExtreme_Male)) {
				ChestRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(ChestFlashRiskUltra_Male)) {
				ChestRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain_Male) || PlayerWornHasKeyword(Miniskirt_Male));
			bool HasPelvicCurtainT = (PlayerWornHasKeyword(PelvicCurtainT_Male) || PlayerWornHasKeyword(MiniskirtT_Male));

			int PelvicRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(PelvicFlashRiskLow_Male)) {
				PelvicRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRisk_Male)) {
				PelvicRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRiskHigh_Male)) {
				PelvicRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRiskExtreme_Male)) {
				PelvicRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(PelvicFlashRiskUltra_Male)) {
				PelvicRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasAssCurtain = (PlayerWornHasKeyword(AssCurtain_Male) || PlayerWornHasKeyword(Miniskirt_Male));
			bool HasAssCurtainT = (PlayerWornHasKeyword(AssCurtainT_Male) || PlayerWornHasKeyword(MiniskirtT_Male));

			int AssRiskLevel = FlashRiskLevel::None;
			if (PlayerWornHasKeyword(AssFlashRiskLow_Male)) {
				AssRiskLevel = FlashRiskLevel::Low;
			}
			else if (PlayerWornHasKeyword(AssFlashRisk_Male)) {
				AssRiskLevel = FlashRiskLevel::Normal;
			}
			else if (PlayerWornHasKeyword(AssFlashRiskHigh_Male)) {
				AssRiskLevel = FlashRiskLevel::High;
			}
			else if (PlayerWornHasKeyword(AssFlashRiskExtreme_Male)) {
				AssRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (PlayerWornHasKeyword(AssFlashRiskUltra_Male)) {
				AssRiskLevel = FlashRiskLevel::Ultra;
			}

			Log("<C++ MaleArmorScan> [MaleAnalyze] HasChestCurtain = " + BoolToString(HasChestCurtain), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasChestCurtainT = " + BoolToString(HasChestCurtainT), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] ChestRiskLevel = " + BoolToString(ChestRiskLevel), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasPelvicCurtain = " + BoolToString(HasPelvicCurtain), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasPelvicCurtainT = " + BoolToString(HasPelvicCurtainT), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] PelvicRiskLevel = " + BoolToString(PelvicRiskLevel), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasAssCurtain = " + BoolToString(HasAssCurtain), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] HasAssCurtainT = " + BoolToString(HasAssCurtainT), LogType::PlayerArmorScan);
			Log("<C++ MaleArmorScan> [MaleAnalyze] AssRiskLevel = " + BoolToString(AssRiskLevel), LogType::PlayerArmorScan);

			if (VanillaArmorCheck() == true) {
				Log("<C++ MaleArmorScan> [MaleAnalyze] Armor is considered vanilla", LogType::PlayerArmorScan);

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
				bool HasArmorTop = PlayerWornHasKeyword(ArmorTop_Male);
				int TopRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(ArmorTopT_Low_Male)) {
					TopRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(ArmorTopT_Male)) {
					TopRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(ArmorTopT_High_Male)) {
					TopRiskLevel = FlashRiskLevel::High;
				}
				bool HasArmorTopT = TopRiskLevel > FlashRiskLevel::None;

				//Bra
				bool HasBra = PlayerWornHasKeyword(Bra_Male);
				int BraRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(BraT_Low_Male)) {
					BraRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(BraT_Male)) {
					BraRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(BraT_High_Male)) {
					BraRiskLevel = FlashRiskLevel::High;
				}
				bool HasBraT = BraRiskLevel > FlashRiskLevel::None;
				bool HasBraNoCover = PlayerWornHasKeyword(Bra_NoCover_Male);

				/*
				================
				BOTTOM VARIABLES
				================
				*/

				//Bottom Armor
				bool HasArmorBottom = PlayerWornHasKeyword(ArmorBottom_Male);
				int BottomRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(ArmorBottomT_Low_Male)) {
					BottomRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(ArmorBottomT_Male)) {
					BottomRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(ArmorBottomT_High_Male)) {
					BottomRiskLevel = FlashRiskLevel::High;
				}
				bool HasArmorBottomT = BottomRiskLevel > FlashRiskLevel::None;

				//Hotpants
				bool HasHotpants = PlayerWornHasKeyword(Hotpants_Male);
				int HotpantsRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(HotpantsT_Low_Male)) {
					HotpantsRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(HotpantsT_Male)) {
					HotpantsRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(HotpantsT_High_Male)) {
					HotpantsRiskLevel = FlashRiskLevel::High;
				}
				bool HasHotpantsT = HotpantsRiskLevel > FlashRiskLevel::None;

				//Himbo Skirt
				bool HasHimbo = PlayerWornHasKeyword(HimboSkirt);
				int HimboRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(HimboSkirtT_Low)) {
					HimboRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(HimboSkirtT)) {
					HimboRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(HimboSkirtT_High)) {
					HimboRiskLevel = FlashRiskLevel::High;
				}
				bool HasHimboT = HimboRiskLevel > FlashRiskLevel::None;

				//Underwear
				bool HasUnderwear = PlayerWornHasKeyword(Underwear_Male);
				int UnderwearRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(UnderwearT_Low_Male)) {
					UnderwearRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(UnderwearT_Male)) {
					UnderwearRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(UnderwearT_High_Male)) {
					UnderwearRiskLevel = FlashRiskLevel::High;
				}
				bool HasUnderwearT = UnderwearRiskLevel > FlashRiskLevel::None;
				bool HasUnderwearNoCover = PlayerWornHasKeyword(Underwear_NoCover_Male);

				//Thong
				bool HasThong = PlayerWornHasKeyword(Thong_Male);
				int ThongRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(ThongT_Low_Male)) {
					ThongRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(ThongT_Male)) {
					ThongRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(ThongT_High_Male)) {
					ThongRiskLevel = FlashRiskLevel::High;
				}
				bool HasThongT = ThongRiskLevel > FlashRiskLevel::None;
				bool HasThongNoCover = PlayerWornHasKeyword(Thong_NoCover_Male);

				//BananaHammock
				bool HasBananaHammock = PlayerWornHasKeyword(BananaHammock);
				int BananaHammockRiskLevel = FlashRiskLevel::None;
				if (PlayerWornHasKeyword(BananaHammockT_Low)) {
					BananaHammockRiskLevel = FlashRiskLevel::Low;
				}
				else if (PlayerWornHasKeyword(BananaHammockT)) {
					BananaHammockRiskLevel = FlashRiskLevel::Normal;
				}
				else if (PlayerWornHasKeyword(BananaHammockT_High)) {
					BananaHammockRiskLevel = FlashRiskLevel::High;
				}
				bool HasBananaHammockT = BananaHammockRiskLevel > FlashRiskLevel::None;

				//Debug Results
				//Top
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorTop = " + BoolToString(HasArmorTop), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorTopT = " + BoolToString(HasArmorTopT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] TopRiskLevel = " + BoolToString(TopRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBra = " + BoolToString(HasBra), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBraT = " + BoolToString(HasBraT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] BraRiskLevel = " + BoolToString(BraRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBraNoCover = " + BoolToString(HasBraNoCover), LogType::PlayerArmorScan);

				//Bottom
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorBottom = " + BoolToString(HasArmorBottom), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasArmorBottomT = " + BoolToString(HasArmorBottomT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] BottomRiskLevel = " + BoolToString(BottomRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHotpants = " + BoolToString(HasHotpants), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHotpantsT = " + BoolToString(HasHotpantsT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HotpantsRiskLevel = " + BoolToString(HotpantsRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHimbo = " + BoolToString(HasHimbo), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasHimboT = " + BoolToString(HasHimboT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HimboRiskLevel = " + BoolToString(HimboRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwear = " + BoolToString(HasUnderwear), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwearT = " + BoolToString(HasUnderwearT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] UnderwearRiskLevel = " + BoolToString(UnderwearRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwearNoCover = " + BoolToString(HasUnderwearNoCover), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasThong = " + BoolToString(HasThong), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasThongT = " + BoolToString(HasThongT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] ThongRiskLevel = " + BoolToString(ThongRiskLevel), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasThongNoCover = " + BoolToString(HasThongNoCover), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBananaHammock = " + BoolToString(HasBananaHammock), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] HasBananaHammockT = " + BoolToString(HasBananaHammockT), LogType::PlayerArmorScan);
				Log("<C++ MaleArmorScan> [MaleAnalyze] BananaHammockRiskLevel = " + BoolToString(BananaHammockRiskLevel), LogType::PlayerArmorScan);

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
		Log("<C++ MaleArmorScan> [MaleAnalyze] Analysis Succeeded!", LogType::PlayerArmorScan);
	}
}
void ExternalMaleAnalyze(RE::StaticFunctionTag*) {
	MaleArmorScan::MaleAnalyze();
}