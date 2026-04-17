#include "Logger.h"

void EnableLogging(RE::StaticFunctionTag*, bool loggingEnabled) {
	doLogging = loggingEnabled;
}

void SetLogLevel(RE::StaticFunctionTag*, int loggingLevel) {
	logLevel = loggingLevel;
}

void ExternalLog(RE::StaticFunctionTag*, std::string logString, int severity) {
	if (severity < 3 && (doLogging == false || logLevel < severity)) {
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

void Log(std::string logString, int severity) {
	if (severity < 3 && (doLogging == false || logLevel < severity)) {
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