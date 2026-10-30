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
static constexpr std::uint32_t kMultiPartObjectRecord = 'MPOR';
static constexpr std::uint32_t kVersion = 1;

void SavePermanentNPCs() 
{
	constexpr char FilePath[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PersistentFemales.bin";
	constexpr char FolderPath[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/";

	if (!std::filesystem::exists(FolderPath)) {
		std::filesystem::create_directories(FolderPath);
	}

	if(!PermanentFemaleVector.size())
	{
		Log("<C++ SaveLoad> [SavePermanentNPCs] There are no Permanent NPCs to save! Skipping save function...", Logger::LogType::Core, Logger::LoggingLevel::warning);
		if (std::filesystem::exists(FilePath))
		{
			Log("<C++ SaveLoad> [SavePermanentNPCs] Deleting Permanent NPC file since no Permanent NPCs exist!", Logger::LogType::Core, Logger::LoggingLevel::warning);
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
	Log("<C++ NPCData> [LoadPermanentNPCs] - Function Triggered", Logger::LogType::Core);
	
	constexpr char FilePath[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PersistentFemales.bin";

	if (!std::filesystem::exists(FilePath))
	{
		Log("<C++ SaveLoad> [LoadPermanentNPCs] 'PermanentFemales.bin' file does not exist in expected folder. Checking for Legacy file 'PermanentActors.bin'...", Logger::LogType::Core, Logger::LoggingLevel::warning);

		constexpr char LegacyFilePath[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PermanentActors.bin";

		if (!std::filesystem::exists(LegacyFilePath))
		{
			Log("<C++ SaveLoad> [LoadPermanentNPCs] Legacy file does not exist in expected directory. No Females imported...", Logger::LogType::Core, Logger::LoggingLevel::warning);
		}
		else {
			std::ifstream LegacyActorFile(LegacyFilePath, std::ios::binary);

			LegacyActorFile.seekg(0, std::ios::end);
			size_t LegacyFileSize = LegacyActorFile.tellg();
			LegacyActorFile.seekg(0, std::ios::beg);

			LegacyPermanentFemales LegacyFemale;
			PermanentFemales ConvertedFemale;

			for (size_t Index = 0; Index < (LegacyFileSize / sizeof(LegacyPermanentFemales)); ++Index)
			{

				LegacyActorFile.read(reinterpret_cast<char*>(&LegacyFemale), sizeof(LegacyFemale));

				ConvertedFemale = ConvertLegacyFemale(LegacyFemale);

				if (FindInVector(PermanentFemaleVector, ConvertedFemale) >= 0) {
					Log("<C++ SaveLoad> [LoadPermanentNPCs] This Female " + static_cast<std::string>(ConvertedFemale.Name) + " already exists in Permanent NPC list. Skipping...", Logger::Core, Logger::critical);
					continue;
				}

				if (ValidatePermanentFemale(ConvertedFemale)) {
					PermanentFemaleVector.emplace_back(ConvertedFemale);
				}
			}

			LegacyActorFile.close();
		}

		return;
	}

	std::ifstream ActorFile(FilePath, std::ios::binary);

	ActorFile.seekg(0, std::ios::end);
	size_t FileSize = ActorFile.tellg();
	ActorFile.seekg(0, std::ios::beg);

	PermanentFemales Female;

	for(size_t Index = 0; Index < (FileSize / sizeof(PermanentFemales)); ++Index)
	{
		ActorFile.read(reinterpret_cast<char*>(&Female), sizeof(Female));

		if (FindInVector(PermanentFemaleVector, Female) >= 0) {
			Log("<C++ SaveLoad> [LoadPermanentNPCs] This Female " + static_cast<std::string>(Female.Name) + " already exists in Permanent NPC list. Skipping...", Logger::Core, Logger::critical);
			continue;
		}

		if (ValidatePermanentFemale(Female)) {
			PermanentFemaleVector.emplace_back(Female);
		}
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
		serializer->WriteRecordData(reinterpret_cast<const char*>(&ChestCurtainRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&PelvicCurtainRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&AssCurtainRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&CStringRoll), sizeof(INT8));

		serializer->WriteRecordData(reinterpret_cast<const char*>(&TopTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&BottomTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&BraTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&UnderwearTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&HotpantsTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&ShowgirlTransparentRoll), sizeof(INT8));

		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCChestCurtainRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCPelvicCurtainRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCAssCurtainRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCCStringRoll), sizeof(INT8));

		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCTopTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCBottomTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCBraTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCUnderwearTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCHotpantsTransparentRoll), sizeof(INT8));
		serializer->WriteRecordData(reinterpret_cast<const char*>(&NPCShowgirlTransparentRoll), sizeof(INT8));
	}
	
	// --- NPC record ---
	if (serializer->OpenRecord(kNPCsRecord, kVersion)) {

		const uint32_t RegisteredCount = (uint32_t)RegisteredFemaleMap.size();

		serializer->WriteRecordData(&RegisteredCount, sizeof(RegisteredCount));

		for (auto& [ID, Female] : RegisteredFemaleMap)
		{
			serializer->WriteRecordData(reinterpret_cast<const char*>(&Female), sizeof(RegisteredFemales));
		}

		SavePermanentNPCs();

		serializer->WriteRecordData(&PermanentFemalesImported, sizeof(bool));
	}

	// --- MCM record ---
	if (serializer->OpenRecord(kMCMRecord, kVersion)) {
		serializer->WriteRecordData(Configuration::FlashingOdds, sizeof(Configuration::FlashingOdds));
		serializer->WriteRecordData(&Configuration::ImmodestyTimeNeeded, sizeof(UINT16));

		serializer->WriteRecordData(&Configuration::MinimumStrictModestyRank, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::MinimumTopModestyRank, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::MinimumBottomModestyRank, sizeof(UINT8));

		serializer->WriteRecordData(&Configuration::DefaultNPCShyness, sizeof(UINT8));

		serializer->WriteRecordData(&Configuration::SprintingMod, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::RunningMod, sizeof(UINT8));

		serializer->WriteRecordData(&Configuration::PlayerConfidenceLevel, sizeof(UINT8));

		serializer->WriteRecordData(&Configuration::NudeCommentChance, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::ToplessCommentChance, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::BottomlessCommentChance, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::ChestCommentChance, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::BraCommentChance, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::AssCommentChance, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::GenitalsCommentChance, sizeof(UINT8));
		serializer->WriteRecordData(&Configuration::UnderwearCommentChance, sizeof(UINT8));

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

		float DynamicModestyValue = Configuration::DynamicModestyMode->value;
		serializer->WriteRecordData(&DynamicModestyValue, sizeof(float));
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
			serializer->WriteRecordData(&RegisteredPlugins::DynamicModestyEnabled[Index], sizeof(UINT8));
			serializer->WriteRecordData(&RegisteredPlugins::HardcoreEnabled[Index], sizeof(UINT8));
			serializer->WriteRecordData(&RegisteredPlugins::CorruptionEnabled[Index], sizeof(UINT8));
			serializer->WriteRecordData(&RegisteredPlugins::ShamelessEnabled[Index], sizeof(UINT8));
			serializer->WriteRecordData(&RegisteredPlugins::UpgradeBlocked[Index], sizeof(UINT8));
			serializer->WriteRecordData(&RegisteredPlugins::UseStrictModesty[Index], sizeof(UINT8));

			serializer->WriteRecordData(&RegisteredPlugins::MinimumStrictRank[Index], sizeof(UINT8));
			serializer->WriteRecordData(&RegisteredPlugins::MinimumTopRank[Index], sizeof(UINT8));
			serializer->WriteRecordData(&RegisteredPlugins::MinimumBottomRank[Index], sizeof(UINT8));

			serializer->WriteRecordData(&RegisteredPlugins::ImmodestyTimeRequired[Index], sizeof(UINT16));

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

		if (PlayerBaseRace == nullptr) {
			PlayerBaseRace = Player->GetRace();
		}

		std::string raceEditorID = PlayerBaseRace->GetFormEditorID();
		Log("Saving Race Editor ID String: " + raceEditorID, Logger::LogType::Core, Logger::LoggingLevel::critical);
		WriteString(serializer, raceEditorID);

		const std::uint32_t count = (uint32_t)CustomTransformations.size();
		serializer->WriteRecordData(&count, sizeof(count));
		
		for (uint32_t Index = 0; Index < count; ++Index) {
			raceEditorID = CustomTransformations[Index]->GetFormEditorID();
			WriteString(serializer, raceEditorID);
		}
	}

	// --- MULTI PART OBJECT record ---
	if (serializer->OpenRecord(kMultiPartObjectRecord, kVersion)) {
		UINT16 Count = (UINT16)TwoPart_Object_PartA.size();
		serializer->WriteRecordData(&Count, sizeof(UINT16));

		std::string EditorID;
		for (UINT16 Index = 0; Index < Count; ++Index) {
			EditorID = static_cast<std::string>(TwoPart_Object_PartA[Index]);
			WriteString(serializer, EditorID);
			
			//serializer->WriteRecordData(&EditorID, sizeof(std::string_view));
		}

		//Shouldn't be needed - All should have same count
		//Count = (UINT16)TwoPart_Object_PartB.size();

		serializer->WriteRecordData(&Count, sizeof(UINT16));

		for (UINT16 Index = 0; Index < Count; ++Index) {
			EditorID = static_cast<std::string>(TwoPart_Object_PartB[Index]);
			WriteString(serializer, EditorID);
		}

		//Shouldn't be needed - All should have same count
		//Count = (UINT16)TwoPart_Object_Type.size();
		
		serializer->WriteRecordData(&Count, sizeof(UINT16));

		UINT8 TypeIndex;
		for (UINT16 Index = 0; Index < Count; ++Index) {
			TypeIndex = TwoPart_Object_Type[Index];
			serializer->WriteRecordData(&TypeIndex, sizeof(UINT8));
		}
	}
}

inline void LoadCallback(SKSE::SerializationInterface* serializer)
{
	Log("<C++ NPCData> [LoadCallback] - Function Triggered", Logger::LogType::Core);
	
	std::uint32_t type, version, length;
	while (serializer->GetNextRecordInfo(type, version, length)) {
		switch (type) {

			case kCoreRecord:
			{
				serializer->ReadRecordData(&ChestCurtainRoll, sizeof(ChestCurtainRoll));
				serializer->ReadRecordData(&PelvicCurtainRoll, sizeof(PelvicCurtainRoll));
				serializer->ReadRecordData(&AssCurtainRoll, sizeof(AssCurtainRoll));
				serializer->ReadRecordData(&CStringRoll, sizeof(CStringRoll));

				serializer->ReadRecordData(&TopTransparentRoll, sizeof(TopTransparentRoll));
				serializer->ReadRecordData(&BottomTransparentRoll, sizeof(BottomTransparentRoll));
				serializer->ReadRecordData(&BraTransparentRoll, sizeof(BraTransparentRoll));
				serializer->ReadRecordData(&UnderwearTransparentRoll, sizeof(UnderwearTransparentRoll));
				serializer->ReadRecordData(&HotpantsTransparentRoll, sizeof(HotpantsTransparentRoll));
				serializer->ReadRecordData(&ShowgirlTransparentRoll, sizeof(ShowgirlTransparentRoll));

				serializer->ReadRecordData(&NPCChestCurtainRoll, sizeof(NPCChestCurtainRoll));
				serializer->ReadRecordData(&NPCPelvicCurtainRoll, sizeof(NPCPelvicCurtainRoll));
				serializer->ReadRecordData(&NPCAssCurtainRoll, sizeof(NPCAssCurtainRoll));
				serializer->ReadRecordData(&NPCCStringRoll, sizeof(NPCCStringRoll));

				serializer->ReadRecordData(&NPCTopTransparentRoll, sizeof(NPCTopTransparentRoll));
				serializer->ReadRecordData(&NPCBottomTransparentRoll, sizeof(NPCBottomTransparentRoll));
				serializer->ReadRecordData(&NPCBraTransparentRoll, sizeof(NPCBraTransparentRoll));
				serializer->ReadRecordData(&NPCUnderwearTransparentRoll, sizeof(NPCUnderwearTransparentRoll));
				serializer->ReadRecordData(&NPCHotpantsTransparentRoll, sizeof(NPCHotpantsTransparentRoll));
				serializer->ReadRecordData(&NPCShowgirlTransparentRoll, sizeof(NPCShowgirlTransparentRoll));
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

				serializer->ReadRecordData(&Configuration::ImmodestyTimeNeeded, sizeof(UINT16));

				serializer->ReadRecordData(&Configuration::MinimumStrictModestyRank, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::MinimumTopModestyRank, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::MinimumBottomModestyRank, sizeof(UINT8));

				serializer->ReadRecordData(&Configuration::DefaultNPCShyness, sizeof(UINT8));

				serializer->ReadRecordData(&Configuration::SprintingMod, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::RunningMod, sizeof(UINT8));

				serializer->ReadRecordData(&Configuration::PlayerConfidenceLevel, sizeof(UINT8));

				serializer->ReadRecordData(&Configuration::NudeCommentChance, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::ToplessCommentChance, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::BottomlessCommentChance, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::ChestCommentChance, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::BraCommentChance, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::AssCommentChance, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::GenitalsCommentChance, sizeof(UINT8));
				serializer->ReadRecordData(&Configuration::UnderwearCommentChance, sizeof(UINT8));

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

				UINT8 bValue;

				UINT8 ui8Value;
				UINT16 ui16Value;

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

					serializer->ReadRecordData(&ui8Value, sizeof(UINT8));
					RegisteredPlugins::MinimumStrictRank.emplace_back(ui8Value);

					serializer->ReadRecordData(&ui8Value, sizeof(UINT8));
					RegisteredPlugins::MinimumTopRank.emplace_back(ui8Value);

					serializer->ReadRecordData(&ui8Value, sizeof(UINT8));
					RegisteredPlugins::MinimumBottomRank.emplace_back(ui8Value);

					serializer->ReadRecordData(&ui16Value, sizeof(UINT16));
					RegisteredPlugins::ImmodestyTimeRequired.emplace_back(ui16Value);

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
				Log("Loading Race Editor ID String: " + raceEditorID, Logger::LogType::Core, Logger::LoggingLevel::critical);
				PlayerBaseRace = RE::TESForm::LookupByEditorID<RE::TESRace>(raceEditorID) != nullptr ? RE::TESForm::LookupByEditorID<RE::TESRace>(raceEditorID) : Player->GetRace();

				std::uint32_t count = 0;
				serializer->ReadRecordData(&count, sizeof(count));
				
				for (uint32_t Index = 0; Index < count; ++Index) {
					ReadString(serializer, raceEditorID);
					CustomTransformations.emplace_back(RE::TESForm::LookupByEditorID<RE::TESRace>(raceEditorID));
				}
				break;
			}

			case kMultiPartObjectRecord: {
				std::string EditorID;
				UINT16 Count;

				serializer->ReadRecordData(&Count, sizeof(UINT16));

				//Part A Reads
				for (UINT16 Index = 0; Index < Count; ++Index) {
					ReadString(serializer, EditorID);
					//serializer->ReadRecordData(&EditorID, sizeof(std::string_view));
					TwoPart_Object_PartA.emplace_back(EditorID);
				}

				//Part B Reads
				//serializer->ReadRecordData(&Count, sizeof(UINT16));

				for (UINT16 Index = 0; Index < Count; ++Index) {
					ReadString(serializer, EditorID);
					//serializer->ReadRecordData(&EditorID, sizeof(std::string_view));
					TwoPart_Object_PartB.emplace_back(EditorID);
				}

				//Object Type Reads
				//serializer->ReadRecordData(&Count, sizeof(UINT16));

				UINT8 ObjectType;
				for (UINT16 Index = 0; Index < Count; ++Index) {
					serializer->ReadRecordData(&ObjectType, sizeof(UINT8));
					TwoPart_Object_Type.emplace_back(ObjectType);
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

	//Clear Multi-Part Object Lists
	TwoPart_Object_PartA.clear();
	TwoPart_Object_PartB.clear();
	TwoPart_Object_Type.clear();
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