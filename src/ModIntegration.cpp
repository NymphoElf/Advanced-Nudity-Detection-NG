#include "ModIntegration.h"
#include "Core.h"
#include "Logger.h"
#include "APIs/ArousalAPI.h"

void CheckMods() {
	//RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	const RE::TESFile* RosaRoundBottom = GameDataHandler->LookupLoadedModByName("RosaFollower.esp");
	const RE::TESFile* Sexlab = GameDataHandler->LookupLoadedModByName("SexLab.esm");
	const RE::TESFile* SLSFR = GameDataHandler->LookupLoadedLightModByName("SLSF Reloaded.esp");
	const RE::TESFile* DFFMA = GameDataHandler->LookupLoadedLightModByName("Modesty_Keyword.esp");
	const RE::TESFile* OSLAroused = GameDataHandler->LookupLoadedLightModByName("OSLAroused.esp");

	if (RosaRoundBottom) {
		InstalledMods::RosaRoundBottom = true;
		Rosa = RE::TESForm::LookupByEditorID<RE::Actor>("Rosa");
		Log("<C++ ModIntegration> [CheckMods] RosaFollower.esp FOUND", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}
	else {
		InstalledMods::RosaRoundBottom = false;
		Rosa = nullptr;
		Log("<C++ ModIntegration> [CheckMods] RosaFollower.esp MISSING", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}

	if (Sexlab) {
		InstalledMods::Sexlab = true;
		Log("<C++ ModIntegration> [CheckMods] SexLab.esm FOUND", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}
	else {
		InstalledMods::Sexlab = false;
		Log("<C++ ModIntegration> [CheckMods] SexLab.esm MISSING", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}

	if (DFFMA) {
		InstalledMods::DFFMA = true;
		Log("<C++ ModIntegration> [CheckMods] Modesty_Keyword.esp (aka DFFMA) FOUND", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}
	else {
		InstalledMods::DFFMA = false;
		Log("<C++ ModIntegration> [CheckMods] Modesty_Keyword.esp (aka DFFMA) MISSING", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}

	if (OSLAroused) {
		InstalledMods::OSLAroused = true;
		Log("<C++ ModIntegration> [CheckMods] OSLAroused.esp FOUND", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}
	else {
		InstalledMods::OSLAroused = false;
		Log("<C++ ModIntegration> [CheckMods] OSLAroused.esp MISSING", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}

	if (SLSFR) {
		InstalledMods::SLSFR = true;
		Log("<C++ ModIntegration> [CheckMods] SLSF Reloaded.esp FOUND", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}
	else {
		InstalledMods::SLSFR = false;
		Log("<C++ ModIntegration> [CheckMods] SLSF Reloaded.esp MISSING", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}

	if (ModAPI::SLOArousedNG::GetSLAVersion() >= 30200000) {
		InstalledMods::SLOAroused = true;
		Log("<C++ ModIntegration> [CheckMods] SLO Aroused NG FOUND", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}
	else {
		InstalledMods::SLOAroused = false;
		Log("<C++ ModIntegration> [CheckMods] SLO Aroused NG MISSING", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}

	if (InstalledMods::OSLAroused && InstalledMods::SLOAroused) {
		Log("<C++ ModIntegration> [CheckMods] CRITIAL ERROR!!! OSL Aroused and SLO Aroused are both installed! These mods conflict!!!", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}

	const RE::TESFile* UBE = GameDataHandler->LookupLoadedModByName("UBE_AllRace.esp");
	InstalledMods::UBE = UBE;
	if (UBE) {
		Log("<C++ ModIntegration> [CheckMods] UBE_AllRace.esp FOUND", Logger::LogType::Core, Logger::LoggingLevel::critical);
		
		UBE::UBERaces[UBE::Altmer] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A1A2));
		UBE::UBERaces[UBE::AltmerVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A1A3));
		UBE::UBERaces[UBE::Bosmer] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A1AC));
		UBE::UBERaces[UBE::BosmerVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A1AD));
		UBE::UBERaces[UBE::Breton] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5734));
		UBE::UBERaces[UBE::BretonVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5735));
		UBE::UBERaces[UBE::Dunmer] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A198));
		UBE::UBERaces[UBE::DunmerVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A199));
		UBE::UBERaces[UBE::Imperial] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A179));
		UBE::UBERaces[UBE::ImperialVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A17A));
		UBE::UBERaces[UBE::Nord] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A184));
		UBE::UBERaces[UBE::NordVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A185));
		UBE::UBERaces[UBE::Orsimer] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A1B0));
		UBE::UBERaces[UBE::OrsimerVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A1B1));
		UBE::UBERaces[UBE::Redguard] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A18E));
		UBE::UBERaces[UBE::RedguardVampire] = RE::TESForm::LookupByID<RE::TESRace>(UBE->GetFormID(0x5A18F));
	}
	else {
		Log("<C++ ModIntegration> [CheckMods] UBE_AllRace.esp MISSING", Logger::LogType::Core, Logger::LoggingLevel::critical);
	}
}

std::vector<bool> GetInstalledMods(RE::StaticFunctionTag*) {
	std::vector<bool> ModVector = {
		InstalledMods::RosaRoundBottom, //0
		InstalledMods::Sexlab, //1
		InstalledMods::DFFMA, //2
		InstalledMods::OSLAroused, //3
		InstalledMods::SLSFR, //4
		InstalledMods::SLOAroused, //5
		InstalledMods::UBE //6
	};

	return ModVector;
}

namespace ModAPI {
	namespace SLOArousedNG {
		void ConnectToSLOArousedNG() {
			SLOArousedAPI = LoadSLA();
		}

		uint32_t GetSLAVersion() {
			return SLOArousedAPI.available() ? SLOArousedAPI.GetVersion() : 0;
		}

		int GetActorArousal(RE::Actor* akActor) {
			if (!SLOArousedAPI.GetArousalInt) {
				return 0;
			}
			return (int)SLOArousedAPI.GetArousalInt(akActor);
		}

		int GetPlayerArousal() {
			if (!SLOArousedAPI.GetArousalInt) {
				return 0;
			}
			return (int)SLOArousedAPI.GetArousalInt(Player);
		}
	}
	
	namespace SLSFR {
		void ConnectToSLSFRAPI() {
			API = static_cast<const SLSFR_API::SLSFRInterfaceV1*>(SLSFR_API::RequestAPI(SLSFR_API::InterfaceVersion::V1));

			if (!API) {
				Log("<C++ ModIntegration> [ConnectToSLSFRAPI] SLSFR API Connection Failed!", Logger::LogType::Core, Logger::LoggingLevel::critical);
				if (InstalledMods::SLSFR) {
					Log("<C++ ModIntegration> [ConnectToSLSFRAPI] This version of SLSFR does not have a working SKSE API!", Logger::LogType::Core, Logger::LoggingLevel::critical);
				}
				else {
					Log("<C++ ModIntegration> [ConnectToSLSFRAPI] SLSFR is not installed.", Logger::LogType::Core, Logger::LoggingLevel::critical);
				}
				return;
			}

			const auto ModVersion = API->APIGetPluginVersion();
			Log("<C++ ModIntegration> [ConnectToSLSFRAPI] SLSFR API Connection Succeeded! Obtained API version: " + std::to_string(ModVersion[0]) + "." + std::to_string(ModVersion[1]) + "." + std::to_string(ModVersion[2]), Logger::LogType::Core, Logger::LoggingLevel::critical);
		}

		bool DisableNakedCommentsWhilePublicWhore() {
			return API ? API->APIGetConfigBool(20) : false;
		}

		bool GetIsPublicWhore() {
			return API ? API->APIGetIsPublicWhore() : false;
		}

		bool SuppressNakedComments() {
			return GetIsPublicWhore() && DisableNakedCommentsWhilePublicWhore();
		}
	}
}