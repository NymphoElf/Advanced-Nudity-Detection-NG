#pragma once

#include "SKSE APIs/SLSFR_API.h"

//Mod Detection Status
namespace InstalledMods {
	inline bool Sexlab;
	inline bool SLSFR;
	inline bool DFFMA;
	inline bool OSLAroused;

	inline bool RosaRoundBottom;
}

std::vector<bool> GetInstalledMods(RE::StaticFunctionTag*);

namespace ModAPI {
	namespace SLSFR {
		inline static const SLSFR_API::SLSFRInterfaceV1* API = nullptr;

		void ConnectToSLSFRAPI();
		bool SuppressNakedComments();
	}
}