#include "Core.h"
#include "Config.h"
#include "Logger.h"
#include "NPCArmorScan.h"

bool NPCTopCurtainCover = false;
bool NPCPelvicCurtainCover = false;
bool NPCAssCurtainCover = false;

bool NPCChestCover = false;
bool NPCBraCover = false;

bool NPCAssCover = false;
bool NPCGenitalCover = false;
bool NPCUnderwearCover = false;

RE::Actor* thisActor;

bool CurtainCheck(int Type, bool IsTransparent, int Level) {
	logs::info("<C++ NPCFemaleArmorScan> [CurtainCheck] START");

	int Roll = 0;
	int Odds = 0;

	std::string TypeString = "None";

	if (Type == ChestType) {
		TypeString = "Chest";
		Roll = NPCTopCurtainRoll;
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
		Roll = NPCPelvicCurtainRoll;
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
		Roll = NPCAssCurtainRoll;
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

	logs::info("<C++ NPCFemaleArmorScan> [CurtainCheck] Roll = {}", Roll);
	logs::info("<C++ NPCFemaleArmorScan> [CurtainCheck] Odds = {}", Odds);

	logs::info("<C++ NPCFemaleArmorScan> [CurtainCheck] Type = {}", TypeString);
	logs::info("<C++ NPCFemaleArmorScan> [CurtainCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ NPCFemaleArmorScan> [CurtainCheck] RiskLevel = {}", Level);

	logs::info("<C++ NPCFemaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

	return (Roll > Odds);
}

bool TransparentItemCheck(int Type, int Level) {
	int Roll = 0;
	int Odds = 0;

	std::string TypeString = "None";

	if (Type == TopType) {
		TypeString = "Top";
		Roll = NPCTopTransparentRoll;
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
		Roll = NPCBottomTransparentRoll;
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
		Roll = NPCBraTransparentRoll;
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

		Roll = NPCUnderwearTransparentRoll;
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
		Roll = NPCHotpantsTransparentRoll;
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
		Roll = NPCShowgirlTransparentRoll;
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

	logs::info("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Roll = {}", Roll);
	logs::info("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Odds = {}", Odds);

	logs::info("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Type = {}", TypeString);
	logs::info("<C++ NPCFemaleArmorScan> [TransparentItemCheck] RiskLevel = {}", Level);

	logs::info("<C++ NPCFemaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

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

	logs::info("<C++ NPCFemaleArmorScan> [CStringCheck] Roll = {}", NPCCStringRoll);
	logs::info("<C++ NPCFemaleArmorScan> [CStringCheck] Odds = {}", Odds);

	logs::info("<C++ NPCFemaleArmorScan> [CStringCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ NPCFemaleArmorScan> [CStringCheck] RiskLevel = {}", Level);

	logs::info("<C++ NPCFemaleArmorScan> [CStringCheck] Function Return Value: Is Covering? {}", (NPCCStringRoll > Odds));

	return (NPCCStringRoll > Odds);
}

void AnalyzeBra(bool HasBra, bool HasBraT, int BraRiskLevel, bool HasBraNoCover) {
	if (HasBra) {
		NPCBraCover = false;
		NPCChestCover = true;
	}
	else if (HasBraT) {
		NPCBraCover = false;
		NPCChestCover = TransparentItemCheck(BraType, BraRiskLevel);
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
		NPCTopCurtainCover = CurtainCheck(ChestType, HasChestCurtainT, ChestRiskLevel);
	}
	else {
		NPCTopCurtainCover = false;
	}

	if (HasArmorTop) {
		NPCBraCover = true;
		NPCChestCover = true;
	}
	else if (HasArmorTopT) {
		bool TopCovering = TransparentItemCheck(TopType, TopRiskLevel);

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
		NPCAssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
		NPCGenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
			NPCUnderwearCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
		}
		else if (HasUnderwearT) {
			NPCUnderwearCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
			if (NPCUnderwearCover) {
				NPCAssCover = true;
			}
			else {
				NPCAssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
		}
		else if (HasUnderwearNoCover) {
			NPCUnderwearCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
			NPCAssCover = NPCUnderwearCover;
		}
		else {
			NPCUnderwearCover = true;
			NPCAssCover = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);
		}
	}
	else if (HasHotpantsT && HasShowgirl) {
		NPCAssCover = true;

		if (HasUnderwear || HasThong) {
			NPCGenitalCover = true;
			NPCUnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		}
		else if (HasUnderwearT || HasThongT || HasCString || HasCStringT) {
			NPCUnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);

			if (NPCUnderwearCover) {
				NPCGenitalCover = true;
			}
			else {
				if (HasUnderwearT) {
					NPCGenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
				}
				else if (HasThongT) {
					NPCGenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
				}
				else {
					AnalyzeCString(HasCStringT, CStringRiskLevel);
				}
			}
		}
		else if (HasUnderwearNoCover || HasThongNoCover) {
			NPCUnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
			NPCGenitalCover = NPCUnderwearCover;
		}
		else {
			NPCUnderwearCover = true;
			NPCGenitalCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		}
	}
	else if (HasHotpantsT && HasShowgirlT) {
		bool HotpantsCovering = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		bool ShowgirlCovering = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);

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
				NPCAssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
				NPCGenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
			else if (HasThongT) {
				NPCUnderwearCover = false;
				NPCGenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
			NPCAssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
			NPCGenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
		}
		else if (HasThongT) {
			NPCUnderwearCover = false;
			NPCGenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
		bool HotpantsCovering = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);

		if (HotpantsCovering) {
			NPCGenitalCover = true;

			if (HasUnderwear) {
				NPCUnderwearCover = false;
				NPCAssCover = true;
			}
			else if (HasUnderwearT) {
				NPCUnderwearCover = false;
				NPCAssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
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
		bool ShowgirlCovering = TransparentItemCheck(ShowgirlType, ShowgirlRiskLevel);

		if (ShowgirlCovering) {
			NPCAssCover = true;

			if (HasUnderwear || HasThong) {
				NPCUnderwearCover = false;
				NPCGenitalCover = true;
			}
			else if (HasUnderwearT) {
				NPCUnderwearCover = false;
				NPCGenitalCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
			else if (HasThongT) {
				NPCUnderwearCover = false;
				NPCGenitalCover = TransparentItemCheck(ThongType, ThongRiskLevel);
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
		NPCPelvicCurtainCover = CurtainCheck(PelvicType, HasPelvicCurtainT, PelvicRiskLevel);
	}
	else {
		NPCPelvicCurtainCover = false;
	}

	if (HasAsscurtain || HasAssCurtainT) {
		NPCAssCurtainCover = CurtainCheck(AssType, HasAssCurtainT, AssRiskLevel);
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
		NPCUnderwearCover = TransparentItemCheck(BottomType, BottomRiskLevel);

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

	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Nude Faction Rank: {}", thisActor->GetFactionRank(NudeFaction, true));
	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Topless Faction Rank: {}", thisActor->GetFactionRank(ToplessFaction, true));
	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Bottomless Faction Rank: {}", thisActor->GetFactionRank(BottomlessFaction, true));
	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Showing Bra Faction Rank: {}", thisActor->GetFactionRank(ShowingBraFaction, true));
	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Showing Chest Faction Rank: {}", thisActor->GetFactionRank(ShowingChestFaction, true));
	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Showing Underwear Faction Rank: {}", thisActor->GetFactionRank(ShowingUnderwearFaction, true));
	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Showing Genitals Faction Rank: {}", thisActor->GetFactionRank(ShowingGenitalsFaction, true));
	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Showing Ass Faction Rank: {}", thisActor->GetFactionRank(ShowingAssFaction, true));

	logs::info("<C++ NPCFemaleArmorScan> [Finalize] Female Scan Completed");
}

bool VanillaArmorCheck() {
	logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] START");

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
		logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: {}", HasCurtainKeyword);

		bool HasTopKeyword =
			(
				BodyItem->HasKeyword(ArmorTop) ||
				BodyItem->HasKeyword(ArmorTopT_Low) || BodyItem->HasKeyword(ArmorTopT) || BodyItem->HasKeyword(ArmorTopT_High) ||
				BodyItem->HasKeyword(ArmorTop_NoCover)
				);
		logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: {}", HasTopKeyword);

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
		logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: {}", HasBottomKeyword);

		bool HasBraKeyword =
			(
				BodyItem->HasKeyword(Bra) ||
				BodyItem->HasKeyword(BraT_Low) || BodyItem->HasKeyword(BraT) || BodyItem->HasKeyword(BraT_High) ||
				BodyItem->HasKeyword(Bra_NoCover)
				);
		logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: {}", HasBraKeyword);

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
		logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: {}", HasUnderwearKeyword);

		bool HasExtraKeyword =
			(
				BodyItem->HasKeyword(NearlyNaked) ||
				BodyItem->HasKeyword(NipplePasties) ||
				BodyItem->HasKeyword(VaginaPasties) ||
				BodyItem->HasKeyword(Microskirt) ||
				BodyItem->HasKeyword(EffectivelyNaked)
				);
		logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: {}", HasExtraKeyword);

		logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? {}", (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword));
		return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
	}
	logs::info("<C++ NPCFemaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? false");
	return false;
}

void NPCFemaleAnalyze(RE::Actor* akFemale) {
	logs::critical("<C++ NPCFemaleArmorScan> [FemaleAnalyze] NPC Female Analysis Triggered!");

	if (akFemale == nullptr) {
		logs::critical("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Actor is None/nullptr!!!");
		return;
	}

	logs::critical("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Analyzing Actor: {}", akFemale->GetName());

	if (akFemale->GetActorBase()->IsFemale() == false) {
		logs::critical("<C++ NPCFemaleArmorScan> [FemaleAnalyze] ERROR: Actor {} is Male!", akFemale->GetName());
		return;
	}

	thisActor = akFemale;

	logs::critical("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Start analysis...");
	if (ActorWornHasKeyword(thisActor, CoversAll)) {
		Log("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Covers All keyword detected", info);

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

		int ChestRiskLevel = RiskNone;
		if (ActorWornHasKeyword(thisActor, ChestFlashRiskLow)) {
			ChestRiskLevel = RiskLow;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRisk)) {
			ChestRiskLevel = RiskNormal;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRiskHigh)) {
			ChestRiskLevel = RiskHigh;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRiskExtreme)) {
			ChestRiskLevel = RiskExtreme;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRiskUltra)) {
			ChestRiskLevel = RiskUltra;
		}

		bool HasPelvicCurtain = (ActorWornHasKeyword(thisActor, PelvicCurtain) || ActorWornHasKeyword(thisActor, Miniskirt));
		bool HasPelvicCurtainT = (ActorWornHasKeyword(thisActor, PelvicCurtainT) || ActorWornHasKeyword(thisActor, MiniskirtT));

		int PelvicRiskLevel = RiskNone;
		if (ActorWornHasKeyword(thisActor, PelvicFlashRiskLow)) {
			PelvicRiskLevel = RiskLow;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRisk)) {
			PelvicRiskLevel = RiskNormal;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskHigh)) {
			PelvicRiskLevel = RiskHigh;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskExtreme)) {
			PelvicRiskLevel = RiskExtreme;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskUltra)) {
			PelvicRiskLevel = RiskUltra;
		}

		bool HasAssCurtain = (ActorWornHasKeyword(thisActor, AssCurtain) || ActorWornHasKeyword(thisActor, Miniskirt));
		bool HasAssCurtainT = (ActorWornHasKeyword(thisActor, AssCurtainT) || ActorWornHasKeyword(thisActor, MiniskirtT));

		int AssRiskLevel = RiskNone;
		if (ActorWornHasKeyword(thisActor, AssFlashRiskLow)) {
			AssRiskLevel = RiskLow;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRisk)) {
			AssRiskLevel = RiskNormal;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRiskHigh)) {
			AssRiskLevel = RiskHigh;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRiskExtreme)) {
			AssRiskLevel = RiskExtreme;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRiskUltra)) {
			AssRiskLevel = RiskUltra;
		}

		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasChestCurtain = {}", HasChestCurtain);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasChestCurtainT = {}", HasChestCurtainT);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] ChestRiskLevel = {}", ChestRiskLevel);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasPelvicCurtain = {}", HasPelvicCurtain);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasPelvicCurtainT = {}", HasPelvicCurtainT);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] PelvicRiskLevel = {}", PelvicRiskLevel);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasAssCurtain = {}", HasAssCurtain);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasAssCurtainT = {}", HasAssCurtainT);
		logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] AssRiskLevel = {}", AssRiskLevel);

		if (VanillaArmorCheck() == true) {
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Armor is considered vanilla");

			NPCTopCurtainCover = CurtainCheck(ChestType, HasChestCurtainT, ChestRiskLevel);
			NPCPelvicCurtainCover = CurtainCheck(PelvicType, HasPelvicCurtainT, PelvicRiskLevel);
			NPCAssCurtainCover = CurtainCheck(AssType, HasAssCurtainT, AssRiskLevel);

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
			int TopRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, ArmorTopT_Low)) {
				TopRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorTopT)) {
				TopRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorTopT_High)) {
				TopRiskLevel = RiskHigh;
			}
			bool HasArmorTopT = TopRiskLevel > RiskNone;

			//Bra
			bool HasBra = ActorWornHasKeyword(thisActor, Bra);
			int BraRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, BraT_Low)) {
				BraRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, BraT)) {
				BraRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, BraT_High)) {
				BraRiskLevel = RiskHigh;
			}
			bool HasBraT = BraRiskLevel > RiskNone;
			bool HasBraNoCover = ActorWornHasKeyword(thisActor, Bra_NoCover);

			/*
			================
			BOTTOM VARIABLES
			================
			*/

			//Bottom Armor
			bool HasArmorBottom = ActorWornHasKeyword(thisActor, ArmorBottom);
			int BottomRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, ArmorBottomT_Low)) {
				BottomRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorBottomT)) {
				BottomRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorBottomT_High)) {
				BottomRiskLevel = RiskHigh;
			}
			bool HasArmorBottomT = BottomRiskLevel > RiskNone;

			//Hotpants
			bool HasHotpants = ActorWornHasKeyword(thisActor, Hotpants);
			int HotpantsRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, HotpantsT_Low)) {
				HotpantsRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, HotpantsT)) {
				HotpantsRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, HotpantsT_High)) {
				HotpantsRiskLevel = RiskHigh;
			}
			bool HasHotpantsT = HotpantsRiskLevel > RiskNone;

			//Showgirl Skirt
			bool HasShowgirl = ActorWornHasKeyword(thisActor, ShowgirlSkirt);
			int ShowgirlRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, ShowgirlSkirtT_Low)) {
				ShowgirlRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, ShowgirlSkirtT)) {
				ShowgirlRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, ShowgirlSkirtT_High)) {
				ShowgirlRiskLevel = RiskHigh;
			}
			bool HasShowgirlT = ShowgirlRiskLevel > RiskNone;

			//Underwear
			bool HasUnderwear = ActorWornHasKeyword(thisActor, Underwear);
			int UnderwearRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, UnderwearT_Low)) {
				UnderwearRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, UnderwearT)) {
				UnderwearRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, UnderwearT_High)) {
				UnderwearRiskLevel = RiskHigh;
			}
			bool HasUnderwearT = UnderwearRiskLevel > RiskNone;
			bool HasUnderwearNoCover = ActorWornHasKeyword(thisActor, Underwear_NoCover);

			//Thong
			bool HasThong = ActorWornHasKeyword(thisActor, Thong);
			int ThongRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, ThongT_Low)) {
				ThongRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, ThongT)) {
				ThongRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, ThongT_High)) {
				ThongRiskLevel = RiskHigh;
			}
			bool HasThongT = ThongRiskLevel > RiskNone;
			bool HasThongNoCover = ActorWornHasKeyword(thisActor, Thong_NoCover);

			//CString
			bool HasCString = ActorWornHasKeyword(thisActor, CString);
			int CStringRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, CStringT_Low)) {
				CStringRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, CStringT)) {
				CStringRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, CStringT_High)) {
				CStringRiskLevel = RiskHigh;
			}
			bool HasCStringT = CStringRiskLevel > RiskNone;

			//Debug Results
			//Top
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorTop = {}", HasArmorTop);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorTopT = {}", HasArmorTopT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] TopRiskLevel = {}", TopRiskLevel);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasBra = {}", HasBra);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasBraT = {}", HasBraT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] BraRiskLevel = {}", BraRiskLevel);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasBraNoCover = {}", HasBraNoCover);

			//Bottom
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorBottom = {}", HasArmorBottom);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasArmorBottomT = {}", HasArmorBottomT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] BottomRiskLevel = {}", BottomRiskLevel);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasHotpants = {}", HasHotpants);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasHotpantsT = {}", HasHotpantsT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HotpantsRiskLevel = {}", HotpantsRiskLevel);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasShowgirl = {}", HasShowgirl);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasShowgirlT = {}", HasShowgirlT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] ShowgirlRiskLevel = {}", ShowgirlRiskLevel);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasUnderwear = {}", HasUnderwear);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasUnderwearT = {}", HasUnderwearT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] UnderwearRiskLevel = {}", UnderwearRiskLevel);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasUnderwearNoCover = {}", HasUnderwearNoCover);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasThong = {}", HasThong);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasThongT = {}", HasThongT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] ThongRiskLevel = {}", ThongRiskLevel);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasThongNoCover = {}", HasThongNoCover);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasCString = {}", HasCString);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] HasCStringT = {}", HasCStringT);
			logs::info("<C++ NPCFemaleArmorScan> [FemaleAnalyze] CStringRiskLevel = {}", CStringRiskLevel);

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
	logs::critical("<C++ NPCFemaleArmorScan> [FemaleAnalyze] Analysis Succeeded!");
}

void ExternalNPCFemaleAnalyze(RE::StaticFunctionTag*, RE::Actor* akFemale) {
	NPCFemaleAnalyze(akFemale);
}