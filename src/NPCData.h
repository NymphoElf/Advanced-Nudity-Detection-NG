#pragma once

#include <vector>

enum ShySex {
	Men,
	Women,
	Both,
	Random,
	Sexuality
};

namespace PermanentFemales {
	inline std::vector<RE::FormID> FemaleLocalID;
	inline std::vector<std::string_view> FemalePlugin;
	inline std::vector<uint8_t> IsInLightPlugin;
	inline std::vector<std::string> FemaleName;

	inline std::vector<int> DefaultRankStrict;
	inline std::vector<int> MinimumRankStrict;

	inline std::vector<int> DefaultRankTop;
	inline std::vector<int> MinimumRankTop;

	inline std::vector<int> DefaultRankBottom;
	inline std::vector<int> MinimumRankBottom;

	inline std::vector<int> ShynessMode;
	inline std::vector<int> SexualityScore;

	inline std::vector<uint8_t> AllowShameless;
	inline std::vector<uint8_t> AllowCorruption;
	inline std::vector<uint8_t> StrictRules;

	inline int TotalFemales = 0;
}

namespace RegisteredFemales {
	inline std::vector<std::string> FemaleName;
	inline std::vector<RE::FormID> FemaleFormID;

	inline std::vector<int> ModestyTimer0; //Modest
	inline std::vector<int> ModestyTimer1; //Reasonable
	inline std::vector<int> ModestyTimer2; //Relaxed
	inline std::vector<int> ModestyTimer3; //Comfortable
	inline std::vector<int> ModestyTimer4; //Tease
	inline std::vector<int> ModestyTimer5; //Brazen
	inline std::vector<int> ModestyTimer6; //Immodest

	inline std::vector<int> DefaultRankStrict;
	inline std::vector<int> CurrentRankStrict;
	inline std::vector<int> MinimumRankStrict;

	inline std::vector<int> TopModestyTimer0; //Modest
	inline std::vector<int> TopModestyTimer1; //Comfortable
	inline std::vector<int> TopModestyTimer2; //Brazen
	inline std::vector<int> TopModestyTimer3; //Immodest

	inline std::vector<int> DefaultRankTop;
	inline std::vector<int> CurrentRankTop;
	inline std::vector<int> MinimumRankTop;

	inline std::vector<int> BottomModestyTimer0; //Modest
	inline std::vector<int> BottomModestyTimer1; //Comfortable
	inline std::vector<int> BottomModestyTimer2; //Brazen
	inline std::vector<int> BottomModestyTimer3; //Immodest

	inline std::vector<int> DefaultRankBottom;
	inline std::vector<int> CurrentRankBottom;
	inline std::vector<int> MinimumRankBottom;

	inline std::vector<int> ShynessMode;
	inline std::vector<int> SexualityScore;

	//inline std::vector<bool> AllowShameless;
	//inline std::vector<bool> AllowCorruption;
	//inline std::vector<bool> StrictRules;
	//inline std::vector<bool> UpgradeBlocked;

	inline std::vector<uint8_t> AllowShameless; //BOOL
	inline std::vector<uint8_t> AllowCorruption; //BOOL
	inline std::vector<uint8_t> StrictRules; //BOOL
	inline std::vector<uint8_t> UpgradeBlocked; //BOOL

	inline std::vector<float> LastUpdateTime;

	inline int TotalFemales = 0;
}

//Functions

void RegisterFemale(RE::Actor* akFemale, float CurrentGameTime, int SexualityScore);
void RegisterRosa(float CurrentGameTime, int SexualityScore);
int GetInternalFemaleID(RE::Actor* akFemale);

void ProcessNPCModesty(RE::Actor* akFemale, int FemaleID, float CurrentGameTime);

void DeleteFemale(RE::StaticFunctionTag*, RE::Actor* akfemale);
void DeleteAllFemales(RE::StaticFunctionTag*);

void ExternalResetFemale(RE::StaticFunctionTag*, RE::Actor* akFemale);
void ResetAllFemales(RE::StaticFunctionTag*);

int RegisterPermanent(RE::StaticFunctionTag*, RE::Actor* akFemale);
int RemovePermanent(RE::StaticFunctionTag*, RE::Actor* akFemale);
void ImportPermanentFemales(RE::StaticFunctionTag*, float CurrentGameTime);
void TweakFemaleData
(
	RE::StaticFunctionTag*,
	RE::Actor* akFemale,
	int StrictRank, int TopRank, int BottomRank, int MinimumStrict, int MinimumTop, int MinimumBottom, int ShynessMode,
	bool EnableShameless, bool EnableCorrupt, bool MakeDefault, bool IsStrictRules, bool IsUpgradeBlocked,
	float CurrentGameTime
);