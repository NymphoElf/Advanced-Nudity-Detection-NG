ScriptName AND_PlayerScript extends ReferenceAlias

Import PO3_SKSEFunctions

AND_Core Property Core Auto
AND_MotionTimer Property MotionClock Auto
AND_MCM Property Config Auto
AND_ModEventListener Property ModEventListener Auto
AND_Logger Property Logger Auto

Actor Property PlayerRef Auto

Bool Property PermanentsImported = False Auto Hidden

Float Property GameTimeUpdateSpeed Auto Hidden

GlobalVariable Property TimeScale Auto

Int Property MaxTimeScale = 100 Auto Hidden

Message Property IsTransformedMessage Auto
Message Property AddTransformRace Auto

String Property ScanSetting Auto Hidden

Function CheckWearingCurtains() Global Native
Function ClosedMenuEvent(String MenuName) Global Native

Event OnInit()
	Startup()
EndEvent

Function Startup()
	RegisterForMenu("RaceSex Menu")
	RegisterForMenu("Console")
	RegisterForUpdateGameTime(0.25)
	AND_Logger.FastLog("<PlayerScript> [Startup] Completed!", Logger.Core, Logger.CRITICAL)
EndFunction

Event OnPlayerLoadGame()
	If Core.BaseRace == None
		AND_Logger.FastLog("<PlayerScript> [OnPlayerLoadGame] - Base Race is None!", Logger.Core, Logger.ERROR)
		Debug.MessageBox("A.N.D. - Your character's race was not detected. Please confirm your charcater's race again.")
		Game.ShowRaceMenu()
	EndIf
	
	AND_Logger.FastLog("===LOAD GAME===")
	Core.ModCheck()
	
	ModEventListener.InitializeModEvents()
	
	RegisterForAnimations()
EndEvent

Function RegisterForAnimations()
	RegisterForAnimationEvent(PlayerRef, "FootLeft")
	RegisterForAnimationEvent(PlayerRef, "FootSprintLeft")
EndFunction

Event OnMenuClose(String MenuName)
	AND_Logger.FastLog("<PlayerScript> [OnCloseMenu] - Menu Closed", Logger.Core, Logger.CRITICAL)
	If MenuName == "RaceSex Menu"
		AND_Logger.FastLog("<PlayerScript> [OnCloseMenu] - RaceSex Menu Closed", Logger.Core, Logger.CRITICAL)
		
		RegisterForAnimations()
		
		If PermanentsImported == False
			AND_NPCData.ImportPermanentFemales(Utility.GetCurrentGameTime())
			PermanentsImported = True
		EndIf
		
		Core.BaseRace = Core.PlayerBase.GetRace()
		AND_Logger.FastLog("<PlayerScript> [OnCloseMenu] - Base Race is: " + Core.BaseRace, Logger.Core)
		
		If Core.BaseRace == None
			AND_Logger.FastLog("<PlayerScript> [OnPlayerLoadGame] - Base Race is None!", Logger.Core, Logger.ERROR)
			Debug.MessageBox("A.N.D. - Race was not detected. Something is wrong with one or more of your other mods because they're telling Skyrim your Race is 'None'.")
			;Game.ShowRaceMenu()
			return
		EndIf
		
		Core.RegisterForSingleUpdate(1.0)
	EndIf
	
	If MenuName == "Console"
		Race arPlayer = Core.PlayerBase.GetRace()
		If arPlayer != Core.BaseRace
			If Core.DefaultRaces.Find(arPlayer) >= 0
				Core.BaseRace = arPlayer
			ElseIf Core.TransformedRaces.Find(arPlayer) >= 0 || Core.CustomTransform.Find(arPlayer) >= 0
				;Do nothing, player is still Transformed
			Else
				Int TransformedSelection = IsTransformedMessage.Show()
				If TransformedSelection == 1 ;Custom Race
					Core.BaseRace = arPlayer
					Debug.MessageBox("A.N.D. MESSAGE - Your race is detected as: " + arPlayer + " " + arPlayer.GetName() + ". If this is not your NON-transformed race, use Racemenu to reset it to the correct race.")
				Else
					Int AddTransform = AddTransformRace.Show()
					If AddTransform == 0
						Core.AddCustomTransform(arPlayer)
					EndIf
				EndIf
			EndIf
		EndIf
	EndIf
	
	AND_Logger.FastLog("<PlayerScript> [OnCloseMenu] - Sending ClosedMenuEvent to C++...", Logger.Core, Logger.CRITICAL)
	ClosedMenuEvent(MenuName)
EndEvent

Event OnAnimationEvent(ObjectReference akReference, String akEventName)
	If Config.ConfigBoolOptions[Config.MotionFlashEnabled] == True
		If akEventName == "FootLeft"
			If MotionClock.CooldownActive == False
				AND_Logger.FastLog("<PlayerScript> [OnAnimationEvent] Event is 'FootLeft'")
				AND_Logger.FastLog("<PlayerScript> [OnAnimationEvent] Running Motion Flash Trigger")
				AND_Core.MovementDiceRoll(False)
				MotionClock.Cooldown()
			EndIf
		EndIf
		
		If akEventName == "FootSprintLeft"
			If MotionClock.CooldownActive == False
				AND_Logger.FastLog("<PlayerScript> [OnAnimationEvent] Event is 'FootSprintLeft'")
				AND_Logger.FastLog("<PlayerScript> [OnAnimationEvent] Sprinting Motion Flash Trigger")
				AND_Core.MovementDiceRoll(True)
				MotionClock.Cooldown()
			EndIf
		EndIf
	EndIf
EndEvent

Event OnObjectEquipped(Form akBaseObject, ObjectReference akReference)
	AND_Logger.FastLog("<Player Script> [OnObjectEquipped] Object Data: Base Object = " + akBaseObject \
	+ " | Editor ID = " + GetFormEditorID(akBaseObject) + " | Object Reference = " + akReference \
	+ " | Object Name = " + akBaseObject.GetName() + " | Has Ignore Keyword = " + akBaseObject.HasKeyword(Core.AND_Ignore))
	
	If (akBaseObject == none || akBaseObject.GetName() == "" || akBaseObject.HasKeyword(Core.AND_Ignore))
		AND_Logger.FastLog("<Player Script> [OnObjectEquipped] Equipped Null Object or has Ignore Keyword. Update Skipped.")
		return
	EndIf
	
	If Core.EquipScanArmed == False
		Core.EquipScanArmed = True
		CheckWearingCurtains()
		Core.RegisterForSingleUpdate(0.1)
	EndIf
EndEvent

Event OnObjectUnequipped(Form akBaseObject, ObjectReference akReference)
	AND_Logger.FastLog("<Player Script> [OnObjectUnequipped] Object Data: Base Object = " + akBaseObject \
	+ " | Editor ID = " + GetFormEditorID(akBaseObject) + " | Object Reference = " + akReference \
	+ " | Object Name = " + akBaseObject.GetName() + " | Has Ignore Keyword = " + akBaseObject.HasKeyword(Core.AND_Ignore))

	If (akBaseObject == none || akBaseObject.GetName() == "" || akBaseObject.HasKeyword(Core.AND_Ignore))
		AND_Logger.FastLog("<Player Script> [OnObjectUnequipped] Unequipped Null Object or has Ignore Keyword. Update Skipped.")
		return
	EndIf
	
	If Core.EquipScanArmed == False
		Core.EquipScanArmed = True
		CheckWearingCurtains()
		Core.RegisterForSingleUpdate(0.1)
	EndIf
EndEvent

Event OnUpdateGameTime()
	If TimeScale.GetValue() as Int > MaxTimeScale
		UnregisterForUpdateGameTime()
		Debug.MessageBox("A.N.D. Warning - Time Scale too high. Current: " + TimeScale.GetValue() as Int + ". Maximum: " + MaxTimeScale + ". Either choose a slower AND scan frequency or change the settings on your Time Scale mod.")
		While TimeScale.GetValue() as Int > MaxTimeScale
			AND_Logger.FastLog("<Player Script> [OnUpdateGameTime] Time Scale too high: " + TimeScale.GetValue() as Int + ". Waiting for Time Scale to go below: " + MaxTimeScale, Logger.Core, Logger.WARNING)
			Utility.Wait(30.0)
		EndWhile
		RegisterForUpdateGameTime(GameTimeUpdateSpeed)
		return
	EndIf
	
	AND_Logger.FastLog("<Player Script> [OnUpdateGameTime] Update Game Time Triggered.")
	
	AND_Core.DiceRoll(PlayerRef.IsSprinting(), PlayerRef.IsRunning())
	Core.NPCScanSpell.Cast(PlayerRef)
EndEvent