#pragma once

enum FlashingIndex {
	//Curtain Odds
	
	TopCurtainOddsLow,
	TopCurtainOdds,
	TopCurtainOddsHigh,
	TopCurtainOddsExtreme,
	TopCurtainOddsUltra,

	PelvicCurtainOddsLow,
	PelvicCurtainOdds,
	PelvicCurtainOddsHigh,
	PelvicCurtainOddsExtreme,
	PelvicCurtainOddsUltra,

	AssCurtainOddsLow,
	AssCurtainOdds,
	AssCurtainOddsHigh,
	AssCurtainOddsExtreme,
	AssCurtainOddsUltra,

	TransparentTopCurtainOddsLow,
	TransparentTopCurtainOdds,
	TransparentTopCurtainOddsHigh,
	TransparentTopCurtainOddsExtreme,
	TransparentTopCurtainOddsUltra,

	TransparentPelvicCurtainOddsLow,
	TransparentPelvicCurtainOdds,
	TransparentPelvicCurtainOddsHigh,
	TransparentPelvicCurtainOddsExtreme,
	TransparentPelvicCurtainOddsUltra,

	TransparentAssCurtainOddsLow,
	TransparentAssCurtainOdds,
	TransparentAssCurtainOddsHigh,
	TransparentAssCurtainOddsExtreme,
	TransparentAssCurtainOddsUltra,

	//Armor Piece Odds

	TransparentTopArmorOdds_Low,
	TransparentTopArmorOdds,
	TransparentTopArmorOdds_High,

	TransparentBottomArmorOdds_Low,
	TransparentBottomArmorOdds,
	TransparentBottomArmorOdds_High,

	TransparentBraOdds_Low,
	TransparentBraOdds,
	TransparentBraOdds_High,

	TransparentUnderwearOdds_Low,
	TransparentUnderwearOdds,
	TransparentUnderwearOdds_High,

	TransparentHotpantsOdds_Low,
	TransparentHotpantsOdds,
	TransparentHotpantsOdds_High,

	TransparentShowgirlOdds_Low,
	TransparentShowgirlOdds,
	TransparentShowgirlOdds_High,

	//CString Odds

	CStringOdds,
	TransparentCStringOdds_Low,
	TransparentCStringOdds,
	TransparentCStringOdds_High,

	//Curtain Odds MALE

	TopCurtainOddsLow_Male,
	TopCurtainOdds_Male,
	TopCurtainOddsHigh_Male,
	TopCurtainOddsExtreme_Male,
	TopCurtainOddsUltra_Male,

	PelvicCurtainOddsLow_Male,
	PelvicCurtainOdds_Male,
	PelvicCurtainOddsHigh_Male,
	PelvicCurtainOddsExtreme_Male,
	PelvicCurtainOddsUltra_Male,

	AssCurtainOddsLow_Male,
	AssCurtainOdds_Male,
	AssCurtainOddsHigh_Male,
	AssCurtainOddsExtreme_Male,
	AssCurtainOddsUltra_Male,

	TransparentTopCurtainOddsLow_Male,
	TransparentTopCurtainOdds_Male,
	TransparentTopCurtainOddsHigh_Male,
	TransparentTopCurtainOddsExtreme_Male,
	TransparentTopCurtainOddsUltra_Male,

	TransparentPelvicCurtainOddsLow_Male,
	TransparentPelvicCurtainOdds_Male,
	TransparentPelvicCurtainOddsHigh_Male,
	TransparentPelvicCurtainOddsExtreme_Male,
	TransparentPelvicCurtainOddsUltra_Male,

	TransparentAssCurtainOddsLow_Male,
	TransparentAssCurtainOdds_Male,
	TransparentAssCurtainOddsHigh_Male,
	TransparentAssCurtainOddsExtreme_Male,
	TransparentAssCurtainOddsUltra_Male,

	//Armor Piece Odds MALE

	TransparentTopArmorOdds_Low_Male,
	TransparentTopArmorOdds_Male,
	TransparentTopArmorOdds_High_Male,

	TransparentBottomArmorOdds_Low_Male,
	TransparentBottomArmorOdds_Male,
	TransparentBottomArmorOdds_High_Male,

	TransparentBraOdds_Low_Male,
	TransparentBraOdds_Male,
	TransparentBraOdds_High_Male,

	TransparentUnderwearOdds_Low_Male,
	TransparentUnderwearOdds_Male,
	TransparentUnderwearOdds_High_Male,

	TransparentHotpantsOdds_Low_Male,
	TransparentHotpantsOdds_Male,
	TransparentHotpantsOdds_High_Male,

	TransparentHimboOdds_Low,
	TransparentHimboOdds,
	TransparentHimboOdds_High,

	//BananaHammock Odds

	BananaHammockOdds,
	TransparentBananaHammockOdds_Low,
	TransparentBananaHammockOdds,
	TransparentBananaHammockOdds_High,

	//KEEP THIS AS LAST ENUM ENTRY

	FlashingOddsLength
};

inline int FlashingOdds[FlashingOddsLength] = {};

inline int ImmodestyTimeNeeded;
inline int MinimumModestyRank;
inline int MinimumTopModestyRank;
inline int MinimumBottomModestyRank;

//Modifiers

inline bool MotionFlashEnabled;
inline bool DynamicModestyEnabled;

inline bool PermanentShameless;
inline bool Corruption;
inline bool StrictModestyRules;

inline int SprintingMod;
inline int RunningMod;

//Functions

void InitializeConfigData();