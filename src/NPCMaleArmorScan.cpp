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
	logs::info("<C++ NPCMaleArmorScan> [CurtainCheck] START");

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

	logs::info("<C++ NPCMaleArmorScan> [CurtainCheck] Roll = {}", Roll);
	logs::info("<C++ NPCMaleArmorScan> [CurtainCheck] Odds = {}", Odds);

	logs::info("<C++ NPCMaleArmorScan> [CurtainCheck] Type = {}", TypeString);
	logs::info("<C++ NPCMaleArmorScan> [CurtainCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ NPCMaleArmorScan> [CurtainCheck] RiskLevel = {}", Level);

	logs::info("<C++ NPCMaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

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
	else if (Type == HimboType) {
		TypeString = "Himbo";
		Roll = NPCShowgirlTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentHimboOdds_Low];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentHimboOdds];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentHimboOdds_High];
		}
	}

	logs::info("<C++ NPCMaleArmorScan> [TransparentItemCheck] Roll = {}", Roll);
	logs::info("<C++ NPCMaleArmorScan> [TransparentItemCheck] Odds = {}", Odds);

	logs::info("<C++ NPCMaleArmorScan> [TransparentItemCheck] Type = {}", TypeString);
	logs::info("<C++ NPCMaleArmorScan> [TransparentItemCheck] RiskLevel = {}", Level);

	logs::info("<C++ NPCMaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

	return (Roll > Odds);
}

bool BananaHammockCheck(bool IsTransparent, int Level) {
	int Odds = 0;

	if (IsTransparent == false) {
		Odds = FlashingOdds[BananaHammockOdds];
	}
	else if (Level == RiskLow) {
		Odds = FlashingOdds[TransparentBananaHammockOdds_Low];
	}
	else if (Level == RiskNormal) {
		Odds = FlashingOdds[TransparentBananaHammockOdds];
	}
	else if (Level == RiskHigh) {
		Odds = FlashingOdds[TransparentBananaHammockOdds_High];
	}

	logs::info("<C++ NPCMaleArmorScan> [BananaHammockCheck] Roll = {}", NPCCStringRoll);
	logs::info("<C++ NPCMaleArmorScan> [BananaHammockCheck] Odds = {}", Odds);

	logs::info("<C++ NPCMaleArmorScan> [BananaHammockCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ NPCMaleArmorScan> [BananaHammockCheck] RiskLevel = {}", Level);

	logs::info("<C++ NPCMaleArmorScan> [BananaHammockCheck] Function Return Value: Is Covering? {}", (NPCCStringRoll > Odds));

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

void AnalyzeBananaHammock(bool HasBananaHammockT, int BananaHammockRiskLevel) {
	NPCGenitalCover = BananaHammockCheck(HasBananaHammockT, BananaHammockRiskLevel);
	NPCUnderwearCover = !NPCGenitalCover;
}

void AnalyzeUnderwear
(
	bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
	bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
	bool HasBananaHammock, bool HasBananaHammockT, int BananaHammockRiskLevel
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
	bool HasHotpants, bool HasHotpantsT, int HotpantsRiskLevel,
	bool HasHimbo, bool HasHimboT, int HimboRiskLevel,
	bool HasUnderwear, bool HasUnderwearT, int UnderwearRiskLevel, bool HasUnderwearNoCover,
	bool HasThong, bool HasThongT, int ThongRiskLevel, bool HasThongNoCover,
	bool HasBananaHammock, bool HasBananaHammockT, int BananaHammockRiskLevel
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
			NPCUnderwearCover = TransparentItemCheck(HimboType, HimboRiskLevel);
		}
		else if (HasUnderwearT) {
			NPCUnderwearCover = TransparentItemCheck(HimboType, HimboRiskLevel);
			if (NPCUnderwearCover) {
				NPCAssCover = true;
			}
			else {
				NPCAssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
		}
		else if (HasUnderwearNoCover) {
			NPCUnderwearCover = TransparentItemCheck(HimboType, HimboRiskLevel);
			NPCAssCover = NPCUnderwearCover;
		}
		else {
			NPCUnderwearCover = true;
			NPCAssCover = TransparentItemCheck(HimboType, HimboRiskLevel);
		}
	}
	else if (HasHotpantsT && HasHimbo) {
		NPCAssCover = true;

		if (HasUnderwear || HasThong) {
			NPCGenitalCover = true;
			NPCUnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		}
		else if (HasUnderwearT || HasThongT || HasBananaHammock || HasBananaHammockT) {
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
					AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
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
	else if (HasHotpantsT && HasHimboT) {
		bool HotpantsCovering = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		bool HimboCovering = TransparentItemCheck(HimboType, HimboRiskLevel);

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
		else if (!HotpantsCovering && HimboCovering) {
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
	else if (HasHimbo) {
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
				HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
			);
		}
	}
	else if (HasHimboT) {
		bool HimboCovering = TransparentItemCheck(HimboType, HimboRiskLevel);

		if (HimboCovering) {
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
			if (ActorWornHasKeyword(thisActor, ArmorTopT_Low_Male) || ActorWornHasKeyword(thisActor, ArmorTopT_Male) || ActorWornHasKeyword(thisActor, ArmorTopT_High_Male)
				|| ActorWornHasKeyword(thisActor, ArmorTop_NoCover_Male) || ActorWornHasKeyword(thisActor, NipplePasties_Male)) {
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
				ActorWornHasKeyword(thisActor, ArmorBottom_NoCover_Male) ||
				ActorWornHasKeyword(thisActor, HotpantsT_Low_Male) || ActorWornHasKeyword(thisActor, HotpantsT_Male) || ActorWornHasKeyword(thisActor, HotpantsT_High_Male) ||
				ActorWornHasKeyword(thisActor, HimboSkirtT_Low) || ActorWornHasKeyword(thisActor, HimboSkirtT) || ActorWornHasKeyword(thisActor, HimboSkirtT_High) ||
				ActorWornHasKeyword(thisActor, Microskirt_Male)
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

	logs::info("<C++ NPCMaleArmorScan> [Finalize] Nude Faction Rank: {}", thisActor->GetFactionRank(NudeFaction, true));
	logs::info("<C++ NPCMaleArmorScan> [Finalize] Topless Faction Rank: {}", thisActor->GetFactionRank(ToplessFaction, true));
	logs::info("<C++ NPCMaleArmorScan> [Finalize] Bottomless Faction Rank: {}", thisActor->GetFactionRank(BottomlessFaction, true));
	logs::info("<C++ NPCMaleArmorScan> [Finalize] Showing Bra Faction Rank: {}", thisActor->GetFactionRank(ShowingBraFaction, true));
	logs::info("<C++ NPCMaleArmorScan> [Finalize] Showing Chest Faction Rank: {}", thisActor->GetFactionRank(ShowingChestFaction, true));
	logs::info("<C++ NPCMaleArmorScan> [Finalize] Showing Underwear Faction Rank: {}", thisActor->GetFactionRank(ShowingUnderwearFaction, true));
	logs::info("<C++ NPCMaleArmorScan> [Finalize] Showing Genitals Faction Rank: {}", thisActor->GetFactionRank(ShowingGenitalsFaction, true));
	logs::info("<C++ NPCMaleArmorScan> [Finalize] Showing Ass Faction Rank: {}", thisActor->GetFactionRank(ShowingAssFaction, true));

	logs::info("<C++ NPCMaleArmorScan> [Finalize] Female Scan Completed");
}

bool VanillaArmorCheck() {
	logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] START");

	RE::TESBoundObject* BodyArmor = thisActor->GetWornArmor(RE::BIPED_MODEL::BipedObjectSlot::kBody);

	if (BodyArmor) {
		const auto BodyItem = AsKeywordForm(BodyArmor);

		bool HasCurtainKeyword =
			(
				BodyItem->HasKeyword(ChestCurtain_Male) || BodyItem->HasKeyword(ChestCurtainT_Male) ||
				BodyItem->HasKeyword(PelvicCurtain_Male) || BodyItem->HasKeyword(PelvicCurtainT_Male) ||
				BodyItem->HasKeyword(AssCurtain_Male) || BodyItem->HasKeyword(AssCurtainT_Male) ||
				BodyItem->HasKeyword(Miniskirt_Male) || BodyItem->HasKeyword(MiniskirtT_Male)
				);
		logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: {}", HasCurtainKeyword);

		bool HasTopKeyword =
			(
				BodyItem->HasKeyword(ArmorTop_Male) ||
				BodyItem->HasKeyword(ArmorTopT_Low_Male) || BodyItem->HasKeyword(ArmorTopT_Male) || BodyItem->HasKeyword(ArmorTopT_High_Male) ||
				BodyItem->HasKeyword(ArmorTop_NoCover_Male)
				);
		logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: {}", HasTopKeyword);

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
		logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: {}", HasBottomKeyword);

		bool HasBraKeyword =
			(
				BodyItem->HasKeyword(Bra_Male) ||
				BodyItem->HasKeyword(BraT_Low_Male) || BodyItem->HasKeyword(BraT_Male) || BodyItem->HasKeyword(BraT_High_Male) ||
				BodyItem->HasKeyword(Bra_NoCover_Male)
				);
		logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: {}", HasBraKeyword);

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
		logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: {}", HasUnderwearKeyword);

		bool HasExtraKeyword =
			(
				BodyItem->HasKeyword(NearlyNaked_Male) ||
				BodyItem->HasKeyword(NipplePasties_Male) ||
				BodyItem->HasKeyword(Microskirt_Male) ||
				BodyItem->HasKeyword(EffectivelyNaked_Male)
				);
		logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: {}", HasExtraKeyword);

		logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? {}", (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword));
		return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
	}
	logs::info("<C++ NPCMaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? false");
	return false;
}

void NPCMaleAnalyze(RE::Actor* akMale) {
	logs::critical("<C++ NPCMaleArmorScan> [MaleAnalyze] NPC Female Analysis Triggered!");

	if (akMale == nullptr) {
		logs::critical("<C++ NPCMaleArmorScan> [MaleAnalyze] Actor is None/nullptr!!!");
		return;
	}

	logs::critical("<C++ NPCMaleArmorScan> [MaleAnalyze] Analyzing Actor: {}", akMale->GetName());

	if (akMale->GetActorBase()->IsFemale() == true) {
		logs::critical("<C++ NPCMaleArmorScan> [MaleAnalyze] ERROR: Actor {} is Female!", akMale->GetName());
		return;
	}

	thisActor = akMale;

	logs::critical("<C++ NPCMaleArmorScan> [MaleAnalyze] Start analysis...");
	if (ActorWornHasKeyword(thisActor, CoversAll_Male)) {
		Log("<C++ NPCMaleArmorScan> [MaleAnalyze] Covers All keyword detected", info);

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
		bool HasChestCurtain = ActorWornHasKeyword(thisActor, ChestCurtain_Male);
		bool HasChestCurtainT = ActorWornHasKeyword(thisActor, ChestCurtainT_Male);

		int ChestRiskLevel = RiskNone;
		if (ActorWornHasKeyword(thisActor, ChestFlashRiskLow_Male)) {
			ChestRiskLevel = RiskLow;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRisk_Male)) {
			ChestRiskLevel = RiskNormal;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRiskHigh_Male)) {
			ChestRiskLevel = RiskHigh;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRiskExtreme_Male)) {
			ChestRiskLevel = RiskExtreme;
		}
		else if (ActorWornHasKeyword(thisActor, ChestFlashRiskUltra_Male)) {
			ChestRiskLevel = RiskUltra;
		}

		bool HasPelvicCurtain = (ActorWornHasKeyword(thisActor, PelvicCurtain_Male) || ActorWornHasKeyword(thisActor, Miniskirt_Male));
		bool HasPelvicCurtainT = (ActorWornHasKeyword(thisActor, PelvicCurtainT_Male) || ActorWornHasKeyword(thisActor, MiniskirtT_Male));

		int PelvicRiskLevel = RiskNone;
		if (ActorWornHasKeyword(thisActor, PelvicFlashRiskLow_Male)) {
			PelvicRiskLevel = RiskLow;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRisk_Male)) {
			PelvicRiskLevel = RiskNormal;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskHigh_Male)) {
			PelvicRiskLevel = RiskHigh;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskExtreme_Male)) {
			PelvicRiskLevel = RiskExtreme;
		}
		else if (ActorWornHasKeyword(thisActor, PelvicFlashRiskUltra_Male)) {
			PelvicRiskLevel = RiskUltra;
		}

		bool HasAssCurtain = (ActorWornHasKeyword(thisActor, AssCurtain_Male) || ActorWornHasKeyword(thisActor, Miniskirt_Male));
		bool HasAssCurtainT = (ActorWornHasKeyword(thisActor, AssCurtainT_Male) || ActorWornHasKeyword(thisActor, MiniskirtT_Male));

		int AssRiskLevel = RiskNone;
		if (ActorWornHasKeyword(thisActor, AssFlashRiskLow_Male)) {
			AssRiskLevel = RiskLow;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRisk_Male)) {
			AssRiskLevel = RiskNormal;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRiskHigh_Male)) {
			AssRiskLevel = RiskHigh;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRiskExtreme_Male)) {
			AssRiskLevel = RiskExtreme;
		}
		else if (ActorWornHasKeyword(thisActor, AssFlashRiskUltra_Male)) {
			AssRiskLevel = RiskUltra;
		}

		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasChestCurtain = {}", HasChestCurtain);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasChestCurtainT = {}", HasChestCurtainT);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] ChestRiskLevel = {}", ChestRiskLevel);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasPelvicCurtain = {}", HasPelvicCurtain);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasPelvicCurtainT = {}", HasPelvicCurtainT);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] PelvicRiskLevel = {}", PelvicRiskLevel);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasAssCurtain = {}", HasAssCurtain);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasAssCurtainT = {}", HasAssCurtainT);
		logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] AssRiskLevel = {}", AssRiskLevel);

		if (VanillaArmorCheck() == true) {
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] Armor is considered vanilla");

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
			bool HasArmorTop = ActorWornHasKeyword(thisActor, ArmorTop_Male);
			int TopRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, ArmorTopT_Low_Male)) {
				TopRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorTopT_Male)) {
				TopRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorTopT_High_Male)) {
				TopRiskLevel = RiskHigh;
			}
			bool HasArmorTopT = TopRiskLevel > RiskNone;

			//Bra
			bool HasBra = ActorWornHasKeyword(thisActor, Bra_Male);
			int BraRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, BraT_Low_Male)) {
				BraRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, BraT_Male)) {
				BraRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, BraT_High_Male)) {
				BraRiskLevel = RiskHigh;
			}
			bool HasBraT = BraRiskLevel > RiskNone;
			bool HasBraNoCover = ActorWornHasKeyword(thisActor, Bra_NoCover_Male);

			/*
			================
			BOTTOM VARIABLES
			================
			*/

			//Bottom Armor
			bool HasArmorBottom = ActorWornHasKeyword(thisActor, ArmorBottom_Male);
			int BottomRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, ArmorBottomT_Low_Male)) {
				BottomRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorBottomT_Male)) {
				BottomRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, ArmorBottomT_High_Male)) {
				BottomRiskLevel = RiskHigh;
			}
			bool HasArmorBottomT = BottomRiskLevel > RiskNone;

			//Hotpants
			bool HasHotpants = ActorWornHasKeyword(thisActor, Hotpants_Male);
			int HotpantsRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, HotpantsT_Low_Male)) {
				HotpantsRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, HotpantsT_Male)) {
				HotpantsRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, HotpantsT_High_Male)) {
				HotpantsRiskLevel = RiskHigh;
			}
			bool HasHotpantsT = HotpantsRiskLevel > RiskNone;

			//Himbo Skirt
			bool HasHimbo = ActorWornHasKeyword(thisActor, HimboSkirt);
			int HimboRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, HimboSkirtT_Low)) {
				HimboRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, HimboSkirtT)) {
				HimboRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, HimboSkirtT_High)) {
				HimboRiskLevel = RiskHigh;
			}
			bool HasHimboT = HimboRiskLevel > RiskNone;

			//Underwear
			bool HasUnderwear = ActorWornHasKeyword(thisActor, Underwear_Male);
			int UnderwearRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, UnderwearT_Low_Male)) {
				UnderwearRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, UnderwearT_Male)) {
				UnderwearRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, UnderwearT_High_Male)) {
				UnderwearRiskLevel = RiskHigh;
			}
			bool HasUnderwearT = UnderwearRiskLevel > RiskNone;
			bool HasUnderwearNoCover = ActorWornHasKeyword(thisActor, Underwear_NoCover_Male);

			//Thong
			bool HasThong = ActorWornHasKeyword(thisActor, Thong_Male);
			int ThongRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, ThongT_Low_Male)) {
				ThongRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, ThongT_Male)) {
				ThongRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, ThongT_High_Male)) {
				ThongRiskLevel = RiskHigh;
			}
			bool HasThongT = ThongRiskLevel > RiskNone;
			bool HasThongNoCover = ActorWornHasKeyword(thisActor, Thong_NoCover_Male);

			//BananaHammock
			bool HasBananaHammock = ActorWornHasKeyword(thisActor, BananaHammock);
			int BananaHammockRiskLevel = RiskNone;
			if (ActorWornHasKeyword(thisActor, BananaHammockT_Low)) {
				BananaHammockRiskLevel = RiskLow;
			}
			else if (ActorWornHasKeyword(thisActor, BananaHammockT)) {
				BananaHammockRiskLevel = RiskNormal;
			}
			else if (ActorWornHasKeyword(thisActor, BananaHammockT_High)) {
				BananaHammockRiskLevel = RiskHigh;
			}
			bool HasBananaHammockT = BananaHammockRiskLevel > RiskNone;

			//Debug Results
			//Top
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorTop = {}", HasArmorTop);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorTopT = {}", HasArmorTopT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] TopRiskLevel = {}", TopRiskLevel);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBra = {}", HasBra);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBraT = {}", HasBraT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] BraRiskLevel = {}", BraRiskLevel);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBraNoCover = {}", HasBraNoCover);

			//Bottom
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorBottom = {}", HasArmorBottom);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasArmorBottomT = {}", HasArmorBottomT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] BottomRiskLevel = {}", BottomRiskLevel);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHotpants = {}", HasHotpants);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHotpantsT = {}", HasHotpantsT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HotpantsRiskLevel = {}", HotpantsRiskLevel);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHimbo = {}", HasHimbo);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasHimboT = {}", HasHimboT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HimboRiskLevel = {}", HimboRiskLevel);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasUnderwear = {}", HasUnderwear);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasUnderwearT = {}", HasUnderwearT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] UnderwearRiskLevel = {}", UnderwearRiskLevel);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasUnderwearNoCover = {}", HasUnderwearNoCover);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasThong = {}", HasThong);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasThongT = {}", HasThongT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] ThongRiskLevel = {}", ThongRiskLevel);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasThongNoCover = {}", HasThongNoCover);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBananaHammock = {}", HasBananaHammock);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] HasBananaHammockT = {}", HasBananaHammockT);
			logs::info("<C++ NPCMaleArmorScan> [MaleAnalyze] BananaHammockRiskLevel = {}", BananaHammockRiskLevel);

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
	logs::critical("<C++ NPCMaleArmorScan> [MaleAnalyze] Analysis Succeeded!");
}

void ExternalNPCMaleAnalyze(RE::StaticFunctionTag*, RE::Actor* akMale) {
	NPCMaleAnalyze(akMale);
}