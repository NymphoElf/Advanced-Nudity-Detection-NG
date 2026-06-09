#pragma once

#include <functional>
#include <vector>

namespace ActorScanner
{
    // Iterate every loaded reference within `radius` game units of `origin`,
	// handling both interior and exterior (grid) cells.
	void ForEachReferenceInRange(
		RE::TESObjectREFR* origin,
		float radius,
		std::function<RE::BSContainer::ForEachResult(RE::TESObjectREFR& ref)> callback);

	// Return all valid NPC actors within `radius` of `source` (excludes the
	// source itself, disabled actors, children, and non-NPC bases).
	std::vector<RE::Actor*> GetNearbyActors(RE::Actor* source, float radius);

	// Start/stop the native periodic scan. Idempotent. The DLL owns the timer (a
	// background Ticker) and runs each pass on the main thread, so this replaces
	// the old Papyrus RegisterForSingleUpdate loop entirely.
	void StartScanLoop();
	void StopScanLoop();

	// One scan pass: sweep nearby NPCs and ProcessActor each. MUST run on the main
	// thread (it reads inventories and writes faction ranks) — the Ticker marshals
	// it there via the SKSE task interface.
	void RunScanPass();
}