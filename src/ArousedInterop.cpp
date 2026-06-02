#include "ArousedInterop.h"

#include "Logger.h"

namespace
{
	using GetArousalExt_t = float (*)(RE::Actor*);
	GetArousalExt_t g_getArousalExt = nullptr;
	bool g_initialized = false;
}

void ArousedInterop::Initialize()
{
	if (g_initialized) {
		return;
	}
	g_initialized = true;

	// OSLAroused is loaded by SKSE as a normal plugin DLL, so it is already in
	// the process by kPostPostLoad. GetModuleHandle does not increment a ref
	// count, which is what we want for a non-owning lookup.
	HMODULE oslModule = GetModuleHandleA("OSLAroused.dll");
	if (!oslModule) {
		Log("<C++ ArousedInterop> [Initialize] OSLAroused.dll not loaded; arousal integration disabled", LogType::Core);
		return;
	}

	g_getArousalExt = reinterpret_cast<GetArousalExt_t>(GetProcAddress(oslModule, "GetArousalExt"));
	if (!g_getArousalExt) {
		Log("<C++ ArousedInterop> [Initialize] OSLAroused.dll found but GetArousalExt export missing; arousal integration disabled",
			LogType::Core, LoggingLevel::warning);
		return;
	}

	Log("<C++ ArousedInterop> [Initialize] OSLAroused arousal integration enabled", LogType::Core, LoggingLevel::critical);
}

bool ArousedInterop::IsAvailable()
{
	return g_getArousalExt != nullptr;
}

float ArousedInterop::GetArousal(RE::Actor* akActor)
{
	if (!g_getArousalExt || !akActor) {
		return 0.0f;
	}
	return g_getArousalExt(akActor);
}
