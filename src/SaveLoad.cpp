#include <string>
#include <vector>

#include "SaveLoad.h"
#include "Config.h"
#include "Core.h"
#include "Logger.h"
#include "NPCData.h"
#include "ModEventHandler.h"
#include "PlayerModesty.h"
#include "Player.h"

// 4-char record tags. Must be unique within your plugin.
static constexpr std::uint32_t kPluginID = 'AND4'; // Set any unique id for your plugin here
static constexpr std::uint32_t kCoreRecord = 'CORE';
static constexpr std::uint32_t kNPCsRecord = 'NPC0';
static constexpr std::uint32_t kMCMRecord = 'MCM0';
static constexpr std::uint32_t kLogRecord = 'LOG0';
static constexpr std::uint32_t kModEventHandlerRecord = 'MEH0';
static constexpr std::uint32_t kPlayerRecord = 'PLY0';
static constexpr std::uint32_t kVersion = 1;

void SavePermanentNPCs() 
{
	constexpr char FilePath[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PermanentActors.bin";

	if(!PermanentFemaleVector.size())
	{
		Log("<C++ SaveLoad> [SavePermanentNPCs] There are no Permanent NPCs to save! Skipping save function...", LogType::Core, LoggingLevel::warning);
		if (std::filesystem::exists(FilePath))
		{
			Log("<C++ SaveLoad> [SavePermanentNPCs] Deleting Permanent NPC file since no Permanent NPCs exist!", LogType::Core, LoggingLevel::warning);
			std::filesystem::remove(FilePath);
		}

		return;
	}

	std::ofstream ActorFile(FilePath, std::ios::trunc | std::ios::binary);

	for(auto& Female : PermanentFemaleVector)
	{
		ActorFile.write(reinterpret_cast<char*>(&Female), sizeof(Female));
	}

	ActorFile.close();
}

void LoadPermanentNPCs()
{
	Log("<C++ NPCData> [LoadPermanentNPCs] - Function Triggered", LogType::Core);
	
	constexpr char FilePath[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PermanentActors.bin";

	if (!std::filesystem::exists(FilePath))
	{
		Log("<C++ SaveLoad> [LoadPermanentNPCs] Permanent NPC File does not exist!", LogType::Core, LoggingLevel::warning);

		return;
	}

	std::ifstream ActorFile(FilePath, std::ios::binary);

	ActorFile.seekg(0, std::ios::end);
	size_t FileSize = ActorFile.tellg();
	ActorFile.seekg(0, std::ios::beg);

	for(size_t Index = 0; Index < (FileSize / sizeof(PermanentFemales)); ++Index)
	{
		PermanentFemales Female;
		ActorFile.read(reinterpret_cast<char*>(&Female), sizeof(Female));
		
		PermanentFemaleVector.emplace_back(Female);
	}

	ActorFile.close();
}

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
	if (serializer->OpenRecord(kCoreRecord, kVersion)) {
		serializer->WriteRecordData(reinterpret_cast<const char*>(&ChestCurtainRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&PelvicCurtainRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&AssCurtainRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&CStringRoll), sizeof(int));

		serializer->WriteRecordData(reinterpret_cast<const char*>(&TopTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&BottomTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&BraTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&UnderwearTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&HotpantsTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&ShowgirlTransparentRoll), sizeof(int));

		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCChestCurtainRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCPelvicCurtainRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCAssCurtainRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCCStringRoll), sizeof(int));

		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCTopTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCBottomTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCBraTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCUnderwearTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCHotpantsTransparentRoll), sizeof(int));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCShowgirlTransparentRoll), sizeof(int));
	}
	
	// --- NPC record ---
	if (serializer->OpenRecord(kNPCsRecord, kVersion)) {

		const uint32_t RegisteredCount = (uint32_t)RegisteredFemaleMap.size();

		serializer->WriteRecordData(&RegisteredCount, sizeof(RegisteredCount));

		for (auto& [ID, Female] : RegisteredFemaleMap)
		{
			serializer->WriteRecordData(reinterpret_cast<const char*>(&Female), sizeof(Female));
		}

		SavePermanentNPCs();

		serializer->WriteRecordData(&PermanentFemalesImported, sizeof(bool));
	}

	// --- MCM record ---
	if (serializer->OpenRecord(kMCMRecord, kVersion)) {
		serializer->WriteRecordData(Configuration::FlashingOdds, sizeof(Configuration::FlashingOdds));
		serializer->WriteRecordData(&Configuration::ImmodestyTimeNeeded, sizeof(int));

		serializer->WriteRecordData(&Configuration::MinimumStrictModestyRank, sizeof(int));
		serializer->WriteRecordData(&Configuration::MinimumTopModestyRank, sizeof(int));
		serializer->WriteRecordData(&Configuration::MinimumBottomModestyRank, sizeof(int));

		serializer->WriteRecordData(&Configuration::DefaultNPCShyness, sizeof(int));

		serializer->WriteRecordData(&Configuration::SprintingMod, sizeof(int));
		serializer->WriteRecordData(&Configuration::RunningMod, sizeof(int));

		serializer->WriteRecordData(&Configuration::PlayerConfidenceLevel, sizeof(int));

		serializer->WriteRecordData(&Configuration::NudeCommentChance, sizeof(int));
		serializer->WriteRecordData(&Configuration::ToplessCommentChance, sizeof(int));
		serializer->WriteRecordData(&Configuration::BottomlessCommentChance, sizeof(int));
		serializer->WriteRecordData(&Configuration::ChestCommentChance, sizeof(int));
		serializer->WriteRecordData(&Configuration::BraCommentChance, sizeof(int));
		serializer->WriteRecordData(&Configuration::AssCommentChance, sizeof(int));
		serializer->WriteRecordData(&Configuration::GenitalsCommentChance, sizeof(int));
		serializer->WriteRecordData(&Configuration::UnderwearCommentChance, sizeof(int));

		serializer->WriteRecordData(&Configuration::MotionFlashEnabled, sizeof(bool));
		serializer->WriteRecordData(&Configuration::DynamicModestyEnabled, sizeof(bool));

		serializer->WriteRecordData(&Configuration::AllowPlayerShameless, sizeof(bool));
		serializer->WriteRecordData(&Configuration::NPCShamelessByDefault, sizeof(bool));

		serializer->WriteRecordData(&Configuration::AllowPlayerCorruption, sizeof(bool));
		serializer->WriteRecordData(&Configuration::NPCCorruptionByDefault, sizeof(bool));

		serializer->WriteRecordData(&Configuration::StrictModestyRules, sizeof(bool));
		serializer->WriteRecordData(&Configuration::NPCStrictRulesByDefault, sizeof(bool));

		serializer->WriteRecordData(&Configuration::HardcoreModeEnabled, sizeof(bool));
		
		serializer->WriteRecordData(&Configuration::ModestyUpgradeBlocked, sizeof(bool));

		serializer->WriteRecordData(&Configuration::DisableNakedComments, sizeof(bool));

		float DynamicModstyValue = Configuration::DynamicModestyMode->value;
		serializer->WriteRecordData(&DynamicModstyValue, sizeof(float));
	}

	// --- LOG record ---
	if (serializer->OpenRecord(kLogRecord, kVersion)) {
		serializer->WriteRecordData(LogTypeEnabled, sizeof(LogTypeEnabled));
		serializer->WriteRecordData(LogLevelEnabled, sizeof(LogLevelEnabled));
	}

	// --- MOD EVENTS record ---
	if (serializer->OpenRecord(kModEventHandlerRecord, kVersion)) {
		const std::uint32_t count = RegisteredPlugins::TotalRegisteredPlugins;

		serializer->WriteRecordData(&count, sizeof(count));

		uint32_t Index = 0;
		while (Index < count) {
			serializer->WriteRecordData(&RegisteredPlugins::DynamicModestyEnabled[Index], sizeof(uint8_t));
			serializer->WriteRecordData(&RegisteredPlugins::HardcoreEnabled[Index], sizeof(uint8_t));
			serializer->WriteRecordData(&RegisteredPlugins::CorruptionEnabled[Index], sizeof(uint8_t));
			serializer->WriteRecordData(&RegisteredPlugins::ShamelessEnabled[Index], sizeof(uint8_t));
			serializer->WriteRecordData(&RegisteredPlugins::UpgradeBlocked[Index], sizeof(uint8_t));
			serializer->WriteRecordData(&RegisteredPlugins::UseStrictModesty[Index], sizeof(uint8_t));

			serializer->WriteRecordData(&RegisteredPlugins::MinimumStrictRank[Index], sizeof(int));
			serializer->WriteRecordData(&RegisteredPlugins::MinimumTopRank[Index], sizeof(int));
			serializer->WriteRecordData(&RegisteredPlugins::MinimumBottomRank[Index], sizeof(int));

			serializer->WriteRecordData(&RegisteredPlugins::ImmodestyTimeRequired[Index], sizeof(int));

			WriteString(serializer, RegisteredPlugins::Plugins[Index]);
			Index++;
		}
	}

	// --- PLAYER record ---
	if (serializer->OpenRecord(kPlayerRecord, kVersion)) {
		serializer->WriteRecordData(StrictModestyTimer, sizeof(StrictModestyTimer));
		serializer->WriteRecordData(TopModestyTimer, sizeof(TopModestyTimer));
		serializer->WriteRecordData(BottomModestyTimer, sizeof(BottomModestyTimer));

		serializer->WriteRecordData(&LastTimeChecked, sizeof(float));

		serializer->WriteRecordData(&IsWearingChestCurtain, sizeof(bool));
		serializer->WriteRecordData(&IsWearingPelvicCurtain, sizeof(bool));
		serializer->WriteRecordData(&IsWearingAssCurtain, sizeof(bool));

		serializer->WriteRecordData(&PlayerFactionsInitialized, sizeof(bool));

		std::string raceEditorID = PlayerBaseRace->GetFormEditorID();
		Log("Saving Race Editor ID String: " + raceEditorID, LogType::Core, LoggingLevel::critical);
		WriteString(serializer, raceEditorID);

		const std::uint32_t count = (uint32_t)CustomTransformations.size();
		serializer->WriteRecordData(&count, sizeof(count));
		
		for (uint32_t Index = 0; Index < count; ++Index) {
			raceEditorID = CustomTransformations[Index]->GetFormEditorID();
			WriteString(serializer, raceEditorID);
		}
	}
}

inline void LoadCallback(SKSE::SerializationInterface* serializer)
{
	Log("<C++ NPCData> [LoadCallback] - Function Triggered", LogType::Core);
	
	std::uint32_t type, version, length;
	while (serializer->GetNextRecordInfo(type, version, length)) {
		switch (type) {

			case kCoreRecord:
			{
				serializer->ReadRecordData(&ChestCurtainRoll, sizeof(int));
				serializer->ReadRecordData(&PelvicCurtainRoll, sizeof(int));
				serializer->ReadRecordData(&AssCurtainRoll, sizeof(int));
				serializer->ReadRecordData(&CStringRoll, sizeof(int));

				serializer->ReadRecordData(&TopTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&BottomTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&BraTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&UnderwearTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&HotpantsTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&ShowgirlTransparentRoll, sizeof(int));

				serializer->ReadRecordData(&NPCChestCurtainRoll, sizeof(int));
				serializer->ReadRecordData(&NPCPelvicCurtainRoll, sizeof(int));
				serializer->ReadRecordData(&NPCAssCurtainRoll, sizeof(int));
				serializer->ReadRecordData(&NPCCStringRoll, sizeof(int));

				serializer->ReadRecordData(&NPCTopTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&NPCBottomTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&NPCBraTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&NPCUnderwearTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&NPCHotpantsTransparentRoll, sizeof(int));
				serializer->ReadRecordData(&NPCShowgirlTransparentRoll, sizeof(int));
				break;
			}

			case kNPCsRecord: 
			{
				uint32_t RegisteredCount = 0;
				serializer->ReadRecordData(&RegisteredCount, sizeof(RegisteredCount));
				logs::critical("Reading NPC Records. RegisteredFemales Record Count is {}", RegisteredCount);
				
				for (uint32_t Index = 0; Index < RegisteredCount; ++Index)
				{
					RegisteredFemales ThisFemale;
					serializer->ReadRecordData(reinterpret_cast<char*>(&ThisFemale), sizeof(ThisFemale));

					RE::FormID ResolvedID = 0;
					if (!serializer->ResolveFormID(ThisFemale.FemaleFormID, ResolvedID))
					{
						logs::warn("Dropping unresolved FormID {:08X}", ThisFemale.FemaleFormID);

						continue;
					}

					ThisFemale.FemaleFormID = ResolvedID;

					RegisteredFemaleMap[ThisFemale.FemaleFormID] = ThisFemale;
				}

				LoadPermanentNPCs();

				serializer->ReadRecordData(&PermanentFemalesImported, sizeof(bool));

				break;
			}

			case kMCMRecord: {
				serializer->ReadRecordData(Configuration::FlashingOdds, sizeof(Configuration::FlashingOdds));

				serializer->ReadRecordData(&Configuration::ImmodestyTimeNeeded, sizeof(int));

				serializer->ReadRecordData(&Configuration::MinimumStrictModestyRank, sizeof(int));
				serializer->ReadRecordData(&Configuration::MinimumTopModestyRank, sizeof(int));
				serializer->ReadRecordData(&Configuration::MinimumBottomModestyRank, sizeof(int));

				serializer->ReadRecordData(&Configuration::DefaultNPCShyness, sizeof(int));

				serializer->ReadRecordData(&Configuration::SprintingMod, sizeof(int));
				serializer->ReadRecordData(&Configuration::RunningMod, sizeof(int));

				serializer->ReadRecordData(&Configuration::PlayerConfidenceLevel, sizeof(int));

				serializer->ReadRecordData(&Configuration::NudeCommentChance, sizeof(int));
				serializer->ReadRecordData(&Configuration::ToplessCommentChance, sizeof(int));
				serializer->ReadRecordData(&Configuration::BottomlessCommentChance, sizeof(int));
				serializer->ReadRecordData(&Configuration::ChestCommentChance, sizeof(int));
				serializer->ReadRecordData(&Configuration::BraCommentChance, sizeof(int));
				serializer->ReadRecordData(&Configuration::AssCommentChance, sizeof(int));
				serializer->ReadRecordData(&Configuration::GenitalsCommentChance, sizeof(int));
				serializer->ReadRecordData(&Configuration::UnderwearCommentChance, sizeof(int));

				serializer->ReadRecordData(&Configuration::MotionFlashEnabled, sizeof(bool));
				serializer->ReadRecordData(&Configuration::DynamicModestyEnabled, sizeof(bool));

				serializer->ReadRecordData(&Configuration::AllowPlayerShameless, sizeof(bool));
				serializer->ReadRecordData(&Configuration::NPCShamelessByDefault, sizeof(bool));

				serializer->ReadRecordData(&Configuration::AllowPlayerCorruption, sizeof(bool));
				serializer->ReadRecordData(&Configuration::NPCCorruptionByDefault, sizeof(bool));

				serializer->ReadRecordData(&Configuration::StrictModestyRules, sizeof(bool));
				serializer->ReadRecordData(&Configuration::NPCStrictRulesByDefault, sizeof(bool));

				serializer->ReadRecordData(&Configuration::HardcoreModeEnabled, sizeof(bool));

				serializer->ReadRecordData(&Configuration::ModestyUpgradeBlocked, sizeof(bool));

				serializer->ReadRecordData(&Configuration::DisableNakedComments, sizeof(bool));

				float DynamicModestyValue;
				serializer->ReadRecordData(&DynamicModestyValue, sizeof(float));
				Configuration::DynamicModestyMode->value = DynamicModestyValue;

				break;
			}

			case kLogRecord: {
				serializer->ReadRecordData(LogTypeEnabled, sizeof(LogTypeEnabled));
				serializer->ReadRecordData(LogLevelEnabled, sizeof(LogLevelEnabled));
				
				break;
			}

			case kModEventHandlerRecord: {
				std::uint32_t count = 0;
				serializer->ReadRecordData(&count, sizeof(count));

				uint8_t bValue;

				int iValue;

				std::string sValue;

				uint32_t Index = 0;
				while (Index < count) {
					serializer->ReadRecordData(&bValue, sizeof(bValue));
					RegisteredPlugins::DynamicModestyEnabled.emplace_back(bValue);
					
					serializer->ReadRecordData(&bValue, sizeof(bValue));
					RegisteredPlugins::HardcoreEnabled.emplace_back(bValue);
					
					serializer->ReadRecordData(&bValue, sizeof(bValue));
					RegisteredPlugins::CorruptionEnabled.emplace_back(bValue);
					
					serializer->ReadRecordData(&bValue, sizeof(bValue));
					RegisteredPlugins::ShamelessEnabled.emplace_back(bValue);
					
					serializer->ReadRecordData(&bValue, sizeof(bValue));
					RegisteredPlugins::UpgradeBlocked.emplace_back(bValue);
					
					serializer->ReadRecordData(&bValue, sizeof(bValue));
					RegisteredPlugins::UseStrictModesty.emplace_back(bValue);

					serializer->ReadRecordData(&iValue, sizeof(int));
					RegisteredPlugins::MinimumStrictRank.emplace_back(iValue);

					serializer->ReadRecordData(&iValue, sizeof(int));
					RegisteredPlugins::MinimumTopRank.emplace_back(iValue);

					serializer->ReadRecordData(&iValue, sizeof(int));
					RegisteredPlugins::MinimumBottomRank.emplace_back(iValue);

					serializer->ReadRecordData(&iValue, sizeof(int));
					RegisteredPlugins::ImmodestyTimeRequired.emplace_back(iValue);

					ReadString(serializer, sValue);
					RegisteredPlugins::Plugins.emplace_back(sValue);

					Index++;
				}
				break;
			}

			case kPlayerRecord: {
				serializer->ReadRecordData(StrictModestyTimer, sizeof(StrictModestyTimer));
				serializer->ReadRecordData(TopModestyTimer, sizeof(TopModestyTimer));
				serializer->ReadRecordData(BottomModestyTimer, sizeof(BottomModestyTimer));

				serializer->ReadRecordData(&LastTimeChecked, sizeof(float));

				serializer->ReadRecordData(&IsWearingChestCurtain, sizeof(bool));
				serializer->ReadRecordData(&IsWearingPelvicCurtain, sizeof(bool));
				serializer->ReadRecordData(&IsWearingAssCurtain, sizeof(bool));

				serializer->ReadRecordData(&PlayerFactionsInitialized, sizeof(bool));

				std::string raceEditorID;
				ReadString(serializer, raceEditorID);
				Log("Loading Race Editor ID String: " + raceEditorID, LogType::Core, LoggingLevel::critical);
				PlayerBaseRace = RE::TESForm::LookupByEditorID<RE::TESRace>(raceEditorID);

				std::uint32_t count = 0;
				serializer->ReadRecordData(&count, sizeof(count));
				
				for (uint32_t Index = 0; Index < count; ++Index) {
					ReadString(serializer, raceEditorID);
					CustomTransformations.emplace_back(RE::TESForm::LookupByEditorID<RE::TESRace>(raceEditorID));
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
	logs::critical("SAVELOAD | RevertCallback");
	NPCDataOnRevertCallback();

	InitializeConfigData();

	//Clear Flash Rolls
	ChestCurtainRoll = -1;
	PelvicCurtainRoll = -1;
	AssCurtainRoll = -1;
	CStringRoll = -1;

	TopTransparentRoll = -1;
	BottomTransparentRoll = -1;
	BraTransparentRoll = -1;
	UnderwearTransparentRoll = -1;
	HotpantsTransparentRoll = -1;
	ShowgirlTransparentRoll = -1;

	NPCChestCurtainRoll = -1;
	NPCPelvicCurtainRoll = -1;
	NPCAssCurtainRoll = -1;
	NPCCStringRoll = -1;

	NPCTopTransparentRoll = -1;
	NPCBottomTransparentRoll = -1;
	NPCBraTransparentRoll = -1;
	NPCUnderwearTransparentRoll = -1;
	NPCHotpantsTransparentRoll = -1;
	NPCShowgirlTransparentRoll = -1;

	//Clear Custom Transform List
	CustomTransformations.clear();
}

void RegisterCoSaveSerializer()
{
	auto* serializer = SKSE::GetSerializationInterface();
	serializer->SetUniqueID(kPluginID);
	serializer->SetSaveCallback(SaveCallback);
	serializer->SetLoadCallback(LoadCallback);
	serializer->SetRevertCallback(RevertCallback);

	logs::critical("CoSave Serializer Registered!");
}