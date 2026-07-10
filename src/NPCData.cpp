#include "NPCData.h"
#include "Logger.h"
#include "Core.h"
#include "Config.h"
#include "SaveLoad.h"
#include "NPCScanner.h"

enum FunctionEnd {
	Success,
	FailWarn,
	FailError,
	FailCritical
};

void NPCDataOnRevertCallback() {
	PermanentFemaleVector.clear();
	RegisteredFemaleMap.clear();
}

int GetInternalPermanentFemaleID(RE::Actor* akFemale)
{
	Log("<C++ NPCData> [GetInternalPermanentFemaleID] Getting Female Index...", LogType::NPCData, LoggingLevel::info);
	
	for(int Index = 0; Index < PermanentFemaleVector.size(); ++Index)
	{
		uint32_t ModIndex = PermanentFemaleVector[Index].GetModIndex();

		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Checking Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()), LogType::NPCData, LoggingLevel::info);
		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") ModIndex is: " + std::format("{:08X}", ModIndex), LogType::NPCData, LoggingLevel::info);
		
		if (PermanentFemaleVector[Index].LightPlugin) {
			ModIndex += 0xFE000000;
		}

		uint32_t akLocalID = PermanentFemaleVector[Index].LocalID;
		RE::FormID PermanentFemaleFormID = ModIndex + akLocalID;

		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") LocalID is: " + std::format("{:08X}", akLocalID), LogType::NPCData, LoggingLevel::info);
		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") FullID should be: " + std::format("{:08X}", PermanentFemaleFormID), LogType::NPCData, LoggingLevel::info);
		
		if (PermanentFemaleFormID == akFemale->GetFormID()) { 
			Log("<C++ NPCData> [GetInternalPermanentFemaleID] Match Found!", LogType::NPCData, LoggingLevel::info);
			return Index; 
		}

		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Match not found. Checking next Permanent Female...", LogType::NPCData, LoggingLevel::info);
	}

	Log("<C++ NPCData> [GetInternalPermanentFemaleID] Could not find " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") in Permanent Female List", LogType::NPCData, LoggingLevel::warning);

	return -1;
}

void ImportSinglePermanent(int InternalID) {
	float CurrentGameTime = GameCalendar->GetCurrentGameTime();
	
	PermanentFemales& ThePermFemale = PermanentFemaleVector[InternalID];
	
	uint32_t ModIndex = ThePermFemale.GetModIndex();

	if (ThePermFemale.LightPlugin) {
		ModIndex += 0xFE000000;
	}

	RE::FormID PermanentFemaleFormID = ModIndex | ThePermFemale.LocalID;

	RegisteredFemales TheRegFemale;
	memset(&TheRegFemale, 0, sizeof(TheRegFemale));

	memcpy(TheRegFemale.Name, ThePermFemale.Name, sizeof(TheRegFemale.Name));

	TheRegFemale.FemaleFormID = PermanentFemaleFormID;

	TheRegFemale.CurrentRankStrict = ThePermFemale.DefaultRankStrict;
	TheRegFemale.DefaultRankStrict = ThePermFemale.DefaultRankStrict;
	TheRegFemale.MinimumRankStrict = ThePermFemale.MinimumRankStrict;

	TheRegFemale.CurrentRankTop = ThePermFemale.DefaultRankTop;
	TheRegFemale.DefaultRankTop = ThePermFemale.DefaultRankTop;
	TheRegFemale.MinimumRankTop = ThePermFemale.MinimumRankTop;

	TheRegFemale.CurrentRankBottom = ThePermFemale.DefaultRankBottom;
	TheRegFemale.DefaultRankBottom = ThePermFemale.DefaultRankBottom;
	TheRegFemale.MinimumRankBottom = ThePermFemale.MinimumRankBottom;

	TheRegFemale.ShynessMode = ThePermFemale.ShynessMode;
	TheRegFemale.SexualityScore = ThePermFemale.SexualityScore;

	TheRegFemale.AllowShameless = ThePermFemale.AllowShameless;
	TheRegFemale.AllowCorruption = ThePermFemale.AllowCorruption;
	TheRegFemale.StrictRules = ThePermFemale.StrictRules;
	TheRegFemale.UpgradeBlocked = false;

	TheRegFemale.LastUpdateTime = CurrentGameTime;

	RegisteredFemaleMap[PermanentFemaleFormID] = TheRegFemale;
}

void RegisterFemale(RE::Actor* akFemale, float CurrentGameTime, int SexualityScore) {
	if (akFemale == nullptr) {
		Log("<C++ NPCData> [RegisterFemale] Cannot register NULL actor!", LogType::NPCData, LoggingLevel::warning);
		return;
	}
	
	RE::FormID FemaleForm = akFemale->GetFormID();
	std::string FemaleName = akFemale->GetName();

	Log("<C++ NPCData> [RegisterFemale] Female Form ID: " + std::format("{:08X}", FemaleForm), LogType::NPCData);
	Log("<C++ NPCData> [RegisterFemale] Female Name: " + FemaleName, LogType::NPCData);

	if (FemaleName == "") {
		Log("<C++ NPCData> [RegisterFemale] Cannot Register Unnamed Female!", LogType::NPCData, LoggingLevel::warning);
		return;
	}

	int PermanentID = GetInternalPermanentFemaleID(akFemale);
	if (PermanentID >= 0) {
		Log("<C++ NPCData> [RegisterFemale] Female exists on Permanent List. Re-importing female...", LogType::NPCData);
		ImportSinglePermanent(PermanentID);
		return;
	}

	int ShynessMode = ShySex::Men; //Default to Men (zero) if no shyness otherwise found
	int StrictModesty = GetRandomizedModesty(akFemale, false);
	int TopModesty = SimpleModestyLevel::Modest;
	int BottomModesty = TopModesty;

	switch (StrictModesty) {
		case StrictModestyLevel::Reasonable:
			TopModesty = SimpleModestyLevel::Comfortable;
			break;
		case StrictModestyLevel::Relaxed:
			TopModesty = SimpleModestyLevel::Comfortable;
			BottomModesty = TopModesty;
			break;
		case StrictModestyLevel::Comfortable:
			TopModesty = SimpleModestyLevel::Brazen;
			BottomModesty = SimpleModestyLevel::Comfortable;
			break;
		case StrictModestyLevel::Tease:
			TopModesty = SimpleModestyLevel::Brazen;
			BottomModesty = TopModesty;
			break;
		case StrictModestyLevel::Brazen:
			TopModesty = SimpleModestyLevel::Immodest;
			BottomModesty = SimpleModestyLevel::Brazen;
			break;
		case StrictModestyLevel::Immodest:
			TopModesty = SimpleModestyLevel::Immodest;
			BottomModesty = TopModesty;
			break;
		default:
			TopModesty = SimpleModestyLevel::Modest;
			BottomModesty = TopModesty;
			break;
	}

	SetActorFactionRank(akFemale, ModestyFaction, HandleInteger(StrictModesty));
	SetActorFactionRank(akFemale, TopModestyFaction, HandleInteger(TopModesty));
	SetActorFactionRank(akFemale, BottomModestyFaction, HandleInteger(BottomModesty));

	//Establish Shyness
	if (InstalledMods::Sexlab && Configuration::DefaultNPCShyness == ShySex::Sexuality) {
		if (SexualityScore > 65) {
			//Straight
			SetActorFactionRank(akFemale, ShyWithMale, 1);
			SetActorFactionRank(akFemale, ShyWithFemale, 0);
			ShynessMode = ShySex::Men;
		}
		else if (SexualityScore < 35) {
			//Gay
			SetActorFactionRank(akFemale, ShyWithMale, 0);
			SetActorFactionRank(akFemale, ShyWithFemale, 1);
			ShynessMode = ShySex::Women;
		}
		else {
			//Bisexual
			SetActorFactionRank(akFemale, ShyWithMale, 1);
			SetActorFactionRank(akFemale, ShyWithFemale, 1);
			ShynessMode = ShySex::Both;
		}
	}
	else if (Configuration::DefaultNPCShyness == ShySex::Random) {
		int ShyRoll = Randomizer(0,2);
		if (ShyRoll == ShySex::Men) {
			//Straight
			SetActorFactionRank(akFemale, ShyWithMale, 1);
			SetActorFactionRank(akFemale, ShyWithFemale, 0);
		}
		else if (ShyRoll == ShySex::Women) {
			//Gay
			SetActorFactionRank(akFemale, ShyWithMale, 0);
			SetActorFactionRank(akFemale, ShyWithFemale, 1);
		}
		else {
			//Bisexual
			SetActorFactionRank(akFemale, ShyWithMale, 1);
			SetActorFactionRank(akFemale, ShyWithFemale, 1);
		}
		ShynessMode = ShyRoll;
	}
	else if (Configuration::DefaultNPCShyness == ShySex::Both) {
		SetActorFactionRank(akFemale, ShyWithMale, 1);
		SetActorFactionRank(akFemale, ShyWithFemale, 1);
		ShynessMode = ShySex::Both;
	}
	else if (Configuration::DefaultNPCShyness == ShySex::Women) {
		SetActorFactionRank(akFemale, ShyWithMale, 0);
		SetActorFactionRank(akFemale, ShyWithFemale, 1);
		ShynessMode = ShySex::Women;
	}
	else {
		SetActorFactionRank(akFemale, ShyWithMale, 1);
		SetActorFactionRank(akFemale, ShyWithFemale, 0);
	}

	RegisteredFemales ThisFemale;
	memset(&ThisFemale, 0, sizeof(ThisFemale)); // intialize all data as 0

	strncpy_s(ThisFemale.Name, sizeof(ThisFemale.Name), FemaleName.c_str(), sizeof(ThisFemale.Name));

	ThisFemale.FemaleFormID = FemaleForm;

	ThisFemale.DefaultRankStrict = StrictModesty;
	ThisFemale.CurrentRankStrict = StrictModesty;

	ThisFemale.DefaultRankTop = TopModesty;
	ThisFemale.CurrentRankTop = TopModesty;

	ThisFemale.DefaultRankBottom = BottomModesty;
	ThisFemale.CurrentRankBottom = BottomModesty;

	ThisFemale.ShynessMode = ShynessMode;
	ThisFemale.SexualityScore = SexualityScore;

	ThisFemale.AllowShameless = Configuration::NPCShamelessByDefault;
	ThisFemale.AllowCorruption = Configuration::NPCCorruptionByDefault;
	ThisFemale.StrictRules = Configuration::NPCStrictRulesByDefault;
	ThisFemale.UpgradeBlocked = false;

	ThisFemale.LastUpdateTime = CurrentGameTime;

	RegisteredFemaleMap[FemaleForm] = ThisFemale;

	Log("<C++ NPCData> [RegisterFemale] Registered Female: " + FemaleName + " | Form ID: " + std::format("{:08X}", FemaleForm) + " | Internal ID: " + std::to_string(RegisteredFemaleMap.size()), LogType::Core, LoggingLevel::info);
}

void DeleteFemale(RE::StaticFunctionTag*, RE::Actor* akFemale)
{
	int index = 0;
	while (index < TotalFactions) {
		if (akFemale->IsInFaction(AllFactions[index]) == false) {
			akFemale->RemoveFromFaction(AllFactions[index]);
		}
		index++;
	}
	
	RegisteredFemaleMap.erase(akFemale->GetFormID());
}

void DeleteFemaleWithID(RE::FormID FemaleID) {
	RegisteredFemaleMap.erase(FemaleID);
}

void DeleteAllFemales(RE::StaticFunctionTag*)
{
	for (auto& [FemaleFormID, ThisFemale] : RegisteredFemaleMap) {
		RE::Actor* akFemale = RE::TESForm::LookupByID<RE::Actor>(FemaleFormID);

		if (akFemale == nullptr) {
			continue;
		}

		int index = 0;
		while (index < TotalFactions) {
			if (akFemale->IsInFaction(AllFactions[index]) == false) {
				akFemale->RemoveFromFaction(AllFactions[index]);
			}
			index++;
		}
	}
	
	RegisteredFemaleMap.clear();
}

void RegisterRosa(float CurrentGameTime, int SexualityScore) {
	int RosaForm = Rosa->GetFormID();
	int RosaBaseForm = Rosa->GetActorBase()->GetFormID();
	std::string RosaEditorID = Rosa->GetFormEditorID();
	std::string RosaBaseEditorID = Rosa->GetActorBase()->GetFormEditorID();
	std::string RosaName = Rosa->GetName();
	std::string RosaBaseName = Rosa->GetActorBase()->GetFormEditorID();

	Log("<C++ NPCData> [RegisterRosa] Rosa Form ID: " + std::format("{:08X}", RosaForm), LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Base Form ID: " + std::format("{:08X}", RosaBaseForm), LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Editor ID: " + static_cast<std::string>(RosaEditorID), LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Base Editor ID: " + static_cast<std::string>(RosaBaseEditorID), LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Name: " + RosaName, LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Base Name: " + RosaBaseName, LogType::NPCData);

	int ShynessMode;

	if (SexualityScore > 65) {
		//Straight
		Rosa->AddToFaction(ShyWithMale, 1);
		Rosa->AddToFaction(ShyWithFemale, 0);
		ShynessMode = ShySex::Men;
	}
	else if (SexualityScore < 35) {
		//Gay
		Rosa->AddToFaction(ShyWithMale, 0);
		Rosa->AddToFaction(ShyWithFemale, 1);
		ShynessMode = ShySex::Women;
	}
	else {
		//Bisexual
		Rosa->AddToFaction(ShyWithMale, 1);
		Rosa->AddToFaction(ShyWithFemale, 1);
		ShynessMode = ShySex::Both;
	}

	RegisteredFemales ThisFemale;
	memset(&ThisFemale, 0, sizeof(ThisFemale)); // intialize all data as 0

	strncpy_s(ThisFemale.Name, sizeof(ThisFemale.Name), RosaName.c_str(), sizeof(ThisFemale.Name));

	ThisFemale.FemaleFormID = RosaForm;

	ThisFemale.DefaultRankStrict = StrictModestyLevel::Immodest;
	ThisFemale.CurrentRankStrict = StrictModestyLevel::Immodest;
	ThisFemale.MinimumRankStrict = StrictModestyLevel::Immodest;

	ThisFemale.DefaultRankTop = SimpleModestyLevel::Immodest;
	ThisFemale.CurrentRankTop = SimpleModestyLevel::Immodest;
	ThisFemale.MinimumRankTop = SimpleModestyLevel::Immodest;

	ThisFemale.DefaultRankBottom = SimpleModestyLevel::Immodest;
	ThisFemale.CurrentRankBottom = SimpleModestyLevel::Immodest;
	ThisFemale.MinimumRankBottom = SimpleModestyLevel::Immodest;

	ThisFemale.ShynessMode = ShynessMode;
	ThisFemale.SexualityScore = SexualityScore;

	ThisFemale.AllowShameless = Configuration::NPCShamelessByDefault;
	ThisFemale.AllowCorruption = Configuration::NPCCorruptionByDefault;
	ThisFemale.StrictRules = Configuration::StrictModestyRules;
	ThisFemale.UpgradeBlocked = false;

	ThisFemale.LastUpdateTime = CurrentGameTime;

	RegisteredFemaleMap[RosaForm] = ThisFemale;
}

int RegisterPermanent(RE::StaticFunctionTag*, RE::Actor* akFemale) 
{
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	std::string akName = akFemale->GetName();
	RE::FormID FemaleFormID = akFemale->GetFormID();

	if (!RegisteredFemaleMap.count(FemaleFormID))
	{
		Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " does not exist on regular registry! This should not be possible!", LogType::NPCData, LoggingLevel::critical);

		return FunctionEnd::FailCritical;
	}

	PermanentFemales ThisFemale;
	memset(&ThisFemale, 0, sizeof(ThisFemale)); //force all new data to blank/false

	uint32_t pluginID;

	switch(FemaleFormID >> 24)
	{
		case 0xFF:
		Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " with Form ID " + std::format("{:08X}", FemaleFormID) + " is a dynamic form. Cannot make this NPC persistent.", LogType::NPCData, LoggingLevel::error);
		return FunctionEnd::FailError;

		case 0xFE:
			ThisFemale.LightPlugin = true;
			pluginID = FemaleFormID >> 12;
		break;

		default: pluginID = FemaleFormID >> 24; break;
	}

	const RE::TESFile* plugin;

	if (ThisFemale.LightPlugin) {
		Log("<C++ NPCData> [RegisterPermanent] LIGHT PLUGIN 12 Bit-shifted Plugin ID is: " + std::format("{:08X}", pluginID), LogType::NPCData, LoggingLevel::info);
		pluginID -= 0xFE000;
		Log("<C++ NPCData> [RegisterPermanent] Subtracted 0xFE000 Plugin ID is: " + std::format("{:08X}", pluginID), LogType::NPCData, LoggingLevel::info);
		plugin = DataHandler->LookupLoadedLightModByIndex((uint16_t)pluginID);
	}
	else {
		Log("<C++ NPCData> [RegisterPermanent] FULL PLUGIN 24 Bit-shifted Plugin ID is: " + std::format("{:08X}", pluginID), LogType::NPCData, LoggingLevel::info);
		plugin = DataHandler->LookupLoadedModByIndex((uint8_t)pluginID);
	}

	if(!plugin)
	{
		Log("<C++ NPCData> [RegisterPermanent] Error: Failed to find Plugin Index! Plugin ID is: " + std::format("{:08X}", pluginID), LogType::NPCData, LoggingLevel::error);
		return FunctionEnd::FailError; 
	}

	RE::FormID localID = akFemale->GetLocalFormID();

	if (plugin->GetFilename() == "Skyrim.esm") {
		localID = akFemale->GetFormID();
	}

	for(size_t i = 0; i < PermanentFemaleVector.size(); ++i)
	{
		if(PermanentFemaleVector[i].LocalID == localID)
		{
			Log("<C++ NPCData> [RegisterPermanent] Female " + akName + " from Plugin " + static_cast<std::string>(plugin->GetFilename()) + " with Form IDs: (Full ID | " + std::format("{:08X}", FemaleFormID) + ") (Local ID | " + std::format("{:08X}", localID) + ") already exists in Permanent Female list!", LogType::NPCData, LoggingLevel::warning);
			return FunctionEnd::FailWarn;
		}
	}

	Log("<C++ NPCData> [RegisterPermanent] Actor Form ID is: " + std::format("{:08X}", FemaleFormID), LogType::NPCData);
	Log("<C++ NPCData> [RegisterPermanent] Actor Local Form ID is: " + std::format("{:08X}", localID), LogType::NPCData);
	Log("<C++ NPCData> [RegisterPermanent] Actor Plugin Origin is: " + static_cast<std::string>(plugin->GetFilename()), LogType::NPCData);

	ThisFemale.LocalID = localID;

	const std::string_view plugin_name = plugin->GetFilename();
	memset(ThisFemale.Plugin, 0, sizeof(ThisFemale.Plugin));
	// if plugin_name.size() is larger than sizeof(ThisFemale.Plugin) we write over the buffer length.
	// if plugin_name.size() if equal to 256 then the string will not be null terminated
	memcpy(ThisFemale.Plugin, plugin_name.data(), plugin_name.size());
	strncpy_s(ThisFemale.Name, sizeof(ThisFemale.Name), akName.c_str(), sizeof(ThisFemale.Name));

	RegisteredFemales& reg = RegisteredFemaleMap[FemaleFormID];

	ThisFemale.DefaultRankStrict = reg.DefaultRankStrict;
	ThisFemale.MinimumRankStrict = reg.MinimumRankStrict;

	ThisFemale.DefaultRankTop = reg.DefaultRankTop;
	ThisFemale.MinimumRankTop = reg.MinimumRankTop;

	ThisFemale.DefaultRankBottom = reg.DefaultRankBottom;
	ThisFemale.MinimumRankBottom = reg.MinimumRankBottom;

	ThisFemale.ShynessMode = reg.ShynessMode;
	ThisFemale.SexualityScore = reg.SexualityScore;

	ThisFemale.AllowShameless = reg.AllowShameless;
	ThisFemale.AllowCorruption = reg.AllowCorruption;
	ThisFemale.StrictRules = reg.StrictRules;

	PermanentFemaleVector.emplace_back(ThisFemale);

	return FunctionEnd::Success;
}

int RemovePermanent(RE::StaticFunctionTag*, RE::Actor* akFemale)
{
	if (akFemale == nullptr) {
		Log("<C++ NPCData> [RemovePermanent] Can't remove NULL female!", LogType::NPCData, LoggingLevel::critical);
		return FunctionEnd::FailCritical;
	}
	
	int index = GetInternalPermanentFemaleID(akFemale);

	Log("<C++ NPCData> [RemovePermanent] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") Index is: " + std::to_string(index), LogType::NPCData, LoggingLevel::critical);

	if(index < 0)
	{
		Log("<C++ NPCData> [RemovePermanent] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") does not exist on Permanent list! This should not be possible!", LogType::NPCData, LoggingLevel::critical);

		return FunctionEnd::FailCritical;
	}

	PermanentFemaleVector.erase(PermanentFemaleVector.begin() + index);

	return FunctionEnd::Success;
}

void RemovePermanentAtIndex(int PermanentIndex) {
	PermanentFemaleVector.erase(PermanentFemaleVector.begin() + PermanentIndex);
}

void ExternalRemovePermanentAtIndex(RE::StaticFunctionTag*, int PermanentIndex) {
	RemovePermanentAtIndex(PermanentIndex);
}

void ImportPermanentFemales()
{
	Log("<C++ NPCData> [ImportPermanentFemales] - Function Triggered", LogType::NPCData);
	if (!PermanentFemaleVector.size())
	{
		Log("<C++ NPCData> [ImportPermanentFemales] No Permanent Females to import!", LogType::NPCData, LoggingLevel::warning);

		return;
	}

	float CurrentGameTime = GameCalendar->GetCurrentGameTime();

	for (PermanentFemales& ThePermFemale : PermanentFemaleVector)
	{
		uint32_t ModIndex = ThePermFemale.GetModIndex();

		if (ThePermFemale.LightPlugin) {
			ModIndex += 0xFE000000;
		}
		
		RE::FormID PermanentFemaleFormID = ModIndex | ThePermFemale.LocalID;

		RE::Actor* ValidActor = RE::TESForm::LookupByID<RE::Actor>(PermanentFemaleFormID);
		if (!ValidActor)
		{
			Log("<C++ NPCData> [ImportPermanents] Could not import Female " + std::string(ThePermFemale.GetName()) + " because their Form ID (" + std::format("{:08X}", PermanentFemaleFormID) + ") returns a null pointer!");

			continue;
		}

		RegisteredFemales TheRegFemale;
		memset(&TheRegFemale, 0, sizeof(TheRegFemale));

		memcpy(TheRegFemale.Name, ThePermFemale.Name, sizeof(TheRegFemale.Name));

		TheRegFemale.FemaleFormID = PermanentFemaleFormID;

		TheRegFemale.CurrentRankStrict = ThePermFemale.DefaultRankStrict;
		TheRegFemale.DefaultRankStrict = ThePermFemale.DefaultRankStrict;
		TheRegFemale.MinimumRankStrict = ThePermFemale.MinimumRankStrict;

		TheRegFemale.CurrentRankTop = ThePermFemale.DefaultRankTop;
		TheRegFemale.DefaultRankTop = ThePermFemale.DefaultRankTop;
		TheRegFemale.MinimumRankTop = ThePermFemale.MinimumRankTop;

		TheRegFemale.CurrentRankBottom = ThePermFemale.DefaultRankBottom;
		TheRegFemale.DefaultRankBottom = ThePermFemale.DefaultRankBottom;
		TheRegFemale.MinimumRankBottom = ThePermFemale.MinimumRankBottom;

		TheRegFemale.ShynessMode = ThePermFemale.ShynessMode;
		TheRegFemale.SexualityScore = ThePermFemale.SexualityScore;

		TheRegFemale.AllowShameless = ThePermFemale.AllowShameless;
		TheRegFemale.AllowCorruption = ThePermFemale.AllowCorruption;
		TheRegFemale.StrictRules = ThePermFemale.StrictRules;
		TheRegFemale.UpgradeBlocked = false;

		TheRegFemale.LastUpdateTime = CurrentGameTime;

		RegisteredFemaleMap[PermanentFemaleFormID] = TheRegFemale;
	}
}

void ExternalImportPermanentFemales(RE::StaticFunctionTag*) 
{
	Log("<C++ NPCData> [ImportPermanentFemales] - Function Triggered", LogType::NPCData);
	if (!PermanentFemaleVector.size())
	{
		Log("<C++ NPCData> [ImportPermanentFemales] No Permanent Females to import!", LogType::NPCData, LoggingLevel::warning);

		return;
	}

	float CurrentGameTime = GameCalendar->GetCurrentGameTime();

	for(PermanentFemales& ThePermFemale : PermanentFemaleVector)
	{
		uint32_t ModIndex = ThePermFemale.GetModIndex();

		if (ThePermFemale.LightPlugin) {
			ModIndex += 0xFE000000;
		}
		
		RE::FormID PermanentFemaleFormID = ModIndex | ThePermFemale.LocalID;

		RE::Actor* ValidActor = RE::TESForm::LookupByID<RE::Actor>(PermanentFemaleFormID);
		if(!ValidActor)
		{
			Log("<C++ NPCData> [ImportPermanents] Could not import Female " + std::string(ThePermFemale.GetName()) + " because their Form ID (" + std::format("{:08X}", PermanentFemaleFormID) + ") returns a null pointer!");

			continue;
		}

		RegisteredFemales TheRegFemale;
		memset(&TheRegFemale, 0, sizeof(TheRegFemale));

		memcpy(TheRegFemale.Name, ThePermFemale.Name, sizeof(TheRegFemale.Name));

		TheRegFemale.FemaleFormID = PermanentFemaleFormID;

		TheRegFemale.CurrentRankStrict = ThePermFemale.DefaultRankStrict;
		TheRegFemale.DefaultRankStrict = ThePermFemale.DefaultRankStrict;
		TheRegFemale.MinimumRankStrict = ThePermFemale.MinimumRankStrict;

		TheRegFemale.CurrentRankTop = ThePermFemale.DefaultRankTop;
		TheRegFemale.DefaultRankTop = ThePermFemale.DefaultRankTop;
		TheRegFemale.MinimumRankTop = ThePermFemale.MinimumRankTop;

		TheRegFemale.CurrentRankBottom = ThePermFemale.DefaultRankBottom;
		TheRegFemale.DefaultRankBottom = ThePermFemale.DefaultRankBottom;
		TheRegFemale.MinimumRankBottom = ThePermFemale.MinimumRankBottom;

		TheRegFemale.ShynessMode = ThePermFemale.ShynessMode;
		TheRegFemale.SexualityScore = ThePermFemale.SexualityScore;

		TheRegFemale.AllowShameless = ThePermFemale.AllowShameless;
		TheRegFemale.AllowCorruption = ThePermFemale.AllowCorruption;
		TheRegFemale.StrictRules = ThePermFemale.StrictRules;
		TheRegFemale.UpgradeBlocked = false;

		TheRegFemale.LastUpdateTime = CurrentGameTime;

		RegisteredFemaleMap[PermanentFemaleFormID] = TheRegFemale;
	}
}

void TweakFemaleData
(
	RE::StaticFunctionTag*,
	RE::Actor* akFemale, 
	int StrictRank, int TopRank, int BottomRank, int MinimumStrict, int MinimumTop, int MinimumBottom, int ShynessMode, 
	bool EnableShameless, bool EnableCorrupt, bool MakeDefault, bool IsStrictRules, bool IsUpgradeBlocked
) {
	RE::FormID id = akFemale->GetFormID();

	if (!RegisteredFemaleMap.count(id)) 
	{
		Log("<C++ NPCData> [TweakFemaleData] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", id) + ") does not exist in Female Registry!", LogType::NPCData, LoggingLevel::warning);
		
		return;
	}

	float CurrentGameTime = GameCalendar->GetCurrentGameTime();

	SetActorFactionRank(akFemale, ModestyFaction, HandleInteger(StrictRank));
	SetActorFactionRank(akFemale, TopModestyFaction, HandleInteger(TopRank));
	SetActorFactionRank(akFemale, BottomModestyFaction, HandleInteger(BottomRank));

	RegisteredFemales& ThisFemale = RegisteredFemaleMap[id];

	ThisFemale.ModestyTimer0 = 0;
	ThisFemale.ModestyTimer1 = 0;
	ThisFemale.ModestyTimer2 = 0;
	ThisFemale.ModestyTimer3 = 0;
	ThisFemale.ModestyTimer4 = 0;
	ThisFemale.ModestyTimer5 = 0;
	ThisFemale.ModestyTimer6 = 0;

	ThisFemale.TopModestyTimer0 = 0;
	ThisFemale.TopModestyTimer1 = 0;
	ThisFemale.TopModestyTimer2 = 0;
	ThisFemale.TopModestyTimer3 = 0;

	ThisFemale.BottomModestyTimer0 = 0;
	ThisFemale.BottomModestyTimer1 = 0;
	ThisFemale.BottomModestyTimer2 = 0;
	ThisFemale.BottomModestyTimer3 = 0;

	ThisFemale.CurrentRankStrict = StrictRank;
	ThisFemale.CurrentRankTop = TopRank;
	ThisFemale.CurrentRankBottom = BottomRank;

	ThisFemale.MinimumRankStrict = MinimumStrict;
	ThisFemale.MinimumRankTop = MinimumTop;
	ThisFemale.MinimumRankBottom = MinimumBottom;

	if (MakeDefault)
	{
		ThisFemale.DefaultRankStrict = StrictRank;
		ThisFemale.DefaultRankTop = TopRank;
		ThisFemale.DefaultRankBottom = BottomRank;
	}

	ThisFemale.AllowShameless = EnableShameless;
	ThisFemale.AllowCorruption = EnableCorrupt;
	ThisFemale.StrictRules = IsStrictRules;
	ThisFemale.UpgradeBlocked = IsUpgradeBlocked;

	ThisFemale.ShynessMode = ShynessMode;

	ThisFemale.LastUpdateTime = CurrentGameTime;

	int PermFemaleID = GetInternalPermanentFemaleID(akFemale);
	if (PermFemaleID >= 0)
	{
		PermanentFemaleVector[PermFemaleID].MinimumRankStrict  = MinimumStrict;
		PermanentFemaleVector[PermFemaleID].MinimumRankTop = MinimumTop;
		PermanentFemaleVector[PermFemaleID].MinimumRankBottom = MinimumBottom;

		if (MakeDefault)
		{
			PermanentFemaleVector[PermFemaleID].DefaultRankStrict = StrictRank;
			PermanentFemaleVector[PermFemaleID].DefaultRankTop = TopRank;
			PermanentFemaleVector[PermFemaleID].DefaultRankBottom = BottomRank;
		}

		if (PermanentFemaleVector[PermFemaleID].MinimumRankStrict > PermanentFemaleVector[PermFemaleID].DefaultRankStrict) {
			PermanentFemaleVector[PermFemaleID].DefaultRankStrict = PermanentFemaleVector[PermFemaleID].MinimumRankStrict;
		}

		if (PermanentFemaleVector[PermFemaleID].MinimumRankTop > PermanentFemaleVector[PermFemaleID].DefaultRankTop) {
			PermanentFemaleVector[PermFemaleID].DefaultRankTop = PermanentFemaleVector[PermFemaleID].MinimumRankTop;
		}

		if (PermanentFemaleVector[PermFemaleID].MinimumRankBottom > PermanentFemaleVector[PermFemaleID].DefaultRankBottom) {
			PermanentFemaleVector[PermFemaleID].DefaultRankBottom = PermanentFemaleVector[PermFemaleID].MinimumRankBottom;
		}

		PermanentFemaleVector[PermFemaleID].AllowShameless = EnableShameless;
		PermanentFemaleVector[PermFemaleID].AllowCorruption = EnableCorrupt;
		PermanentFemaleVector[PermFemaleID].StrictRules = IsStrictRules;

		PermanentFemaleVector[PermFemaleID].ShynessMode = ShynessMode;
	}
}

void ResetFemale(RE::Actor* akFemale)
{
	RE::FormID id = akFemale->GetFormID();

	if (!RegisteredFemaleMap.count(id))
	{
		Log("<C++ NPCData> [ResetFemaleModesty] Error: Cannot find " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") in Registered Females list!", LogType::NPCData);

		return;
	}

	RegisteredFemales& ThisFemale = RegisteredFemaleMap[id];

	ThisFemale.CurrentRankStrict = ThisFemale.DefaultRankStrict;
	ThisFemale.CurrentRankTop = ThisFemale.DefaultRankTop;
	ThisFemale.CurrentRankBottom = ThisFemale.DefaultRankBottom;

	ThisFemale.ModestyTimer0 = 0;
	ThisFemale.ModestyTimer1 = 0;
	ThisFemale.ModestyTimer2 = 0;
	ThisFemale.ModestyTimer3 = 0;
	ThisFemale.ModestyTimer4 = 0;
	ThisFemale.ModestyTimer5 = 0;
	ThisFemale.ModestyTimer6 = 0;

	ThisFemale.TopModestyTimer0 = 0;
	ThisFemale.TopModestyTimer1 = 0;
	ThisFemale.TopModestyTimer2 = 0;
	ThisFemale.TopModestyTimer3 = 0;

	ThisFemale.BottomModestyTimer0 = 0;
	ThisFemale.BottomModestyTimer1 = 0;
	ThisFemale.BottomModestyTimer2 = 0;
	ThisFemale.BottomModestyTimer3 = 0;
}

void ExternalResetFemale(RE::StaticFunctionTag*, RE::Actor* akFemale)
{
	ResetFemale(akFemale);
}

void ResetAllFemales(RE::StaticFunctionTag*)
{
	for(auto& [id, ThisFemale] : RegisteredFemaleMap)
	{
		ThisFemale.CurrentRankStrict = ThisFemale.DefaultRankStrict;
		ThisFemale.CurrentRankTop = ThisFemale.DefaultRankTop;
		ThisFemale.CurrentRankBottom = ThisFemale.DefaultRankBottom;

		ThisFemale.ModestyTimer0 = 0;
		ThisFemale.ModestyTimer1 = 0;
		ThisFemale.ModestyTimer2 = 0;
		ThisFemale.ModestyTimer3 = 0;
		ThisFemale.ModestyTimer4 = 0;
		ThisFemale.ModestyTimer5 = 0;
		ThisFemale.ModestyTimer6 = 0;

		ThisFemale.TopModestyTimer0 = 0;
		ThisFemale.TopModestyTimer1 = 0;
		ThisFemale.TopModestyTimer2 = 0;
		ThisFemale.TopModestyTimer3 = 0;

		ThisFemale.BottomModestyTimer0 = 0;
		ThisFemale.BottomModestyTimer1 = 0;
		ThisFemale.BottomModestyTimer2 = 0;
		ThisFemale.BottomModestyTimer3 = 0;
	}
}

void RemoveDeadFemales() {
	Log("<C++ NPCData> [RemoveDeadFemales] Removing Dead Females...", LogType::NPCData);
	RE::Actor* FemaleActor;
	for (auto& [ID, Female] : RegisteredFemaleMap) {
		FemaleActor = RE::TESForm::LookupByID<RE::Actor>(ID);
		if (FemaleActor->IsDead()) {
			DeleteFemaleWithID(ID);
		}
	}
}

void CleanFemaleList() {
	Log("<C++ NPCData> [CleanFemaleLists] Cleaning Female Lists...", LogType::NPCData);
	RE::Actor* FemaleActor;
	for (auto& [ID, Female] : RegisteredFemaleMap) {
		FemaleActor = RE::TESForm::LookupByID<RE::Actor>(ID);

		Log("<C++ NPCModesty> [CleanFemaleLists] Female Map ID is: " + std::format("{0:08X}", ID), LogType::NPCData, LoggingLevel::info);
		Log("<C++ NPCModesty> [CleanFemaleLists] Female Registered ID is: " + std::format("{0:08X}", Female.FemaleFormID), LogType::NPCData, LoggingLevel::info);

		if (FemaleActor == nullptr) {
			Log("<C++ NPCModesty> [ProcessAllNPCModesty] Female is NULL. Removing...", LogType::NPCModesty, LoggingLevel::info);
			DeleteFemaleWithID(ID);
		}
	}
}