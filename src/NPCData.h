#pragma once

#include <vector>
#include <unordered_map>

#include "Core.h"
#include "Logger.h"

enum ShySex {
	Men,
	Women,
	Both,
	Random,
	Sexuality
};

struct LegacyPermanentFemales {
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
};

struct PermanentFemales
{
	RE::FormID LocalID;
	char Plugin[256];
	char Name[256];

	UINT8 DefaultRankStrict;
	UINT8 MinimumRankStrict;

	UINT8 DefaultRankTop;
	UINT8 MinimumRankTop;

	UINT8 DefaultRankBottom;
	UINT8 MinimumRankBottom;

	UINT8 ShynessMode;
	UINT8 SexualityScore;

	bool AllowShameless;
	bool AllowCorruption;
	bool StrictRules;

	std::string_view GetPluginName(void) const { return std::string_view(Plugin); }
	std::string_view GetName(void) const { return std::string_view(Name); }
	const RE::TESFile* GetPluginFile() const {
		std::string_view PluginName = GetPluginName();
		const RE::TESFile* PluginFile = GameDataHandler->LookupModByName(PluginName);
		
		if (PluginFile && PluginFile->IsLight()) {
			PluginFile = GameDataHandler->LookupLoadedLightModByName(PluginName);
		}
		else if (PluginFile) {
			PluginFile = GameDataHandler->LookupLoadedModByName(PluginName);
		}

		return PluginFile;
	}

	uint32_t GetModIndex(void) const
	{
		uint32_t ModIndex;
		std::string_view PluginName = GetPluginName();
		const RE::TESFile* PluginFile = GameDataHandler->LookupModByName(PluginName);

		if(PluginFile->IsLight())
		{
			Log("<C++ NPCData Header> [GetModIndex] Plugin " + static_cast<std::string>(PluginName) + " is LIGHT");
			ModIndex = GameDataHandler->GetLoadedLightModIndex(PluginName).value_or(0xFF000) << 12;
			//ModIndex << 12;
		}
		else
		{
			Log("<C++ NPCData Header> [GetModIndex] Plugin " + static_cast<std::string>(PluginName) + " is FULL");
			ModIndex = GameDataHandler->GetLoadedModIndex(PluginName).value_or(0xFF) << 24;
			//ModIndex << 24;
		}

		return ModIndex;
	}
};

inline std::vector<PermanentFemales> PermanentFemaleVector;

struct RegisteredFemales
{
	char Name[256];
	RE::FormID FemaleFormID;

	INT16 ModestyTimer0; //Modest
	INT16 ModestyTimer1; //Reasonable
	INT16 ModestyTimer2; //Relaxed
	INT16 ModestyTimer3; //Comfortable
	INT16 ModestyTimer4; //Tease
	INT16 ModestyTimer5; //Brazen
	INT16 ModestyTimer6; //Immodest

	UINT8 DefaultRankStrict;
	UINT8 CurrentRankStrict;
	UINT8 MinimumRankStrict;

	INT16 TopModestyTimer0; //Modest
	INT16 TopModestyTimer1; //Comfortable
	INT16 TopModestyTimer2; //Brazen
	INT16 TopModestyTimer3; //Immodest

	UINT8 DefaultRankTop;
	UINT8 CurrentRankTop;
	UINT8 MinimumRankTop;

	INT16 BottomModestyTimer0; //Modest
	INT16 BottomModestyTimer1; //Comfortable
	INT16 BottomModestyTimer2; //Brazen
	INT16 BottomModestyTimer3; //Immodest

	UINT8 DefaultRankBottom;
	UINT8 CurrentRankBottom;
	UINT8 MinimumRankBottom;

	UINT8 ShynessMode;
	UINT8 SexualityScore;

	bool AllowShameless;
	bool AllowCorruption;
	bool StrictRules;
	bool UpgradeBlocked;

	float LastUpdateTime;

	std::string GetName(void) const { return std::string(Name); }
};

inline std::unordered_map<RE::FormID, RegisteredFemales> RegisteredFemaleMap;

static_assert(std::is_trivially_copyable_v<PermanentFemales>);
static_assert(std::is_trivially_copyable_v<RegisteredFemales>);

inline bool PermanentFemalesImported;

//Functions
int FindInVector(std::vector<PermanentFemales> SearchVector, PermanentFemales SearchTarget);

PermanentFemales ConvertLegacyFemale(LegacyPermanentFemales LegacyFemale);
bool ValidatePermanentFemale(PermanentFemales ThisPermanentFemale);

void NPCDataOnRevertCallback();

void RegisterFemale(RE::Actor* akFemale, float CurrentGameTime, UINT8 SexualityScore);
void RegisterRosa(float CurrentGameTime, UINT8 SexualityScore);

void ProcessNPCModesty(RE::Actor* akFemale, float CurrentGameTime);
void ProcessAllNPCModesty(RE::StaticFunctionTag*);

void DeleteFemale(RE::StaticFunctionTag*, RE::Actor* akfemale);
void DeleteAllFemales(RE::StaticFunctionTag*);

void ExternalResetFemale(RE::StaticFunctionTag*, RE::Actor* akFemale);
void ResetAllFemales(RE::StaticFunctionTag*);

int RegisterPermanent(RE::StaticFunctionTag*, RE::Actor* akFemale);
int RemovePermanent(RE::StaticFunctionTag*, RE::Actor* akFemale);
void ExternalRemovePermanentAtIndex(RE::StaticFunctionTag*, int PermanentIndex);

void ExternalImportPermanentFemales(RE::StaticFunctionTag*);
void ImportPermanentFemales();
void TweakFemaleData
(
	RE::StaticFunctionTag*,
	RE::Actor* akFemale,
	int StrictRank, int TopRank, int BottomRank, int MinimumStrict, int MinimumTop, int MinimumBottom, int ShynessMode,
	bool EnableShameless, bool EnableCorrupt, bool MakeDefault, bool IsStrictRules, bool IsUpgradeBlocked
);

void CleanFemaleList();