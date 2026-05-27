#include <string>
#include <vector>

#include "SaveLoad.h"
#include "Config.h"
#include "Core.h"
#include "Logger.h"
#include "NPCData.h"
#include "ModEventHandler.h"
#include "PlayerModesty.h"

void SavePermanentNPCs() 
{
	const char path[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PermanentActors.txt";

	if(!permanentfemales.size())
	{
		Log("<C++ SaveLoad> [SavePermanentNPCs] There are no Permanent NPCs to save! Skipping save function...", LogType::Core, LoggingLevel::warning);
		if (std::filesystem::exists(path)) 
		{
			Log("<C++ SaveLoad> [SavePermanentNPCs] Deleting Permanent NPC file since no Permanent NPCs exist!", LogType::Core, LoggingLevel::warning);
			std::filesystem::remove(path);
		}

		return;
	}

	std::ofstream file(path, std::ios::binary);

	for(auto& female : permanentfemales)
	{
		file.write(reinterpret_cast<char*>(&female), sizeof(female));
	}

	file.close();
}

void LoadPermanentNPCs()
{
	const char path[] = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PermanentActors.txt";

	if (!std::filesystem::exists(path))
	{
		Log("<C++ SaveLoad> [LoadPermanentNPCs] Permanent NPC File does not exist!", LogType::Core, LoggingLevel::warning);

		return;
	}

	std::ifstream file(path, std::ios::binary);

	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(0, std::ios::beg);

	for(size_t i = 0; i < (size / sizeof(PermanentFemales)); ++i)
	{
		PermanentFemales female;
		file.read(reinterpret_cast<char*>(&female), sizeof(female));

		permanentfemales.emplace_back(female);
	}

	file.close();
}
*/

void Serialize(std::ostream& output) {
	logs::critical("SAVELOAD | Serialize - START");

	logs::critical("SAVELOAD | Serialize - Writing TotalFemales...");
	output.write(reinterpret_cast<const char*>(&PermanentFemales::TotalFemales), sizeof(int));

	std::array<char, 256> tempCharArray;

	//std::vector<std::array<char, 256>> tempPluginVector;
	//std::vector<std::array<char, 256>> tempNameVector;

	int Index = 0;

	while (Index < PermanentFemales::TotalFemales) {
		
		logs::critical("SAVELOAD | Serialize - Writing LocalID. Index {}", Index);
		output.write(reinterpret_cast<const char*>(&PermanentFemales::FemaleLocalID[Index]), sizeof(RE::FormID));

		logs::critical("SAVELOAD | Serialize - Writing FemalePlugin. Index {}", Index);
		//PermanentFemales::FemalePlugin[Index].copy(tempPluginVector[Index].data(), tempPluginVector[Index].size());
		PermanentFemales::FemalePlugin[Index].copy(tempCharArray.data(), tempCharArray.size());
		//output.write(reinterpret_cast<const char*>(tempPluginVector[Index].data()), sizeof(char[256]));
		output.write(tempCharArray.data(), sizeof(char[256]));

		logs::critical("SAVELOAD | Serialize - Writing IsInLightPlugin. Index {}", Index);
		output.write(reinterpret_cast<const char*>(&PermanentFemales::IsInLightPlugin[Index]), sizeof(uint8_t));
		
		logs::critical("SAVELOAD | Serialize - Writing FemaleName. Index {}", Index);
		PermanentFemales::FemaleName[Index].copy(tempCharArray.data(), tempCharArray.size());
		output.write(tempCharArray.data(), sizeof(char[256]));

		logs::critical("SAVELOAD | Serialize - Writing Strict Ranks. Index {}", Index);
		output.write(reinterpret_cast<const char*>(&PermanentFemales::DefaultRankStrict[Index]), sizeof(int));
		output.write(reinterpret_cast<const char*>(&PermanentFemales::MinimumRankStrict[Index]), sizeof(int));

		logs::critical("SAVELOAD | Serialize - Writing Top Ranks. Index {}", Index);
		output.write(reinterpret_cast<const char*>(&PermanentFemales::DefaultRankTop[Index]), sizeof(int));
		output.write(reinterpret_cast<const char*>(&PermanentFemales::MinimumRankTop[Index]), sizeof(int));

		logs::critical("SAVELOAD | Serialize - Writing BottomRanks. Index {}", Index);
		output.write(reinterpret_cast<const char*>(&PermanentFemales::DefaultRankBottom[Index]), sizeof(int));
		output.write(reinterpret_cast<const char*>(&PermanentFemales::MinimumRankBottom[Index]), sizeof(int));

		logs::critical("SAVELOAD | Serialize - Writing Shyness and Sexuality. Index {}", Index);
		output.write(reinterpret_cast<const char*>(&PermanentFemales::ShynessMode[Index]), sizeof(int));
		output.write(reinterpret_cast<const char*>(&PermanentFemales::SexualityScore[Index]), sizeof(int));

		logs::critical("SAVELOAD | Serialize - Writing Rulesets. Index {}", Index);
		output.write(reinterpret_cast<const char*>(&PermanentFemales::AllowShameless[Index]), sizeof(uint8_t));
		output.write(reinterpret_cast<const char*>(&PermanentFemales::AllowCorruption[Index]), sizeof(uint8_t));
		output.write(reinterpret_cast<const char*>(&PermanentFemales::StrictRules[Index]), sizeof(uint8_t));

		Index++;
	}
	logs::critical("SAVELOAD | Serialize - COMPLETE");
}

void SavePermanentNPCs() {
	std::string FilePath = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PermanentActors.bin";

	if (PermanentFemales::TotalFemales < 1) {
		Log("<C++ SaveLoad> [SavePermanentNPCs] There are no Permanent NPCs to save! Skipping save function...", LogType::Core, LoggingLevel::warning);

		if (std::filesystem::exists(FilePath)) {
			Log("<C++ SaveLoad> [SavePermanentNPCs] Deleting Permanent NPC file since no Permanent NPCs exist!", LogType::Core, LoggingLevel::warning);
			std::filesystem::remove(FilePath);
		}
		return;
	}

	logs::critical("SAVELOAD | SavePermanentNPCs - Create OFSTREAM");
	std::ofstream SaveFile(FilePath, std::ios::binary);

	logs::critical("SAVELOAD | SavePermanentNPCs - SERIALIZE");
	Serialize(SaveFile);
	SaveFile.close();
}

void Deserialize(std::istream& input) {
	logs::critical("SAVELOAD | Deserialize - START");
	
	logs::critical("SAVELOAD | Deserialize - Reading TotalFemales...");
	input.read(reinterpret_cast<char*>(&PermanentFemales::TotalFemales), sizeof(int));

	RE::FormID tempFormID;

	uint8_t bValue;

	int iValue;

	std::array<char, 256> tempCharArray;

	//std::vector<std::array<char, 256>> tempPluginVector;
	//std::vector<std::array<char, 256>> tempNameVector;

	int Index = 0;
	while (Index < PermanentFemales::TotalFemales) {
		logs::critical("SAVELOAD | Deserialize - Reading LocalID. Index {}", Index);
		input.read(reinterpret_cast<char*>(&tempFormID), sizeof(RE::FormID));
		PermanentFemales::FemaleLocalID.emplace_back(tempFormID);

		logs::critical("SAVELOAD | Deserialize - Reading FemalePlugin. Index {}", Index);
		input.read(reinterpret_cast<char*>(&tempCharArray), sizeof(char[256]));
		PermanentFemales::FemalePlugin.emplace_back(tempCharArray.data());

		logs::critical("SAVELOAD | Deserialize - Reading IsInLightPlugin. Index {}", Index);
		input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
		PermanentFemales::IsInLightPlugin.emplace_back(bValue);

		logs::critical("SAVELOAD | Deserialize - Reading FemaleName. Index {}", Index);
		input.read(reinterpret_cast<char*>(&tempCharArray), sizeof(char[256]));
		PermanentFemales::FemaleName.emplace_back(tempCharArray.data());

		//Ranks

		logs::critical("SAVELOAD | Deserialize - Reading Ranks. Index {}", Index);
		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::DefaultRankStrict.emplace_back(iValue);

		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::MinimumRankStrict.emplace_back(iValue);

		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::DefaultRankTop.emplace_back(iValue);

		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::MinimumRankTop.emplace_back(iValue);

		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::DefaultRankBottom.emplace_back(iValue);

		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::MinimumRankBottom.emplace_back(iValue);

		//Shy & Sexuality

		logs::critical("SAVELOAD | Deserialize - Reading Shyness and Sexuality. Index {}", Index);
		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::ShynessMode.emplace_back(iValue);

		input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
		PermanentFemales::SexualityScore.emplace_back(iValue);

		//Rulesets

		logs::critical("SAVELOAD | Deserialize - Reading Rulesets. Index {}", Index);
		input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
		PermanentFemales::AllowShameless.emplace_back(bValue);

		input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
		PermanentFemales::AllowCorruption.emplace_back(bValue);

		input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
		PermanentFemales::StrictRules.emplace_back(bValue);

		Index++;
	}

	logs::critical("SAVELOAD | Deserialize - COMPLETE");
}

void LoadPermanentNPCs() {
	std::string FilePath = "Data/SKSE/Plugins/NymphoElf/Advanced Nudity Detection/PermanentActors.bin";

	if (std::filesystem::exists(FilePath)) {
		std::ifstream LoadFile(FilePath, std::ios::binary);
		Deserialize(LoadFile);
		LoadFile.close();
	}
	else {
		Log("<C++ SaveLoad> [LoadPermanentNPCs] Permanent NPC File does not exist!", LogType::Core, LoggingLevel::warning);
	}
}

// 4-char record tags. Must be unique within your plugin.
constexpr std::uint32_t kPluginID = 'AND4'; // Set any unique id for your plugin here
constexpr std::uint32_t kNPCsRecord = 'NPC0';
constexpr std::uint32_t kMCMRecord = 'MCM0';
constexpr std::uint32_t kLogRecord = 'LOG0';
constexpr std::uint32_t kModEventHandlerRecord = 'MEH0';
constexpr std::uint32_t kPlayerRecord = 'PLY0';
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

		const uint32_t count = (uint32_t)registeredfemales.size();

		serializer->WriteRecordData(&count, sizeof(count));

		for (auto& [id, female] : registeredfemales)
		{
			serializer->WriteRecordData(reinterpret_cast<const char*>(&female), sizeof(female));
		}

		const uint32_t permanent_count = (uint32_t)permanentfemales.size();

		serializer->WriteRecordData(&permanent_count, sizeof(permanent_count));

		for(auto& female : permanentfemales)
		{
			serializer->WriteRecordData(reinterpret_cast<const char*>(&female), sizeof(female));
		}
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

			//serializer->WriteRecordData(&RegisteredPlugins::Plugins[Index], sizeof(std::string));
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
	}
}

inline void LoadCallback(SKSE::SerializationInterface* serializer)
{
	std::uint32_t type, version, length;
	while (serializer->GetNextRecordInfo(type, version, length)) {
		switch (type) {

			case kNPCsRecord: 
			{
				uint32_t count = 0;
				serializer->ReadRecordData(&count, sizeof(count));
				logs::critical("Reading NPC Records. RegisteredFemales Record Count is {}", count);

				int StrictTimer[7];
				int SimpleTimer[4];

				int Ranks[3];
				
				for (uint32_t i = 0; i < count; ++i)
				{
					RegisteredFemales female;
					serializer->ReadRecordData(reinterpret_cast<char*>(&female), sizeof(female));

					RE::FormID resolvedID = 0;
					if (!serializer->ResolveFormID(female.id, resolvedID)) 
					{
						logs::warn("Dropping unresolved FormID {:08X}", female.id);

						continue;
					}

					female.id = resolvedID;

					registeredfemales[female.id] = female;
				}

				uint32_t permanent_count = 0;
				serializer->ReadRecordData(&permanent_count, sizeof(permanent_count));
	
				for (uint32_t i = 0; i < permanent_count; ++i)
				{
					PermanentFemales female;
					serializer->ReadRecordData(reinterpret_cast<char*>(&female), sizeof(female));

					permanentfemales.emplace_back(female);
				}

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

				serializer->ReadRecordData(&Configuration::MotionFlashEnabled, sizeof(bool));
				serializer->ReadRecordData(&Configuration::DynamicModestyEnabled, sizeof(bool));

				serializer->ReadRecordData(&Configuration::AllowPlayerShameless, sizeof(bool));
				serializer->ReadRecordData(&Configuration::NPCShamelessByDefault, sizeof(bool));

				serializer->ReadRecordData(&Configuration::AllowPlayerCorruption, sizeof(bool));
				serializer->ReadRecordData(&Configuration::NPCCorruptionByDefault, sizeof(bool));

				serializer->ReadRecordData(&Configuration::StrictModestyRules, sizeof(bool));
				serializer->ReadRecordData(&Configuration::NPCStrictRulesByDefault, sizeof(bool));

				serializer->ReadRecordData(&Configuration::HardcoreModeEnabled, sizeof(bool));

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

					//serializer->ReadRecordData(&sValue, sizeof(sValue));
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