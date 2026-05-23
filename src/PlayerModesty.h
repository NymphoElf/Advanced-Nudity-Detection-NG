#pragma once

//inline bool ModestyUpgradeBlocked = false;

inline float LastTimeChecked = 0.0;

inline int StrictModestyTimer[7] = {0,0,0,0,0,0,0};
inline int TopModestyTimer[4] = {0,0,0,0};
inline int BottomModestyTimer[4] = {0,0,0,0};

//Functions

void ExternalStrictModesty(RE::StaticFunctionTag*, float CurrentGameTime);
void ExternalSimpleModesty(RE::StaticFunctionTag*, float CurrentGameTime);
void ExternalRankJump(RE::StaticFunctionTag*, int RankValue);
void ExternalTopRankJump(RE::StaticFunctionTag*, int RankValue);
void ExternalBottomRankJump(RE::StaticFunctionTag*, int RankValue);