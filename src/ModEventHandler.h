#pragma once

#include <vector>

namespace RegisteredPlugins {
	inline std::vector<UINT8> DynamicModestyEnabled;
	inline std::vector<UINT8> HardcoreEnabled;
	inline std::vector<UINT8> CorruptionEnabled;
	inline std::vector<UINT8> ShamelessEnabled;
	inline std::vector<UINT8> UpgradeBlocked;
	inline std::vector<UINT8> UseStrictModesty;

	inline std::vector<UINT8> MinimumStrictRank;
	inline std::vector<UINT8> MinimumTopRank;
	inline std::vector<UINT8> MinimumBottomRank;

	inline std::vector<UINT16> ImmodestyTimeRequired;

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

void OnSetMinimumStrictModestyRank(RE::StaticFunctionTag*, std::string Plugin, UINT8 ModestyRank);
int OnGetMinimumStrictModestyRank(RE::StaticFunctionTag*);

void OnSetMinimumTopModestyRank(RE::StaticFunctionTag*, std::string Plugin, UINT8 TopRank);
int OnGetMinimumTopModestyRank(RE::StaticFunctionTag*);

void OnSetMinimumBottomModestyRank(RE::StaticFunctionTag*, std::string Plugin, UINT8 BottomRank);
int OnGetMinimumBottomModestyRank(RE::StaticFunctionTag*);

void OnSetHardcore(RE::StaticFunctionTag*, std::string Plugin, bool HardcoreEnabled);
bool OnGetHardcore(RE::StaticFunctionTag*);

void OnSetCorruption(RE::StaticFunctionTag*, std::string Plugin, bool CorruptionEnabled);
bool OnGetCorruption(RE::StaticFunctionTag*);

void OnSetShameless(RE::StaticFunctionTag*, std::string Plugin, bool ShamelessEnabled);
bool OnGetShameless(RE::StaticFunctionTag*);

void OnSetModestyUpgradeBlocked(RE::StaticFunctionTag*, std::string Plugin, bool UpgradeBlocked);
bool OnGetModestyUpgradeBlocked(RE::StaticFunctionTag*);

void OnSetImmodestyTime(RE::StaticFunctionTag*, std::string Plugin, UINT16 ImmodestyTime);
int OnGetImmodestyTime(RE::StaticFunctionTag*);