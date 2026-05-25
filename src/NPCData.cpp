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

int GetInternalFemaleID(RE::Actor* akFemale) {
	RE::FormID FemaleForm = akFemale->GetFormID();
	std::string FemaleName = akFemale->GetName();

	Log("<C++ NPCData> [GetInternalFemaleID] Female Form ID: " + std::format("{:#x}", FemaleForm), LogType::NPCData);
	Log("<C++ NPCData> [GetInternalFemaleID] Female Name: " + FemaleName, LogType::NPCData);

	return FindInVector(RegisteredFemales::FemaleFormID, FemaleForm);
}

int GetInternalPermanentFemaleID(RE::Actor* akFemale)
{
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	for(int i = 0; i < permanentfemales.size(); ++i)
	{
		std::optional<uint32_t> modindex = permanentfemales[i].LightPlugin ? static_cast<std::optional<uint32_t>>(DataHandler->GetLoadedLightModIndex(permanentfemales[i].GetPlugin())) : static_cast<std::optional<uint32_t>>(DataHandler->GetLoadedModIndex(permanentfemales[i].GetPlugin()));

		RE::FormID id = (modindex.value_or(0xFF) << 24) | permanentfemales[i].LocalID;
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

	RegisteredFemales::FemaleName.emplace_back(FemaleName);
	//RegisteredFemales::FemaleBaseEditorID.emplace_back(FemaleBaseEditorID);
	RegisteredFemales::FemaleFormID.emplace_back(FemaleForm);

	RegisteredFemales::ModestyTimer0.emplace_back(0);
	RegisteredFemales::ModestyTimer1.emplace_back(0);
	RegisteredFemales::ModestyTimer2.emplace_back(0);
	RegisteredFemales::ModestyTimer3.emplace_back(0);
	RegisteredFemales::ModestyTimer4.emplace_back(0);
	RegisteredFemales::ModestyTimer5.emplace_back(0);
	RegisteredFemales::ModestyTimer6.emplace_back(0);

	RegisteredFemales::DefaultRankStrict.emplace_back(StrictModesty);
	RegisteredFemales::CurrentRankStrict.emplace_back(StrictModesty);
	RegisteredFemales::MinimumRankStrict.emplace_back(0);

	RegisteredFemales::TopModestyTimer0.emplace_back(0);
	RegisteredFemales::TopModestyTimer1.emplace_back(0);
	RegisteredFemales::TopModestyTimer2.emplace_back(0);
	RegisteredFemales::TopModestyTimer3.emplace_back(0);

	RegisteredFemales::DefaultRankTop.emplace_back(TopModesty);
	RegisteredFemales::CurrentRankTop.emplace_back(TopModesty);
	RegisteredFemales::MinimumRankTop.emplace_back(0);

	RegisteredFemales::BottomModestyTimer0.emplace_back(0);
	RegisteredFemales::BottomModestyTimer1.emplace_back(0);
	RegisteredFemales::BottomModestyTimer2.emplace_back(0);
	RegisteredFemales::BottomModestyTimer3.emplace_back(0);

	RegisteredFemales::DefaultRankBottom.emplace_back(BottomModesty);
	RegisteredFemales::CurrentRankBottom.emplace_back(BottomModesty);
	RegisteredFemales::MinimumRankBottom.emplace_back(0);

	RegisteredFemales::ShynessMode.emplace_back(ShynessMode);
	RegisteredFemales::SexualityScore.emplace_back(SexualityScore);

	RegisteredFemales::AllowShameless.emplace_back(Configuration::NPCShamelessByDefault);
	RegisteredFemales::AllowCorruption.emplace_back(Configuration::NPCCorruptionByDefault);
	RegisteredFemales::StrictRules.emplace_back(Configuration::NPCStrictRulesByDefault);
	RegisteredFemales::UpgradeBlocked.emplace_back(false);

	RegisteredFemales::LastUpdateTime.emplace_back(CurrentGameTime);

	Log("<C++ NPCData> [RegisterFemale] Registered Female: " + FemaleName + " | Form ID: " + std::format("{:#x}", FemaleForm) + " | Internal ID: " + std::to_string(RegisteredFemales::TotalFemales), LogType::Core, LoggingLevel::info);

	RegisteredFemales::TotalFemales++;
}

void DeleteFemale(RE::StaticFunctionTag*, RE::Actor* akfemale) {
	int FemaleID = FindInVector(RegisteredFemales::FemaleFormID, akfemale->GetFormID());

	RegisteredFemales::FemaleName.erase(RegisteredFemales::FemaleName.begin() + FemaleID);
	//RegisteredFemales::FemaleBaseEditorID.erase(RegisteredFemales::FemaleBaseEditorID.begin() + FemaleID);
	RegisteredFemales::FemaleFormID.erase(RegisteredFemales::FemaleFormID.begin() + FemaleID);

	RegisteredFemales::ModestyTimer0.erase(RegisteredFemales::ModestyTimer0.begin() + FemaleID);
	RegisteredFemales::ModestyTimer1.erase(RegisteredFemales::ModestyTimer1.begin() + FemaleID);
	RegisteredFemales::ModestyTimer2.erase(RegisteredFemales::ModestyTimer2.begin() + FemaleID);
	RegisteredFemales::ModestyTimer3.erase(RegisteredFemales::ModestyTimer3.begin() + FemaleID);
	RegisteredFemales::ModestyTimer4.erase(RegisteredFemales::ModestyTimer4.begin() + FemaleID);
	RegisteredFemales::ModestyTimer5.erase(RegisteredFemales::ModestyTimer5.begin() + FemaleID);
	RegisteredFemales::ModestyTimer6.erase(RegisteredFemales::ModestyTimer6.begin() + FemaleID);

	RegisteredFemales::DefaultRankStrict.erase(RegisteredFemales::DefaultRankStrict.begin() + FemaleID);
	RegisteredFemales::CurrentRankStrict.erase(RegisteredFemales::CurrentRankStrict.begin() + FemaleID);
	RegisteredFemales::MinimumRankStrict.erase(RegisteredFemales::MinimumRankStrict.begin() + FemaleID);

	RegisteredFemales::TopModestyTimer0.erase(RegisteredFemales::TopModestyTimer0.begin() + FemaleID);
	RegisteredFemales::TopModestyTimer1.erase(RegisteredFemales::TopModestyTimer1.begin() + FemaleID);
	RegisteredFemales::TopModestyTimer2.erase(RegisteredFemales::TopModestyTimer2.begin() + FemaleID);
	RegisteredFemales::TopModestyTimer3.erase(RegisteredFemales::TopModestyTimer3.begin() + FemaleID);

	RegisteredFemales::DefaultRankTop.erase(RegisteredFemales::DefaultRankTop.begin() + FemaleID);
	RegisteredFemales::CurrentRankTop.erase(RegisteredFemales::CurrentRankTop.begin() + FemaleID);
	RegisteredFemales::MinimumRankTop.erase(RegisteredFemales::MinimumRankTop.begin() + FemaleID);

	RegisteredFemales::BottomModestyTimer0.erase(RegisteredFemales::BottomModestyTimer0.begin() + FemaleID);
	RegisteredFemales::BottomModestyTimer1.erase(RegisteredFemales::BottomModestyTimer1.begin() + FemaleID);
	RegisteredFemales::BottomModestyTimer2.erase(RegisteredFemales::BottomModestyTimer2.begin() + FemaleID);
	RegisteredFemales::BottomModestyTimer3.erase(RegisteredFemales::BottomModestyTimer3.begin() + FemaleID);

	RegisteredFemales::DefaultRankBottom.erase(RegisteredFemales::DefaultRankBottom.begin() + FemaleID);
	RegisteredFemales::CurrentRankBottom.erase(RegisteredFemales::CurrentRankBottom.begin() + FemaleID);
	RegisteredFemales::MinimumRankBottom.erase(RegisteredFemales::MinimumRankBottom.begin() + FemaleID);

	RegisteredFemales::ShynessMode.erase(RegisteredFemales::ShynessMode.begin() + FemaleID);
	RegisteredFemales::ShynessMode.erase(RegisteredFemales::SexualityScore.begin() + FemaleID);

	RegisteredFemales::AllowShameless.erase(RegisteredFemales::AllowShameless.begin() + FemaleID);
	RegisteredFemales::AllowCorruption.erase(RegisteredFemales::AllowCorruption.begin() + FemaleID);
	RegisteredFemales::StrictRules.erase(RegisteredFemales::StrictRules.begin() + FemaleID);
	RegisteredFemales::UpgradeBlocked.erase(RegisteredFemales::UpgradeBlocked.begin() + FemaleID);

	RegisteredFemales::LastUpdateTime.erase(RegisteredFemales::LastUpdateTime.begin() + FemaleID);

	RegisteredFemales::TotalFemales--;
}

void DeleteAllFemales(RE::StaticFunctionTag*) {
	RegisteredFemales::FemaleName.clear();
	RegisteredFemales::FemaleFormID.clear();

	RegisteredFemales::ModestyTimer0.clear();
	RegisteredFemales::ModestyTimer1.clear();
	RegisteredFemales::ModestyTimer2.clear();
	RegisteredFemales::ModestyTimer3.clear();
	RegisteredFemales::ModestyTimer4.clear();
	RegisteredFemales::ModestyTimer5.clear();
	RegisteredFemales::ModestyTimer6.clear();

	RegisteredFemales::DefaultRankStrict.clear();
	RegisteredFemales::CurrentRankStrict.clear();
	RegisteredFemales::MinimumRankStrict.clear();

	RegisteredFemales::TopModestyTimer0.clear();
	RegisteredFemales::TopModestyTimer1.clear();
	RegisteredFemales::TopModestyTimer2.clear();
	RegisteredFemales::TopModestyTimer3.clear();

	RegisteredFemales::DefaultRankTop.clear();
	RegisteredFemales::CurrentRankTop.clear();
	RegisteredFemales::MinimumRankTop.clear();

	RegisteredFemales::BottomModestyTimer0.clear();
	RegisteredFemales::BottomModestyTimer1.clear();
	RegisteredFemales::BottomModestyTimer2.clear();
	RegisteredFemales::BottomModestyTimer3.clear();

	RegisteredFemales::DefaultRankBottom.clear();
	RegisteredFemales::CurrentRankBottom.clear();
	RegisteredFemales::MinimumRankBottom.clear();

	RegisteredFemales::ShynessMode.clear();
	RegisteredFemales::ShynessMode.clear();

	RegisteredFemales::AllowShameless.clear();
	RegisteredFemales::AllowCorruption.clear();
	RegisteredFemales::StrictRules.clear();
	RegisteredFemales::UpgradeBlocked.clear();

	RegisteredFemales::LastUpdateTime.clear();

	RegisteredFemales::TotalFemales = 0;
}

void RegisterRosa(float CurrentGameTime, int SexualityScore) {
	int RosaForm = Rosa->GetFormID();
	int RosaBaseForm = Rosa->GetActorBase()->GetFormID();
	std::string RosaEditorID = Rosa->GetFormEditorID();
	std::string RosaBaseEditorID = Rosa->GetActorBase()->GetFormEditorID();
	std::string RosaName = Rosa->GetName();
	std::string RosaBaseName = Rosa->GetActorBase()->GetFormEditorID();

	Log("<C++ NPCData> [RegisterRosa] Rosa Form ID: " + std::format("{:#x}", RosaForm), LogType::NPCData);
	Log("<C++ NPCData> [RegisterRosa] Rosa Base Form ID: " + std::format("{:#x}", RosaBaseForm), LogType::NPCData);
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


	RegisteredFemales::FemaleName.emplace_back(RosaName);
	//RegisteredFemales::FemaleBaseEditorID.emplace_back(RosaBaseEditorID);
	RegisteredFemales::FemaleFormID.emplace_back(RosaForm);

	RegisteredFemales::ModestyTimer0.emplace_back(0);
	RegisteredFemales::ModestyTimer1.emplace_back(0);
	RegisteredFemales::ModestyTimer2.emplace_back(0);
	RegisteredFemales::ModestyTimer3.emplace_back(0);
	RegisteredFemales::ModestyTimer4.emplace_back(0);
	RegisteredFemales::ModestyTimer5.emplace_back(0);
	RegisteredFemales::ModestyTimer6.emplace_back(0);

	RegisteredFemales::DefaultRankStrict.emplace_back(StrictModestyLevel::Immodest);
	RegisteredFemales::CurrentRankStrict.emplace_back(StrictModestyLevel::Immodest);
	RegisteredFemales::MinimumRankStrict.emplace_back(StrictModestyLevel::Immodest);

	RegisteredFemales::TopModestyTimer0.emplace_back(0);
	RegisteredFemales::TopModestyTimer1.emplace_back(0);
	RegisteredFemales::TopModestyTimer2.emplace_back(0);
	RegisteredFemales::TopModestyTimer3.emplace_back(0);

	RegisteredFemales::DefaultRankTop.emplace_back(SimpleModestyLevel::Immodest);
	RegisteredFemales::CurrentRankTop.emplace_back(SimpleModestyLevel::Immodest);
	RegisteredFemales::MinimumRankTop.emplace_back(SimpleModestyLevel::Immodest);

	RegisteredFemales::BottomModestyTimer0.emplace_back(0);
	RegisteredFemales::BottomModestyTimer1.emplace_back(0);
	RegisteredFemales::BottomModestyTimer2.emplace_back(0);
	RegisteredFemales::BottomModestyTimer3.emplace_back(0);

	RegisteredFemales::DefaultRankBottom.emplace_back(SimpleModestyLevel::Immodest);
	RegisteredFemales::CurrentRankBottom.emplace_back(SimpleModestyLevel::Immodest);
	RegisteredFemales::MinimumRankBottom.emplace_back(SimpleModestyLevel::Immodest);

	RegisteredFemales::ShynessMode.emplace_back(ShynessMode);
	RegisteredFemales::SexualityScore.emplace_back(SexualityScore);

	RegisteredFemales::AllowShameless.emplace_back(Configuration::NPCShamelessByDefault);
	RegisteredFemales::AllowCorruption.emplace_back(Configuration::NPCCorruptionByDefault);
	RegisteredFemales::StrictRules.emplace_back(Configuration::StrictModestyRules);
	RegisteredFemales::UpgradeBlocked.emplace_back(false);

	RegisteredFemales::LastUpdateTime.emplace_back(CurrentGameTime);

	RegisteredFemales::TotalFemales++;
}

int RegisterPermanent(RE::StaticFunctionTag*, RE::Actor* akFemale) 
{
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	int FemaleID = GetInternalFemaleID(akFemale);
	std::string akName = akFemale->GetName();

	if (FemaleID == -1) 
	{
		Log("<C++ NPCData> [RegisterPermanent] NPC " + akName + " does not exist on regular registry! This should not be possible!", LogType::NPCData, LoggingLevel::critical);

		return FunctionEnd::FailCritical;
	}

	PermanentFemales female;
	uint32_t pluginID;

	RE::FormID id = akFemale->GetFormID();

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

	female.DefaultRankStrict = RegisteredFemales::DefaultRankStrict[FemaleID];
	female.MinimumRankStrict = RegisteredFemales::MinimumRankStrict[FemaleID];

	female.DefaultRankTop = RegisteredFemales::DefaultRankTop[FemaleID];
	female.MinimumRankTop = RegisteredFemales::MinimumRankTop[FemaleID];

	female.DefaultRankBottom = RegisteredFemales::DefaultRankBottom[FemaleID];
	female.MinimumRankBottom = RegisteredFemales::MinimumRankBottom[FemaleID];

	female.ShynessMode = RegisteredFemales::ShynessMode[FemaleID];
	female.SexualityScore = RegisteredFemales::SexualityScore[FemaleID];

	female.AllowShameless = RegisteredFemales::AllowShameless[FemaleID];
	female.AllowCorruption = RegisteredFemales::AllowCorruption[FemaleID];
	female.StrictRules = RegisteredFemales::StrictRules[FemaleID];

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
		RE::FormID id = (female.LightPlugin ? static_cast<std::optional<uint32_t>>(DataHandler->GetLoadedLightModIndex(female.GetPlugin())) : static_cast<std::optional<uint32_t>>(DataHandler->GetLoadedModIndex(female.GetPlugin()))).value_or(0xFF) << 24 | female.LocalID;

		RE::Actor* actor = RE::TESForm::LookupByID<RE::Actor>(id);
		if(!actor)
		{
			Log("<C++ NPCData> [ImportPermanents] Could not import female " + std::string(female.GetName()) + " because their Form ID (" + std::format("{:#x}", id) + ") returns a null pointer!");

			continue;
		}

		RegisteredFemales::FemaleFormID.emplace_back(id);
		RegisteredFemales::FemaleName.emplace_back(female.GetName());

		RegisteredFemales::ModestyTimer0.emplace_back(0);
		RegisteredFemales::ModestyTimer1.emplace_back(0);
		RegisteredFemales::ModestyTimer2.emplace_back(0);
		RegisteredFemales::ModestyTimer3.emplace_back(0);
		RegisteredFemales::ModestyTimer4.emplace_back(0);
		RegisteredFemales::ModestyTimer5.emplace_back(0);
		RegisteredFemales::ModestyTimer6.emplace_back(0);

		RegisteredFemales::CurrentRankStrict.emplace_back(female.DefaultRankStrict);
		RegisteredFemales::DefaultRankStrict.emplace_back(female.DefaultRankStrict);
		RegisteredFemales::MinimumRankStrict.emplace_back(female.MinimumRankStrict);

		RegisteredFemales::TopModestyTimer0.emplace_back(0);
		RegisteredFemales::TopModestyTimer1.emplace_back(0);
		RegisteredFemales::TopModestyTimer2.emplace_back(0);
		RegisteredFemales::TopModestyTimer3.emplace_back(0);

		RegisteredFemales::CurrentRankTop.emplace_back(female.DefaultRankTop);
		RegisteredFemales::DefaultRankTop.emplace_back(female.DefaultRankTop);
		RegisteredFemales::MinimumRankTop.emplace_back(female.MinimumRankTop);

		RegisteredFemales::BottomModestyTimer0.emplace_back(0);
		RegisteredFemales::BottomModestyTimer1.emplace_back(0);
		RegisteredFemales::BottomModestyTimer2.emplace_back(0);
		RegisteredFemales::BottomModestyTimer3.emplace_back(0);

		RegisteredFemales::CurrentRankBottom.emplace_back(female.DefaultRankBottom);
		RegisteredFemales::DefaultRankBottom.emplace_back(female.DefaultRankBottom);
		RegisteredFemales::MinimumRankBottom.emplace_back(female.MinimumRankBottom);

		RegisteredFemales::ShynessMode.emplace_back(female.ShynessMode);
		RegisteredFemales::SexualityScore.emplace_back(female.SexualityScore);

		RegisteredFemales::AllowShameless.emplace_back(female.AllowShameless);
		RegisteredFemales::AllowCorruption.emplace_back(female.AllowCorruption);
		RegisteredFemales::StrictRules.emplace_back(female.StrictRules);
		RegisteredFemales::UpgradeBlocked.emplace_back(false);

		RegisteredFemales::LastUpdateTime.emplace_back(CurrentGameTime);

		RegisteredFemales::TotalFemales++;
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
	RE::FormID FemaleFormID = akFemale->GetFormID();
	int FemaleID = FindInVector(RegisteredFemales::FemaleFormID, FemaleFormID);
	if (FemaleID < 0) {
		std::string akName = akFemale->GetName();
		Log("<C++ NPCData> [TweakFemaleData] Female " + akName + " (" + std::format("{:#x}", FemaleFormID) + ") does not exist in Female Registry!", LogType::NPCData, LoggingLevel::warning);
		return;
	}
	
	SetActorFactionRank(akFemale, ModestyFaction, HandleInteger(StrictRank));
	SetActorFactionRank(akFemale, TopModestyFaction, HandleInteger(TopRank));
	SetActorFactionRank(akFemale, BottomModestyFaction, HandleInteger(BottomRank));

	RegisteredFemales::ModestyTimer0[FemaleID] = 0;
	RegisteredFemales::ModestyTimer1[FemaleID] = 0;
	RegisteredFemales::ModestyTimer2[FemaleID] = 0;
	RegisteredFemales::ModestyTimer3[FemaleID] = 0;
	RegisteredFemales::ModestyTimer4[FemaleID] = 0;
	RegisteredFemales::ModestyTimer5[FemaleID] = 0;
	RegisteredFemales::ModestyTimer6[FemaleID] = 0;

	RegisteredFemales::TopModestyTimer0[FemaleID] = 0;
	RegisteredFemales::TopModestyTimer1[FemaleID] = 0;
	RegisteredFemales::TopModestyTimer2[FemaleID] = 0;
	RegisteredFemales::TopModestyTimer3[FemaleID] = 0;

	RegisteredFemales::BottomModestyTimer0[FemaleID] = 0;
	RegisteredFemales::BottomModestyTimer1[FemaleID] = 0;
	RegisteredFemales::BottomModestyTimer2[FemaleID] = 0;
	RegisteredFemales::BottomModestyTimer3[FemaleID] = 0;

	RegisteredFemales::CurrentRankStrict[FemaleID] = StrictRank;
	RegisteredFemales::CurrentRankTop[FemaleID] = TopRank;
	RegisteredFemales::CurrentRankBottom[FemaleID] = BottomRank;

	RegisteredFemales::MinimumRankStrict[FemaleID] = MinimumStrict;
	RegisteredFemales::MinimumRankTop[FemaleID] = MinimumTop;
	RegisteredFemales::MinimumRankBottom[FemaleID] = MinimumBottom;

	if (MakeDefault) {
		RegisteredFemales::DefaultRankStrict[FemaleID] = StrictRank;
		RegisteredFemales::DefaultRankTop[FemaleID] = TopRank;
		RegisteredFemales::DefaultRankBottom[FemaleID] = BottomRank;
	}

	RegisteredFemales::AllowShameless[FemaleID] = EnableShameless;
	RegisteredFemales::AllowCorruption[FemaleID] = EnableCorrupt;
	RegisteredFemales::StrictRules[FemaleID] = IsStrictRules;
	RegisteredFemales::UpgradeBlocked[FemaleID] = IsUpgradeBlocked;

	RegisteredFemales::ShynessMode[FemaleID] = ShynessMode;

	RegisteredFemales::LastUpdateTime[FemaleID] = CurrentGameTime;

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

void ResetFemale(RE::Actor* akFemale) {
	int FemaleIndex = FindInVector(RegisteredFemales::FemaleFormID, akFemale->GetFormID());

	if (FemaleIndex < 0) {
		std::string akName = akFemale->GetName();
		Log("<C++ NPCData> [ResetFemaleModesty] Error: Cannot find " + akName + " (" + std::format("{:#x}", akFemale->GetFormID()) + ") in Registered Females list!");
		return;
	}

	RegisteredFemales::CurrentRankStrict[FemaleIndex] = RegisteredFemales::DefaultRankStrict[FemaleIndex];
	RegisteredFemales::CurrentRankTop[FemaleIndex] = RegisteredFemales::DefaultRankTop[FemaleIndex];
	RegisteredFemales::CurrentRankBottom[FemaleIndex] = RegisteredFemales::DefaultRankBottom[FemaleIndex];

	RegisteredFemales::ModestyTimer0[FemaleIndex] = 0;
	RegisteredFemales::ModestyTimer1[FemaleIndex] = 0;
	RegisteredFemales::ModestyTimer2[FemaleIndex] = 0;
	RegisteredFemales::ModestyTimer3[FemaleIndex] = 0;
	RegisteredFemales::ModestyTimer4[FemaleIndex] = 0;
	RegisteredFemales::ModestyTimer5[FemaleIndex] = 0;
	RegisteredFemales::ModestyTimer6[FemaleIndex] = 0;

	RegisteredFemales::TopModestyTimer0[FemaleIndex] = 0;
	RegisteredFemales::TopModestyTimer1[FemaleIndex] = 0;
	RegisteredFemales::TopModestyTimer2[FemaleIndex] = 0;
	RegisteredFemales::TopModestyTimer3[FemaleIndex] = 0;

	RegisteredFemales::BottomModestyTimer0[FemaleIndex] = 0;
	RegisteredFemales::BottomModestyTimer1[FemaleIndex] = 0;
	RegisteredFemales::BottomModestyTimer2[FemaleIndex] = 0;
	RegisteredFemales::BottomModestyTimer3[FemaleIndex] = 0;
}

void ExternalResetFemale(RE::StaticFunctionTag*, RE::Actor* akFemale) {
	ResetFemale(akFemale);
}

void ResetAllFemales(RE::StaticFunctionTag*) {
	int FemaleIndex = 0;
	while (FemaleIndex < RegisteredFemales::TotalFemales) {
		RegisteredFemales::CurrentRankStrict[FemaleIndex] = RegisteredFemales::DefaultRankStrict[FemaleIndex];
		RegisteredFemales::CurrentRankTop[FemaleIndex] = RegisteredFemales::DefaultRankTop[FemaleIndex];
		RegisteredFemales::CurrentRankBottom[FemaleIndex] = RegisteredFemales::DefaultRankBottom[FemaleIndex];

		RegisteredFemales::ModestyTimer0[FemaleIndex] = 0;
		RegisteredFemales::ModestyTimer1[FemaleIndex] = 0;
		RegisteredFemales::ModestyTimer2[FemaleIndex] = 0;
		RegisteredFemales::ModestyTimer3[FemaleIndex] = 0;
		RegisteredFemales::ModestyTimer4[FemaleIndex] = 0;
		RegisteredFemales::ModestyTimer5[FemaleIndex] = 0;
		RegisteredFemales::ModestyTimer6[FemaleIndex] = 0;

		RegisteredFemales::TopModestyTimer0[FemaleIndex] = 0;
		RegisteredFemales::TopModestyTimer1[FemaleIndex] = 0;
		RegisteredFemales::TopModestyTimer2[FemaleIndex] = 0;
		RegisteredFemales::TopModestyTimer3[FemaleIndex] = 0;

		RegisteredFemales::BottomModestyTimer0[FemaleIndex] = 0;
		RegisteredFemales::BottomModestyTimer1[FemaleIndex] = 0;
		RegisteredFemales::BottomModestyTimer2[FemaleIndex] = 0;
		RegisteredFemales::BottomModestyTimer3[FemaleIndex] = 0;

		FemaleIndex++;
	}
}