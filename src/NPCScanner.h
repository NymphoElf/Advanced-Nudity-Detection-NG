#pragma once

enum FactionIndex {
	Bottomless,
	Nude,
	ShowingAss,
	ShowingBra,
	ShowingChest,
	ShowingGenitals,
	ShowingUnderwear,
	Topless,
	Arousal,

	TotalFactions
};

inline RE::TESFaction* AllFactions[TotalFactions];

void ExternalProcessNPC(RE::StaticFunctionTag*, RE::Actor akActor);