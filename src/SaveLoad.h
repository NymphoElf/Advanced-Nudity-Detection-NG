#pragma once
/*
struct PermanentFemaleData {
	RE::FormID FemaleLocalID;
	std::string_view FemalePlugin;
	bool IsInLightPlugin;
	std::string FemaleName;

	int DefaultRankStrict;
	int MinimumRankStrict;

	int DefaultRankTop;
	int MinimumRankTop;

	int DefaultRankBottom;
	int MinimumRankBottom;

	int ShynessMode;
	int SexualityScore;

	bool AllowShameless;
	bool AllowCorruption;
	bool StrictRules;
};
*/

struct PermanentNPCData {
	std::vector<RE::FormID> FemaleLocalID;
	std::vector<std::string_view> FemalePlugin;
	std::vector<uint8_t> IsInLightPlugin;
	std::vector<std::string> FemaleName;

	std::vector<int> DefaultRankStrict;
	std::vector<int> MinimumRankStrict;

	std::vector<int> DefaultRankTop;
	std::vector<int> MinimumRankTop;

	std::vector<int> DefaultRankBottom;
	std::vector<int> MinimumRankBottom;

	std::vector<int> ShynessMode;
	std::vector<int> SexualityScore;

	std::vector<uint8_t> AllowShameless;
	std::vector<uint8_t> AllowCorruption;
	std::vector<uint8_t> StrictRules;

	int TotalFemales = 0;

	void Serialize(std::ostream& output) {
		output.write(reinterpret_cast<const char*>(&TotalFemales), sizeof(int));
		
		int Index = 0;
		
		while (Index < TotalFemales) {
			output.write(reinterpret_cast<const char*>(&FemaleLocalID[Index]), sizeof(uint32_t));
			output.write(reinterpret_cast<const char*>(&FemalePlugin[Index]), sizeof(std::string_view));
			output.write(reinterpret_cast<const char*>(&IsInLightPlugin[Index]), sizeof(uint8_t));
			output.write(reinterpret_cast<const char*>(&FemaleName[Index]), sizeof(std::string));

			output.write(reinterpret_cast<const char*>(&DefaultRankStrict[Index]), sizeof(int));
			output.write(reinterpret_cast<const char*>(&MinimumRankStrict[Index]), sizeof(int));

			output.write(reinterpret_cast<const char*>(&DefaultRankTop[Index]), sizeof(int));
			output.write(reinterpret_cast<const char*>(&MinimumRankTop[Index]), sizeof(int));

			output.write(reinterpret_cast<const char*>(&DefaultRankBottom[Index]), sizeof(int));
			output.write(reinterpret_cast<const char*>(&MinimumRankBottom[Index]), sizeof(int));

			output.write(reinterpret_cast<const char*>(&ShynessMode[Index]), sizeof(int));
			output.write(reinterpret_cast<const char*>(&SexualityScore[Index]), sizeof(int));

			output.write(reinterpret_cast<const char*>(&AllowShameless[Index]), sizeof(uint8_t));
			output.write(reinterpret_cast<const char*>(&AllowCorruption[Index]), sizeof(uint8_t));
			output.write(reinterpret_cast<const char*>(&StrictRules[Index]), sizeof(uint8_t));

			Index++;
		}
	}

	void Deserialize(std::istream& input) {
		input.read(reinterpret_cast<char*>(&TotalFemales), sizeof(TotalFemales));
		
		int Index = 0;

		uint32_t uiValue = 0;
		std::string_view svValue = "";
		std::string sValue = "";
		
		uint8_t bValue = 0;
		int iValue = 0;

		while (Index < TotalFemales) {
			input.read(reinterpret_cast<char*>(&uiValue), sizeof(uint32_t));
			FemaleLocalID.emplace_back(uiValue);

			input.read(reinterpret_cast<char*>(&svValue), sizeof(std::string_view));
			FemalePlugin.emplace_back(svValue);

			input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
			IsInLightPlugin.emplace_back(bValue);

			input.read(reinterpret_cast<char*>(&sValue), sizeof(std::string));
			FemaleName.emplace_back(sValue);

			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			DefaultRankStrict.emplace_back(iValue);

			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			MinimumRankStrict.emplace_back(iValue);

			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			DefaultRankTop.emplace_back(iValue);
			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			MinimumRankTop.emplace_back(iValue);

			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			DefaultRankBottom.emplace_back(iValue);
			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			MinimumRankBottom.emplace_back(iValue);

			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			ShynessMode.emplace_back(iValue);
			input.read(reinterpret_cast<char*>(&iValue), sizeof(int));
			SexualityScore.emplace_back(iValue);

			input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
			AllowShameless.emplace_back(bValue);
			input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
			AllowCorruption.emplace_back(bValue);
			input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
			StrictRules.emplace_back(bValue);

			Index++;
		}
	}
};

void SavePermanentNPCs();
void LoadPermanentNPCs();

void RegisterCoSaveSerializer();

//void SaveData(std::string FileName);
//void LoadData(std::string FileName);
//void DeleteData(std::string FileName);