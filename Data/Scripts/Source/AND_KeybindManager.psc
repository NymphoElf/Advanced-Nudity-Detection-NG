ScriptName AND_KeybindManager extends Quest

AND_MCM Property Config Auto
AND_Logger Property Logger Auto

Bool Property KeysEnabled Auto Hidden

Int Property FlashChestCurtainKey = 0 AutoReadOnly ;FlashKey[0]
Int Property FlashPelvicCurtainKey = 1 AutoReadOnly ;FlashKey[1]
Int Property FlashAssCurtainKey = 2 AutoReadOnly ;FlashKey[2]
Int Property FixChestCurtainKey = 3 AutoReadOnly ;FlashKey[3]
Int Property FixPelvicCurtainKey = 4 AutoReadOnly ;FlashKey[4]
Int Property FixAssCurtainKey = 5 AutoReadOnly ;FlashKey[5]

Int[] Property RegisteredKeys Auto

Int OpenMenus = 0

Bool Function PlayerIsWearingChestCurtain() Global Native
Bool Function PlayerIsWearingPelvicCurtain() Global Native
Bool Function PlayerIsWearingAssCurtain() Global Native

Function OverrideCurtainRoll(Int CurtainType, Int RollOverride) Global Native

Int Property ChestCurtain = 0 AutoReadOnly
Int Property PelvicCurtain = 1 AutoReadOnly
Int Property AssCurtain = 2 AutoReadOnly

Event OnInit()
	Startup()
EndEvent

Function Startup()
	RegisterForMenu("BarterMenu")
	RegisterForMenu("Book Menu")
	RegisterForMenu("Console")
	RegisterForMenu("Console Native UI Menu")
	RegisterForMenu("Container Menu")
	RegisterForMenu("Crafting Menu")
	RegisterForMenu("FavoritesMenu")
	RegisterForMenu("GiftMenu")
	RegisterForMenu("InventoryMenu")
	RegisterForMenu("Journal Menu")
	RegisterForMenu("LevelUp Menu")
	RegisterForMenu("Loading Menu")
	RegisterForMenu("Lockpicking Menu")
	RegisterForMenu("MagicMenu")
	RegisterForMenu("Main Menu")
	RegisterForMenu("MapMenu")
	RegisterForMenu("MessageBoxMenu")
	RegisterForMenu("Quantity Menu")
	RegisterForMenu("RaceSex Menu")
	RegisterForMenu("Sleep/Wait Menu")
	RegisterForMenu("Stats Menu")
	RegisterForMenu("Training Menu")
	RegisterForMenu("Tutorial Menu")
	
	RegisterForKey(RegisteredKeys[0])
	RegisterForKey(RegisteredKeys[1])
	RegisterForKey(RegisteredKeys[2])
	RegisterForKey(RegisteredKeys[3])
	RegisterForKey(RegisteredKeys[4])
	RegisterForKey(RegisteredKeys[5])
EndFunction

Event OnMenuOpen(String MenuName)
	KeysEnabled = False
	OpenMenus += 1
	AND_Logger.FastLog("<Keybind Manager> [OnMenuOpen] Opened Menu: " + MenuName + ". KeysEnabled is now: " + KeysEnabled + " | Menus Open = " + OpenMenus)
EndEvent

Event OnMenuClose(String MenuName)
	OpenMenus -= 1
	If OpenMenus <= 0
		OpenMenus = 0
		KeysEnabled = True
	EndIf
	AND_Logger.FastLog("<Keybind Manager> [OnMenuClose] Closed Menu: " + MenuName + ". KeysEnabled is now: " + KeysEnabled + " | Menus Open = " + OpenMenus)
EndEvent

Event OnKeyDown(Int KeyCode)
	AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Registered Key was pressed! Keycode is " + KeyCode)
	If KeysEnabled == True
		AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Keys are ENABLED")
		
		Int CheckedIndex = 0
		While CheckedIndex < 6
			If KeyCode == RegisteredKeys[CheckedIndex]
				ProcessKey(CheckedIndex)
			EndIf
			CheckedIndex += 1
		EndWhile

		If Config.PlayerIsFemale
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Send Female Scan")
			AND_Core.FemaleAnalyze()
		Else
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Send Male Scan")
			AND_Core.MaleAnalyze()
		EndIf
	Else
		AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Keys are DISABLED.")
	EndIf
EndEvent

Function ProcessKey(Int KeyIndex)
	If KeyIndex == FlashChestCurtainKey
		If PlayerIsWearingChestCurtain() == True
			OverrideCurtainRoll(ChestCurtain, 0)
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Flash Chest Curtain")
		Else
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Not Wearing a Chest Curtain")
		EndIf
	ElseIf KeyIndex == FlashPelvicCurtainKey
		If PlayerIsWearingPelvicCurtain() == True
			OverrideCurtainRoll(PelvicCurtain, 0)
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Flash Pelvic Curtain")
		Else
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Not Wearing a Pelvic Curtain")
		EndIf
	ElseIf KeyIndex == FlashAssCurtainKey
		If PlayerIsWearingAssCurtain() == True
			OverrideCurtainRoll(AssCurtain, 0)
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Flash Ass Curtain")
		Else
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Not Wearing an Ass Curtain")
		EndIf
	ElseIf KeyIndex == FixChestCurtainKey
		If PlayerIsWearingChestCurtain() == True
			OverrideCurtainRoll(ChestCurtain, 101)
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Fix Chest Curtain")
		Else
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Not Wearing a Chest Curtain")
		EndIf
	ElseIf KeyIndex == FixPelvicCurtainKey
		If PlayerIsWearingPelvicCurtain() == True
			OverrideCurtainRoll(PelvicCurtain, 101)
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Fix Pelvic Curtain")
		Else
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Not Wearing a Pelvic Curtain")
		EndIf
	ElseIf KeyIndex == FixAssCurtainKey
		If PlayerIsWearingAssCurtain() == True
			OverrideCurtainRoll(AssCurtain, 101)
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Fix Ass Curtain")
		Else
			AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] Not Wearing an Ass Curtain")
		EndIf
	Else
		AND_Logger.FastLog("<Keybind Manager> [OnKeyDown] ERROR: Registered Key was pressed but somehow not found in the RegisteredKeys Array. KeyIndex value is: " + KeyIndex, Logger.Core, Logger.ERROR)
		Debug.MessageBox("ADVANCED NUDITY DETECTION ERROR: Registered Flash/Fix Key was pressed but somehow not found in the RegisteredKeys Array.")
		return
	EndIf
EndFunction

Function UpdateRegister(Int KeyIndex)
	AND_Logger.FastLog("<Keybind Manager> [UpdateRegister] Update Key Index " + KeyIndex)
	UnregisterForKey(RegisteredKeys[KeyIndex])
	RegisteredKeys[KeyIndex] = Config.FlashKey[KeyIndex]
	AND_Logger.FastLog("KeyCode is " + Config.FlashKey[KeyIndex])
	RegisterForKey(RegisteredKeys[KeyIndex])
EndFunction