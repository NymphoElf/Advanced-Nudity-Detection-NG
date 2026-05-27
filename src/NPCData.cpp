#include "NPCData.h"
#include "Logger.h"
#include "Core.h"
#include "Config.h"
#include "SaveLoad.h"

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
	for(int Index = 0; Index < PermanentFemaleVector.size(); ++Index)
	{
		uint32_t ModIndex = PermanentFemaleVector[Index].GetModIndex();

		RE::FormID PermanentFemaleFormID = ModIndex | PermanentFemaleVector[Index].LocalID;
		if(PermanentFemaleFormID == akFemale->GetFormID()) { return Index; }
	}

	Log("<C++ NPCData> [GetInternalPermanentFemaleID] Could not find " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") in Permanent Female List", LogType::NPCData, LoggingLevel::warning);

	return -1;
}

void RegisterFemale(RE::Actor* akFemale, float CurrentGameTime, int SexualityScore) {
	int FemaleForm = akFemale->GetFormID();
	std::string FemaleName = akFemale->GetName();

	Log("<C++ NPCData> [RegisterFemale] Female Form ID: " + std::format("{:08X}", FemaleForm), LogType::NPCData);
	Log("<C++ NPCData> [RegisterFemale] Female Name: " + FemaleName, LogType::NPCData);

	if (FemaleName == "") {
		Log("<C++ NPCData> [RegisterFemale] Cannot Register Unnamed Female!", LogType::NPCData, LoggingLevel::warning);
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

void DeleteFemale(RE::StaticFunctionTag*, RE::Actor* akfemale) 
{
	RegisteredFemaleMap.erase(akfemale->GetFormID());
}

void DeleteAllFemales(RE::StaticFunctionTag*)
{
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

	Log("DEBUG | REGISTER PERMANENT | Female Form ID (Pre-shift) is: " + std::format("{:08X}", FemaleFormID));
	RE::FormID testID = FemaleFormID >> 24;
	Log("DEBUG | REGISTER PERMANENT | Female Form ID (Post-shift) is: " + std::format("{:08X}", testID));

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

	const RE::TESFile* plugin = DataHandler->LookupLoadedModByIndex((uint8_t)pluginID);
	if(!plugin)
	{
		Log("<C++ NPCData> [RegisterPermanent] <TODO>", LogType::NPCData, LoggingLevel::error);
		return FunctionEnd::FailError; 
	}

	RE::FormID localID = akFemale->GetLocalFormID();

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
	int index = GetInternalPermanentFemaleID(akFemale);

	if(index < 0)
	{
		Log("<C++ NPCData> [RemovePermanent] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") does not exist on Permanent list! This should not be possible!", LogType::NPCData, LoggingLevel::critical);

		return FunctionEnd::FailCritical;
	}

	PermanentFemaleVector.erase(PermanentFemaleVector.begin() + index);

	return FunctionEnd::Success;
}

void ImportPermanentFemales(RE::StaticFunctionTag*, float CurrentGameTime) 
{
	if (!PermanentFemaleVector.size())
	{
		Log("<C++ NPCData> [ImportPermanentFemales] No Permanent Females to import!", LogType::NPCData, LoggingLevel::warning);

		return;
	}

	for(PermanentFemales& ThisFemale : PermanentFemaleVector)
	{
		RE::FormID PermanentFemaleFormID = ThisFemale.GetModIndex() | ThisFemale.LocalID;

		RE::Actor* ValidActor = RE::TESForm::LookupByID<RE::Actor>(PermanentFemaleFormID);
		if(!ValidActor)
		{
			Log("<C++ NPCData> [ImportPermanents] Could not import Female " + std::string(ThisFemale.GetName()) + " because their Form ID (" + std::format("{:08X}", PermanentFemaleFormID) + ") returns a null pointer!");

			continue;
		}

		RegisteredFemales ImportThisFemale;
		memset(&ImportThisFemale, 0, sizeof(ImportThisFemale));

		memcpy(ImportThisFemale.Name, ThisFemale.Name, sizeof(ImportThisFemale.Name));

		ImportThisFemale.FemaleFormID = PermanentFemaleFormID;

		ImportThisFemale.CurrentRankStrict = ThisFemale.DefaultRankStrict;
		ImportThisFemale.DefaultRankStrict = ThisFemale.DefaultRankStrict;
		ImportThisFemale.MinimumRankStrict = ThisFemale.MinimumRankStrict;

		ImportThisFemale.CurrentRankTop = ThisFemale.DefaultRankTop;
		ImportThisFemale.DefaultRankTop = ThisFemale.DefaultRankTop;
		ImportThisFemale.MinimumRankTop = ThisFemale.MinimumRankTop;

		ImportThisFemale.CurrentRankBottom = ThisFemale.DefaultRankBottom;
		ImportThisFemale.DefaultRankBottom = ThisFemale.DefaultRankBottom;
		ImportThisFemale.MinimumRankBottom = ThisFemale.MinimumRankBottom;

		ImportThisFemale.ShynessMode = ThisFemale.ShynessMode;
		ImportThisFemale.SexualityScore = ThisFemale.SexualityScore;

		ImportThisFemale.AllowShameless = ThisFemale.AllowShameless;
		ImportThisFemale.AllowCorruption = ThisFemale.AllowCorruption;
		ImportThisFemale.StrictRules = ThisFemale.StrictRules;
		ImportThisFemale.UpgradeBlocked = false;

		ImportThisFemale.LastUpdateTime = CurrentGameTime;

		RegisteredFemaleMap[PermanentFemaleFormID] = ImportThisFemale;
	}
}

void TweakFemaleData
(
	RE::StaticFunctionTag*,
	RE::Actor* akFemale, 
	int StrictRank, int TopRank, int BottomRank, int MinimumStrict, int MinimumTop, int MinimumBottom, int ShynessMode, 
	bool EnableShameless, bool EnableCorrupt, bool MakeDefault, bool IsStrictRules, bool IsUpgradeBlocked,
	float CurrentGameTime
) {
	RE::FormID id = akFemale->GetFormID();

	if (!RegisteredFemaleMap.count(id)) 
	{
		Log("<C++ NPCData> [TweakFemaleData] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", id) + ") does not exist in Female Registry!", LogType::NPCData, LoggingLevel::warning);
		
		return;
	}

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
		Log("<C++ NPCData> [ResetFemaleModesty] Error: Cannot find " + std::string(akFemale->GetName()) + " (" + std::format("{:08X}", akFemale->GetFormID()) + ") in Registered Females list!");

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