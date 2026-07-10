Scriptname AND_MCM extends SKI_Configbase

AND_Core Property Main Auto
AND_PlayerScript Property PlayerScript Auto
AND_Modesty_Manager Property ModestyManager Auto
AND_KeybindManager Property Keybinds Auto
AND_Logger Property Logger Auto

Actor Property PlayerRef Auto
Actor Property SelectedFemaleActor Auto Hidden

Float Property ThisNPCStrictRank Auto Hidden
Float Property ThisNPCMinimumStrictRank Auto Hidden
Float Property ThisNPCTopRank Auto Hidden
Float Property ThisNPCMinimumTopRank Auto Hidden
Float Property ThisNPCBottomRank Auto Hidden
Float Property ThisNPCMinimumBottomRank Auto Hidden

Bool Property ThisNPCShameless Auto Hidden
Bool Property ThisNPCCorrupt Auto Hidden
Bool Property ThisNPCStrictRules Auto Hidden
Bool Property ThisNPCUpgradeBlocked Auto Hidden

Int[] Property FlashRolls Auto Hidden

Int Property ChestCurtainRoll = 0 AutoReadOnly
Int Property PelvicCurtainRoll = 1 AutoReadOnly
Int Property AssCurtainRoll = 2 AutoReadOnly
Int Property CStringRoll = 3 AutoReadOnly
Int Property TopTransparentRoll = 4 AutoReadOnly
Int Property BottomTransparentRoll = 5 AutoReadOnly
Int Property BraTransparentRoll = 6 AutoReadOnly
Int Property UnderwearTransparentRoll = 7 AutoReadOnly
Int Property HotpantsTransparentRoll = 8 AutoReadOnly
Int Property ShowgirlTransparentRoll = 9 AutoReadOnly

Int Property NPCChestCurtainRoll = 10 AutoReadOnly
Int Property NPCPelvicCurtainRoll = 11 AutoReadOnly
Int Property NPCAssCurtainRoll = 12 AutoReadOnly
Int Property NPCCStringRoll = 13 AutoReadOnly
Int Property NPCTopTransparentRoll = 14 AutoReadOnly
Int Property NPCBottomTransparentRoll = 15 AutoReadOnly
Int Property NPCBraTransparentRoll = 16 AutoReadOnly
Int Property NPCUnderwearTransparentRoll = 17 AutoReadOnly
Int Property NPCHotpantsTransparentRoll = 18 AutoReadOnly
Int Property NPCShowgirlTransparentRoll = 19 AutoReadOnly

Int[] Property FlashOdds Auto Hidden

Int Property ChestCurtainOddsLow = 0 AutoReadOnly
Int Property ChestCurtainOdds = 1 AutoReadOnly
Int Property ChestCurtainOddsHigh = 2 AutoReadOnly
Int Property ChestCurtainOddsExtreme = 3 AutoReadOnly
Int Property ChestCurtainOddsUltra = 4 AutoReadOnly

Int Property PelvicCurtainOddsLow = 5 AutoReadOnly
Int Property PelvicCurtainOdds = 6 AutoReadOnly
Int Property PelvicCurtainOddsHigh = 7 AutoReadOnly
Int Property PelvicCurtainOddsExtreme = 8 AutoReadOnly
Int Property PelvicCurtainOddsUltra = 9 AutoReadOnly

Int Property AssCurtainOddsLow = 10 AutoReadOnly
Int Property AssCurtainOdds = 11 AutoReadOnly
Int Property AssCurtainOddsHigh = 12 AutoReadOnly
Int Property AssCurtainOddsExtreme = 13 AutoReadOnly
Int Property AssCurtainOddsUltra = 14 AutoReadOnly

Int Property TransparentChestCurtainOddsLow = 15 AutoReadOnly
Int Property TransparentChestCurtainOdds = 16 AutoReadOnly
Int Property TransparentChestCurtainOddsHigh = 17 AutoReadOnly
Int Property TransparentChestCurtainOddsExtreme = 18 AutoReadOnly
Int Property TransparentChestCurtainOddsUltra = 19 AutoReadOnly

Int Property TransparentPelvicCurtainOddsLow = 20 AutoReadOnly
Int Property TransparentPelvicCurtainOdds = 21 AutoReadOnly
Int Property TransparentPelvicCurtainOddsHigh = 22 AutoReadOnly
Int Property TransparentPelvicCurtainOddsExtreme = 23 AutoReadOnly
Int Property TransparentPelvicCurtainOddsUltra = 24 AutoReadOnly

Int Property TransparentAssCurtainOddsLow = 25 AutoReadOnly
Int Property TransparentAssCurtainOdds = 26 AutoReadOnly
Int Property TransparentAssCurtainOddsHigh = 27 AutoReadOnly
Int Property TransparentAssCurtainOddsExtreme = 28 AutoReadOnly
Int Property TransparentAssCurtainOddsUltra = 29 AutoReadOnly

Int Property TransparentTopArmorOdds_Low = 30 AutoReadOnly
Int Property TransparentTopArmorOdds = 31 AutoReadOnly
Int Property TransparentTopArmorOdds_High = 32 AutoReadOnly

Int Property TransparentBottomArmorOdds_Low = 33 AutoReadOnly
Int Property TransparentBottomArmorOdds = 34 AutoReadOnly
Int Property TransparentBottomArmorOdds_High = 35 AutoReadOnly

Int Property TransparentBraOdds_Low = 36 AutoReadOnly
Int Property TransparentBraOdds = 37 AutoReadOnly
Int Property TransparentBraOdds_High = 38 AutoReadOnly

Int Property TransparentUnderwearOdds_Low = 39 AutoReadOnly
Int Property TransparentUnderwearOdds = 40 AutoReadOnly
Int Property TransparentUnderwearOdds_High = 41 AutoReadOnly

Int Property TransparentHotpantsOdds_Low = 42 AutoReadOnly
Int Property TransparentHotpantsOdds = 43 AutoReadOnly
Int Property TransparentHotpantsOdds_High = 44 AutoReadOnly

Int Property TransparentShowgirlSkirtOdds_Low = 45 AutoReadOnly
Int Property TransparentShowgirlSkirtOdds = 46 AutoReadOnly
Int Property TransparentShowgirlSkirtOdds_High = 47 AutoReadOnly

Int Property CStringOdds = 48 AutoReadOnly

Int Property TransparentCStringOdds_Low = 49 AutoReadOnly
Int Property TransparentCStringOdds = 50 AutoReadOnly
Int Property TransparentCStringOdds_High = 51 AutoReadOnly

;MALE ODDS

Int Property ChestCurtainOddsLow_Male = 52 AutoReadOnly
Int Property ChestCurtainOdds_Male = 53 AutoReadOnly
Int Property ChestCurtainOddsHigh_Male = 54 AutoReadOnly
Int Property ChestCurtainOddsExtreme_Male = 55 AutoReadOnly
Int Property ChestCurtainOddsUltra_Male = 56 AutoReadOnly

Int Property PelvicCurtainOddsLow_Male = 57 AutoReadOnly
Int Property PelvicCurtainOdds_Male = 58 AutoReadOnly
Int Property PelvicCurtainOddsHigh_Male = 59 AutoReadOnly
Int Property PelvicCurtainOddsExtreme_Male = 60 AutoReadOnly
Int Property PelvicCurtainOddsUltra_Male = 61 AutoReadOnly

Int Property AssCurtainOddsLow_Male = 62 AutoReadOnly
Int Property AssCurtainOdds_Male = 63 AutoReadOnly
Int Property AssCurtainOddsHigh_Male = 64 AutoReadOnly
Int Property AssCurtainOddsExtreme_Male = 65 AutoReadOnly
Int Property AssCurtainOddsUltra_Male = 66 AutoReadOnly

Int Property TransparentChestCurtainOddsLow_Male = 67 AutoReadOnly
Int Property TransparentChestCurtainOdds_Male = 68 AutoReadOnly
Int Property TransparentChestCurtainOddsHigh_Male = 69 AutoReadOnly
Int Property TransparentChestCurtainOddsExtreme_Male = 70 AutoReadOnly
Int Property TransparentChestCurtainOddsUltra_Male = 71 AutoReadOnly

Int Property TransparentPelvicCurtainOddsLow_Male = 72 AutoReadOnly
Int Property TransparentPelvicCurtainOdds_Male = 73 AutoReadOnly
Int Property TransparentPelvicCurtainOddsHigh_Male = 74 AutoReadOnly
Int Property TransparentPelvicCurtainOddsExtreme_Male = 75 AutoReadOnly
Int Property TransparentPelvicCurtainOddsUltra_Male = 76 AutoReadOnly

Int Property TransparentAssCurtainOddsLow_Male = 77 AutoReadOnly
Int Property TransparentAssCurtainOdds_Male = 78 AutoReadOnly
Int Property TransparentAssCurtainOddsHigh_Male = 79 AutoReadOnly
Int Property TransparentAssCurtainOddsExtreme_Male = 80 AutoReadOnly
Int Property TransparentAssCurtainOddsUltra_Male = 81 AutoReadOnly

Int Property TransparentTopArmorOdds_Low_Male = 82 AutoReadOnly
Int Property TransparentTopArmorOdds_Male = 83 AutoReadOnly
Int Property TransparentTopArmorOdds_High_Male = 84 AutoReadOnly

Int Property TransparentBottomArmorOdds_Low_Male = 85 AutoReadOnly
Int Property TransparentBottomArmorOdds_Male = 86 AutoReadOnly
Int Property TransparentBottomArmorOdds_High_Male = 87 AutoReadOnly

Int Property TransparentBraOdds_Low_Male = 88 AutoReadOnly
Int Property TransparentBraOdds_Male = 89 AutoReadOnly
Int Property TransparentBraOdds_High_Male = 90 AutoReadOnly

Int Property TransparentUnderwearOdds_Low_Male = 91 AutoReadOnly
Int Property TransparentUnderwearOdds_Male = 92 AutoReadOnly
Int Property TransparentUnderwearOdds_High_Male = 93 AutoReadOnly

Int Property TransparentHotpantsOdds_Low_Male = 94 AutoReadOnly
Int Property TransparentHotpantsOdds_Male = 95 AutoReadOnly
Int Property TransparentHotpantsOdds_High_Male = 96 AutoReadOnly

Int Property TransparentShowgirlSkirtOdds_Low_Male = 97 AutoReadOnly
Int Property TransparentShowgirlSkirtOdds_Male = 98 AutoReadOnly
Int Property TransparentShowgirlSkirtOdds_High_Male = 99 AutoReadOnly

Int Property CStringOdds_Male = 100 AutoReadOnly

Int Property TransparentCStringOdds_Low_Male = 101 AutoReadOnly
Int Property TransparentCStringOdds_Male = 102 AutoReadOnly
Int Property TransparentCStringOdds_High_Male = 103 AutoReadOnly

Int Property TotalFlashOddsLength = 104 AutoReadOnly

;/
SKSE CONFIG OPTIONS
/;

Int Property Enum_Male = 0 AutoReadOnly
Int Property Enum_Female = 1 AutoReadOnly

Bool[] Property WornKeywordList Auto Hidden

Int Property ArmorTop = 0 AutoReadOnly
Int Property ArmorTop_NoCover = 1 AutoReadOnly
Int Property ArmorTopT_Low = 2 AutoReadOnly
Int Property ArmorTopT = 3 AutoReadOnly
Int Property ArmorTopT_High = 4 AutoReadOnly

Int Property ArmorBottom = 5 AutoReadOnly
Int Property ArmorBottom_NoCover = 6 AutoReadOnly
Int Property ArmorBottomT_Low = 7 AutoReadOnly
Int Property ArmorBottomT = 8 AutoReadOnly
Int Property ArmorBottomT_High = 9 AutoReadOnly

Int Property AssCurtain = 10 AutoReadOnly
Int Property AssCurtainT = 11 AutoReadOnly

Int Property AssFlashRiskLow = 12 AutoReadOnly
Int Property AssFlashRisk = 13 AutoReadOnly
Int Property AssFlashRiskHigh = 14 AutoReadOnly
Int Property AssFlashRiskExtreme = 15 AutoReadOnly
Int Property AssFlashRiskUltra = 16 AutoReadOnly

Int Property Bra = 17 AutoReadOnly
Int Property Bra_NoCover = 18 AutoReadOnly
Int Property BraT_Low = 19 AutoReadOnly
Int Property BraT = 20 AutoReadOnly
Int Property BraT_High = 21 AutoReadOnly

Int Property ChestCurtain = 22 AutoReadOnly
Int Property ChestCurtainT = 23 AutoReadOnly

Int Property ChestFlashRiskLow = 24 AutoReadOnly
Int Property ChestFlashRisk = 25 AutoReadOnly
Int Property ChestFlashRiskHigh = 26 AutoReadOnly
Int Property ChestFlashRiskExtreme = 27 AutoReadOnly
Int Property ChestFlashRiskUltra = 28 AutoReadOnly

Int Property CoversAll = 29 AutoReadOnly

Int Property CString = 30 AutoReadOnly
Int Property CStringT_Low = 31 AutoReadOnly
Int Property CStringT = 32 AutoReadOnly
Int Property CStringT_High = 33 AutoReadOnly
Int Property BananaHammock = 30 AutoReadOnly
Int Property BananaHammockT_Low = 31 AutoReadOnly
Int Property BananaHammockT = 32 AutoReadOnly
Int Property BananaHammockT_High = 33 AutoReadOnly

Int Property EffectivelyNaked = 34 AutoReadOnly

Int Property Hotpants = 35 AutoReadOnly
Int Property HotpantsT_Low = 36 AutoReadOnly
Int Property HotpantsT = 37 AutoReadOnly
Int Property HotpantsT_High = 38 AutoReadOnly

Int Property Microskirt = 39 AutoReadOnly

Int Property Miniskirt = 40 AutoReadOnly
Int Property MiniskirtT = 41 AutoReadOnly

Int Property NearlyNaked = 42 AutoReadOnly
Int Property NipplePasties = 43 AutoReadOnly

Int Property PelvicCurtain = 44 AutoReadOnly
Int Property PelvicCurtainT = 45 AutoReadOnly

Int Property PelvicFlashRiskLow = 46 AutoReadOnly
Int Property PelvicFlashRisk = 47 AutoReadOnly
Int Property PelvicFlashRiskHigh = 48 AutoReadOnly
Int Property PelvicFlashRiskExtreme = 49 AutoReadOnly
Int Property PelvicFlashRiskUltra = 50 AutoReadOnly

Int Property ShowgirlSkirt = 51 AutoReadOnly
Int Property ShowgirlSkirtT_Low = 52 AutoReadOnly
Int Property ShowgirlSkirtT = 53 AutoReadOnly
Int Property ShowgirlSkirtT_High = 54 AutoReadOnly
Int Property HimboSkirt = 51 AutoReadOnly
Int Property HimboSkirtT_Low = 52 AutoReadOnly
Int Property HimboSkirtT = 53 AutoReadOnly
Int Property HimboSkirtT_High = 54 AutoReadOnly

Int Property Thong = 55 AutoReadOnly
Int Property Thong_NoCover = 56 AutoReadOnly
Int Property ThongT_Low = 57 AutoReadOnly
Int Property ThongT = 58 AutoReadOnly
Int Property ThongT_High = 59 AutoReadOnly

Int Property Underwear = 60 AutoReadOnly
Int Property Underwear_NoCover = 61 AutoReadOnly
Int Property UnderwearT_Low = 62 AutoReadOnly
Int Property UnderwearT = 63 AutoReadOnly
Int Property UnderwearT_High = 64 AutoReadOnly

Int Property VaginaPasties = 65 AutoReadOnly

Bool[] Property ConfigBoolOptions Auto Hidden

Int Property MotionFlashEnabled = 0 AutoReadOnly
Int Property DynamicModestyEnabled = 1 AutoReadOnly
Int Property AllowPlayerShameless = 2 AutoReadOnly
Int Property NPCShamelessByDefault = 3 AutoReadOnly
Int Property AllowPlayerCorruption = 4 AutoReadOnly
Int Property NPCCorruptionByDeault = 5 AutoReadOnly
Int Property PlayerStrictRules = 6 AutoReadOnly
Int Property NPCStrictRulesByDefault = 7 AutoReadOnly
Int Property HardcoreModeEnabled = 8 AutoReadOnly
Int Property PlayerModestyUpgradeBlocked = 9 AutoReadOnly
Int Property DisableNakedComments = 10 AutoReadOnly

Int[] Property ConfigIntOptions Auto Hidden

Int Property RunningModifier = 0 AutoReadOnly
Int Property SprintingModifier = 1 AutoReadOnly

Int Property MinimumStrictRank = 2 AutoReadOnly
Int Property MinimumTopRank = 3 AutoReadOnly
Int Property MinimumBottomRank = 4 AutoReadOnly

Int Property ImmodestyTimeNeeded = 5 AutoReadOnly
Int Property PlayerConfidenceValue = 6 AutoReadOnly

Int Property NudeFactionCommentChance = 7 AutoReadOnly
Int Property ToplessFactionCommentChance = 8 AutoReadOnly
Int Property BottomlessFactionCommentChance = 9 AutoReadOnly
Int Property ChestFactionCommentChance = 10 AutoReadOnly
Int Property GenitalsFactionCommentChance = 11 AutoReadOnly
Int Property AssFactionCommentChance = 12 AutoReadOnly
Int Property BraFactionCommentChance = 13 AutoReadOnly
Int Property UnderwearFactionCommentChance = 14 AutoReadOnly

Int[] Property PlayerCurtainState Auto Hidden

Int Property Enum_ChestCurtain = 0 AutoReadOnly
Int Property Enum_PelvicCurtain = 1 AutoReadOnly
Int Property Enum_AssCurtain = 2 AutoReadOnly

Int Property NotWearing = 0 AutoReadOnly
Int Property Covering = 1 AutoReadOnly
Int Property Flashing = 2 AutoReadOnly

Int[] Property PlayerFactionRanks Auto Hidden

Int Property NudeFaction = 0 AutoReadOnly
Int Property ToplessFaction = 1 AutoReadOnly
Int Property BottomlessFaction = 2 AutoReadOnly
Int Property ShowingChestFaction = 3 AutoReadOnly
Int Property ShowingGenitalsFaction = 4 AutoReadOnly
Int Property ShowingAssFaction = 5 AutoReadOnly
Int Property ShowingBraFaction = 6 AutoReadOnly
Int Property ShowingUnderwearFaction = 7 AutoReadOnly

Int Property ModestyFaction = 8 AutoReadOnly
Int Property TopModestyFaction = 9 AutoReadOnly
Int Property BottomModestyFaction = 10 AutoReadOnly

Int Property ShyWithFemale = 11 AutoReadOnly
Int Property ShyWithMale = 12 AutoReadOnly

Int Property ArousalFaction = 13 AutoReadOnly

Int[] Property StrictModestyTimers Auto Hidden ;0-6
Int[] Property SimpleModestyTimers Auto Hidden ;0-7 (0-3 = Top | 4-7 = Bottom)

Actor[] Property RegisteredFemaleActors Auto Hidden
Actor[] Property PermanentFemaleActors Auto Hidden

Int[] Property FemaleActorData Auto Hidden

Int Property FemaleActorData_CurrentStrictRank = 0 AutoReadOnly
Int Property FemaleActorData_MinimumStrictRank = 1 AutoReadOnly
Int Property FemaleActorData_CurrentTopRank = 2 AutoReadOnly
Int Property FemaleActorData_MinimumTopRank = 3 AutoReadOnly
Int Property FemaleActorData_CurrentBottomRank = 4 AutoReadOnly
Int Property FemaleActorData_MinimumBottomRank = 5 AutoReadOnly
Int Property FemaleActorData_Shameless = 6 AutoReadOnly
Int Property FemaleActorData_Corrupt = 7 AutoReadOnly
Int Property FemaleActorData_ShySexIndex = 8 AutoReadOnly
Int Property FemaleActorData_UsingStrictRules = 9 AutoReadOnly
Int Property FemaleActorData_UpgradeBlocked = 10 AutoReadOnly

Bool[] Property LogSettings Auto Hidden

Int Property LogType_Misc = 0 AutoReadOnly
Int Property LogType_Core = 1 AutoReadOnly
Int Property LogType_PlayerArmorScan = 2 AutoReadOnly
Int Property LogType_PlayerModesty = 3 AutoReadOnly
Int Property LogType_NPCData = 4 AutoReadOnly
Int Property LogType_NPCArmorScan = 5 AutoReadOnly
Int Property LogType_NPCModesty = 6 AutoReadOnly
Int Property LogType_Config = 7 AutoReadOnly

Int Property LogLevel_Info = 8 AutoReadOnly
Int Property LogLevel_Warning = 9 AutoReadOnly
Int Property LogLevel_Error = 10 AutoReadOnly

;/
PAPYRUS-ONLY CONFIG OPTIONS
/;

Bool Property GenderlessWording Auto Hidden
Bool Property ConfirmSelection Auto Hidden

Bool Property Rank1Jump = False Auto Hidden
Bool Property Rank2Jump = False Auto Hidden
Bool Property Rank3Jump = False Auto Hidden
Bool Property Rank4Jump = False Auto Hidden
Bool Property Rank5Jump = False Auto Hidden
Bool Property Rank6Jump = False Auto Hidden

Bool Property TopRank1Jump = False Auto Hidden
Bool Property TopRank2Jump = False Auto Hidden
Bool Property TopRank3Jump = False Auto Hidden

Bool Property BottomRank1Jump = False Auto Hidden
Bool Property BottomRank2Jump = False Auto Hidden
Bool Property BottomRank3Jump = False Auto Hidden

Bool Property ResetModesty = False Auto Hidden
Bool Property ResetFemaleModesty = False Auto Hidden 
Bool Property RandomizePlayer = False Auto Hidden

Bool Property HardcoreLockdown Auto Hidden
Bool Property ResetAllNPCs = False Auto Hidden
Bool Property DeleteAllNPCs = False Auto Hidden
Bool Property ModestyMonologue = True Auto Hidden
Bool Property ModestyMessagebox = True Auto Hidden

Bool Property TopCurtainLayer_Cover Auto Hidden
Bool Property PelvicCurtain_Cover Auto Hidden
Bool Property AssCurtain_Cover Auto Hidden

Bool Property ScanNPC = True Auto Hidden

Bool Property ApplyTweak = False Auto Hidden
Bool Property ApplyAsDefault = False Auto Hidden

Bool Property StrictNPC = False Auto Hidden

String Property PlayerConfidence = "Average" Auto Hidden
String Property ShySex = "Males" Auto Hidden
String Property NPCShySex = "Males" Auto Hidden
String Property ThisNPCShySex = "Males" Auto Hidden
String[] Property Sexes Auto
String[] Property NPCSexes Auto

GlobalVariable Property ModestyArousalThreshold Auto
GlobalVariable Property NPCModestyArousalThreshold Auto
GlobalVariable Property AND_DynamicModesty Auto

Int[] Property FlashKey Auto

Int[] Property DynamicModestyToggles Auto Hidden
Int[] Property DynamicModestyMenus Auto Hidden

Int[] Property StrictModestyToggles Auto Hidden

Int[] Property SimpleModestyToggles Auto Hidden
Int[] Property SimpleModestySliders Auto Hidden

Int[] Property NPCModestyToggles Auto Hidden
Int[] Property NPCModestySliders Auto Hidden
Int[] Property NPCModestyMenus Auto Hidden

Int[] Property FlashKeyToggles Auto Hidden
Int[] Property FlashKeyMaps Auto Hidden

Int[] Property LoggingToggles Auto Hidden

String Property ScanFrequency = "Normal" Auto Hidden

String[] Property RegisteredFemaleNames Auto Hidden
Int Property DisplayIndex = 0 Auto Hidden
Int Property CurrentRegisteredFemalePage = 1 Auto Hidden
Int Property MaxRegisteredFemalePages = 1 Auto Hidden
String Property SelectedFemale = "---" Auto Hidden
Bool Property MakeFemalePermanent = False Auto Hidden
Bool Property DeleteFemale = False Auto Hidden

String[] Property PermanentFemaleNames Auto Hidden
Int Property PermIndex = 0 Auto Hidden
Int Property CurrentPermanentFemalePage = 1 Auto Hidden
Int Property MaxPermanentFemalePages = 1 Auto Hidden
String Property SelectedPermFemale = "---" Auto Hidden
Bool Property DeletePermFemale = False Auto Hidden

Event OnConfigInit()
	Startup()
EndEvent

Event OnUpdate()
	AND_Logger.FastLog("<MCM> [OnUpdate] - START", Logger.Config, Logger.CRITICAL)
	InstallMCM()
	
	ConfigBoolOptions = GetConfigBoolOptions()
	ConfigIntOptions = GetConfigIntOptions()
	
	FlashOdds = GetFlashOdds()
	
	ModestyArousalThreshold.SetValue(70)
	NPCModestyArousalThreshold.SetValue(70)
	
	Debug.Notification("Advanced Nudity MCM Ready!")
	AND_Logger.FastLog("<MCM> [OnUpdate] - FINISHED", Logger.Config, Logger.CRITICAL)
EndEvent

Function Startup()
	Utility.Wait(1.0)
	
	Debug.Notification("Advanced Nudity MCM Initializing...")
	
	RegisterForSingleUpdate(1)
	AND_Logger.FastLog("<MCM> [Startup] - Completed!", Logger.Config, Logger.CRITICAL)
EndFunction

Function InstallMCM()
	AND_Logger.FastLog("<MCM> [InstallMCM] - START", Logger.Config, Logger.CRITICAL)
	
	ModName = "Advanced Nudity"
	Pages = New String[15]
	Pages[0] = "$NudityStatesPage"
	Pages[1] = "$FlashingStatesPage"
	
	Pages[2] = "$CurtainKeywordsPage"
	Pages[3] = "$ArmorAndUnderwearKeywordsPage"
	Pages[4] = "$GeneralKeywordsPage"
	Pages[5] = "$FlashRiskKeywordsPage"
	
	Pages[6] = "$FemaleFlashChancesPage"
	Pages[7] = "$MaleFlashChancesPage"
	Pages[8] = "$NakedCommentsPage"
	Pages[9] = "$DynamicModestyPage"
	Pages[10] = "$StrictModestyPage"
	Pages[11] = "$SimpleModestyPage"
	Pages[12] = "$NPCModestyPage"
	Pages[13] = "$FlashKeys"
	Pages[14] = "$DebugPage"
	
	
	DynamicModestyToggles = new Int[9]
	DynamicModestyMenus = new Int[1]
	
	StrictModestyToggles = new Int[6]
	
	SimpleModestyToggles = new Int[6]
	SimpleModestySliders = new Int[2]
	
	NPCModestyToggles = new Int[21]
	NPCModestySliders = new Int[7]
	NPCModestyMenus = new Int[4]
	
	FlashKeyToggles = new Int[4]
	FlashKeyMaps = new Int[6]
	
	LoggingToggles = new Int[11]
	
	AND_Logger.FastLog("<MCM> [InstallMCM] - END", Logger.Config, Logger.CRITICAL)
EndFunction

Actor[] Function GetRegisteredFemaleActors(Int PageNumber) Global Native
Actor[] Function GetPermanentFemaleActors(Int PageNumber) Global Native

Bool[] Function GetConfigBoolOptions() Global Native

Bool[] Function FemaleWornKeywordList() Global Native
Bool[] Function MaleWornKeywordList() Global Native

Int[] Function GetFlashOdds() Global Native
Int[] Function GetFlashRolls() Global Native

Int[] Function GetCurtainCoverage() Global Native

Int[] Function GetConfigIntOptions() Global Native

Int[] Function GetPlayerFactionRanks() Global Native
Int[] Function GetPlayerStrictModestyTimers() Global Native
Int[] Function GetPlayerSimpleModestyTimers() Global Native

Int[] Function GetFemaleActorData(Actor akFemale) Global Native

Int Function GetRegisteredFemalesPages() Global Native
Int Function GetPermanentFemalesPages() Global Native

String[] Function GetRegisteredFemaleNames(Int PageNumber) Global Native
String[] Function GetPermanentFemaleNames(Int PageNumber) Global Native

String Function GetFemaleActorFormID(Actor akFemale) Global Native

Event OnConfigOpen()
	AND_Logger.FastLog("<MCM> [OnConfigOpen] - START")
	
	LogSettings = AND_Logger.GetLogSettings()
	
	ConfigBoolOptions = GetConfigBoolOptions()
	
	If ConfigBoolOptions[HardcoreModeEnabled] == True
		HardcoreLockdown = True
	EndIf
	
	ConfigIntOptions = GetConfigIntOptions()
	
	FlashOdds = GetFlashOdds()
	FlashRolls = GetFlashRolls()
	
	PlayerCurtainState = GetCurtainCoverage()
	
	MaxRegisteredFemalePages = GetRegisteredFemalesPages()
	MaxPermanentFemalePages = GetPermanentFemalesPages()
	
	If MaxRegisteredFemalePages > CurrentRegisteredFemalePage
		CurrentRegisteredFemalePage = MaxRegisteredFemalePages
	ElseIf CurrentRegisteredFemalePage < 1
		CurrentRegisteredFemalePage = 1
	EndIf
	
	If MaxPermanentFemalePages > CurrentPermanentFemalePage
		CurrentPermanentFemalePage = MaxPermanentFemalePages
	ElseIf CurrentPermanentFemalePage < 1
		CurrentPermanentFemalePage = 1
	EndIf
	
	RegisteredFemaleNames = GetRegisteredFemaleNames(CurrentRegisteredFemalePage)
	RegisteredFemaleActors = GetRegisteredFemaleActors(CurrentRegisteredFemalePage)
	
	PermanentFemaleNames = GetPermanentFemaleNames(CurrentPermanentFemalePage)
	PermanentFemaleActors = GetPermanentFemaleActors(CurrentPermanentFemalePage)
	
	If DisplayIndex >= RegisteredFemaleActors.Length && RegisteredFemaleActors.Length > 0
		DisplayIndex = 0
		
		SelectedFemale = RegisteredFemaleNames[DisplayIndex]
		SelectedFemaleActor = RegisteredFemaleActors[DisplayIndex]
	ElseIf RegisteredFemaleActors.Length == 0
		SelectedFemale = "---"
		SelectedFemaleActor = None
	EndIf
	
	If PermIndex >= PermanentFemaleActors.Length && PermanentFemaleActors.Length > 0
		PermIndex = 0
		
		SelectedPermFemale = PermanentFemaleNames[PermIndex]
	ElseIf PermanentFemaleActors.Length == 0
		SelectedPermFemale = "---"
	EndIf
	
	If Main.PlayerBase.GetSex() == Enum_Male
		WornKeywordList = MaleWornKeywordList()
	Else
		WornKeywordList = FemaleWornKeywordList()
	EndIf
	
	PlayerFactionRanks = GetPlayerFactionRanks()
	StrictModestyTimers = GetPlayerStrictModestyTimers()
	SimpleModestyTimers = GetPlayerSimpleModestyTimers()
	
	AND_Logger.FastLog("<MCM> [OnConfigOpen] - END")
EndEvent

Function UpdateConfigBoolOptions(Bool[] Options) Global Native
Function UpdateConfigIntOptions(Int[] Options) Global Native

Function UpdateFlashingOdds(Int FlashOddsIndex, Int OddsValue) Global Native

Event OnConfigClose()
	UpdateConfigBoolOptions(ConfigBoolOptions)
	UpdateConfigIntOptions(ConfigIntOptions)
	
	If TopRank1Jump == True
		AND_Modesty_Manager.SKSETopRankJump(1)
	ElseIf TopRank2Jump == True
		AND_Modesty_Manager.SKSETopRankJump(2)
	ElseIf TopRank3Jump == True
		AND_Modesty_Manager.SKSETopRankJump(3)
	EndIf
	
	If BottomRank1Jump == True
		AND_Modesty_Manager.SKSEBottomRankJump(1)
	ElseIf BottomRank2Jump == True
		AND_Modesty_Manager.SKSEBottomRankJump(2)
	ElseIf BottomRank3Jump == True
		AND_Modesty_Manager.SKSEBottomRankJump(3)
	EndIf
	
	If Rank6Jump == True
		AND_Modesty_Manager.SKSERankJump(6)
	ElseIf Rank5Jump == True
		AND_Modesty_Manager.SKSERankJump(5)
	ElseIf Rank4Jump == True
		AND_Modesty_Manager.SKSERankJump(4)
	ElseIf Rank3Jump == True
		AND_Modesty_Manager.SKSERankJump(3)
	ElseIf Rank2Jump == True
		AND_Modesty_Manager.SKSERankJump(2)
	ElseIf Rank1Jump == True
		AND_Modesty_Manager.SKSERankJump(1)
	ElseIf ResetModesty == True
		AND_Modesty_Manager.SKSERankJump(0)
		AND_Modesty_Manager.SKSETopRankJump(0)
		AND_Modesty_Manager.SKSEBottomRankJump(0)
	EndIf
	
	TopRank1Jump = False
	TopRank2Jump = False
	TopRank3Jump = False
	
	BottomRank1Jump = False
	BottomRank2Jump = False
	BottomRank3Jump = False
	
	Rank6Jump = False
	Rank5Jump = False
	Rank4Jump = False
	Rank3Jump = False
	Rank2Jump = False
	Rank1Jump = False
	
	ResetModesty = False
	
	If ScanFrequency == "$VFScan"
		PlayerScript.MaxTimeScale = 40
		PlayerScript.GameTimeUpdateSpeed = 0.1
		If PlayerScript.ScanSetting != "Very Fast"
			PlayerScript.ScanSetting = "Very Fast"
			PlayerScript.UnregisterForUpdateGameTime()
			PlayerScript.RegisterForUpdateGameTime(0.1)
		EndIf
	ElseIf ScanFrequency == "$FScan"
		PlayerScript.MaxTimeScale = 60
		PlayerScript.GameTimeUpdateSpeed = 0.15
		If PlayerScript.ScanSetting != "Fast"
			PlayerScript.ScanSetting = "Fast"
			PlayerScript.UnregisterForUpdateGameTime()
			PlayerScript.RegisterForUpdateGameTime(0.15)
		EndIf
	ElseIf ScanFrequency == "$NScan"
		PlayerScript.MaxTimeScale = 100
		PlayerScript.GameTimeUpdateSpeed = 0.25
		If PlayerScript.ScanSetting != "Normal"
			PlayerScript.ScanSetting = "Normal"
			PlayerScript.UnregisterForUpdateGameTime()
			PlayerScript.RegisterForUpdateGameTime(0.25)
		EndIf
	ElseIf ScanFrequency == "$SScan"
		PlayerScript.MaxTimeScale = 200
		PlayerScript.GameTimeUpdateSpeed = 0.5
		If PlayerScript.ScanSetting != "Slow"
			PlayerScript.ScanSetting = "Slow"
			PlayerScript.UnregisterForUpdateGameTime()
			PlayerScript.RegisterForUpdateGameTime(0.5)
		EndIf
	ElseIf ScanFrequency == "$VSScan"
		PlayerScript.MaxTimeScale = 300
		PlayerScript.GameTimeUpdateSpeed = 0.75
		If PlayerScript.ScanSetting != "Very Slow"
			PlayerScript.ScanSetting = "Very Slow"
			PlayerScript.UnregisterForUpdateGameTime()
			PlayerScript.RegisterForUpdateGameTime(0.75)
		EndIf
	Else
		ScanFrequency = "$NScan"
		PlayerScript.MaxTimeScale = 100
		PlayerScript.GameTimeUpdateSpeed = 0.25
		PlayerScript.ScanSetting = "Normal"
		PlayerScript.UnregisterForUpdateGameTime()
		PlayerScript.RegisterForUpdateGameTime(0.25)
	EndIf
	
	If HardcoreLockdown == False && ConfigBoolOptions[HardcoreModeEnabled] == True
		HardcoreLockdown = True
	EndIf
	
	If RandomizePlayer == True
		Int PlayerModesty = AND_Core.GetRandomizedModesty(PlayerRef)
		
		If PlayerModesty <= 0
			AND_Modesty_Manager.SKSERankJump(0)
			AND_Modesty_Manager.SKSETopRankJump(0)
			AND_Modesty_Manager.SKSEBottomRankJump(0)
		ElseIf PlayerModesty == 1
			AND_Modesty_Manager.SKSERankJump(1)
			AND_Modesty_Manager.SKSETopRankJump(1)
			AND_Modesty_Manager.SKSEBottomRankJump(0)
		ElseIf PlayerModesty == 2
			AND_Modesty_Manager.SKSERankJump(2)
			AND_Modesty_Manager.SKSETopRankJump(1)
			AND_Modesty_Manager.SKSEBottomRankJump(1)
		ElseIf PlayerModesty == 3
			AND_Modesty_Manager.SKSERankJump(3)
			AND_Modesty_Manager.SKSETopRankJump(2)
			AND_Modesty_Manager.SKSEBottomRankJump(1)
		ElseIf PlayerModesty == 4
			AND_Modesty_Manager.SKSERankJump(4)
			AND_Modesty_Manager.SKSETopRankJump(2)
			AND_Modesty_Manager.SKSEBottomRankJump(2)
		ElseIf PlayerModesty == 5
			AND_Modesty_Manager.SKSERankJump(5)
			AND_Modesty_Manager.SKSETopRankJump(3)
			AND_Modesty_Manager.SKSEBottomRankJump(2)
		ElseIf PlayerModesty >= 6
			AND_Modesty_Manager.SKSERankJump(6)
			AND_Modesty_Manager.SKSETopRankJump(3)
			AND_Modesty_Manager.SKSEBottomRankJump(3)
		EndIf
	EndIf
	
	Int EventHandle = ModEvent.Create("AdvancedNudityDetection_MCMChanged")
	ModEvent.Send(EventHandle)
	
	RandomizePlayer = False
	
	ApplyTweak = False
	ApplyAsDefault = False
	ResetAllNPCs = False
	DeleteAllNPCs = False
	MakeFemalePermanent = False
	DeleteFemale = False
	ResetFemaleModesty = False
	DeletePermFemale = False
EndEvent

Event OnPageReset(string page)
	If (page == "")
		Int Screen = Utility.RandomInt(1,8)
		
		Int xPos = 155
		Int yPos = 0
		
		If Screen == 1
			LoadCustomContent("Advanced Nudity Detection/ANDSplash.dds", xPos, yPos)
		ElseIf Screen == 2
			LoadCustomContent("Advanced Nudity Detection/ANDSplashAlmostNude.dds", xPos, yPos)
		ElseIf Screen == 3
			LoadCustomContent("Advanced Nudity Detection/ANDSplashBraPanties.dds", xPos, yPos)
		ElseIf Screen == 4
			LoadCustomContent("Advanced Nudity Detection/ANDSplashCovered.dds", xPos, yPos)
		ElseIf Screen == 5
			LoadCustomContent("Advanced Nudity Detection/ANDSplashNude.dds", xPos, yPos)
		ElseIf Screen == 6
			LoadCustomContent("Advanced Nudity Detection/ANDSplashPanties.dds", xPos, yPos)
		ElseIf Screen == 7
			LoadCustomContent("Advanced Nudity Detection/ANDSplashTopless.dds", xPos, yPos)
		ElseIf Screen == 8
			LoadCustomContent("Advanced Nudity Detection/ANDSplashThanks.dds", xPos, yPos)
		EndIf
		
		return
	Else
		UnloadCustomContent()
	EndIf
	
	SetCursorFillMode(TOP_TO_BOTTOM)
	SetCursorPosition(0)
	
	ActorBase PlayerBase = Main.PlayerBase
	Int PlayerSex = PlayerBase.GetSex()
	
	If (page == "$NudityStatesPage") ;default page
		AddHeaderOption("$NudityConditionsHeader")
		If PlayerRef.GetFactionRank(Main.AND_NudeActorFaction) == 1
			AddTextOption("$NudeText", "$YesText")
		Else
			AddTextOption("$NudeText", "$NoText")
		EndIf
		
		If PlayerRef.GetFactionRank(Main.AND_ToplessFaction) == 1
			AddTextOption("$ToplessText", "$YesText")
		Else
			AddTextOption("$ToplessText", "$NoText")
		EndIf
		
		If PlayerRef.GetFactionRank(Main.AND_BottomlessFaction) == 1
			AddTextOption("$BottomlessText", "$YesText")
		Else
			AddTextOption("$BottomlessText", "$NoText")
		EndIf
		
		If PlayerRef.GetFactionRank(Main.AND_ShowingBraFaction) == 1
			AddTextOption("$ShowingBraText", "$YesText")
		Else
			AddTextOption("$ShowingBraText", "$NoText")
		EndIf
		
		If PlayerRef.GetFactionRank(Main.AND_ShowingChestFaction) == 1
			If PlayerSex == 0 || GenderlessWording == True ;Male/Genderless
				AddTextOption("$ShowingChestText", "$YesText")
			Else
				AddTextOption("$ShowingBoobsText", "$YesText")
			EndIf
		Else
			If PlayerSex == 0 || GenderlessWording == True ;Male/Genderless
				AddTextOption("$ShowingChestText", "$NoText")
			Else
				AddTextOption("$ShowingBoobsText", "$NoText")
			EndIf
		EndIf
		
		If PlayerRef.GetFactionRank(Main.AND_ShowingUnderwearFaction) == 1
			AddTextOption("$ShowingUnderwearText", "$YesText")
		Else
			AddTextOption("$ShowingUnderwearText", "$NoText")
		EndIf
		
		If PlayerRef.GetFactionRank(Main.AND_ShowingGenitalsFaction) == 1
			If PlayerSex == 0 && GenderlessWording == False ;Male
				AddTextOption("$ShowingPenisText", "$YesText")
			ElseIf GenderlessWording == False
				AddTextOption("$ShowingPussyText", "$YesText")
			Else
				AddTextOption("$ShowingGenitalsText", "$YesText")
			EndIf
		Else
			If PlayerSex == 0 && GenderlessWording == False ;Male
				AddTextOption("$ShowingPenisText", "$NoText")
			ElseIf GenderlessWording == False
				AddTextOption("$ShowingPussyText", "$NoText")
			Else
				AddTextOption("$ShowingGenitalsText", "$NoText")
			EndIf
		EndIf
		
		If PlayerRef.GetFactionRank(Main.AND_ShowingAssFaction) == 1
			AddTextOption("$ShowingAssText", "$YesText")
		Else
			AddTextOption("$ShowingAssText", "$NoText")
		EndIf
		
		AddEmptyOption()
		AddToggleOptionST("UseGenderlessState", "$GenderlessWordingText", GenderlessWording, 0)
		
		If PlayerSex == 0 ;Male
			AddTextOption("$BaseSexText", "$MaleText")
		Else
			AddTextOption("$BaseSexText", "$FemaleText")
		EndIf
		
		SetCursorPosition(1)
		
		AddHeaderOption("$CurtainStatesHeader")
		
		If PlayerCurtainState[Enum_ChestCurtain] == Covering
			AddTextOption("$TopCurtainText", "$CoveringText")
		ElseIf PlayerCurtainState[Enum_ChestCurtain] == Flashing
			AddTextOption("$TopCurtainText", "$NotCoveringText")
		Else
			AddTextOption("$TopCurtainText", "$NotWearingText")
		EndIf
		
		If PlayerCurtainState[Enum_PelvicCurtain] == Covering
			AddTextOption("$PelvicCurtainText", "$CoveringText")
		ElseIf PlayerCurtainState[Enum_PelvicCurtain] == Flashing
			AddTextOption("$PelvicCurtainText", "$NotCoveringText")
		Else
			AddTextOption("$PelvicCurtainText", "$NotWearingText")
		EndIf
		
		If PlayerCurtainState[Enum_AssCurtain] == Covering
			AddTextOption("$AssCurtainText", "$CoveringText")
		ElseIf PlayerCurtainState[Enum_AssCurtain] == Flashing
			AddTextOption("$AssCurtainText", "$NotCoveringText")
		Else
			AddTextOption("$AssCurtainText", "$NotWearingText")
		EndIf
		
		AddHeaderOption("$MotionSettingsHeader")
		AddToggleOptionST("AND_AllowMotionFlashState", "$AllowMotionFlashText", ConfigBoolOptions[MotionFlashEnabled], 0)
		AddSliderOptionST("AND_RunningFlashIncreaseState", "$RunningModifierText", ConfigIntOptions[RunningModifier], "{0}", DisabledIf(ConfigBoolOptions[MotionFlashEnabled] == False))
		AddSliderOptionST("AND_SprintingFlashIncreaseState", "$SprintingModifierText", ConfigIntOptions[SprintingModifier], "{0}", DisabledIf(ConfigBoolOptions[MotionFlashEnabled] == False))
		AddHeaderOption("$ScanSettingsHeader")
		AddToggleOptionST("AND_ScanNPCToggle_State", "$ScanNPCText", ScanNPC, 0)
		AddMenuOptionST("AND_ScanFrequency_State", "$ScanFrequencyText", ScanFrequency, 0)
		
	ElseIf (page == "$FlashingStatesPage")
		AddHeaderOption("$CurtainRiskHeader")
		If PlayerSex == Enum_Male ;Male
			
			If WornKeywordList[ChestFlashRiskLow]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsLow_Male] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsLow_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskLow' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRisk]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOdds_Male] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOdds_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRisk' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRiskHigh]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsHigh_Male] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsHigh_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskHigh' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRiskExtreme]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsExtreme_Male] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsExtreme_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskExtreme' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRiskUltra]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsUltra_Male] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsUltra_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskUltra' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			Else
				AddTextOption("$ChestText", "0%")
			EndIf
			
			If WornKeywordList[AssFlashRiskLow]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsLow_Male] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsLow_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskLow' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRisk]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOdds_Male] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOdds_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRisk' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRiskHigh]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsHigh_Male] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsHigh_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskHigh' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRiskExtreme]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsExtreme_Male] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsExtreme_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskExtreme' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRiskUltra]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsUltra_Male] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsUltra_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskUltra' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			Else
				AddTextOption("$AssText", "0%")
			EndIf
			
			If WornKeywordList[PelvicFlashRiskLow]
				If WornKeywordList[PelvicCurtain]
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsLow_Male] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT]
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsLow_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRiskLow' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRisk]
				If WornKeywordList[PelvicCurtain]
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOdds_Male] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT]
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOdds_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRisk' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRiskHigh]
				If WornKeywordList[PelvicCurtain]
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsHigh_Male] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT]
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsHigh_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRisk' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRiskExtreme]
				If WornKeywordList[PelvicCurtain]
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsExtreme_Male] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT]
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashExtreme' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRiskUltra]
				If WornKeywordList[PelvicCurtain]
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsUltra_Male] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT]
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsUltra_Male] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRiskUltra' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			Else
				AddTextOption("$PelvicText", "0%")
			EndIf
			
		Else ;Female
			
			If WornKeywordList[ChestFlashRiskLow]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsLow] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsLow] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskLow' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRisk]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOdds] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOdds] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRisk' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRiskHigh]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsHigh] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsHigh] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskHigh' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRiskExtreme]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsExtreme] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsExtreme] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskExtreme' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			ElseIf WornKeywordList[ChestFlashRiskUltra]
				If WornKeywordList[ChestCurtain]
					AddTextOption("$ChestText", FlashOdds[ChestCurtainOddsUltra] as String + "%")
				ElseIf WornKeywordList[ChestCurtainT]
					AddTextOption("$ChestText", FlashOdds[TransparentChestCurtainOddsUltra] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'ChestFlashRiskUltra' keyword without also having a Chest Curtain keyword.", Logger.Config)
					AddTextOption("$ChestText", "0%")
				EndIf
			Else
				AddTextOption("$ChestText", "0%")
			EndIf
			
			If WornKeywordList[AssFlashRiskLow]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsLow] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsLow] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskLow' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRisk]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOdds] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOdds] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRisk' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRiskHigh]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsHigh] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsHigh] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskHigh' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRiskExtreme]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsExtreme] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsExtreme] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskExtreme' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			ElseIf WornKeywordList[AssFlashRiskUltra]
				If WornKeywordList[AssCurtain]
					AddTextOption("$AssText", FlashOdds[AssCurtainOddsUltra] as String + "%")
				ElseIf WornKeywordList[AssCurtainT]
					AddTextOption("$AssText", FlashOdds[TransparentAssCurtainOddsUltra] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'AssFlashRiskUltra' keyword without also having an Ass Curtain keyword.", Logger.Config)
					AddTextOption("$AssText", "0%")
				EndIf
			Else
				AddTextOption("$AssText", "0%")
			EndIf
			
			If WornKeywordList[PelvicFlashRiskLow] 
				If WornKeywordList[PelvicCurtain] 
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsLow] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT] 
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsLow] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRiskLow' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRisk] 
				If WornKeywordList[PelvicCurtain] 
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOdds] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT] 
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOdds] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRisk' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRiskHigh] 
				If WornKeywordList[PelvicCurtain] 
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsHigh] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT] 
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsHigh] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRisk' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRiskExtreme] 
				If WornKeywordList[PelvicCurtain] 
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsExtreme] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT] 
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsExtreme] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashExtreme' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			ElseIf WornKeywordList[PelvicFlashRiskUltra]
				If WornKeywordList[PelvicCurtain]
					AddTextOption("$PelvicText", FlashOdds[PelvicCurtainOddsUltra] as String + "%")
				ElseIf WornKeywordList[PelvicCurtainT]
					AddTextOption("$PelvicText", FlashOdds[TransparentPelvicCurtainOddsUltra] as String + "%")
				Else
					AND_Logger.FastLog("<MCM> [Flashing States Page] Player has 'PelvicFlashRiskUltra' keyword without also having a Pelvic Curtain keyword.", Logger.Config)
					AddTextOption("$PelvicText", "0%")
				EndIf
			Else
				AddTextOption("$PelvicText", "0%")
			EndIf
		EndIf
		
		AddHeaderOption("$TransparentClothesRiskHeader")
		If PlayerSex == Enum_Female ;FEMALE
			
			If WornKeywordList[ArmorTopT_Low]
				AddTextOption("$TopText", FlashOdds[TransparentTopArmorOdds_Low] as String + "%")
			ElseIf WornKeywordList[ArmorTopT]
				AddTextOption("$TopText", FlashOdds[TransparentTopArmorOdds] as String + "%")
			ElseIf WornKeywordList[ArmorTopT_High]
				AddTextOption("$TopText", FlashOdds[TransparentTopArmorOdds_High] as String + "%")
			Else
				AddTextOption("$TopText", "0%")
			EndIf
			
			If WornKeywordList[ArmorBottomT_Low]
				AddTextOption("$BottomText", FlashOdds[TransparentBottomArmorOdds_Low] as String + "%")
			ElseIf WornKeywordList[ArmorBottomT]
				AddTextOption("$BottomText", FlashOdds[TransparentBottomArmorOdds] as String + "%")
			ElseIf WornKeywordList[ArmorBottomT_High]
				AddTextOption("$BottomText", FlashOdds[TransparentBottomArmorOdds_High] as String + "%")
			Else
				AddTextOption("$BottomText", "0%")
			EndIf
			
			If WornKeywordList[BraT_Low]
				AddTextOption("$BraText", FlashOdds[TransparentBraOdds_Low] as String + "%")
			ElseIf WornKeywordList[BraT]
				AddTextOption("$BraText", FlashOdds[TransparentBraOdds] as String + "%")
			ElseIf WornKeywordList[BraT_High]
				AddTextOption("$BraText", FlashOdds[TransparentBraOdds_High] as String + "%")
			Else
				AddTextOption("$BraText", "0%")
			EndIf
			
			If WornKeywordList[UnderwearT_Low]
				AddTextOption("$UnderwearText", FlashOdds[TransparentUnderwearOdds_Low] as String + "%")
			ElseIf WornKeywordList[UnderwearT]
				AddTextOption("$UnderwearText", FlashOdds[TransparentUnderwearOdds] as String + "%")
			ElseIf WornKeywordList[UnderwearT_High]
				AddTextOption("$UnderwearText", FlashOdds[TransparentUnderwearOdds_High] as String + "%")
			ElseIf WornKeywordList[ThongT_Low]
				AddTextOption("$ThongText", FlashOdds[TransparentUnderwearOdds_Low] as String + "%")
			ElseIf WornKeywordList[ThongT]
				AddTextOption("$ThongText", FlashOdds[TransparentUnderwearOdds] as String + "%")
			ElseIf WornKeywordList[ThongT_High]
				AddTextOption("$ThongText", FlashOdds[TransparentUnderwearOdds_High] as String + "%")
			ElseIf WornKeywordList[CString]
				AddTextOption("$CStringText", FlashOdds[CStringOdds] as String + "%")
			ElseIf WornKeywordList[CStringT_Low]
				AddTextOption("$CStringText", FlashOdds[TransparentCStringOdds_Low] as String + "%")
			ElseIf WornKeywordList[CStringT]
				AddTextOption("$CStringText", FlashOdds[TransparentCStringOdds] as String + "%")
			ElseIf WornKeywordList[CStringT_High]
				AddTextOption("$CStringText", FlashOdds[TransparentCStringOdds_High] as String + "%")
			Else
				AddTextOption("$UnderwearText", "0%")
			EndIf
			
			If WornKeywordList[HotpantsT_Low]
				AddTextOption("$HotpantsText", FlashOdds[TransparentHotpantsOdds_Low] as String + "%")
			ElseIf WornKeywordList[HotpantsT]
				AddTextOption("$HotpantsText", FlashOdds[TransparentHotpantsOdds] as String + "%")
			ElseIf WornKeywordList[HotpantsT_High]
				AddTextOption("$HotpantsText", FlashOdds[TransparentHotpantsOdds_High] as String + "%")
			Else
				AddTextOption("$HotpantsText", "0%")
			EndIf
			
			If WornKeywordList[ShowgirlSkirtT_Low]
				AddTextOption("$ShowgirlSkirtText", FlashOdds[TransparentShowgirlSkirtOdds_Low] as String + "")
			ElseIf WornKeywordList[ShowgirlSkirtT]
				AddTextOption("$ShowgirlSkirtText", FlashOdds[TransparentShowgirlSkirtOdds] as String + "")
			ElseIf WornKeywordList[ShowgirlSkirtT_High]
				AddTextOption("$ShowgirlSkirtText", FlashOdds[TransparentShowgirlSkirtOdds_High] as String + "")
			Else
				AddTextOption("$ShowgirlSkirtText", "0%")
			EndIf
		Else ;MALE
			
			If WornKeywordList[ArmorTopT_Low]
				AddTextOption("$TopText", FlashOdds[TransparentTopArmorOdds_Low_Male] as String + "%")
			ElseIf WornKeywordList[ArmorTopT]
				AddTextOption("$TopText", FlashOdds[TransparentTopArmorOdds_Male] as String + "%")
			ElseIf WornKeywordList[ArmorTopT_High]
				AddTextOption("$TopText", FlashOdds[TransparentTopArmorOdds_High_Male] as String + "%")
			Else
				AddTextOption("$TopText", "0%")
			EndIf
			
			If WornKeywordList[ArmorBottomT_Low]
				AddTextOption("$BottomText", FlashOdds[TransparentBottomArmorOdds_Low_Male] as String + "%")
			ElseIf WornKeywordList[ArmorBottomT]
				AddTextOption("$BottomText", FlashOdds[TransparentBottomArmorOdds_Male] as String + "%")
			ElseIf WornKeywordList[ArmorBottomT_High]
				AddTextOption("$BottomText", FlashOdds[TransparentBottomArmorOdds_High_Male] as String + "%")
			Else
				AddTextOption("$BottomText", "0%")
			EndIf
			
			If WornKeywordList[BraT_Low]
				AddTextOption("$BraText", FlashOdds[TransparentBraOdds_Low_Male] as String + "%")
			ElseIf WornKeywordList[BraT]
				AddTextOption("$BraText", FlashOdds[TransparentBraOdds_Male] as String + "%")
			ElseIf WornKeywordList[BraT_High]
				AddTextOption("$BraText", FlashOdds[TransparentBraOdds_High_Male] as String + "%")
			Else
				AddTextOption("$BraText", "0%")
			EndIf
			
			If WornKeywordList[UnderwearT_Low]
				AddTextOption("$UnderwearText", FlashOdds[TransparentUnderwearOdds_Low_Male] as String + "%")
			ElseIf WornKeywordList[UnderwearT]
				AddTextOption("$UnderwearText", FlashOdds[TransparentUnderwearOdds_Male] as String + "%")
			ElseIf WornKeywordList[UnderwearT_High]
				AddTextOption("$UnderwearText", FlashOdds[TransparentUnderwearOdds_High_Male] as String + "%")
			ElseIf WornKeywordList[ThongT_Low]
				AddTextOption("$ThongText", FlashOdds[TransparentUnderwearOdds_Low_Male] as String + "%")
			ElseIf WornKeywordList[ThongT]
				AddTextOption("$ThongText", FlashOdds[TransparentUnderwearOdds_Male] as String + "%")
			ElseIf WornKeywordList[ThongT_High]
				AddTextOption("$ThongText", FlashOdds[TransparentUnderwearOdds_High_Male] as String + "%")
			ElseIf WornKeywordList[BananaHammock]
				AddTextOption("$BananaHammockText", FlashOdds[CStringOdds] as String + "%")
			ElseIf WornKeywordList[BananaHammockT_Low]
				AddTextOption("$BananaHammockText", FlashOdds[TransparentCStringOdds_Low_Male] as String + "%")
			ElseIf WornKeywordList[BananaHammockT]
				AddTextOption("$BananaHammockText", FlashOdds[TransparentCStringOdds_Male] as String + "%")
			ElseIf WornKeywordList[BananaHammockT_High]
				AddTextOption("$BananaHammockText", FlashOdds[TransparentCStringOdds_High_Male] as String + "%")
			Else
				AddTextOption("$UnderwearText", "0%")
			EndIf
			
			If WornKeywordList[HotpantsT_Low]
				AddTextOption("$HotpantsText", FlashOdds[TransparentHotpantsOdds_Low_Male] as String + "%")
			ElseIf WornKeywordList[HotpantsT]
				AddTextOption("$HotpantsText", FlashOdds[TransparentHotpantsOdds_Male] as String + "%")
			ElseIf WornKeywordList[HotpantsT_High]
				AddTextOption("$HotpantsText", FlashOdds[TransparentHotpantsOdds_High_Male] as String + "%")
			Else
				AddTextOption("$HotpantsText", "0%")
			EndIf
			
			If WornKeywordList[HimboSkirtT_Low]
				AddTextOption("$HimboSkirtText", FlashOdds[TransparentShowgirlSkirtOdds_Low_Male] as String + "")
			ElseIf WornKeywordList[HimboSkirtT]
				AddTextOption("$HimboSkirtText", FlashOdds[TransparentShowgirlSkirtOdds] as String + "")
			ElseIf WornKeywordList[HimboSkirtT_High]
				AddTextOption("$HimboSkirtText", FlashOdds[TransparentShowgirlSkirtOdds_High_Male] as String + "")
			Else
				AddTextOption("$HimboSkirtText", "0%")
			EndIf
		EndIf
		
		SetCursorPosition(1)
		
		AddHeaderOption("$FlashRollsHeader")
		AddTextOption("$ChestCurtainRollText", FlashRolls[ChestCurtainRoll])
		AddTextOption("$AssCurtainRollText", FlashRolls[AssCurtainRoll])
		AddTextOption("$PelvicCurtainRollText", FlashRolls[PelvicCurtainRoll])
		If PlayerSex == Enum_Male ;Male
			AddTextOption("$BananaHammockRollText", FlashRolls[CStringRoll])
		Else
			AddTextOption("$CStringRollText", FlashRolls[CStringRoll])
		EndIf
		AddTextOption("$TransparentTopRollText", FlashRolls[TopTransparentRoll])
		AddTextOption("$TransparentBottomRollText", FlashRolls[BottomTransparentRoll])
		AddTextOption("$TransparentBraRollText", FlashRolls[BraTransparentRoll])
		AddTextOption("$TransparentUnderwearRollText", FlashRolls[UnderwearTransparentRoll])
		AddTextOption("$TransparentHotpantsRollText", FlashRolls[HotpantsTransparentRoll])
		If PlayerSex == Enum_Male ;Male
			AddTextOption("$TransparentHimboSkirtRollText", FlashRolls[ShowgirlTransparentRoll])
		Else
			AddTextOption("$TransparentShowgirlSkirtRollText", FlashRolls[ShowgirlTransparentRoll])
		EndIf
		
	ElseIf (page == "$CurtainKeywordsPage")
		
		If WornKeywordList[ChestCurtain]
			AddTextOption("AND_ChestCurtain", "$YesText")
		Else
			AddTextOption("AND_ChestCurtain", "$NoText")
		EndIf
		
		If WornKeywordList[ChestCurtainT]
			AddTextOption("AND_ChestCurtainT", "$YesText")
		Else
			AddTextOption("AND_ChestCurtainT", "$NoText")
		EndIf
		
		If WornKeywordList[PelvicCurtain]
			AddTextOption("AND_PelvicCurtain", "$YesText")
		Else
			AddTextOption("AND_PelvicCurtain", "$NoText")
		EndIf
		
		If WornKeywordList[PelvicCurtainT]
			AddTextOption("AND_PelvicCurtainT", "$YesText")
		Else
			AddTextOption("AND_PelvicCurtainT", "$NoText")
		EndIf
		
		If WornKeywordList[AssCurtain]
			AddTextOption("AND_AssCurtain", "$YesText")
		Else
			AddTextOption("AND_AssCurtain", "$NoText")
		EndIf
		
		If WornKeywordList[AssCurtainT]
			AddTextOption("AND_AssCurtainT", "$YesText")
		Else
			AddTextOption("AND_AssCurtainT", "$NoText")
		EndIf
		
		If WornKeywordList[Miniskirt]
			AddTextOption("AND_Miniskirt", "$YesText")
		Else
			AddTextOption("AND_Miniskirt", "$NoText")
		EndIf
		
		If WornKeywordList[MiniskirtT]
			AddTextOption("AND_MiniskirtT", "$YesText")
		Else
			AddTextOption("AND_MiniskirtT", "$NoText")
		EndIf
	
	ElseIf (page == "$ArmorAndUnderwearKeywordsPage")
	
		AddHeaderOption("$ArmorKeywordsHeader")
		
		If WornKeywordList[ArmorTop]
			AddTextOption("AND_ArmorTop", "$YesText")
		Else
			AddTextOption("AND_ArmorTop", "$NoText")
		EndIf
		
		If WornKeywordList[ArmorTopT_Low] || WornKeywordList[ArmorTopT] || WornKeywordList[ArmorTopT_High]
			AddTextOption("AND_ArmorTopT", "$YesText")
		Else
			AddTextOption("AND_ArmorTopT", "$NoText")
		EndIf
		
		If WornKeywordList[ArmorTop_NoCover]
			AddTextOption("AND_ArmorTop_NoCover", "$YesText")
		Else
			AddTextOption("AND_ArmorTop_NoCover", "$NoText")
		EndIf
		
		If WornKeywordList[ArmorBottom]
			AddTextOption("AND_ArmorBottom", "$YesText")
		Else
			AddTextOption("AND_ArmorBottom", "$NoText")
		EndIf
		
		If WornKeywordList[ArmorBottomT_Low] || WornKeywordList[ArmorBottomT] || WornKeywordList[ArmorBottomT_High]
			AddTextOption("AND_ArmorBottomT", "$YesText")
		Else
			AddTextOption("AND_ArmorBottomT", "$NoText")
		EndIf
		
		If WornKeywordList[ArmorBottom_NoCover]
			AddTextOption("AND_ArmorBottom_NoCover", "$YesText")
		Else
			AddTextOption("AND_ArmorBottom_NoCover", "$NoText")
		EndIf
		
		If WornKeywordList[Hotpants]
			AddTextOption("AND_Hotpants", "$YesText")
		Else
			AddTextOption("AND_Hotpants", "$NoText")
		EndIf
		
		If WornKeywordList[HotpantsT_Low] || WornKeywordList[HotpantsT] || WornKeywordList[HotpantsT_High]
			AddTextOption("AND_HotpantsT", "$YesText")
		Else
			AddTextOption("AND_HotpantsT", "$NoText")
		EndIf
		
		If WornKeywordList[ShowgirlSkirt] && PlayerSex == Enum_Female
			AddTextOption("AND_ShowgirlSkirt", "$YesText")
		ElseIf WornKeywordList[HimboSkirt] && PlayerSex == Enum_Male
			AddTextOption("AND_HimboSkirt", "$YesText")
		Else
			If PlayerSex == Enum_Female
				AddTextOption("AND_ShowgirlSkirt", "$NoText")
			Else
				AddTextOption("AND_HimboSkirt", "$NoText")
			EndIf
		EndIf
		
		If (WornKeywordList[ShowgirlSkirtT_Low] || WornKeywordList[ShowgirlSkirtT] || WornKeywordList[ShowgirlSkirtT_High]) && PlayerSex == Enum_Female
			AddTextOption("AND_ShowgirlSkirtT", "$YesText")
		ElseIf (WornKeywordList[HimboSkirtT_Low] || WornKeywordList[HimboSkirtT] || WornKeywordList[HimboSkirtT_High]) && PlayerSex == Enum_Male
			AddTextOption("AND_HimboSkirtT", "$YesText")
		Else
			If PlayerSex == Enum_Female
				AddTextOption("AND_ShowgirlSkirtT", "$NoText")
			Else
				AddTextOption("AND_HimboSkirtT", "$NoText")
			EndIf
		EndIf
		
		SetCursorPosition(1)
		
		AddHeaderOption("$UnderwearKeywordsHeader")
		
		If WornKeywordList[Bra]
			AddTextOption("AND_Bra", "$YesText")
		Else
			AddTextOption("AND_Bra", "$NoText")
		EndIf
		
		If WornKeywordList[BraT_Low] || WornKeywordList[BraT] || WornKeywordList[BraT_High]
			AddTextOption("AND_BraT", "$YesText")
		Else
			AddTextOption("AND_BraT", "$NoText")
		EndIf
		
		If WornKeywordList[Bra_NoCover]
			AddTextOption("AND_Bra_NoCover", "$YesText")
		Else
			AddTextOption("AND_Bra_NoCover", "$NoText")
		EndIf
		
		If WornKeywordList[CString] && PlayerSex == Enum_Female
			AddTextOption("AND_CString", "$YesText")
		ElseIf WornKeywordList[BananaHammock] && PlayerSex == Enum_Male
			AddTextOption("AND_BananaHammock", "$YesText")
		Else
			If PlayerSex == Enum_Female
				AddTextOption("AND_CString", "$NoText")
			Else
				AddTextOption("AND_BananaHammock", "$NoText")
			EndIf
		EndIf
		
		If (WornKeywordList[CStringT_Low] || WornKeywordList[CStringT] || WornKeywordList[CStringT_High]) && PlayerSex == Enum_Female
			AddTextOption("AND_CStringT", "$YesText")
		ElseIf (WornKeywordList[BananaHammockT_Low] || WornKeywordList[BananaHammockT] || WornKeywordList[BananaHammockT_High]) && PlayerSex == Enum_Male
			AddTextOption("AND_BananaHammockT", "$YesText")
		Else
			If PlayerSex == Enum_Female
				AddTextOption("AND_CStringT", "$NoText")
			Else
				AddTextOption("AND_BananaHammockT", "$NoText")
			EndIf
		EndIf
		
		If WornKeywordList[Thong]
			AddTextOption("AND_Thong", "$YesText")
		Else
			AddTextOption("AND_Thong", "$NoText")
		EndIf
		
		If WornKeywordList[ThongT_Low] || WornKeywordList[ThongT] || WornKeywordList[ThongT_High]
			AddTextOption("AND_ThongT", "$YesText")
		Else
			AddTextOption("AND_ThongT", "$NoText")
		EndIf
		
		If WornKeywordList[Thong_NoCover]
			AddTextOption("AND_Thong_NoCover", "$YesText")
		Else
			AddTextOption("AND_Thong_NoCover", "$NoText")
		EndIf
		
		If WornKeywordList[Underwear]
			AddTextOption("AND_Underwear", "$YesText")
		Else
			AddTextOption("AND_Underwear", "$NoText")
		EndIf
		
		If WornKeywordList[UnderwearT_Low] || WornKeywordList[UnderwearT] || WornKeywordList[UnderwearT_High]
			AddTextOption("AND_UnderwearT", "$YesText")
		Else
			AddTextOption("AND_UnderwearT", "$NoText")
		EndIf
		
		If WornKeywordList[Underwear_NoCover]
			AddTextOption("AND_Underwear_NoCover", "$YesText")
		Else
			AddTextOption("AND_Underwear_NoCover", "$NoText")
		EndIf

	ElseIf (page == "$GeneralKeywordsPage")
		
		If WornKeywordList[CoversAll]
			AddTextOption("AND_CoversAll", "$YesText")
		Else
			AddTextOption("AND_CoversAll", "$NoText")
		EndIf
		
		If WornKeywordList[Microskirt]
			AddTextOption("AND_Microskirt", "$YesText")
		Else
			AddTextOption("AND_Microskirt", "$NoText")
		EndIf
		
		If WornKeywordList[NipplePasties]
			AddTextOption("AND_NipplePasties", "$YesText")
		Else
			AddTextOption("AND_NipplePasties", "$NoText")
		EndIf
		
		If PlayerSex == Enum_Female
			If WornKeywordList[VaginaPasties]
				AddTextOption("AND_VaginaPasties", "$YesText")
			Else
				AddTextOption("AND_VaginaPasties", "$NoText")
			EndIf
		Else
			AddTextOption("AND_VaginaPasties", "N/A")
		EndIf
		
		If WornKeywordList[NearlyNaked]
			AddTextOption("AND_NearlyNaked", "$YesText")
		Else
			AddTextOption("AND_NearlyNaked", "$NoText")
		EndIf
		
		If WornKeywordList[EffectivelyNaked]
			AddTextOption("AND_EffectivelyNaked", "$YesText")
		Else
			AddTextOption("AND_EffectivelyNaked", "$NoText")
		EndIf
	
	ElseIf (page == "$FlashRiskKeywordsPage")
		AddHeaderOption("$ChestCurtainText")
		
		If WornKeywordList[ChestFlashRiskUltra]
			AddTextOption("AND_ChestFlashRiskUltra", "$YesText")
		Else
			AddTextOption("AND_ChestFlashRiskUltra", "$NoText")
		EndIf
		
		If WornKeywordList[ChestFlashRiskExtreme]
			AddTextOption("AND_ChestFlashRiskExtreme", "$YesText")
		Else
			AddTextOption("AND_ChestFlashRiskExtreme", "$NoText")
		EndIf
		
		If WornKeywordList[ChestFlashRiskHigh]
			AddTextOption("AND_ChestFlashRiskHigh", "$YesText")
		Else
			AddTextOption("AND_ChestFlashRiskHigh", "$NoText")
		EndIf
		
		If WornKeywordList[ChestFlashRisk]
			AddTextOption("AND_ChestFlashRisk", "$YesText")
		Else
			AddTextOption("AND_ChestFlashRisk", "$NoText")
		EndIf
		
		If WornKeywordList[ChestFlashRiskLow]
			AddTextOption("AND_ChestFlashRiskLow", "$YesText")
		Else
			AddTextOption("AND_ChestFlashRiskLow", "$NoText")
		EndIf
		
		AddHeaderOption("$PelvicCurtainText")
		
		If WornKeywordList[PelvicFlashRiskUltra]
			AddTextOption("AND_PelvicFlashRiskUltra", "$YesText")
		Else
			AddTextOption("AND_PelvicFlashRiskUltra", "$NoText")
		EndIf
		
		If WornKeywordList[PelvicFlashRiskExtreme]
			AddTextOption("AND_PelvicFlashRiskExtreme", "$YesText")
		Else
			AddTextOption("AND_PelvicFlashRiskExtreme", "$NoText")
		EndIf
		
		If WornKeywordList[PelvicFlashRiskHigh]
			AddTextOption("AND_PelvicFlashRiskHigh", "$YesText")
		Else
			AddTextOption("AND_PelvicFlashRiskHigh", "$NoText")
		EndIf
		
		If WornKeywordList[PelvicFlashRisk]
			AddTextOption("AND_PelvicFlashRisk", "$YesText")
		Else
			AddTextOption("AND_PelvicFlashRisk", "$NoText")
		EndIf
		
		If WornKeywordList[PelvicFlashRiskLow]
			AddTextOption("AND_PelvicFlashRiskLow", "$YesText")
		Else
			AddTextOption("AND_PelvicFlashRiskLow", "$NoText")
		EndIf
		
		SetCursorPosition(1)
		
		AddHeaderOption("$AssCurtainText")
		
		If WornKeywordList[AssFlashRiskUltra]
			AddTextOption("AND_AssFlashRiskUltra", "$YesText")
		Else
			AddTextOption("AND_AssFlashRiskUltra", "$NoText")
		EndIf
		
		If WornKeywordList[AssFlashRiskExtreme]
			AddTextOption("AND_AssFlashRiskExtreme", "$YesText")
		Else
			AddTextOption("AND_AssFlashRiskExtreme", "$NoText")
		EndIf
		
		If WornKeywordList[AssFlashRiskHigh]
			AddTextOption("AND_AssFlashRiskHigh", "$YesText")
		Else
			AddTextOption("AND_AssFlashRiskHigh", "$NoText")
		EndIf
		
		If WornKeywordList[AssFlashRisk]
			AddTextOption("AND_AssFlashRisk", "$YesText")
		Else
			AddTextOption("AND_AssFlashRisk", "$NoText")
		EndIf
		
		If WornKeywordList[AssFlashRiskLow]
			AddTextOption("AND_AssFlashRiskLow", "$YesText")
		Else
			AddTextOption("AND_AssFlashRiskLow", "$NoText")
		EndIf
	ElseIf (page == "$FemaleFlashChancesPage")
		AddHeaderOption("$ChestCurtainText")
		AddSliderOptionST("AND_ChestCurtainLowOdds", "$ChestCurtainLowText", FlashOdds[ChestCurtainOddsLow], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainOdds", "$ChestCurtainNormalText", FlashOdds[ChestCurtainOdds], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainHighOdds", "$ChestCurtainHighText", FlashOdds[ChestCurtainOddsHigh], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainExtremeOdds", "$ChestCurtainExtremeText", FlashOdds[ChestCurtainOddsExtreme], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainUltraOdds", "$ChestCurtainUltraText", FlashOdds[ChestCurtainOddsUltra], "{0}%", 0)
		
		AddHeaderOption("$PelvicCurtainText")
		AddSliderOptionST("AND_PelvicCurtainLowOdds", "$PelvicCurtainLowText", FlashOdds[PelvicCurtainOddsLow], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainOdds", "$PelvicCurtainNormalText", FlashOdds[PelvicCurtainOdds], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainHighOdds", "$PelvicCurtainHighText", FlashOdds[PelvicCurtainOddsHigh], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainExtremeOdds", "$PelvicCurtainExtremeText", FlashOdds[PelvicCurtainOddsExtreme], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainUltraOdds", "$PelvicCurtainUltraText", FlashOdds[PelvicCurtainOddsUltra], "{0}%", 0)
		
		AddHeaderOption("$AssCurtainText")
		AddSliderOptionST("AND_AssCurtainLowOdds", "$AssCurtainLowText", FlashOdds[AssCurtainOddsLow], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainOdds", "$AssCurtainNormalText", FlashOdds[AssCurtainOdds], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainHighOdds", "$AssCurtainHighText", FlashOdds[AssCurtainOddsHigh], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainExtremeOdds", "$AssCurtainExtremeText", FlashOdds[AssCurtainOddsExtreme], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainUltraOdds", "$AssCurtainUltraText", FlashOdds[AssCurtainOddsUltra], "{0}%", 0)
		
		AddHeaderOption("$CStringText")
		AddSliderOptionST("AND_CStringOdds", "$CStringText", FlashOdds[CStringOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentCStringOddsLow", "$TransparentCStringLowText", FlashOdds[TransparentCStringOdds_Low], "{0}%", 0)
		AddSliderOptionST("AND_TransparentCStringOdds", "$TransparentCStringNormalText", FlashOdds[TransparentCStringOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentCStringOddsHigh", "$TransparentCStringHighText", FlashOdds[TransparentCStringOdds_High], "{0}%", 0)
		
		AddHeaderOption("$TransparentArmorBottomHeader")
		AddSliderOptionST("AND_TransparentBottomArmorOddsLow", "$TransparentArmorBottomLowText", FlashOdds[TransparentBottomArmorOdds_Low], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBottomArmorOdds", "$TransparentArmorBottomNormalText", FlashOdds[TransparentBottomArmorOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBottomArmorOddsHigh", "$TransparentArmorBottomHighText", FlashOdds[TransparentBottomArmorOdds_High], "{0}%", 0)
		
		AddHeaderOption("$TransparentUnderwearHeader")
		AddSliderOptionST("AND_TransparentUnderwearOddsLow", "$TransparentUnderwearLowText", FlashOdds[TransparentUnderwearOdds_Low], "{0}%", 0)
		AddSliderOptionST("AND_TransparentUnderwearOdds", "$TransparentUnderwearNormalText", FlashOdds[TransparentUnderwearOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentUnderwearOddsHigh", "$TransparentUnderwearHighText", FlashOdds[TransparentUnderwearOdds_High], "{0}%", 0)
		
		AddHeaderOption("$TransparentShowgirlHeader")
		AddSliderOptionST("AND_TransparentShowgirlSkirtOddsLow", "$TransparentShowgirlSkirtLowText", FlashOdds[TransparentShowgirlSkirtOdds_Low], "{0}%", 0)
		AddSliderOptionST("AND_TransparentShowgirlSkirtOdds", "$TransparentShowgirlSkirtNormalText", FlashOdds[TransparentShowgirlSkirtOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentShowgirlSkirtOddsHigh", "$TransparentShowgirlSkirtHighText", FlashOdds[TransparentShowgirlSkirtOdds_High], "{0}%", 0)
		
		SetCursorPosition(1)
		
		AddHeaderOption("$TransparentChestCurtainHeader")
		AddSliderOptionST("AND_TransparentChestCurtainLowOdds", "$TransparentChestCurtainLowText", FlashOdds[TransparentChestCurtainOddsLow], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainOdds", "$TransparentChestCurtainNormalText", FlashOdds[TransparentChestCurtainOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainHighOdds", "$TransparentChestCurtainHighText", FlashOdds[TransparentChestCurtainOddsHigh], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainExtremeOdds", "$TransparentChestCurtainExtremeText", FlashOdds[TransparentChestCurtainOddsExtreme], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainUltraOdds", "$TransparentChestCurtainUltraText", FlashOdds[TransparentChestCurtainOddsUltra], "{0}%", 0)
		
		AddHeaderOption("$TransparentPelvicCurtainHeader")
		AddSliderOptionST("AND_TransparentPelvicCurtainLowOdds", "$TransparentPelvicCurtainLowText", FlashOdds[TransparentPelvicCurtainOddsLow], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainOdds", "$TransparentPelvicCurtainNormalText", FlashOdds[TransparentPelvicCurtainOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainHighOdds", "$TransparentPelvicCurtainHighText", FlashOdds[TransparentPelvicCurtainOddsHigh], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainExtremeOdds", "$TransparentPelvicCurtainExtremeText", FlashOdds[TransparentPelvicCurtainOddsExtreme], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainUltraOdds", "$TransparentPelvicCurtainUltraText", FlashOdds[TransparentPelvicCurtainOddsUltra], "{0}%", 0)
		
		AddHeaderOption("$TransparentAssCurtainHeader")
		AddSliderOptionST("AND_TransparentAssCurtainLowOdds", "$TransparentAssCurtainLowText", FlashOdds[TransparentAssCurtainOddsLow], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainOdds", "$TransparentAssCurtainNormalText", FlashOdds[TransparentAssCurtainOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainHighOdds", "$TransparentAssCurtainHighText", FlashOdds[TransparentAssCurtainOddsHigh], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainExtremeOdds", "$TransparentAssCurtainExtremeText", FlashOdds[TransparentAssCurtainOddsExtreme], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainUltraOdds", "$TransparentAssCurtainUltraText", FlashOdds[TransparentAssCurtainOddsUltra], "{0}%", 0)
		
		AddHeaderOption("$TransparentArmorTopHeader")
		AddSliderOptionST("AND_TransparentTopArmorOddsLow", "$TransparentArmorTopLowText", FlashOdds[TransparentTopArmorOdds_Low], "{0}%", 0)
		AddSliderOptionST("AND_TransparentTopArmorOdds", "$TransparentArmorTopNormalText", FlashOdds[TransparentTopArmorOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentTopArmorOddsHigh", "$TransparentArmorTopHighText", FlashOdds[TransparentTopArmorOdds_High], "{0}%", 0)
		AddEmptyOption()
		
		AddHeaderOption("$TransparentBraHeader")
		AddSliderOptionST("AND_TransparentBraOddsLow", "$TransparentBraLowText", FlashOdds[TransparentBraOdds_Low], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBraOdds", "$TransparentBraNormalText", FlashOdds[TransparentBraOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBraOddsHigh", "$TransparentBraHighText", FlashOdds[TransparentBraOdds_High], "{0}%", 0)
		
		AddHeaderOption("$TransparentHotpantsHeader")
		AddSliderOptionST("AND_TransparentHotpantsOddsLow", "$TransparentHotpantsLowText", FlashOdds[TransparentHotpantsOdds_Low], "{0}%", 0)
		AddSliderOptionST("AND_TransparentHotpantsOdds", "$TransparentHotpantsNormalText", FlashOdds[TransparentHotpantsOdds], "{0}%", 0)
		AddSliderOptionST("AND_TransparentHotpantsOddsHigh", "$TransparentHotpantsHighText", FlashOdds[TransparentHotpantsOdds_High], "{0}%", 0)
	
	ElseIf (page == "$MaleFlashChancesPage")
		AddHeaderOption("$ChestCurtainText")
		AddSliderOptionST("AND_ChestCurtainLowOddsMale", "$ChestCurtainLowText", FlashOdds[ChestCurtainOddsLow_Male], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainOddsMale", "$ChestCurtainNormalText", FlashOdds[ChestCurtainOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainHighOddsMale", "$ChestCurtainHighText", FlashOdds[ChestCurtainOddsHigh_Male], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainExtremeOddsMale", "$ChestCurtainExtremeText", FlashOdds[ChestCurtainOddsExtreme_Male], "{0}%", 0)
		AddSliderOptionST("AND_ChestCurtainUltraOddsMale", "$ChestCurtainUltraText", FlashOdds[ChestCurtainOddsUltra_Male], "{0}%", 0)
		
		AddHeaderOption("$PelvicCurtainText")
		AddSliderOptionST("AND_PelvicCurtainLowOddsMale", "$PelvicCurtainLowText", FlashOdds[PelvicCurtainOddsLow_Male], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainOddsMale", "$PelvicCurtainNormalText", FlashOdds[PelvicCurtainOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainHighOddsMale", "$PelvicCurtainHighText", FlashOdds[PelvicCurtainOddsHigh_Male], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainExtremeOddsMale", "$PelvicCurtainExtremeText", FlashOdds[PelvicCurtainOddsExtreme_Male], "{0}%", 0)
		AddSliderOptionST("AND_PelvicCurtainUltraOddsMale", "$PelvicCurtainUltraText", FlashOdds[PelvicCurtainOddsUltra_Male], "{0}%", 0)
		
		AddHeaderOption("$AssCurtainText")
		AddSliderOptionST("AND_AssCurtainLowOddsMale", "$AssCurtainLowText", FlashOdds[AssCurtainOddsLow_Male], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainOddsMale", "$AssCurtainNormalText", FlashOdds[AssCurtainOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainHighOddsMale", "$AssCurtainHighText", FlashOdds[AssCurtainOddsHigh_Male], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainExtremeOddsMale", "$AssCurtainExtremeText", FlashOdds[AssCurtainOddsExtreme_Male], "{0}%", 0)
		AddSliderOptionST("AND_AssCurtainUltraOddsMale", "$AssCurtainUltraText", FlashOdds[AssCurtainOddsUltra_Male], "{0}%", 0)
		
		AddHeaderOption("$BananaHammockText")
		AddSliderOptionST("AND_CStringOddsMale", "$BananaHammockText", FlashOdds[CStringOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentCStringOddsLowMale", "$TransparentBananaHammockLowText", FlashOdds[TransparentCStringOdds_Low_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentCStringOddsMale", "$TransparentBananaHammockNormalText", FlashOdds[TransparentCStringOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentCStringOddsHighMale", "$TransparentBananaHammockHighText", FlashOdds[TransparentCStringOdds_High_Male], "{0}%", 0)
		
		AddHeaderOption("$TransparentArmorBottomHeader")
		AddSliderOptionST("AND_TransparentBottomArmorOddsLowMale", "$TransparentArmorBottomLowText", FlashOdds[TransparentBottomArmorOdds_Low_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBottomArmorOddsMale", "$TransparentArmorBottomNormalText", FlashOdds[TransparentBottomArmorOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBottomArmorOddsHighMale", "$TransparentArmorBottomHighText", FlashOdds[TransparentBottomArmorOdds_High_Male], "{0}%", 0)
		
		AddHeaderOption("$TransparentUnderwearHeader")
		AddSliderOptionST("AND_TransparentUnderwearOddsLowMale", "$TransparentUnderwearLowText", FlashOdds[TransparentUnderwearOdds_Low_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentUnderwearOddsMale", "$TransparentUnderwearNormalText", FlashOdds[TransparentUnderwearOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentUnderwearOddsHighMale", "$TransparentUnderwearHighText", FlashOdds[TransparentUnderwearOdds_High_Male], "{0}%", 0)
		
		AddHeaderOption("$TransparentHimboHeader")
		AddSliderOptionST("AND_TransparentShowgirlSkirtOddsLowMale", "$TransparentHimboSkirtLowText", FlashOdds[TransparentShowgirlSkirtOdds_Low_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentShowgirlSkirtOddsMale", "$TransparentHimboSkirtNormalText", FlashOdds[TransparentShowgirlSkirtOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentShowgirlSkirtOddsHighMale", "$TransparentHimboSkirtHighText", FlashOdds[TransparentShowgirlSkirtOdds_High_Male], "{0}%", 0)
		
		SetCursorPosition(1)
		
		AddHeaderOption("$TransparentChestCurtainHeader")
		AddSliderOptionST("AND_TransparentChestCurtainLowOddsMale", "$TransparentChestCurtainLowText", FlashOdds[TransparentChestCurtainOddsLow_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainOddsMale", "$TransparentChestCurtainNormalText", FlashOdds[TransparentChestCurtainOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainHighOddsMale", "$TransparentChestCurtainHighText", FlashOdds[TransparentChestCurtainOddsHigh_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainExtremeOddsMale", "$TransparentChestCurtainExtremeText", FlashOdds[TransparentChestCurtainOddsExtreme_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentChestCurtainUltraOddsMale", "$TransparentChestCurtainUltraText", FlashOdds[TransparentChestCurtainOddsUltra_Male], "{0}%", 0)
		
		AddHeaderOption("$TransparentPelvicCurtainHeader")
		AddSliderOptionST("AND_TransparentPelvicCurtainLowOddsMale", "$TransparentPelvicCurtainLowText", FlashOdds[TransparentPelvicCurtainOddsLow_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainOddsMale", "$TransparentPelvicCurtainNormalText", FlashOdds[TransparentPelvicCurtainOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainHighOddsMale", "$TransparentPelvicCurtainHighText", FlashOdds[TransparentPelvicCurtainOddsHigh_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainExtremeOddsMale", "$TransparentPelvicCurtainExtremeText", FlashOdds[TransparentPelvicCurtainOddsExtreme_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentPelvicCurtainUltraOddsMale", "$TransparentPelvicCurtainUltraText", FlashOdds[TransparentPelvicCurtainOddsUltra_Male], "{0}%", 0)
		
		AddHeaderOption("$TransparentAssCurtainHeader")
		AddSliderOptionST("AND_TransparentAssCurtainLowOddsMale", "$TransparentAssCurtainLowText", FlashOdds[TransparentAssCurtainOddsLow_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainOddsMale", "$TransparentAssCurtainNormalText", FlashOdds[TransparentAssCurtainOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainHighOddsMale", "$TransparentAssCurtainHighText", FlashOdds[TransparentAssCurtainOddsHigh_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainExtremeOddsMale", "$TransparentAssCurtainExtremeText", FlashOdds[TransparentAssCurtainOddsExtreme_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentAssCurtainUltraOddsMale", "$TransparentAssCurtainUltraText", FlashOdds[TransparentAssCurtainOddsUltra_Male], "{0}%", 0)
		
		AddHeaderOption("$TransparentArmorTopHeader")
		AddSliderOptionST("AND_TransparentTopArmorOddsLowMale", "$TransparentArmorTopLowText", FlashOdds[TransparentTopArmorOdds_Low_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentTopArmorOddsMale", "$TransparentArmorTopNormalText", FlashOdds[TransparentTopArmorOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentTopArmorOddsHighMale", "$TransparentArmorTopHighText", FlashOdds[TransparentTopArmorOdds_High_Male], "{0}%", 0)
		AddEmptyOption()
		
		AddHeaderOption("$TransparentBraHeader")
		AddSliderOptionST("AND_TransparentBraOddsLowMale", "$TransparentBraLowText", FlashOdds[TransparentBraOdds_Low_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBraOddsMale", "$TransparentBraNormalText", FlashOdds[TransparentBraOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentBraOddsHighMale", "$TransparentBraHighText", FlashOdds[TransparentBraOdds_High_Male], "{0}%", 0)
		
		AddHeaderOption("$TransparentHotpantsHeader")
		AddSliderOptionST("AND_TransparentHotpantsOddsLowMale", "$TransparentHotpantsLowText", FlashOdds[TransparentHotpantsOdds_Low_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentHotpantsOddsMale", "$TransparentHotpantsNormalText", FlashOdds[TransparentHotpantsOdds_Male], "{0}%", 0)
		AddSliderOptionST("AND_TransparentHotpantsOddsHighMale", "$TransparentHotpantsHighText", FlashOdds[TransparentHotpantsOdds_High_Male], "{0}%", 0)
		
	ElseIf (page == "$NakedCommentsPage")
		AddToggleOptionST("AND_DisableNakedCommentsState", "$DisableNakedCommentsText", ConfigBoolOptions[DisableNakedComments], 0)
		AddEmptyOption()
		AddSliderOptionST("AND_NudeFactionCommentChanceState", "$NudeFactionCommentChanceText", ConfigIntOptions[NudeFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		AddSliderOptionST("AND_ToplessFactionCommentChanceState", "$ToplessFactionCommentChanceText", ConfigIntOptions[ToplessFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		AddSliderOptionST("AND_BottomlessFactionCommentChanceState", "$BottomlessFactionCommentChanceText", ConfigIntOptions[BottomlessFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		AddSliderOptionST("AND_ChestFactionCommentChanceState", "$ChestFactionCommentChanceText", ConfigIntOptions[ChestFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		AddSliderOptionST("AND_GenitalsFactionCommentChanceState", "$GenitalsFactionCommentChanceText", ConfigIntOptions[GenitalsFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		AddSliderOptionST("AND_AssFactionCommentChanceState", "$AssFactionCommentChanceText", ConfigIntOptions[AssFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		AddSliderOptionST("AND_BraFactionCommentChanceState", "$BraFactionCommentChanceText", ConfigIntOptions[BraFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		AddSliderOptionST("AND_UnderwearFactionCommentChanceState", "$UnderwearFactionCommentChanceText", ConfigIntOptions[UnderwearFactionCommentChance], "{0}%", DisabledIf(ConfigBoolOptions[DisableNakedComments] == True))
		
		SetCursorPosition(1)
		AddTextOptionST("AND_NakedCommentChanceState", "$CurrentNakedCommentChanceText", AND_Core.NakedCommentChance(True) as String + "%", 0)
	
	ElseIf (page == "$DynamicModestyPage")
		If Main.DFFMA_Found == True || Main.DynamicModestyEnabledByOtherMod == True
			
			AddHeaderOption("$ModestySettingsHeader")
			DynamicModestyToggles[0] = AddToggleOption("$EnableModesty", ConfigBoolOptions[DynamicModestyEnabled], DisabledIf(HardcoreLockdown == True))
			DynamicModestyToggles[1] = AddToggleOption("$StrictRules", ConfigBoolOptions[PlayerStrictRules], DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			DynamicModestyToggles[2] = AddToggleOption("$ModestyCorruptionText", ConfigBoolOptions[AllowPlayerCorruption], DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			DynamicModestyToggles[3] = AddToggleOption("$PermanentShamelessText", ConfigBoolOptions[AllowPlayerShameless], DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			DynamicModestyToggles[4] = AddToggleOption("$HardcoreMode", ConfigBoolOptions[HardcoreModeEnabled], DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			
			AddHeaderOption("$ResetPlayerModestyHeader")
			DynamicModestyToggles[5] = AddToggleOption("$ResetModestyText", ResetModesty, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			
			SetCursorPosition(1)
			
			AddHeaderOption("$GeneralPlayerSettingsHeader")
			DynamicModestyToggles[6] = AddToggleOption("$RandomizePlayerText", RandomizePlayer, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			AddSliderOptionST("AND_ModestyUpgradeTimeState", "$ImmodestyTime", ConfigIntOptions[ImmodestyTimeNeeded], "{0}", DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			AddSliderOptionST("AND_ModestyArousalThresholdState", "$ArousalCutoff", ModestyArousalThreshold.GetValue(), "{0}", DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			AddMenuOptionST("AND_PlayerConfidence_State", "$PlayerConfidenceText", PlayerConfidence, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
			DynamicModestyToggles[7] = AddToggleOption("$ModestyMonologueText", ModestyMonologue, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False))
			DynamicModestyToggles[8] = AddToggleOption("$ModestyMessageboxText", ModestyMessagebox, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False))
			DynamicModestyMenus[0] = AddMenuOption("$ShyWhenSeen", ShySex, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True))
		Else
			AddTextOption("$ModestyDisabled", None)
		EndIf
	ElseIf (page == "$StrictModestyPage")
		If Main.DFFMA_Found == True || Main.DynamicModestyEnabledByOtherMod == True
			Int ModestyRank = PlayerFactionRanks[ModestyFaction]
			
			AddHeaderOption("$StrictModestySettingsHeader")
			AddSliderOptionST("AND_MinimumRankState", "$MinimumRank", ConfigIntOptions[MinimumStrictRank], "{0}", DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == False))
			
			StrictModestyToggles[0] = AddToggleOption("$JumpRank1", Rank1Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == False || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			StrictModestyToggles[1] = AddToggleOption("$JumpRank2", Rank2Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == False || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			StrictModestyToggles[2] = AddToggleOption("$JumpRank3", Rank3Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == False || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			StrictModestyToggles[3] = AddToggleOption("$JumpRank4", Rank4Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == False || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			StrictModestyToggles[4] = AddToggleOption("$JumpRank5", Rank5Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == False || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			StrictModestyToggles[5] = AddToggleOption("$JumpRank6", Rank6Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == False || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			
			SetCursorPosition(1)
			
			AddHeaderOption("$CurrentModestyHeader")
			AddTextOption("$ModestyRank", ModestyRank as String)
			AddTextOption("$ModestyTitle", ModestyManager.ModestyTitle[ModestyRank])
			
			AddHeaderOption("$ModestyTimer")
			If PlayerFactionRanks[ModestyFaction] <= 0
				AddTextOption("$Modest", StrictModestyTimers[0])
			ElseIf PlayerFactionRanks[ModestyFaction] == 1
				AddTextOption("$Reasonable", StrictModestyTimers[1])
			ElseIf PlayerFactionRanks[ModestyFaction] == 2
				AddTextOption("$Relaxed", StrictModestyTimers[2])
			ElseIf PlayerFactionRanks[ModestyFaction] == 3
				AddTextOption("$Comfortable", StrictModestyTimers[3])
			ElseIf PlayerFactionRanks[ModestyFaction] == 4
				AddTextOption("$Tease", StrictModestyTimers[4])
			ElseIf PlayerFactionRanks[ModestyFaction] == 5
				AddTextOption("$Brazen", StrictModestyTimers[5])
			ElseIf PlayerFactionRanks[ModestyFaction] >= 6
				AddTextOption("$Shameless", StrictModestyTimers[6])
			EndIf
		Else
			AddTextOption("$ModestyDisabled", None)
		EndIf
	ElseIf (page == "$SimpleModestyPage")
		If Main.DFFMA_Found == True || Main.DynamicModestyEnabledByOtherMod == True
		
			Int TopModestyRank = PlayerFactionRanks[TopModestyFaction]
			Int BottomModestyRank = PlayerFactionRanks[BottomModestyFaction]
			
			AddHeaderOption("$TopModestyHeader")
			AddTextOption("$TopModestyRank", TopModestyRank as String)
			AddTextOption("$TopModestyTitle", ModestyManager.TopModestyTitle[TopModestyRank])
			AddHeaderOption("$TopModestyTimer")
			If TopModestyRank <= 0
				AddTextOption("$Shy", SimpleModestyTimers[0])
			ElseIf TopModestyRank == 1
				AddTextOption("$Comfortable", SimpleModestyTimers[1])
			ElseIf TopModestyRank == 2
				AddTextOption("$Bold", SimpleModestyTimers[2])
			ElseIf TopModestyRank >= 3
				AddTextOption("$Shameless", SimpleModestyTimers[3])
			EndIf
			
			AddHeaderOption("$TopModestySettingsHeader")
			SimpleModestySliders[0] = AddSliderOption("$MinimumTopModestyRankText", ConfigIntOptions[MinimumTopRank], "{0}", DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True))
			
			SimpleModestyToggles[0] = AddToggleOption("$JumpTopRank1", TopRank1Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			SimpleModestyToggles[1] = AddToggleOption("$JumpTopRank2", TopRank2Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			SimpleModestyToggles[2] = AddToggleOption("$JumpTopRank3", TopRank3Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			
			SetCursorPosition(1)
			
			AddHeaderOption("$BottomModestyHeader")
			AddTextOption("$BottomModestyRank", BottomModestyRank as String)
			AddTextOption("$BottomModestyTitle", ModestyManager.BottomModestyTitle[BottomModestyRank])
			AddHeaderOption("$BottomModestyTimer")
			If BottomModestyRank <= 0
				AddTextOption("$Shy", SimpleModestyTimers[4])
			ElseIf BottomModestyRank == 1
				AddTextOption("$Comfortable", SimpleModestyTimers[5])
			ElseIf BottomModestyRank == 2
				AddTextOption("$Bold", SimpleModestyTimers[6])
			ElseIf BottomModestyRank >= 3
				AddTextOption("$Shameless", SimpleModestyTimers[7])
			EndIf
			
			AddHeaderOption("$BottomModestySettingsHeader")
			SimpleModestySliders[1] = AddSliderOption("$MinimumBottomModestyRankText", ConfigIntOptions[MinimumBottomRank], "{0}", DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True))
			
			SimpleModestyToggles[3] = AddToggleOption("$JumpBottomRank1", BottomRank1Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			SimpleModestyToggles[4] = AddToggleOption("$JumpBottomRank2", BottomRank2Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
			SimpleModestyToggles[5] = AddToggleOption("$JumpBottomRank3", BottomRank3Jump, DisabledIf(ConfigBoolOptions[DynamicModestyEnabled] == False || HardcoreLockdown == True || ConfigBoolOptions[PlayerStrictRules] == True || ConfigBoolOptions[PlayerModestyUpgradeBlocked] == True))
		Else
			AddTextOption("$ModestyDisabled", None)
		EndIf
	ElseIf (page == "$NPCModestyPage")
		If (Main.DFFMA_Found == False && Main.DynamicModestyEnabledByOtherMod == False) || ConfigBoolOptions[DynamicModestyEnabled] == False
			AddTextOption("$ModestyDisabled", None)
		Else
			AddHeaderOption("$AllNPCHeader")
			
			NPCModestyToggles[0] = AddToggleOption("$NPCStrictRulesByDefaultText", ConfigBoolOptions[NPCStrictRulesByDefault], 0) 
			NPCModestyToggles[1] = AddToggleOption("$NPCShamelessByDefaultText", ConfigBoolOptions[NPCShamelessByDefault], 0) 
			NPCModestyToggles[2] = AddToggleOption("$NPCCorruptionByDeaultText", ConfigBoolOptions[NPCCorruptionByDeault], 0)
			
			NPCModestyMenus[0] = AddMenuOption("$NPCShyWhenSeen", NPCShySex, 0)
			NPCModestySliders[0] = AddSliderOption("$NPCArousalCutoff", NPCModestyArousalThreshold.GetValue(), "{0}", 0)
			
			NPCModestyToggles[3] = AddToggleOption("$ResetAllNPC", ResetAllNPCs, DisabledIf(RegisteredFemaleNames.Length < 1 || RegisteredFemaleActors.Length < 1 || DeleteAllNPCs == True))
			NPCModestyToggles[4] = AddToggleOption("$ResetAllNPCConfirm", ConfirmSelection, DisabledIf(ResetAllNPCs == False || DeleteAllNPCs == True))
			
			NPCModestyToggles[5] = AddToggleOption("$DeleteAllNPC", DeleteAllNPCs, DisabledIf(RegisteredFemaleNames.Length < 1 || RegisteredFemaleActors.Length < 1 || ResetAllNPCs == True))
			NPCModestyToggles[6] = AddToggleOption("$DeleteAllNPCConfirm", ConfirmSelection, DisabledIf(DeleteAllNPCs == False || ResetAllNPCs == True))
			
			SetCursorPosition(1)
			
			AddHeaderOption("$TrackedFemalesHeader")
			NPCModestyMenus[1] = AddMenuOption("$SelectedFemaleText", SelectedFemale, 0)
			AddTextOption("$FemaleFormIDText", GetFemaleActorFormID(SelectedFemaleActor))
			NPCModestySliders[7] = AddMenuOption("$RegisteredFemalesPage", CurrentRegisteredFemalePage, DisabledIf(MaxRegisteredFemalePages < 2))
			
			NPCModestyToggles[7] = AddToggleOption("$PersistentFemale", MakeFemalePermanent, DisabledIf(SelectedFemale == "---" || SelectedFemale == "" || DeleteFemale == True || ResetFemaleModesty == True || PermanentFemaleNames.Find(SelectedFemale) >= 0))
			NPCModestyToggles[8] = AddToggleOption("$PersistentFemaleConfirm", ConfirmSelection, DisabledIf(MakeFemalePermanent == False))
			
			NPCModestyToggles[9] = AddToggleOption("$DeleteFemale", DeleteFemale, DisabledIf(SelectedFemale == "---" || SelectedFemale == "" || ResetFemaleModesty == True || MakeFemalePermanent == True))
			NPCModestyToggles[10] = AddToggleOption("$DeleteFemaleConfirm", ConfirmSelection, DisabledIf(DeleteFemale == False))
		
			NPCModestyToggles[11] = AddToggleOption("$ResetFemale", ResetFemaleModesty, DisabledIf(SelectedFemale == "---" || SelectedFemale == "" || DeleteFemale == True || MakeFemalePermanent == True))
			NPCModestyToggles[12] = AddToggleOption("$ResetFemaleConfirm", ConfirmSelection, DisabledIf(ResetFemaleModesty == False))
			
			NPCModestySliders[1] = AddSliderOption("$NPCStrictRank", ThisNPCStrictRank, "{0}", DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestySliders[2] = AddSliderOption("$NPCMinStrictRank", ThisNPCMinimumStrictRank, "{0}", DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestySliders[3] = AddSliderOption("$NPCTopRank", ThisNPCTopRank, "{0}", DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestySliders[4] = AddSliderOption("$NPCMinTopRank", ThisNPCMinimumTopRank, "{0}", DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestySliders[5] = AddSliderOption("$NPCBottomRank", ThisNPCBottomRank, "{0}", DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestySliders[6] = AddSliderOption("$NPCMinBottomRank", ThisNPCMinimumBottomRank, "{0}", DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestyToggles[13] = AddToggleOption("$ThisNPCPermanentShamelessText", ThisNPCShameless, DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestyToggles[14] = AddToggleOption("$NPCIsCorrupted", ThisNPCCorrupt, DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestyToggles[15] = AddToggleOption("$NPCHasStrictRules", ThisNPCStrictRules, DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestyMenus[2] = AddMenuOption("$ShyWhenSeen", ThisNPCShySex, DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestyToggles[16] = AddToggleOption("$ApplyRankTweak", ApplyTweak, DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestyToggles[17] = AddToggleOption("$ApplyRankTweakAsDefault", ApplyAsDefault, DisabledIf(SelectedFemale == "---" || SelectedFemale == ""))
			NPCModestyToggles[18] = AddToggleOption("$ApplyRankTweakConfirm", ConfirmSelection, DisabledIf(ApplyTweak == False))
			
			AddHeaderOption("$PersistentFemaleHeader")
			NPCModestyMenus[3] = AddMenuOption("$SelectedFemaleText", SelectedPermFemale, 0)
			NPCModestySliders[8] = AddMenuOption("$PermanentFemalesPage", CurrentPermanentFemalePage, DisabledIf(MaxPermanentFemalePages < 2))
			NPCModestyToggles[19] = AddToggleOption("$RemovePersistence", DeletePermFemale, DisabledIf(SelectedPermFemale == "---" || SelectedPermFemale == ""))
			NPCModestyToggles[20] = AddToggleOption("$RemovePersistenceConfirm", ConfirmSelection, DisabledIf(DeletePermFemale == False || SelectedPermFemale == "---" || SelectedPermFemale == ""))
		EndIf
	ElseIf (page == "$FlashKeys")
		AddHeaderOption("$FlashKeysHeader")
		FlashKeyMaps[0] = AddKeyMapOption("$FlashChestCurtainText", FlashKey[0], OPTION_FLAG_WITH_UNMAP)
		FlashKeyMaps[1] = AddKeyMapOption("$FlashPelvicCurtainText", FlashKey[1], OPTION_FLAG_WITH_UNMAP)
		FlashKeyMaps[2] = AddKeyMapOption("$FlashAssCurtainText", FlashKey[2], OPTION_FLAG_WITH_UNMAP)
		
		AddEmptyOption()
		
		FlashKeyToggles[0] = AddToggleOption("$ResetFlashKeybindsText", ConfirmSelection, 0)
		FlashKeyToggles[1] = AddToggleOption("$ClearFlashKeybindsText", ConfirmSelection, 0)
		SetCursorPosition(1)
		
		AddHeaderOption("$FixKeysHeader")
		FlashKeyMaps[3] = AddKeyMapOption("$FixChestCurtainText", FlashKey[3], OPTION_FLAG_WITH_UNMAP)
		FlashKeyMaps[4] = AddKeyMapOption("$FixPelvicCurtainText", FlashKey[4], OPTION_FLAG_WITH_UNMAP)
		FlashKeyMaps[5] = AddKeyMapOption("$FixAssCurtainText", FlashKey[5], OPTION_FLAG_WITH_UNMAP)
		
		AddEmptyOption()
		
		FlashKeyToggles[2] = AddToggleOption("$ResetFixKeybindsText", ConfirmSelection, 0)
		FlashKeyToggles[3] = AddToggleOption("$ClearFixKeybindsText", ConfirmSelection, 0)
	ElseIf (page == "$DebugPage")
		
		AddHeaderOption("$LoggingTypesHeader")
		LoggingToggles[0] = AddToggleOption("$MiscLoggingTypeText", LogSettings[LogType_Misc], 0)
		LoggingToggles[1] = AddToggleOption("$CoreLoggingTypeText", LogSettings[LogType_Core], 0)
		LoggingToggles[2] = AddToggleOption("$PlayerArmorScanLoggingTypeText", LogSettings[LogType_PlayerArmorScan], 0)
		LoggingToggles[3] = AddToggleOption("$PlayerModestyLoggingTypeText", LogSettings[LogType_PlayerModesty], 0)
		LoggingToggles[4] = AddToggleOption("$NPCDataLoggingTypeText", LogSettings[LogType_NPCData], 0)
		LoggingToggles[5] = AddToggleOption("$NPCArmorScanLoggingTypeText", LogSettings[LogType_NPCArmorScan], 0)
		LoggingToggles[6] = AddToggleOption("$NPCModestyLoggingTypeText", LogSettings[LogType_NPCModesty], 0)
		LoggingToggles[7] = AddToggleOption("$ConfigLoggingTypeText", LogSettings[LogType_Config], 0)
		
		SetCursorPosition(1)
		
		AddHeaderOption("$LoggingLevelsHeader")
		LoggingToggles[8] = AddToggleOption("$InfoLoggingLevelText", LogSettings[LogLevel_Info], 0)
		LoggingToggles[9] = AddToggleOption("$WarningLoggingLevelText", LogSettings[LogLevel_Warning], 0)
		LoggingToggles[10] = AddToggleOption("$ErrorLoggingLevelText", LogSettings[LogLevel_Error], 0)
	EndIf
EndEvent

Int Function DisabledIf(Bool Condition)
	If (Condition)
		return OPTION_FLAG_DISABLED
	Else
		return 0
	EndIf
EndFunction

Bool Function ShowConfirmationDialog(String Text)
	return ShowMessage(Text, True)
EndFunction

Event OnOptionKeyMapChange(Int Option, Int KeyCode, String ConflictControl, String ConflictName)
	AND_Logger.FastLog("<MCM> [OnOptionKeyMapChange] KeyCode is " + KeyCode, Logger.Config)
	AND_Logger.FastLog("<MCM> [OnOptionKeyMapChange] ConflictControl is " + ConflictControl, Logger.Config)
	AND_Logger.FastLog("<MCM> [OnOptionKeyMapChange] ConflictName is " + ConflictName, Logger.Config)
	If (KeyCode != 1 && ConflictControl != "" && !ShowConfirmationDialog("$AND_KeyAlreadyInUse"))
		return
	ElseIf KeyCode == 1
		KeyCode = -1
	EndIf
	
	If Option == FlashKeyMaps[0]
		FlashKey[0] = KeyCode
		Keybinds.UpdateRegister(0)
		SetKeymapOptionValue(Option, KeyCode)
	ElseIf Option == FlashKeyMaps[1]
		FlashKey[1] = KeyCode
		Keybinds.UpdateRegister(1)
		SetKeymapOptionValue(Option, KeyCode)
	ElseIf Option == FlashKeyMaps[2]
		FlashKey[2] = KeyCode
		Keybinds.UpdateRegister(2)
		SetKeymapOptionValue(Option, KeyCode)
	ElseIf Option == FlashKeyMaps[3]
		FlashKey[3] = KeyCode
		Keybinds.UpdateRegister(3)
		SetKeymapOptionValue(Option, KeyCode)
	ElseIf Option == FlashKeyMaps[4]
		FlashKey[4] = KeyCode
		Keybinds.UpdateRegister(4)
		SetKeymapOptionValue(Option, KeyCode)
	ElseIf Option == FlashKeyMaps[5]
		FlashKey[5] = KeyCode
		Keybinds.UpdateRegister(5)
		SetKeymapOptionValue(Option, KeyCode)
	EndIf
EndEvent

Event OnOptionHighlight(Int Option)
		;=========================
		;---TOGGLES---
		;=========================
		
		;=========================
		;General Modesty Page
		;=========================
	If Option == DynamicModestyToggles[0] ;DynamicModestyEnabled
		SetInfoText("$DynamicModestyInfoText")
	ElseIf Option == DynamicModestyToggles[1] ;PlayerStrictRules
		SetInfoText("$StrictModestyInfoText")
	ElseIf Option == DynamicModestyToggles[2] ;Corruption
		SetInfoText("$CorruptionInfoText")
	ElseIf Option == DynamicModestyToggles[3] ;Permanent Shameless
		SetInfoText("$ShamelessInfoText")
	ElseIf Option == DynamicModestyToggles[4] ;Hardcore
		SetInfoText("$HardcoreInfoText")
	ElseIf Option == DynamicModestyToggles[5] ;Reset Modesty
		SetInfoText("$ResetModestyInfoText")
	ElseIf Option == DynamicModestyToggles[6] ;Randomize Modesty
		SetInfoText("$RandomizeModestyInfoText")
	ElseIf Option == DynamicModestyToggles[7] ;Modesty Monologue
		SetInfoText("$ModestyMonologueInfoText")
	ElseIf Option == DynamicModestyToggles[8] ;Modesty MessageBox
		SetInfoText("$ModestyMessageboxInfoText")
		
		;=========================
		;Strict Modesty Page
		;=========================
		
	ElseIf Option == StrictModestyToggles[0] ;Rank Jump 1
		SetInfoText("$Rank1JumpInfoText")
	ElseIf Option == StrictModestyToggles[1] ;Rank Jump 2
		SetInfoText("$Rank2JumpInfoText")
	ElseIf Option == StrictModestyToggles[2] ;Rank Jump 3
		SetInfoText("$Rank3JumpInfoText")
	ElseIf Option == StrictModestyToggles[3] ;Rank Jump 4
		SetInfoText("$Rank4JumpInfoText")
	ElseIf Option == StrictModestyToggles[4] ;Rank Jump 5
		SetInfoText("$Rank5JumpInfoText")
	ElseIf Option == StrictModestyToggles[5] ;Rank Jump 6
		SetInfoText("$Rank6JumpInfoText")
		
		;=========================
		;Simple Modesty Page
		;=========================
	
	ElseIf Option == SimpleModestyToggles[0] ;Top Rank Jump 1
		SetInfoText("$TopRank1JumpInfoText")
	ElseIf Option == SimpleModestyToggles[1] ;Top Rank Jump 2
		SetInfoText("$TopRank2JumpInfoText")
	ElseIf Option == SimpleModestyToggles[2] ;Top Rank Jump 3
		SetInfoText("$TopRank3JumpInfoText")
	ElseIf Option == SimpleModestyToggles[3] ;Bottom Rank Jump 1
		SetInfoText("$BottomRank1JumpInfoText")
	ElseIf Option == SimpleModestyToggles[4] ;Bottom Rank Jump 2
		SetInfoText("$BottomRank2JumpInfoText")
	ElseIf Option == SimpleModestyToggles[5] ;Bottom Rank Jump 3
		SetInfoText("$BottomRank3JumpInfoText")
		
		;=========================
		;NPC Modesty Page
		;=========================
		
	ElseIf Option == NPCModestyToggles[0] ;NPC Strict Rules by Default
		SetInfoText("$NPCStrictRulesByDefaultInfoText")
	ElseIf Option == NPCModestyToggles[1] ;NPC Shameless by Default
		SetInfoText("$NPCShamelessByDefaultInfoText")
	ElseIf Option == NPCModestyToggles[2] ;NPC Corruption by Default
		SetInfoText("$NPCCorruptionByDefaultInfoText")
	
	ElseIf Option == NPCModestyToggles[3] ;Reset All NPCs
		SetInfoText("$ResetAllNPCInfoText")
	ElseIf Option == NPCModestyToggles[4] ;Reset All NPCs Confirm
		SetInfoText("$ResetAllNPCInfoText")
	ElseIf Option == NPCModestyToggles[5] ;Delete All NPCs
		SetInfoText("$DeleteAllNPCInfoText")
	ElseIf Option == NPCModestyToggles[6] ;Delete All NPCs Confirm
		SetInfoText("$DeleteAllNPCInfoText")
	
	ElseIf Option == NPCModestyToggles[7] ;Permanent Female
		SetInfoText("$PermanentFemaleInfoText")
	ElseIf Option == NPCModestyToggles[8] ;Permanent Female Confirm
		SetInfoText("$PermanentFemaleInfoText")
	ElseIf Option == NPCModestyToggles[9] ;Delete Female
		SetInfoText("$DeleteFemaleInfoText")
	ElseIf Option == NPCModestyToggles[10] ;Delete Female Confirm
		SetInfoText("$DeleteFemaleInfoText")
	ElseIf Option == NPCModestyToggles[11] ;Reset Female
		SetInfoText("$ResetFemaleInfoText")
	ElseIf Option == NPCModestyToggles[12] ;Reset Female Confirm
		SetInfoText("$ResetFemaleInfoText")
	ElseIf Option == NPCModestyToggles[13] ;Allow This NPC to gain permanent shameless
		SetInfoText("$ThisNPCPermanentShamelessInfoText")
	ElseIf Option == NPCModestyToggles[14] ;This NPC is Corrupted
		SetInfoText("$ThisNPCCorruptInfoText")
	ElseIf Option == NPCModestyToggles[15] ;This NPC is Strict
		SetInfoText("$NPCHasStrictRulesInfoText")
	ElseIf Option == NPCModestyToggles[16] ;Apply Ranks
		SetInfoText("$ApplyRanksInfoText")
	ElseIf Option == NPCModestyToggles[17] ;Apply Ranks as Default
		SetInfoText("$ApplyAsDefaultInfoText")
	ElseIf Option == NPCModestyToggles[18] ;Apply Ranks Confirm
		SetInfoText("$ApplyRanksConfirmInfoText")
	ElseIf Option == NPCModestyToggles[19] ;Delete Perm Female
		SetInfoText("$DeletePermFemaleInfoText")
	ElseIf Option == NPCModestyToggles[20] ;Delete Perm Female Confirm
		SetInfoText("$DeletePermFemaleInfoText")
		
		;=========================
		;Flash Keys Page
		;=========================
		
	ElseIf Option == FlashKeyMaps[0]
		SetInfoText("$FlashChestCurtainInfoText")
	ElseIf Option == FlashKeyMaps[1]
		SetInfoText("$FlashPelvicCurtainInfoText")
	ElseIf Option == FlashKeyMaps[2]
		SetInfoText("$FlashAssCurtainInfoText")
	ElseIf Option == FlashKeyMaps[3]
		SetInfoText("$FixChestCurtainInfoText")
	ElseIf Option == FlashKeyMaps[4]
		SetInfoText("$FixPelvicCurtainInfoText")
	ElseIf Option == FlashKeyMaps[5]
		SetInfoText("$FixAssCurtainInfoText")
		
	ElseIf Option == FlashKeyToggles[0]
		SetInfoText("$ResetFlashKeybindsInfoText")
	ElseIf Option == FlashKeyToggles[1]
		SetInfoText("$ClearFlashKeybindsInfoText")
	ElseIf Option == FlashKeyToggles[2]
		SetInfoText("$ResetFixKeybindsInfoText")
	ElseIf Option == FlashKeyToggles[3]
		SetInfoText("$ClearFixKeybindsInfoText")
		
		;=========================
		;Logging Page
		;=========================
		
	ElseIf Option == LoggingToggles[0] ;Misc Logging Type
		SetInfoText("$MiscLoggingInfoText")
	ElseIf Option == LoggingToggles[1] ;Core Logging Type
		SetInfoText("$CoreLoggingInfoText")
	ElseIf Option == LoggingToggles[2]
		SetInfoText("$PlayerArmorScanLoggingInfoText")
	ElseIf Option == LoggingToggles[3]
		SetInfoText("$PlayerModestyLoggingInfoText")
	ElseIf Option == LoggingToggles[4]
		SetInfoText("$NPCDataLoggingInfoText")
	ElseIf Option == LoggingToggles[5]
		SetInfoText("$NPCArmorScanLoggingInfoText")
	ElseIf Option == LoggingToggles[6]
		SetInfoText("$NPCModestyLoggingInfoText")
	ElseIf Option == LoggingToggles[7]
		SetInfoText("$ConfigLoggingInfoText")
	ElseIf Option == LoggingToggles[8]
		SetInfoText("$InfoLoggingLevelInfoText")
	ElseIf Option == LoggingToggles[9]
		SetInfoText("$WarningLoggingLevelInfoText")
	ElseIf Option == LoggingToggles[10]
		SetInfoText("$ErrorLoggingLevelInfoText")
		
		;=========================
		;---SLIDERS---
		;=========================
		
		;=========================
		;Simple Modesty Page
		;=========================
		
	ElseIf Option == SimpleModestySliders[0] ;Minimum Top Modesty
		SetInfoText("$MinimumTopModestyInfoText")
	ElseIf Option == SimpleModestySliders[1] ;Minimum Bottom Modesty
		SetInfoText("$MinimumBottomModestyInfoText")
		
		;=========================
		;NPC Modesty Page
		;=========================
		
	ElseIf Option == NPCModestySliders[0] ;NPC Arousal Cutoff
		SetInfoText("$NPCArousalCutoffInfoText")
	ElseIf Option == NPCModestySliders[1] ;Tweak Strict Rank
		SetInfoText("$TweakStrictRankInfoText")
	ElseIf Option == NPCModestySliders[2] ;Tweak Minimum Strict Rank
		SetInfoText("$TweakMinStrictRankInfoText")
	ElseIf Option == NPCModestySliders[3] ;Tweak Top Rank
		SetInfoText("$TweakTopRankInfoText")
	ElseIf Option == NPCModestySliders[4] ;Tweak Minimum Top Rank
		SetInfoText("$TweakMinTopRankInfoText")
	ElseIf Option == NPCModestySliders[5] ;Tweak Bottom Rank
		SetInfoText("$TweakBottomRankInfoText")
	ElseIf Option == NPCModestySliders[6] ;Tweak Minimum Bottom Rank
		SetInfoText("$TweakMinBottomRankInfoText")
	ElseIf Option == NPCModestySliders[7] ;Current Registered Females Page
		SetInfoText("$RegisteredFemalePageInfoText")
	ElseIf Option == NPCModestySliders[8] ;Current Permanent Females Page
		SetInfoText("$PermanentFemalePageInfoText")
	
		;=========================
		;---MENUS---
		;=========================
		
		;=========================
		;General Modesty Page
		;=========================
		
	ElseIf Option == DynamicModestyMenus[0] ;Select Shy Sex (PC)
		SetInfoText("SelectShySexInfoText")
		
		;=========================
		;NPC Modesty Page
		;=========================
		
	ElseIf Option == NPCModestyMenus[0] ;NPC Shy Sex
		SetInfoText("$NPCSelectShySexInfoText")
	ElseIf Option == NPCModestyMenus[1] ;Selected Female
		SetInfoText("$SelectedFemaleInfoText")
	ElseIf Option == NPCModestyMenus[2] ;NPC Shy Sex Tweak
		SetInfoText("$NPCSelectShySexTweakInfoText")
	ElseIf Option == NPCModestyMenus[3] ;Selected Permanent Female
		SetInfoText("$SelectedPermFemaleInfoText")
		
	EndIf
EndEvent

Event OnOptionSliderOpen(Int Option)
	Float StartValue
	Float RangeMin
	Float RangeMax
	Float Interval
	Float DefaultValue
	If Option == SimpleModestySliders[0]
		StartValue = ConfigIntOptions[MinimumTopRank] ;MinimumTopModestyRank
		RangeMin = 0
		RangeMax = 3
		Interval = 1
		DefaultValue = 0
	ElseIf Option == SimpleModestySliders[1]
		StartValue = ConfigIntOptions[MinimumBottomRank] ;MinimumBottomModestyRank
		RangeMin = 0
		RangeMax = 3
		Interval = 1
		DefaultValue = 0
	ElseIf Option == NPCModestySliders[0]
		StartValue = NPCModestyArousalThreshold.GetValue()
		RangeMin = 0
		RangeMax = 101
		Interval = 1
		DefaultValue = 70
	ElseIf Option == NPCModestySliders[1]
		StartValue = ThisNPCStrictRank
		RangeMin = 0
		RangeMax = 6
		Interval = 1
		DefaultValue = 0
	ElseIf Option == NPCModestySliders[2]
		StartValue = ThisNPCMinimumStrictRank
		RangeMin = 0
		RangeMax = 6
		Interval = 1
		DefaultValue = 0
	ElseIf Option == NPCModestySliders[3]
		StartValue = ThisNPCTopRank
		RangeMin = 0
		RangeMax = 3
		Interval = 1
		DefaultValue = 0
	ElseIf Option == NPCModestySliders[4]
		StartValue = ThisNPCMinimumTopRank
		RangeMin = 0
		RangeMax = 3
		Interval = 1
		DefaultValue = 0
	ElseIf Option == NPCModestySliders[5]
		StartValue = ThisNPCBottomRank
		RangeMin = 0
		RangeMax = 3
		Interval = 1
		DefaultValue = 0
	ElseIf Option == NPCModestySliders[6]
		StartValue = ThisNPCMinimumBottomRank
		RangeMin = 0
		RangeMax = 3
		Interval = 1
		DefaultValue = 0
	ElseIf Option == NPCModestySliders[7]
		StartValue = CurrentRegisteredFemalePage
		RangeMin = 1
		RangeMax = MaxRegisteredFemalePages
		Interval = 1
		DefaultValue = 1
	ElseIf Option == NPCModestySliders[8]
		StartValue = CurrentPermanentFemalePage
		RangeMin = 1
		RangeMax = MaxPermanentFemalePages
		Interval = 1
		DefaultValue = 1
	EndIf
	
	SetSliderDialogStartValue(StartValue)
	SetSliderDialogDefaultValue(StartValue)
	SetSliderDialogRange(RangeMin, RangeMax)
	SetSliderDialogInterval(Interval)
EndEvent

Event OnOptionSliderAccept(Int Option, Float Value)
	If Option == SimpleModestySliders[0]
		ConfigIntOptions[MinimumTopRank] = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == SimpleModestySliders[1]
		ConfigIntOptions[MinimumBottomRank] = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[0]
		NPCModestyArousalThreshold.SetValue(Value)
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[1]
		ThisNPCStrictRank = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[2]
		ThisNPCMinimumStrictRank = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[3]
		ThisNPCTopRank = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[4]
		ThisNPCMinimumTopRank = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[5]
		ThisNPCBottomRank = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[6]
		ThisNPCMinimumBottomRank = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
	ElseIf Option == NPCModestySliders[7]
		CurrentRegisteredFemalePage = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
		
		RegisteredFemaleNames = GetRegisteredFemaleNames(CurrentRegisteredFemalePage)
		RegisteredFemaleActors = GetRegisteredFemaleActors(CurrentRegisteredFemalePage)
		
		DisplayIndex = 0
		
		SelectedFemale = RegisteredFemaleNames[DisplayIndex]
		SelectedFemaleActor = RegisteredFemaleActors[DisplayIndex]
		ForcePageReset()
	ElseIf Option == NPCModestySliders[8]
		CurrentPermanentFemalePage = Value as Int
		SetSliderOptionValue(Option, Value, "{0}", False)
		
		PermanentFemaleNames = GetPermanentFemaleNames(CurrentPermanentFemalePage)
		PermanentFemaleActors = GetPermanentFemaleActors(CurrentPermanentFemalePage)
		
		PermIndex = 0
		
		SelectedPermFemale = PermanentFemaleNames[PermIndex]
		ForcePageReset()
	EndIf
EndEvent

Event OnOptionMenuOpen(Int Option)
	String[] Texts
	Int StartIndex
	If Option == DynamicModestyMenus[0]
		Texts = Sexes
		StartIndex = 0
	ElseIf Option == NPCModestyMenus[0]
		Texts = NPCSexes
		StartIndex = 0
	ElseIf Option == NPCModestyMenus[1]
		Texts = RegisteredFemaleNames ;DisplayFemaleName
		StartIndex = DisplayIndex
	ElseIf Option == NPCModestyMenus[2]
		Texts = Sexes
		StartIndex = 0
	ElseIf Option == NPCModestyMenus[3]
		Texts = PermanentFemaleNames
		StartIndex = PermIndex
	EndIf
	SetMenuDialogOptions(Texts)
	SetMenuDialogStartIndex(StartIndex)
	SetMenuDialogDefaultIndex(0)
EndEvent

Event OnOptionMenuAccept(Int Option, Int Index)
	String[] Texts
	If Option == DynamicModestyMenus[0]
		Texts = Sexes
		ShySex = Sexes[Index]
		
		If Index == 0
			PlayerFactionRanks[ShyWithMale] = 1
			PlayerFactionRanks[ShyWithFemale] = 0
		ElseIf Index == 1
			PlayerFactionRanks[ShyWithMale] = 0
			PlayerFactionRanks[ShyWithFemale] = 1
		ElseIf Index == 2
			PlayerFactionRanks[ShyWithMale] = 1
			PlayerFactionRanks[ShyWithFemale] = 1
		EndIf
		
		;=============
		;END PAGE 9
		;=============
		
	ElseIf Option == NPCModestyMenus[0]
		Texts = NPCSexes
		NPCShySex = NPCSexes[Index]
	ElseIf Option == NPCModestyMenus[1]
		Texts = RegisteredFemaleNames ;DisplayFemaleName
		DisplayIndex = Index
		MakeFemalePermanent = False
		DeleteFemale = False
		DeletePermFemale = False
		
		If DisplayIndex < 0
			DisplayIndex = 0
		EndIf
		
		SelectedFemale = RegisteredFemaleNames[DisplayIndex] ;DisplayFemaleName[DisplayIndex]
		SelectedFemaleActor = RegisteredFemaleActors[DisplayIndex]
		
		
		If SelectedFemale != "---" && SelectedFemale != ""
			AND_Logger.FastLog("<MCM> {NPC Modesty Page} Selected Female Actor is: " + SelectedFemaleActor + " " + SelectedFemale, Logger.Config)
			FemaleActorData = GetFemaleActorData(SelectedFemaleActor)
			
			ThisNPCStrictRank = FemaleActorData[FemaleActorData_CurrentStrictRank] as Float
			ThisNPCMinimumStrictRank = FemaleActorData[FemaleActorData_MinimumStrictRank] as Float
			ThisNPCTopRank = FemaleActorData[FemaleActorData_CurrentTopRank] as Float
			ThisNPCMinimumTopRank = FemaleActorData[FemaleActorData_MinimumTopRank] as Float
			ThisNPCBottomRank = FemaleActorData[FemaleActorData_CurrentBottomRank] as Float
			ThisNPCMinimumBottomRank = FemaleActorData[FemaleActorData_MinimumBottomRank] as Float
			
			ThisNPCShameless = FemaleActorData[FemaleActorData_Shameless] as Bool
			ThisNPCCorrupt = FemaleActorData[FemaleActorData_Corrupt] as Bool
			ThisNPCStrictRules = FemaleActorData[FemaleActorData_UsingStrictRules] as Bool
			ThisNPCUpgradeBlocked = FemaleActorData[FemaleActorData_UpgradeBlocked] as Bool
			
			Int SexIndex = FemaleActorData[FemaleActorData_ShySexIndex]
			ThisNPCShySex = Sexes[SexIndex]
		Else
			ThisNPCStrictRank = 0 as Float
			ThisNPCTopRank = 0 as Float
			ThisNPCBottomRank = 0 as Float
			ThisNPCMinimumStrictRank = 0 as Float
			ThisNPCMinimumTopRank = 0 as Float
			ThisNPCMinimumBottomRank = 0 as Float
			
			ThisNPCShameless = False
			ThisNPCCorrupt = False
			ThisNPCStrictRules = False
			ThisNPCUpgradeBlocked = False
			
			ThisNPCShySex = Sexes[0]
		EndIf
		
		ApplyTweak = False
		ApplyAsDefault = False
	ElseIf Option == NPCModestyMenus[2]
		ThisNPCShySex = Sexes[Index]
	ElseIf Option == NPCModestyMenus[3]
		Texts = PermanentFemaleNames
		PermIndex = Index
		DeletePermFemale = False
		
		If PermIndex < 0
			PermIndex = 0
		EndIf
		
		SelectedPermFemale = PermanentFemaleNames[PermIndex]
	EndIf
	ForcePageReset()
EndEvent

Event OnOptionSelect(Int Option)
	If Option == DynamicModestyToggles[0]
		If ConfigBoolOptions[DynamicModestyEnabled] == False
			ConfigBoolOptions[DynamicModestyEnabled] = True
			If ConfigBoolOptions[PlayerStrictRules] == True
				AND_DynamicModesty.SetValue(1)
			Else
				AND_DynamicModesty.SetValue(2)
			EndIf
		Else
			ConfigBoolOptions[DynamicModestyEnabled] = False
			AND_DynamicModesty.SetValue(0)
		EndIf
		SetToggleOptionValue(Option, ConfigBoolOptions[DynamicModestyEnabled])
		ForcePageReset()
	ElseIf Option == DynamicModestyToggles[1]
		If ConfigBoolOptions[PlayerStrictRules] == False
			ConfigBoolOptions[PlayerStrictRules] = True
			AND_DynamicModesty.SetValue(1)
		Else
			ConfigBoolOptions[PlayerStrictRules] = False
			AND_DynamicModesty.SetValue(2)
		EndIf
		SetToggleOptionValue(Option, ConfigBoolOptions[PlayerStrictRules])
		ForcePageReset()
	ElseIf Option == DynamicModestyToggles[2]
		ConfigBoolOptions[AllowPlayerCorruption] = !ConfigBoolOptions[AllowPlayerCorruption]
		SetToggleOptionValue(Option, ConfigBoolOptions[AllowPlayerCorruption])
	ElseIf Option == DynamicModestyToggles[3]
		ConfigBoolOptions[AllowPlayerShameless] = !ConfigBoolOptions[AllowPlayerShameless]
		SetToggleOptionValue(Option, ConfigBoolOptions[AllowPlayerShameless])
		ForcePageReset()
	ElseIf Option == DynamicModestyToggles[4]
		ConfigBoolOptions[HardcoreModeEnabled] = !ConfigBoolOptions[HardcoreModeEnabled]
		SetToggleOptionValue(Option, ConfigBoolOptions[HardcoreModeEnabled])
		
		If ConfigBoolOptions[HardcoreModeEnabled] == True
			Debug.MessageBox("WARNING: This will lock all Dynamic Modesty Settings when leaving the MCM! This CANNOT BE UNDONE UNLESS YOU HAVE AN OLDER SAVE TO REVERT TO!!!")
		EndIf
		
		ForcePageReset()
	ElseIf Option == DynamicModestyToggles[5]
		If ResetModesty == False
			Rank1Jump = False
			Rank2Jump = False
			Rank3Jump = False
			Rank4Jump = False
			Rank5Jump = False
			Rank6Jump = False
			
			TopRank1Jump = False
			TopRank2Jump = False
			TopRank3Jump = False
			
			BottomRank1Jump = False
			BottomRank2Jump = False
			BottomRank3Jump = False
			
			ResetModesty = True
		Else
			ResetModesty = False
		EndIf
		SetToggleOptionValue(Option, ResetModesty)
		ForcePageReset()
	ElseIf Option == DynamicModestyToggles[6]
		RandomizePlayer = !RandomizePlayer
		SetToggleOptionValue(Option, RandomizePlayer)
		ForcePageReset()
	ElseIf Option == DynamicModestyToggles[7]
		ModestyMonologue = !ModestyMonologue
		SetToggleOptionValue(Option, ModestyMonologue)
	ElseIf Option == DynamicModestyToggles[8]
		ModestyMessagebox = !ModestyMessagebox
		SetToggleOptionValue(Option, ModestyMessagebox)
		
		;===================
		;Strict Modesty Page
		;===================
		
	ElseIf Option == StrictModestyToggles[0]
		If Rank1Jump == False
			Rank1Jump = True
			Rank2Jump = False
			Rank3Jump = False
			Rank4Jump = False
			Rank5Jump = False
			Rank6Jump = False
			ResetModesty = False
		Else
			Rank1Jump = False
		EndIf
		SetToggleOptionValue(Option, Rank1Jump)
		ForcePageReset()
	ElseIf Option == StrictModestyToggles[1]
		If Rank2Jump == False
			Rank1Jump = False
			Rank2Jump = True
			Rank3Jump = False
			Rank4Jump = False
			Rank5Jump = False
			Rank6Jump = False
			ResetModesty = False
		Else
			Rank2Jump = False
		EndIf
		SetToggleOptionValue(Option, Rank2Jump)
		ForcePageReset()
	ElseIf Option == StrictModestyToggles[2]
		If Rank3Jump == False
			Rank1Jump = False
			Rank2Jump = False
			Rank3Jump = True
			Rank4Jump = False
			Rank5Jump = False
			Rank6Jump = False
			ResetModesty = False
		Else
			Rank3Jump = False
		EndIf
		SetToggleOptionValue(Option, Rank3Jump)
		ForcePageReset()
	ElseIf Option == StrictModestyToggles[3]
		If Rank4Jump == False
			Rank1Jump = False
			Rank2Jump = False
			Rank3Jump = False
			Rank4Jump = True
			Rank5Jump = False
			Rank6Jump = False
			ResetModesty = False
		Else
			Rank4Jump = False
		EndIf
		SetToggleOptionValue(Option, Rank4Jump)
		ForcePageReset()
	ElseIf Option == StrictModestyToggles[4]
		If Rank5Jump == False
			Rank1Jump = False
			Rank2Jump = False
			Rank3Jump = False
			Rank4Jump = False
			Rank5Jump = True
			Rank6Jump = False
			ResetModesty = False
		Else
			Rank5Jump = False
		EndIf
		SetToggleOptionValue(Option, Rank5Jump)
		ForcePageReset()
	ElseIf Option == StrictModestyToggles[5]
		If Rank6Jump == False
			Rank1Jump = False
			Rank2Jump = False
			Rank3Jump = False
			Rank4Jump = False
			Rank5Jump = False
			Rank6Jump = True
			ResetModesty = False
		Else
			Rank6Jump = False
		EndIf
		SetToggleOptionValue(Option, Rank6Jump)
		ForcePageReset()
		
		;===================
		;Simple Modesty Page
		;===================
		
	ElseIf Option == SimpleModestyToggles[0]
		If TopRank1Jump == False
			TopRank1Jump = True
			TopRank2Jump = False
			TopRank3Jump = False
		Else
			TopRank1Jump = False
		EndIf
		SetToggleOptionValue(Option, TopRank1Jump)
		ForcePageReset()
	ElseIf Option == SimpleModestyToggles[1]
		If TopRank2Jump == False
			TopRank1Jump = False
			TopRank2Jump = True
			TopRank3Jump = False
		Else
			TopRank2Jump = False
		EndIf
		SetToggleOptionValue(Option, TopRank2Jump)
		ForcePageReset()
	ElseIf Option == SimpleModestyToggles[2]
		If TopRank3Jump == False
			TopRank1Jump = False
			TopRank2Jump = False
			TopRank3Jump = True
		Else
			TopRank3Jump = False
		EndIf
		SetToggleOptionValue(Option, TopRank3Jump)
		ForcePageReset()
	ElseIf Option == SimpleModestyToggles[3]
		If BottomRank1Jump == False
			BottomRank1Jump = True
			BottomRank2Jump = False
			BottomRank3Jump = False
		Else
			BottomRank1Jump = False
		EndIf
		SetToggleOptionValue(Option, BottomRank1Jump)
		ForcePageReset()
	ElseIf Option == SimpleModestyToggles[4]
		If BottomRank2Jump == False
			BottomRank1Jump = False
			BottomRank2Jump = True
			BottomRank3Jump = False
		Else
			BottomRank2Jump = False
		EndIf
		SetToggleOptionValue(Option, BottomRank2Jump)
		ForcePageReset()
	ElseIf Option == SimpleModestyToggles[5]
		If BottomRank3Jump == False
			BottomRank1Jump = False
			BottomRank2Jump = False
			BottomRank3Jump = True
		Else
			BottomRank3Jump = False
		EndIf
		SetToggleOptionValue(Option, BottomRank3Jump)
		ForcePageReset()
		
		;===================
		;NPC Modesty Page
		;===================

	ElseIf Option == NPCModestyToggles[0]
		ConfigBoolOptions[NPCStrictRulesByDefault] = !ConfigBoolOptions[NPCStrictRulesByDefault]
		SetToggleOptionValue(Option, ConfigBoolOptions[NPCStrictRulesByDefault])
	ElseIf Option == NPCModestyToggles[1]
		ConfigBoolOptions[NPCShamelessByDefault] = !ConfigBoolOptions[NPCShamelessByDefault]
		SetToggleOptionValue(Option, ConfigBoolOptions[NPCShamelessByDefault])
	ElseIf Option == NPCModestyToggles[2]
		ConfigBoolOptions[NPCCorruptionByDeault] = !ConfigBoolOptions[NPCCorruptionByDeault]
		SetToggleOptionValue(Option, ConfigBoolOptions[NPCCorruptionByDeault])
	
	ElseIf Option == NPCModestyToggles[3]
		ResetAllNPCs = !ResetAllNPCs
		SetToggleOptionValue(Option, ResetAllNPCs)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[4]
		AND_NPCData.ResetAllFemales()
		ResetAllNPCs = False
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[5]
		DeleteAllNPCs = !DeleteAllNPCs
		SetToggleOptionValue(Option, DeleteAllNPCs)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[6]
		AND_Logger.FastLog("<MCM> {NPCModestyToggles[3]} Delete All NPC Data Started", Logger.Config, Logger.CRITICAL)
		
		AND_NPCData.DeleteAllFemales()
		
		AND_Logger.FastLog("<MCM> {NPCModestyToggles[3]} Delete All NPC Data Complete", Logger.Config, Logger.CRITICAL)
		DeleteAllNPCs = False
		ForcePageReset()
	
	ElseIf Option == NPCModestyToggles[7]
		MakeFemalePermanent = !MakeFemalePermanent
		SetToggleOptionValue(Option, MakeFemalePermanent)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[8] ;Confirm Make Permanent
		Int Result = AND_NPCData.RegisterPermanentFemale(RegisteredFemaleActors[DisplayIndex])
		If Result == 1
			Debug.MessageBox(RegisteredFemaleNames[DisplayIndex] + " already exists as a Persistent Female.")
		ElseIf Result >= 2
			Debug.MessageBox("AND - An Error occurred while trying to register " + RegisteredFemaleNames[DisplayIndex] + " as a Persistent Female! Check your logs!")
		EndIf
		
		MakeFemalePermanent = False
		PermanentFemaleNames = GetPermanentFemaleNames(CurrentPermanentFemalePage)
		PermanentFemaleActors = GetPermanentFemaleActors(CurrentPermanentFemalePage)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[9]
		DeleteFemale = !DeleteFemale
		SetToggleOptionValue(Option, DeleteFemale)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[10] ;Confirm Delete
		AND_NPCData.DeleteFemale(RegisteredFemaleActors[DisplayIndex])
		
		DeleteFemale = False
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[11]
		ResetFemaleModesty = !ResetFemaleModesty
		SetToggleOptionValue(Option, ResetFemaleModesty)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[12] ;Confirm Reset
		AND_NPCData.ResetFemale(RegisteredFemaleActors[DisplayIndex])
		
		ResetFemaleModesty = False
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[13]
		ThisNPCShameless = !ThisNPCShameless
		SetToggleOptionValue(Option, ThisNPCShameless)
	ElseIf Option == NPCModestyToggles[14]
		ThisNPCCorrupt = !ThisNPCCorrupt
		SetToggleOptionValue(Option, ThisNPCCorrupt)
	ElseIf Option == NPCModestyToggles[15]
		ThisNPCStrictRules = !ThisNPCStrictRules
		SetToggleOptionValue(Option, ApplyTweak)
	ElseIf Option == NPCModestyToggles[16]
		ApplyTweak = !ApplyTweak
		SetToggleOptionValue(Option, ApplyTweak)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[17]
		ApplyAsDefault = !ApplyAsDefault
		SetToggleOptionValue(Option, ApplyAsDefault)
	ElseIf Option == NPCModestyToggles[18] ;Confirm Tweak
		
		AND_NPCData.TweakFemale(RegisteredFemaleActors[DisplayIndex], ThisNPCStrictRank as Int, ThisNPCTopRank as Int, ThisNPCBottomRank as Int,\
			ThisNPCMinimumStrictRank as Int, ThisNPCMinimumTopRank as Int, ThisNPCMinimumBottomRank as Int, Sexes.Find(ThisNPCShySex),\
			ThisNPCShameless, ThisNPCCorrupt, ApplyAsDefault, ThisNPCStrictRules, ThisNPCUpgradeBlocked)
		ApplyTweak = False
		ApplyAsDefault = False
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[19]
		DeletePermFemale = !DeletePermFemale
		SetToggleOptionValue(Option, DeletePermFemale)
		ForcePageReset()
	ElseIf Option == NPCModestyToggles[20] ;Confirm Permanent Removal
		
		Int Result = AND_NPCData.RemovePermanent(PermanentFemaleActors[PermIndex])
		If Result >= 2
			Debug.MessageBox("AND - An Error occurred while trying to remove " + PermanentFemaleNames[DisplayIndex] + " from the Persistent Female list! Check your logs!")
		EndIf
		
		DeletePermFemale = False
		
		PermanentFemaleActors = GetPermanentFemaleActors(CurrentPermanentFemalePage)
		PermanentFemaleNames = GetPermanentFemaleNames(CurrentPermanentFemalePage)
		ForcePageReset()
		
		;===============
		;Flash Keys Page
		;===============
		
	ElseIf Option == FlashKeyToggles[0] ;Reset Flash Keys
		FlashKey[0] = 26
		FlashKey[1] = 27
		FlashKey[2] = 43
		Keybinds.UpdateRegister(0)
		Keybinds.UpdateRegister(1)
		Keybinds.UpdateRegister(2)
		ForcePageReset()
		
	ElseIf Option == FlashKeyToggles[1] ;Clear Flash Keys
		FlashKey[0] = -1
		FlashKey[1] = -1
		FlashKey[2] = -1
		Keybinds.UpdateRegister(0)
		Keybinds.UpdateRegister(1)
		Keybinds.UpdateRegister(2)
		ForcePageReset()
		
	ElseIf Option == FlashKeyToggles[2] ;Reset Fix Keys
		FlashKey[3] = 39
		FlashKey[4] = 40
		FlashKey[5] = 28
		Keybinds.UpdateRegister(3)
		Keybinds.UpdateRegister(4)
		Keybinds.UpdateRegister(5)
		ForcePageReset()
		
	ElseIf Option == FlashKeyToggles[3] ;Reset Fix Keys
		FlashKey[3] = -1
		FlashKey[4] = -1
		FlashKey[5] = -1
		Keybinds.UpdateRegister(3)
		Keybinds.UpdateRegister(4)
		Keybinds.UpdateRegister(5)
		ForcePageReset()
		
		;=============
		;Logging Page
		;=============
		
	ElseIf Option == LoggingToggles[0] ;Misc Logging Type
		LogSettings[LogType_Misc] = !LogSettings[LogType_Misc]
		AND_Logger.UpdateLoggingType(LogType_Misc, LogSettings[LogType_Misc])
		SetToggleOptionValue(Option, LogSettings[LogType_Misc])
		ForcePageReset()
	ElseIf Option == LoggingToggles[1] ;Core Logging Type
		LogSettings[LogType_Core] = !LogSettings[LogType_Core]
		AND_Logger.UpdateLoggingType(LogType_Core, LogSettings[LogType_Core])
		SetToggleOptionValue(Option, LogSettings[LogType_Core])
	ElseIf Option == LoggingToggles[2] ;Player Armor Logging Type
		LogSettings[LogType_PlayerArmorScan] = !LogSettings[LogType_PlayerArmorScan]
		AND_Logger.UpdateLoggingType(LogType_PlayerArmorScan, LogSettings[LogType_PlayerArmorScan])
		SetToggleOptionValue(Option, LogSettings[LogType_PlayerArmorScan])
	ElseIf Option == LoggingToggles[3] ;Player Modesty Logging Type
		LogSettings[LogType_PlayerModesty] = !LogSettings[LogType_PlayerModesty]
		AND_Logger.UpdateLoggingType(LogType_PlayerModesty, LogSettings[LogType_PlayerModesty])
		SetToggleOptionValue(Option, LogSettings[LogType_PlayerModesty])
	ElseIf Option == LoggingToggles[4] ;NPC Data Logging Type
		LogSettings[LogType_NPCData] = !LogSettings[LogType_NPCData]
		AND_Logger.UpdateLoggingType(LogType_NPCData, LogSettings[LogType_NPCData])
		SetToggleOptionValue(Option, LogSettings[LogType_NPCData])
	ElseIf Option == LoggingToggles[5] ;NPC Armor Scan Logging Type
		LogSettings[LogType_NPCArmorScan] = !LogSettings[LogType_NPCArmorScan]
		AND_Logger.UpdateLoggingType(LogType_NPCArmorScan, LogSettings[LogType_NPCArmorScan])
		SetToggleOptionValue(Option, LogSettings[LogType_NPCArmorScan])
	ElseIf Option == LoggingToggles[6] ;NPC Modesty Logging Type
		LogSettings[LogType_NPCModesty] = !LogSettings[LogType_NPCModesty]
		AND_Logger.UpdateLoggingType(LogType_NPCModesty, LogSettings[LogType_NPCModesty])
		SetToggleOptionValue(Option, LogSettings[LogType_NPCModesty])
	ElseIf Option == LoggingToggles[7] ;Config Logging Type
		LogSettings[LogType_Config] = !LogSettings[LogType_Config]
		AND_Logger.UpdateLoggingType(LogType_Config, LogSettings[LogType_Config])
		SetToggleOptionValue(Option, LogSettings[LogType_Config])
	
	;--- LOGGING LEVELS ---
	ElseIf Option == LoggingToggles[8] ;Info Logging Level
		LogSettings[LogLevel_Info] = !LogSettings[LogLevel_Info]
		AND_Logger.UpdateLoggingType(LogLevel_Info, LogSettings[LogLevel_Info])
		SetToggleOptionValue(Option, LogSettings[LogLevel_Info])
	ElseIf Option == LoggingToggles[9] ;Warning Logging Level
		LogSettings[LogLevel_Warning] = !LogSettings[LogLevel_Warning]
		AND_Logger.UpdateLoggingType(LogLevel_Warning, LogSettings[LogLevel_Warning])
		SetToggleOptionValue(Option, LogSettings[LogLevel_Warning])
	ElseIf Option == LoggingToggles[10] ;Error Logging Level
		LogSettings[LogLevel_Error] = !LogSettings[LogLevel_Error]
		AND_Logger.UpdateLoggingType(LogLevel_Error, LogSettings[LogLevel_Error])
		SetToggleOptionValue(Option, LogSettings[LogLevel_Error])
	EndIf
EndEvent

State AND_PlayerConfidence_State
	Event OnMenuOpenST()
		String[] Options = new String[6]
		
		Options[0] = "$Cowardly"
		Options[1] = "$Cautious"
		Options[2] = "$Average"
		Options[3] = "$Brave"
		Options[4] = "$Foolhardy"
		Options[5] = "$Random"
		
		Int StartIndex = Options.Find(PlayerConfidence)
		
		SetMenuDialogOptions(Options)
		SetMenuDialogStartIndex(StartIndex)
		SetMenuDialogDefaultIndex(2)
	EndEvent
	
	Event OnMenuAcceptST(Int AcceptedIndex)
		String[] Options = new String[6]
		
		Options[0] = "$Cowardly"
		Options[1] = "$Cautious"
		Options[2] = "$Average"
		Options[3] = "$Brave"
		Options[4] = "$Foolhardy"
		Options[5] = "$Random"
		
		PlayerConfidence = Options[AcceptedIndex]
		ConfigIntOptions[PlayerConfidenceValue] = AcceptedIndex
		SetMenuOptionValueST(PlayerConfidence, False, "AND_PlayerConfidence_State")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$PlayerConfidenceInfoText")
	EndEvent
EndState

State AND_ScanNPCToggle_State
	Event OnSelectST()
		If ScanNPC == False
			ScanNPC = True
		Else
			ScanNPC = False
		EndIf
		
		SetToggleOptionValueST(ScanNPC, False, "AND_ScanNPCToggle_State")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$ScanToggleInfoText")
	EndEvent
EndState

State AND_ScanFrequency_State
	Event OnMenuOpenST()
		String[] Options = new String[5]
		
		Options[0] = "$VSScan" ;0.75 Game Time (45 Game Minutes/135 IRL Seconds) - TimeScale Limit: 300
		Options[1] = "$SScan" ;0.5 Game Time (30 Game Minutes/90 IRL Seconds) - TimeScale Limit: 200
		Options[2] = "$NScan" ;0.25 Game Time (15 Game Minutes/45 IRL Seconds) - TimeScale Limit: 100
		Options[3] = "$FScan" ;0.15 Game Time (9 Game Minutes/27 IRL Seconds) - TimeScale Limit: 60
		Options[4] = "$VFScan" ;0.1 Game Time (6 Game Minutes/18 IRL Seconds) - TimeScale Limit: 40
		
		Int StartIndex = Options.Find(ScanFrequency)
		
		SetMenuDialogOptions(Options)
		SetMenuDialogStartIndex(StartIndex)
		SetMenuDialogDefaultIndex(2)
	EndEvent
	
	Event OnMenuAcceptST(Int AcceptedIndex)
		String[] Options = new String[5]
		
		Options[0] = "$VSScan" ;0.75 Game Time (45 Game Minutes/135 IRL Seconds) - TimeScale Limit: 300
		Options[1] = "$SScan" ;0.5 Game Time (30 Game Minutes/90 IRL Seconds) - TimeScale Limit: 200
		Options[2] = "$NScan" ;0.25 Game Time (15 Game Minutes/45 IRL Seconds) - TimeScale Limit: 100
		Options[3] = "$FScan" ;0.15 Game Time (9 Game Minutes/27 IRL Seconds) - TimeScale Limit: 60
		Options[4] = "$VFScan" ;0.1 Game Time (6 Game Minutes/18 IRL Seconds) - TimeScale Limit: 40
		
		ScanFrequency = Options[AcceptedIndex]
		AND_Logger.FastLog("<MCM> {AND_ScanFrequency_State:OnMenuAcceptST} Scan Speed is now: " + ScanFrequency, Logger.Config)
		SetMenuOptionValueST(ScanFrequency, False, "AND_ScanFrequency_State")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$ScanFrequencyInfoText")
	EndEvent
EndState

State AND_ModestyArousalThresholdState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ModestyArousalThreshold.GetValue())
		SetSliderDialogDefaultValue(70)
		SetSliderDialogRange(0,101)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ModestyArousalThreshold.SetValue(value)
		SetSliderOptionValueST(ModestyArousalThreshold.GetValue() as Int, "{0}", False, "AND_ModestyArousalThresholdState")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$ModestyArousalThresholdInfoText")
	EndEvent
EndState

State AND_ModestyUpgradeTimeState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[ImmodestyTimeNeeded])
		SetSliderDialogDefaultValue(14)
		SetSliderDialogRange(1, 120)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[ImmodestyTimeNeeded] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[ImmodestyTimeNeeded], "{0}", False, "AND_ModestyUpgradeTimeState")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$ImmodestyTimeInfoText")
	EndEvent
EndState

State AND_MinimumRankState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[MinimumStrictRank]) ;MinimumModestyRank)
		SetSliderDialogDefaultValue(0)
		SetSliderDialogRange(0,5)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[MinimumStrictRank] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[MinimumStrictRank], "{0}", False, "AND_MinimumRankState")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$MinimumRankInfoText")
	EndEvent
EndState

State AND_DisableNakedCommentsState
	Event OnSelectST()
		ConfigBoolOptions[DisableNakedComments] = !ConfigBoolOptions[DisableNakedComments]
		
		SetToggleOptionValueST(ConfigBoolOptions[DisableNakedComments], False, "AND_DisableNakedCommentsState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$DisableNakedCommentsInfoText")
	EndEvent
EndState

State AND_NudeFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[NudeFactionCommentChance])
		SetSliderDialogDefaultValue(30)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[NudeFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[NudeFactionCommentChance], "{0}", False, "AND_NudeFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$NudeCommentChanceInfoText")
	EndEvent
EndState

State AND_ToplessFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[ToplessFactionCommentChance])
		SetSliderDialogDefaultValue(20)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[ToplessFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[ToplessFactionCommentChance], "{0}", False, "AND_ToplessFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$ToplessCommentChanceInfoText")
	EndEvent
EndState

State AND_BottomlessFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[BottomlessFactionCommentChance])
		SetSliderDialogDefaultValue(20)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[BottomlessFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[BottomlessFactionCommentChance], "{0}", False, "AND_BottomlessFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$BottomlessCommentChanceInfoText")
	EndEvent
EndState

State AND_ChestFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[ChestFactionCommentChance])
		SetSliderDialogDefaultValue(10)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[ChestFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[ChestFactionCommentChance], "{0}", False, "AND_ChestFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$ChestCommentChanceInfoText")
	EndEvent
EndState

State AND_GenitalsFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[GenitalsFactionCommentChance])
		SetSliderDialogDefaultValue(15)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[GenitalsFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[GenitalsFactionCommentChance], "{0}", False, "AND_GenitalsFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$GenitalsCommentChanceInfoText")
	EndEvent
EndState

State AND_AssFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[AssFactionCommentChance])
		SetSliderDialogDefaultValue(5)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[AssFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[AssFactionCommentChance], "{0}", False, "AND_AssFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AssCommentChanceInfoText")
	EndEvent
EndState

State AND_BraFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[BraFactionCommentChance])
		SetSliderDialogDefaultValue(5)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[BraFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[BraFactionCommentChance], "{0}", False, "AND_BraFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$BraCommentChanceInfoText")
	EndEvent
EndState

State AND_UnderwearFactionCommentChanceState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[UnderwearFactionCommentChance])
		SetSliderDialogDefaultValue(5)
		SetSliderDialogRange(0,50)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[UnderwearFactionCommentChance] = value as Int
		SetSliderOptionValueST(ConfigIntOptions[UnderwearFactionCommentChance], "{0}", False, "AND_UnderwearFactionCommentChanceState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$UnderwearCommentChanceInfoText")
	EndEvent
EndState

State AND_NakedCommentChanceState
	Event OnHighlightST()
		SetInfoText("$NakedCommentChanceInfoText")
	EndEvent
EndState

State AND_AllowMotionFlashState
	Event OnSelectST()
		ConfigBoolOptions[MotionFlashEnabled] = !ConfigBoolOptions[MotionFlashEnabled]
		SetToggleOptionValueST(ConfigBoolOptions[MotionFlashEnabled], False, "AND_AllowMotionFlashState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AllowMotionFlash_InfoText")
	EndEvent
EndState

State AND_RunningFlashIncreaseState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[RunningModifier])
		If ConfigIntOptions[SprintingModifier] >= 10
			SetSliderDialogDefaultValue(10)
		Else
			SetSliderDialogDefaultValue(ConfigIntOptions[SprintingModifier])
		EndIf
		
		If ConfigIntOptions[SprintingModifier] <= 20
			SetSliderDialogRange(0, ConfigIntOptions[SprintingModifier])
		Else
			SetSliderDialogRange(5, 20)
		EndIf
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[RunningModifier] = value as Int
		SetSliderOptionValueST(value, "{0}", False, "AND_RunningFlashIncreaseState")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_RunningFlash_InfoText")
	EndEvent
EndState

State AND_SprintingFlashIncreaseState
	Event OnSliderOpenST()
		SetSliderDialogStartValue(ConfigIntOptions[SprintingModifier])
		SetSliderDialogDefaultValue(20)
		SetSliderDialogRange(ConfigIntOptions[RunningModifier], 40)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		ConfigIntOptions[SprintingModifier] = value as Int
		SetSliderOptionValueST(value, "{0}", False, "AND_SprintingFlashIncreaseState")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_SprintingFlash_InfoText")
	EndEvent
EndState

State UseGenderlessState
	Event OnSelectST()
		GenderlessWording = !GenderlessWording
		SetToggleOptionValueST(GenderlessWording, False, "UseGenderlessState")
		ForcePageReset()
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_Genderless_InfoText")
	EndEvent
EndState

State AND_ChestCurtainLowOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsLow])
		If FlashOdds[ChestCurtainOdds] >= 20
			SetSliderDialogDefaultValue(20)
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[ChestCurtainOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsLow] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsLow, FlashOdds[ChestCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsLow], "{0}%", False, "AND_ChestCurtainLowOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOdds] >= 20
			FlashOdds[ChestCurtainOddsLow] = 20
		Else
			FlashOdds[ChestCurtainOddsLow] = FlashOdds[ChestCurtainOdds]
		EndIf
		
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsLow], "{0}%", False, "AND_ChestCurtainLowOdds")
		UpdateFlashingOdds(ChestCurtainOddsLow, FlashOdds[ChestCurtainOddsLow])
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_ChestCurtainLowOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsLow_Male])
		If FlashOdds[ChestCurtainOdds_Male] >= 20
			SetSliderDialogDefaultValue(20)
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[ChestCurtainOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsLow_Male] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsLow_Male, FlashOdds[ChestCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsLow_Male], "{0}%", False, "AND_ChestCurtainLowOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOdds_Male] >= 20
			FlashOdds[ChestCurtainOddsLow_Male] = 20
		Else
			FlashOdds[ChestCurtainOddsLow_Male] = FlashOdds[ChestCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOddsLow_Male, FlashOdds[ChestCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsLow_Male], "{0}%", False, "AND_ChestCurtainLowOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_ChestCurtainOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOdds])
		If FlashOdds[ChestCurtainOddsLow] <= 35 && FlashOdds[ChestCurtainOddsHigh] >= 35
			SetSliderDialogDefaultValue(35)
		ElseIf FlashOdds[ChestCurtainOddsHigh] < 35
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsHigh])
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsLow])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOddsLow], FlashOdds[ChestCurtainOddsHigh])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOdds] = value as Int
		UpdateFlashingOdds(ChestCurtainOdds, FlashOdds[ChestCurtainOdds])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOdds], "{0}%", False, "AND_ChestCurtainOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOddsLow] <= 35 && FlashOdds[ChestCurtainOddsHigh] >= 35
			FlashOdds[ChestCurtainOdds] = 35
		ElseIf FlashOdds[ChestCurtainOddsHigh] < 35
			FlashOdds[ChestCurtainOdds] = FlashOdds[ChestCurtainOddsHigh]
		Else
			FlashOdds[ChestCurtainOdds] = FlashOdds[ChestCurtainOddsLow]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOdds, FlashOdds[ChestCurtainOdds])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOdds], "{0}%", False, "AND_ChestCurtainOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOdds_InfoText")
	EndEvent
EndState

State AND_ChestCurtainOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOdds_Male])
		If FlashOdds[ChestCurtainOddsLow_Male] <= 35 && FlashOdds[ChestCurtainOddsHigh_Male] >= 35
			SetSliderDialogDefaultValue(35)
		ElseIf FlashOdds[ChestCurtainOddsHigh_Male] < 35
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsHigh_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsLow_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOddsLow_Male], FlashOdds[ChestCurtainOddsHigh_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOdds_Male] = value as Int
		UpdateFlashingOdds(ChestCurtainOdds_Male, FlashOdds[ChestCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOdds_Male], "{0}%", False, "AND_ChestCurtainOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOddsLow_Male] <= 35 && FlashOdds[ChestCurtainOddsHigh_Male] >= 35
			FlashOdds[ChestCurtainOdds_Male] = 35
		ElseIf FlashOdds[ChestCurtainOddsHigh_Male] < 35
			FlashOdds[ChestCurtainOdds_Male] = FlashOdds[ChestCurtainOddsHigh_Male]
		Else
			FlashOdds[ChestCurtainOdds_Male] = FlashOdds[ChestCurtainOddsLow_Male]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOdds_Male, FlashOdds[ChestCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOdds_Male], "{0}%", False, "AND_ChestCurtainOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOdds_InfoText")
	EndEvent
EndState

State AND_ChestCurtainHighOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsHigh])
		If FlashOdds[ChestCurtainOdds] <= 50 && FlashOdds[ChestCurtainOddsExtreme] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[ChestCurtainOddsExtreme] < 50
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsExtreme])
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOdds], FlashOdds[ChestCurtainOddsExtreme])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsHigh] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsHigh, FlashOdds[ChestCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsHigh], "{0}%", False, "AND_ChestCurtainHighOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOdds] <= 50 && FlashOdds[ChestCurtainOddsExtreme] >= 50
			FlashOdds[ChestCurtainOddsHigh] = 50
		ElseIf ChestCurtainOddsExtreme < 50
			FlashOdds[ChestCurtainOddsHigh] = FlashOdds[ChestCurtainOddsExtreme]
		Else
			FlashOdds[ChestCurtainOddsHigh] = FlashOdds[ChestCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOddsHigh, FlashOdds[ChestCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsHigh], "{0}%", False, "AND_ChestCurtainHighOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_ChestCurtainHighOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsHigh_Male])
		If FlashOdds[ChestCurtainOdds_Male] <= 50 && FlashOdds[ChestCurtainOddsExtreme_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[ChestCurtainOddsExtreme_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsExtreme_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOdds_Male], FlashOdds[ChestCurtainOddsExtreme_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsHigh_Male] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsHigh_Male, FlashOdds[ChestCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsHigh_Male], "{0}%", False, "AND_ChestCurtainHighOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOdds_Male] <= 50 && FlashOdds[ChestCurtainOddsExtreme_Male] >= 50
			FlashOdds[ChestCurtainOddsHigh_Male] = 50
		ElseIf FlashOdds[ChestCurtainOddsExtreme_Male] < 50
			FlashOdds[ChestCurtainOddsHigh_Male] = FlashOdds[ChestCurtainOddsExtreme_Male]
		Else
			FlashOdds[ChestCurtainOddsHigh_Male] = FlashOdds[ChestCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOddsHigh_Male, FlashOdds[ChestCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsHigh_Male], "{0}%", False, "AND_ChestCurtainHighOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_ChestCurtainExtremeOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsExtreme])
		If FlashOdds[ChestCurtainOddsHigh] <= 65 && FlashOdds[ChestCurtainOddsUltra] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[ChestCurtainOddsUltra] < 65
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsUltra])
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsHigh])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOddsHigh], FlashOdds[ChestCurtainOddsUltra])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsExtreme] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsExtreme, FlashOdds[ChestCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsExtreme], "{0}%", False, "AND_ChestCurtainExtremeOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOddsHigh] <= 65 && FlashOdds[ChestCurtainOddsUltra] >= 65
			FlashOdds[ChestCurtainOddsExtreme] = 65
		ElseIf FlashOdds[ChestCurtainOddsUltra] < 65
			FlashOdds[ChestCurtainOddsExtreme] = FlashOdds[ChestCurtainOddsUltra]
		Else
			FlashOdds[ChestCurtainOddsExtreme] = FlashOdds[ChestCurtainOddsHigh]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOddsExtreme, FlashOdds[ChestCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsExtreme], "{0}%", False, "AND_ChestCurtainExtremeOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_ChestCurtainExtremeOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsExtreme_Male])
		If FlashOdds[ChestCurtainOddsHigh_Male] <= 65 && FlashOdds[ChestCurtainOddsUltra_Male] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[ChestCurtainOddsUltra_Male] < 65
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsUltra_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsHigh_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOddsHigh_Male], FlashOdds[ChestCurtainOddsUltra_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsExtreme_Male] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsExtreme_Male, FlashOdds[ChestCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsExtreme_Male], "{0}%", False, "AND_ChestCurtainExtremeOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOddsHigh_Male] <= 65 && FlashOdds[ChestCurtainOddsUltra_Male] >= 65
			FlashOdds[ChestCurtainOddsExtreme_Male] = 65
		ElseIf FlashOdds[ChestCurtainOddsUltra_Male] < 65
			FlashOdds[ChestCurtainOddsExtreme_Male] = FlashOdds[ChestCurtainOddsUltra_Male]
		Else
			FlashOdds[ChestCurtainOddsExtreme_Male] = FlashOdds[ChestCurtainOddsHigh_Male]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOddsExtreme_Male, FlashOdds[ChestCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsExtreme_Male], "{0}%", False, "AND_ChestCurtainExtremeOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_ChestCurtainUltraOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsUltra])
		If FlashOdds[ChestCurtainOddsExtreme] <= 80
			SetSliderDialogDefaultValue(80)
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsExtreme])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOddsExtreme], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsUltra] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsUltra, FlashOdds[ChestCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsUltra], "{0}%", False, "AND_ChestCurtainUltraOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOddsExtreme] <= 80
			FlashOdds[ChestCurtainOddsUltra] = 80
		Else
			FlashOdds[ChestCurtainOddsUltra] = FlashOdds[ChestCurtainOddsExtreme]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOddsUltra, FlashOdds[ChestCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsUltra], "{0}%", False, "AND_ChestCurtainUltraOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_ChestCurtainUltraOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[ChestCurtainOddsUltra_Male])
		If FlashOdds[ChestCurtainOddsExtreme_Male] <= 80
			SetSliderDialogDefaultValue(80)
		Else
			SetSliderDialogDefaultValue(FlashOdds[ChestCurtainOddsExtreme_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[ChestCurtainOddsExtreme_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[ChestCurtainOddsUltra_Male] = value as Int
		UpdateFlashingOdds(ChestCurtainOddsUltra_Male, FlashOdds[ChestCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsUltra_Male], "{0}%", False, "AND_ChestCurtainUltraOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[ChestCurtainOddsExtreme_Male] <= 80
			FlashOdds[ChestCurtainOddsUltra_Male] = 80
		Else
			FlashOdds[ChestCurtainOddsUltra_Male] = FlashOdds[ChestCurtainOddsExtreme_Male]
		EndIf
		
		UpdateFlashingOdds(ChestCurtainOddsUltra_Male, FlashOdds[ChestCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[ChestCurtainOddsUltra_Male], "{0}%", False, "AND_ChestCurtainUltraOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_ChestCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainLowOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsLow])
		If FlashOdds[TransparentChestCurtainOdds] >= 55
			SetSliderDialogDefaultValue(55)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentChestCurtainOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsLow] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsLow, FlashOdds[TransparentChestCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsLow], "{0}%", False, "AND_TransparentChestCurtainLowOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOdds] >= 55
			FlashOdds[TransparentChestCurtainOddsLow] = 55
		Else
			FlashOdds[TransparentChestCurtainOddsLow] = FlashOdds[TransparentChestCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsLow, FlashOdds[TransparentChestCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsLow], "{0}%", False, "AND_TransparentChestCurtainLowOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainLowOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsLow_Male])
		If FlashOdds[TransparentChestCurtainOdds_Male] >= 55
			SetSliderDialogDefaultValue(55)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentChestCurtainOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsLow_Male] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsLow_Male, FlashOdds[TransparentChestCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsLow_Male], "{0}%", False, "AND_TransparentChestCurtainLowOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOdds_Male] >= 55
			FlashOdds[TransparentChestCurtainOddsLow_Male] = 55
		Else
			FlashOdds[TransparentChestCurtainOddsLow_Male] = FlashOdds[TransparentChestCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsLow_Male, FlashOdds[TransparentChestCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsLow_Male], "{0}%", False, "AND_TransparentChestCurtainLowOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOdds])
		If FlashOdds[TransparentChestCurtainOddsLow] <= 65 && FlashOdds[TransparentChestCurtainOddsHigh] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[TransparentChestCurtainOddsHigh] < 65
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsHigh])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsLow])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOddsLow], FlashOdds[TransparentChestCurtainOddsHigh])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOdds] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOdds, FlashOdds[TransparentChestCurtainOdds])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOdds], "{0}%", False, "AND_TransparentChestCurtainOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOddsLow] <= 65 && FlashOdds[TransparentChestCurtainOddsHigh] >= 65
			FlashOdds[TransparentChestCurtainOdds] = 65
		ElseIf FlashOdds[TransparentChestCurtainOddsHigh] < 65
			FlashOdds[TransparentChestCurtainOdds] = FlashOdds[TransparentChestCurtainOddsHigh]
		Else
			FlashOdds[TransparentChestCurtainOdds] = FlashOdds[TransparentChestCurtainOddsLow]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOdds, FlashOdds[TransparentChestCurtainOdds])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOdds], "{0}%", False, "AND_TransparentChestCurtainOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOdds_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOdds_Male])
		If FlashOdds[TransparentChestCurtainOddsLow_Male] <= 65 && FlashOdds[TransparentChestCurtainOddsHigh_Male] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[TransparentChestCurtainOddsHigh_Male] < 65
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsHigh_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsLow_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOddsLow_Male], FlashOdds[TransparentChestCurtainOddsHigh_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOdds_Male, FlashOdds[TransparentChestCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOdds_Male], "{0}%", False, "AND_TransparentChestCurtainOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOddsLow_Male] <= 65 && FlashOdds[TransparentChestCurtainOddsHigh_Male] >= 65
			FlashOdds[TransparentChestCurtainOdds_Male] = 65
		ElseIf FlashOdds[TransparentChestCurtainOddsHigh_Male] < 65
			FlashOdds[TransparentChestCurtainOdds_Male] = FlashOdds[TransparentChestCurtainOddsHigh_Male]
		Else
			FlashOdds[TransparentChestCurtainOdds_Male] = FlashOdds[TransparentChestCurtainOddsLow_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOdds_Male, FlashOdds[TransparentChestCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOdds_Male], "{0}%", False, "AND_TransparentChestCurtainOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOdds_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainHighOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsHigh])
		If FlashOdds[TransparentChestCurtainOdds] <= 75 && FlashOdds[TransparentChestCurtainOddsExtreme] >= 75
			SetSliderDialogDefaultValue(75)
		ElseIf FlashOdds[TransparentChestCurtainOddsExtreme] < 75
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsExtreme])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOdds], FlashOdds[TransparentChestCurtainOddsExtreme])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsHigh] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsHigh, FlashOdds[TransparentChestCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsHigh], "{0}%", False, "AND_TransparentChestCurtainHighOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOdds] <= 75 && FlashOdds[TransparentChestCurtainOddsExtreme] >= 75
			FlashOdds[TransparentChestCurtainOddsHigh] = 75
		ElseIf FlashOdds[TransparentChestCurtainOddsExtreme] < 75
			FlashOdds[TransparentChestCurtainOddsHigh] = FlashOdds[TransparentChestCurtainOddsExtreme]
		Else
			FlashOdds[TransparentChestCurtainOddsHigh] = FlashOdds[TransparentChestCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsHigh, FlashOdds[TransparentChestCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsHigh], "{0}%", False, "AND_TransparentChestCurtainHighOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainHighOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsHigh_Male])
		If FlashOdds[TransparentChestCurtainOdds_Male] <= 75 && FlashOdds[TransparentChestCurtainOddsExtreme_Male] >= 75
			SetSliderDialogDefaultValue(75)
		ElseIf FlashOdds[TransparentChestCurtainOddsExtreme_Male] < 75
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsExtreme_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOdds_Male], FlashOdds[TransparentChestCurtainOddsExtreme_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsHigh_Male] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsHigh_Male, FlashOdds[TransparentChestCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsHigh_Male], "{0}%", False, "AND_TransparentChestCurtainHighOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOdds_Male] <= 75 && FlashOdds[TransparentChestCurtainOddsExtreme_Male] >= 75
			FlashOdds[TransparentChestCurtainOddsHigh_Male] = 75
		ElseIf FlashOdds[TransparentChestCurtainOddsExtreme_Male] < 75
			FlashOdds[TransparentChestCurtainOddsHigh_Male] = FlashOdds[TransparentChestCurtainOddsExtreme_Male]
		Else
			FlashOdds[TransparentChestCurtainOddsHigh_Male] = FlashOdds[TransparentChestCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsHigh_Male, FlashOdds[TransparentChestCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsHigh_Male], "{0}%", False, "AND_TransparentChestCurtainHighOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainExtremeOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsExtreme])
		If FlashOdds[TransparentChestCurtainOddsHigh] <= 85 && FlashOdds[TransparentChestCurtainOddsUltra] >= 85
			SetSliderDialogDefaultValue(85)
		ElseIf FlashOdds[TransparentChestCurtainOddsUltra] < 85
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsUltra])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsHigh])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOddsHigh], FlashOdds[TransparentChestCurtainOddsUltra])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsExtreme] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsExtreme, FlashOdds[TransparentChestCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsExtreme], "{0}%", False, "AND_TransparentChestCurtainExtremeOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOddsHigh] <= 85 && FlashOdds[TransparentChestCurtainOddsUltra] >= 85
			FlashOdds[TransparentChestCurtainOddsExtreme] = 85
		ElseIf FlashOdds[TransparentChestCurtainOddsUltra] < 85
			FlashOdds[TransparentChestCurtainOddsExtreme] = FlashOdds[TransparentChestCurtainOddsUltra]
		Else
			FlashOdds[TransparentChestCurtainOddsExtreme] = FlashOdds[TransparentChestCurtainOddsHigh]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsExtreme, FlashOdds[TransparentChestCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsExtreme], "{0}%", False, "AND_TransparentChestCurtainExtremeOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainExtremeOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsExtreme_Male])
		If FlashOdds[TransparentChestCurtainOddsHigh_Male] <= 85 && FlashOdds[TransparentChestCurtainOddsUltra_Male] >= 85
			SetSliderDialogDefaultValue(85)
		ElseIf FlashOdds[TransparentChestCurtainOddsUltra_Male] < 85
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsUltra_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsHigh_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOddsHigh_Male], FlashOdds[TransparentChestCurtainOddsUltra_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsExtreme_Male] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsExtreme_Male, FlashOdds[TransparentChestCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsExtreme_Male], "{0}%", False, "AND_TransparentChestCurtainExtremeOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOddsHigh_Male] <= 85 && FlashOdds[TransparentChestCurtainOddsUltra_Male] >= 85
			FlashOdds[TransparentChestCurtainOddsExtreme_Male] = 85
		ElseIf FlashOdds[TransparentChestCurtainOddsUltra_Male] < 85
			FlashOdds[TransparentChestCurtainOddsExtreme_Male] = FlashOdds[TransparentChestCurtainOddsUltra_Male]
		Else
			FlashOdds[TransparentChestCurtainOddsExtreme_Male] = FlashOdds[TransparentChestCurtainOddsHigh_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsExtreme_Male, FlashOdds[TransparentChestCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsExtreme_Male], "{0}%", False, "AND_TransparentChestCurtainExtremeOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainUltraOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsUltra])
		If FlashOdds[TransparentChestCurtainOddsExtreme] <= 95
			SetSliderDialogDefaultValue(95)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsExtreme])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOddsExtreme], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsUltra] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsUltra, FlashOdds[TransparentChestCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsUltra], "{0}%", False, "AND_TransparentChestCurtainUltraOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOddsExtreme] <= 95
			FlashOdds[TransparentChestCurtainOddsUltra] = 95
		Else
			FlashOdds[TransparentChestCurtainOddsUltra] = FlashOdds[TransparentChestCurtainOddsExtreme]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsUltra, FlashOdds[TransparentChestCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsUltra], "{0}%", False, "AND_TransparentChestCurtainUltraOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_TransparentChestCurtainUltraOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentChestCurtainOddsUltra_Male])
		If FlashOdds[TransparentChestCurtainOddsExtreme_Male] <= 95
			SetSliderDialogDefaultValue(95)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentChestCurtainOddsExtreme_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentChestCurtainOddsExtreme_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentChestCurtainOddsUltra_Male] = value as Int
		UpdateFlashingOdds(TransparentChestCurtainOddsUltra_Male, FlashOdds[TransparentChestCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsUltra_Male], "{0}%", False, "AND_TransparentChestCurtainUltraOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentChestCurtainOddsExtreme_Male] <= 95
			FlashOdds[TransparentChestCurtainOddsUltra_Male] = 95
		Else
			FlashOdds[TransparentChestCurtainOddsUltra_Male] = FlashOdds[TransparentChestCurtainOddsExtreme_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentChestCurtainOddsUltra_Male, FlashOdds[TransparentChestCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[TransparentChestCurtainOddsUltra_Male], "{0}%", False, "AND_TransparentChestCurtainUltraOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentChestCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainLowOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsLow])
		If FlashOdds[PelvicCurtainOdds] >= 20
			SetSliderDialogDefaultValue(20)
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[PelvicCurtainOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsLow] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsLow, FlashOdds[PelvicCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsLow], "{0}%", False, "AND_PelvicCurtainLowOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOdds] >= 20
			FlashOdds[PelvicCurtainOddsLow] = 20
		Else
			FlashOdds[PelvicCurtainOddsLow] = FlashOdds[PelvicCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsLow, FlashOdds[PelvicCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsLow], "{0}%", False, "AND_PelvicCurtainLowOdds")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainLowOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsLow_Male])
		If FlashOdds[PelvicCurtainOdds_Male] >= 20
			SetSliderDialogDefaultValue(20)
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[PelvicCurtainOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsLow_Male] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsLow_Male, FlashOdds[PelvicCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsLow_Male], "{0}%", False, "AND_PelvicCurtainLowOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOdds_Male] >= 20
			FlashOdds[PelvicCurtainOddsLow_Male] = 20
		Else
			FlashOdds[PelvicCurtainOddsLow_Male] = FlashOdds[PelvicCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsLow_Male, FlashOdds[PelvicCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsLow_Male], "{0}%", False, "AND_PelvicCurtainLowOddsMale")
	EndEvent 
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOdds])
		If FlashOdds[PelvicCurtainOddsLow] <= 35 && FlashOdds[PelvicCurtainOddsHigh] >= 35
			SetSliderDialogDefaultValue(35)
		ElseIf FlashOdds[PelvicCurtainOddsHigh] < 35
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsHigh])
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsLow])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOddsLow], FlashOdds[PelvicCurtainOddsHigh])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOdds] = value as Int
		UpdateFlashingOdds(PelvicCurtainOdds, FlashOdds[PelvicCurtainOdds])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOdds], "{0}%", False, "AND_PelvicCurtainOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOddsLow] <= 35 && FlashOdds[PelvicCurtainOddsHigh] >= 35
			FlashOdds[PelvicCurtainOdds] = 35
		ElseIf FlashOdds[PelvicCurtainOddsHigh] < 35
			FlashOdds[PelvicCurtainOdds] = FlashOdds[PelvicCurtainOddsHigh]
		Else
			FlashOdds[PelvicCurtainOdds] = FlashOdds[PelvicCurtainOddsLow]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOdds, FlashOdds[PelvicCurtainOdds])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOdds], "{0}%", False, "AND_PelvicCurtainOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOdds_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOdds_Male])
		If FlashOdds[PelvicCurtainOddsLow_Male] <= 35 && FlashOdds[PelvicCurtainOddsHigh_Male] >= 35
			SetSliderDialogDefaultValue(35)
		ElseIf FlashOdds[PelvicCurtainOddsHigh_Male] < 35
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsHigh_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsLow_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOddsLow_Male], FlashOdds[PelvicCurtainOddsHigh_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOdds_Male] = value as Int
		UpdateFlashingOdds(PelvicCurtainOdds_Male, FlashOdds[PelvicCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOdds_Male], "{0}%", False, "AND_PelvicCurtainOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOddsLow_Male] <= 35 && FlashOdds[PelvicCurtainOddsHigh_Male] >= 35
			FlashOdds[PelvicCurtainOdds_Male] = 35
		ElseIf FlashOdds[PelvicCurtainOddsHigh_Male] < 35
			FlashOdds[PelvicCurtainOdds_Male] = FlashOdds[PelvicCurtainOddsHigh_Male]
		Else
			FlashOdds[PelvicCurtainOdds_Male] = FlashOdds[PelvicCurtainOddsLow_Male]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOdds_Male, FlashOdds[PelvicCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOdds_Male], "{0}%", False, "AND_PelvicCurtainOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOdds_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainHighOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsHigh])
		If FlashOdds[PelvicCurtainOdds] <= 50 && FlashOdds[PelvicCurtainOddsExtreme] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[PelvicCurtainOddsExtreme] < 50
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsExtreme])
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOdds], FlashOdds[PelvicCurtainOddsExtreme])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsHigh] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsHigh, FlashOdds[PelvicCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsHigh], "{0}%", False, "AND_PelvicCurtainHighOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOdds] <= 50 && FlashOdds[PelvicCurtainOddsExtreme] >= 50
			FlashOdds[PelvicCurtainOddsHigh] = 50
		ElseIf FlashOdds[PelvicCurtainOddsExtreme] < 50
			FlashOdds[PelvicCurtainOddsHigh] = FlashOdds[PelvicCurtainOddsExtreme]
		Else
			FlashOdds[PelvicCurtainOddsHigh] = FlashOdds[PelvicCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsHigh, FlashOdds[PelvicCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsHigh], "{0}%", False, "AND_PelvicCurtainHighOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainHighOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsHigh_Male])
		If FlashOdds[PelvicCurtainOdds_Male] <= 50 && FlashOdds[PelvicCurtainOddsExtreme_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[PelvicCurtainOddsExtreme_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsExtreme_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOdds_Male], FlashOdds[PelvicCurtainOddsExtreme_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsHigh_Male] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsHigh_Male, FlashOdds[PelvicCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsHigh_Male], "{0}%", False, "AND_PelvicCurtainHighOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOdds_Male] <= 50 && FlashOdds[PelvicCurtainOddsExtreme_Male] >= 50
			FlashOdds[PelvicCurtainOddsHigh_Male] = 50
		ElseIf FlashOdds[PelvicCurtainOddsExtreme_Male] < 50
			FlashOdds[PelvicCurtainOddsHigh_Male] = FlashOdds[PelvicCurtainOddsExtreme_Male]
		Else
			FlashOdds[PelvicCurtainOddsHigh_Male] = FlashOdds[PelvicCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsHigh_Male, FlashOdds[PelvicCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsHigh_Male], "{0}%", False, "AND_PelvicCurtainHighOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainExtremeOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsExtreme])
		If FlashOdds[PelvicCurtainOddsHigh] <= 65 && FlashOdds[PelvicCurtainOddsUltra] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[PelvicCurtainOddsUltra] < 65
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsUltra])
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsHigh])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOddsHigh], FlashOdds[PelvicCurtainOddsUltra])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsExtreme] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsExtreme, FlashOdds[PelvicCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsExtreme], "{0}%", False, "AND_PelvicCurtainExtremeOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOddsHigh] <= 65 && FlashOdds[PelvicCurtainOddsUltra] >= 65
			FlashOdds[PelvicCurtainOddsExtreme] = 65
		ElseIf FlashOdds[PelvicCurtainOddsUltra] < 65
			FlashOdds[PelvicCurtainOddsExtreme] = FlashOdds[PelvicCurtainOddsUltra]
		Else
			FlashOdds[PelvicCurtainOddsExtreme] = FlashOdds[PelvicCurtainOddsHigh]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsExtreme, FlashOdds[PelvicCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsExtreme], "{0}%", False, "AND_PelvicCurtainExtremeOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainExtremeOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsExtreme_Male])
		If FlashOdds[PelvicCurtainOddsHigh_Male] <= 65 && FlashOdds[PelvicCurtainOddsUltra_Male] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[PelvicCurtainOddsUltra_Male] < 65
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsUltra_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsHigh_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOddsHigh_Male], FlashOdds[PelvicCurtainOddsUltra_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsExtreme_Male] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsExtreme_Male, FlashOdds[PelvicCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsExtreme_Male], "{0}%", False, "AND_PelvicCurtainExtremeOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOddsHigh_Male] <= 65 && FlashOdds[PelvicCurtainOddsUltra_Male] >= 65
			FlashOdds[PelvicCurtainOddsExtreme_Male] = 65
		ElseIf FlashOdds[PelvicCurtainOddsUltra_Male] < 65
			FlashOdds[PelvicCurtainOddsExtreme_Male] = FlashOdds[PelvicCurtainOddsUltra_Male]
		Else
			FlashOdds[PelvicCurtainOddsExtreme_Male] = FlashOdds[PelvicCurtainOddsHigh_Male]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsExtreme_Male, FlashOdds[PelvicCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsExtreme_Male], "{0}%", False, "AND_PelvicCurtainExtremeOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainUltraOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsUltra])
		If FlashOdds[PelvicCurtainOddsExtreme] <= 80
			SetSliderDialogDefaultValue(80)
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsExtreme])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOddsExtreme], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsUltra] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsUltra, FlashOdds[PelvicCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsUltra], "{0}%", False, "AND_PelvicCurtainUltraOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOddsExtreme] <= 80
			FlashOdds[PelvicCurtainOddsUltra] = 80
		Else
			FlashOdds[PelvicCurtainOddsUltra] = FlashOdds[PelvicCurtainOddsExtreme]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsUltra, FlashOdds[PelvicCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsUltra], "{0}%", False, "AND_PelvicCurtainUltraOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_PelvicCurtainUltraOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[PelvicCurtainOddsUltra_Male])
		If FlashOdds[PelvicCurtainOddsExtreme_Male] <= 80
			SetSliderDialogDefaultValue(80)
		Else
			SetSliderDialogDefaultValue(FlashOdds[PelvicCurtainOddsExtreme_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[PelvicCurtainOddsExtreme_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[PelvicCurtainOddsUltra_Male] = value as Int
		UpdateFlashingOdds(PelvicCurtainOddsUltra_Male, FlashOdds[PelvicCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsUltra_Male], "{0}%", False, "AND_PelvicCurtainUltraOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[PelvicCurtainOddsExtreme_Male] <= 80
			FlashOdds[PelvicCurtainOddsUltra_Male] = 80
		Else
			FlashOdds[PelvicCurtainOddsUltra_Male] = FlashOdds[PelvicCurtainOddsExtreme_Male]
		EndIf
		
		UpdateFlashingOdds(PelvicCurtainOddsUltra_Male, FlashOdds[PelvicCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[PelvicCurtainOddsUltra_Male], "{0}%", False, "AND_PelvicCurtainUltraOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_PelvicCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainLowOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsLow])
		If FlashOdds[TransparentPelvicCurtainOdds] >= 55
			SetSliderDialogDefaultValue(55)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentPelvicCurtainOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsLow] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsLow, FlashOdds[TransparentPelvicCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsLow], "{0}%", False, "AND_TransparentPelvicCurtainLowOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOdds] >= 55
			FlashOdds[TransparentPelvicCurtainOddsLow] = 55
		Else
			FlashOdds[TransparentPelvicCurtainOddsLow] = FlashOdds[TransparentPelvicCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsLow, FlashOdds[TransparentPelvicCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsLow], "{0}%", False, "AND_TransparentPelvicCurtainLowOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainLowOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsLow_Male])
		If FlashOdds[TransparentPelvicCurtainOdds_Male] >= 55
			SetSliderDialogDefaultValue(55)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentPelvicCurtainOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsLow_Male] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsLow_Male, FlashOdds[TransparentPelvicCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsLow_Male], "{0}%", False, "AND_TransparentPelvicCurtainLowOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOdds_Male] >= 55
			FlashOdds[TransparentPelvicCurtainOddsLow_Male] = 55
		Else
			FlashOdds[TransparentPelvicCurtainOddsLow_Male] = FlashOdds[TransparentPelvicCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsLow_Male, FlashOdds[TransparentPelvicCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsLow_Male], "{0}%", False, "AND_TransparentPelvicCurtainLowOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOdds])
		If FlashOdds[TransparentPelvicCurtainOddsLow] <= 65 && FlashOdds[TransparentPelvicCurtainOddsHigh] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[TransparentPelvicCurtainOddsHigh] < 65
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsHigh])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsLow])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOddsLow], FlashOdds[TransparentPelvicCurtainOddsHigh])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOdds] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOdds, FlashOdds[TransparentPelvicCurtainOdds])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOdds], "{0}%", False, "AND_TransparentPelvicCurtainOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOddsLow] <= 65 && FlashOdds[TransparentPelvicCurtainOddsHigh] >= 65
			FlashOdds[TransparentPelvicCurtainOdds] = 65
		ElseIf FlashOdds[TransparentPelvicCurtainOddsHigh] < 65
			FlashOdds[TransparentPelvicCurtainOdds] = FlashOdds[TransparentPelvicCurtainOddsHigh]
		Else
			FlashOdds[TransparentPelvicCurtainOdds] = FlashOdds[TransparentPelvicCurtainOddsLow]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOdds, FlashOdds[TransparentPelvicCurtainOdds])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOdds], "{0}%", False, "AND_TransparentPelvicCurtainOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOdds_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOdds_Male])
		If FlashOdds[TransparentPelvicCurtainOddsLow_Male] <= 65 && FlashOdds[TransparentPelvicCurtainOddsHigh_Male] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[TransparentPelvicCurtainOddsHigh_Male] < 65
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsHigh_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsLow_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOddsLow_Male], FlashOdds[TransparentPelvicCurtainOddsHigh_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOdds_Male, FlashOdds[TransparentPelvicCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOdds_Male], "{0}%", False, "AND_TransparentPelvicCurtainOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOddsLow_Male] <= 65 && FlashOdds[TransparentPelvicCurtainOddsHigh_Male] >= 65
			FlashOdds[TransparentPelvicCurtainOdds_Male] = 65
		ElseIf FlashOdds[TransparentPelvicCurtainOddsHigh_Male] < 65
			FlashOdds[TransparentPelvicCurtainOdds_Male] = FlashOdds[TransparentPelvicCurtainOddsHigh_Male]
		Else
			FlashOdds[TransparentPelvicCurtainOdds_Male] = FlashOdds[TransparentPelvicCurtainOddsLow_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOdds_Male, FlashOdds[TransparentPelvicCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOdds_Male], "{0}%", False, "AND_TransparentPelvicCurtainOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOdds_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainHighOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsHigh])
		If FlashOdds[TransparentPelvicCurtainOdds] <= 75 && FlashOdds[TransparentPelvicCurtainOddsExtreme] >= 75
			SetSliderDialogDefaultValue(75)
		ElseIf FlashOdds[TransparentPelvicCurtainOddsExtreme] < 75
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsExtreme])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOdds], FlashOdds[TransparentPelvicCurtainOddsExtreme])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsHigh] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsHigh, FlashOdds[TransparentPelvicCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsHigh], "{0}%", False, "AND_TransparentPelvicCurtainHighOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOdds] <= 75 && FlashOdds[TransparentPelvicCurtainOddsExtreme] >= 75
			FlashOdds[TransparentPelvicCurtainOddsHigh] = 75
		ElseIf FlashOdds[TransparentPelvicCurtainOddsExtreme] < 75
			FlashOdds[TransparentPelvicCurtainOddsHigh] = FlashOdds[TransparentPelvicCurtainOddsExtreme]
		Else
			FlashOdds[TransparentPelvicCurtainOddsHigh] = FlashOdds[TransparentPelvicCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsHigh, FlashOdds[TransparentPelvicCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsHigh], "{0}%", False, "AND_TransparentPelvicCurtainHighOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainHighOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsHigh_Male])
		If FlashOdds[TransparentPelvicCurtainOdds_Male] <= 75 && FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] >= 75
			SetSliderDialogDefaultValue(75)
		ElseIf FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] < 75
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsExtreme_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOdds_Male], FlashOdds[TransparentPelvicCurtainOddsExtreme_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsHigh_Male] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsHigh_Male, FlashOdds[TransparentPelvicCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsHigh_Male], "{0}%", False, "AND_TransparentPelvicCurtainHighOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOdds_Male] <= 75 && FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] >= 75
			FlashOdds[TransparentPelvicCurtainOddsHigh_Male] = 75
		ElseIf FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] < 75
			FlashOdds[TransparentPelvicCurtainOddsHigh_Male] = FlashOdds[TransparentPelvicCurtainOddsExtreme_Male]
		Else
			FlashOdds[TransparentPelvicCurtainOddsHigh_Male] = FlashOdds[TransparentPelvicCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsHigh_Male, FlashOdds[TransparentPelvicCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsHigh_Male], "{0}%", False, "AND_TransparentPelvicCurtainHighOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainExtremeOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsExtreme])
		If FlashOdds[TransparentPelvicCurtainOddsHigh] <= 85 && TransparentAssCurtainOddsUltra >= 85
			SetSliderDialogDefaultValue(85)
		ElseIf FlashOdds[TransparentPelvicCurtainOddsUltra] < 85
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsUltra])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsHigh])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOddsHigh], FlashOdds[TransparentPelvicCurtainOddsUltra])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsExtreme] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsExtreme, FlashOdds[TransparentPelvicCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsExtreme], "{0}%", False, "AND_TransparentPelvicCurtainExtremeOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOddsHigh] <= 85 && TransparentAssCurtainOddsUltra >= 85
			FlashOdds[TransparentPelvicCurtainOddsExtreme] = 85
		ElseIf FlashOdds[TransparentPelvicCurtainOddsUltra] < 85
			FlashOdds[TransparentPelvicCurtainOddsExtreme] = TransparentAssCurtainOddsUltra
		Else
			FlashOdds[TransparentPelvicCurtainOddsExtreme] = FlashOdds[TransparentPelvicCurtainOddsHigh]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsExtreme, FlashOdds[TransparentPelvicCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsExtreme], "{0}%", False, "AND_TransparentPelvicCurtainExtremeOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainExtremeOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsExtreme_Male])
		If FlashOdds[TransparentPelvicCurtainOddsHigh_Male] <= 85 && TransparentAssCurtainOddsUltra_Male >= 85
			SetSliderDialogDefaultValue(85)
		ElseIf FlashOdds[TransparentPelvicCurtainOddsUltra_Male] < 85
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsUltra_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsHigh_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOddsHigh_Male], FlashOdds[TransparentPelvicCurtainOddsUltra_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsExtreme_Male, FlashOdds[TransparentPelvicCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsExtreme_Male], "{0}%", False, "AND_TransparentPelvicCurtainExtremeOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOddsHigh_Male] <= 85 && TransparentAssCurtainOddsUltra_Male >= 85
			FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] = 85
		ElseIf FlashOdds[TransparentPelvicCurtainOddsUltra_Male] < 85
			FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] = TransparentAssCurtainOddsUltra_Male
		Else
			FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] = FlashOdds[TransparentPelvicCurtainOddsHigh_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsExtreme_Male, FlashOdds[TransparentPelvicCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsExtreme_Male], "{0}%", False, "AND_TransparentPelvicCurtainExtremeOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainUltraOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsUltra])
		If FlashOdds[TransparentPelvicCurtainOddsExtreme] <= 95
			SetSliderDialogDefaultValue(95)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsExtreme])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOddsExtreme], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsUltra] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsUltra, FlashOdds[TransparentPelvicCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsUltra], "{0}%", False, "AND_TransparentPelvicCurtainUltraOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOddsExtreme] <= 95
			FlashOdds[TransparentPelvicCurtainOddsUltra] = 95
		Else
			FlashOdds[TransparentPelvicCurtainOddsUltra] = FlashOdds[TransparentPelvicCurtainOddsExtreme]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsUltra, FlashOdds[TransparentPelvicCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsUltra], "{0}%", False, "AND_TransparentPelvicCurtainUltraOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_TransparentPelvicCurtainUltraOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentPelvicCurtainOddsUltra_Male])
		If FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] <= 95
			SetSliderDialogDefaultValue(95)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentPelvicCurtainOddsExtreme_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentPelvicCurtainOddsExtreme_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentPelvicCurtainOddsUltra_Male] = value as Int
		UpdateFlashingOdds(TransparentPelvicCurtainOddsUltra_Male, FlashOdds[TransparentPelvicCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsUltra_Male], "{0}%", False, "AND_TransparentPelvicCurtainUltraOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentPelvicCurtainOddsExtreme_Male] <= 95
			FlashOdds[TransparentPelvicCurtainOddsUltra_Male] = 95
		Else
			FlashOdds[TransparentPelvicCurtainOddsUltra_Male] = FlashOdds[TransparentPelvicCurtainOddsExtreme_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentPelvicCurtainOddsUltra_Male, FlashOdds[TransparentPelvicCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[TransparentPelvicCurtainOddsUltra_Male], "{0}%", False, "AND_TransparentPelvicCurtainUltraOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentPelvicCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_AssCurtainLowOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsLow])
		If FlashOdds[AssCurtainOdds] >= 20
			SetSliderDialogDefaultValue(20)
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[AssCurtainOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsLow] = value as Int
		UpdateFlashingOdds(AssCurtainOddsLow, FlashOdds[AssCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsLow], "{0}%", False, "AND_AssCurtainLowOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOdds] >= 20
			FlashOdds[AssCurtainOddsLow] = 20
		Else
			FlashOdds[AssCurtainOddsLow] = FlashOdds[AssCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsLow, FlashOdds[AssCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsLow], "{0}%", False, "AND_AssCurtainLowOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_AssCurtainLowOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsLow_Male])
		If FlashOdds[AssCurtainOdds_Male] >= 20
			SetSliderDialogDefaultValue(20)
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[AssCurtainOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsLow_Male] = value as Int
		UpdateFlashingOdds(AssCurtainOddsLow_Male, FlashOdds[AssCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsLow_Male], "{0}%", False, "AND_AssCurtainLowOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOdds_Male] >= 20
			FlashOdds[AssCurtainOddsLow_Male] = 20
		Else
			FlashOdds[AssCurtainOddsLow_Male] = FlashOdds[AssCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsLow_Male, FlashOdds[AssCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsLow_Male], "{0}%", False, "AND_AssCurtainLowOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_AssCurtainOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOdds])
		If FlashOdds[AssCurtainOddsLow] <= 35 && FlashOdds[AssCurtainOddsHigh] >= 35
			SetSliderDialogDefaultValue(35)
		ElseIf FlashOdds[AssCurtainOddsHigh] < 35
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsHigh])
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsLow])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOddsLow], FlashOdds[AssCurtainOddsHigh])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOdds] = value as Int
		UpdateFlashingOdds(AssCurtainOdds, FlashOdds[AssCurtainOdds])
		SetSliderOptionValueST(FlashOdds[AssCurtainOdds], "{0}%", False, "AND_AssCurtainOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOddsLow] <= 35 && FlashOdds[AssCurtainOddsHigh] >= 35
			FlashOdds[AssCurtainOdds] = 35
		ElseIf FlashOdds[AssCurtainOddsHigh] < 35
			FlashOdds[AssCurtainOdds] = FlashOdds[AssCurtainOddsHigh]
		Else
			FlashOdds[AssCurtainOdds] = FlashOdds[AssCurtainOddsLow]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOdds, FlashOdds[AssCurtainOdds])
		SetSliderOptionValueST(FlashOdds[AssCurtainOdds], "{0}%", False, "AND_AssCurtainOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOdds_InfoText")
	EndEvent
EndState

State AND_AssCurtainOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOdds_Male])
		If FlashOdds[AssCurtainOddsLow_Male] <= 35 && FlashOdds[AssCurtainOddsHigh_Male] >= 35
			SetSliderDialogDefaultValue(35)
		ElseIf FlashOdds[AssCurtainOddsHigh_Male] < 35
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsHigh_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsLow_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOddsLow_Male], FlashOdds[AssCurtainOddsHigh_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOdds_Male] = value as Int
		UpdateFlashingOdds(AssCurtainOdds_Male, FlashOdds[AssCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOdds_Male], "{0}%", False, "AND_AssCurtainOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOddsLow_Male] <= 35 && FlashOdds[AssCurtainOddsHigh_Male] >= 35
			FlashOdds[AssCurtainOdds_Male] = 35
		ElseIf FlashOdds[AssCurtainOddsHigh_Male] < 35
			FlashOdds[AssCurtainOdds_Male] = FlashOdds[AssCurtainOddsHigh_Male]
		Else
			FlashOdds[AssCurtainOdds_Male] = FlashOdds[AssCurtainOddsLow_Male]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOdds_Male, FlashOdds[AssCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOdds_Male], "{0}%", False, "AND_AssCurtainOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOdds_InfoText")
	EndEvent
EndState

State AND_AssCurtainHighOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsHigh])
		If FlashOdds[AssCurtainOdds] <= 50 && FlashOdds[AssCurtainOddsExtreme] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[AssCurtainOddsExtreme] < 50
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsExtreme])
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOdds], FlashOdds[AssCurtainOddsExtreme])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsHigh] = value as Int
		UpdateFlashingOdds(AssCurtainOddsHigh, FlashOdds[AssCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsHigh], "{0}%", False, "AND_AssCurtainHighOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOdds] <= 50 && FlashOdds[AssCurtainOddsExtreme] >= 50
			FlashOdds[AssCurtainOddsHigh] = 50
		ElseIf FlashOdds[AssCurtainOddsExtreme] < 50
			FlashOdds[AssCurtainOddsHigh] = FlashOdds[AssCurtainOddsExtreme]
		Else
			FlashOdds[AssCurtainOddsHigh] = FlashOdds[AssCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsHigh, FlashOdds[AssCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsHigh], "{0}%", False, "AND_AssCurtainHighOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_AssCurtainHighOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsHigh_Male])
		If FlashOdds[AssCurtainOdds_Male] <= 50 && FlashOdds[AssCurtainOddsExtreme_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[AssCurtainOddsExtreme_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsExtreme_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOdds_Male], FlashOdds[AssCurtainOddsExtreme_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsHigh_Male] = value as Int
		UpdateFlashingOdds(AssCurtainOddsHigh_Male, FlashOdds[AssCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsHigh_Male], "{0}%", False, "AND_AssCurtainHighOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOdds_Male] <= 50 && FlashOdds[AssCurtainOddsExtreme_Male] >= 50
			FlashOdds[AssCurtainOddsHigh_Male] = 50
		ElseIf FlashOdds[AssCurtainOddsExtreme_Male] < 50
			FlashOdds[AssCurtainOddsHigh_Male] = FlashOdds[AssCurtainOddsExtreme_Male]
		Else
			FlashOdds[AssCurtainOddsHigh_Male] = FlashOdds[AssCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsHigh_Male, FlashOdds[AssCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsHigh_Male], "{0}%", False, "AND_AssCurtainHighOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_AssCurtainExtremeOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsExtreme])
		If FlashOdds[AssCurtainOddsHigh] <= 65 && FlashOdds[AssCurtainOddsUltra] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[AssCurtainOddsUltra] < 65
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsUltra])
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsHigh])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOddsHigh], FlashOdds[AssCurtainOddsUltra])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsExtreme] = value as Int
		UpdateFlashingOdds(AssCurtainOddsExtreme, FlashOdds[AssCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsExtreme], "{0}%", False, "AND_AssCurtainExtremeOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOddsHigh] <= 65 && FlashOdds[AssCurtainOddsUltra] >= 65
			FlashOdds[AssCurtainOddsExtreme] = 65
		ElseIf FlashOdds[AssCurtainOddsUltra] < 65
			FlashOdds[AssCurtainOddsExtreme] = FlashOdds[AssCurtainOddsUltra]
		Else
			FlashOdds[AssCurtainOddsExtreme] = FlashOdds[AssCurtainOddsHigh]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsExtreme, FlashOdds[AssCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsExtreme], "{0}%", False, "AND_AssCurtainExtremeOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_AssCurtainExtremeOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsExtreme_Male])
		If FlashOdds[AssCurtainOddsHigh_Male] <= 65 && FlashOdds[AssCurtainOddsUltra_Male] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[AssCurtainOddsUltra_Male] < 65
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsUltra_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsHigh_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOddsHigh_Male], FlashOdds[AssCurtainOddsUltra_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsExtreme_Male] = value as Int
		UpdateFlashingOdds(AssCurtainOddsExtreme_Male, FlashOdds[AssCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsExtreme_Male], "{0}%", False, "AND_AssCurtainExtremeOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOddsHigh_Male] <= 65 && FlashOdds[AssCurtainOddsUltra_Male] >= 65
			FlashOdds[AssCurtainOddsExtreme_Male] = 65
		ElseIf FlashOdds[AssCurtainOddsUltra_Male] < 65
			FlashOdds[AssCurtainOddsExtreme_Male] = FlashOdds[AssCurtainOddsUltra_Male]
		Else
			FlashOdds[AssCurtainOddsExtreme_Male] = FlashOdds[AssCurtainOddsHigh_Male]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsExtreme_Male, FlashOdds[AssCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsExtreme_Male], "{0}%", False, "AND_AssCurtainExtremeOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_AssCurtainUltraOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsUltra])
		If FlashOdds[AssCurtainOddsExtreme] <= 80
			SetSliderDialogDefaultValue(80)
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsExtreme])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOddsExtreme], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsUltra] = value as Int
		UpdateFlashingOdds(AssCurtainOddsUltra, FlashOdds[AssCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsUltra], "{0}%", False, "AND_AssCurtainUltraOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOddsExtreme] <= 80
			FlashOdds[AssCurtainOddsUltra] = 80
		Else
			FlashOdds[AssCurtainOddsUltra] = FlashOdds[AssCurtainOddsExtreme]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsUltra, FlashOdds[AssCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsUltra], "{0}%", False, "AND_AssCurtainUltraOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_AssCurtainUltraOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[AssCurtainOddsUltra_Male])
		If FlashOdds[AssCurtainOddsExtreme_Male] <= 80
			SetSliderDialogDefaultValue(80)
		Else
			SetSliderDialogDefaultValue(FlashOdds[AssCurtainOddsExtreme_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[AssCurtainOddsExtreme_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[AssCurtainOddsUltra_Male] = value as Int
		UpdateFlashingOdds(AssCurtainOddsUltra_Male, FlashOdds[AssCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsUltra_Male], "{0}%", False, "AND_AssCurtainUltraOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[AssCurtainOddsExtreme_Male] <= 80
			FlashOdds[AssCurtainOddsUltra_Male] = 80
		Else
			FlashOdds[AssCurtainOddsUltra_Male] = FlashOdds[AssCurtainOddsExtreme_Male]
		EndIf
		
		UpdateFlashingOdds(AssCurtainOddsUltra_Male, FlashOdds[AssCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[AssCurtainOddsUltra_Male], "{0}%", False, "AND_AssCurtainUltraOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_AssCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainLowOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsLow])
		If FlashOdds[TransparentAssCurtainOdds] >= 55
			SetSliderDialogDefaultValue(55)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentAssCurtainOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsLow] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsLow, FlashOdds[TransparentAssCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsLow], "{0}%", False, "AND_TransparentAssCurtainLowOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOdds] >= 55
			FlashOdds[TransparentAssCurtainOddsLow] = 55
		Else
			FlashOdds[TransparentAssCurtainOddsLow] = FlashOdds[TransparentAssCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsLow, FlashOdds[TransparentAssCurtainOddsLow])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsLow], "{0}%", False, "AND_TransparentAssCurtainLowOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainLowOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsLow_Male])
		If FlashOdds[TransparentAssCurtainOdds_Male] >= 55
			SetSliderDialogDefaultValue(55)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentAssCurtainOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsLow_Male] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsLow_Male, FlashOdds[TransparentAssCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsLow_Male], "{0}%", False, "AND_TransparentAssCurtainLowOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOdds_Male] >= 55
			FlashOdds[TransparentAssCurtainOddsLow_Male] = 55
		Else
			FlashOdds[TransparentAssCurtainOddsLow_Male] = FlashOdds[TransparentAssCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsLow_Male, FlashOdds[TransparentAssCurtainOddsLow_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsLow_Male], "{0}%", False, "AND_TransparentAssCurtainLowOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOdds])
		If FlashOdds[TransparentAssCurtainOddsLow] <= 65 && FlashOdds[TransparentAssCurtainOddsHigh] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[TransparentAssCurtainOddsHigh] < 65
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsHigh])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsLow])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOddsLow], FlashOdds[TransparentAssCurtainOddsHigh])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOdds] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOdds, FlashOdds[TransparentAssCurtainOdds])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOdds], "{0}%", False, "AND_TransparentAssCurtainOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOddsLow] <= 65 && FlashOdds[TransparentAssCurtainOddsHigh] >= 65
			FlashOdds[TransparentAssCurtainOdds] = 65
		ElseIf FlashOdds[TransparentAssCurtainOddsHigh] < 65
			FlashOdds[TransparentAssCurtainOdds] = FlashOdds[TransparentAssCurtainOddsHigh]
		Else
			FlashOdds[TransparentAssCurtainOdds] = FlashOdds[TransparentAssCurtainOddsLow]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOdds, FlashOdds[TransparentAssCurtainOdds])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOdds], "{0}%", False, "AND_TransparentAssCurtainOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOdds_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOdds_Male])
		If FlashOdds[TransparentAssCurtainOddsLow_Male] <= 65 && FlashOdds[TransparentAssCurtainOddsHigh_Male] >= 65
			SetSliderDialogDefaultValue(65)
		ElseIf FlashOdds[TransparentAssCurtainOddsHigh_Male] < 65
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsHigh_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsLow_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOddsLow_Male], FlashOdds[TransparentAssCurtainOddsHigh_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOdds_Male, FlashOdds[TransparentAssCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOdds_Male], "{0}%", False, "AND_TransparentAssCurtainOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOddsLow_Male] <= 65 && FlashOdds[TransparentAssCurtainOddsHigh_Male] >= 65
			FlashOdds[TransparentAssCurtainOdds_Male] = 65
		ElseIf FlashOdds[TransparentAssCurtainOddsHigh_Male] < 65
			FlashOdds[TransparentAssCurtainOdds_Male] = FlashOdds[TransparentAssCurtainOddsHigh_Male]
		Else
			FlashOdds[TransparentAssCurtainOdds_Male] = FlashOdds[TransparentAssCurtainOddsLow_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOdds_Male, FlashOdds[TransparentAssCurtainOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOdds_Male], "{0}%", False, "AND_TransparentAssCurtainOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOdds_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainHighOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsHigh])
		If FlashOdds[TransparentAssCurtainOdds] <= 75 && FlashOdds[TransparentAssCurtainOddsExtreme] >= 75
			SetSliderDialogDefaultValue(75)
		ElseIf FlashOdds[TransparentAssCurtainOddsExtreme] < 75
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsExtreme])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOdds], FlashOdds[TransparentAssCurtainOddsExtreme])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsHigh] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsHigh, FlashOdds[TransparentAssCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsHigh], "{0}%", False, "AND_TransparentAssCurtainHighOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOdds] <= 75 && FlashOdds[TransparentAssCurtainOddsExtreme] >= 75
			FlashOdds[TransparentAssCurtainOddsHigh] = 75
		ElseIf FlashOdds[TransparentAssCurtainOddsExtreme] < 75
			FlashOdds[TransparentAssCurtainOddsHigh] = FlashOdds[TransparentAssCurtainOddsExtreme]
		Else
			FlashOdds[TransparentAssCurtainOddsHigh] = FlashOdds[TransparentAssCurtainOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsHigh, FlashOdds[TransparentAssCurtainOddsHigh])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsHigh], "{0}%", False, "AND_TransparentAssCurtainHighOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainHighOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsHigh_Male])
		If FlashOdds[TransparentAssCurtainOdds_Male] <= 75 && FlashOdds[TransparentAssCurtainOddsExtreme_Male] >= 75
			SetSliderDialogDefaultValue(75)
		ElseIf FlashOdds[TransparentAssCurtainOddsExtreme_Male] < 75
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsExtreme_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOdds_Male], FlashOdds[TransparentAssCurtainOddsExtreme_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsHigh_Male] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsHigh_Male, FlashOdds[TransparentAssCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsHigh_Male], "{0}%", False, "AND_TransparentAssCurtainHighOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOdds_Male] <= 75 && FlashOdds[TransparentAssCurtainOddsExtreme_Male] >= 75
			FlashOdds[TransparentAssCurtainOddsHigh_Male] = 75
		ElseIf FlashOdds[TransparentAssCurtainOddsExtreme_Male] < 75
			FlashOdds[TransparentAssCurtainOddsHigh_Male] = FlashOdds[TransparentAssCurtainOddsExtreme_Male]
		Else
			FlashOdds[TransparentAssCurtainOddsHigh_Male] = FlashOdds[TransparentAssCurtainOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsHigh_Male, FlashOdds[TransparentAssCurtainOddsHigh_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsHigh_Male], "{0}%", False, "AND_TransparentAssCurtainHighOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainExtremeOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsExtreme])
		If FlashOdds[TransparentAssCurtainOddsHigh] <= 85 && FlashOdds[TransparentAssCurtainOddsUltra] >= 85
			SetSliderDialogDefaultValue(85)
		ElseIf FlashOdds[TransparentAssCurtainOddsUltra] < 85
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsUltra])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsHigh])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOddsHigh], FlashOdds[TransparentAssCurtainOddsUltra])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsExtreme] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsExtreme, FlashOdds[TransparentAssCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsExtreme], "{0}%", False, "AND_TransparentAssCurtainExtremeOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOddsHigh] <= 85 && FlashOdds[TransparentAssCurtainOddsUltra] >= 85
			FlashOdds[TransparentAssCurtainOddsExtreme] = 85
		ElseIf FlashOdds[TransparentAssCurtainOddsUltra] < 85
			FlashOdds[TransparentAssCurtainOddsExtreme] = FlashOdds[TransparentAssCurtainOddsUltra]
		Else
			FlashOdds[TransparentAssCurtainOddsExtreme] = FlashOdds[TransparentAssCurtainOddsHigh]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsExtreme, FlashOdds[TransparentAssCurtainOddsExtreme])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsExtreme], "{0}%", False, "AND_TransparentAssCurtainExtremeOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainExtremeOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsExtreme_Male])
		If FlashOdds[TransparentAssCurtainOddsHigh_Male] <= 85 && FlashOdds[TransparentAssCurtainOddsUltra_Male] >= 85
			SetSliderDialogDefaultValue(85)
		ElseIf FlashOdds[TransparentAssCurtainOddsUltra_Male] < 85
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsUltra_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsHigh_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOddsHigh_Male], FlashOdds[TransparentAssCurtainOddsUltra_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsExtreme_Male] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsExtreme_Male, FlashOdds[TransparentAssCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsExtreme_Male], "{0}%", False, "AND_TransparentAssCurtainExtremeOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOddsHigh_Male] <= 85 && FlashOdds[TransparentAssCurtainOddsUltra_Male] >= 85
			FlashOdds[TransparentAssCurtainOddsExtreme_Male] = 85
		ElseIf FlashOdds[TransparentAssCurtainOddsUltra_Male] < 85
			FlashOdds[TransparentAssCurtainOddsExtreme_Male] = FlashOdds[TransparentAssCurtainOddsUltra_Male]
		Else
			FlashOdds[TransparentAssCurtainOddsExtreme_Male] = FlashOdds[TransparentAssCurtainOddsHigh_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsExtreme_Male, FlashOdds[TransparentAssCurtainOddsExtreme_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsExtreme_Male], "{0}%", False, "AND_TransparentAssCurtainExtremeOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsExtreme_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainUltraOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsUltra])
		If FlashOdds[TransparentAssCurtainOddsExtreme] <= 95
			SetSliderDialogDefaultValue(95)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsExtreme])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOddsExtreme], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsUltra] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsUltra, FlashOdds[TransparentAssCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsUltra], "{0}%", False, "AND_TransparentAssCurtainUltraOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOddsExtreme] <= 95
			FlashOdds[TransparentAssCurtainOddsUltra] = 95
		Else
			FlashOdds[TransparentAssCurtainOddsUltra] = FlashOdds[TransparentAssCurtainOddsExtreme]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsUltra, FlashOdds[TransparentAssCurtainOddsUltra])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsUltra], "{0}%", False, "AND_TransparentAssCurtainUltraOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_TransparentAssCurtainUltraOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentAssCurtainOddsUltra_Male])
		If FlashOdds[TransparentAssCurtainOddsExtreme_Male] <= 95
			SetSliderDialogDefaultValue(95)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentAssCurtainOddsExtreme_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentAssCurtainOddsExtreme_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentAssCurtainOddsUltra_Male] = value as Int
		UpdateFlashingOdds(TransparentAssCurtainOddsUltra_Male, FlashOdds[TransparentAssCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsUltra_Male], "{0}%", False, "AND_TransparentAssCurtainUltraOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentAssCurtainOddsExtreme_Male] <= 95
			FlashOdds[TransparentAssCurtainOddsUltra_Male] = 95
		Else
			FlashOdds[TransparentAssCurtainOddsUltra_Male] = FlashOdds[TransparentAssCurtainOddsExtreme_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentAssCurtainOddsUltra_Male, FlashOdds[TransparentAssCurtainOddsUltra_Male])
		SetSliderOptionValueST(FlashOdds[TransparentAssCurtainOddsUltra_Male], "{0}%", False, "AND_TransparentAssCurtainUltraOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentAssCurtainOddsUltra_InfoText")
	EndEvent
EndState

State AND_CStringOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[CStringOdds])
		If FlashOdds[TransparentCStringOdds_Low] >= 60
			SetSliderDialogDefaultValue(60)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_Low])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentCStringOdds_Low])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[CStringOdds] = value as Int
		UpdateFlashingOdds(CStringOdds, FlashOdds[CStringOdds])
		SetSliderOptionValueST(FlashOdds[CStringOdds], "{0}%", False, "AND_CStringOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentCStringOdds_Low] >= 60
			FlashOdds[CStringOdds] = 60
		Else
			FlashOdds[CStringOdds] = FlashOdds[TransparentCStringOdds_Low]
		EndIf
		
		UpdateFlashingOdds(CStringOdds, FlashOdds[CStringOdds])
		SetSliderOptionValueST(FlashOdds[CStringOdds], "{0}%", False, "AND_CStringOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_CstringOdds_InfoText")
	EndEvent
EndState

State AND_CStringOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[CStringOdds_Male])
		If FlashOdds[TransparentCStringOdds_Low_Male] >= 60
			SetSliderDialogDefaultValue(60)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_Low_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentCStringOdds_Low_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[CStringOdds_Male] = value as Int
		UpdateFlashingOdds(CStringOdds_Male, FlashOdds[CStringOdds_Male])
		SetSliderOptionValueST(FlashOdds[CStringOdds_Male], "{0}%", False, "AND_CStringOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentCStringOdds_Low_Male] >= 60
			FlashOdds[CStringOdds_Male] = 60
		Else
			FlashOdds[CStringOdds_Male] = FlashOdds[TransparentCStringOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(CStringOdds_Male, FlashOdds[CStringOdds_Male])
		SetSliderOptionValueST(FlashOdds[CStringOdds_Male], "{0}%", False, "AND_CStringOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_CstringOdds_InfoText")
	EndEvent
EndState

State AND_TransparentCStringOddsLow
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentCStringOdds_Low])
		If FlashOdds[CStringOdds] <= 70 && FlashOdds[TransparentCStringOdds] >= 70
			SetSliderDialogDefaultValue(70)
		ElseIf FlashOdds[TransparentCStringOdds] < 70
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds])
		Else
			SetSliderDialogDefaultValue(FlashOdds[CStringOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[CStringOdds], FlashOdds[TransparentCStringOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentCStringOdds_Low] = value as Int
		UpdateFlashingOdds(TransparentCStringOdds_Low, FlashOdds[TransparentCStringOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_Low], "{0}%", False, "AND_TransparentCStringOddsLow")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[CStringOdds] <= 70 && FlashOdds[TransparentCStringOdds] >= 70
			FlashOdds[TransparentCStringOdds_Low] = 70
		ElseIf FlashOdds[TransparentCStringOdds] < 70
			FlashOdds[TransparentCStringOdds_Low] = FlashOdds[TransparentCStringOdds]
		Else
			FlashOdds[TransparentCStringOdds_Low] = FlashOdds[CStringOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentCStringOdds_Low, FlashOdds[TransparentCStringOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_Low], "{0}%", False, "AND_TransparentCStringOddsLow")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentCstringOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentCStringOddsLowMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentCStringOdds_Low_Male])
		If FlashOdds[CStringOdds_Male] <= 70 && FlashOdds[TransparentCStringOdds_Male] >= 70
			SetSliderDialogDefaultValue(70)
		ElseIf FlashOdds[TransparentCStringOdds_Male] < 70
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[CStringOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[CStringOdds_Male], FlashOdds[TransparentCStringOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentCStringOdds_Low_Male] = value as Int
		UpdateFlashingOdds(TransparentCStringOdds_Low_Male, FlashOdds[TransparentCStringOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_Low_Male], "{0}%", False, "AND_TransparentCStringOddsLowMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[CStringOdds_Male] <= 70 && FlashOdds[TransparentCStringOdds_Male] >= 70
			FlashOdds[TransparentCStringOdds_Low_Male] = 70
		ElseIf FlashOdds[TransparentCStringOdds_Male] < 70
			FlashOdds[TransparentCStringOdds_Low_Male] = FlashOdds[TransparentCStringOdds_Male]
		Else
			FlashOdds[TransparentCStringOdds_Low_Male] = FlashOdds[CStringOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentCStringOdds_Low_Male, FlashOdds[TransparentCStringOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_Low_Male], "{0}%", False, "AND_TransparentCStringOddsLowMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentCstringOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentCStringOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentCStringOdds])
		If FlashOdds[TransparentCStringOdds_Low] <= 80 && FlashOdds[TransparentCStringOdds_High] >= 80
			SetSliderDialogDefaultValue(80)
		ElseIf FlashOdds[TransparentCStringOdds_High] < 80
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_High])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_Low])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentCStringOdds_Low], FlashOdds[TransparentCStringOdds_High])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentCStringOdds] = value as Int
		UpdateFlashingOdds(TransparentCStringOdds, FlashOdds[TransparentCStringOdds])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds], "{0}%", False, "AND_TransparentCStringOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentCStringOdds_Low] <= 80 && FlashOdds[TransparentCStringOdds_High] >= 80
			FlashOdds[TransparentCStringOdds] = 80
		ElseIf FlashOdds[TransparentCStringOdds_High] < 80
			FlashOdds[TransparentCStringOdds] = FlashOdds[TransparentCStringOdds_High]
		Else
			FlashOdds[TransparentCStringOdds] = FlashOdds[TransparentCStringOdds_Low]
		EndIf
		
		UpdateFlashingOdds(TransparentCStringOdds, FlashOdds[TransparentCStringOdds])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds], "{0}%", False, "AND_TransparentCStringOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentCstringOdds_InfoText")
	EndEvent
EndState

State AND_TransparentCStringOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentCStringOdds_Male])
		If FlashOdds[TransparentCStringOdds_Low_Male] <= 80 && FlashOdds[TransparentCStringOdds_High_Male] >= 80
			SetSliderDialogDefaultValue(80)
		ElseIf FlashOdds[TransparentCStringOdds_High_Male] < 80
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_High_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_Low_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentCStringOdds_Low_Male], FlashOdds[TransparentCStringOdds_High_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentCStringOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentCStringOdds_Male, FlashOdds[TransparentCStringOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_Male], "{0}%", False, "AND_TransparentCStringOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentCStringOdds_Low_Male] <= 80 && FlashOdds[TransparentCStringOdds_High_Male] >= 80
			FlashOdds[TransparentCStringOdds_Male] = 80
		ElseIf FlashOdds[TransparentCStringOdds_High_Male] < 80
			FlashOdds[TransparentCStringOdds_Male] = FlashOdds[TransparentCStringOdds_High_Male]
		Else
			FlashOdds[TransparentCStringOdds_Male] = FlashOdds[TransparentCStringOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentCStringOdds_Male, FlashOdds[TransparentCStringOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_Male], "{0}%", False, "AND_TransparentCStringOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentCstringOdds_InfoText")
	EndEvent
EndState

State AND_TransparentCStringOddsHigh
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentCStringOdds_High])
		If FlashOdds[TransparentCStringOdds] <= 90
			SetSliderDialogDefaultValue(90)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentCStringOdds], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentCStringOdds_High] = value as Int
		UpdateFlashingOdds(TransparentCStringOdds_High, FlashOdds[TransparentCStringOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_High], "{0}%", False, "AND_TransparentCStringOddsHigh")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentCStringOdds] <= 90
			FlashOdds[TransparentCStringOdds_High] = 90
		Else
			FlashOdds[TransparentCStringOdds_High] = FlashOdds[TransparentCStringOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentCStringOdds_High, FlashOdds[TransparentCStringOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_High], "{0}%", False, "AND_TransparentCStringOddsHigh")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentCstringOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentCStringOddsHighMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentCStringOdds_High_Male])
		If FlashOdds[TransparentCStringOdds_Male] <= 90
			SetSliderDialogDefaultValue(90)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentCStringOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentCStringOdds_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentCStringOdds_High_Male] = value as Int
		UpdateFlashingOdds(TransparentCStringOdds_High_Male, FlashOdds[TransparentCStringOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_High_Male], "{0}%", False, "AND_TransparentCStringOddsHighMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentCStringOdds_Male] <= 90
			FlashOdds[TransparentCStringOdds_High_Male] = 90
		Else
			FlashOdds[TransparentCStringOdds_High_Male] = FlashOdds[TransparentCStringOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentCStringOdds_High_Male, FlashOdds[TransparentCStringOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentCStringOdds_High_Male], "{0}%", False, "AND_TransparentCStringOddsHighMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentCstringOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentTopArmorOddsLow
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentTopArmorOdds_Low])
		If FlashOdds[TransparentTopArmorOdds] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentTopArmorOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentTopArmorOdds_Low] = value as Int
		UpdateFlashingOdds(TransparentTopArmorOdds_Low, FlashOdds[TransparentTopArmorOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_Low], "{0}%", False, "AND_TransparentTopArmorOddsLow")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentTopArmorOdds] >= 30
			FlashOdds[TransparentTopArmorOdds_Low] = 30
		Else
			FlashOdds[TransparentTopArmorOdds_Low] = FlashOdds[TransparentTopArmorOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentTopArmorOdds_Low, FlashOdds[TransparentTopArmorOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_Low], "{0}%", False, "AND_TransparentTopArmorOddsLow")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorTopOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentTopArmorOddsLowMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentTopArmorOdds_Low_Male])
		If FlashOdds[TransparentTopArmorOdds_Male] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentTopArmorOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentTopArmorOdds_Low_Male] = value as Int
		UpdateFlashingOdds(TransparentTopArmorOdds_Low_Male, FlashOdds[TransparentTopArmorOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_Low_Male], "{0}%", False, "AND_TransparentTopArmorOddsLowMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentTopArmorOdds_Male] >= 30
			FlashOdds[TransparentTopArmorOdds_Low_Male] = 30
		Else
			FlashOdds[TransparentTopArmorOdds_Low_Male] = FlashOdds[TransparentTopArmorOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentTopArmorOdds_Low_Male, FlashOdds[TransparentTopArmorOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_Low_Male], "{0}%", False, "AND_TransparentTopArmorOddsLowMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorTopOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentTopArmorOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentTopArmorOdds])
		If FlashOdds[TransparentTopArmorOdds_Low] <= 50 && FlashOdds[TransparentTopArmorOdds_High] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentTopArmorOdds_High] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds_High])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds_Low])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentTopArmorOdds_Low], FlashOdds[TransparentTopArmorOdds_High])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentTopArmorOdds] = value as Int
		UpdateFlashingOdds(TransparentTopArmorOdds, FlashOdds[TransparentTopArmorOdds])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds], "{0}%", False, "AND_TransparentTopArmorOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentTopArmorOdds_Low] <= 50 && FlashOdds[TransparentTopArmorOdds_High] >= 50
			FlashOdds[TransparentTopArmorOdds] = 50
		ElseIf FlashOdds[TransparentTopArmorOdds_High] < 50
			FlashOdds[TransparentTopArmorOdds] = FlashOdds[TransparentTopArmorOdds_High]
		Else
			FlashOdds[TransparentTopArmorOdds] = FlashOdds[TransparentTopArmorOdds_Low]
		EndIf
		
		UpdateFlashingOdds(TransparentTopArmorOdds, FlashOdds[TransparentTopArmorOdds])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds], "{0}%", False, "AND_TransparentTopArmorOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorTopOdds_InfoText")
	EndEvent
EndState

State AND_TransparentTopArmorOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentTopArmorOdds_Male])
		If FlashOdds[TransparentTopArmorOdds_Low_Male] <= 50 && FlashOdds[TransparentTopArmorOdds_High_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentTopArmorOdds_High_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds_High_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds_Low_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentTopArmorOdds_Low_Male], FlashOdds[TransparentTopArmorOdds_High_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentTopArmorOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentTopArmorOdds_Male, FlashOdds[TransparentTopArmorOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_Male], "{0}%", False, "AND_TransparentTopArmorOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentTopArmorOdds_Low_Male] <= 50 && FlashOdds[TransparentTopArmorOdds_High_Male] >= 50
			FlashOdds[TransparentTopArmorOdds_Male] = 50
		ElseIf FlashOdds[TransparentTopArmorOdds_High_Male] < 50
			FlashOdds[TransparentTopArmorOdds_Male] = FlashOdds[TransparentTopArmorOdds_High_Male]
		Else
			FlashOdds[TransparentTopArmorOdds_Male] = FlashOdds[TransparentTopArmorOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentTopArmorOdds_Male, FlashOdds[TransparentTopArmorOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_Male], "{0}%", False, "AND_TransparentTopArmorOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorTopOdds_InfoText")
	EndEvent
EndState

State AND_TransparentTopArmorOddsHigh
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentTopArmorOdds_High])
		If FlashOdds[TransparentTopArmorOdds] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentTopArmorOdds], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentTopArmorOdds_High] = value as Int
		UpdateFlashingOdds(TransparentTopArmorOdds_High, FlashOdds[TransparentTopArmorOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_High], "{0}%", False, "AND_TransparentTopArmorOddsHigh")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentTopArmorOdds] <= 70
			FlashOdds[TransparentTopArmorOdds_High] = 70
		Else
			FlashOdds[TransparentTopArmorOdds_High] = FlashOdds[TransparentTopArmorOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentTopArmorOdds_High, FlashOdds[TransparentTopArmorOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_High], "{0}%", False, "AND_TransparentTopArmorOddsHigh")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorTopOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentTopArmorOddsHighMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentTopArmorOdds_High_Male])
		If FlashOdds[TransparentTopArmorOdds_Male] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentTopArmorOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentTopArmorOdds_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentTopArmorOdds_High_Male] = value as Int
		UpdateFlashingOdds(TransparentTopArmorOdds_High_Male, FlashOdds[TransparentTopArmorOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_High_Male], "{0}%", False, "AND_TransparentTopArmorOddsHighMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentTopArmorOdds_Male] <= 70
			FlashOdds[TransparentTopArmorOdds_High_Male] = 70
		Else
			FlashOdds[TransparentTopArmorOdds_High_Male] = FlashOdds[TransparentTopArmorOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentTopArmorOdds_High_Male, FlashOdds[TransparentTopArmorOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentTopArmorOdds_High_Male], "{0}%", False, "AND_TransparentTopArmorOddsHighMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorTopOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentBottomArmorOddsLow
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBottomArmorOdds_Low])
		If FlashOdds[TransparentBottomArmorOdds] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentBottomArmorOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBottomArmorOdds_Low] = value as Int
		UpdateFlashingOdds(TransparentBottomArmorOdds_Low, FlashOdds[TransparentBottomArmorOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_Low], "{0}%", False, "AND_TransparentBottomArmorOddsLow")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBottomArmorOdds] >= 30
			FlashOdds[TransparentBottomArmorOdds_Low] = 30
		Else
			FlashOdds[TransparentBottomArmorOdds_Low] = FlashOdds[TransparentBottomArmorOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentBottomArmorOdds_Low, FlashOdds[TransparentBottomArmorOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_Low], "{0}%", False, "AND_TransparentBottomArmorOddsLow")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorBottomOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentBottomArmorOddsLowMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBottomArmorOdds_Low_Male])
		If FlashOdds[TransparentBottomArmorOdds_Male] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentBottomArmorOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBottomArmorOdds_Low_Male] = value as Int
		UpdateFlashingOdds(TransparentBottomArmorOdds_Low_Male, FlashOdds[TransparentBottomArmorOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_Low_Male], "{0}%", False, "AND_TransparentBottomArmorOddsLowMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBottomArmorOdds_Male] >= 30
			FlashOdds[TransparentBottomArmorOdds_Low_Male] = 30
		Else
			FlashOdds[TransparentBottomArmorOdds_Low_Male] = FlashOdds[TransparentBottomArmorOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentBottomArmorOdds_Low_Male, FlashOdds[TransparentBottomArmorOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_Low_Male], "{0}%", False, "AND_TransparentBottomArmorOddsLowMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorBottomOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentBottomArmorOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBottomArmorOdds])
		If FlashOdds[TransparentBottomArmorOdds_Low] <= 50 && FlashOdds[TransparentBottomArmorOdds_High] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentBottomArmorOdds_High] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds_High])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds_Low])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBottomArmorOdds_Low], FlashOdds[TransparentBottomArmorOdds_High])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBottomArmorOdds] = value as Int
		UpdateFlashingOdds(TransparentBottomArmorOdds, FlashOdds[TransparentBottomArmorOdds])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds], "{0}%", False, "AND_TransparentBottomArmorOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBottomArmorOdds_Low] <= 50 && FlashOdds[TransparentBottomArmorOdds_High] >= 50
			FlashOdds[TransparentBottomArmorOdds] = 50
		ElseIf FlashOdds[TransparentBottomArmorOdds_High] < 50
			FlashOdds[TransparentBottomArmorOdds] = FlashOdds[TransparentBottomArmorOdds_High]
		Else
			FlashOdds[TransparentBottomArmorOdds] = FlashOdds[TransparentBottomArmorOdds_Low]
		EndIf
		
		UpdateFlashingOdds(TransparentBottomArmorOdds, FlashOdds[TransparentBottomArmorOdds])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds], "{0}%", False, "AND_TransparentBottomArmorOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorBottomOdds_InfoText")
	EndEvent
EndState

State AND_TransparentBottomArmorOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBottomArmorOdds_Male])
		If FlashOdds[TransparentBottomArmorOdds_Low_Male] <= 50 && FlashOdds[TransparentBottomArmorOdds_High_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentBottomArmorOdds_High_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds_High_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds_Low_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBottomArmorOdds_Low_Male], FlashOdds[TransparentBottomArmorOdds_High_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBottomArmorOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentBottomArmorOdds_Male, FlashOdds[TransparentBottomArmorOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_Male], "{0}%", False, "AND_TransparentBottomArmorOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBottomArmorOdds_Low_Male] <= 50 && FlashOdds[TransparentBottomArmorOdds_High_Male] >= 50
			FlashOdds[TransparentBottomArmorOdds_Male] = 50
		ElseIf FlashOdds[TransparentBottomArmorOdds_High_Male] < 50
			FlashOdds[TransparentBottomArmorOdds_Male] = FlashOdds[TransparentBottomArmorOdds_High_Male]
		Else
			FlashOdds[TransparentBottomArmorOdds_Male] = FlashOdds[TransparentBottomArmorOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentBottomArmorOdds_Male, FlashOdds[TransparentBottomArmorOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_Male], "{0}%", False, "AND_TransparentBottomArmorOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorBottomOdds_InfoText")
	EndEvent
EndState

State AND_TransparentBottomArmorOddsHigh
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBottomArmorOdds_High])
		If FlashOdds[TransparentBottomArmorOdds] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBottomArmorOdds], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBottomArmorOdds_High] = value as Int
		UpdateFlashingOdds(TransparentBottomArmorOdds_High, FlashOdds[TransparentBottomArmorOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_High], "{0}%", False, "AND_TransparentBottomArmorOddsHigh")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBottomArmorOdds] <= 70
			FlashOdds[TransparentBottomArmorOdds_High] = 70
		Else
			FlashOdds[TransparentBottomArmorOdds_High] = FlashOdds[TransparentBottomArmorOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentBottomArmorOdds_High, FlashOdds[TransparentBottomArmorOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_High], "{0}%", False, "AND_TransparentBottomArmorOddsHigh")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorBottomOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentBottomArmorOddsHighMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBottomArmorOdds_High_Male])
		If FlashOdds[TransparentBottomArmorOdds_Male] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBottomArmorOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBottomArmorOdds_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBottomArmorOdds_High_Male] = value as Int
		UpdateFlashingOdds(TransparentBottomArmorOdds_High_Male, FlashOdds[TransparentBottomArmorOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_High_Male], "{0}%", False, "AND_TransparentBottomArmorOddsHighMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBottomArmorOdds_Male] <= 70
			FlashOdds[TransparentBottomArmorOdds_High_Male] = 70
		Else
			FlashOdds[TransparentBottomArmorOdds_High_Male] = FlashOdds[TransparentBottomArmorOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentBottomArmorOdds_High_Male, FlashOdds[TransparentBottomArmorOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBottomArmorOdds_High_Male], "{0}%", False, "AND_TransparentBottomArmorOddsHighMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentArmorBottomOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentBraOddsLow
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBraOdds_Low])
		If FlashOdds[TransparentBraOdds] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentBraOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBraOdds_Low] = value as Int
		UpdateFlashingOdds(TransparentBraOdds_Low, FlashOdds[TransparentBraOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_Low], "{0}%", False, "AND_TransparentBraOddsLow")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBraOdds] >= 30
			FlashOdds[TransparentBraOdds_Low] = 30
		Else
			FlashOdds[TransparentBraOdds_Low] = FlashOdds[TransparentBraOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentBraOdds_Low, FlashOdds[TransparentBraOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_Low], "{0}%", False, "AND_TransparentBraOddsLow")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentBraOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentBraOddsLowMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBraOdds_Low_Male])
		If FlashOdds[TransparentBraOdds_Male] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentBraOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBraOdds_Low_Male] = value as Int
		UpdateFlashingOdds(TransparentBraOdds_Low_Male, FlashOdds[TransparentBraOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_Low_Male], "{0}%", False, "AND_TransparentBraOddsLowMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBraOdds_Male] >= 30
			FlashOdds[TransparentBraOdds_Low_Male] = 30
		Else
			FlashOdds[TransparentBraOdds_Low_Male] = FlashOdds[TransparentBraOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentBraOdds_Low_Male, FlashOdds[TransparentBraOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_Low_Male], "{0}%", False, "AND_TransparentBraOddsLowMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentBraOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentBraOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBraOdds])
		If FlashOdds[TransparentBraOdds_Low] <= 50 && FlashOdds[TransparentBraOdds_High] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentBraOdds_High] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds_High])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds_Low])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBraOdds_Low], FlashOdds[TransparentBraOdds_High])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBraOdds] = value as Int
		UpdateFlashingOdds(TransparentBraOdds, FlashOdds[TransparentBraOdds])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds], "{0}%", False, "AND_TransparentBraOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBraOdds_Low] <= 50 && FlashOdds[TransparentBraOdds_High] >= 50
			FlashOdds[TransparentBraOdds] = 50
		ElseIf FlashOdds[TransparentBraOdds_High] < 50
			FlashOdds[TransparentBraOdds] = FlashOdds[TransparentBraOdds_High]
		Else
			FlashOdds[TransparentBraOdds] = FlashOdds[TransparentBraOdds_Low]
		EndIf
		
		UpdateFlashingOdds(TransparentBraOdds, FlashOdds[TransparentBraOdds])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds], "{0}%", False, "AND_TransparentBraOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentBraOdds_InfoText")
	EndEvent
EndState

State AND_TransparentBraOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBraOdds_Male])
		If FlashOdds[TransparentBraOdds_Low_Male] <= 50 && FlashOdds[TransparentBraOdds_High_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentBraOdds_High_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds_High_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds_Low_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBraOdds_Low_Male], FlashOdds[TransparentBraOdds_High_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBraOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentBraOdds_Male, FlashOdds[TransparentBraOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_Male], "{0}%", False, "AND_TransparentBraOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBraOdds_Low_Male] <= 50 && FlashOdds[TransparentBraOdds_High_Male] >= 50
			FlashOdds[TransparentBraOdds_Male] = 50
		ElseIf FlashOdds[TransparentBraOdds_High_Male] < 50
			FlashOdds[TransparentBraOdds_Male] = FlashOdds[TransparentBraOdds_High_Male]
		Else
			FlashOdds[TransparentBraOdds_Male] = FlashOdds[TransparentBraOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentBraOdds_Male, FlashOdds[TransparentBraOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_Male], "{0}%", False, "AND_TransparentBraOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentBraOdds_InfoText")
	EndEvent
EndState

State AND_TransparentBraOddsHigh
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBraOdds_High])
		If FlashOdds[TransparentBraOdds] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBraOdds], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBraOdds_High] = value as Int
		UpdateFlashingOdds(TransparentBraOdds_High, FlashOdds[TransparentBraOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_High], "{0}%", False, "AND_TransparentBraOddsHigh")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBraOdds] <= 70
			FlashOdds[TransparentBraOdds_High] = 70
		Else
			FlashOdds[TransparentBraOdds_High] = FlashOdds[TransparentBraOdds]
		EndIf
		UpdateFlashingOdds(TransparentBraOdds_High, FlashOdds[TransparentBraOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_High], "{0}%", False, "AND_TransparentBraOddsHigh")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentBraOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentBraOddsHighMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentBraOdds_High_Male])
		If FlashOdds[TransparentBraOdds_Male] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentBraOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentBraOdds_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentBraOdds_High_Male] = value as Int
		UpdateFlashingOdds(TransparentBraOdds_High_Male, FlashOdds[TransparentBraOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_High_Male], "{0}%", False, "AND_TransparentBraOddsHighMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentBraOdds_Male] <= 70
			FlashOdds[TransparentBraOdds_High_Male] = 70
		Else
			FlashOdds[TransparentBraOdds_High_Male] = FlashOdds[TransparentBraOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentBraOdds_High_Male, FlashOdds[TransparentBraOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentBraOdds_High_Male], "{0}%", False, "AND_TransparentBraOddsHighMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentBraOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentUnderwearOddsLow
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentUnderwearOdds_Low])
		If FlashOdds[TransparentUnderwearOdds] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentUnderwearOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentUnderwearOdds_Low] = value as Int
		UpdateFlashingOdds(TransparentUnderwearOdds_Low, FlashOdds[TransparentUnderwearOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_Low], "{0}%", False, "AND_TransparentUnderwearOddsLow")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentUnderwearOdds] >= 30
			FlashOdds[TransparentUnderwearOdds_Low] = 30
		Else
			FlashOdds[TransparentUnderwearOdds_Low] = FlashOdds[TransparentUnderwearOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentUnderwearOdds_Low, FlashOdds[TransparentUnderwearOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_Low], "{0}%", False, "AND_TransparentUnderwearOddsLow")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentUnderwearOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentUnderwearOddsLowMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentUnderwearOdds_Low_Male])
		If FlashOdds[TransparentUnderwearOdds] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentUnderwearOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentUnderwearOdds_Low_Male] = value as Int
		UpdateFlashingOdds(TransparentUnderwearOdds_Low_Male, FlashOdds[TransparentUnderwearOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_Low_Male], "{0}%", False, "AND_TransparentUnderwearOddsLowMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentUnderwearOdds_Male] >= 30
			FlashOdds[TransparentUnderwearOdds_Low_Male] = 30
		Else
			FlashOdds[TransparentUnderwearOdds_Low_Male] = FlashOdds[TransparentUnderwearOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentUnderwearOdds_Low_Male, FlashOdds[TransparentUnderwearOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_Low_Male], "{0}%", False, "AND_TransparentUnderwearOddsLowMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentUnderwearOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentUnderwearOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentUnderwearOdds])
		If FlashOdds[TransparentUnderwearOdds_Low] <= 50 && FlashOdds[TransparentUnderwearOdds_High] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentUnderwearOdds_High] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds_High])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds_Low])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentUnderwearOdds_Low], FlashOdds[TransparentUnderwearOdds_High])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentUnderwearOdds] = value as Int
		UpdateFlashingOdds(TransparentUnderwearOdds, FlashOdds[TransparentUnderwearOdds])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds], "{0}%", False, "AND_TransparentUnderwearOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentUnderwearOdds_Low] <= 50 && FlashOdds[TransparentUnderwearOdds_High] >= 50
			FlashOdds[TransparentUnderwearOdds] = 50
		ElseIf FlashOdds[TransparentUnderwearOdds_High] < 50
			FlashOdds[TransparentUnderwearOdds] = FlashOdds[TransparentUnderwearOdds_High]
		Else
			FlashOdds[TransparentUnderwearOdds] = FlashOdds[TransparentUnderwearOdds_Low]
		EndIf
		
		UpdateFlashingOdds(TransparentUnderwearOdds, FlashOdds[TransparentUnderwearOdds])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds], "{0}%", False, "AND_TransparentUnderwearOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentUnderwearOdds_InfoText")
	EndEvent
EndState

State AND_TransparentUnderwearOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentUnderwearOdds_Male])
		If FlashOdds[TransparentUnderwearOdds_Low_Male] <= 50 && FlashOdds[TransparentUnderwearOdds_High_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentUnderwearOdds_High_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds_High_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds_Low_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentUnderwearOdds_Low_Male], FlashOdds[TransparentUnderwearOdds_High_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentUnderwearOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentUnderwearOdds_Male, FlashOdds[TransparentUnderwearOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_Male], "{0}%", False, "AND_TransparentUnderwearOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentUnderwearOdds_Low_Male] <= 50 && FlashOdds[TransparentUnderwearOdds_High_Male] >= 50
			FlashOdds[TransparentUnderwearOdds_Male] = 50
		ElseIf FlashOdds[TransparentUnderwearOdds_High_Male] < 50
			FlashOdds[TransparentUnderwearOdds_Male] = FlashOdds[TransparentUnderwearOdds_High_Male]
		Else
			FlashOdds[TransparentUnderwearOdds_Male] = FlashOdds[TransparentUnderwearOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentUnderwearOdds_Male, FlashOdds[TransparentUnderwearOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_Male], "{0}%", False, "AND_TransparentUnderwearOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentUnderwearOdds_InfoText")
	EndEvent
EndState

State AND_TransparentUnderwearOddsHigh
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentUnderwearOdds_High])
		If FlashOdds[TransparentUnderwearOdds] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentUnderwearOdds], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentUnderwearOdds_High] = value as Int
		UpdateFlashingOdds(transparentunderwearodds_High, FlashOdds[TransparentUnderwearOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_High], "{0}%", False, "AND_TransparentUnderwearOddsHigh")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentUnderwearOdds] <= 70
			FlashOdds[TransparentUnderwearOdds_High] = 70
		Else
			FlashOdds[TransparentUnderwearOdds_High] = FlashOdds[TransparentUnderwearOdds]
		EndIf
		
		UpdateFlashingOdds(transparentunderwearodds_High, FlashOdds[TransparentUnderwearOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_High], "{0}%", False, "AND_TransparentUnderwearOddsHigh")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentUnderwearOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentUnderwearOddsHighMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentUnderwearOdds_High_Male])
		If FlashOdds[TransparentUnderwearOdds_Male] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentUnderwearOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentUnderwearOdds_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentUnderwearOdds_High_Male] = value as Int
		UpdateFlashingOdds(TransparentUnderwearOdds_High_Male, FlashOdds[TransparentUnderwearOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_High_Male], "{0}%", False, "AND_TransparentUnderwearOddsHighMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentUnderwearOdds_Male] <= 70
			FlashOdds[TransparentUnderwearOdds_High_Male] = 70
		Else
			FlashOdds[TransparentUnderwearOdds_High_Male] = FlashOdds[TransparentUnderwearOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentUnderwearOdds_High_Male, FlashOdds[TransparentUnderwearOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentUnderwearOdds_High_Male], "{0}%", False, "AND_TransparentUnderwearOddsHighMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentUnderwearOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentHotpantsOddsLow
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentHotpantsOdds_Low])
		If FlashOdds[TransparentHotpantsOdds] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentHotpantsOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentHotpantsOdds_Low] = value as Int
		UpdateFlashingOdds(TransparentHotpantsOdds_Low, FlashOdds[TransparentHotpantsOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_Low], "{0}%", False, "AND_TransparentHotpantsOddsLow")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentHotpantsOdds] >= 30
			FlashOdds[TransparentHotpantsOdds_Low] = 30
		Else
			FlashOdds[TransparentHotpantsOdds_Low] = FlashOdds[TransparentHotpantsOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentHotpantsOdds_Low, FlashOdds[TransparentHotpantsOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_Low], "{0}%", False, "AND_TransparentHotpantsOddsLow")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentHotpantsOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentHotpantsOddsLowMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentHotpantsOdds_Low_Male])
		If FlashOdds[TransparentHotpantsOdds_Male] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentHotpantsOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentHotpantsOdds_Low_Male] = value as Int
		UpdateFlashingOdds(TransparentHotpantsOdds_Low_Male, FlashOdds[TransparentHotpantsOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_Low_Male], "{0}%", False, "AND_TransparentHotpantsOddsLowMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentHotpantsOdds_Male] >= 30
			FlashOdds[TransparentHotpantsOdds_Low_Male] = 30
		Else
			FlashOdds[TransparentHotpantsOdds_Low_Male] = FlashOdds[TransparentHotpantsOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentHotpantsOdds_Low_Male, FlashOdds[TransparentHotpantsOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_Low_Male], "{0}%", False, "AND_TransparentHotpantsOddsLowMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentHotpantsOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentHotpantsOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentHotpantsOdds])
		If FlashOdds[TransparentHotpantsOdds_Low] <= 50 && FlashOdds[TransparentHotpantsOdds_High] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentHotpantsOdds_High] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds_High])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds_Low])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentHotpantsOdds_Low], FlashOdds[TransparentHotpantsOdds_High])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentHotpantsOdds] = value as Int
		UpdateFlashingOdds(TransparentHotpantsOdds, FlashOdds[TransparentHotpantsOdds])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds], "{0}%", False, "AND_TransparentHotpantsOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentHotpantsOdds_Low] <= 50 && FlashOdds[TransparentHotpantsOdds_High] >= 50
			FlashOdds[TransparentHotpantsOdds] = 50
		ElseIf FlashOdds[TransparentHotpantsOdds_High] < 50
			FlashOdds[TransparentHotpantsOdds] = FlashOdds[TransparentHotpantsOdds_High]
		Else
			FlashOdds[TransparentHotpantsOdds] = FlashOdds[TransparentHotpantsOdds_Low]
		EndIf
		
		UpdateFlashingOdds(TransparentHotpantsOdds, FlashOdds[TransparentHotpantsOdds])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds], "{0}%", False, "AND_TransparentHotpantsOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentHotpantsOdds_InfoText")
	EndEvent
EndState

State AND_TransparentHotpantsOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentHotpantsOdds_Male])
		If FlashOdds[TransparentHotpantsOdds_Low_Male] <= 50 && FlashOdds[TransparentHotpantsOdds_High_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentHotpantsOdds_High_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds_High_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds_Low_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentHotpantsOdds_Low_Male], FlashOdds[TransparentHotpantsOdds_High_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentHotpantsOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentHotpantsOdds_Male, FlashOdds[TransparentHotpantsOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_Male], "{0}%", False, "AND_TransparentHotpantsOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentHotpantsOdds_Low_Male] <= 50 && FlashOdds[TransparentHotpantsOdds_High_Male] >= 50
			FlashOdds[TransparentHotpantsOdds_Male] = 50
		ElseIf FlashOdds[TransparentHotpantsOdds_High_Male] < 50
			FlashOdds[TransparentHotpantsOdds_Male] = FlashOdds[TransparentHotpantsOdds_High_Male]
		Else
			FlashOdds[TransparentHotpantsOdds_Male] = FlashOdds[TransparentHotpantsOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentHotpantsOdds_Male, FlashOdds[TransparentHotpantsOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_Male], "{0}%", False, "AND_TransparentHotpantsOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentHotpantsOdds_InfoText")
	EndEvent
EndState

State AND_TransparentHotpantsOddsHigh
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentHotpantsOdds_High])
		If FlashOdds[TransparentHotpantsOdds] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentHotpantsOdds], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentHotpantsOdds_High] = value as Int
		UpdateFlashingOdds(TransparentHotpantsOdds_High, FlashOdds[TransparentHotpantsOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_High], "{0}%", False, "AND_TransparentHotpantsOddsHigh")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentHotpantsOdds] <= 70
			FlashOdds[TransparentHotpantsOdds_High] = 70
		Else
			FlashOdds[TransparentHotpantsOdds_High] = FlashOdds[TransparentHotpantsOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentHotpantsOdds_High, FlashOdds[TransparentHotpantsOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_High], "{0}%", False, "AND_TransparentHotpantsOddsHigh")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentHotpantsOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentHotpantsOddsHighMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentHotpantsOdds_High_Male])
		If FlashOdds[TransparentHotpantsOdds_Male] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentHotpantsOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentHotpantsOdds_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentHotpantsOdds_High_Male] = value as Int
		UpdateFlashingOdds(TransparentHotpantsOdds_High_Male, FlashOdds[TransparentHotpantsOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_High_Male], "{0}%", False, "AND_TransparentHotpantsOddsHighMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentHotpantsOdds_Male] <= 70
			FlashOdds[TransparentHotpantsOdds_High_Male] = 70
		Else
			FlashOdds[TransparentHotpantsOdds_High_Male] = FlashOdds[TransparentHotpantsOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentHotpantsOdds_High_Male, FlashOdds[TransparentHotpantsOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentHotpantsOdds_High_Male], "{0}%", False, "AND_TransparentHotpantsOddsHighMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentHotpantsOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentShowgirlSkirtOddsLow
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentShowgirlSkirtOdds_Low])
		If FlashOdds[TransparentShowgirlSkirtOdds] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentShowgirlSkirtOdds])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentShowgirlSkirtOdds_Low] = value as Int
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_Low, FlashOdds[TransparentShowgirlSkirtOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_Low], "{0}%", False, "AND_TransparentShowgirlSkirtOddsLow")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentShowgirlSkirtOdds] >= 30
			FlashOdds[TransparentShowgirlSkirtOdds_Low] = 30
		Else
			FlashOdds[TransparentShowgirlSkirtOdds_Low] = FlashOdds[TransparentShowgirlSkirtOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_Low, FlashOdds[TransparentShowgirlSkirtOdds_Low])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_Low], "{0}%", False, "AND_TransparentShowgirlSkirtOddsLow")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentShowgirlSkirtOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentShowgirlSkirtOddsLowMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentShowgirlSkirtOdds_Low_Male])
		If FlashOdds[TransparentShowgirlSkirtOdds_Male] >= 30
			SetSliderDialogDefaultValue(30)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds_Male])
		EndIf
		SetSliderDialogRange(1, FlashOdds[TransparentShowgirlSkirtOdds_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentShowgirlSkirtOdds_Low_Male] = value as Int
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_Low_Male, FlashOdds[TransparentShowgirlSkirtOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_Low_Male], "{0}%", False, "AND_TransparentShowgirlSkirtOddsLowMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentShowgirlSkirtOdds_Male] >= 30
			FlashOdds[TransparentShowgirlSkirtOdds_Low_Male] = 30
		Else
			FlashOdds[TransparentShowgirlSkirtOdds_Low_Male] = FlashOdds[TransparentShowgirlSkirtOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_Low_Male, FlashOdds[TransparentShowgirlSkirtOdds_Low_Male])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_Low_Male], "{0}%", False, "AND_TransparentShowgirlSkirtOddsLowMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentShowgirlSkirtOddsLow_InfoText")
	EndEvent
EndState

State AND_TransparentShowgirlSkirtOdds
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentShowgirlSkirtOdds])
		If FlashOdds[TransparentShowgirlSkirtOdds_Low] <= 50 && FlashOdds[TransparentShowgirlSkirtOdds_High] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentShowgirlSkirtOdds_High] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds_High])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds_Low])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentShowgirlSkirtOdds_Low], FlashOdds[TransparentShowgirlSkirtOdds_High])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentShowgirlSkirtOdds] = value as Int
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds, FlashOdds[TransparentShowgirlSkirtOdds])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds], "{0}%", False, "AND_TransparentShowgirlSkirtOdds")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentShowgirlSkirtOdds_Low] <= 50 && FlashOdds[TransparentShowgirlSkirtOdds_High] >= 50
			FlashOdds[TransparentShowgirlSkirtOdds] = 50
		ElseIf FlashOdds[TransparentShowgirlSkirtOdds_High] < 50
			FlashOdds[TransparentShowgirlSkirtOdds] = FlashOdds[TransparentShowgirlSkirtOdds_High]
		Else
			FlashOdds[TransparentShowgirlSkirtOdds] = FlashOdds[TransparentShowgirlSkirtOdds_Low]
		EndIf
		
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds, FlashOdds[TransparentShowgirlSkirtOdds])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds], "{0}%", False, "AND_TransparentShowgirlSkirtOdds")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentShowgirlSkirtOdds_InfoText")
	EndEvent
EndState

State AND_TransparentShowgirlSkirtOddsMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentShowgirlSkirtOdds_Male])
		If FlashOdds[TransparentShowgirlSkirtOdds_Low_Male] <= 50 && FlashOdds[TransparentShowgirlSkirtOdds_High_Male] >= 50
			SetSliderDialogDefaultValue(50)
		ElseIf FlashOdds[TransparentShowgirlSkirtOdds_High_Male] < 50
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds_High_Male])
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds_Low_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentShowgirlSkirtOdds_Low_Male], FlashOdds[TransparentShowgirlSkirtOdds_High_Male])
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentShowgirlSkirtOdds_Male] = value as Int
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_Male, FlashOdds[TransparentShowgirlSkirtOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_Male], "{0}%", False, "AND_TransparentShowgirlSkirtOddsMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentShowgirlSkirtOdds_Low_Male] <= 50 && FlashOdds[TransparentShowgirlSkirtOdds_High_Male] >= 50
			FlashOdds[TransparentShowgirlSkirtOdds_Male] = 50
		ElseIf FlashOdds[TransparentShowgirlSkirtOdds_High_Male] < 50
			FlashOdds[TransparentShowgirlSkirtOdds] = FlashOdds[TransparentShowgirlSkirtOdds_High_Male]
		Else
			FlashOdds[TransparentShowgirlSkirtOdds_Male] = FlashOdds[TransparentShowgirlSkirtOdds_Low_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_Male, FlashOdds[TransparentShowgirlSkirtOdds_Male])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_Male], "{0}%", False, "AND_TransparentShowgirlSkirtOddsMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentShowgirlSkirtOdds_InfoText")
	EndEvent
EndState

State AND_TransparentShowgirlSkirtOddsHigh
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentShowgirlSkirtOdds_High])
		If FlashOdds[TransparentShowgirlSkirtOdds] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentShowgirlSkirtOdds], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentShowgirlSkirtOdds_High] = value as Int
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_High, FlashOdds[TransparentShowgirlSkirtOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_High], "{0}%", False, "AND_TransparentShowgirlSkirtOddsHigh")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentShowgirlSkirtOdds] <= 70
			FlashOdds[TransparentShowgirlSkirtOdds_High] = 70
		Else
			FlashOdds[TransparentShowgirlSkirtOdds_High] = FlashOdds[TransparentShowgirlSkirtOdds]
		EndIf
		
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_High, FlashOdds[TransparentShowgirlSkirtOdds_High])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_High], "{0}%", False, "AND_TransparentShowgirlSkirtOddsHigh")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentShowgirlSkirtOddsHigh_InfoText")
	EndEvent
EndState

State AND_TransparentShowgirlSkirtOddsHighMale
	Event OnSliderOpenST()
		SetSliderDialogStartValue(FlashOdds[TransparentShowgirlSkirtOdds_High_Male])
		If FlashOdds[TransparentShowgirlSkirtOdds_Male] <= 70
			SetSliderDialogDefaultValue(70)
		Else
			SetSliderDialogDefaultValue(FlashOdds[TransparentShowgirlSkirtOdds_Male])
		EndIf
		SetSliderDialogRange(FlashOdds[TransparentShowgirlSkirtOdds_Male], 99)
		SetSliderDialogInterval(1)
	EndEvent
	
	Event OnSliderAcceptST(Float value)
		FlashOdds[TransparentShowgirlSkirtOdds_High_Male] = value as Int
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_High_Male, FlashOdds[TransparentShowgirlSkirtOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_High_Male], "{0}%", False, "AND_TransparentShowgirlSkirtOddsHighMale")
	EndEvent 

	Event OnDefaultST()
		If FlashOdds[TransparentShowgirlSkirtOdds_Male] <= 70
			FlashOdds[TransparentShowgirlSkirtOdds_High_Male] = 70
		Else
			FlashOdds[TransparentShowgirlSkirtOdds_High_Male] = FlashOdds[TransparentShowgirlSkirtOdds_Male]
		EndIf
		
		UpdateFlashingOdds(TransparentShowgirlSkirtOdds_High_Male, FlashOdds[TransparentShowgirlSkirtOdds_High_Male])
		SetSliderOptionValueST(FlashOdds[TransparentShowgirlSkirtOdds_High_Male], "{0}%", False, "AND_TransparentShowgirlSkirtOddsHighMale")
	EndEvent
	
	Event OnHighlightST()
		SetInfoText("$AND_TransparentShowgirlSkirtOddsHigh_InfoText")
	EndEvent
EndState