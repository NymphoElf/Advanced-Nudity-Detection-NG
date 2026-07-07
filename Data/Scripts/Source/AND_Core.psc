ScriptName AND_Core extends Quest

AND_MCM Property Config Auto
AND_PlayerScript Property PlayerScript Auto
AND_Modesty_Manager Property ModestyManager Auto
AND_Logger Property Logger Auto

SLSF_Reloaded_MCM Property SLSFR_Config = None Auto Hidden
SLSF_Reloaded_ModIntegration Property SLSFR_Mods = None Auto Hidden

;Actor Property Rosa Auto Hidden
ActorBase Property PlayerBase Auto

Bool Property MainRollRunning Auto Hidden
Bool Property EquipScanArmed Auto Hidden
Bool Property DynamicModestyEnabledByOtherMod = False Auto Hidden

Faction Property AND_ShowingAssFaction Auto
Faction Property AND_ShowingChestFaction Auto
Faction Property AND_ShowingGenitalsFaction Auto 
Faction Property AND_ShowingBraFaction Auto
Faction Property AND_ShowingUnderwearFaction Auto
Faction Property AND_ToplessFaction Auto
Faction Property AND_BottomlessFaction Auto
Faction Property AND_NudeActorFaction Auto

Faction Property ModestyFaction Auto

Faction Property TopModestyFaction Auto ;0 = Shy, 1 = Comfortable, 2 = Bold, 3 = Shameless, 4 = Permanent
Faction Property BottomModestyFaction Auto ;0 = Shy, 1 = Comfortable, 2 = Bold, 3 = Shameless, 4 = Permanent

Faction Property ShyWithMale Auto ;0 = No, 1 = Yes
Faction Property ShyWithFemale Auto ;0 = No, 1 = Yes

Faction Property FlashingChestCurtain Auto
Faction Property FlashingPelvicCurtain Auto
Faction Property FlashingAssCurtain Auto

Faction Property FlashingTop Auto
Faction Property FlashingBra Auto

Faction Property FlashingBottom Auto
Faction Property FlashingUnderwear Auto
Faction Property FlashingHotpants Auto
Faction Property FlashingSkirt Auto
Faction Property FlashingCString Auto

Faction Property ArousalFaction Auto

Keyword Property AND_ArmorTop Auto
Keyword Property AND_ArmorTopT_Low Auto
Keyword Property AND_ArmorTopT Auto
Keyword Property AND_ArmorTopT_High Auto
Keyword Property AND_ArmorBottom Auto
Keyword Property AND_ArmorBottomT_Low Auto
Keyword Property AND_ArmorBottomT Auto
Keyword Property AND_ArmorBottomT_High Auto
Keyword Property AND_Bra Auto
Keyword Property AND_BraT_Low Auto
Keyword Property AND_BraT Auto
Keyword Property AND_BraT_High Auto
Keyword Property AND_CString Auto
Keyword Property AND_CStringT_Low Auto
Keyword Property AND_CStringT Auto
Keyword Property AND_CStringT_High Auto
Keyword Property AND_Hotpants Auto
Keyword Property AND_HotpantsT_Low Auto
Keyword Property AND_HotpantsT Auto
Keyword Property AND_HotpantsT_High Auto
Keyword Property AND_Microskirt Auto
Keyword Property AND_Miniskirt Auto
Keyword Property AND_MiniskirtT Auto
Keyword Property AND_ShowgirlSkirt Auto
Keyword Property AND_ShowgirlSkirtT_Low Auto
Keyword Property AND_ShowgirlSkirtT Auto
Keyword Property AND_ShowgirlSkirtT_High Auto
Keyword Property AND_Thong Auto
Keyword Property AND_ThongT_Low Auto
Keyword Property AND_ThongT Auto
Keyword Property AND_ThongT_High Auto
Keyword Property AND_Underwear Auto
Keyword Property AND_UnderwearT_Low Auto
Keyword Property AND_UnderwearT Auto
Keyword Property AND_UnderwearT_High Auto
Keyword Property AND_Ignore Auto

Keyword Property AND_ArmorBottom_NoCover Auto
Keyword Property AND_ArmorTop_NoCover Auto
Keyword Property AND_Bra_NoCover Auto
Keyword Property AND_Underwear_NoCover Auto
Keyword Property AND_Thong_NoCover Auto

Keyword Property AND_NearlyNaked Auto
Keyword Property AND_NipplePasties Auto
Keyword Property AND_VaginaPasties Auto
Keyword Property AND_EffectivelyNaked Auto

Keyword Property AND_AssCurtain Auto
Keyword Property AND_AssCurtainT Auto
Keyword Property AND_ChestCurtain Auto
Keyword Property AND_ChestCurtainT Auto
Keyword Property AND_PelvicCurtain Auto
Keyword Property AND_PelvicCurtainT Auto

Keyword Property AND_ArmorTop_Male Auto
Keyword Property AND_ArmorTopT_Low_Male Auto
Keyword Property AND_ArmorTopT_Male Auto
Keyword Property AND_ArmorTopT_High_Male Auto
Keyword Property AND_ArmorBottom_Male Auto
Keyword Property AND_ArmorBottomT_Low_Male Auto
Keyword Property AND_ArmorBottomT_Male Auto
Keyword Property AND_ArmorBottomT_High_Male Auto
Keyword Property AND_Bra_Male Auto
Keyword Property AND_BraT_Low_Male Auto
Keyword Property AND_BraT_Male Auto
Keyword Property AND_BraT_High_Male Auto
Keyword Property AND_BananaHammock Auto
Keyword Property AND_BananaHammockT_Low Auto
Keyword Property AND_BananaHammockT Auto
Keyword Property AND_BananaHammockT_High Auto
Keyword Property AND_Hotpants_Male Auto
Keyword Property AND_HotpantsT_Low_Male Auto
Keyword Property AND_HotpantsT_Male Auto
Keyword Property AND_HotpantsT_High_Male Auto
Keyword Property AND_Microskirt_Male Auto
Keyword Property AND_Miniskirt_Male Auto
Keyword Property AND_MiniskirtT_Male Auto
Keyword Property AND_HimboSkirt Auto
Keyword Property AND_HimboSkirtT_Low Auto
Keyword Property AND_HimboSkirtT Auto
Keyword Property AND_HimboSkirtT_High Auto
Keyword Property AND_Thong_Male Auto
Keyword Property AND_ThongT_Low_Male Auto
Keyword Property AND_ThongT_Male Auto
Keyword Property AND_ThongT_High_Male Auto
Keyword Property AND_Underwear_Male Auto
Keyword Property AND_UnderwearT_Low_Male Auto
Keyword Property AND_UnderwearT_Male Auto
Keyword Property AND_UnderwearT_High_Male Auto

Keyword Property AND_ArmorBottom_NoCover_Male Auto
Keyword Property AND_ArmorTop_NoCover_Male Auto
Keyword Property AND_Bra_NoCover_Male Auto
Keyword Property AND_Underwear_NoCover_Male Auto
Keyword Property AND_Thong_NoCover_Male Auto

Keyword Property AND_NearlyNaked_Male Auto
Keyword Property AND_NipplePasties_Male Auto
Keyword Property AND_EffectivelyNaked_Male Auto

Keyword Property AND_AssCurtain_Male Auto
Keyword Property AND_AssCurtainT_Male Auto
Keyword Property AND_ChestCurtain_Male Auto
Keyword Property AND_ChestCurtainT_Male Auto
Keyword Property AND_PelvicCurtain_Male Auto
Keyword Property AND_PelvicCurtainT_Male Auto

Keyword Property AND_CoversAll Auto
Keyword Property AND_CoversAll_Male Auto

Keyword Property AND_ChestFlashRiskLow Auto
Keyword Property AND_ChestFlashRisk Auto
Keyword Property AND_ChestFlashRiskHigh Auto
Keyword Property AND_ChestFlashRiskExtreme Auto
Keyword Property AND_ChestFlashRiskUltra Auto
Keyword Property AND_PelvicFlashRiskLow Auto
Keyword Property AND_PelvicFlashRisk Auto
Keyword Property AND_PelvicFlashRiskHigh Auto
Keyword Property AND_PelvicFlashRiskExtreme Auto
Keyword Property AND_PelvicFlashRiskUltra Auto
Keyword Property AND_AssFlashRiskLow Auto
Keyword Property AND_AssFlashRisk Auto
Keyword Property AND_AssFlashRiskHigh Auto
Keyword Property AND_AssFlashRiskExtreme Auto
Keyword Property AND_AssFlashRiskUltra Auto

Keyword Property AND_ChestFlashRiskLow_Male Auto
Keyword Property AND_ChestFlashRisk_Male Auto
Keyword Property AND_ChestFlashRiskHigh_Male Auto
Keyword Property AND_ChestFlashRiskExtreme_Male Auto
Keyword Property AND_ChestFlashRiskUltra_Male Auto
Keyword Property AND_PelvicFlashRiskLow_Male Auto
Keyword Property AND_PelvicFlashRisk_Male Auto
Keyword Property AND_PelvicFlashRiskHigh_Male Auto
Keyword Property AND_PelvicFlashRiskExtreme_Male Auto
Keyword Property AND_PelvicFlashRiskUltra_Male Auto
Keyword Property AND_AssFlashRiskLow_Male Auto
Keyword Property AND_AssFlashRisk_Male Auto
Keyword Property AND_AssFlashRiskHigh_Male Auto
Keyword Property AND_AssFlashRiskExtreme_Male Auto
Keyword Property AND_AssFlashRiskUltra_Male Auto

Int Property TransformOverwrite = 0 Auto Hidden

;Spell Property NPCScanSpell Auto

Bool Property SLSFR_Found Auto Hidden
Bool Property DFFMA_Found Auto Hidden
Bool Property OSLArousedInstalled Auto Hidden

Race Property BaseRace Auto Hidden

Race[] Property DefaultRaces Auto
Race[] Property TransformedRaces Auto
Race[] Property CustomTransform Auto Hidden

GlobalVariable Property WICommentChanceNaked Auto

Function DiceRoll(Bool IsSprinting, Bool IsRunning) Global Native
Function MovementDiceRoll(Bool IsSprinting) Global Native
Function FemaleAnalyze() Global Native
Function MaleAnalyze() Global Native
Int Function GetRandomizedModesty(Actor akActor) Global Native

Function AddCustomTransform(Race TransformRace) Global Native

Event OnInit()
	Startup()
EndEvent

Function Startup()
	ModCheck()
	CustomTransform = new Race[10]
	AND_Logger.FastLog("<Core> [Startup] Completed!", Logger.Core, Logger.CRITICAL)
EndFunction

;/
Event OnUpdate()
	If PlayerBase.GetSex() == 0 ;Male
		AND_Logger.FastLog("<Core> [OnUpdate] Send Male Scan", Logger.Core)
		
		MaleAnalyze()
	Else
		AND_Logger.FastLog("<Core> [OnUpdate] Send Female Scan", Logger.Core)
		
		FemaleAnalyze()
	EndIf
	
	If SLSFR_Found == True
		SLSFR_NakedCommentPreCheck()
	Else
		WICommentChanceNaked.SetValue(NakedCommentChance(False))
	EndIf
	
	Utility.Wait(0.1)
	EquipScanArmed = False
EndEvent
/;

Function ModCheck()
	If Game.GetModByName("SLSF Reloaded.esp") != 255
		AND_Logger.FastLog("<Core> [Mod Check] SLSF Reloaded.esp Found", Logger.Core)
		SLSFR_Found = True
		SLSFR_Config = Game.GetFormFromFile(0x809, "SLSF Reloaded.esp") as SLSF_Reloaded_MCM
		SLSFR_Mods = Game.GetFormFromFile(0x808, "SLSF Reloaded.esp") as SLSF_Reloaded_ModIntegration
	Else
		AND_Logger.FastLog("<Core> [Mod Check] SLSF Reloaded.esp NOT Found", Logger.Core)
		SLSFR_Found = False
		SLSFR_Config = None
		SLSFR_Mods = None
	EndIf
	
	If Game.GetModByName("Modesty_Keyword.esp") != 255
		AND_Logger.FastLog("<Core> [Mod Check] Modesty_Keyword.esp (aka DFFMA) Found", Logger.Core)
		DFFMA_Found = True
	Else
		AND_Logger.FastLog("<Core> [Mod Check] Modesty_Keyword.esp (aka DFFMA) NOT Found", Logger.Core)
		DFFMA_Found = False
	EndIf
	
	If Game.GetModByName("OSLAroused.esp") != 255
		AND_Logger.FastLog("<Core> [Mod Check] OSLAroused.esp Found", Logger.Core)
		OSLArousedInstalled = True
	Else
		AND_Logger.FastLog("<Core> [Mod Check] OSLAroused.esp NOT Found", Logger.Core)
		OSLArousedInstalled = False
	EndIf
EndFunction

Function ProcessEquipmentChange() 
	If PlayerBase.GetSex() == 0 ;Male
		AND_Logger.FastLog("<Core> [OnUpdate] Send Male Scan", Logger.Core)
		
		MaleAnalyze()
	Else
		AND_Logger.FastLog("<Core> [OnUpdate] Send Female Scan", Logger.Core)
		
		FemaleAnalyze()
	EndIf
	
	If SLSFR_Found == True
		SLSFR_NakedCommentPreCheck()
	Else
		WICommentChanceNaked.SetValue(NakedCommentChance(False))
	EndIf
	
	Int EventHandle = ModEvent.Create("AdvancedNudityDetectionUpdate")
	ModEvent.Send(EventHandle)
	
	Utility.Wait(0.1)
	EquipScanArmed = False
EndFunction

;/
Function AddCustomTransform(Race TransformRace)
	Int Index = CustomTransform.Find(None)
	If Index < 0
		AND_Logger.FastLog("<Core> [AddCustomTransform] - Custom Transform List Full! Oldest Entry will be overwritten!", Logger.Core, Logger.WARNING)
		Debug.MessageBox("A.N.D. MESSAGE - Custom Transform List Full! Oldest Entry will be overwritten!")
		Index = TransformOverwrite
		If TransformOverwrite < 9
			TransformOverwrite += 1
		Else
			TransformOverwrite = 0
		EndIf
	EndIf
	
	CustomTransform[Index] = TransformRace
EndFunction
/;

;Function NakedCommentPreCheck(Bool ) Global Native

;Redo when SLSFR v4 is done?
Function SLSFR_NakedCommentPreCheck()
	If SLSFR_Config.DisableNakedCommentsWhilePW == True
		If SLSFR_Mods.IsPublicWhore() == True
			return
		Else
			WICommentChanceNaked.SetValue(NakedCommentChance(False))
		EndIf
	Else
		WICommentChanceNaked.SetValue(NakedCommentChance(False))
	EndIf
EndFunction

Int Function NakedCommentChance(Bool IsMCMRequest) Global Native

;/
Int Function NakedCommentChance(Bool IsMCMRequest)
	Int CommentChance = -1
	Bool UnderwearCounted = False
	
	If IsMCMRequest == True
		CommentChance += 1 ;Increase return value by 1 for a more understandable % return in the MCM
	EndIf
	
	If Config.DisableNakedComments == False
		If PlayerScript.PlayerRef.GetFactionRank(AND_NudeActorFaction) == 1
			CommentChance += Config.NudeFactionCommentChance
		EndIf
		
		If PlayerScript.PlayerRef.GetFactionRank(AND_ToplessFaction) == 1
			CommentChance += Config.ToplessFactionCommentChance
		EndIf
		
		If PlayerScript.PlayerRef.GetFactionRank(AND_BottomlessFaction) == 1
			CommentChance += Config.BottomlessFactionCommentChance
		EndIf
		
		If PlayerScript.PlayerRef.GetFactionRank(AND_ShowingChestFaction) == 1
			CommentChance += Config.ChestFactionCommentChance
		ElseIf PlayerScript.PlayerRef.GetFactionRank(AND_ShowingBraFaction) == 1
			CommentChance += Config.BraFactionCommentChance
		EndIf
		
		If PlayerScript.PlayerRef.GetFactionRank(AND_ShowingGenitalsFaction) == 1
			CommentChance += Config.GenitalsFactionCommentChance
		ElseIf PlayerScript.PlayerRef.GetFactionRank(AND_ShowingUnderwearFaction) == 1
			CommentChance += Config.UnderwearFactionCommentChance
			UnderwearCounted = True
		EndIf
		
		If PlayerScript.PlayerRef.GetFactionRank(AND_ShowingAssFaction) == 1
			CommentChance += Config.AssFactionCommentChance
		ElseIf PlayerScript.PlayerRef.GetFactionRank(AND_ShowingUnderwearFaction) == 1 && UnderwearCounted == False
			CommentChance += Config.UnderwearFactionCommentChance
		EndIf
	EndIf
	
	return CommentChance
EndFunction
/;

;/
Function UpdateArousalValue(Actor akActor)
	If OSLArousedInstalled == True
		akActor.SetFactionRank(ArousalFaction, (OSLAroused_ModInterface.GetArousal(akActor) as Int))
	Else
		akActor.SetFactionRank(ArousalFaction, 0)
	EndIf
EndFunction
/;

;/
Bool Function IsPlayerTransformed()
	If PlayerBase.GetRace() != BaseRace
		return True
	EndIf
	return False
EndFunction
/;