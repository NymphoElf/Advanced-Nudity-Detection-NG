#include "PlayerArmorScan.h"
#include "Core.h"
#include "Config.h"
#include "Logger.h"

bool CurtainCheck(int Type, bool IsTransparent, int Level) {
	logs::info("<C++ MaleArmorScan> [CurtainCheck] START");

	int Roll = 0;
	int Odds = 0;

	std::string TypeString = "None";

	if (Type == ChestType) {
		TypeString = "Chest";
		Roll = TopCurtainRoll;
		if (Level == RiskLow) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsLow_Male];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsLow_Male];
			}
		}
		else if (Level == RiskNormal) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOdds_Male];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOdds_Male];
			}
		}
		else if (Level == RiskHigh) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsHigh_Male];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsHigh_Male];
			}
		}
		else if (Level == RiskExtreme) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsExtreme_Male];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsExtreme_Male];
			}
		}
		else if (Level == RiskUltra) {
			if (IsTransparent) {
				Odds = FlashingOdds[TopCurtainOddsUltra_Male];
			}
			else {
				Odds = FlashingOdds[TransparentTopCurtainOddsUltra_Male];
			}
		}
	}
	else if (Type == PelvicType) {
		TypeString = "Pelvic";
		Roll = PelvicCurtainRoll;
		if (Level == RiskLow) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsLow_Male];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsLow_Male];
			}
		}
		else if (Level == RiskNormal) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOdds_Male];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOdds_Male];
			}
		}
		else if (Level == RiskHigh) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsHigh_Male];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsHigh_Male];
			}
		}
		else if (Level == RiskExtreme) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsExtreme_Male];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsExtreme_Male];
			}
		}
		else if (Level == RiskUltra) {
			if (IsTransparent) {
				Odds = FlashingOdds[PelvicCurtainOddsUltra_Male];
			}
			else {
				Odds = FlashingOdds[TransparentPelvicCurtainOddsUltra_Male];
			}
		}
	}
	else if (Type == AssType) {
		TypeString = "Ass";
		Roll = AssCurtainRoll;
		if (Level == RiskLow) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsLow_Male];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsLow_Male];
			}
		}
		else if (Level == RiskNormal) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOdds_Male];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOdds_Male];
			}
		}
		else if (Level == RiskHigh) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsHigh_Male];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsHigh_Male];
			}
		}
		else if (Level == RiskExtreme) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsExtreme_Male];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsExtreme_Male];
			}
		}
		else if (Level == RiskUltra) {
			if (IsTransparent) {
				Odds = FlashingOdds[AssCurtainOddsUltra_Male];
			}
			else {
				Odds = FlashingOdds[TransparentAssCurtainOddsUltra_Male];
			}
		}
	}

	logs::info("<C++ MaleArmorScan> [CurtainCheck] Roll = {}", Roll);
	logs::info("<C++ MaleArmorScan> [CurtainCheck] Odds = {}", Odds);

	logs::info("<C++ MaleArmorScan> [CurtainCheck] Type = {}", TypeString);
	logs::info("<C++ MaleArmorScan> [CurtainCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ MaleArmorScan> [CurtainCheck] RiskLevel = {}", Level);

	logs::info("<C++ MaleArmorScan> [CurtainCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

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
			Odds = FlashingOdds[TransparentTopArmorOdds_Low_Male];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentTopArmorOdds_Male];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentTopArmorOdds_High_Male];
		}
	}
	else if (Type == BottomType) {
		TypeString = "Bottom";
		Roll = BottomTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentBottomArmorOdds_Low_Male];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentBottomArmorOdds_Male];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentBottomArmorOdds_High_Male];
		}
	}
	else if (Type == BraType) {
		TypeString = "Bra";
		Roll = BraTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentBraOdds_Low_Male];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentBraOdds_Male];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentBraOdds_High_Male];
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
			Odds = FlashingOdds[TransparentUnderwearOdds_Low_Male];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentUnderwearOdds_Male];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentUnderwearOdds_High_Male];
		}
	}
	else if (Type == HotpantsType) {
		TypeString = "Hotpants";
		Roll = HotpantsTransparentRoll;
		if (Level == RiskLow) {
			Odds = FlashingOdds[TransparentHotpantsOdds_Low_Male];
		}
		else if (Level == RiskNormal) {
			Odds = FlashingOdds[TransparentHotpantsOdds_Male];
		}
		else if (Level == RiskHigh) {
			Odds = FlashingOdds[TransparentHotpantsOdds_High_Male];
		}
	}
	else if (Type == HimboType) {
		TypeString = "Himbo";
		Roll = ShowgirlTransparentRoll;
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

	logs::info("<C++ MaleArmorScan> [TransparentItemCheck] Roll = {}", Roll);
	logs::info("<C++ MaleArmorScan> [TransparentItemCheck] Odds = {}", Odds);

	logs::info("<C++ MaleArmorScan> [TransparentItemCheck] Type = {}", TypeString);
	logs::info("<C++ MaleArmorScan> [TransparentItemCheck] RiskLevel = {}", Level);

	logs::info("<C++ MaleArmorScan> [TransparentItemCheck] Function Return Value: Is Covering? {}", (Roll > Odds));

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

	logs::info("<C++ MaleArmorScan> [BananaHammockCheck] Roll = {}", CStringRoll);
	logs::info("<C++ MaleArmorScan> [BananaHammockCheck] Odds = {}", Odds);

	logs::info("<C++ MaleArmorScan> [BananaHammockCheck] IsTransparent = {}", IsTransparent);
	logs::info("<C++ MaleArmorScan> [BananaHammockCheck] RiskLevel = {}", Level);

	logs::info("<C++ MaleArmorScan> [BananaHammockCheck] Function Return Value: Is Covering? {}", (CStringRoll > Odds));

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
			PlayerCoverage::UnderwearCover = TransparentItemCheck(HimboType, HimboRiskLevel);
		}
		else if (HasUnderwearT) {
			PlayerCoverage::UnderwearCover = TransparentItemCheck(HimboType, HimboRiskLevel);
			if (PlayerCoverage::UnderwearCover) {
				PlayerCoverage::AssCover = true;
			}
			else {
				PlayerCoverage::AssCover = TransparentItemCheck(UnderwearType, UnderwearRiskLevel);
			}
		}
		else if (HasUnderwearNoCover) {
			PlayerCoverage::UnderwearCover = TransparentItemCheck(HimboType, HimboRiskLevel);
			PlayerCoverage::AssCover = PlayerCoverage::UnderwearCover;
		}
		else {
			PlayerCoverage::UnderwearCover = true;
			PlayerCoverage::AssCover = TransparentItemCheck(HimboType, HimboRiskLevel);
		}
	}
	else if (HasHotpantsT && HasHimbo) {
		PlayerCoverage::AssCover = true;

		if (HasUnderwear || HasThong) {
			PlayerCoverage::GenitalCover = true;
			PlayerCoverage::UnderwearCover = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		}
		else if (HasUnderwearT || HasThongT || HasBananaHammock || HasBananaHammockT) {
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
					AnalyzeBananaHammock(HasBananaHammockT, BananaHammockRiskLevel);
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
	else if (HasHotpantsT && HasHimboT) {
		bool HotpantsCovering = TransparentItemCheck(HotpantsType, HotpantsRiskLevel);
		bool HimboCovering = TransparentItemCheck(HimboType, HimboRiskLevel);

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
		else if (!HotpantsCovering && HimboCovering) {
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
	else if (HasHimbo) {
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
				HasBananaHammock, HasBananaHammockT, BananaHammockRiskLevel
			);
		}
	}
	else if (HasHimboT) {
		bool HimboCovering = TransparentItemCheck(HimboType, HimboRiskLevel);

		if (HimboCovering) {
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

	logs::info("<C++ MaleArmorScan> [Finalize] Nude Faction Rank: {}", Player->GetFactionRank(NudeFaction, true));
	logs::info("<C++ MaleArmorScan> [Finalize] Topless Faction Rank: {}", Player->GetFactionRank(ToplessFaction, true));
	logs::info("<C++ MaleArmorScan> [Finalize] Bottomless Faction Rank: {}", Player->GetFactionRank(BottomlessFaction, true));
	logs::info("<C++ MaleArmorScan> [Finalize] Showing Bra Faction Rank: {}", Player->GetFactionRank(ShowingBraFaction, true));
	logs::info("<C++ MaleArmorScan> [Finalize] Showing Chest Faction Rank: {}", Player->GetFactionRank(ShowingChestFaction, true));
	logs::info("<C++ MaleArmorScan> [Finalize] Showing Underwear Faction Rank: {}", Player->GetFactionRank(ShowingUnderwearFaction, true));
	logs::info("<C++ MaleArmorScan> [Finalize] Showing Genitals Faction Rank: {}", Player->GetFactionRank(ShowingGenitalsFaction, true));
	logs::info("<C++ MaleArmorScan> [Finalize] Showing Ass Faction Rank: {}", Player->GetFactionRank(ShowingAssFaction, true));

	logs::info("<C++ MaleArmorScan> [Finalize] Player Female Scan Completed");
}

bool VanillaArmorCheck() {
	logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] START");

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
		logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasCurtainKeyword: {}", HasCurtainKeyword);

		bool HasTopKeyword =
			(
				BodyItem->HasKeyword(ArmorTop_Male) ||
				BodyItem->HasKeyword(ArmorTopT_Low_Male) || BodyItem->HasKeyword(ArmorTopT_Male) || BodyItem->HasKeyword(ArmorTopT_High_Male) ||
				BodyItem->HasKeyword(ArmorTop_NoCover_Male)
				);
		logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasTopKeyword: {}", HasTopKeyword);

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
		logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasBottomKeyword: {}", HasBottomKeyword);

		bool HasBraKeyword =
			(
				BodyItem->HasKeyword(Bra_Male) ||
				BodyItem->HasKeyword(BraT_Low_Male) || BodyItem->HasKeyword(BraT_Male) || BodyItem->HasKeyword(BraT_High_Male) ||
				BodyItem->HasKeyword(Bra_NoCover_Male)
				);
		logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasBraKeyword: {}", HasBraKeyword);

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
		logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasUnderwearKeyword: {}", HasUnderwearKeyword);

		bool HasExtraKeyword =
			(
				BodyItem->HasKeyword(NearlyNaked_Male) ||
				BodyItem->HasKeyword(NipplePasties_Male) ||
				BodyItem->HasKeyword(Microskirt_Male) ||
				BodyItem->HasKeyword(EffectivelyNaked_Male)
				);
		logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] Slot32 HasExtraKeyword: {}", HasExtraKeyword);

		logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? {}", (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword));
		return (!HasCurtainKeyword && !HasTopKeyword && !HasBottomKeyword && !HasBraKeyword && !HasUnderwearKeyword && !HasExtraKeyword);
	}
	logs::info("<C++ MaleArmorScan> [VanillaArmorCheck] END - Armor is Vanilla? false");
	return false;
}

void MaleAnalyze() {
	logs::critical("<C++ MaleArmorScan> [MaleAnalyze] Player Female Analysis Triggered!");

	bool ShouldEscape = false;

	logs::critical("<C++ MaleArmorScan> [MaleAnalyze] Check if Player is PlayerRef...");
	if (Player == nullptr || Player->IsPlayerRef() == false) {
		logs::critical("<C++ MaleArmorScan> [MaleAnalyze] RE::Actor variable not set!!!");
		ShouldEscape = true;
	}

	logs::critical("<C++ MaleArmorScan> [MaleAnalyze] Check if PlayerBase is Player...");
	if (PlayerBase == nullptr || PlayerBase->IsPlayer() == false) {
		logs::critical("<C++ MaleArmorScan> [MaleAnalyze] RE::TESActorBase variable not set!!!");
		ShouldEscape = true;
	}

	if (ShouldEscape == true) {
		logs::critical("<C++ MaleArmorScan> [MaleAnalyze] Female Analysis Failed! (Escaped)");
		return;
	}

	logs::critical("<C++ MaleArmorScan> [MaleAnalyze] Start analysis...");
	if (PlayerWornHasKeyword(CoversAll_Male)) {
		Log("<C++ MaleArmorScan> [MaleAnalyze] Covers All keyword detected", info);

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
		bool HasChestCurtain = PlayerWornHasKeyword(ChestCurtain_Male);
		bool HasChestCurtainT = PlayerWornHasKeyword(ChestCurtainT_Male);

		int ChestRiskLevel = RiskNone;
		if (PlayerWornHasKeyword(ChestFlashRiskLow_Male)) {
			ChestRiskLevel = RiskLow;
		}
		else if (PlayerWornHasKeyword(ChestFlashRisk_Male)) {
			ChestRiskLevel = RiskNormal;
		}
		else if (PlayerWornHasKeyword(ChestFlashRiskHigh_Male)) {
			ChestRiskLevel = RiskHigh;
		}
		else if (PlayerWornHasKeyword(ChestFlashRiskExtreme_Male)) {
			ChestRiskLevel = RiskExtreme;
		}
		else if (PlayerWornHasKeyword(ChestFlashRiskUltra_Male)) {
			ChestRiskLevel = RiskUltra;
		}

		bool HasPelvicCurtain = (PlayerWornHasKeyword(PelvicCurtain_Male) || PlayerWornHasKeyword(Miniskirt_Male));
		bool HasPelvicCurtainT = (PlayerWornHasKeyword(PelvicCurtainT_Male) || PlayerWornHasKeyword(MiniskirtT_Male));

		int PelvicRiskLevel = RiskNone;
		if (PlayerWornHasKeyword(PelvicFlashRiskLow_Male)) {
			PelvicRiskLevel = RiskLow;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRisk_Male)) {
			PelvicRiskLevel = RiskNormal;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRiskHigh_Male)) {
			PelvicRiskLevel = RiskHigh;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRiskExtreme_Male)) {
			PelvicRiskLevel = RiskExtreme;
		}
		else if (PlayerWornHasKeyword(PelvicFlashRiskUltra_Male)) {
			PelvicRiskLevel = RiskUltra;
		}

		bool HasAssCurtain = (PlayerWornHasKeyword(AssCurtain_Male) || PlayerWornHasKeyword(Miniskirt_Male));
		bool HasAssCurtainT = (PlayerWornHasKeyword(AssCurtainT_Male) || PlayerWornHasKeyword(MiniskirtT_Male));

		int AssRiskLevel = RiskNone;
		if (PlayerWornHasKeyword(AssFlashRiskLow_Male)) {
			AssRiskLevel = RiskLow;
		}
		else if (PlayerWornHasKeyword(AssFlashRisk_Male)) {
			AssRiskLevel = RiskNormal;
		}
		else if (PlayerWornHasKeyword(AssFlashRiskHigh_Male)) {
			AssRiskLevel = RiskHigh;
		}
		else if (PlayerWornHasKeyword(AssFlashRiskExtreme_Male)) {
			AssRiskLevel = RiskExtreme;
		}
		else if (PlayerWornHasKeyword(AssFlashRiskUltra_Male)) {
			AssRiskLevel = RiskUltra;
		}

		logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasChestCurtain = {}", HasChestCurtain);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasChestCurtainT = {}", HasChestCurtainT);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] ChestRiskLevel = {}", ChestRiskLevel);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasPelvicCurtain = {}", HasPelvicCurtain);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasPelvicCurtainT = {}", HasPelvicCurtainT);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] PelvicRiskLevel = {}", PelvicRiskLevel);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasAssCurtain = {}", HasAssCurtain);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasAssCurtainT = {}", HasAssCurtainT);
		logs::info("<C++ MaleArmorScan> [MaleAnalyze] AssRiskLevel = {}", AssRiskLevel);

		if (VanillaArmorCheck() == true) {
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] Armor is considered vanilla");

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
			bool HasArmorTop = PlayerWornHasKeyword(ArmorTop_Male);
			int TopRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(ArmorTopT_Low_Male)) {
				TopRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(ArmorTopT_Male)) {
				TopRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(ArmorTopT_High_Male)) {
				TopRiskLevel = RiskHigh;
			}
			bool HasArmorTopT = TopRiskLevel > RiskNone;

			//Bra
			bool HasBra = PlayerWornHasKeyword(Bra_Male);
			int BraRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(BraT_Low_Male)) {
				BraRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(BraT_Male)) {
				BraRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(BraT_High_Male)) {
				BraRiskLevel = RiskHigh;
			}
			bool HasBraT = BraRiskLevel > RiskNone;
			bool HasBraNoCover = PlayerWornHasKeyword(Bra_NoCover_Male);

			/*
			================
			BOTTOM VARIABLES
			================
			*/

			//Bottom Armor
			bool HasArmorBottom = PlayerWornHasKeyword(ArmorBottom_Male);
			int BottomRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(ArmorBottomT_Low_Male)) {
				BottomRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(ArmorBottomT_Male)) {
				BottomRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(ArmorBottomT_High_Male)) {
				BottomRiskLevel = RiskHigh;
			}
			bool HasArmorBottomT = BottomRiskLevel > RiskNone;

			//Hotpants
			bool HasHotpants = PlayerWornHasKeyword(Hotpants_Male);
			int HotpantsRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(HotpantsT_Low_Male)) {
				HotpantsRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(HotpantsT_Male)) {
				HotpantsRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(HotpantsT_High_Male)) {
				HotpantsRiskLevel = RiskHigh;
			}
			bool HasHotpantsT = HotpantsRiskLevel > RiskNone;

			//Himbo Skirt
			bool HasHimbo = PlayerWornHasKeyword(HimboSkirt);
			int HimboRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(HimboSkirtT_Low)) {
				HimboRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(HimboSkirtT)) {
				HimboRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(HimboSkirtT_High)) {
				HimboRiskLevel = RiskHigh;
			}
			bool HasHimboT = HimboRiskLevel > RiskNone;

			//Underwear
			bool HasUnderwear = PlayerWornHasKeyword(Underwear_Male);
			int UnderwearRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(UnderwearT_Low_Male)) {
				UnderwearRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(UnderwearT_Male)) {
				UnderwearRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(UnderwearT_High_Male)) {
				UnderwearRiskLevel = RiskHigh;
			}
			bool HasUnderwearT = UnderwearRiskLevel > RiskNone;
			bool HasUnderwearNoCover = PlayerWornHasKeyword(Underwear_NoCover_Male);

			//Thong
			bool HasThong = PlayerWornHasKeyword(Thong_Male);
			int ThongRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(ThongT_Low_Male)) {
				ThongRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(ThongT_Male)) {
				ThongRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(ThongT_High_Male)) {
				ThongRiskLevel = RiskHigh;
			}
			bool HasThongT = ThongRiskLevel > RiskNone;
			bool HasThongNoCover = PlayerWornHasKeyword(Thong_NoCover_Male);

			//BananaHammock
			bool HasBananaHammock = PlayerWornHasKeyword(BananaHammock);
			int BananaHammockRiskLevel = RiskNone;
			if (PlayerWornHasKeyword(BananaHammockT_Low)) {
				BananaHammockRiskLevel = RiskLow;
			}
			else if (PlayerWornHasKeyword(BananaHammockT)) {
				BananaHammockRiskLevel = RiskNormal;
			}
			else if (PlayerWornHasKeyword(BananaHammockT_High)) {
				BananaHammockRiskLevel = RiskHigh;
			}
			bool HasBananaHammockT = BananaHammockRiskLevel > RiskNone;

			//Debug Results
			//Top
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasArmorTop = {}", HasArmorTop);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasArmorTopT = {}", HasArmorTopT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] TopRiskLevel = {}", TopRiskLevel);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasBra = {}", HasBra);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasBraT = {}", HasBraT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] BraRiskLevel = {}", BraRiskLevel);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasBraNoCover = {}", HasBraNoCover);

			//Bottom
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasArmorBottom = {}", HasArmorBottom);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasArmorBottomT = {}", HasArmorBottomT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] BottomRiskLevel = {}", BottomRiskLevel);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasHotpants = {}", HasHotpants);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasHotpantsT = {}", HasHotpantsT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HotpantsRiskLevel = {}", HotpantsRiskLevel);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasHimbo = {}", HasHimbo);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasHimboT = {}", HasHimboT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HimboRiskLevel = {}", HimboRiskLevel);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwear = {}", HasUnderwear);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwearT = {}", HasUnderwearT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] UnderwearRiskLevel = {}", UnderwearRiskLevel);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasUnderwearNoCover = {}", HasUnderwearNoCover);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasThong = {}", HasThong);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasThongT = {}", HasThongT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] ThongRiskLevel = {}", ThongRiskLevel);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasThongNoCover = {}", HasThongNoCover);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasBananaHammock = {}", HasBananaHammock);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] HasBananaHammockT = {}", HasBananaHammockT);
			logs::info("<C++ MaleArmorScan> [MaleAnalyze] BananaHammockRiskLevel = {}", BananaHammockRiskLevel);

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
	logs::critical("<C++ MaleArmorScan> [MaleAnalyze] Analysis Succeeded!");
}

void ExternalMaleAnalyze(RE::StaticFunctionTag*) {
	MaleAnalyze();
}