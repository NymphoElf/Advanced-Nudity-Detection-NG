#include "PlayerArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "Logger.h"

bool CurtainCheck(int Type, bool IsTransparent, int Level) {
	logs::info("<C++ FemaleArmorScan> [CurtainCheck] START");

	int Roll = 0;
	int Odds = 0;

	std::string TypeString = "None";

	if (Type == ChestType) {
		TypeString = "Chest";
		Roll = TopCurtainRoll;
		if (Level == RiskLow) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsLow];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsLow];
			}
		}
		else if (Level == RiskNormal) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOdds];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOdds];
			}
		}
		else if (Level == RiskHigh) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsHigh];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsHigh];
			}
		}
		else if (Level == RiskExtreme) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsExtreme];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsExtreme];
			}
		}
		else if (Level == RiskUltra) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsUltra];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsUltra];
			}
		}
	}
	else if (Type == PelvicType) {
		TypeString = "Pelvic";
		Roll = PelvicCurtainRoll;
		if (Level == RiskLow) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsLow];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsLow];
			}
		}
		else if (Level == RiskNormal) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOdds];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOdds];
			}
		}
		else if (Level == RiskHigh) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsHigh];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsHigh];
			}
		}
		else if (Level == RiskExtreme) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsExtreme];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsExtreme];
			}
		}
		else if (Level == RiskUltra) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsUltra];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsUltra];
			}
		}
	}
	else if (Type == AssType) {
		TypeString = "Ass";
		Roll = AssCurtainRoll;
		if (Level == RiskLow) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsLow];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsLow];
			}
		}
		else if (Level == RiskNormal) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOdds];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOdds];
			}
		}
		else if (Level == RiskHigh) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsHigh];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsHigh];
			}
		}
		else if (Level == RiskExtreme) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsExtreme];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsExtreme];
			}
		}
		else if (Level == RiskUltra) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsUltra];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsUltra];
			}
		}
	}

	logs::info("<C++ FemaleArmorScan> [CurtainCheck] Roll = {}", Roll);
	logs::info("<C++ FemaleArmorScan> [CurtainCheck] Odds = {}", Odds);

	logs::info("<C++ FemaleArmorScan> [CurtainCheck] Type = {}", TypeString);
	logs::info("<C++ FemaleArmorScan> [CurtainCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ FemaleArmorScan> [CurtainCheck] RiskLevel = {}", Level);

	logs::info("<C++ FemaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

	return (Roll > Odds);
}

bool TransparentItemCheck(int Type, int Level) {
	int Roll = 0;
	int Odds = 0;

	std::string TypeString = "None";

	if (Type == TopType) {
		TypeString = "Top";
		Roll = TopTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentTopArmorOdds_Low];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentTopArmorOdds];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentTopArmorOdds_High];
		}
	}
	else if (Type == BottomType) {
		TypeString = "Bottom";
		Roll = BottomTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentBottomArmorOdds_Low];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentBottomArmorOdds];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentBottomArmorOdds_High];
		}
	}
	else if (Type == BraType) {
		TypeString = "Bra";
		Roll = BraTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentBraOdds_Low];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentBraOdds];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentBraOdds_High];
		}
	}
	else if (Type == UnderwearType || Type == ThongType) {
		if (Type == UnderwearType) {
			TypeString = "Underwear";
		}
		else {
			TypeString = "Thong";
		}

		Roll = UnderwearTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentUnderwearOdds_Low];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentUnderwearOdds];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentUnderwearOdds_High];
		}
	}
	else if (Type == HotpantsType) {
		TypeString = "Hotpants";
		Roll = HotpantsTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentHotpantsOdds_Low];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentHotpantsOdds];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentHotpantsOdds_High];
		}
	}
	else if (Type == ShowgirlType) {
		TypeString = "Showgirl";
		Roll = ShowgirlTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentShowgirlOdds_Low];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentShowgirlOdds];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentShowgirlOdds_High];
		}
	}

	logs::info("<C++ FemaleArmorScan> [TransparentItemCheck] Roll = {}", Roll);
	logs::info("<C++ FemaleArmorScan> [TransparentItemCheck] Odds = {}", Odds);

	logs::info("<C++ FemaleArmorScan> [TransparentItemCheck] Type = {}", TypeString);
	logs::info("<C++ FemaleArmorScan> [TransparentItemCheck] RiskLevel = {}", Level);

	logs::info("<C++ FemaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

	return (Roll > Odds);
}

bool CStringCheck(bool IsTransparent, int Level) {
	int Odds = 0;

	if (IsTransparent == false) {
		Odds = FlashingOdds[CStringOdds];
	}
	else if (Level == RiskLow) {
		Odds = FlashingOdds[TransparentCStringOdds_Low];
	}
	else if (Level == RiskNormal) {
		Odds = FlashingOdds[TransparentCStringOdds];
	}
	else if (Level == RiskHigh) {
		Odds = FlashingOdds[TransparentCStringOdds_High];
	}

	logs::info("<C++ FemaleArmorScan> [CStringCheck] Roll = {}", CStringRoll);
	logs::info("<C++ FemaleArmorScan> [CStringCheck] Odds = {}", Odds);

	logs::info("<C++ FemaleArmorScan> [CStringCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ FemaleArmorScan> [CStringCheck] RiskLevel = {}", Level);

	logs::info("<C++ FemaleArmorScan> [CStringCheck] Function Return Value: Is Covering? {}", (CStringRoll > Odds));

	return (CStringRoll > Odds);
}

void AnalyzeBra(bool HasBra, bool HasBraT, int BraRiskLevel, bool HasBraNoCover) {
	if (HasBra) {
		PlayerCoverage::BraCover = false;
		PlayerCoverage::ChestCover = true;
	}
	else if (HasBraT) {
		PlayerCoverage::BraCover = false;
		PlayerCoverage::ChestCover = TransparentItemCheck(BraType, BraRiskLevel);
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
		PlayerCoverage::TopCurtainCover = CurtainCheck(ChestType, HasChestCurtainT, ChestRiskLevel);
	}
	else {
		PlayerCoverage::TopCurtainCover = false;
	}

	if (HasArmorTop) {
		PlayerCoverage::BraCover = true;
		PlayerCoverage::ChestCover = true;
	}
	else if (HasArmorTopT) {
		bool TopCovering = TransparentItemCheck(TopType, TopRiskLevel);

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
		PlayerCoverage::AssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
		PlayerCoverage::GenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
			PlayerCoverage::UnderwearCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
		}
		else if (HasUnderwearT) {
			PlayerCoverage::UnderwearCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
			if (PlayerCoverage::UnderwearCover) {
				PlayerCoverage::AssCover = true;
			}
			else {
				PlayerCoverage::AssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
		}
		else if (HasUnderwearNoCover) {
			PlayerCoverage::UnderwearCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
			PlayerCoverage::AssCover = PlayerCoverage::UnderwearCover;
		}
		else {
			PlayerCoverage::UnderwearCover = true;
			PlayerCoverage::AssCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
		}
	}
	else if (HasHotpantsT && HasShowgirl) {
		PlayerCoverage::AssCover = true;

		if (HasUnderwear || HasThong) {
			PlayerCoverage::GenitalCover = true;
			PlayerCoverage::UnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		}
		else if (HasUnderwearT || HasThongT || HasCString || HasCStringT) {
			PlayerCoverage::UnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);

			if (PlayerCoverage::UnderwearCover) {
				PlayerCoverage::GenitalCover = true;
			}
			else {
				if (HasUnderwearT) {
					PlayerCoverage::GenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
				}
				else if (HasThongT) {
					PlayerCoverage::GenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
				}
				else {
					AnalyzeCString(HasCStringT, CStringRiskLevel);
				}
			}
		}
		else if (HasUnderwearNoCover || HasThongNoCover) {
			PlayerCoverage::UnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
			PlayerCoverage::GenitalCover = PlayerCoverage::UnderwearCover;
		}
		else {
			PlayerCoverage::UnderwearCover = true;
			PlayerCoverage::GenitalCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		}
	}
	else if (HasHotpantsT && HasShowgirlT) {
		bool HotpantsCovering = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		bool ShowgirlCovering = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);

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
				PlayerCoverage::AssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
				PlayerCoverage::GenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
			else if (HasThongT) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
			PlayerCoverage::AssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
			PlayerCoverage::GenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
		}
		else if (HasThongT) {
			PlayerCoverage::UnderwearCover = false;
			PlayerCoverage::GenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
		bool HotpantsCovering = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);

		if (HotpantsCovering) {
			PlayerCoverage::GenitalCover = true;

			if (HasUnderwear) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::AssCover = true;
			}
			else if (HasUnderwearT) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::AssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
		bool ShowgirlCovering = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);

		if (ShowgirlCovering) {
			PlayerCoverage::AssCover = true;

			if (HasUnderwear || HasThong) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = true;
			}
			else if (HasUnderwearT) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
			else if (HasThongT) {
				PlayerCoverage::UnderwearCover = false;
				PlayerCoverage::GenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
		PlayerCoverage::PelvicCurtainCover = CurtainCheck(PelvicType, HasPelvicCurtainT, PelvicRiskLevel);
	}
	else {
		PlayerCoverage::PelvicCurtainCover = false;
	}

	if (HasAsscurtain || HasAssCurtainT) {
		PlayerCoverage::AssCurtainCover = CurtainCheck(AssType, HasAssCurtainT, AssRiskLevel);
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
		PlayerCoverage::UnderwearCover = TransparentItemCheck(BottomType, BottomRiskLevel);

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
	if (PlayerCoverage::TopCurtainCover) {
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

	logs::info("<C++ FemaleArmorScan> [Finalize] Nude Faction Rank: {}", Player->GetFactionRank(NudeFaction, true));
	logs::info("<C++ FemaleArmorScan> [Finalize] Topless Faction Rank: {}", Player->GetFactionRank(ToplessFaction, true));
	logs::info("<C++ FemaleArmorScan> [Finalize] Bottomless Faction Rank: {}", Player->GetFactionRank(BottomlessFaction, true));
	logs::info("<C++ FemaleArmorScan> [Finalize] Showing Bra Faction Rank: {}", Player->GetFactionRank(ShowingBraFaction, true));
	logs::info("<C++ FemaleArmorScan> [Finalize] Showing Chest Faction Rank: {}", Player->GetFactionRank(ShowingChestFaction, true));
	logs::info("<C++ FemaleArmorScan> [Finalize] Showing Underwear Faction Rank: {}", Player->GetFactionRank(ShowingUnderwearFaction, true));
	logs::info("<C++ FemaleArmorScan> [Finalize] Showing Genitals Faction Rank: {}", Player->GetFactionRank(ShowingGenitalsFaction, true));
	logs::info("<C++ FemaleArmorScan> [Finalize] Showing Ass Faction Rank: {}", Player->GetFactionRank(ShowingAssFaction, true));

	logs::info("<C++ FemaleArmorScan> [Finalize] Player Female Scan Completed");
}

bool VanillaArmorCheck() {
	logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] START");
	
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
		logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: {}", HasCurtainKeyword);

		bool HasTopKeyword =
			(
				BodyItem->HasKeyword(ArmorTop) ||
				BodyItem->HasKeyword(ArmorTopT_Low) || BodyItem->HasKeyword(ArmorTopT) || BodyItem->HasKeyword(ArmorTopT_High) ||
				BodyItem->HasKeyword(ArmorTop_NoCover)
				);
		logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: {}", HasTopKeyword);

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
		logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: {}", HasBottomKeyword);

		bool HasBraKeyword =
			(
				BodyItem->HasKeyword(Bra) ||
				BodyItem->HasKeyword(BraT_Low) || BodyItem->HasKeyword(BraT) || BodyItem->HasKeyword(BraT_High) ||
				BodyItem->HasKeyword(Bra_NoCover)
				);
		logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: {}", HasBraKeyword);

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
		logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: {}", HasUnderwearKeyword);

		bool HasExtraKeyword =
			(
				BodyItem->HasKeyword(NearlyNaked) ||
				BodyItem->HasKeyword(NipplePasties) ||
				BodyItem->HasKeyword(VaginaPasties) ||
				BodyItem->HasKeyword(Microskirt) ||
				BodyItem->HasKeyword(EffectivelyNaked)
				);
		logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: {}", HasExtraKeyword);

		logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? {}", (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword));
		return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
	}
	logs::info("<C++ FemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? false");
	return false;
}

void FemaleAnalyze() {
	logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] Player Female Analysis Triggered!");
	
	bool ShouldEscape = false;

	logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] Check if Player is PlayerRef...");
	if (Player == nullptr || Player->IsPlayerRef() == false) {
		logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] RE::Actor variable not set!!!");
		ShouldEscape = true;
	}

	logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] Check if PlayerBase is Player...");
	if (PlayerBase == nullptr || PlayerBase->IsPlayer() == false) {
		logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] RE::TESActorBase variable not set!!!");
		ShouldEscape = true;
	}

	if (ShouldEscape == true) {
		logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] Female Analysis Failed! (Escaped)");
		return;
	}
	
	logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] Start analysis...");
	if (PlayerWornHasKeyword(CoversAll)) {
		Log("<C++ FemaleArmorScan> [FemaleAnalyze] Covers All keyword detected", info);

		PlayerCoverage::TopCurtainCover = true;
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

		int ChestRiskLevel = RiskNone;
		if (PlayerWornHasKeyword(ChestFlashRiskLow)) {
			ChestRiskLevel = RiskLow;
		}
		else if (PlayerWornHasKeyword(ChestFlashRisk)) {
			ChestRiskLevel = RiskNormal;
		}
		else if (PlayerWornHasKeyword(ChestFlashRiskHigh)) {
			ChestRiskLevel = RiskHigh;
		}
		else if (PlayerWornHasKeyword(ChestFlashRiskExtreme)) {
			ChestRiskLevel = RiskExtreme;
		}
		else if (PlayerWornHasKeyword(ChestFlashRiskUltra)) {
			ChestRiskLevel = RiskUltra;
		}

		bool HasPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain) || PlayerWornHasKeyword(Miniskirt));
		bool HasPelvicCurtainT = (PlayerWornHasKeyword(PelvicCurtainT) || PlayerWornHasKeyword(MiniskirtT));

		int PelvicRiskLevel = RiskNone;
		if (PlayerWornHasKeyword(PelvicFlashRiskLow)) {
			PelvicRiskLevel = RiskLow;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRisk)) {
			PelvicRiskLevel = RiskNormal;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRiskHigh)) {
			PelvicRiskLevel = RiskHigh;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRiskExtreme)) {
			PelvicRiskLevel = RiskExtreme;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRiskUltra)) {
			PelvicRiskLevel = RiskUltra;
		}

		bool HasAssCurtain = (PlayerWornHasKeyword(AssCurtain) || PlayerWornHasKeyword(Miniskirt));
		bool HasAssCurtainT = (PlayerWornHasKeyword(AssCurtainT) || PlayerWornHasKeyword(MiniskirtT));

		int AssRiskLevel = RiskNone;
		if (PlayerWornHasKeyword(AssFlashRiskLow)) {
			AssRiskLevel = RiskLow;
		}
		else if (PlayerWornHasKeyword(AssFlashRisk)) {
			AssRiskLevel = RiskNormal;
		}
		else if (PlayerWornHasKeyword(AssFlashRiskHigh)) {
			AssRiskLevel = RiskHigh;
		}
		else if (PlayerWornHasKeyword(AssFlashRiskExtreme)) {
			AssRiskLevel = RiskExtreme;
		}
		else if (PlayerWornHasKeyword(AssFlashRiskUltra)) {
			AssRiskLevel = RiskUltra;
		}

		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasChestCurtain = {}", HasChestCurtain);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasChestCurtainT = {}", HasChestCurtainT);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] ChestRiskLevel = {}", ChestRiskLevel);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasPelvicCurtain = {}", HasPelvicCurtain);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasPelvicCurtainT = {}", HasPelvicCurtainT);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] PelvicRiskLevel = {}", PelvicRiskLevel);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasAssCurtain = {}", HasAssCurtain);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasAssCurtainT = {}", HasAssCurtainT);
		logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] AssRiskLevel = {}", AssRiskLevel);

		if (VanillaArmorCheck() == true) {
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] Armor is considered vanilla");

			PlayerCoverage::TopCurtainCover = CurtainCheck(ChestType, HasChestCurtainT, ChestRiskLevel);
			PlayerCoverage::PelvicCurtainCover = CurtainCheck(PelvicType, HasPelvicCurtainT, PelvicRiskLevel);
			PlayerCoverage::AssCurtainCover = CurtainCheck(AssType, HasAssCurtainT, AssRiskLevel);

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
			int TopRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(ArmorTopT_Low)) {
				TopRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(ArmorTopT)) {
				TopRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(ArmorTopT_High)) {
				TopRiskLevel = RiskHigh;
			}
			bool HasArmorTopT = TopRiskLevel > RiskNone;

			//Bra
			bool HasBra = PlayerWornHasKeyword(Bra);
			int BraRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(BraT_Low)) {
				BraRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(BraT)) {
				BraRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(BraT_High)) {
				BraRiskLevel = RiskHigh;
			}
			bool HasBraT = BraRiskLevel > RiskNone;
			bool HasBraNoCover = PlayerWornHasKeyword(Bra_NoCover);

			/*
			================
			BOTTOM VARIABLES
			================
			*/

			//Bottom Armor
			bool HasArmorBottom = PlayerWornHasKeyword(ArmorBottom);
			int BottomRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(ArmorBottomT_Low)) {
				BottomRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(ArmorBottomT)) {
				BottomRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(ArmorBottomT_High)) {
				BottomRiskLevel = RiskHigh;
			}
			bool HasArmorBottomT = BottomRiskLevel > RiskNone;

			//Hotpants
			bool HasHotpants = PlayerWornHasKeyword(Hotpants);
			int HotpantsRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(HotpantsT_Low)) {
				HotpantsRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(HotpantsT)) {
				HotpantsRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(HotpantsT_High)) {
				HotpantsRiskLevel = RiskHigh;
			}
			bool HasHotpantsT = HotpantsRiskLevel > RiskNone;

			//Showgirl Skirt
			bool HasShowgirl = PlayerWornHasKeyword(ShowgirlSkirt);
			int ShowgirlRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(ShowgirlSkirtT_Low)) {
				ShowgirlRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(ShowgirlSkirtT)) {
				ShowgirlRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(ShowgirlSkirtT_High)) {
				ShowgirlRiskLevel = RiskHigh;
			}
			bool HasShowgirlT = ShowgirlRiskLevel > RiskNone;

			//Underwear
			bool HasUnderwear = PlayerWornHasKeyword(Underwear);
			int UnderwearRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(UnderwearT_Low)) {
				UnderwearRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(UnderwearT)) {
				UnderwearRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(UnderwearT_High)) {
				UnderwearRiskLevel = RiskHigh;
			}
			bool HasUnderwearT = UnderwearRiskLevel > RiskNone;
			bool HasUnderwearNoCover = PlayerWornHasKeyword(Underwear_NoCover);

			//Thong
			bool HasThong = PlayerWornHasKeyword(Thong);
			int ThongRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(ThongT_Low)) {
				ThongRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(ThongT)) {
				ThongRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(ThongT_High)) {
				ThongRiskLevel = RiskHigh;
			}
			bool HasThongT = ThongRiskLevel > RiskNone;
			bool HasThongNoCover = PlayerWornHasKeyword(Thong_NoCover);

			//CString
			bool HasCString = PlayerWornHasKeyword(CString);
			int CStringRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(CStringT_Low)) {
				CStringRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(CStringT)) {
				CStringRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(CStringT_High)) {
				CStringRiskLevel = RiskHigh;
			}
			bool HasCStringT = CStringRiskLevel > RiskNone;
			
			//Debug Results
			//Top
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorTop = {}", HasArmorTop);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorTopT = {}", HasArmorTopT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] TopRiskLevel = {}", TopRiskLevel);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasBra = {}", HasBra);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasBraT = {}", HasBraT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] BraRiskLevel = {}", BraRiskLevel);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasBraNoCover = {}", HasBraNoCover);

			//Bottom
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorBottom = {}", HasArmorBottom);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasArmorBottomT = {}", HasArmorBottomT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] BottomRiskLevel = {}", BottomRiskLevel);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasHotpants = {}", HasHotpants);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasHotpantsT = {}", HasHotpantsT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HotpantsRiskLevel = {}", HotpantsRiskLevel);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasShowgirl = {}", HasShowgirl);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasShowgirlT = {}", HasShowgirlT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] ShowgirlRiskLevel = {}", ShowgirlRiskLevel);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwear = {}", HasUnderwear);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwearT = {}", HasUnderwearT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] UnderwearRiskLevel = {}", UnderwearRiskLevel);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasUnderwearNoCover = {}", HasUnderwearNoCover);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasThong = {}", HasThong);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasThongT = {}", HasThongT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] ThongRiskLevel = {}", ThongRiskLevel);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasThongNoCover = {}", HasThongNoCover);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasCString = {}", HasCString);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] HasCStringT = {}", HasCStringT);
			logs::info("<C++ FemaleArmorScan> [FemaleAnalyze] CStringRiskLevel = {}", CStringRiskLevel);

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
	logs::critical("<C++ FemaleArmorScan> [FemaleAnalyze] Analysis Succeeded!");
}

void ExternalFemaleAnalyze(RE::StaticFunctionTag*) {
	FemaleAnalyze();
}