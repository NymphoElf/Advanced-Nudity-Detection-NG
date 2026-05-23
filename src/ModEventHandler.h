#pragma once

#include <vector>

namespace RegisteredPlugins {
	/*
	inline std::vector<bool> DynamicModestyEnabled;
	inline std::vector<bool> HardcoreEnabled;
	inline std::vector<bool> CorruptionEnabled;
	inline std::vector<bool> ShamelessEnabled;
	inline std::vector<bool> UpgradeBlocked;
	inline std::vector<bool> UseStrictModesty;
	*/

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