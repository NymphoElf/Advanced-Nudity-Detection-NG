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

int GetInternalPermanentFemaleID(RE::Actor* akFemale)
{
	for(int i = 0; i < permanentfemales.size(); ++i)
	{
		uint32_t modindex = permanentfemales[i].GetModIndex();

		RE::FormID id = (modindex << 24) | permanentfemales[i].LocalID;
		if(id == akFemale->GetFormID()) { return i; }
	}

	Log("<C++ NPCData> [GetInternalPermanentFemaleID] Could not find " + std::string(akFemale->GetName()) + " (" + std::format("{:#x}", akFemale->GetFormID()) + ") in Permanent Female List", LogType::NPCData, LoggingLevel::warning);

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

	RegisteredFemales female;
	memset(&female, 0, sizeof(female)); // intialize all data as 0

	strncpy_s(female.Name, sizeof(female.Name), FemaleName.c_str(), sizeof(female.Name));

	female.id = FemaleForm;

	female.DefaultRankStrict = StrictModesty;
	female.CurrentRankStrict = StrictModesty;

	female.DefaultRankTop = TopModesty;
	female.CurrentRankTop = TopModesty;

	female.DefaultRankBottom = BottomModesty;
	female.CurrentRankBottom = BottomModesty;

	female.ShynessMode = ShynessMode;
	female.SexualityScore = SexualityScore;

	female.AllowShameless = Configuration::NPCShamelessByDefault;
	female.AllowCorruption = Configuration::NPCCorruptionByDefault;
	female.StrictRules = Configuration::NPCStrictRulesByDefault;
	female.UpgradeBlocked = false;

	female.LastUpdateTime = CurrentGameTime;

	registeredfemales[FemaleForm] = female;

	Log("<C++ NPCData> [RegisterFemale] Registered Female: " + FemaleName + " | Form ID: " + std::format("{:#x}", FemaleForm) + " | Internal ID: " + std::to_string(registeredfemales.size()), LogType::Core, LoggingLevel::info);
}

void DeleteFemale(RE::StaticFunctionTag*, RE::Actor* akfemale) 
{
	registeredfemales.erase(akfemale->GetFormID());
}

void DeleteAllFemales(RE::StaticFunctionTag*)
{
	registeredfemales.clear();
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

	RegisteredFemales female;
	memset(&female, 0, sizeof(female)); // intialize all data as 0

	strncpy_s(female.Name, sizeof(female.Name), RosaName.c_str(), sizeof(female.Name));

	female.id = RosaForm;

	female.DefaultRankStrict = StrictModestyLevel::Immodest;
	female.CurrentRankStrict = StrictModestyLevel::Immodest;
	female.MinimumRankStrict = StrictModestyLevel::Immodest;

	female.DefaultRankTop = SimpleModestyLevel::Immodest;
	female.CurrentRankTop = SimpleModestyLevel::Immodest;
	female.MinimumRankTop = SimpleModestyLevel::Immodest;

	female.DefaultRankBottom = SimpleModestyLevel::Immodest;
	female.CurrentRankBottom = SimpleModestyLevel::Immodest;
	female.MinimumRankBottom = SimpleModestyLevel::Immodest;

	female.ShynessMode = ShynessMode;
	female.SexualityScore = SexualityScore;

	female.AllowShameless = Configuration::NPCShamelessByDefault;
	female.AllowCorruption = Configuration::NPCCorruptionByDefault;
	female.StrictRules = Configuration::StrictModestyRules;
	female.UpgradeBlocked = false;

	female.LastUpdateTime = CurrentGameTime;

	registeredfemales[RosaForm] = female;
}

int RegisterPermanent(RE::StaticFunctionTag*, RE::Actor* akFemale) 
{
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	std::string akName = akFemale->GetName();
	RE::FormID id = akFemale->GetFormID();

	if (!registeredfemales.count(id)) 
	{
		Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " does not exist on regular registry! This should not be possible!", LogType::NPCData, LoggingLevel::critical);

		return FunctionEnd::FailCritical;
	}

	PermanentFemales female;
	uint32_t pluginID;

	switch(id >> 24)
	{
		case 0xFF:
		Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " with Form ID " + std::format("{:#x}", id) + " is a dynamic form. Cannot make this NPC persistent.", LogType::NPCData, LoggingLevel::error);
		return FunctionEnd::FailError;

		case 0xFE:
		female.LightPlugin = true;
		pluginID = id >> 12;
		break;

		default: pluginID = id >> 24; break;
	}

	const RE::TESFile* plugin = DataHandler->LookupLoadedModByIndex((uint8_t)pluginID);
	if(!plugin)
	{
		Log("<C++ NPCData> [RegisterPermanent] <TODO>", LogType::NPCData, LoggingLevel::error);
		return FunctionEnd::FailError; 
	}

	RE::FormID localID = akFemale->GetLocalFormID();

	for(size_t i = 0; i < permanentfemales.size(); ++i)
	{
		if(permanentfemales[i].LocalID == localID)
		{
			Log("<C++ NPCData> [RegisterPermanent] Female " + akName + " from Plugin " + static_cast<std::string>(plugin->GetFilename()) + " with Form IDs: (Full ID | " + std::format("{:#x}", id) + ") (Local ID | " + std::format("{:#x}", localID) + ") already exists in Permanent Female list!", LogType::NPCData, LoggingLevel::warning);
			return FunctionEnd::FailWarn;
		}
	}

	Log("<C++ NPCData> [RegisterPermanent] Actor Form ID is: " + std::format("{:#x}", id), LogType::NPCData);
	Log("<C++ NPCData> [RegisterPermanent] Actor Local Form ID is: " + std::format("{:#x}", localID), LogType::NPCData);
	Log("<C++ NPCData> [RegisterPermanent] Actor Plugin Origin is: " + static_cast<std::string>(plugin->GetFilename()), LogType::NPCData);

	female.LocalID = localID;

	const std::string_view plugin_name = plugin->GetFilename();
	memset(female.Plugin, 0, sizeof(female.Plugin));
	// if plugin_name.size() is larger than sizeof(female.Plugin) we write over the buffer length.
	// if plugin_name.size() if equal to 256 then the string will not be null terminated
	memcpy(female.Plugin, plugin_name.data(), plugin_name.size());
	strncpy_s(female.Name, sizeof(female.Name), akName.c_str(), sizeof(female.Name));

	RegisteredFemales& reg = registeredfemales[id];

	female.DefaultRankStrict = reg.DefaultRankStrict;
	female.MinimumRankStrict = reg.MinimumRankStrict;

	female.DefaultRankTop = reg.DefaultRankTop;
	female.MinimumRankTop = reg.MinimumRankTop;

	female.DefaultRankBottom = reg.DefaultRankBottom;
	female.MinimumRankBottom = reg.MinimumRankBottom;

	female.ShynessMode = reg.ShynessMode;
	female.SexualityScore = reg.SexualityScore;

	female.AllowShameless = reg.AllowShameless;
	female.AllowCorruption = reg.AllowCorruption;
	female.StrictRules = reg.StrictRules;

	permanentfemales.emplace_back(female);

	return FunctionEnd::Success;
}

int RemovePermanent(RE::StaticFunctionTag*, RE::Actor* akFemale)
{
	int index = GetInternalPermanentFemaleID(akFemale);

	if(index < 0)
	{
		Log("<C++ NPCData> [RemovePermanent] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:#x}", akFemale->GetFormID()) + ") does not exist on Permanent list! This should not be possible!", LogType::NPCData, LoggingLevel::critical);

		return FunctionEnd::FailCritical;
	}

	permanentfemales.erase(permanentfemales.begin() + index);

	return FunctionEnd::Success;
}

void ImportPermanentFemales(RE::StaticFunctionTag*, float CurrentGameTime) 
{
	if (!permanentfemales.size())
	{
		Log("<C++ NPCData> [ImportPermanentFemales] No Permanent Females to import!", LogType::NPCData, LoggingLevel::warning);

		return;
	}

	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	for(PermanentFemales& female : permanentfemales)
	{
		RE::FormID id = female.GetModIndex() << 24 | female.LocalID;

		RE::Actor* actor = RE::TESForm::LookupByID<RE::Actor>(id);
		if(!actor)
		{
			Log("<C++ NPCData> [ImportPermanents] Could not import female " + std::string(female.GetName()) + " because their Form ID (" + std::format("{:#x}", id) + ") returns a null pointer!");

			continue;
		}

		RegisteredFemales f;
		memset(&f, 0, sizeof(f));

		memcpy(f.Name, female.Name, sizeof(f.Name));

		f.id = id;

		f.CurrentRankStrict = female.DefaultRankStrict;
		f.DefaultRankStrict = female.DefaultRankStrict;
		f.MinimumRankStrict = female.MinimumRankStrict;

		f.CurrentRankTop = female.DefaultRankTop;
		f.DefaultRankTop = female.DefaultRankTop;
		f.MinimumRankTop = female.MinimumRankTop;

		f.CurrentRankBottom = female.DefaultRankBottom;
		f.DefaultRankBottom = female.DefaultRankBottom;
		f.MinimumRankBottom = female.MinimumRankBottom;

		f.ShynessMode = female.ShynessMode;
		f.SexualityScore = female.SexualityScore;

		f.AllowShameless = female.AllowShameless;
		f.AllowCorruption = female.AllowCorruption;
		f.StrictRules = female.StrictRules;
		f.UpgradeBlocked = false;

		f.LastUpdateTime = CurrentGameTime;

		registeredfemales[id] = f;
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

	if (!registeredfemales.count(id)) 
	{
		Log("<C++ NPCData> [TweakFemaleData] Female " + std::string(akFemale->GetName()) + " (" + std::format("{:#x}", id) + ") does not exist in Female Registry!", LogType::NPCData, LoggingLevel::warning);
		
		return;
	}

	SetActorFactionRank(akFemale, ModestyFaction, HandleInteger(StrictRank));
	SetActorFactionRank(akFemale, TopModestyFaction, HandleInteger(TopRank));
	SetActorFactionRank(akFemale, BottomModestyFaction, HandleInteger(BottomRank));

	RegisteredFemales& female = registeredfemales[id];

	female.ModestyTimer0 = 0;
	female.ModestyTimer1 = 0;
	female.ModestyTimer2 = 0;
	female.ModestyTimer3 = 0;
	female.ModestyTimer4 = 0;
	female.ModestyTimer5 = 0;
	female.ModestyTimer6 = 0;

	female.TopModestyTimer0 = 0;
	female.TopModestyTimer1 = 0;
	female.TopModestyTimer2 = 0;
	female.TopModestyTimer3 = 0;

	female.BottomModestyTimer0 = 0;
	female.BottomModestyTimer1 = 0;
	female.BottomModestyTimer2 = 0;
	female.BottomModestyTimer3 = 0;

	female.CurrentRankStrict = StrictRank;
	female.CurrentRankTop = TopRank;
	female.CurrentRankBottom = BottomRank;

	female.MinimumRankStrict = MinimumStrict;
	female.MinimumRankTop = MinimumTop;
	female.MinimumRankBottom = MinimumBottom;

	if (MakeDefault)
	{
		female.DefaultRankStrict = StrictRank;
		female.DefaultRankTop = TopRank;
		female.DefaultRankBottom = BottomRank;
	}

	female.AllowShameless = EnableShameless;
	female.AllowCorruption = EnableCorrupt;
	female.StrictRules = IsStrictRules;
	female.UpgradeBlocked = IsUpgradeBlocked;

	female.ShynessMode = ShynessMode;

	female.LastUpdateTime = CurrentGameTime;

	int PermFemaleID = GetInternalPermanentFemaleID(akFemale);
	if (PermFemaleID >= 0)
	{
		permanentfemales[PermFemaleID].MinimumRankStrict  = MinimumStrict;
		permanentfemales[PermFemaleID].MinimumRankTop = MinimumTop;
		permanentfemales[PermFemaleID].MinimumRankBottom = MinimumBottom;

		if (MakeDefault)
		{
			permanentfemales[PermFemaleID].DefaultRankStrict = StrictRank;
			permanentfemales[PermFemaleID].DefaultRankTop = TopRank;
			permanentfemales[PermFemaleID].DefaultRankBottom = BottomRank;
		}

		permanentfemales[PermFemaleID].AllowShameless = EnableShameless;
		permanentfemales[PermFemaleID].AllowCorruption = EnableCorrupt;
		permanentfemales[PermFemaleID].StrictRules = IsStrictRules;

		permanentfemales[PermFemaleID].ShynessMode = ShynessMode;
	}
}

void ResetFemale(RE::Actor* akFemale)
{
	RE::FormID id = akFemale->GetFormID();

	if (!registeredfemales.count(id))
	{
		Log("<C++ NPCData> [ResetFemaleModesty] Error: Cannot find " + std::string(akFemale->GetName()) + " (" + std::format("{:#x}", akFemale->GetFormID()) + ") in Registered Females list!");

		return;
	}

	RegisteredFemales& female = registeredfemales[id];

	female.CurrentRankStrict = female.DefaultRankStrict;
	female.CurrentRankTop = female.DefaultRankTop;
	female.CurrentRankBottom = female.DefaultRankBottom;

	female.ModestyTimer0 = 0;
	female.ModestyTimer1 = 0;
	female.ModestyTimer2 = 0;
	female.ModestyTimer3 = 0;
	female.ModestyTimer4 = 0;
	female.ModestyTimer5 = 0;
	female.ModestyTimer6 = 0;

	female.TopModestyTimer0 = 0;
	female.TopModestyTimer1 = 0;
	female.TopModestyTimer2 = 0;
	female.TopModestyTimer3 = 0;

	female.BottomModestyTimer0 = 0;
	female.BottomModestyTimer1 = 0;
	female.BottomModestyTimer2 = 0;
	female.BottomModestyTimer3 = 0;
}

void ExternalResetFemale(RE::StaticFunctionTag*, RE::Actor* akFemale)
{
	ResetFemale(akFemale);
}

void ResetAllFemales(RE::StaticFunctionTag*)
{
	for(auto& [id, female] : registeredfemales)
	{
		female.CurrentRankStrict = female.DefaultRankStrict;
		female.CurrentRankTop = female.DefaultRankTop;
		female.CurrentRankBottom = female.DefaultRankBottom;

		female.ModestyTimer0 = 0;
		female.ModestyTimer1 = 0;
		female.ModestyTimer2 = 0;
		female.ModestyTimer3 = 0;
		female.ModestyTimer4 = 0;
		female.ModestyTimer5 = 0;
		female.ModestyTimer6 = 0;

		female.TopModestyTimer0 = 0;
		female.TopModestyTimer1 = 0;
		female.TopModestyTimer2 = 0;
		female.TopModestyTimer3 = 0;

		female.BottomModestyTimer0 = 0;
		female.BottomModestyTimer1 = 0;
		female.BottomModestyTimer2 = 0;
		female.BottomModestyTimer3 = 0;
	}
}