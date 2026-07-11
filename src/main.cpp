#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>
#include <vector>
#include <random>

#include "PlayerArmorScan.h"
#include "Core.h"
#include "Logger.h"
#include "SaveLoad.h"
#include "Config.h"
#include "Player.h"
#include "PlayerModesty.h"
#include "NPCScanner.h"
#include "NPCData.h"
#include "ModEventHandler.h"

bool BindNativePapyrusFunctions(RE::BSScript::IVirtualMachine* papyrusVM) {
	//Main Script Binds
	
	//Logger Script Binds
	
	papyrusVM->RegisterFunction("FastLog", "AND_Logger", ExternalLog);
	papyrusVM->RegisterFunction("UpdateLoggingType", "AND_Logger", UpdateLoggingType);
	papyrusVM->RegisterFunction("UpdateLoggingLevel", "AND_Logger", UpdateLoggingLevel);

	papyrusVM->RegisterFunction("GetLogSettings", "AND_Logger", GetLogSettings);

	//Core Script Binds
	papyrusVM->RegisterFunction("DiceRoll", "AND_Core", DiceRoll);
	papyrusVM->RegisterFunction("MovementDiceRoll", "AND_Core", MotionDiceRoll);
	papyrusVM->RegisterFunction("FemaleAnalyze", "AND_Core", ExternalFemaleAnalyze);
	papyrusVM->RegisterFunction("MaleAnalyze", "AND_Core", ExternalMaleAnalyze);
	papyrusVM->RegisterFunction("GetRandomizedModesty", "AND_Core", ExternalGetRandomizedModesty);
	papyrusVM->RegisterFunction("NakedCommentChance", "AND_Core", ExternalNakedCommentChance);
	papyrusVM->RegisterFunction("AddCustomTransform", "AND_Core", AddCustomTransform);

	//Player Script Binds
	papyrusVM->RegisterFunction("CheckWearingCurtains", "AND_PlayerScript", CheckWearingCurtains);
	papyrusVM->RegisterFunction("ClosedMenuEvent", "AND_PlayerScript", ClosedMenuEvent);
	papyrusVM->RegisterFunction("PlayerRaceIsRecognized", "AND_PlayerScript", PlayerRaceIsRecognized);
	papyrusVM->RegisterFunction("GetPlayerBaseRace", "AND_PlayerScript", ExternalGetPlayerBaseRace);
	papyrusVM->RegisterFunction("ValidatePlayerBaseRace", "AND_PlayerScript", ValidatePlayerBaseRace);
	papyrusVM->RegisterFunction("SetPlayerBaseRace", "AND_PlayerScript", ExternalSetPlayerBaseRace);

	//Keybind Manager Binds
	papyrusVM->RegisterFunction("PlayerIsWearingChestCurtain", "AND_KeybindManager", PlayerIsWearingChestCurtain);
	papyrusVM->RegisterFunction("PlayerIsWearingPelvicCurtain", "AND_KeybindManager", PlayerIsWearingPelvicCurtain);
	papyrusVM->RegisterFunction("PlayerIsWearingAssCurtain", "AND_KeybindManager", PlayerIsWearingAssCurtain);

	papyrusVM->RegisterFunction("OverrideCurtainRoll", "AND_KeybindManager", OverrideCurtainRoll);

	//NPC Data Binds
	papyrusVM->RegisterFunction("DeleteFemale", "AND_NPCData", DeleteFemale);
	papyrusVM->RegisterFunction("ResetFemale", "AND_NPCData", ExternalResetFemale);
	papyrusVM->RegisterFunction("ResetAllFemales", "AND_NPCData", ResetAllFemales);
	papyrusVM->RegisterFunction("DeleteAllFemales", "AND_NPCData", DeleteAllFemales);
	papyrusVM->RegisterFunction("TweakFemale", "AND_NPCData", TweakFemaleData);
	papyrusVM->RegisterFunction("RegisterPermanentFemale", "AND_NPCData", RegisterPermanent);
	papyrusVM->RegisterFunction("RemovePermanent", "AND_NPCData", RemovePermanent);
	papyrusVM->RegisterFunction("RemovePermanentAtIndex", "AND_NPCData", ExternalRemovePermanentAtIndex);

	//Config Script Binds
	papyrusVM->RegisterFunction("FemaleWornKeywordList", "AND_MCM", FemaleWornKeywordList);
	papyrusVM->RegisterFunction("MaleWornKeywordList", "AND_MCM", MaleWornKeywordList);

	papyrusVM->RegisterFunction("UpdateFlashingOdds", "AND_MCM", UpdateFlashingOdds);
	papyrusVM->RegisterFunction("GetFlashOdds", "AND_MCM", GetFlashOddsArray);

	papyrusVM->RegisterFunction("GetFlashRolls", "AND_MCM", GetFlashRolls);

	papyrusVM->RegisterFunction("GetConfigBoolOptions", "AND_MCM", GetConfigBoolOptions);
	papyrusVM->RegisterFunction("UpdateConfigBoolOptions", "AND_MCM", UpdateConfigBoolOptions);

	papyrusVM->RegisterFunction("GetDynamicModestyEnabledByOtherMod", "AND_MCM", GetDynamicModestyEnabledByOtherMod);

	papyrusVM->RegisterFunction("GetConfigIntOptions", "AND_MCM", GetConfigIntOptions);
	papyrusVM->RegisterFunction("UpdateConfigIntOptions", "AND_MCM", UpdateConfigIntOptions);
	
	papyrusVM->RegisterFunction("GetCurtainCoverage", "AND_MCM", GetCurtainCoverage);

	papyrusVM->RegisterFunction("GetRegisteredFemalesPages", "AND_MCM", GetRegisteredFemalesPages);
	papyrusVM->RegisterFunction("GetPermanentFemalesPages", "AND_MCM", GetPermanentFemalesPages);

	papyrusVM->RegisterFunction("GetRegisteredFemaleNames", "AND_MCM", GetRegisteredFemaleNames);
	papyrusVM->RegisterFunction("GetRegisteredFemaleActors", "AND_MCM", GetRegisteredFemaleActors);

	papyrusVM->RegisterFunction("GetPermanentFemaleNames", "AND_MCM", GetPermanentFemaleNames);
	papyrusVM->RegisterFunction("GetPermanentFemaleActors", "AND_MCM", GetPermanentFemaleActors);

	papyrusVM->RegisterFunction("GetFemaleActorData", "AND_MCM", GetFemaleActorData);
	papyrusVM->RegisterFunction("GetFemaleActorFormID", "AND_MCM", GetFemaleActorFormID);

	papyrusVM->RegisterFunction("GetPlayerFactionRanks", "AND_MCM", GetPlayerFactionRanks);
	papyrusVM->RegisterFunction("GetPlayerStrictModestyTimers", "AND_MCM", GetPlayerStrictModestyTimers);
	papyrusVM->RegisterFunction("GetPlayerSimpleModestyTimers", "AND_MCM", GetPlayerSimpleModestyTimers);

	//Modesty Script Binds
	papyrusVM->RegisterFunction("SKSEStrictModesty", "AND_Modesty_Manager", ExternalStrictModesty);
	papyrusVM->RegisterFunction("SKSESimpleModesty", "AND_Modesty_Manager", ExternalSimpleModesty);
	papyrusVM->RegisterFunction("SKSERankJump", "AND_Modesty_Manager", ExternalRankJump);
	papyrusVM->RegisterFunction("SKSETopRankJump", "AND_Modesty_Manager", ExternalTopRankJump);
	papyrusVM->RegisterFunction("SKSEBottomRankJump", "AND_Modesty_Manager", ExternalBottomRankJump);
	papyrusVM->RegisterFunction("ProcessAllNPCModesty", "AND_Modesty_Manager", ProcessAllNPCModesty);

	//ModEventListener Script Binds
	papyrusVM->RegisterFunction("RegisterPlugin", "AND_ModEventListener", RegisterPlugin);
	papyrusVM->RegisterFunction("UnregisterPlugin", "AND_ModEventListener", UnregisterPlugin);

	papyrusVM->RegisterFunction("EnableDynamicModesty", "AND_ModEventListener", OnEnableDynamicModesty);
	papyrusVM->RegisterFunction("GetIsDynamicModestyEnabled", "AND_ModEventListener", OnGetIsDynamicModestyEnabled);

	papyrusVM->RegisterFunction("SetStrictModestyRules", "AND_ModEventListener", OnSetStrictModestyRules);
	papyrusVM->RegisterFunction("GetStrictRulesEnabled", "AND_ModEventListener", OnGetStrictRulesEnabled);

	papyrusVM->RegisterFunction("SetMinimumStrictModestyRank", "AND_ModEventListener", OnSetMinimumStrictModestyRank);
	papyrusVM->RegisterFunction("GetMinimumStrictModestyRank", "AND_ModEventListener", OnGetMinimumStrictModestyRank);

	papyrusVM->RegisterFunction("SetMinimumTopModestyRank", "AND_ModEventListener", OnSetMinimumTopModestyRank);
	papyrusVM->RegisterFunction("GetMinimumTopModestyRank", "AND_ModEventListener", OnGetMinimumTopModestyRank);

	papyrusVM->RegisterFunction("SetMinimumBottomModestyRank", "AND_ModEventListener", OnSetMinimumBottomModestyRank);
	papyrusVM->RegisterFunction("GetMinimumBottomModestyRank", "AND_ModEventListener", OnGetMinimumBottomModestyRank);

	papyrusVM->RegisterFunction("SetHardcore", "AND_ModEventListener", OnSetHardcore);
	papyrusVM->RegisterFunction("GetHardcore", "AND_ModEventListener", OnGetHardcore);

	papyrusVM->RegisterFunction("SetCorruption", "AND_ModEventListener", OnSetCorruption);
	papyrusVM->RegisterFunction("GetCorruption", "AND_ModEventListener", OnGetCorruption);

	papyrusVM->RegisterFunction("SetShameless", "AND_ModEventListener", OnSetShameless);
	papyrusVM->RegisterFunction("GetShameless", "AND_ModEventListener", OnGetShameless);

	papyrusVM->RegisterFunction("SetModestyUpgradeBlocked", "AND_ModEventListener", OnSetModestyUpgradeBlocked);
	papyrusVM->RegisterFunction("GetModestyUpgradeBlocked", "AND_ModEventListener", OnGetModestyUpgradeBlocked);

	papyrusVM->RegisterFunction("SetImmodestyTime", "AND_ModEventListener", OnSetImmodestyTime);
	papyrusVM->RegisterFunction("GetImmodestyTime", "AND_ModEventListener", OnGetImmodestyTime);

	logs::critical("Native Papyrus Functions Bound!");
	return true;
}

void InitializeLog()
{
	auto log_directory = SKSE::log::log_directory();
	if (!log_directory.has_value())
	{
		logs::error("failed to get known folder path");
		return;
	}

	std::filesystem::path path = log_directory.value();
	path /= std::format("{}.log", SKSE::GetPluginName());

	std::vector<spdlog::sink_ptr> sinks {
		std::make_shared<spdlog::sinks::rotating_file_sink_mt>(path.string(), 0x6400000, 4, true),
		std::make_shared<spdlog::sinks::msvc_sink_mt>()
	};

	auto logger = std::make_shared<spdlog::logger>("global", sinks.begin(), sinks.end());
	logger->set_level(spdlog::level::trace);
	logger->flush_on(spdlog::level::trace);

	spdlog::set_default_logger(std::move(logger));
	spdlog::set_pattern("[%T.%e] [%=5t] [%L] %v");

	logs::info("{} v{}", SKSE::GetPluginName(), SKSE::GetPluginVersion());
}

void OnMessage(SKSE::MessagingInterface::Message* message) {
	logs::info("Message Type: {}", message->type);
	std::string essPath = "";
	switch (message->type) {
	case SKSE::MessagingInterface::kInputLoaded:
		logs::info("Input Loaded");
		break;
	case SKSE::MessagingInterface::kDataLoaded: //After PLUGIN (esp/esm/esl) files are loaded
		logs::info("Data Loaded");

		InitializeCoreData();
		CheckMods();
		InitializeConfigData();

		break;
	case SKSE::MessagingInterface::kPostLoad: //after main game loads
		logs::info("Post Load");
		break;
	case SKSE::MessagingInterface::kPostPostLoad: //after main game loads and DLLs have time to do something
		logs::info("Post Post Load");
		break;
	case SKSE::MessagingInterface::kNewGame:
		logs::info("New Game");

		LoadPermanentNPCs();

		break;
	case SKSE::MessagingInterface::kSaveGame:
		logs::info("Save Game");
		essPath = std::string{ (char*)message->data, message->dataLen };
		logs::info("Saving Game: {}", essPath);
		break;
	case SKSE::MessagingInterface::kPreLoadGame:
		logs::info("Pre Load Game");
		essPath = std::string{ (char*)message->data, message->dataLen };
		logs::info("Loading Save: {}", essPath);
		break;
	case SKSE::MessagingInterface::kPostLoadGame:
		logs::info("Post Load Game");

		CleanFemaleList();

		break;
	case SKSE::MessagingInterface::kDeleteGame:
		logs::info("Deleted Game");
		essPath = std::string{ (char*)message->data, message->dataLen };
		logs::info("Deleted Save: {}", essPath);
		
		break;
	default:
		logs::info("Unknown Message of type: {}", message->type);
		break;
	}
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse, false);
	InitializeLog();
	logs::critical("Advanced Nudity Detection DLL Initialized!");
	SKSE::GetMessagingInterface()->RegisterListener(OnMessage);
	logs::critical("Messaging Interface Initialized!");
	SKSE::GetPapyrusInterface()->Register(BindNativePapyrusFunctions);

	RegisterCoSaveSerializer();

	return true;
}
