#include "ModIntegration.h"
#include "Core.h"
#include "Logger.h"

void CheckMods() {
	RE::TESDataHandler* DataHandler = RE::TESDataHandler::GetSingleton();

	const RE::TESFile* RosaRoundBottom = DataHandler->LookupLoadedModByName("RosaFollower.esp");
	const RE::TESFile* Sexlab = DataHandler->LookupLoadedModByName("SexLab.esm");
	const RE::TESFile* SLSFR = DataHandler->LookupLoadedLightModByName("SLSF Reloaded.esp");
	const RE::TESFile* DFFMA = DataHandler->LookupLoadedLightModByName("Modesty_Keyword.esp");
	const RE::TESFile* OSLAroused = DataHandler->LookupLoadedLightModByName("OSLAroused.esp");

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
}

std::vector<bool> GetInstalledMods(RE::StaticFunctionTag*) {
	std::vector<bool> ModVector = {
		InstalledMods::RosaRoundBottom, //0
		InstalledMods::Sexlab, //1
		InstalledMods::DFFMA, //2
		InstalledMods::OSLAroused, //3
		InstalledMods::SLSFR //4
	};

	return ModVector;
}

namespace ModAPI {
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