#pragma once

#include "APIs/SLSFR_API.h"
#include "APIs/ArousalAPI.h"

//Mod Detection Status
namespace InstalledMods {
	inline bool Sexlab;
	inline bool SLSFR;
	inline bool DFFMA;
	inline bool OSLAroused;
	inline bool SLOAroused;

	inline bool RosaRoundBottom;
}

std::vector<bool> GetInstalledMods(RE::StaticFunctionTag*);

namespace ModAPI {
	namespace SLSFR {
		inline static const SLSFR_API::SLSFRInterfaceV1* API = nullptr;

		void ConnectToSLSFRAPI();
		bool SuppressNakedComments();
	}

	namespace SLOArousedNG {
		// One holder for the exports you actually call. Each pointer's TYPE is taken
		// straight from the header via decltype(&SLA_Xxx) -- that is the whole point of
		// copying ArousalAPI.h: you never hand-retype a signature, and if ours ever
		// changed, your build would flag the mismatch instead of crashing at runtime.
		// (decltype only inspects the declaration; it creates no link dependency.)
		struct SLA {
			decltype(&SLA_GetVersion)         GetVersion = nullptr;
			decltype(&SLA_GetArousal)         GetArousal = nullptr;
			decltype(&SLA_AddDecayingEffect)  AddDecayingEffect = nullptr;
			decltype(&SLA_ClearDynamicEffect) ClearDynamicEffect = nullptr;
			decltype(&SLA_GetArousalInt) GetArousalInt = nullptr;
			// add only the exports you use

			bool available() const { return GetVersion != nullptr; }
		};

		// Call once, after SLA's DLL has loaded (see the tip below). If SLA isn't
		// installed every pointer stays null and available() returns false, so the
		// whole integration is opt-in with no hard dependency.
		inline SLA LoadSLA() {
			SLA sla;
			HMODULE h = GetModuleHandleA("SexlabArousedNG.dll");   // null => SLA absent
			if (!h) return sla;

			// Resolve each export BY NAME and store it as a callable pointer. The
			// reinterpret_cast target is the pointer's own type, so the string name
			// and the signature always agree. (C4191 is MSVC's expected warning for a
			// FARPROC->function-pointer cast; the push/disable/pop lets /W4 /WX pass.)
#pragma warning(push)
#pragma warning(disable : 4191)
			sla.GetVersion = reinterpret_cast<decltype(sla.GetVersion)>        (GetProcAddress(h, "SLA_GetVersion"));
			sla.GetArousal = reinterpret_cast<decltype(sla.GetArousal)>        (GetProcAddress(h, "SLA_GetArousal"));
			sla.AddDecayingEffect = reinterpret_cast<decltype(sla.AddDecayingEffect)> (GetProcAddress(h, "SLA_AddDecayingEffect"));
			sla.ClearDynamicEffect = reinterpret_cast<decltype(sla.ClearDynamicEffect)>(GetProcAddress(h, "SLA_ClearDynamicEffect"));
#pragma warning(pop)
			return sla;
		}

		inline SLA SLOArousedAPI;

		void ConnectToSLOArousedNG();
		uint32_t GetSLAVersion();
		int GetPlayerArousal();
	}
}