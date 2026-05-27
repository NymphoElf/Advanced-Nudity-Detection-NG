#include "Core.h"
#include "Config.h"
#include "Logger.h"
#include "NPCArmorScan.h"

namespace NPCFemaleScan {

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

	bool CurtainCheck(int Type, bool IsTransparent, int Level) {
		Log("<C++ NPCFemaleArmorScan> [CurtainCheck] START", LogType::NPCArmorScan);

		int Roll = 0;
		int Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Chest) {
			TypeString = "Chest";
			Roll = NPCChestCurtainRoll;
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
			Roll = NPCPelvicCurtainRoll;
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
			Roll = NPCAssCurtainRoll;
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

		Log("<C++ NPCFemaleArmorScan> [CurtainCheck] Roll = " + std::to_string(Roll), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [CurtainCheck] Odds = " + std::to_string(Odds), LogType::NPCArmorScan);

		Log("<C++ NPCFemaleArmorScan> [CurtainCheck] Type = " + TypeString, LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [CurtainCheck] IsTransparent = " + BoolToString(IsTransparent), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [CurtainCheck] RiskLevel = " + FlashRiskToString(Level), LogType::NPCArmorScan);

		Log("<C++ NPCFemaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), LogType::NPCArmorScan);

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

	bool TransparentItemCheck(int Type, int Level) {
		int Roll = 0;
		int Odds = 0;

		std::string TypeString = "None";

		if (Type == FlashRiskType::Top) {
			TypeString = "Top";
			Roll = NPCTopTransparentRoll;
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
			Roll = NPCBottomTransparentRoll;
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
			Roll = NPCBraTransparentRoll;
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

			Roll = NPCUnderwearTransparentRoll;
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
			Roll = NPCHotpantsTransparentRoll;
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
			Roll = NPCShowgirlTransparentRoll;
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

		Log("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Roll = " + std::to_string(Roll), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Odds = " + std::to_string(Odds), LogType::NPCArmorScan);

		Log("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Type = " + TypeString, LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [TransparentItemCheck] RiskLevel = " + FlashRiskToString(Level), LogType::NPCArmorScan);

		Log("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? " + BoolToString(Roll > Odds), LogType::NPCArmorScan);

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
		case FlashRiskType::Showgirl:
			SetActorFactionRank(thisActor, FlashingShowgirlSkirtFaction, !Result);
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

		Log("<C++ NPCFemaleArmorScan> [CStringCheck] Roll = " + std::to_string(NPCCStringRoll), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [CStringCheck] Odds = " + std::to_string(Odds), LogType::NPCArmorScan);

		Log("<C++ NPCFemaleArmorScan> [CStringCheck] IsTransparent = " + BoolToString(IsTransparent), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [CStringCheck] RiskLevel = " + FlashRiskToString(Level), LogType::NPCArmorScan);

		Log("<C++ NPCFemaleArmorScan> [CStringCheck] Function Return Value: Is Covering? " + BoolToString(NPCCStringRoll > Odds), LogType::NPCArmorScan);

		bool Result = (CStringRoll > Odds);

		SetActorFactionRank(thisActor, FlashingCStringFaction, !Result);

		return Result;
	}

	void AnalyzeBra(bool HasBra, bool HasBraT, int BraRiskLevel, bool HasBraNoCover) {
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
		bool HasChestCurtain, bool HasChestCurtainT, int ChestRiskLevel,
		bool HasArmorTop, bool HasArmorTopT, int TopRiskLevel,
		bool HasBra, bool HasBraT, int BraRiskLevel, bool HasBraNoCover
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

	void AnalyzeCString(bool HasCStringT, int CStringRiskLevel) {
		NPCGenitalCover = CStringCheck(HasCStringT, CStringRiskLevel);
		NPCUnderwearCover = !NPCGenitalCover;
	}

	void AnalyzeUnderwear
	(
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, int CStringRiskLevel
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
		else if (HasCString || HasCStringT) {
			NPCAssCover = false;
			AnalyzeCString(HasCStringT, CStringRiskLevel);
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
		bool HasHotpants, bool HasHotpantsT, int HotpantsRiskLevel,
		bool HasShowgirl, bool HasShowgirlT, int ShowgirlRiskLevel,
		bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
		bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
		bool HasCString, bool HasCStringT, int CStringRiskLevel
	) {
		if (HasHotpants && HasShowgirl) {
			NPCAssCover = true;
			NPCGenitalCover = true;
			NPCUnderwearCover = true;
		}
		else if (HasHotpants && HasShowgirlT) {
			NPCGenitalCover = true;

			if (HasUnderwear) {
				NPCAssCover = true;
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
			}
			else if (HasUnderwearT) {
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
				if (NPCUnderwearCover) {
					NPCAssCover = true;
				}
				else {
					NPCAssCover = TransparentItemCheck(FlashRiskType::Underwear, UnderwearRiskLevel);
				}
			}
			else if (HasUnderwearNoCover) {
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
				NPCAssCover = NPCUnderwearCover;
			}
			else {
				NPCUnderwearCover = true;
				NPCAssCover = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);
			}
		}
		else if (HasHotpantsT && HasShowgirl) {
			NPCAssCover = true;

			if (HasUnderwear || HasThong) {
				NPCGenitalCover = true;
				NPCUnderwearCover = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			}
			else if (HasUnderwearT || HasThongT || HasCString || HasCStringT) {
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
						AnalyzeCString(HasCStringT, CStringRiskLevel);
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
		else if (HasHotpantsT && HasShowgirlT) {
			bool HotpantsCovering = TransparentItemCheck(FlashRiskType::Hotpants, HotpantsRiskLevel);
			bool ShowgirlCovering = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);

			if (HotpantsCovering && ShowgirlCovering) {
				NPCAssCover = true;
				NPCGenitalCover = true;
				NPCUnderwearCover = true;
			}
			else if (HotpantsCovering && !ShowgirlCovering) {
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
			else if (!HotpantsCovering && ShowgirlCovering) {
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
				else if (HasCString || HasCStringT) {
					AnalyzeCString(HasCStringT, CStringRiskLevel);
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
					HasCString, HasCStringT, CStringRiskLevel
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
		else if (HasShowgirl) {
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
			else if (HasCString || HasCStringT) {
				AnalyzeCString(HasCStringT, CStringRiskLevel);
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
					HasCString, HasCStringT, CStringRiskLevel
				);
			}
		}
		else if (HasShowgirlT) {
			bool ShowgirlCovering = TransparentItemCheck(FlashRiskType::Showgirl, ShowgirlRiskLevel);

			if (ShowgirlCovering) {
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
				else if (HasCString || HasCStringT) {
					AnalyzeCString(HasCStringT, CStringRiskLevel);
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
				if (ActorWornHasKeyword(thisActor, ArmorTopT_Low) || ActorWornHasKeyword(thisActor, ArmorTopT) || ActorWornHasKeyword(thisActor, ArmorTopT_High)
					|| ActorWornHasKeyword(thisActor, ArmorTop_NoCover) || ActorWornHasKeyword(thisActor, NipplePasties)) {
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
					ActorWornHasKeyword(thisActor, ArmorBottom_NoCover) ||
					ActorWornHasKeyword(thisActor, HotpantsT_Low) || ActorWornHasKeyword(thisActor, HotpantsT) || ActorWornHasKeyword(thisActor, HotpantsT_High) ||
					ActorWornHasKeyword(thisActor, ShowgirlSkirtT_Low) || ActorWornHasKeyword(thisActor, ShowgirlSkirtT) || ActorWornHasKeyword(thisActor, ShowgirlSkirtT_High) ||
					ActorWornHasKeyword(thisActor, Microskirt) || ActorWornHasKeyword(thisActor, VaginaPasties)
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

		if (thisActor->GetFactionRank(ToplessFaction, true) == 1 && thisActor->GetFactionRank(BottomlessFaction, true) == 1 && !ActorWornHasKeyword(thisActor, NearlyNaked)) {
			SetActorFactionRank(thisActor, NudeFaction, 1);
		}
		else {
			SetActorFactionRank(thisActor, NudeFaction, 0);
		}

		Log("<C++ NPCFemaleArmorScan> [Finalize] Nude Faction Rank: " + BoolToString(thisActor->GetFactionRank(NudeFaction, true)), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [Finalize] Topless Faction Rank: " + BoolToString(thisActor->GetFactionRank(ToplessFaction, true)), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [Finalize] Bottomless Faction Rank: " + BoolToString(thisActor->GetFactionRank(BottomlessFaction, true)), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [Finalize] Showing Bra Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingBraFaction, true)), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [Finalize] Showing Chest Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingChestFaction, true)), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [Finalize] Showing Underwear Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingUnderwearFaction, true)), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [Finalize] Showing Genitals Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingGenitalsFaction, true)), LogType::NPCArmorScan);
		Log("<C++ NPCFemaleArmorScan> [Finalize] Showing Ass Faction Rank: " + BoolToString(thisActor->GetFactionRank(ShowingAssFaction, true)), LogType::NPCArmorScan);

		Log("<C++ NPCFemaleArmorScan> [Finalize] Female Scan Completed", LogType::NPCArmorScan);
	}

	bool VanillaArmorCheck() {
		Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] START", LogType::NPCArmorScan);

		RE::TESBoundObject* BodyArmor = thisActor->GetWornArmor(RE::BIPED_MODEL::BipedObjectSlot::kBody);

		if (BodyArmor) {
			const auto BodyItem = AsKeywordForm(BodyArmor);

			bool HasCurtainKeyword =
				(
					BodyItem->HasKeyword(ChestCurtain) || BodyItem->HasKeyword(ChestCurtainT) ||
					BodyItem->HasKeyword(PelvicCurtain) || BodyItem->HasKeyword(PelvicCurtainT) ||
					BodyItem->HasKeyword(AssCurtain) || BodyItem->HasKeyword(AssCurtainT) ||
					BodyItem->HasKeyword(Miniskirt) || BodyItem->HasKeyword(MiniskirtT)
					);
			Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: " + BoolToString(HasCurtainKeyword), LogType::NPCArmorScan);

			bool HasTopKeyword =
				(
					BodyItem->HasKeyword(ArmorTop) ||
					BodyItem->HasKeyword(ArmorTopT_Low) || BodyItem->HasKeyword(ArmorTopT) || BodyItem->HasKeyword(ArmorTopT_High) ||
					BodyItem->HasKeyword(ArmorTop_NoCover)
					);
			Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: " + BoolToString(HasTopKeyword), LogType::NPCArmorScan);

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
			Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: " + BoolToString(HasBottomKeyword), LogType::NPCArmorScan);

			bool HasBraKeyword =
				(
					BodyItem->HasKeyword(Bra) ||
					BodyItem->HasKeyword(BraT_Low) || BodyItem->HasKeyword(BraT) || BodyItem->HasKeyword(BraT_High) ||
					BodyItem->HasKeyword(Bra_NoCover)
					);
			Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: " + BoolToString(HasBraKeyword), LogType::NPCArmorScan);

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
			Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: " + BoolToString(HasUnderwearKeyword), LogType::NPCArmorScan);

			bool HasExtraKeyword =
				(
					BodyItem->HasKeyword(NearlyNaked) ||
					BodyItem->HasKeyword(NipplePasties) ||
					BodyItem->HasKeyword(VaginaPasties) ||
					BodyItem->HasKeyword(Microskirt) ||
					BodyItem->HasKeyword(EffectivelyNaked)
					);
			Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: " + BoolToString(HasExtraKeyword), LogType::NPCArmorScan);

			Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? " + BoolToString(!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword), LogType::NPCArmorScan);
			return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
		}
		Log("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? False", LogType::NPCArmorScan);
		return false;
	}

	void NPCFemaleAnalyze(RE::Actor* akFemale) {
		Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] NPC Female Analysis Triggered!", LogType::NPCArmorScan);

		if (akFemale == nullptr) {
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Actor is None/Null Pointer!!!", LogType::NPCArmorScan, LoggingLevel::critical);
			return;
		}

		std::string akName = akFemale->GetName();
		Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Analyzing Actor: " + akName + " | Form ID: (" + std::format("{:08X}", akFemale->GetFormID()) + ")", LogType::NPCArmorScan);

		if (akFemale->GetActorBase()->IsFemale() == false) {
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] CRITICAL ERROR: Actor " + akName + " is Male! This should not have happened!", LogType::NPCArmorScan, LoggingLevel::critical);
			return;
		}

		thisActor = akFemale;

		ResetFlashingFactions();

		Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Start analysis...", LogType::NPCArmorScan);
		if (ActorWornHasKeyword(thisActor, CoversAll)) {
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Covers All keyword detected", LogType::NPCArmorScan);

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
			bool HasChestCurtain = ActorWornHasKeyword(thisActor, ChestCurtain);
			bool HasChestCurtainT = ActorWornHasKeyword(thisActor, ChestCurtainT);

			int ChestRiskLevel = FlashRiskLevel::None;
			if (ActorWornHasKeyword(thisActor, ChestFlashRiskLow)) {
				ChestRiskLevel = FlashRiskLevel::Low;
			}
			else if (ActorWornHasKeyword(thisActor, ChestFlashRisk)) {
				ChestRiskLevel = FlashRiskLevel::Normal;
			}
			else if (ActorWornHasKeyword(thisActor, ChestFlashRiskHigh)) {
				ChestRiskLevel = FlashRiskLevel::High;
			}
			else if (ActorWornHasKeyword(thisActor, ChestFlashRiskExtreme)) {
				ChestRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (ActorWornHasKeyword(thisActor, ChestFlashRiskUltra)) {
				ChestRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasPelvicCurtain = (ActorWornHasKeyword(thisActor, PelvicCurtain) || ActorWornHasKeyword(thisActor, Miniskirt));
			bool HasPelvicCurtainT = (ActorWornHasKeyword(thisActor, PelvicCurtainT) || ActorWornHasKeyword(thisActor, MiniskirtT));

			int PelvicRiskLevel = FlashRiskLevel::None;
			if (ActorWornHasKeyword(thisActor, PelvicFlashRiskLow)) {
				PelvicRiskLevel = FlashRiskLevel::Low;
			}
			else if (ActorWornHasKeyword(thisActor, PelvicFlashRisk)) {
				PelvicRiskLevel = FlashRiskLevel::Normal;
			}
			else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskHigh)) {
				PelvicRiskLevel = FlashRiskLevel::High;
			}
			else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskExtreme)) {
				PelvicRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskUltra)) {
				PelvicRiskLevel = FlashRiskLevel::Ultra;
			}

			bool HasAssCurtain = (ActorWornHasKeyword(thisActor, AssCurtain) || ActorWornHasKeyword(thisActor, Miniskirt));
			bool HasAssCurtainT = (ActorWornHasKeyword(thisActor, AssCurtainT) || ActorWornHasKeyword(thisActor, MiniskirtT));

			int AssRiskLevel = FlashRiskLevel::None;
			if (ActorWornHasKeyword(thisActor, AssFlashRiskLow)) {
				AssRiskLevel = FlashRiskLevel::Low;
			}
			else if (ActorWornHasKeyword(thisActor, AssFlashRisk)) {
				AssRiskLevel = FlashRiskLevel::Normal;
			}
			else if (ActorWornHasKeyword(thisActor, AssFlashRiskHigh)) {
				AssRiskLevel = FlashRiskLevel::High;
			}
			else if (ActorWornHasKeyword(thisActor, AssFlashRiskExtreme)) {
				AssRiskLevel = FlashRiskLevel::Extreme;
			}
			else if (ActorWornHasKeyword(thisActor, AssFlashRiskUltra)) {
				AssRiskLevel = FlashRiskLevel::Ultra;
			}

			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasChestCurtain = " + BoolToString(HasChestCurtain), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasChestCurtainT = " + BoolToString(HasChestCurtainT), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] ChestRiskLevel = " + BoolToString(ChestRiskLevel), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasPelvicCurtain = " + BoolToString(HasPelvicCurtain), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasPelvicCurtainT = " + BoolToString(HasPelvicCurtainT), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] PelvicRiskLevel = " + BoolToString(PelvicRiskLevel), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasAssCurtain = " + BoolToString(HasAssCurtain), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasAssCurtainT = " + BoolToString(HasAssCurtainT), LogType::NPCArmorScan);
			Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] AssRiskLevel = " + BoolToString(AssRiskLevel), LogType::NPCArmorScan);

			if (VanillaArmorCheck() == true) {
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Armor is considered vanilla.", LogType::NPCArmorScan);

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
				bool HasArmorTop = ActorWornHasKeyword(thisActor, ArmorTop);
				int TopRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, ArmorTopT_Low)) {
					TopRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, ArmorTopT)) {
					TopRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, ArmorTopT_High)) {
					TopRiskLevel = FlashRiskLevel::High;
				}
				bool HasArmorTopT = TopRiskLevel > FlashRiskLevel::None;

				//Bra
				bool HasBra = ActorWornHasKeyword(thisActor, Bra);
				int BraRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, BraT_Low)) {
					BraRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, BraT)) {
					BraRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, BraT_High)) {
					BraRiskLevel = FlashRiskLevel::High;
				}
				bool HasBraT = BraRiskLevel > FlashRiskLevel::None;
				bool HasBraNoCover = ActorWornHasKeyword(thisActor, Bra_NoCover);

				/*
				================
				BOTTOM VARIABLES
				================
				*/

				//Bottom Armor
				bool HasArmorBottom = ActorWornHasKeyword(thisActor, ArmorBottom);
				int BottomRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, ArmorBottomT_Low)) {
					BottomRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, ArmorBottomT)) {
					BottomRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, ArmorBottomT_High)) {
					BottomRiskLevel = FlashRiskLevel::High;
				}
				bool HasArmorBottomT = BottomRiskLevel > FlashRiskLevel::None;

				//Hotpants
				bool HasHotpants = ActorWornHasKeyword(thisActor, Hotpants);
				int HotpantsRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, HotpantsT_Low)) {
					HotpantsRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, HotpantsT)) {
					HotpantsRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, HotpantsT_High)) {
					HotpantsRiskLevel = FlashRiskLevel::High;
				}
				bool HasHotpantsT = HotpantsRiskLevel > FlashRiskLevel::None;

				//Showgirl Skirt
				bool HasShowgirl = ActorWornHasKeyword(thisActor, ShowgirlSkirt);
				int ShowgirlRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, ShowgirlSkirtT_Low)) {
					ShowgirlRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, ShowgirlSkirtT)) {
					ShowgirlRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, ShowgirlSkirtT_High)) {
					ShowgirlRiskLevel = FlashRiskLevel::High;
				}
				bool HasShowgirlT = ShowgirlRiskLevel > FlashRiskLevel::None;

				//Underwear
				bool HasUnderwear = ActorWornHasKeyword(thisActor, Underwear);
				int UnderwearRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, UnderwearT_Low)) {
					UnderwearRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, UnderwearT)) {
					UnderwearRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, UnderwearT_High)) {
					UnderwearRiskLevel = FlashRiskLevel::High;
				}
				bool HasUnderwearT = UnderwearRiskLevel > FlashRiskLevel::None;
				bool HasUnderwearNoCover = ActorWornHasKeyword(thisActor, Underwear_NoCover);

				//Thong
				bool HasThong = ActorWornHasKeyword(thisActor, Thong);
				int ThongRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, ThongT_Low)) {
					ThongRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, ThongT)) {
					ThongRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, ThongT_High)) {
					ThongRiskLevel = FlashRiskLevel::High;
				}
				bool HasThongT = ThongRiskLevel > FlashRiskLevel::None;
				bool HasThongNoCover = ActorWornHasKeyword(thisActor, Thong_NoCover);

				//CString
				bool HasCString = ActorWornHasKeyword(thisActor, CString);
				int CStringRiskLevel = FlashRiskLevel::None;
				if (ActorWornHasKeyword(thisActor, CStringT_Low)) {
					CStringRiskLevel = FlashRiskLevel::Low;
				}
				else if (ActorWornHasKeyword(thisActor, CStringT)) {
					CStringRiskLevel = FlashRiskLevel::Normal;
				}
				else if (ActorWornHasKeyword(thisActor, CStringT_High)) {
					CStringRiskLevel = FlashRiskLevel::High;
				}
				bool HasCStringT = CStringRiskLevel > FlashRiskLevel::None;

				//Debug Results
				//Top
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorTop = " + BoolToString(HasArmorTop), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorTopT = " + BoolToString(HasArmorTopT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] TopRiskLevel = " + BoolToString(TopRiskLevel), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasBra = " + BoolToString(HasBra), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasBraT = " + BoolToString(HasBraT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] BraRiskLevel = " + BoolToString(BraRiskLevel), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasBraNoCover = " + BoolToString(HasBraNoCover), LogType::NPCArmorScan);

				//Bottom
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorBottom = " + BoolToString(HasArmorBottom), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorBottomT = " + BoolToString(HasArmorBottomT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] BottomRiskLevel = " + BoolToString(BottomRiskLevel), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasHotpants = " + BoolToString(HasHotpants), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasHotpantsT = " + BoolToString(HasHotpantsT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HotpantsRiskLevel = " + BoolToString(HotpantsRiskLevel), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasShowgirl = " + BoolToString(HasShowgirl), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasShowgirlT = " + BoolToString(HasShowgirlT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] ShowgirlRiskLevel = " + BoolToString(ShowgirlRiskLevel), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasUnderwear = " + BoolToString(HasUnderwear), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasUnderwearT = " + BoolToString(HasUnderwearT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] UnderwearRiskLevel = " + BoolToString(UnderwearRiskLevel), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasUnderwearNoCover = " + BoolToString(HasUnderwearNoCover), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasThong = " + BoolToString(HasThong), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasThongT = " + BoolToString(HasThongT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] ThongRiskLevel = " + BoolToString(ThongRiskLevel), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasThongNoCover = " + BoolToString(HasThongNoCover), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasCString = " + BoolToString(HasCString), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasCStringT = " + BoolToString(HasCStringT), LogType::NPCArmorScan);
				Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] CStringRiskLevel = " + BoolToString(CStringRiskLevel), LogType::NPCArmorScan);

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
		Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Analysis Succeeded!", LogType::NPCArmorScan);
	}
}

void ExternalNPCFemaleAnalyze(RE::StaticFunctionTag*, RE::Actor* akFemale) {
	NPCFemaleScan::NPCFemaleAnalyze(akFemale);
}