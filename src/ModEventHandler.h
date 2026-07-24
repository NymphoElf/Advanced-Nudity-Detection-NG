#pragma once

#include <vector>

namespace RegisteredPlugins {
	inline std::vector<uint8_t> DynamicModestyEnabled;
	inline std::vector<uint8_t> HardcoreEnabled;
	inline std::vector<uint8_t> CorruptionEnabled;
	inline std::vector<uint8_t> ShamelessEnabled;
	inline std::vector<uint8_t> UpgradeBlocked;
	inline std::vector<uint8_t> UseStrictModesty;

	inline std::vector<int> MinimumStrictRank;
	inline std::vector<int> MinimumTopRank;
	inline std::vector<int> MinimumBottomRank;

	inline std::vector<int> ImmodestyTimeRequired;

	inline std::vector<std::string> Plugins;

	inline int TotalRegisteredPlugins = 0;
}

int GetModestyRank(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
int GetTopModestyRank(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
int GetBottomModestyRank(RE::StaticFunctionTag*, RE::TESForm* ActorForm);

bool GetShowingBra(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
bool GetShowingUnderwear(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
bool GetShowingChest(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
bool GetShowingGenitals(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
bool GetShowingAss(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
bool GetTopless(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
bool GetBottomless(RE::StaticFunctionTag*, RE::TESForm* ActorForm);
bool GetNude(RE::StaticFunctionTag*, RE::TESForm* ActorForm);

void RegisterPlugin(RE::StaticFunctionTag*, std::string Plugin);
void UnregisterPlugin(RE::StaticFunctionTag*, std::string Plugin);

void OnEnableDynamicModesty(RE::StaticFunctionTag*, std::string Plugin, bool Enabled);
bool OnGetIsDynamicModestyEnabled(RE::StaticFunctionTag*);

void OnSetStrictModestyRules(RE::StaticFunctionTag*, std::string Plugin, bool StrictRules);
bool OnGetStrictRulesEnabled(RE::StaticFunctionTag*);

void OnSetMinimumStrictModestyRank(RE::StaticFunctionTag*, std::string Plugin, int ModestyRank);
int OnGetMinimumStrictModestyRank(RE::StaticFunctionTag*);

void OnSetMinimumTopModestyRank(RE::StaticFunctionTag*, std::string Plugin, int TopRank);
int OnGetMinimumTopModestyRank(RE::StaticFunctionTag*);

void OnSetMinimumBottomModestyRank(RE::StaticFunctionTag*, std::string Plugin, int BottomRank);
int OnGetMinimumBottomModestyRank(RE::StaticFunctionTag*);

void OnSetHardcore(RE::StaticFunctionTag*, std::string Plugin, bool HardcoreEnabled);
bool OnGetHardcore(RE::StaticFunctionTag*);

void OnSetCorruption(RE::StaticFunctionTag*, std::string Plugin, bool CorruptionEnabled);
bool OnGetCorruption(RE::StaticFunctionTag*);

void OnSetShameless(RE::StaticFunctionTag*, std::string Plugin, bool ShamelessEnabled);
bool OnGetShameless(RE::StaticFunctionTag*);

void OnSetModestyUpgradeBlocked(RE::StaticFunctionTag*, std::string Plugin, bool UpgradeBlocked);
bool OnGetModestyUpgradeBlocked(RE::StaticFunctionTag*);

void OnSetImmodestyTime(RE::StaticFunctionTag*, std::string Plugin, int ImmodestyTime);
int OnGetImmodestyTime(RE::StaticFunctionTag*);