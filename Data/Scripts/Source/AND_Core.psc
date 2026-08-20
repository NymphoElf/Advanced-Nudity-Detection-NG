ScriptName AND_Core extends Quest

Function DiceRoll(Bool IsSprinting, Bool IsRunning) Global Native
Function MovementDiceRoll(Bool IsSprinting) Global Native

Function FemaleAnalyze() Global Native
Function MaleAnalyze() Global Native

Int Function GetRandomizedModesty(Actor akActor) Global Native

Function AddCustomTransform(Race TransformRace) Global Native

Int Function NakedCommentChance(Bool IsMCMRequest) Global Native

Event OnInit()
	CheckConflictingMods()
EndEvent

Function CheckConflictingMods()
	Bool[] InstalledMods = AND_MCM.GetInstalledMods()
	
	If InstalledMods[3] && InstalledMods[5]
		Debug.Messagebox("A.N.D. ERROR - You cannot use OSL Aroused and SLO Aroused at the same time! (This includes dummy plugins!) Your game will now close...")
		Utility.Wait(1.0)
		Debug.QuitGame()
	EndIf
EndFunction