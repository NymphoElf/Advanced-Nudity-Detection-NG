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

/*
void Serialize(SKSE::SerializationInterface* serializer) {
	//auto* MALSerializer = SKSE::GetSerializationInterface();

	long MOD_ID = 'AND';

	serializer->SetUniqueID(_byteswap_ulong(MOD_ID)); //1296124978
	//MALSerializer->SetUniqueID(_byteswap_ulong(MALID)); //1296124978
	logs::critical("<C++ Main> [Serialize] AND Unique ID = {}", _byteswap_ulong(MOD_ID));
}
*/

bool BindNativePapyrusFunctions(RE::BSScript::IVirtualMachine* papyrusVM) {
	//Main Script Binds
	
	//Logger Script Binds
	papyrusVM->RegisterFunction("EnableLogging", "AND_Logger", EnableLogging);
	papyrusVM->RegisterFunction("SetLogLevel", "AND_Logger", SetLogLevel);
	papyrusVM->RegisterFunction("FastLog", "AND_Logger", ExternalLog);

	//Core Script Binds
	papyrusVM->RegisterFunction("DiceRoll", "AND_Core", DiceRoll);
	papyrusVM->RegisterFunction("MovementDiceRoll", "AND_Core", MotionDiceRoll);
	papyrusVM->RegisterFunction("FemaleAnalyze", "AND_Core", ExternalFemaleAnalyze);
	papyrusVM->RegisterFunction("MaleAnalyze", "AND_Core", ExternalMaleAnalyze);

	//Player Script Binds


	//Config Script Binds

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
		break;
	case SKSE::MessagingInterface::kPostLoad: //after main game loads
		logs::info("Post Load");
		break;
	case SKSE::MessagingInterface::kPostPostLoad: //after main game loads and DLLs have time to do something
		logs::info("Post Post Load");
		break;
	case SKSE::MessagingInterface::kNewGame:
		logs::info("New Game");
		InitializeCoreData();
		InitializeConfigData();
		break;
	case SKSE::MessagingInterface::kSaveGame:
		logs::info("Save Game");
		essPath = std::string{ (char*)message->data, message->dataLen };
		logs::info("Saving Game: {}", essPath);
		//SaveData(essPath);
		break;
	case SKSE::MessagingInterface::kPreLoadGame:
		logs::info("Pre Load Game");
		essPath = std::string{ (char*)message->data, message->dataLen };
		logs::info("Loading Save: {}", essPath);
		InitializeCoreData();
		//LoadData(essPath);
		break;
	case SKSE::MessagingInterface::kPostLoadGame:
		logs::info("Post Load Game");
		break;
	case SKSE::MessagingInterface::kDeleteGame:
		logs::info("Deleted Game");
		essPath = std::string{ (char*)message->data, message->dataLen };
		logs::info("Deleted Save: {}", essPath);
		//DeleteData(essPath);
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

	return true;
}
