#pragma once

#include <vector>
#include <unordered_map>

enum ShySex {
	Men,
	Women,
	Both,
	Random,
	Sexuality
};

struct PermanentFemales
{
	RE::FormID LocalID;
	char Plugin[256];
	char Name[256];

	int DefaultRankStrict;
	int MinimumRankStrict;

	int DefaultRankTop;
	int MinimumRankTop;

	int DefaultRankBottom;
	int MinimumRankBottom;

	int ShynessMode;
	int SexualityScore;

	bool LightPlugin;
	bool AllowShameless;
	bool AllowCorruption;
	bool StrictRules;

	std::string_view GetPlugin(void) const { return std::string_view(Plugin); }
	std::string_view GetName(void) const { return std::string_view(Name); }

	uint32_t GetModIndex(void) const
	{
		std::optional<uint32_t> modindex;
		RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

		if(LightPlugin)
		{
			modindex = DataHandler->GetLoadedLightModIndex(GetPlugin());
		}
		else
		{
			modindex = DataHandler->GetLoadedModIndex(GetPlugin());
		}

		return modindex.value_or(0xFF);
	}
};

inline std::vector<PermanentFemales> permanentfemales;

struct RegisteredFemales
{
	char Name[256];
	RE::FormID id;

	int ModestyTimer0; //Modest
	int ModestyTimer1; //Reasonable
	int ModestyTimer2; //Relaxed
	int ModestyTimer3; //Comfortable
	int ModestyTimer4; //Tease
	int ModestyTimer5; //Brazen
	int ModestyTimer6; //Immodest

	int DefaultRankStrict;
	int CurrentRankStrict;
	int MinimumRankStrict;

	int TopModestyTimer0; //Modest
	int TopModestyTimer1; //Comfortable
	int TopModestyTimer2; //Brazen
	int TopModestyTimer3; //Immodest

	int DefaultRankTop;
	int CurrentRankTop;
	int MinimumRankTop;

	int BottomModestyTimer0; //Modest
	int BottomModestyTimer1; //Comfortable
	int BottomModestyTimer2; //Brazen
	int BottomModestyTimer3; //Immodest

	int DefaultRankBottom;
	int CurrentRankBottom;
	int MinimumRankBottom;

	int ShynessMode;
	int SexualityScore;

	bool AllowShameless;
	bool AllowCorruption;
	bool StrictRules;
	bool UpgradeBlocked;

	float LastUpdateTime;

	std::string GetName(void) const { return std::string(Name); }
};

inline std::unordered_map<RE::FormID, RegisteredFemales> registeredfemales;

//Functions
void NPCDataOnRevertCallback();

void RegisterFemale(RE::Actor* akFemale, float CurrentGameTime, int SexualityScore);
void RegisterRosa(float CurrentGameTime, int SexualityScore);
int GetInternalFemaleID(RE::Actor* akFemale);

void ProcessNPCModesty(RE::Actor* akFemale, float CurrentGameTime);

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