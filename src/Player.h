#pragma once


inline bool IsWearingChestCurtain;
inline bool IsWearingPelvicCurtain;
inline bool IsWearingAssCurtain;

//void InitializePlayerFactions();

void CheckWearingCurtains(RE::StaticFunctionTag*);
void ClosedMenuEvent(RE::StaticFunctionTag*, std::string MenuName);