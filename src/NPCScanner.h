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

	StrictModesty,
	TopModesty,
	BottomModesty,

	TotalFactions
};

inline RE::TESFaction* AllFactions[TotalFactions];

void ProcessActors(std::vector<RE::Actor*> ScannedActors);
std::vector<RE::Actor*> GetActorsInRadiusOfPlayer(float radius);