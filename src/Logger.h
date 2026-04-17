#pragma once

enum LoggingLevel {info, warning, error, critical};

bool doLogging = false;
int logLevel = 1;

void EnableLogging(RE::StaticFunctionTag*, bool loggingEnabled);
void SetLogLevel(RE::StaticFunctionTag*, int loggingLevel);
void ExternalLog(RE::StaticFunctionTag*, std::string logString, int severity);
void Log(std::string logString, int severity);