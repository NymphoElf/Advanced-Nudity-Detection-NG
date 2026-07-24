ScriptName AND_Modesty_Manager extends Quest

AND_MCM Property Config Auto
AND_Logger Property Logger Auto

Actor Property PlayerRef Auto

String[] Property ModestyTitle Auto
String[] Property TopModestyTitle Auto
String[] Property BottomModestyTitle Auto

Int[] Function SKSEStrictModesty() Global Native
Int[] Function SKSESimpleModesty() Global Native

Function SKSERankJump(Int RankValue) Global Native
Function SKSETopRankJump(Int RankValue) Global Native
Function SKSEBottomRankJump(Int RankValue) Global Native

Function ProcessAllNPCModesty() Global Native

Event OnInit()
	Startup()
EndEvent

Function Startup()
	Utility.Wait(5.0)
	RegisterForUpdateGameTime(1.0)
	AND_Logger.FastLog("<Modesty Manager> [Startup] - Startup Complete", Logger.PlayerModesty, Logger.CRITICAL)
EndFunction

Event OnUpdateGameTime()
	AND_Logger.FastLog("<Modesty Manager> [OnUpdateGameTime] - START")
	
	If Config.ConfigBoolOptions[Config.PlayerStrictRules] == True
		Int[] Result = SKSEStrictModesty()
		
		If Result[0]
			ModestyAlert(0, (Result[1] < Result[2]), Result[2])
			
			If Config.ModestyMonologue == True
				ModestyInnerMonologue((Result[1] < Result[2]), Result[2], 0)
			EndIf
		EndIf
	Else
		Int[] Result = SKSESimpleModesty()
		If Result[0] ;TopModesty
			ModestyAlert(1, (Result[1] < Result[2]), Result[2])
			
			If Config.ModestyMonologue == True
				ModestyInnerMonologue((Result[1] < Result[2]), Result[2], 1)
			EndIf
		EndIf
		
		If Result[3] ;BottomModesty
			ModestyAlert(2, (Result[4] < Result[5]), Result[5])
			
			If Config.ModestyMonologue == True
				ModestyInnerMonologue((Result[4] < Result[5]), Result[5], 2)
			EndIf
		EndIf
	EndIf
	
	ProcessAllNPCModesty()
	
	AND_Logger.FastLog("<Modesty Manager> [OnUpdateGameTime] - END")
EndEvent

Function ModestyAlert(Int ModestyType, Bool IsRankUpgrade, Int NewRank)
	String MessageText = ""
	
	If ModestyType == 0 ;Strict
		If IsRankUpgrade == True
			If NewRank == 1
				MessageText = "Immodesty Upgrade: Rank 1 (Reasonable)"
			ElseIf NewRank == 2
				MessageText = "Immodesty Upgrade: Rank 2 (Relaxed)"
			ElseIf NewRank == 3
				MessageText = "Immodesty Upgrade: Rank 3 (Comfortable)"
			ElseIf NewRank == 4
				MessageText = "Immodesty Upgrade: Rank 4 (Tease)"
			ElseIf NewRank == 5
				MessageText = "Immodesty Upgrade: Rank 5 (Brazen)"
			ElseIf NewRank == 6
				MessageText = "Immodesty Upgrade: Rank 6 (Immodest)"
			ElseIf NewRank == 7
				MessageText = "Immodesty Upgrade: Shameless"
			EndIf
		Else
			If NewRank == 0
				MessageText = "Immodesty Downgrade: Rank 0 (Modest)"
			ElseIf NewRank == 1
				MessageText = "Immodesty Downgrade: Rank 1 (Reasonable)"
			ElseIf NewRank == 2
				MessageText = "Immodesty Downgrade: Rank 2 (Relaxed)"
			ElseIf NewRank == 3
				MessageText = "Immodesty Downgrade: Rank 3 (Comfortable)"
			ElseIf NewRank == 4
				MessageText = "Immodesty Downgrade: Rank 4 (Tease)"
			ElseIf NewRank == 5
				MessageText = "Immodesty Downgrade: Rank 5 (Brazen)"
			EndIf
		EndIf
	ElseIf ModestyType == 1 ;Top
		If IsRankUpgrade == True
			If NewRank == 1
				MessageText = "Top Immodesty Upgrade: Rank 1 (Comfortable)"
			ElseIf NewRank == 2
				MessageText = "Top Immodesty Upgrade: Rank 2 (Brazen)"
			ElseIf NewRank == 3
				MessageText = "Top Immodesty Upgrade: Rank 3 (Immodest)"
			ElseIf NewRank == 4
				MessageText = "Top Immodesty Upgrade: Shameless"
			EndIf
		Else
			If NewRank == 0
				MessageText = "Top Immodesty Downgrade: Rank 0 (Modest)"
			ElseIf NewRank == 1
				MessageText = "Top Immodesty Downgrade: Rank 1 (Comfortable)"
			ElseIf NewRank == 2
				MessageText = "Top Immodesty Downgrade: Rank 2 (Brazen)"
			EndIf
		EndIf
	ElseIf ModestyType == 2 ;Bottom
		If IsRankUpgrade == True
			If NewRank == 1
				MessageText = "Bottom Immodesty Upgrade: Rank 1 (Comfortable)"
			ElseIf NewRank == 2
				MessageText = "Bottom Immodesty Upgrade: Rank 2 (Brazen)"
			ElseIf NewRank == 3
				MessageText = "Bottom Immodesty Upgrade: Rank 3 (Immodest)"
			ElseIf NewRank == 4
				MessageText = "Bottom Immodesty Upgrade: Shameless"
			EndIf
		Else
			If NewRank == 0
				MessageText = "Bottom Immodesty Downgrade: Rank 0 (Modest)"
			ElseIf NewRank == 1
				MessageText = "Bottom Immodesty Downgrade: Rank 1 (Comfortable)"
			ElseIf NewRank == 2
				MessageText = "Bottom Immodesty Downgrade: Rank 2 (Brazen)"
			EndIf
		EndIf
	EndIf
	
	If Config.ModestyMessagebox == True
		Debug.MessageBox(MessageText)
	Else
		Debug.Notification(MessageText)
	EndIf
EndFunction

Function ModestyInnerMonologue(Bool IsRankUpgrade, Int Rank, Int Type = -1) ; Type (0) = Strict, (1) = Top, (2) = Bottom, -1 = Null
	If IsRankUpgrade == True
		If Type == 0
			If Rank == 1
				Debug.MessageBox("I guess showing a little skin couldn't hurt... It's not like I'm flashing people.")
			ElseIf Rank == 2
				Debug.MessageBox("Showing some leg isn't that big of a deal. I probably go swimming in less clothes.")
			ElseIf Rank == 3
				Debug.MessageBox("Yes, I have boobs. Yes, I'm showing a lot of cleavage. Who cares?")
			ElseIf Rank == 4
				Debug.MessageBox("It's kind of fun to see if anyone can catch a glimpse of my pussy through my skimpy clothes! I can tell who saw because they turn red, so cute!")
			ElseIf Rank == 5
				Debug.MessageBox("I wonder how many stares I'll get if I walk through town with my tits out?")
			ElseIf Rank == 6
				Debug.MessageBox("Modesty is annoying. I've shown off so much of my body that covering it seems pointless, and I just don't care anymore. Plus, running around naked just sounds FUN!")
			ElseIf Rank == 7
				Debug.MessageBox("I reject the concept of modesty entirely. How much of my body you can see doesn't matter, and I will never care about it again.")
			EndIf
		ElseIf Type == 1
			If Rank == 1
				Debug.MessageBox("Plenty of women show their cleavage. Why would anyone care that I do too?")
			ElseIf Rank == 2
				Debug.MessageBox("I mean, I'm not going to just walk around completely topless, but I don't mind if anyone gets a peek at my boobs.")
			ElseIf Rank == 3
				Debug.MessageBox("Go ahead, look at my tits! If I wanted to cover them, I wouldn't be topless.")
			ElseIf Rank == 4
				Debug.MessageBox("Yes, I have boobs and I know you can see them. Stare, squeeze, or walk away. Just get over it.")
			EndIf
		ElseIf Type == 2
			If Rank == 1
				Debug.MessageBox("Showing a little leg never hurt anybody.")
			ElseIf Rank == 2
				Debug.MessageBox("It's nice to let my pussy breathe. If someone catches a glimpse, then oh well.")
			ElseIf Rank == 3
				Debug.MessageBox("Being bottomless isn't just convenient, it's fun!")
			ElseIf Rank == 4
				Debug.MessageBox("Ugh... Yes, I have a vagina. If you don't want to see it, don't look.")
			EndIf
		Else
			AND_Logger.FastLog("<Modesty Manager> [ModestyInnerMonologue] - Type is invalid. Type is: " + Type, Logger.PlayerModesty, Logger.ERROR)
		EndIf
	Else
		If Type == 1
			If Rank == 0
				Debug.MessageBox("I should really wear normal, proper clothes. I don't want to turn into one of those slutty adventurer girls!")
			ElseIf Rank == 1
				Debug.MessageBox("Swimsuits are for swimming, not for walking around in public all day!")
			ElseIf Rank == 2
				Debug.MessageBox("I probably shouldn't keep shaking my near-naked tits in everyone's face. Plus not wearing a proper bra kind of hurts.")
			ElseIf Rank == 3
				Debug.MessageBox("How did I let myself get excited from teasing peeks at my vagina? That has to stop. It won't lead to anything good.")
			ElseIf Rank == 4
				Debug.MessageBox("Ok, I guess letting myself walk around Topless isn't smart.")
			ElseIf Rank == 5
				Debug.MessageBox("Hmm, maybe a little modesty is necessary... I'm not as comfortable as I used to be.")
			EndIf
		ElseIf Type == 2
			If Rank == 0
				Debug.MessageBox("Swimsuits are for swimming, not for walking around in public all day!")
			ElseIf Rank == 1
				Debug.MessageBox("I probably shouldn't keep shaking my near-naked tits in everyone's face. Plus not wearing a proper bra kind of hurts.")
			ElseIf Rank == 2
				Debug.MessageBox("Hmm. Maybe SOME modesty would be good... Some men are barely able to resist the urge to grope me...")
			EndIf
		ElseIf Type == 3
			If Rank == 0
				Debug.MessageBox("Swimsuits are for swimming, not for walking around in public all day!")
			ElseIf Rank == 1
				Debug.MessageBox("I guess I should probably go back to keeping my vagina covered.")
			ElseIf Rank == 2
				Debug.MessageBox("Ok, maybe this isn't as fun as I thought... I should cover myself a bit.")
			EndIf
		Else
			AND_Logger.FastLog("<Modesty Manager> [ModestyInnerMonologue] - Type is invalid. Type is: " + Type, Logger.PlayerModesty, Logger.ERROR)
		EndIf
	EndIf
EndFunction