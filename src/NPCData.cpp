#include "NPCData.h"
#include "Logger.h"
#include "Core.h"
#include "Config.h"
#include "SaveLoad.h"
#include "NPCScanner.h"
#include "ModIntegration.h"

enum FunctionEnd {
	Success,
	FailWarn,
	FailError,
	FailCritical
};

int FindInVector(std::vector<PermanentFemales> SearchVector, PermanentFemales SearchTarget) {
	int SearchIndex = 0;
	while (SearchIndex < SearchVector.size()) {
		if (
			SearchVector[SearchIndex].GetName() == SearchTarget.GetName()
			&& SearchVector[SearchIndex].GetModIndex() == SearchTarget.GetModIndex()
			&& SearchVector[SearchIndex].LocalID == SearchTarget.LocalID
			) {
			return SearchIndex;
		}
		SearchIndex++;
	}
	return -1;
}

void NPCDataOnRevertCallback() {
	PermanentFemaleVector.clear();
	RegisteredFemaleMap.clear();
}

PermanentFemales ConvertLegacyFemale(LegacyPermanentFemales LegacyFemale) {
	PermanentFemales ConvertedFemale;

	ConvertedFemale.LocalID = LegacyFemale.LocalID;

	memcpy(ConvertedFemale.Name, LegacyFemale.Name, sizeof(ConvertedFemale.Name));
	memcpy(ConvertedFemale.Plugin, LegacyFemale.Plugin, sizeof(ConvertedFemale.Plugin));

	ConvertedFemale.DefaultRankBottom = (UINT8)LegacyFemale.DefaultRankBottom;
	ConvertedFemale.DefaultRankTop = (UINT8)LegacyFemale.DefaultRankTop;
	ConvertedFemale.DefaultRankStrict = (UINT8)LegacyFemale.DefaultRankStrict;

	ConvertedFemale.MinimumRankBottom = (UINT8)LegacyFemale.MinimumRankBottom;
	ConvertedFemale.MinimumRankTop = (UINT8)LegacyFemale.MinimumRankTop;
	ConvertedFemale.MinimumRankStrict = (UINT8)LegacyFemale.MinimumRankStrict;

	ConvertedFemale.SexualityScore = (UINT8)LegacyFemale.SexualityScore;
	ConvertedFemale.ShynessMode = (UINT8)LegacyFemale.ShynessMode;

	ConvertedFemale.AllowCorruption = LegacyFemale.AllowCorruption;
	ConvertedFemale.AllowShameless = LegacyFemale.AllowShameless;
	ConvertedFemale.StrictRules = LegacyFemale.StrictRules;

	return ConvertedFemale;
}

int GetInternalPermanentFemaleID(RE::Actor* akFemale)
{
	Log("<C++ NPCData> [GetInternalPermanentFemaleID] Getting Female Index...", Logger::LogType::NPCData, Logger::LoggingLevel::info);
	
	for(int Index = 0; Index < PermanentFemaleVector.size(); ++Index)
	{
		UINT32 ModIndex = PermanentFemaleVector[Index].GetModIndex();

		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Checking Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()), Logger::LogType::NPCData, Logger::LoggingLevel::info);
		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") ModIndex is: " + std::format("{:08X}", ModIndex), Logger::LogType::NPCData, Logger::LoggingLevel::info);
		
		if (PermanentFemaleVector[Index].GetPluginFile()->IsLight()) {
			ModIndex += 0xFE000000;
		}

		UINT32 akLocalID = PermanentFemaleVector[Index].LocalID;
		RE::FormID PermanentFemaleFormID = ModIndex + akLocalID;

		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") LocalID is: " + std::format("{:08X}", akLocalID), Logger::LogType::NPCData, Logger::LoggingLevel::info);
		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") FullID should be: " + std::format("{:08X}", PermanentFemaleFormID), Logger::LogType::NPCData, Logger::LoggingLevel::info);
		
		if (PermanentFemaleFormID == akFemale->GetFormID()) { 
			Log("<C++ NPCData> [GetInternalPermanentFemaleID] Match Found!", Logger::LogType::NPCData, Logger::LoggingLevel::info);
			return Index; 
		}

		Log("<C++ NPCData> [GetInternalPermanentFemaleID] Match not found. Checking next Permanent Female...", Logger::LogType::NPCData, Logger::LoggingLevel::info);
	}

	Log("<C++ NPCData> [GetInternalPermanentFemaleID] Could not find " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") in Permanent Female List", Logger::LogType::NPCData, Logger::LoggingLevel::warning);

	return -1;
}

void ImportSinglePermanent(int InternalID) {
	float CurrentGameTime = GameCalendar->GetCurrentGameTime();
	
	PermanentFemales& ThePermFemale = PermanentFemaleVector[InternalID];
	
	uint32_t ModIndex = ThePermFemale.GetModIndex();

	if (ThePermFemale.GetPluginFile()->IsLight()) {
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

void RegisterFemale(RE::Actor* akFemale, float CurrentGameTime, UINT8 SexualityScore) {
	if (akFemale == nullptr) {
		Log("<C++ NPCData> [RegisterFemale] Cannot register NULL actor!", Logger::LogType::NPCData, Logger::LoggingLevel::warning);
		return;
	}
	
	RE::FormID FemaleForm = akFemale->GetFormID();
	std::string FemaleName = akFemale->GetName();

	Log("<C++ NPCData> [RegisterFemale] Female Form ID: " + std::format("{:08X}", FemaleForm), Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterFemale] Female Name: " + FemaleName, Logger::LogType::NPCData);

	if (FemaleName == "") {
		Log("<C++ NPCData> [RegisterFemale] Cannot Register Unnamed Female!", Logger::LogType::NPCData, Logger::LoggingLevel::warning);
		return;
	}

	int PermanentID = GetInternalPermanentFemaleID(akFemale);
	if (PermanentID >= 0) {
		Log("<C++ NPCData> [RegisterFemale] Female exists on Permanent List. Re-importing female...", Logger::LogType::NPCData);
		ImportSinglePermanent(PermanentID);
		return;
	}

	UINT8 ShynessMode = ShySex::Men; //Default to Men (zero) if no shyness otherwise found
	UINT8 StrictModesty = GetRandomizedModesty(akFemale, false);
	UINT8 TopModesty = SimpleModestyLevel::Modest;
	UINT8 BottomModesty = TopModesty;

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

	SetActorFactionRank(akFemale, ModestyFaction, StrictModesty);
	SetActorFactionRank(akFemale, TopModestyFaction, TopModesty);
	SetActorFactionRank(akFemale, BottomModestyFaction, BottomModesty);

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
		UINT8 ShyRoll = Randomizer(0,2);
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

	Log("<C++ NPCData> [RegisterFemale] Registered Female: " + FemaleName + " | Form ID: " + std::format("{:08X}", FemaleForm) + " | Internal ID: " + std::to_string(RegisteredFemaleMap.size()), Logger::LogType::Core, Logger::LoggingLevel::info);
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

		UINT8 index = 0;
		while (index < TotalFactions) {
			if (akFemale->IsInFaction(AllFactions[index]) == false) {
				akFemale->RemoveFromFaction(AllFactions[index]);
			}
			index++;
		}
	}
	
	RegisteredFemaleMap.clear();
}

void RegisterRosa(float CurrentGameTime, UINT8 SexualityScore) {
	RE::FormID RosaForm = Rosa->GetFormID();
	RE::FormID RosaBaseForm = Rosa->GetActorBase()->GetFormID();
	std::string RosaEditorID = static_cast<std::string>(Rosa->GetFormEditorID());
	std::string RosaBaseEditorID = static_cast<std::string>(Rosa->GetActorBase()->GetFormEditorID());
	std::string RosaName = static_cast<std::string>(Rosa->GetName());
	std::string RosaBaseName = static_cast<std::string>(Rosa->GetActorBase()->GetFormEditorID());

	Log("<C++ NPCData> [RegisterRosa] Rosa Form ID: " + std::format("{:08X}", RosaForm), Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Base Form ID: " + std::format("{:08X}", RosaBaseForm), Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Editor ID: " + RosaEditorID, Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Base Editor ID: " + RosaBaseEditorID, Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Name: " + RosaName, Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Base Name: " + RosaBaseName, Logger::LogType::NPCData);

	UINT8 ShynessMode;

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

	ThisFemale.DefaultRankStrict = StrictModestyLevel::Shameless;
	ThisFemale.CurrentRankStrict = StrictModestyLevel::Shameless;
	ThisFemale.MinimumRankStrict = StrictModestyLevel::Shameless;

	ThisFemale.DefaultRankTop = SimpleModestyLevel::Shameless;
	ThisFemale.CurrentRankTop = SimpleModestyLevel::Shameless;
	ThisFemale.MinimumRankTop = SimpleModestyLevel::Shameless;

	ThisFemale.DefaultRankBottom = SimpleModestyLevel::Shameless;
	ThisFemale.CurrentRankBottom = SimpleModestyLevel::Shameless;
	ThisFemale.MinimumRankBottom = SimpleModestyLevel::Shameless;

	ThisFemale.ShynessMode = ShynessMode;
	ThisFemale.SexualityScore = SexualityScore;

	ThisFemale.AllowShameless = true;
	ThisFemale.AllowCorruption = false;
	ThisFemale.StrictRules = Configuration::StrictModestyRules;
	ThisFemale.UpgradeBlocked = false;

	ThisFemale.LastUpdateTime = CurrentGameTime;

	RegisteredFemaleMap[RosaForm] = ThisFemale;
}

int RegisterPermanent(RE::StaticFunctionTag*, RE::Actor* akFemale) {
	std::string akName = akFemale->GetName();
	RE::FormID FemaleFormID = akFemale->GetFormID();

	if (!RegisteredFemaleMap.count(FemaleFormID))
	{
		Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " does not exist on regular registry! This should not be possible!", Logger::LogType::NPCData, Logger::LoggingLevel::critical);

		return FunctionEnd::FailCritical;
	}

	uint32_t pluginID;

	const RE::TESFile* plugin = nullptr;

	switch(FemaleFormID >> 24)
	{
		case 0xFF:
		Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " with Form ID " + std::format("{:08X}", FemaleFormID) + " is a dynamic form. Cannot make this NPC persistent.", Logger::LogType::NPCData, Logger::LoggingLevel::error);
		return FunctionEnd::FailError;

		case 0xFE:
			pluginID = FemaleFormID >> 12;
			plugin = GameDataHandler->LookupLoadedLightModByIndex((UINT16)pluginID);
			plugin ? Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " with Form ID " + std::format("{:08X}", FemaleFormID) + " was found in LIGHT plugin: " + (std::string)plugin->GetFilename(), Logger::LogType::NPCData, Logger::LoggingLevel::info) : Log("<C++ NPCData> [RegisterPermanent] ERROR: NPC " + akName + " with Form ID " + std::format("{:08X}", FemaleFormID) + " was NOT found in a LIGHT plugin...", Logger::LogType::NPCData, Logger::LoggingLevel::error);
		break;

		default: 
			pluginID = FemaleFormID >> 24;
			plugin = GameDataHandler->LookupLoadedModByIndex((UINT8)pluginID);
			plugin ? Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " with Form ID " + std::format("{:08X}", FemaleFormID) + " was found in FULL plugin: " + (std::string)plugin->GetFilename(), Logger::LogType::NPCData, Logger::LoggingLevel::info) : Log("<C++ NPCData> [RegisterPermanent] ERROR: NPC " + akName + " with Form ID " + std::format("{:08X}", FemaleFormID) + " was NOT found in a FULL plugin...", Logger::LogType::NPCData, Logger::LoggingLevel::error);
			break;
	}

	if(!plugin)
	{
		//Log("<C++ NPCData> [RegisterPermanent] Error: Failed to find Plugin for Female " + std::string(akFemale->GetName()), Logger::NPCData, Logger::error);
		return FunctionEnd::FailError; 
	}

	PermanentFemales ThisFemale;

	RE::FormID localID = akFemale->GetLocalFormID();

	if (plugin->GetFilename() == "Skyrim.esm") {
		localID = akFemale->GetFormID();
	}

	for(size_t i = 0; i < PermanentFemaleVector.size(); ++i)
	{
		if(PermanentFemaleVector[i].LocalID == localID)
		{
			Log("<C++ NPCData> [RegisterPermanent] Female " + akName + " from Plugin " + std::string(plugin->GetFilename()) + " with Form IDs: (Full ID | " + std::format("{:08X}", FemaleFormID) + ") (Local ID | " + std::format("{:08X}", localID) + ") already exists in Permanent Female list!", Logger::LogType::NPCData, Logger::LoggingLevel::warning);
			return FunctionEnd::FailWarn;
		}
	}

	Log("<C++ NPCData> [RegisterPermanent] Actor Form ID is: " + std::format("{:08X}", FemaleFormID), Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterPermanent] Actor Local Form ID is: " + std::format("{:08X}", localID), Logger::LogType::NPCData);
	Log("<C++ NPCData> [RegisterPermanent] Actor Plugin Origin is: " + std::string(plugin->GetFilename()), Logger::LogType::NPCData);

	memset(&ThisFemale, 0, sizeof(ThisFemale)); //force all new data to blank/false

	ThisFemale.LocalID = localID;

	const std::string_view plugin_name = plugin->GetFilename();
	// if plugin_name.size() is larger than sizeof(ThisFemale.Plugin) we write over the buffer length.
	// if plugin_name.size() is equal to 256 then the string will not be null terminated

	if (plugin_name.size() > 255) {
		Log("<C++ NPCData> [RegisterPermanent] Plugin Name (" + std::string(plugin->GetFilename()) + ") is too long", Logger::LogType::NPCData);
		return FunctionEnd::FailCritical;
	}

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
		Log("<C++ NPCData> [RemovePermanent] Can't remove NULL female!", Logger::LogType::NPCData, Logger::LoggingLevel::critical);
		return FunctionEnd::FailCritical;
	}
	
	int index = GetInternalPermanentFemaleID(akFemale);

	Log("<C++ NPCData> [RemovePermanent] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") Index is: " + std::to_string(index), Logger::LogType::NPCData, Logger::LoggingLevel::critical);

	if(index < 0)
	{
		Log("<C++ NPCData> [RemovePermanent] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") does not exist on Permanent list! This should not be possible!", Logger::LogType::NPCData, Logger::LoggingLevel::critical);

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

bool ValidatePermanentFemale(PermanentFemales ThisPermanentFemale) {
	UINT32 ModIndex = ThisPermanentFemale.GetModIndex();

	const RE::TESFile* PluginFile = ThisPermanentFemale.GetPluginFile();

	if (!PluginFile) {
		Log("<C++ NPCData> [ValidatePermanentFemale] Could not find plugin file " + std::string(ThisPermanentFemale.GetPluginName()) + " for Female " + std::string(ThisPermanentFemale.GetName()), Logger::NPCData, Logger::warning);
		return false;
	}

	if (PluginFile->IsLight()) {
		ModIndex += 0xFE000000;
	}

	if (ModIndex >= 0xFF000000) {
		Log("<C++ NPCData> [ValidatePermanentFemale] Female " + std::string(ThisPermanentFemale.GetName()) + " is not valid. Mod Index is " + std::to_string(ModIndex), Logger::NPCData, Logger::warning);
		return false;
	}

	RE::FormID PermanentFemaleFormID = ModIndex | ThisPermanentFemale.LocalID;

	if (PermanentFemaleFormID >= 0xFF000000) {
		Log("<C++ NPCData> [ValidatePermanentFemale] Female " + std::string(ThisPermanentFemale.GetName()) + " is not valid. Form ID is " + std::format("{:08X}", PermanentFemaleFormID), Logger::NPCData, Logger::warning);
		return false;
	}

	RE::Actor* ValidActor = RE::TESForm::LookupByID<RE::Actor>(PermanentFemaleFormID);
	if (!ValidActor) {
		Log("<C++ NPCData> [ValidatePermanentFemale] Female " + std::string(ThisPermanentFemale.GetName()) + " is not valid because their Form ID (" + std::format("{:08X}", PermanentFemaleFormID) + ") returns a null pointer when cast as an Actor!", Logger::NPCData, Logger::warning);
		return false;
	}

	if (ThisPermanentFemale.DefaultRankBottom > 3 || ThisPermanentFemale.DefaultRankTop > 3 || ThisPermanentFemale.DefaultRankStrict > 6
		|| ThisPermanentFemale.MinimumRankBottom > 3 || ThisPermanentFemale.MinimumRankTop > 3 || ThisPermanentFemale.MinimumRankStrict > 6) {
		Log("<C++ NPCData> [ValidatePermanentFemale] Female " + std::string(ThisPermanentFemale.GetName()) + " is not valid because one of their modesty rank settings is out of range!", Logger::NPCData, Logger::warning);
		return false;
	}

	return true;
}

void ImportPermanentFemales()
{
	Log("<C++ NPCData> [ImportPermanentFemales] - Function Triggered", Logger::LogType::NPCData);
	if (!PermanentFemaleVector.size())
	{
		Log("<C++ NPCData> [ImportPermanentFemales] No Permanent Females to import!", Logger::LogType::NPCData, Logger::LoggingLevel::warning);

		return;
	}

	float CurrentGameTime = GameCalendar->GetCurrentGameTime();

	for (PermanentFemales& ThePermFemale : PermanentFemaleVector)
	{
		UINT32 ModIndex = ThePermFemale.GetModIndex();

		if (ThePermFemale.GetPluginFile()->IsLight()) {
			ModIndex += 0xFE000000;
		}
		
		RE::FormID PermanentFemaleFormID = ModIndex | ThePermFemale.LocalID;

		RE::Actor* ValidActor = RE::TESForm::LookupByID<RE::Actor>(PermanentFemaleFormID);
		if (!ValidActor) {
			Log("<C++ NPCData> [ImportPermanents] Could not import Female " + std::string(ThePermFemale.GetName()) + " because their Form ID (" + std::format("{:08X}", PermanentFemaleFormID) + ") returns a null pointer!", Logger::NPCData, Logger::warning);

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
	Log("<C++ NPCData> [ImportPermanentFemales] - Function Triggered", Logger::LogType::NPCData);
	if (!PermanentFemaleVector.size())
	{
		Log("<C++ NPCData> [ImportPermanentFemales] No Permanent Females to import!", Logger::LogType::NPCData, Logger::LoggingLevel::warning);

		return;
	}

	float CurrentGameTime = GameCalendar->GetCurrentGameTime();

	for(PermanentFemales& ThePermFemale : PermanentFemaleVector)
	{
		UINT32 ModIndex = ThePermFemale.GetModIndex();

		if (ThePermFemale.GetPluginFile()->IsLight()) {
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
		Log("<C++ NPCData> [TweakFemaleData] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", id) + ") does not exist in Female Registry!", Logger::LogType::NPCData, Logger::LoggingLevel::warning);
		
		return;
	}

	float CurrentGameTime = GameCalendar->GetCurrentGameTime();

	SetActorFactionRank(akFemale, ModestyFaction, (INT8)StrictRank);
	SetActorFactionRank(akFemale, TopModestyFaction, (INT8)TopRank);
	SetActorFactionRank(akFemale, BottomModestyFaction, (INT8)BottomRank);

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

	ThisFemale.CurrentRankStrict = (UINT8)StrictRank;
	ThisFemale.CurrentRankTop = (UINT8)TopRank;
	ThisFemale.CurrentRankBottom = (UINT8)BottomRank;

	ThisFemale.MinimumRankStrict = (UINT8)MinimumStrict;
	ThisFemale.MinimumRankTop = (UINT8)MinimumTop;
	ThisFemale.MinimumRankBottom = (UINT8)MinimumBottom;

	if (MakeDefault)
	{
		ThisFemale.DefaultRankStrict = (UINT8)StrictRank;
		ThisFemale.DefaultRankTop = (UINT8)TopRank;
		ThisFemale.DefaultRankBottom = (UINT8)BottomRank;
	}

	ThisFemale.AllowShameless = EnableShameless;
	ThisFemale.AllowCorruption = EnableCorrupt;
	ThisFemale.StrictRules = IsStrictRules;
	ThisFemale.UpgradeBlocked = IsUpgradeBlocked;

	ThisFemale.ShynessMode = (UINT8)ShynessMode;

	ThisFemale.LastUpdateTime = CurrentGameTime;

	int PermFemaleID = GetInternalPermanentFemaleID(akFemale);
	if (PermFemaleID >= 0)
	{
		PermanentFemaleVector[PermFemaleID].MinimumRankStrict  = (UINT8)MinimumStrict;
		PermanentFemaleVector[PermFemaleID].MinimumRankTop = (UINT8)MinimumTop;
		PermanentFemaleVector[PermFemaleID].MinimumRankBottom = (UINT8)MinimumBottom;

		if (MakeDefault)
		{
			PermanentFemaleVector[PermFemaleID].DefaultRankStrict = (UINT8)StrictRank;
			PermanentFemaleVector[PermFemaleID].DefaultRankTop = (UINT8)TopRank;
			PermanentFemaleVector[PermFemaleID].DefaultRankBottom = (UINT8)BottomRank;
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

		PermanentFemaleVector[PermFemaleID].ShynessMode = (UINT8)ShynessMode;
	}
}

void ResetFemale(RE::Actor* akFemale)
{
	RE::FormID id = akFemale->GetFormID();

	if (!RegisteredFemaleMap.count(id))
	{
		Log("<C++ NPCData> [ResetFemaleModesty] Error: Cannot find " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") in Registered Females list!", Logger::LogType::NPCData);

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

void CleanFemaleList() {
	Log("<C++ NPCData> [CleanFemaleLists] Cleaning Female Lists...", Logger::LogType::NPCData);
	RE::Actor* FemaleActor;
	for (auto& [ID, Female] : RegisteredFemaleMap) {
		FemaleActor = RE::TESForm::LookupByID<RE::Actor>(ID);

		Log("<C++ NPCModesty> [CleanFemaleLists] Female Map ID is: " + std::format("{0:08X}", ID), Logger::LogType::NPCData, Logger::LoggingLevel::info);
		Log("<C++ NPCModesty> [CleanFemaleLists] Female Registered ID is: " + std::format("{0:08X}", Female.FemaleFormID), Logger::LogType::NPCData, Logger::LoggingLevel::info);

		if (FemaleActor == nullptr || FemaleActor->IsDead(false)) {
			Log("<C++ NPCModesty> [CleanFemaleLists] Female is NULL or Dead. Removing...", Logger::LogType::NPCModesty, Logger::LoggingLevel::info);
			DeleteFemaleWithID(ID);
		}
	}
}