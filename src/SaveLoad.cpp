//#include <Windows.h>
#include <string>
#include <vector>

#include "Config.h"
#include "Core.h"

struct ConfigData {
	//Flashing Odds

	int SavedFlashingOdds[FlashingOddsLength] = {};

	//Modifiers

	bool SavedMotionFlashEnabled;

	int SavedSprintingMod;
	int SavedRunningMod;

	//Constructor
	ConfigData(bool _SavedMotionFlashEnabled, int _SavedSprintingMod, int _SavedRunningMod) :
		SavedMotionFlashEnabled(_SavedMotionFlashEnabled), SavedSprintingMod(_SavedSprintingMod), SavedRunningMod(_SavedRunningMod) {}

	//Serializer
	void Serialize(std::ostream& output) {
		int index = 0;
		while (index < FlashingOddsLength) {
			SavedFlashingOdds[index] = FlashingOdds[index];
			index++;
		}

		output.write(reinterpret_cast<const char*>(&SavedFlashingOdds), sizeof(SavedFlashingOdds));
		output.write(reinterpret_cast<const char*>(&SavedMotionFlashEnabled), sizeof(SavedMotionFlashEnabled));
		output.write(reinterpret_cast<const char*>(&SavedSprintingMod), sizeof(SavedSprintingMod));
		output.write(reinterpret_cast<const char*>(&SavedRunningMod), sizeof(SavedRunningMod));
	}

	//Deserializer
	void Deserialize(std::istream& input) {
		input.read(reinterpret_cast<char*>(&SavedFlashingOdds), sizeof(SavedFlashingOdds));
		input.read(reinterpret_cast<char*>(&SavedMotionFlashEnabled), sizeof(SavedMotionFlashEnabled));
		input.read(reinterpret_cast<char*>(&SavedSprintingMod), sizeof(SavedSprintingMod));
		input.read(reinterpret_cast<char*>(&SavedRunningMod), sizeof(SavedRunningMod));

		int index = 0;
		while (index < FlashingOddsLength) {
			FlashingOdds[index] = SavedFlashingOdds[index];
			index++;
		}

		SprintingMod = SavedSprintingMod;
		RunningMod = SavedRunningMod;
		MotionFlashEnabled = SavedMotionFlashEnabled;
	}
};

struct NPCData {
	std::vector<std::string> NPCName;
	std::vector<RE::Actor> NPCActor;

	std::vector<int> NPCModestyTimer0;
	std::vector<int> NPCModestyTimer1;
	std::vector<int> NPCModestyTimer2;
	std::vector<int> NPCModestyTimer3;
	std::vector<int> NPCModestyTimer4;
	std::vector<int> NPCModestyTimer5;
	std::vector<int> NPCModestyTimer6;

	std::vector<int> NPCDefaultRankStrict;
	std::vector<int> NPCCurrentRankStrict;
	std::vector<int> NPCMinimumRankStrict;

	std::vector<int> NPCTopModestyTimer0;
	std::vector<int> NPCTopModestyTimer1;
	std::vector<int> NPCTopModestyTimer2;
	std::vector<int> NPCTopModestyTimer3;

	std::vector<int> NPCDefaultRankTop;
	std::vector<int> NPCCurrentRankTop;
	std::vector<int> NPCMinimumRankTop;

	std::vector<int> NPCBottomModestyTimer0;
	std::vector<int> NPCBottomModestyTimer1;
	std::vector<int> NPCBottomModestyTimer2;
	std::vector<int> NPCBottomModestyTimer3;

	std::vector<int> NPCDefaultRankBottom;
	std::vector<int> NPCCurrentRankBottom;
	std::vector<int> NPCMinimumRankBottom;

	std::vector<int> NPCShynessMode;

	std::vector<bool> NPCAllowPermanentShameless;
	std::vector<bool> NPCAllowCorruption;
	std::vector<bool> NPCStrictNPC;
	std::vector<bool> NPCUpgradeBlocked;

	std::vector<float> LastUpdateTime;

	int TotalSavedNPCs;

	void Serialize(std::ostream& output) {
		output.write(reinterpret_cast<const char*>(&NPCName), sizeof(NPCName));
		output.write(reinterpret_cast<const char*>(&NPCActor), sizeof(NPCActor));
	}

	void Deserialize(std::istream& input) {
		input.read(reinterpret_cast<char*>(&NPCName), sizeof(NPCName));
	}
};

struct PermanentNPCData {
	std::vector<std::string> PermanentNPCName;

	std::vector<int> PermanentNPCDefaultRankStrict;
	std::vector<int> PermanentNPCCurrentRankStrict;
	std::vector<int> PermanentNPCMinimumRankStrict;

	std::vector<int> PermanentNPCDefaultRankTop;
	std::vector<int> PermanentNPCCurrentRankTop;
	std::vector<int> PermanentNPCMinimumRankTop;

	std::vector<int> PermanentNPCDefaultRankBottom;
	std::vector<int> PermanentNPCCurrentRankBottom;
	std::vector<int> PermanentNPCMinimumRankBottom;

	std::vector<int> PermanentNPCShynessMode;

	std::vector<bool> PermanentNPCAllowPermanentShameless;
	std::vector<bool> PermanentNPCAllowCorruption;
	std::vector<bool> PermanentNPCStrictNPC;

	int TotalSavedPermanentNPCs;
};

struct PlayerData {
	bool PlayerModestyUpgradeBlocked;

	float PlayerLastTimeChecked;

	int PlayerStrictModestyTimer[7] = {0,0,0,0,0,0,0};
	int PlayerTopModestyTimer[4] = {0,0,0,0};
	int PlayerBottomModestyTimer[4] = {0,0,0,0};

	//std::string StrictModestyTitle[7] = {"Modest", "Reasonable", "Relaxed", "Comfortable", "Tease", "Brazen", "Shameless"};
	//std::string SimpleModestyTitle[4] = {"Shy", "Comfortable", "Bold", "Shameless"};
};

struct TestData {
	std::vector<std::string> NPCName;
	std::vector<RE::FormID> NPCActor;
};

/*
void SaveData(std::string FileName) {
	ConfigData SaveConfig(MotionFlashEnabled, SprintingMod, RunningMod);
	std::ofstream ConfigSaveFile("Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/" + FileName + ".ess_Config.bin", std::ios::binary);
	SaveConfig.Serialize(ConfigSaveFile);
	ConfigSaveFile.close();

	NPCData TestActorSave;
	std::ofstream TestActorSaveFile("Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/" + FileName + ".ess_Actors.bin", std::ios::binary);
	TestActorSave.NPCName.emplace_back("xxx Test Actor Name xxx");

	RE::Actor& thePlayer = *Player;
	TestActorSave.NPCActor.emplace_back(thePlayer);

	TestActorSave.Serialize(TestActorSaveFile);
	TestActorSaveFile.close();
}

void LoadData(std::string FileName) {
	std::string SavePath = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/";
	
	std::string ConfigFileName = FileName + "_Config.bin";
	if (std::filesystem::exists(SavePath + ConfigFileName)) {
		ConfigData LoadConfigData(true,0,0);
		std::ifstream LoadConfigFile(SavePath + ConfigFileName, std::ios::binary);
		LoadConfigData.Deserialize(LoadConfigFile);
		logs::critical("<C++ SaveLoad> [LoadData] Deserialized Data from {}", SavePath + ConfigFileName);
		logs::critical("<C++ SaveLoad> [LoadData] Config Data SavedFlashingOdds: {}", LoadConfigData.SavedFlashingOdds);
		logs::critical("<C++ SaveLoad> [LoadData] Config Data SavedMotionFlashEnabled: {}", LoadConfigData.SavedMotionFlashEnabled);
		logs::critical("<C++ SaveLoad> [LoadData] Config Data SavedSprintingMod: {}", LoadConfigData.SavedSprintingMod);
		logs::critical("<C++ SaveLoad> [LoadData] Config Data SavedRunningMod: {}", LoadConfigData.SavedRunningMod);
		LoadConfigFile.close();
	}
	else {
		logs::critical("<C++ SaveLoad> [LoadData] File {} NOT FOUND", SavePath + ConfigFileName);
	}

	std::string TestActorFileName = FileName + "_Actors.bin";
	if (std::filesystem::exists(SavePath + TestActorFileName)) {
		NPCData LoadTestActorData;
		std::ifstream LoadTestActorFile(SavePath + TestActorFileName, std::ios::binary);
		LoadTestActorData.Deserialize(LoadTestActorFile);
		logs::critical("<C++ SaveLoad> [LoadData] Deserialized Data from {}", SavePath + TestActorFileName);
		logs::critical("<C++ SaveLoad> [LoadData] Test Actor Data ActorName: {}", LoadTestActorData.NPCName);
		logs::critical("<C++ SaveLoad> [LoadData] Test Actor Data Actor: {}", LoadTestActorData.NPCActor);
		LoadTestActorFile.close();
	}
	else {
		logs::critical("<C++ SaveLoad> [LoadData] File {} NOT FOUND", SavePath + TestActorFileName);
	}
}

void DeleteData(std::string FileName) {
	
	std::string ConfigPath = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/" + FileName + ".ess_Config.bin";
	logs::critical("<C++ SaveLoad> [DeleteData] Attempting to delete {}", ConfigPath);

	try {
		if (std::filesystem::exists(ConfigPath)) {
			if (std::filesystem::remove(ConfigPath)) {
				logs::critical("<C++ SaveLoad> [DeleteData] File delete SUCCESS");
			}
			else {
				logs::critical("<C++ SaveLoad> [DeleteData] File delete FAILED");
			}
		}
		else {
			logs::critical("<C++ SaveLoad> [DeleteData] Cannot delete nonexistent file");
		}
	}
	catch (std::filesystem::filesystem_error& error) {
		logs::critical("<C++ SaveLoad> [DeleteData] Filesystem Error! {}", error.what());
	}
}
*/

// 4-char record tags. Must be unique within your plugin.
constexpr std::uint32_t kPluginID = 'AND4'; // Set any unique id for your plugin here
constexpr std::uint32_t kNPCsRecord = 'NPC0';
constexpr std::uint32_t kVersion = 1;

// Helpers for variable-size types
inline bool WriteString(SKSE::SerializationInterface* serializer, const std::string& stringInput) {
	const std::uint32_t len = static_cast<std::uint32_t>(stringInput.size());
	if (!serializer->WriteRecordData(&len, sizeof(len))) return false;
	return len == 0 || serializer->WriteRecordData(stringInput.data(), len);
}

inline bool ReadString(SKSE::SerializationInterface* serializer, std::string& stringOutput) {
	std::uint32_t len = 0;
	if (!serializer->ReadRecordData(&len, sizeof(len))) return false;
	stringOutput.assign(len, '\0');
	return len == 0 || serializer->ReadRecordData(stringOutput.data(), len);
}

inline void SaveCallback(SKSE::SerializationInterface* serializer)
{
	// --- NPC record ---
	if (serializer->OpenRecord(kNPCsRecord, kVersion)) {
		std::vector<std::string> names;
		std::vector<RE::FormID>  ids;
		if (auto* player = RE::PlayerCharacter::GetSingleton()) {
			names.emplace_back("xxx Test Actor Name xxx");
			ids.emplace_back(player->GetFormID());
		}

		const std::uint32_t count = (std::uint32_t)names.size();
		serializer->WriteRecordData(&count, sizeof(count));
		for (std::uint32_t index = 0; index < count; ++index) {
			WriteString(serializer, names[index]);
			serializer->WriteRecordData(&ids[index], sizeof(RE::FormID));
		}
	}
}

inline void LoadCallback(SKSE::SerializationInterface* serializer)
{
	TestData g_NPCs = {};

	std::uint32_t type, version, length;
	while (serializer->GetNextRecordInfo(type, version, length)) {
		switch (type) {

		case kNPCsRecord: {
			std::uint32_t count = 0;
			serializer->ReadRecordData(&count, sizeof(count));
			for (std::uint32_t index = 0; index < count; ++index) {
				std::string name;
				RE::FormID  rawID = 0;
				ReadString(serializer, name);
				serializer->ReadRecordData(&rawID, sizeof(rawID));

				// CRITICAL: remap FormIDs across load-order changes
				RE::FormID resolvedID = 0;
				if (!serializer->ResolveFormID(rawID, resolvedID)) {
					logs::warn("Dropping unresolved FormID {:08X}", rawID);
					continue;
				}
				g_NPCs.NPCName.push_back(std::move(name));
				g_NPCs.NPCActor.push_back(resolvedID);
			}
			break;
		}

		default:
			logs::warn("Unknown record {:08X}, skipping {} bytes", type, length);
			serializer->ReadRecordData(nullptr, length); // skip
			break;
		}
	}
}

inline void RevertCallback(SKSE::SerializationInterface*) {
	TestData g_NPCs = {};
}

inline void Register()
{
	auto* serializer = SKSE::GetSerializationInterface();
	serializer->SetUniqueID(kPluginID);
	serializer->SetSaveCallback(SaveCallback);
	serializer->SetLoadCallback(LoadCallback);
	serializer->SetRevertCallback(RevertCallback);
}