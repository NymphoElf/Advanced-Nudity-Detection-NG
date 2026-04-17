#pragma once

#include <vector>

inline std::vector<std::string> ActorName;
inline std::vector<std::string> ActorBaseEditorID;
inline std::vector<int> ActorFormID;

inline std::vector<int> ModestyTimer0;
inline std::vector<int> ModestyTimer1;
inline std::vector<int> ModestyTimer2;
inline std::vector<int> ModestyTimer3;
inline std::vector<int> ModestyTimer4;
inline std::vector<int> ModestyTimer5;
inline std::vector<int> ModestyTimer6;

inline std::vector<int> DefaultRankStrict;
inline std::vector<int> CurrentRankStrict;
inline std::vector<int> MinimumRankStrict;

inline std::vector<int> TopModestyTimer0;
inline std::vector<int> TopModestyTimer1;
inline std::vector<int> TopModestyTimer2;
inline std::vector<int> TopModestyTimer3;

inline std::vector<int> DefaultRankTop;
inline std::vector<int> CurrentRankTop;
inline std::vector<int> MinimumRankTop;

inline std::vector<int> BottomModestyTimer0;
inline std::vector<int> BottomModestyTimer1;
inline std::vector<int> BottomModestyTimer2;
inline std::vector<int> BottomModestyTimer3;

inline std::vector<int> DefaultRankBottom;
inline std::vector<int> CurrentRankBottom;
inline std::vector<int> MinimumRankBottom;

inline std::vector<int> ShynessMode;

inline std::vector<bool> AllowPermanentShameless;
inline std::vector<bool> AllowCorruption;
inline std::vector<bool> StrictNPC;
inline std::vector<bool> UpgradeBlocked;

inline std::vector<float> LastUpdateTime;

inline int TotalNPCs;

//Functions

void RegisterFemale(RE::Actor* akFemale);