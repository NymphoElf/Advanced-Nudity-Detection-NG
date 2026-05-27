ScriptName AND_Logger Extends Quest

Int Property WARNING = 1 AutoReadOnly
Int Property ERROR = 2 AutoReadOnly
Int Property CRITICAL = 3 AutoReadOnly

Int Property Misc = 0 AutoReadOnly
Int Property Core = 1 AutoReadOnly
Int Property PlayerArmorScan = 2 AutoReadOnly
Int Property PlayerModesty = 3 AutoReadOnly
Int Property NPCData = 4 AutoReadOnly
Int Property NPCArmorScan = 5 AutoReadOnly
Int Property NPCModesty = 6 AutoReadOnly
Int Property Config = 7 AutoReadOnly

Function FastLog(String LogString, Int LogType = 0, Int Severity = 0) Global Native

Function UpdateLoggingType(Int LogTypeIndex, Bool Enabled) Global Native
Function UpdateLoggingLevel(Int LogLevelIndex, Bool Enabled) Global Native

Bool[] Function GetLogSettings() Global Native