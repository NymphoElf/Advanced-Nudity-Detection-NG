#pragma once

// Inter-plugin bridge to OSLAroused. OSLAroused exports a C function
// (GetArousalExt) for exactly this purpose; we resolve it at runtime so AND-NG
// has no hard dependency on the DLL and degrades gracefully when it is absent.
namespace ArousedInterop
{
	// Resolve the OSLAroused export. Call once after all SKSE plugins have
	// loaded (kPostPostLoad). Safe to call if OSLAroused is not installed.
	void Initialize();

	// True if OSLAroused was found and its arousal export resolved.
	bool IsAvailable();

	// Current arousal [0..100] for the actor, or 0 if OSLAroused is unavailable
	// (matches the old Papyrus behaviour of rank 0 without OSLAroused).
	float GetArousal(RE::Actor* akActor);
}
