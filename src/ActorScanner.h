#pragma once

#include <functional>
#include <vector>

// Proximity-based actor detection, ported from OSLAroused's actor-detection
// logic (RuntimeEvents.cpp / Utils.cpp). The find-nearby-actors step is done in
// C++ (cheap), then handed to Papyrus, which loops and calls ProcessNPC. This
// replaces the old cloak-spell scan (a scripted MagicEffect applied per NPC) and
// its per-NPC Papyrus overhead.
namespace ActorScanner
{
	// Iterate every loaded reference within `radius` game units of `origin`,
	// handling both interior and exterior (grid) cells. Ported verbatim from
	// OSLAroused's Utilities::World::ForEachReferenceInRange.
	void ForEachReferenceInRange(
		RE::TESObjectREFR* origin,
		float radius,
		std::function<RE::BSContainer::ForEachResult(RE::TESObjectREFR& ref)> callback);

	// Return all valid NPC actors within `radius` of `source` (excludes the
	// source itself, disabled actors, children, and non-NPC bases).
	std::vector<RE::Actor*> GetNearbyActors(RE::Actor* source, float radius);

	// Papyrus native: Actor[] GetNearbyActors(Actor akCenter, Float radius).
	// Returns NPCs near akCenter for the Papyrus scan loop to process. Capped at
	// the Papyrus array limit (128); truncation is logged, never silent.
	std::vector<RE::Actor*> GetNearbyActorsPapyrus(RE::StaticFunctionTag*, RE::Actor* akCenter, float radius);
}
