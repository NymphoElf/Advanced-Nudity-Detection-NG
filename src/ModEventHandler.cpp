#include "ModEventHandler.h"
#include "Core.h"
#include "Logger.h"
#include "Config.h"

void CleanRegistry(int StartIndex = 0) {
	int CleaningIndex = StartIndex;
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	while (CleaningIndex < RegisteredPlugins::TotalRegisteredPlugins) {
		const RE::TESFile* Plugin = DataHandler->LookupModByName(RegisteredPlugins::Plugins[CleaningIndex]);
		if (Plugin) {
			CleaningIndex++;
		}
		else {
			RegisteredPlugins::Plugins.erase(RegisteredPlugins::Plugins.begin() + CleaningIndex);

			RegisteredPlugins::DynamicModestyEnabled.erase(RegisteredPlugins::DynamicModestyEnabled.begin() + CleaningIndex);
			RegisteredPlugins::HardcoreEnabled.erase(RegisteredPlugins::HardcoreEnabled.begin() + CleaningIndex);
			RegisteredPlugins::CorruptionEnabled.erase(RegisteredPlugins::CorruptionEnabled.begin() + CleaningIndex);
			RegisteredPlugins::ShamelessEnabled.erase(RegisteredPlugins::ShamelessEnabled.begin() + CleaningIndex);
			RegisteredPlugins::UpgradeBlocked.erase(RegisteredPlugins::UpgradeBlocked.begin() + CleaningIndex);
			RegisteredPlugins::UseStrictModesty.erase(RegisteredPlugins::UseStrictModesty.begin() + CleaningIndex);

			RegisteredPlugins::MinimumStrictRank.erase(RegisteredPlugins::MinimumStrictRank.begin() + CleaningIndex);
			RegisteredPlugins::MinimumTopRank.erase(RegisteredPlugins::MinimumTopRank.begin() + CleaningIndex);
			RegisteredPlugins::MinimumBottomRank.erase(RegisteredPlugins::MinimumBottomRank.begin() + CleaningIndex);

			RegisteredPlugins::ImmodestyTimeRequired.erase(RegisteredPlugins::ImmodestyTimeRequired.begin() + CleaningIndex);

			RegisteredPlugins::TotalRegisteredPlugins--;
		}
	}
}

void RegisterPlugin(RE::StaticFunctionTag*, std::string Plugin) {
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();
	
	std::optional<uint8_t> ModIndex = DataHandler->GetLoadedModIndex(Plugin);

	if (ModIndex.has_value() && ModIndex.value() < 0xFF) {
		RegisteredPlugins::Plugins.emplace_back(Plugin);

		RegisteredPlugins::DynamicModestyEnabled.emplace_back(false);
		RegisteredPlugins::HardcoreEnabled.emplace_back(false);
		RegisteredPlugins::CorruptionEnabled.emplace_back(false);
		RegisteredPlugins::ShamelessEnabled.emplace_back(false);
		RegisteredPlugins::UpgradeBlocked.emplace_back(false);
		RegisteredPlugins::UseStrictModesty.emplace_back(false);

		RegisteredPlugins::MinimumStrictRank.emplace_back(0);
		RegisteredPlugins::MinimumTopRank.emplace_back(0);
		RegisteredPlugins::MinimumBottomRank.emplace_back(0);

		RegisteredPlugins::ImmodestyTimeRequired.emplace_back(0);

		RegisteredPlugins::TotalRegisteredPlugins++;
	}
	else {
		Log("<C++ ModEventHandler> [RegisterPlugin] Plugin " + Plugin + " is not loaded or does not exist!");
	}
}

void UnregisterPlugin(RE::StaticFunctionTag*, std::string Plugin) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [UnregisterPlugin] Plugin " + Plugin + " does not exist in registry.", LogType::Core, LoggingLevel::warning);
	}
	else {
		RegisteredPlugins::Plugins.erase(RegisteredPlugins::Plugins.begin() + PluginIndex);

		RegisteredPlugins::DynamicModestyEnabled.erase(RegisteredPlugins::DynamicModestyEnabled.begin() + PluginIndex);
		RegisteredPlugins::HardcoreEnabled.erase(RegisteredPlugins::HardcoreEnabled.begin() + PluginIndex);
		RegisteredPlugins::CorruptionEnabled.erase(RegisteredPlugins::CorruptionEnabled.begin() + PluginIndex);
		RegisteredPlugins::ShamelessEnabled.erase(RegisteredPlugins::ShamelessEnabled.begin() + PluginIndex);
		RegisteredPlugins::UpgradeBlocked.erase(RegisteredPlugins::UpgradeBlocked.begin() + PluginIndex);
		RegisteredPlugins::UseStrictModesty.erase(RegisteredPlugins::UseStrictModesty.begin() + PluginIndex);

		RegisteredPlugins::MinimumStrictRank.erase(RegisteredPlugins::MinimumStrictRank.begin() + PluginIndex);
		RegisteredPlugins::MinimumTopRank.erase(RegisteredPlugins::MinimumTopRank.begin() + PluginIndex);
		RegisteredPlugins::MinimumBottomRank.erase(RegisteredPlugins::MinimumBottomRank.begin() + PluginIndex);

		RegisteredPlugins::ImmodestyTimeRequired.erase(RegisteredPlugins::ImmodestyTimeRequired.begin() + PluginIndex);

		RegisteredPlugins::TotalRegisteredPlugins--;
	}
}

void OnEnableDynamicModesty(RE::StaticFunctionTag*, std::string Plugin, bool Enabled) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnEnableDynamicModesty] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	RegisteredPlugins::DynamicModestyEnabled[PluginIndex] = Enabled;

	uint8_t bValue = 1;

	if (FindInVector(RegisteredPlugins::DynamicModestyEnabled, bValue) >= 0) {
		Configuration::DynamicModestyEnabled = true;
	}
	else {
		Configuration::DynamicModestyEnabled = false;
	}
}

bool OnGetIsDynamicModestyEnabled(RE::StaticFunctionTag*) {
	return Configuration::DynamicModestyEnabled;
}

void OnSetStrictModestyRules(RE::StaticFunctionTag*, std::string Plugin, bool StrictRules) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetStrictModestyRules] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	RegisteredPlugins::UseStrictModesty[PluginIndex] = StrictRules;

	uint8_t bValue = 1;

	if (FindInVector(RegisteredPlugins::UseStrictModesty, bValue) >= 0) {
		StrictRules = true;
	}

	Configuration::StrictModestyRules = StrictRules;
	
	if (Configuration::DynamicModestyEnabled) {
		if (StrictRules) {
			Configuration::DynamicModestyMode->value = 1;
		}
		else {
			Configuration::DynamicModestyMode->value = 2;
		}
	} 
}

bool OnGetStrictRulesEnabled(RE::StaticFunctionTag*) {
	return Configuration::StrictModestyRules;
}

void OnSetMinimumStrictModestyRank(RE::StaticFunctionTag*, std::string Plugin, int StrictRank) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetMinimumModestyRank] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	if (StrictRank < 0) {
		StrictRank = 0;
	}
	else if (StrictRank > 6) {
		StrictRank = 6;
	}

	RegisteredPlugins::MinimumStrictRank[PluginIndex] = StrictRank;

	if (FindInVector(RegisteredPlugins::MinimumStrictRank, 6) >= 0) {
		StrictRank = 6;
	}
	else if (FindInVector(RegisteredPlugins::MinimumStrictRank, 5) >= 0) {
		StrictRank = 5;
	}
	else if (FindInVector(RegisteredPlugins::MinimumStrictRank, 4) >= 0) {
		StrictRank = 4;
	}
	else if (FindInVector(RegisteredPlugins::MinimumStrictRank, 3) >= 0) {
		StrictRank = 3;
	}
	else if (FindInVector(RegisteredPlugins::MinimumStrictRank, 2) >= 0) {
		StrictRank = 2;
	}
	else if (FindInVector(RegisteredPlugins::MinimumStrictRank, 1) >= 0) {
		StrictRank = 1;
	}
	else {
		StrictRank = 0;
	}

	Configuration::MinimumStrictModestyRank = StrictRank;
}

int OnGetMinimumStrictModestyRank(RE::StaticFunctionTag*) {
	return Configuration::MinimumStrictModestyRank;
}

void OnSetMinimumTopModestyRank(RE::StaticFunctionTag*, std::string Plugin, int TopRank) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetMinimumTopRank] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	if (TopRank < 0) {
		TopRank = 0;
	}
	else if (TopRank > 3) {
		TopRank = 3;
	}

	RegisteredPlugins::MinimumTopRank[PluginIndex] = TopRank;

	if (FindInVector(RegisteredPlugins::MinimumTopRank, 3) >= 0) {
		TopRank = 3;
	}
	else if (FindInVector(RegisteredPlugins::MinimumTopRank, 2) >= 0) {
		TopRank = 2;
	}
	else if (FindInVector(RegisteredPlugins::MinimumTopRank, 1) >= 0) {
		TopRank = 1;
	}
	else {
		TopRank = 0;
	}

	Configuration::MinimumTopModestyRank = TopRank;
}

int OnGetMinimumTopModestyRank(RE::StaticFunctionTag*) {
	return Configuration::MinimumTopModestyRank;
}

void OnSetMinimumBottomModestyRank(RE::StaticFunctionTag*, std::string Plugin, int BottomRank) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetMinimumBottomModestyRank] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	if (BottomRank < 0) {
		BottomRank = 0;
	}
	else if (BottomRank > 3) {
		BottomRank = 3;
	}

	RegisteredPlugins::MinimumBottomRank[PluginIndex] = BottomRank;

	if (FindInVector(RegisteredPlugins::MinimumBottomRank, 3) >= 0) {
		BottomRank = 3;
	}
	else if (FindInVector(RegisteredPlugins::MinimumBottomRank, 2) >= 0) {
		BottomRank = 2;
	}
	else if (FindInVector(RegisteredPlugins::MinimumBottomRank, 1) >= 0) {
		BottomRank = 1;
	}
	else {
		BottomRank = 0;
	}

	Configuration::MinimumBottomModestyRank = BottomRank;
}

int OnGetMinimumBottomModestyRank(RE::StaticFunctionTag*) {
	return Configuration::MinimumBottomModestyRank;
}

void OnSetHardcore(RE::StaticFunctionTag*, std::string Plugin, bool HardcoreEnabled) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetHardcore] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	RegisteredPlugins::HardcoreEnabled[PluginIndex] = HardcoreEnabled;

	uint8_t bValue = 1;

	if (HardcoreEnabled == true || FindInVector(RegisteredPlugins::HardcoreEnabled, bValue) >= 0) {
		Configuration::HardcoreModeEnabled = true;
		//Configuration::HardcoreLockdown = true;
	}
	else {
		Configuration::HardcoreModeEnabled = false;
		//Configuration::HardcoreLockdown = false;
	}
}

bool OnGetHardcore(RE::StaticFunctionTag*) {
	return Configuration::HardcoreModeEnabled;
}

void OnSetCorruption(RE::StaticFunctionTag*, std::string Plugin, bool CorruptionEnabled) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetCorruption] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	RegisteredPlugins::CorruptionEnabled[PluginIndex] = CorruptionEnabled;

	uint8_t bValue = 1;

	if (CorruptionEnabled == true || FindInVector(RegisteredPlugins::CorruptionEnabled, bValue) >= 0) {
		Configuration::AllowPlayerCorruption = true;
	}
	else {
		Configuration::AllowPlayerCorruption = false;
	}
}

bool OnGetCorruption(RE::StaticFunctionTag*) {
	return Configuration::AllowPlayerCorruption;
}

void OnSetShameless(RE::StaticFunctionTag*, std::string Plugin, bool ShamelessEnabled) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetShameless] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	RegisteredPlugins::ShamelessEnabled[PluginIndex] = ShamelessEnabled;

	uint8_t bValue = 1;

	if (ShamelessEnabled == true || FindInVector(RegisteredPlugins::ShamelessEnabled, bValue) >= 0) {
		Configuration::AllowPlayerShameless = true;
	}
	else {
		Configuration::AllowPlayerShameless = false;
	}
}

bool OnGetShameless(RE::StaticFunctionTag*) {
	return Configuration::AllowPlayerShameless;
}

void OnSetModestyUpgradeBlocked(RE::StaticFunctionTag*, std::string Plugin, bool UpgradeBlocked) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [SetModestyUpgradeBlocked] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	RegisteredPlugins::UpgradeBlocked[PluginIndex] = UpgradeBlocked;

	uint8_t bValue = 1;

	if (UpgradeBlocked == true || FindInVector(RegisteredPlugins::UpgradeBlocked, bValue) >= 0) {
		Configuration::ModestyUpgradeBlocked = true;
	}
	else {
		Configuration::ModestyUpgradeBlocked = false;
	}
}

bool OnGetModestyUpgradeBlocked(RE::StaticFunctionTag*) {
	return Configuration::ModestyUpgradeBlocked;
}

void OnSetImmodestyTime(RE::StaticFunctionTag*, std::string Plugin, int ImmodestyTime) {
	int PluginIndex = FindInVector(RegisteredPlugins::Plugins, Plugin);
	if (PluginIndex < 0) {
		Log("<C++ ModEventListener> [OnSetImmodestyTime] Plugin " + Plugin + " is not registered!", LogType::Core, LoggingLevel::warning);
		return;
	}

	RegisteredPlugins::ImmodestyTimeRequired[PluginIndex] = ImmodestyTime;

	int ImmodestySum = 0;
	int AlteredTimers = 0;

	int Index = 0;
	while (Index < RegisteredPlugins::TotalRegisteredPlugins) {
		if (RegisteredPlugins::ImmodestyTimeRequired[Index] > 0) {
			ImmodestySum += RegisteredPlugins::ImmodestyTimeRequired[Index];
			AlteredTimers++;
		}
		Index++;
	}

	if (AlteredTimers > 0) {
		Configuration::ImmodestyTimeNeeded = (ImmodestySum / AlteredTimers);
	}
	else {
		Configuration::ImmodestyTimeNeeded = 14;
	}
}

int OnGetImmodestyTime(RE::StaticFunctionTag*) {
	return Configuration::ImmodestyTimeNeeded;
}