#include "Config.h"

enum DefaultOdds {
	DefaultCurtainOddsLow = 20,
	DefaultCurtainOdds = 35,
	DefaultCurtainOddsHigh = 50,
	DefaultCurtainOddsExtreme = 65,
	DefaultCurtainOddsUltra = 80,

	DefaultTransparentCurtainOddsLow = 55,
	DefaultTransparentCurtainOdds = 65,
	DefaultTransparentCurtainOddsHigh = 75,
	DefaultTransparentCurtainOddsExtreme = 85,
	DefaultTransparentCurtainOddsUltra = 95,

	DefaultCStringOdds = 60,

	DefaultTransparentCStringOddsLow = 70,
	DefaultTransparentCStringOdds = 80,
	DefaultTransparentCStringOddsHigh = 90,

	DefaultTransparentItemOddsLow = 30,
	DefaultTransparentItemOdds = 50,
	DefaultTransparentItemOddsHigh = 70
};

void InitializeConfigData() {
	//Curtain Odds

	FlashingOdds[TopCurtainOddsLow] = DefaultCurtainOddsLow;
	FlashingOdds[TopCurtainOdds] = DefaultCurtainOdds;
	FlashingOdds[TopCurtainOddsHigh] = DefaultCurtainOddsHigh;
	FlashingOdds[TopCurtainOddsExtreme] = DefaultCurtainOddsExtreme;
	FlashingOdds[TopCurtainOddsUltra] = DefaultCurtainOddsUltra;

	FlashingOdds[PelvicCurtainOddsLow] = DefaultCurtainOddsLow;
	FlashingOdds[PelvicCurtainOdds] = DefaultCurtainOdds;
	FlashingOdds[PelvicCurtainOddsHigh] = DefaultCurtainOddsHigh;
	FlashingOdds[PelvicCurtainOddsExtreme] = DefaultCurtainOddsExtreme;
	FlashingOdds[PelvicCurtainOddsUltra] = DefaultCurtainOddsUltra;

	FlashingOdds[AssCurtainOddsLow] = DefaultCurtainOddsLow;
	FlashingOdds[AssCurtainOdds] = DefaultCurtainOdds;
	FlashingOdds[AssCurtainOddsHigh] = DefaultCurtainOddsHigh;
	FlashingOdds[AssCurtainOddsExtreme] = DefaultCurtainOddsExtreme;
	FlashingOdds[AssCurtainOddsUltra] = DefaultCurtainOddsUltra;

	FlashingOdds[TransparentTopCurtainOddsLow] = DefaultTransparentCurtainOddsLow;
	FlashingOdds[TransparentTopCurtainOdds] = DefaultTransparentCurtainOdds;
	FlashingOdds[TransparentTopCurtainOddsHigh] = DefaultTransparentCurtainOddsHigh;
	FlashingOdds[TransparentTopCurtainOddsExtreme] = DefaultTransparentCurtainOddsExtreme;
	FlashingOdds[TransparentTopCurtainOddsUltra] = DefaultTransparentCurtainOddsUltra;

	FlashingOdds[TransparentPelvicCurtainOddsLow] = DefaultTransparentCurtainOddsLow;
	FlashingOdds[TransparentPelvicCurtainOdds] = DefaultTransparentCurtainOdds;
	FlashingOdds[TransparentPelvicCurtainOddsHigh] = DefaultTransparentCurtainOddsHigh;
	FlashingOdds[TransparentPelvicCurtainOddsExtreme] = DefaultTransparentCurtainOddsExtreme;
	FlashingOdds[TransparentPelvicCurtainOddsUltra] = DefaultTransparentCurtainOddsUltra;

	FlashingOdds[TransparentAssCurtainOddsLow] = DefaultTransparentCurtainOddsLow;
	FlashingOdds[TransparentAssCurtainOdds] = DefaultTransparentCurtainOdds;
	FlashingOdds[TransparentAssCurtainOddsHigh] = DefaultTransparentCurtainOddsHigh;
	FlashingOdds[TransparentAssCurtainOddsExtreme] = DefaultTransparentCurtainOddsExtreme;
	FlashingOdds[TransparentAssCurtainOddsUltra] = DefaultTransparentCurtainOddsUltra;

	//Armor Piece Odds

	FlashingOdds[TransparentTopArmorOdds_Low] = DefaultTransparentItemOddsLow;
	FlashingOdds[TransparentTopArmorOdds] = DefaultTransparentItemOdds;
	FlashingOdds[TransparentTopArmorOdds_High] = DefaultTransparentItemOddsHigh;

	FlashingOdds[TransparentBottomArmorOdds_Low] = DefaultTransparentItemOddsLow;
	FlashingOdds[TransparentBottomArmorOdds] = DefaultTransparentItemOdds;
	FlashingOdds[TransparentBottomArmorOdds_High] = DefaultTransparentItemOddsHigh;

	FlashingOdds[TransparentBraOdds_Low] = DefaultTransparentItemOddsLow;
	FlashingOdds[TransparentBraOdds] = DefaultTransparentItemOdds;
	FlashingOdds[TransparentBraOdds_High] = DefaultTransparentItemOddsHigh;

	FlashingOdds[TransparentUnderwearOdds_Low] = DefaultTransparentItemOddsLow;
	FlashingOdds[TransparentUnderwearOdds] = DefaultTransparentItemOdds;
	FlashingOdds[TransparentUnderwearOdds_High] = DefaultTransparentItemOddsHigh;

	FlashingOdds[TransparentHotpantsOdds_Low] = DefaultTransparentItemOddsLow;
	FlashingOdds[TransparentHotpantsOdds] = DefaultTransparentItemOdds;
	FlashingOdds[TransparentHotpantsOdds_High] = DefaultTransparentItemOddsHigh;

	FlashingOdds[TransparentShowgirlOdds_Low] = DefaultTransparentItemOddsLow;
	FlashingOdds[TransparentShowgirlOdds] = DefaultTransparentItemOdds;
	FlashingOdds[TransparentShowgirlOdds_High] = DefaultTransparentItemOddsHigh;

	//CString Odds
	FlashingOdds[CStringOdds] = DefaultCStringOdds;
	FlashingOdds[TransparentCStringOdds_Low] = DefaultTransparentCStringOddsLow;
	FlashingOdds[TransparentCStringOdds] = DefaultTransparentCStringOdds;
	FlashingOdds[TransparentCStringOdds_High] = DefaultTransparentCStringOddsHigh;

	//Modifiers
	MotionFlashEnabled = true;

	SprintingMod = 20;
	RunningMod = 10;
	/*
	int index = 0;
	while (index < FlashingOddsLength) {
		logs::info("<C++ Config> [InitializeConfigData] FlashingOdds[{}] = {}", index, FlashingOdds[index]);
		index++;
	}
	*/
}

void UpdateConfig() {

}