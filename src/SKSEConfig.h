#pragma once

#include "APIs/SKSEMenuFramework.h"

namespace SKSEConfig {
	inline const std::string ModName = "Advanced Nudity Detection";
	inline const std::string ModAuthor = "NymphoElf";

	namespace RegisterTwoPartObject {
		void __stdcall Render();

		//inline ImGuiMCP::ImGuiTextFilter* filter;

		inline std::vector<RE::TESBoundObject*> WornObjects;
		inline std::array<RE::TESBoundObject*, 2> SelectedObjects = {};
		inline RE::BGSKeyword* SelectedKeyword = nullptr;
	}

	namespace TwoPartObjectList {
		void __stdcall Render();

		//inline ImGuiMCP::ImGuiTextFilter* filter;
	}
}

void RegisterSKSEConfigMenu();