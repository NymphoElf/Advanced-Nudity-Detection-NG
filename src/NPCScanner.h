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

void ProcessActor(RE::Actor* akActor, int SexualityScore);
//void ExternalProcessNPC(RE::StaticFunctionTag*, RE::Actor* akActor, float CurrentGameTime, int SexualityScore);