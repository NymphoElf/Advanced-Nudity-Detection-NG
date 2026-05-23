#include "Logger.h"

void ExternalLog(RE::StaticFunctionTag*, std::string logString, int loggingType, int severity) {
	if (LogLevelEnabled[severity] == false || (LogTypeEnabled[loggingType] == false && severity < LoggingLevel::critical)) {
		return;
	}

	switch (severity) {
		case 0:
			logs::info("{}", logString);
			break;
		case 1:
			logs::warn("{}", logString);
			break;
		case 2:
			logs::error("{}", logString);
			break;
		case 3:
			logs::critical("{}", logString);
			break;
		default:
			logs::info("{}", logString);
			break;
	};
}

void Log(std::string logString, int loggingType, int severity) {
	if (LogLevelEnabled[severity] == false || (LogTypeEnabled[loggingType] == false && severity < LoggingLevel::critical)) {
		return;
	}

	switch (severity) {
		case 0:
			logs::info("{}", logString);
			break;
		case 1:
			logs::warn("{}", logString);
			break;
		case 2:
			logs::error("{}", logString);
			break;
		case 3:
			logs::critical("{}", logString);
			break;
		default:
			logs::info("{}", logString);
			break;
	};
}

void UpdateLoggingType(RE::StaticFunctionTag*, int LogTypeIndex, bool Enabled) {
	LogTypeEnabled[LogTypeIndex] = Enabled;
}

void UpdateLoggingLevel(RE::StaticFunctionTag*, int LogLevelIndex, bool Enabled) {
	LogLevelEnabled[LogLevelIndex] = Enabled;
}

std::vector<bool> GetLogSettings(RE::StaticFunctionTag*) {
	std::vector<bool> LogSettings;

	LogSettings.emplace_back(LogTypeEnabled[LogType::Misc]); //0
	LogSettings.emplace_back(LogTypeEnabled[LogType::Core]); //1
	LogSettings.emplace_back(LogTypeEnabled[LogType::PlayerArmorScan]); //2
	LogSettings.emplace_back(LogTypeEnabled[LogType::PlayerModesty]); //3
	LogSettings.emplace_back(LogTypeEnabled[LogType::NPCData]); //4
	LogSettings.emplace_back(LogTypeEnabled[LogType::NPCArmorScan]); //5
	LogSettings.emplace_back(LogTypeEnabled[LogType::NPCModesty]); //6
	LogSettings.emplace_back(LogTypeEnabled[LogType::Config]); //7

	LogSettings.emplace_back(LogLevelEnabled[LoggingLevel::info]); //8
	LogSettings.emplace_back(LogLevelEnabled[LoggingLevel::warning]); //9
	LogSettings.emplace_back(LogLevelEnabled[LoggingLevel::error]); //10

	return LogSettings;
}