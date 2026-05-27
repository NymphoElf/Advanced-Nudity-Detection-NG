ScriptName AND_MotionTimer extends Quest

Bool Property CooldownActive = False Auto Hidden

Function Cooldown()
	If CooldownActive == False
		CooldownActive = True
		Utility.Wait(10)
		CooldownActive = False
	EndIf
EndFunction