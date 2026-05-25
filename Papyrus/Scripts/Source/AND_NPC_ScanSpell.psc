ScriptName AND_NPC_ScanSpell extends ActiveMagicEffect

AND_Core Property Core Auto

Function ProcessNPC(Actor akActor, Float CurrentGameTime, Int SexualityScore) Global Native

Event OnEffectStart(Actor akTarget, Actor akCaster)
	ProcessNPC(akTarget, Utility.GetCurrentGameTime(), Core.FindSexuality(akTarget))
	Core.UpdateArousalValue(akTarget)
EndEvent