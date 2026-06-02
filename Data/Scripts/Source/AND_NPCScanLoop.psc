ScriptName AND_NPCScanLoop extends Quest
{Replaces the old AND_NPC_ScanSpell cloak. A single timed update finds nearby
 NPCs in native C++ (cheap) and processes them, instead of the engine applying a
 scripted MagicEffect to every actor in range.}

AND_Core Property Core Auto
AND_Logger Property Logger Auto

Float Property ScanInterval = 3.0 Auto
{Real-time seconds between scans.}

Float Property ScanRadius = 5120.0 Auto
{Scan radius in game units. 0 = use the plugin's configured default.}

Bool Property LoopEnabled = True Auto Hidden

; Native: returns NPCs within `radius` of `akCenter` (capped at the 128 Papyrus
; array limit). Backed by ActorScanner::GetNearbyActorsPapyrus in the DLL.
Actor[] Function GetNearbyActors(Actor akCenter, Float radius) Global Native

Event OnInit()
	StartLoop()
EndEvent

Function StartLoop()
	LoopEnabled = True
	RegisterForSingleUpdate(ScanInterval)
	Logger.FastLog("<NPCScanLoop> [StartLoop] Started (interval " + ScanInterval + "s)", Logger.Core)
EndFunction

Function StopLoop()
	LoopEnabled = False
	UnregisterForUpdate()
	Logger.FastLog("<NPCScanLoop> [StopLoop] Stopped", Logger.Core)
EndFunction

Event OnUpdate()
	If LoopEnabled == False
		Return
	EndIf

	Actor player = Game.GetPlayer()
	Float currentGameTime = Utility.GetCurrentGameTime()
	Actor[] nearby = GetNearbyActors(player, ScanRadius)

	Int i = 0
	While i < nearby.Length
		Actor a = nearby[i]
		If a && a != player
			; Sexuality stays in Papyrus (SexLab has no C++ API); arousal is set
			; natively inside ProcessNPC. The old UpdateArousalValue call is gone.
			AND_NPC_ScanSpell.ProcessNPC(a, currentGameTime, Core.FindSexuality(a))
		EndIf
		i += 1
	EndWhile

	; Re-arm only after the pass completes, so a slow frame can't stack updates.
	RegisterForSingleUpdate(ScanInterval)
EndEvent
