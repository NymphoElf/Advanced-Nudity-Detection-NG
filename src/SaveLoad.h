#pragma once

/*
struct PermanentNPCData {
	std::vector<RE::FormID> FemaleLocalID;
	//std::vector<std::string_view> FemalePlugin;
	std::vector<std::array<char, 256>> FemalePlugin;
	std::vector<uint8_t> IsInLightPlugin;
	//std::vector<std::string> FemaleName;
	std::vector<std::array<char, 256>> FemaleName;

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
			output.write(reinterpret_cast<const char*>(&FemaleLocalID[Index]), sizeof(RE::FormID));
			output.write(reinterpret_cast<const char*>(FemalePlugin[Index].data()), sizeof(char[256]));
			output.write(reinterpret_cast<const char*>(&IsInLightPlugin[Index]), sizeof(uint8_t));
			output.write(reinterpret_cast<const char*>(FemaleName[Index].data()), sizeof(char[256]));

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
		//std::array<char, 256> char256;
		
		uint8_t bValue = 0;
		int iValue = 0;

		while (Index < TotalFemales) {
			input.read(reinterpret_cast<char*>(&uiValue), sizeof(RE::FormID));
			FemaleLocalID.emplace_back(uiValue);

			input.read(FemalePlugin[Index].data(), sizeof(char[256]));
			//FemalePlugin.emplace_back(char256);

			input.read(reinterpret_cast<char*>(&bValue), sizeof(uint8_t));
			IsInLightPlugin.emplace_back(bValue);

			input.read(FemaleName[Index].data(), sizeof(char[256]));
			//FemaleName.emplace_back(sValue);

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
*/

void SavePermanentNPCs();
void LoadPermanentNPCs();

void RegisterCoSaveSerializer();