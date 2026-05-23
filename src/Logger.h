#pragma once

enum LoggingLevel {info, warning, error, critical};

enum LogType {
	Misc,
	Core,
	PlayerArmorScan,
	PlayerModesty,
	NPCData,
	NPCArmorScan,
	NPCModesty,
	Config,

	TotalTypes
};

inline bool LogTypeEnabled[LogType::TotalTypes] = {true, true, true, true, true, true, true, true};
inline bool LogLevelEnabled[4] = { true, true, true, true };

void Log(std::string logString, int loggingType = LogType::Misc, int severity = LoggingLevel::info);

void ExternalLog(RE::StaticFunctionTag*, std::string logString, int loggingType = LogType::Misc, int severity = LoggingLevel::info);
void UpdateLoggingType(RE::StaticFunctionTag*, int LogTypeIndex, bool Enabled);
void UpdateLoggingLevel(RE::StaticFunctionTag*, int LogLevelIndex, bool Enabled);

std::vector<bool> GetLogSettings(RE::StaticFunctionTag*);