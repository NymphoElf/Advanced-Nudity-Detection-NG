#include "ActorScanner.h"

#include "Config.h"
#include "Core.h"
#include "Logger.h"

namespace
{
	// Papyrus arrays cannot exceed 128 elements.
	constexpr std::size_t kPapyrusArrayMax = 128;
}

// Ported verbatim from OSLAroused (Utilities::World::ForEachReferenceInRange).
void ActorScanner::ForEachReferenceInRange(
	RE::TESObjectREFR* origin,
	float radius,
	std::function<RE::BSContainer::ForEachResult(RE::TESObjectREFR& ref)> callback)
{
	if (origin && radius > 0.0f) {
		const auto originPos = origin->GetPosition();
		auto* tesSingleton = RE::TES::GetSingleton();
		auto* interiorCell = tesSingleton->interiorCell;
		if (interiorCell) {
			interiorCell->ForEachReferenceInRange(originPos, radius, [&](RE::TESObjectREFR* a_ref) {
				return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
			});
		} else {
			if (const auto gridLength = tesSingleton->gridCells ? tesSingleton->gridCells->length : 0; gridLength > 0) {
				const float yPlus = originPos.y + radius;
				const float yMinus = originPos.y - radius;
				const float xPlus = originPos.x + radius;
				const float xMinus = originPos.x - radius;

				std::uint32_t x = 0;
				do {
					std::uint32_t y = 0;
					do {
						if (const auto cell = tesSingleton->gridCells->GetCell(x, y); cell && cell->IsAttached()) {
							if (const auto cellCoords = cell->GetCoordinates(); cellCoords) {
								const RE::NiPoint2 worldPos{ cellCoords->worldX, cellCoords->worldY };
								if (worldPos.x < xPlus && (worldPos.x + 4096.0f) > xMinus && worldPos.y < yPlus &&
									(worldPos.y + 4096.0f) > yMinus) {
									cell->ForEachReferenceInRange(originPos, radius, [&](RE::TESObjectREFR* a_ref) {
										return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
									});
								}
							}
						}
						++y;
					} while (y < gridLength);
					++x;
				} while (x < gridLength);
			}
		}
	} else {
		RE::TES::GetSingleton()->ForEachReference([&](RE::TESObjectREFR* a_ref) {
			return a_ref ? callback(*a_ref) : RE::BSContainer::ForEachResult::kContinue;
		});
	}
}

std::vector<RE::Actor*> ActorScanner::GetNearbyActors(RE::Actor* source, float radius)
{
	std::vector<RE::Actor*> nearbyActors;

	if (!source || !source->parentCell) {
		Log("<C++ ActorScanner> [GetNearbyActors] source cannot be null", LogType::Core, LoggingLevel::warning);
		return nearbyActors;
	}

	ForEachReferenceInRange(source, radius, [&](RE::TESObjectREFR& ref) {
		auto refBase = ref.GetBaseObject();
		auto actor = ref.As<RE::Actor>();
		if (actor && actor != source && !actor->IsDisabled() && !actor->IsChild() &&
			(ref.Is(RE::FormType::NPC) || (refBase && refBase->Is(RE::FormType::NPC)))) {
			nearbyActors.push_back(actor);
		}
		return RE::BSContainer::ForEachResult::kContinue;
	});

	return nearbyActors;
}

std::vector<RE::Actor*> ActorScanner::GetNearbyActorsPapyrus(RE::StaticFunctionTag*, RE::Actor* akCenter, float radius)
{
	if (!Configuration::NearbyScanEnabled) {
		return {};
	}

	RE::Actor* center = akCenter ? akCenter : Player;
	if (radius <= 0.0f) {
		radius = Configuration::ScanDistance;
	}

	auto actors = GetNearbyActors(center, radius);

	if (actors.size() > kPapyrusArrayMax) {
		Log("<C++ ActorScanner> [GetNearbyActors] Found " + std::to_string(actors.size()) +
				" actors; truncating to Papyrus limit of " + std::to_string(kPapyrusArrayMax),
			LogType::Core, LoggingLevel::warning);
		actors.resize(kPapyrusArrayMax);
	}

	Log("<C++ ActorScanner> [GetNearbyActors] Returning " + std::to_string(actors.size()) + " nearby actor(s)", LogType::Core);
	return actors;
}
