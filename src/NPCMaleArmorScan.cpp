#include "Core.h"
#include "Config.h"
#include "Logger.h"
#include "NPCArmorScan.h"

namespace NPCMaleScan {
	bool NPCTopCurtainCover = false;
	bool NPCPelvicCurtainCover = false;
	bool NPCAssCurtainCover = false;

	bool NPCChestCover = false;
	bool NPCBraCover = false;

	bool NPCAssCover = false;
	bool NPCGenitalCover = false;
	bool NPCUnderwearCover = false;

	RE::Actor* thisActor;

	void ResetFlashingFactions() {
		SetActorFactionRank(thisActor, FlashingChestCurtainFaction, 0);
		SetActorFactionRank(thisActor, FlashingPelvicCurtainFaction, 0);
		SetActorFactionRank(thisActor, FlashingAssCurtainFaction, 0);

		SetActorFactionRank(thisActor, FlashingTopArmorFaction, 0);
		SetActorFactionRank(thisActor, FlashingBottomArmorFaction, 0);
		SetActorFactionRank(thisActor, FlashingBraFaction, 0);
		SetActorFactionRank(thisActor, FlashingUnderwearFaction, 0);
		SetActorFactionRank(thisActor, FlashingCStringFaction, 0);
		SetActorFactionRank(thisActor, FlashingHotpantsFaction, 0);
		SetActorFactionRank(thisActor, FlashingShowgirlSkirtFaction, 0);
	}

	bool CurtainCheck(UINT8 Type, bool IsTransparent, UINT8 Level) {
		Log("<C++ NPCMaleArmorScan> [CurtainCheck] START");

		INT8 Roll = 0;
		INT8 Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Chest) {
			TypeString = "Chest";
			Roll = NPCChestCurtainRoll;
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
			Roll = NPCPelvicCurtainRoll;
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
			Roll = NPCAssCurtainRoll;
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

		Log("<C++ NPCMaleArmorScan> [CurtainCheck] Roll = " + std::to_string(Roll), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [CurtainCheck] Odds = " + std::to_string(Odds), Logger::LogType::NPCArmorScan);

		Log("<C++ NPCMaleArmorScan> [CurtainCheck] Type = " + TypeString, Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [CurtainCheck] IsTransparent = " + BoolToString(IsTransparent), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [CurtainCheck] RiskLevel = " + FlashRiskToString(Level), Logger::LogType::NPCArmorScan);

		Log("<C++ NPCMaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), Logger::LogType::NPCArmorScan);

		bool Result = (Roll > Odds);

		switch (Type) {
		case FlashRiskType::Chest:
			SetActorFactionRank(thisActor, FlashingChestCurtainFaction, !Result);
			break;
		case FlashRiskType::Pelvic:
			SetActorFactionRank(thisActor, FlashingPelvicCurtainFaction, !Result);
			break;
		case FlashRiskType::Ass:
			SetActorFactionRank(thisActor, FlashingAssCurtainFaction, !Result);
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
			Roll = NPCTopTransparentRoll;
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
			Roll = NPCBottomTransparentRoll;
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
			Roll = NPCBraTransparentRoll;
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

			Roll = NPCUnderwearTransparentRoll;
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
			Roll = NPCHotpantsTransparentRoll;
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
			Roll = NPCShowgirlTransparentRoll;
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

		Log("<C++ NPCMaleArmorScan> [TransparentItemCheck] Roll = " + std::to_string(Roll), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [TransparentItemCheck] Odds = " + std::to_string(Odds), Logger::LogType::NPCArmorScan);

		Log("<C++ NPCMaleArmorScan> [TransparentItemCheck] Type = " + TypeString, Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [TransparentItemCheck] RiskLevel = " + FlashRiskToString(Level), Logger::LogType::NPCArmorScan);

		Log("<C++ NPCMaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), Logger::LogType::NPCArmorScan);

		bool Result = (Roll > Odds);

		switch (Type) {
		case FlashRiskType::Top:
			SetActorFactionRank(thisActor, FlashingTopArmorFaction, !Result);
			break;
		case FlashRiskType::Bottom:
			SetActorFactionRank(thisActor, FlashingBottomArmorFaction, !Result);
			break;
		case FlashRiskType::Bra:
			SetActorFactionRank(thisActor, FlashingBraFaction, !Result);
			break;
		case FlashRiskType::Underwear:
			SetActorFactionRank(thisActor, FlashingUnderwearFaction, !Result);
			break;
		case FlashRiskType::Thong:
			SetActorFactionRank(thisActor, FlashingUnderwearFaction, !Result);
			break;
		case FlashRiskType::Hotpants:
			SetActorFactionRank(thisActor, FlashingHotpantsFaction, !Result);
			break;
		case FlashRiskType::Himbo:
			SetActorFactionRank(thisActor, FlashingShowgirlSkirtFaction, !Result);
			break;
		default:
			break;
		}

		return Result;
	}

	bool BananaHammockCheck(bool IsTransparent, UINT8 Level) {
		INT8 Odds = 0;

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

		Log("<C++ NPCMaleArmorScan> [BananaHammockCheck] Roll = " + std::to_string(NPCCStringRoll), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [BananaHammockCheck] Odds = " + std::to_string(Odds), Logger::LogType::NPCArmorScan);

		Log("<C++ NPCMaleArmorScan> [BananaHammockCheck] IsTransparent = " + BoolToString(IsTransparent), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [BananaHammockCheck] RiskLevel = " + FlashRiskToString(Level), Logger::LogType::NPCArmorScan);

		Log("<C++ NPCMaleArmorScan> [BananaHammockCheck] Function Return Value: Is Covering? " + BoolToString(NPCCStringRoll > Odds), Logger::LogType::NPCArmorScan);

		bool Result = (CStringRoll > Odds);

		SetActorFactionRank(thisActor, FlashingCStringFaction, !Result);

		return Result;
	}

	void AnalyzeBra(bool HasBra, bool HasBraT, UINT8 BraRiskLevel, bool HasBraNoCover) {
		if (HasBra) {
			NPCBraCover = false;
			NPCChestCover = true;
		}
		else if (HasBraT) {
			NPCBraCover = false;
			NPCChestCover = TransparentItemCheck(FlashRiskType::Bra, BraRiskLevel);
		}
		else if (HasBraNoCover) {
			NPCBraCover = false;
			NPCChestCover = false;
		}
		else {
			NPCBraCover = true;
			NPCChestCover = false;
		}
	}

	void AnalyzeTop
	(
		bool HasChestCurtain, bool HasChestCurtainT, UINT8 ChestRiskLevel,
		bool HasArmorTop, bool HasArmorTopT, UINT8 TopRiskLevel,
		bool HasBra, bool HasBraT, UINT8 BraRiskLevel, bool HasBraNoCover
	) {
		if (HasChestCurtain || HasChestCurtainT) {
			NPCTopCurtainCover = CurtainCheck(FlashRiskType::Chest, HasChestCurtainT, ChestRiskLevel);
		}
		else {
			NPCTopCurtainCover = false;
		}

		if (HasArmorTop) {
			NPCBraCover = true;
			NPCChestCover = true;
		}
		else if (HasArmorTopT) {
			bool TopCovering = TransparentItemCheck(FlashRiskType::Top, TopRiskLevel);

			if (TopCovering) {
				NPCBraCover = true;
				NPCChestCover = true;
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
		NPCGenitalCover = BananaHammockCheck(HasBananaHammockT, BananaHammockRiskLevel);
		NPCUnderwearCover = !NPCGenitalCover;
	}

	void AnalyzeUnderwear
	(
		bool HasUnderwear, bool HasUnderwearT, UINT8 UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, UINT8 ThongRiskLevel, bool HasThongNoCover,
		bool HasBananaHammock, bool HasBananaHammockT, UINT8 BananaHammockRiskLevel
	) {
		if (HasUnderwear) {
			NPCUnderwearCover = false;
			NPCAssCover = true;
			NPCGenitalCover = true;
		}
		else if (HasUnderwearT) {
			NPCUnderwearCover = false;
			NPCAssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
			NPCGenitalCover = NPCAssCover;
		}
		else if (HasThong) {
			NPCUnderwearCover = false;
			NPCAssCover = false;
			NPCGenitalCover = true;
		}
		else if (HasThongT) {
			NPCUnderwearCover = false;
			NPCAssCover = false;
			NPCGenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
		}
		else if (HasBananaHammock || HasBananaHammockT) {
			NPCAssCover = false;
			AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
		}
		else if (HasUnderwearNoCover || HasThongNoCover) {
			NPCUnderwearCover = false;
			NPCAssCover = false;
			NPCGenitalCover = false;
		}
		else {
			NPCUnderwearCover = true;
			NPCAssCover = false;
			NPCGenitalCover = false;
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
			NPCAssCover = true;
			NPCGenitalCover = true;
			NPCUnderwearCover = true;
		}
		else if (HasHotpants && HasHimboT) {
			NPCGenitalCover = true;

			if (HasUnderwear) {
				NPCAssCover = true;
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
			}
			else if (HasUnderwearT) {
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
				if (NPCUnderwearCover) {
					NPCAssCover = true;
				}
				else {
					NPCAssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
			}
			else if (HasUnderwearNoCover) {
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
				NPCAssCover = NPCUnderwearCover;
			}
			else {
				NPCUnderwearCover = true;
				NPCAssCover = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);
			}
		}
		else if (HasHotpantsT && HasHimbo) {
			NPCAssCover = true;

			if (HasUnderwear || HasThong) {
				NPCGenitalCover = true;
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			}
			else if (HasUnderwearT || HasThongT || HasBananaHammock || HasBananaHammockT) {
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);

				if (NPCUnderwearCover) {
					NPCGenitalCover = true;
				}
				else {
					if (HasUnderwearT) {
						NPCGenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
					}
					else if (HasThongT) {
						NPCGenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
					}
					else {
						AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
					}
				}
			}
			else if (HasUnderwearNoCover || HasThongNoCover) {
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
				NPCGenitalCover = NPCUnderwearCover;
			}
			else {
				NPCUnderwearCover = true;
				NPCGenitalCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			}
		}
		else if (HasHotpantsT && HasHimboT) {
			bool HotpantsCovering = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			bool HimboCovering = TransparentItemCheck(FlashRiskType::Himbo, HimboRiskLevel);

			if (HotpantsCovering && HimboCovering) {
				NPCAssCover = true;
				NPCGenitalCover = true;
				NPCUnderwearCover = true;
			}
			else if (HotpantsCovering && !HimboCovering) {
				NPCGenitalCover = true;

				if (HasUnderwear) {
					NPCUnderwearCover = false;
					NPCAssCover = true;
				}
				else if (HasUnderwearT) {
					NPCUnderwearCover = false;
					NPCAssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasUnderwearNoCover) {
					NPCUnderwearCover = false;
					NPCAssCover = false;
				}
				else {
					NPCUnderwearCover = true;
					NPCAssCover = false;
				}
			}
			else if (!HotpantsCovering && HimboCovering) {
				NPCAssCover = true;

				if (HasUnderwear || HasThong) {
					NPCUnderwearCover = false;
					NPCGenitalCover = true;
				}
				else if (HasUnderwearT) {
					NPCUnderwearCover = false;
					NPCGenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasThongT) {
					NPCUnderwearCover = false;
					NPCGenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
				}
				else if (HasBananaHammock || HasBananaHammockT) {
					AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
				}
				else if (HasUnderwearNoCover || HasThongNoCover) {
					NPCUnderwearCover = false;
					NPCGenitalCover = false;
				}
				else {
					NPCUnderwearCover = true;
					NPCGenitalCover = false;
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
			NPCGenitalCover = true;

			if (HasUnderwear) {
				NPCUnderwearCover = false;
				NPCAssCover = true;
			}
			else if (HasUnderwearT) {
				NPCUnderwearCover = false;
				NPCAssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
			}
			else if (HasUnderwearNoCover) {
				NPCUnderwearCover = false;
				NPCAssCover = false;
			}
			else {
				NPCUnderwearCover = true;
				NPCAssCover = false;
			}
		}
		else if (HasHimbo) {
			NPCAssCover = true;

			if (HasUnderwear || HasThong) {
				NPCUnderwearCover = false;
				NPCGenitalCover = true;
			}
			else if (HasUnderwearT) {
				NPCUnderwearCover = false;
				NPCGenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
			}
			else if (HasThongT) {
				NPCUnderwearCover = false;
				NPCGenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
			}
			else if (HasBananaHammock || HasBananaHammockT) {
				AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
			}
			else if (HasUnderwearNoCover || HasThongNoCover) {
				NPCUnderwearCover = false;
				NPCGenitalCover = false;
			}
			else {
				NPCUnderwearCover = true;
				NPCGenitalCover = false;
			}
		}
		else if (HasHotpantsT) {
			bool HotpantsCovering = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);

			if (HotpantsCovering) {
				NPCGenitalCover = true;

				if (HasUnderwear) {
					NPCUnderwearCover = false;
					NPCAssCover = true;
				}
				else if (HasUnderwearT) {
					NPCUnderwearCover = false;
					NPCAssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasUnderwearNoCover) {
					NPCUnderwearCover = false;
					NPCAssCover = false;
				}
				else {
					NPCUnderwearCover = true;
					NPCAssCover = false;
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
				NPCAssCover = true;

				if (HasUnderwear || HasThong) {
					NPCUnderwearCover = false;
					NPCGenitalCover = true;
				}
				else if (HasUnderwearT) {
					NPCUnderwearCover = false;
					NPCGenitalCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
				else if (HasThongT) {
					NPCUnderwearCover = false;
					NPCGenitalCover = TransparentItemCheck(FlashRiskType::Thong, ThongRiskLevel);
				}
				else if (HasBananaHammock || HasBananaHammockT) {
					AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
				}
				else if (HasUnderwearNoCover || HasThongNoCover) {
					NPCUnderwearCover = false;
					NPCGenitalCover = false;
				}
				else {
					NPCUnderwearCover = true;
					NPCGenitalCover = false;
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
			NPCPelvicCurtainCover = CurtainCheck(FlashRiskType::Pelvic, HasPelvicCurtainT, PelvicRiskLevel);
		}
		else {
			NPCPelvicCurtainCover = false;
		}

		if (HasAsscurtain || HasAssCurtainT) {
			NPCAssCurtainCover = CurtainCheck(FlashRiskType::Ass, HasAssCurtainT, AssRiskLevel);
		}
		else {
			NPCAssCurtainCover = false;
		}

		if (HasArmorBottom) {
			NPCAssCover = true;
			NPCGenitalCover = true;
			NPCUnderwearCover = true;
		}
		else if (HasArmorBottomT) {
			NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Bottom, BottomRiskLevel);

			if (NPCUnderwearCover) {
				NPCGenitalCover = true;
				NPCAssCover = true;
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
		if (NPCTopCurtainCover) {
			SetActorFactionRank(thisActor, ToplessFaction, 0);
			SetActorFactionRank(thisActor, ShowingChestFaction, 0);
			SetActorFactionRank(thisActor, ShowingBraFaction, 0);
		}
		else {
			if (NPCBraCover && NPCChestCover) {
				SetActorFactionRank(thisActor, ToplessFaction, 0);
				SetActorFactionRank(thisActor, ShowingBraFaction, 0);
				SetActorFactionRank(thisActor, ShowingChestFaction, 0);
			}
			else if (!NPCBraCover && NPCChestCover) {
				SetActorFactionRank(thisActor, ToplessFaction, 0);
				SetActorFactionRank(thisActor, ShowingBraFaction, 1);
				SetActorFactionRank(thisActor, ShowingChestFaction, 0);
			}
			else if (!NPCBraCover && !NPCChestCover) {
				SetActorFactionRank(thisActor, ToplessFaction, 0);
				SetActorFactionRank(thisActor, ShowingBraFaction, 1);
				SetActorFactionRank(thisActor, ShowingChestFaction, 1);
			}
			else if (NPCBraCover && !NPCChestCover) {
				if (ActorIsWearing(thisActor, MaleKeywords[ArmorTopT_Low]) || ActorIsWearing(thisActor, MaleKeywords[ArmorTopT]) || ActorIsWearing(thisActor, MaleKeywords[ArmorTopT_High])
					|| ActorIsWearing(thisActor, MaleKeywords[ArmorTop_NoCover]) || ActorIsWearing(thisActor, MaleKeywords[NipplePasties])) {
					SetActorFactionRank(thisActor, ToplessFaction, 0);
					SetActorFactionRank(thisActor, ShowingBraFaction, 0);
					SetActorFactionRank(thisActor, ShowingChestFaction, 1);
				}
				else {
					SetActorFactionRank(thisActor, ToplessFaction, 1);
					SetActorFactionRank(thisActor, ShowingBraFaction, 0);
					SetActorFactionRank(thisActor, ShowingChestFaction, 1);
				}
			}
		}

		if (NPCPelvicCurtainCover && NPCAssCurtainCover) {
			SetActorFactionRank(thisActor, BottomlessFaction, 0);
			SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
			SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
		}
		else if (NPCPelvicCurtainCover && !NPCAssCurtainCover) {
			SetActorFactionRank(thisActor, BottomlessFaction, 0);
			SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
			if (NPCUnderwearCover && NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
				SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			}
			else if (!NPCUnderwearCover && NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			}
			else if (!NPCUnderwearCover && !NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingAssFaction, 1);
			}
			else if (NPCUnderwearCover && !NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
				SetActorFactionRank(thisActor, ShowingAssFaction, 1);
			}
		}
		else if (!NPCPelvicCurtainCover && NPCAssCurtainCover) {
			SetActorFactionRank(thisActor, BottomlessFaction, 0);
			SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			if (NPCUnderwearCover && NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
			}
			else if (!NPCUnderwearCover && NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
			}
			else if (!NPCUnderwearCover && !NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 1);
			}
			else if (NPCUnderwearCover && !NPCAssCover) {
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 1);
			}
		}
		else {
			if (NPCUnderwearCover && NPCGenitalCover && NPCAssCover) { //True True True
				SetActorFactionRank(thisActor, BottomlessFaction, 0);
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
				SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			}
			else if (!NPCUnderwearCover && NPCGenitalCover && NPCAssCover) { //False True True
				SetActorFactionRank(thisActor, BottomlessFaction, 0);
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
				SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			}
			else if (!NPCUnderwearCover && !NPCGenitalCover && NPCAssCover) { //False False True
				SetActorFactionRank(thisActor, BottomlessFaction, 0);
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 1);
				SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			}
			else if (!NPCUnderwearCover && NPCGenitalCover && !NPCAssCover) { //False True False
				SetActorFactionRank(thisActor, BottomlessFaction, 0);
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
				SetActorFactionRank(thisActor, ShowingAssFaction, 1);
			}
			else if (!NPCUnderwearCover && !NPCGenitalCover && !NPCAssCover) { //False False False
				SetActorFactionRank(thisActor, BottomlessFaction, 0);
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 1);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 1);
				SetActorFactionRank(thisActor, ShowingAssFaction, 1);
			}
			else if (NPCUnderwearCover && !NPCGenitalCover && NPCAssCover) { //True False True
				SetActorFactionRank(thisActor, BottomlessFaction, 0);
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 1);
				SetActorFactionRank(thisActor, ShowingAssFaction, 0);
			}
			else if (NPCUnderwearCover && NPCGenitalCover && !NPCAssCover) { //True True False
				SetActorFactionRank(thisActor, BottomlessFaction, 0);
				SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
				SetActorFactionRank(thisActor, ShowingGenitalsFaction, 0);
				SetActorFactionRank(thisActor, ShowingAssFaction, 1);
			}
			else if (NPCUnderwearCover && !NPCGenitalCover && !NPCAssCover) { //True False False
				if (
					ActorIsWearing(thisActor, MaleKeywords[ArmorBottom_NoCover]) ||
					ActorIsWearing(thisActor, MaleKeywords[HotpantsT_Low]) || ActorIsWearing(thisActor, MaleKeywords[HotpantsT]) || ActorIsWearing(thisActor, MaleKeywords[HotpantsT_High]) ||
					ActorIsWearing(thisActor, MaleKeywords[HimboSkirtT_Low]) || ActorIsWearing(thisActor, MaleKeywords[HimboSkirtT]) || ActorIsWearing(thisActor, MaleKeywords[HimboSkirtT_High]) ||
					ActorIsWearing(thisActor, MaleKeywords[Microskirt])
					) {
					SetActorFactionRank(thisActor, BottomlessFaction, 0);
					SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
					SetActorFactionRank(thisActor, ShowingGenitalsFaction, 1);
					SetActorFactionRank(thisActor, ShowingAssFaction, 1);
				}
				else {
					SetActorFactionRank(thisActor, BottomlessFaction, 1);
					SetActorFactionRank(thisActor, ShowingUnderwearFaction, 0);
					SetActorFactionRank(thisActor, ShowingGenitalsFaction, 1);
					SetActorFactionRank(thisActor, ShowingAssFaction, 1);
				}
			}
		}

		if (thisActor->GetFactionRank(ToplessFaction, true) == 1 && thisActor->GetFactionRank(BottomlessFaction, true) == 1 && !ActorIsWearing(thisActor, MaleKeywords[NearlyNaked])) {
			SetActorFactionRank(thisActor, NudeFaction, 1);
		}
		else {
			SetActorFactionRank(thisActor, NudeFaction, 0);
		}

		Log("<C++ NPCMaleArmorScan> [Finalize] Nude Faction Rank: " + BoolToString(thisActor->GetFactionRank(NudeFaction, true)), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [Finalize] Topless Faction Rank: " + BoolToString(thisActor->GetFactionRank(ToplessFaction, true)), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [Finalize] Bottomless Faction Rank: " + BoolToString(thisActor->GetFactionRank(BottomlessFaction, true)), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [Finalize] Showing Bra Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingBraFaction, true)), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [Finalize] Showing Chest Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingChestFaction, true)), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [Finalize] Showing Underwear Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingUnderwearFaction, true)), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [Finalize] Showing Genitals Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingGenitalsFaction, true)), Logger::LogType::NPCArmorScan);
		Log("<C++ NPCMaleArmorScan> [Finalize] Showing Ass Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingAssFaction, true)), Logger::LogType::NPCArmorScan);

		Log("<C++ NPCMaleArmorScan> [Finalize] NPC Male Scan Completed", Logger::LogType::NPCArmorScan);
	}

	bool VanillaArmorCheck() {
		Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] START");

		RE::TESBoundObject* BodyArmor = thisActor->GetWornArmor(RE::BIPED_MODEL::BipedObjectSlot::kBody);

		if (BodyArmor) {
			const auto BodyItem = AsKeywordForm(BodyArmor);

			bool HasCurtainKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[ChestCurtain]) || BodyItem->HasKeyword(MaleKeywords[ChestCurtainT]) ||
					BodyItem->HasKeyword(MaleKeywords[PelvicCurtain]) || BodyItem->HasKeyword(MaleKeywords[PelvicCurtainT]) ||
					BodyItem->HasKeyword(MaleKeywords[AssCurtain]) || BodyItem->HasKeyword(MaleKeywords[AssCurtainT]) ||
					BodyItem->HasKeyword(MaleKeywords[Miniskirt]) || BodyItem->HasKeyword(MaleKeywords[MiniskirtT])
					);
			Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: " + BoolToString(HasCurtainKeyword), Logger::LogType::NPCArmorScan);
			if (HasCurtainKeyword) {
				return false;
			}

			bool HasTopKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[ArmorTop]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorTopT_Low]) || BodyItem->HasKeyword(MaleKeywords[ArmorTopT]) || BodyItem->HasKeyword(MaleKeywords[ArmorTopT_High]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorTop_NoCover])
					);
			Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: " + BoolToString(HasTopKeyword), Logger::LogType::NPCArmorScan);
			if (HasTopKeyword) {
				return false;
			}

			bool HasBottomKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[ArmorBottom]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorBottomT_Low]) || BodyItem->HasKeyword(MaleKeywords[ArmorBottomT]) || BodyItem->HasKeyword(MaleKeywords[ArmorBottomT_High]) ||
					BodyItem->HasKeyword(MaleKeywords[ArmorBottom_NoCover]) ||
					BodyItem->HasKeyword(MaleKeywords[Hotpants]) ||
					BodyItem->HasKeyword(MaleKeywords[HotpantsT_Low]) || BodyItem->HasKeyword(MaleKeywords[HotpantsT]) || BodyItem->HasKeyword(MaleKeywords[HotpantsT_High]) ||
					BodyItem->HasKeyword(MaleKeywords[HimboSkirt]) ||
					BodyItem->HasKeyword(MaleKeywords[HimboSkirtT_Low]) || BodyItem->HasKeyword(MaleKeywords[HimboSkirtT]) || BodyItem->HasKeyword(MaleKeywords[HimboSkirtT_High])
					);
			Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: " + BoolToString(HasBottomKeyword), Logger::LogType::NPCArmorScan);
			if (HasBottomKeyword) {
				return false;
			}

			bool HasBraKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[Bra]) ||
					BodyItem->HasKeyword(MaleKeywords[BraT_Low]) || BodyItem->HasKeyword(MaleKeywords[BraT]) || BodyItem->HasKeyword(MaleKeywords[BraT_High]) ||
					BodyItem->HasKeyword(MaleKeywords[Bra_NoCover])
					);
			Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: " + BoolToString(HasBraKeyword), Logger::LogType::NPCArmorScan);
			if (HasBraKeyword) {
				return false;
			}

			bool HasUnderwearKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[Underwear]) ||
					BodyItem->HasKeyword(MaleKeywords[UnderwearT_Low]) || BodyItem->HasKeyword(MaleKeywords[UnderwearT]) || BodyItem->HasKeyword(MaleKeywords[UnderwearT_High]) ||
					BodyItem->HasKeyword(MaleKeywords[Underwear_NoCover]) ||
					BodyItem->HasKeyword(MaleKeywords[Thong]) ||
					BodyItem->HasKeyword(MaleKeywords[ThongT_Low]) || BodyItem->HasKeyword(MaleKeywords[ThongT]) || BodyItem->HasKeyword(MaleKeywords[ThongT_High]) ||
					BodyItem->HasKeyword(MaleKeywords[Thong_NoCover]) ||
					BodyItem->HasKeyword(MaleKeywords[BananaHammock]) ||
					BodyItem->HasKeyword(MaleKeywords[BananaHammockT_Low]) || BodyItem->HasKeyword(MaleKeywords[BananaHammockT]) || BodyItem->HasKeyword(MaleKeywords[BananaHammockT_High])
					);
			Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: " + BoolToString(HasUnderwearKeyword), Logger::LogType::NPCArmorScan);
			if (HasUnderwearKeyword) {
				return false;
			}

			bool HasExtraKeyword =
				(
					BodyItem->HasKeyword(MaleKeywords[NearlyNaked]) ||
					BodyItem->HasKeyword(MaleKeywords[NipplePasties]) ||
					BodyItem->HasKeyword(MaleKeywords[Microskirt]) ||
					BodyItem->HasKeyword(MaleKeywords[EffectivelyNaked])
					);
			Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: " + BoolToString(HasExtraKeyword), Logger::LogType::NPCArmorScan);
			if (HasExtraKeyword) {
				return false;
			}

			Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? True - No A.N.D. Keywords were found on the Body Armor", Logger::LogType::NPCArmorScan);
			return true;
		}
		Log("<C++ NPCMaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? False - Not Wearing Body Armor", Logger::LogType::NPCArmorScan);
		return false;
	}

	UINT8 GetArmorTopRiskLevel() {
		if (ActorIsWearing(thisActor, MaleKeywords[ArmorTopT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (ActorIsWearing(thisActor, MaleKeywords[ArmorTopT])) {
			return FlashRiskLevel::Normal;
		}
		else if (ActorIsWearing(thisActor, MaleKeywords[ArmorTopT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetBraRiskLevel() {
		if (ActorIsWearing(thisActor, MaleKeywords[BraT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (ActorIsWearing(thisActor, MaleKeywords[BraT])) {
			return FlashRiskLevel::Normal;
		}
		else if (ActorIsWearing(thisActor, MaleKeywords[BraT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	UINT8 GetArmorBottomRiskLevel() {
		if (ActorIsWearing(thisActor, MaleKeywords[ArmorBottomT_Low])) {
			return FlashRiskLevel::Low;
		}
		else if (ActorIsWearing(thisActor, MaleKeywords[ArmorBottomT])) {
			return FlashRiskLevel::Normal;
		}
		else if (ActorIsWearing(thisActor, MaleKeywords[ArmorBottomT_High])) {
			return FlashRiskLevel::High;
		}

		return FlashRiskLevel::None;
	}

	void NPCMaleAnalyze(RE::Actor* akMale) {
		Log("<C++ NPCMaleArmorScan> [MaleAnalyze] NPC Male Analysis Triggered!");

		if (akMale == nullptr) {
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] Actor is None/Null Pointer!!!", Logger::LogType::NPCArmorScan, Logger::LoggingLevel::critical);
			return;
		}

		std::string akName = akMale->GetName();
		Log("<C++ NPCMaleArmorScan> [MaleAnalyze] Analyzing Actor: " + akName + " | Form ID: (" + std::format("{:08X}", akMale->GetFormID()) + ")", Logger::LogType::NPCArmorScan);

		if (akMale->GetActorBase()->IsFemale() == true) {
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] CRITICAL ERROR: Actor " + akName + " is Female! This should not have happened!", Logger::LogType::NPCArmorScan, Logger::LoggingLevel::critical);
			return;
		}

		thisActor = akMale;

		ResetFlashingFactions();

		Log("<C++ NPCMaleArmorScan> [MaleAnalyze] Start analysis...", Logger::LogType::NPCArmorScan);
		if (ActorIsWearing(thisActor, MaleKeywords[CoversAll])) {
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] Covers All keyword detected", Logger::LogType::NPCArmorScan);

			NPCTopCurtainCover = true;
			NPCPelvicCurtainCover = true;
			NPCTopCurtainCover = true;

			NPCChestCover = true;
			NPCBraCover = true;
			NPCAssCover = true;
			NPCGenitalCover = true;
			NPCUnderwearCover = true;
		}
		else {
			bool HasChestCurtain = ActorIsWearing(thisActor, MaleKeywords[ChestCurtain]);
			bool HasChestCurtainT = ActorIsWearing(thisActor, MaleKeywords[ChestCurtainT]);

			UINT8 ChestRiskLevel = FlashRiskLevel::None;
			if (ActorWornHasKeyword(thisActor, MaleKeywords[ChestFlashRiskLow])) {
				ChestRiskLevel = FlashRiskLevel::Low;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[ChestFlashRisk])) {
				ChestRiskLevel = FlashRiskLevel::Normal;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[ChestFlashRiskHigh])) {
				ChestRiskLevel = FlashRiskLevel::High;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[ChestFlashRiskExtreme])) {
				ChestRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[ChestFlashRiskUltra])) {
				ChestRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasPelvicCurtain = (ActorIsWearing(thisActor, MaleKeywords[PelvicCurtain]) || ActorIsWearing(thisActor, MaleKeywords[Miniskirt]));
			bool HasPelvicCurtainT = (ActorIsWearing(thisActor, MaleKeywords[PelvicCurtainT]) || ActorIsWearing(thisActor, MaleKeywords[MiniskirtT]));

			UINT8 PelvicRiskLevel = FlashRiskLevel::None;
			if (ActorWornHasKeyword(thisActor, MaleKeywords[PelvicFlashRiskLow])) {
				PelvicRiskLevel = FlashRiskLevel::Low;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[PelvicFlashRisk])) {
				PelvicRiskLevel = FlashRiskLevel::Normal;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[PelvicFlashRiskHigh])) {
				PelvicRiskLevel = FlashRiskLevel::High;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[PelvicFlashRiskExtreme])) {
				PelvicRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[PelvicFlashRiskUltra])) {
				PelvicRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasAssCurtain = (ActorIsWearing(thisActor, MaleKeywords[AssCurtain]) || ActorIsWearing(thisActor, MaleKeywords[Miniskirt]));
			bool HasAssCurtainT = (ActorIsWearing(thisActor, MaleKeywords[AssCurtainT]) || ActorIsWearing(thisActor, MaleKeywords[MiniskirtT]));

			UINT8 AssRiskLevel = FlashRiskLevel::None;
			if (ActorWornHasKeyword(thisActor, MaleKeywords[AssFlashRiskLow])) {
				AssRiskLevel = FlashRiskLevel::Low;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[AssFlashRisk])) {
				AssRiskLevel = FlashRiskLevel::Normal;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[AssFlashRiskHigh])) {
				AssRiskLevel = FlashRiskLevel::High;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[AssFlashRiskExtreme])) {
				AssRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (ActorWornHasKeyword(thisActor, MaleKeywords[AssFlashRiskUltra])) {
				AssRiskLevel = FlashRiskLevel::Ultra;
			}

			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasChestCurtain = " + BoolToString(HasChestCurtain), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasChestCurtainT = " + BoolToString(HasChestCurtainT), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] ChestRiskLevel = " + BoolToString(ChestRiskLevel), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasPelvicCurtain = " + BoolToString(HasPelvicCurtain), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasPelvicCurtainT = " + BoolToString(HasPelvicCurtainT), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] PelvicRiskLevel = " + BoolToString(PelvicRiskLevel), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasAssCurtain = " + BoolToString(HasAssCurtain), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasAssCurtainT = " + BoolToString(HasAssCurtainT), Logger::LogType::NPCArmorScan);
			Log("<C++ NPCMaleArmorScan> [MaleAnalyze] AssRiskLevel = " + BoolToString(AssRiskLevel), Logger::LogType::NPCArmorScan);

			if (VanillaArmorCheck() == true) {
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] Armor is considered vanilla.", Logger::LogType::NPCArmorScan);

				NPCTopCurtainCover = CurtainCheck(FlashRiskType::Chest, HasChestCurtainT, ChestRiskLevel);
				NPCPelvicCurtainCover = CurtainCheck(FlashRiskType::Pelvic, HasPelvicCurtainT, PelvicRiskLevel);
				NPCAssCurtainCover = CurtainCheck(FlashRiskType::Ass, HasAssCurtainT, AssRiskLevel);

				NPCChestCover = true;
				NPCBraCover = true;
				NPCAssCover = true;
				NPCGenitalCover = true;
				NPCUnderwearCover = true;
			}
			else {
				/*
				=============
				TOP VAIRABLES
				=============
				*/

				//Armor Top
				bool HasArmorTop = ActorIsWearing(thisActor, MaleKeywords[ArmorTop]);
				UINT8 TopRiskLevel = GetArmorTopRiskLevel();
				bool HasArmorTopT = TopRiskLevel;

				//Bra
				bool HasBra = ActorIsWearing(thisActor, MaleKeywords[Bra]);
				UINT8 BraRiskLevel = GetBraRiskLevel();
				bool HasBraT = BraRiskLevel;
				bool HasBraNoCover = ActorIsWearing(thisActor, MaleKeywords[Bra_NoCover]);

				/*
				================
				BOTTOM VARIABLES
				================
				*/

				//Bottom Armor
				bool HasArmorBottom = ActorIsWearing(thisActor, MaleKeywords[ArmorBottom]);
				UINT8 BottomRiskLevel = GetArmorBottomRiskLevel();
				bool HasArmorBottomT = BottomRiskLevel;

				//Hotpants
				bool HasHotpants = ActorIsWearing(thisActor, MaleKeywords[Hotpants]);
				UINT8 HotpantsRiskLevel = FlashRiskLevel::None;
				if (ActorIsWearing(thisActor, MaleKeywords[HotpantsT_Low])) {
					HotpantsRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[HotpantsT])) {
					HotpantsRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[HotpantsT_High])) {
					HotpantsRiskLevel = FlashRiskLevel::High;
				}
				bool HasHotpantsT = HotpantsRiskLevel;

				//Himbo Skirt
				bool HasHimbo = ActorIsWearing(thisActor, MaleKeywords[HimboSkirt]);
				UINT8 HimboRiskLevel = FlashRiskLevel::None;
				if (ActorIsWearing(thisActor, MaleKeywords[HimboSkirtT_Low])) {
					HimboRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[HimboSkirtT])) {
					HimboRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[HimboSkirtT_High])) {
					HimboRiskLevel = FlashRiskLevel::High;
				}
				bool HasHimboT = HimboRiskLevel;

				//Underwear
				bool HasUnderwear = ActorIsWearing(thisActor, MaleKeywords[Underwear]);
				UINT8 UnderwearRiskLevel = FlashRiskLevel::None;
				if (ActorIsWearing(thisActor, MaleKeywords[UnderwearT_Low])) {
					UnderwearRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[UnderwearT])) {
					UnderwearRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[UnderwearT_High])) {
					UnderwearRiskLevel = FlashRiskLevel::High;
				}
				bool HasUnderwearT = UnderwearRiskLevel;
				bool HasUnderwearNoCover = ActorIsWearing(thisActor, MaleKeywords[Underwear_NoCover]);

				//Thong
				bool HasThong = ActorIsWearing(thisActor, MaleKeywords[Thong]);
				UINT8 ThongRiskLevel = FlashRiskLevel::None;
				if (ActorIsWearing(thisActor, MaleKeywords[ThongT_Low])) {
					ThongRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[ThongT])) {
					ThongRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[ThongT_High])) {
					ThongRiskLevel = FlashRiskLevel::High;
				}
				bool HasThongT = ThongRiskLevel;
				bool HasThongNoCover = ActorIsWearing(thisActor, MaleKeywords[Thong_NoCover]);

				//BananaHammock
				bool HasBananaHammock = ActorIsWearing(thisActor, MaleKeywords[BananaHammock]);
				UINT8 BananaHammockRiskLevel = FlashRiskLevel::None;
				if (ActorIsWearing(thisActor, MaleKeywords[BananaHammockT_Low])) {
					BananaHammockRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[BananaHammockT])) {
					BananaHammockRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorIsWearing(thisActor, MaleKeywords[BananaHammockT_High])) {
					BananaHammockRiskLevel = FlashRiskLevel::High;
				}
				bool HasBananaHammockT = BananaHammockRiskLevel;

				//Debug Results
				//Top
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorTop = " + BoolToString(HasArmorTop), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorTopT = " + BoolToString(HasArmorTopT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] TopRiskLevel = " + BoolToString(TopRiskLevel), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBra = " + BoolToString(HasBra), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBraT = " + BoolToString(HasBraT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] BraRiskLevel = " + BoolToString(BraRiskLevel), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBraNoCover = " + BoolToString(HasBraNoCover), Logger::LogType::NPCArmorScan);

				//Bottom
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorBottom = " + BoolToString(HasArmorBottom), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorBottomT = " + BoolToString(HasArmorBottomT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] BottomRiskLevel = " + BoolToString(BottomRiskLevel), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHotpants = " + BoolToString(HasHotpants), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHotpantsT = " + BoolToString(HasHotpantsT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HotpantsRiskLevel = " + BoolToString(HotpantsRiskLevel), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHimbo = " + BoolToString(HasHimbo), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHimboT = " + BoolToString(HasHimboT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HimboRiskLevel = " + BoolToString(HimboRiskLevel), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasUnderwear = " + BoolToString(HasUnderwear), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasUnderwearT = " + BoolToString(HasUnderwearT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] UnderwearRiskLevel = " + BoolToString(UnderwearRiskLevel), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasUnderwearNoCover = " + BoolToString(HasUnderwearNoCover), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasThong = " + BoolToString(HasThong), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasThongT = " + BoolToString(HasThongT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] ThongRiskLevel = " + BoolToString(ThongRiskLevel), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasThongNoCover = " + BoolToString(HasThongNoCover), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBananaHammock = " + BoolToString(HasBananaHammock), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBananaHammockT = " + BoolToString(HasBananaHammockT), Logger::LogType::NPCArmorScan);
				Log("<C++ NPCMaleArmorScan> [MaleAnalyze] BananaHammockRiskLevel = " + BoolToString(BananaHammockRiskLevel), Logger::LogType::NPCArmorScan);

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
		Log("<C++ NPCMaleArmorScan> [MaleAnalyze] Analysis Succeeded!", Logger::LogType::NPCArmorScan);
	}
}

void ExternalNPCMaleAnalyze(RE::StaticFunctionTag*, RE::Actor* akMale) {
	NPCMaleScan::NPCMaleAnalyze(akMale);
}