#pragma once

#include "APIs/SKSEMenuFramework.h"
#include "Core.h"
#include "Logger.h"

namespace SKSEConfig {
	inline const std::string ModName = "Advanced Nudity Detection";
	inline const std::string ModAuthor = "NymphoElf";

	namespace RegisterTwoPartObjectMenu {
		void __stdcall Render();

		enum ReturnCodes {
			Success,
			AlreadyExists,
			TooManyObjects,
			InvalidSelection,

			Waiting = 255
		};

		inline std::vector<RE::TESBoundObject*> WornObjects;
		inline std::array<RE::TESBoundObject*, 2> SelectedObjects = {};
		inline RE::BGSKeyword* SelectedKeyword = nullptr;
		inline UINT8 RegisterResult = Waiting;

		inline void __stdcall OnMenuEvent(SKSEMenuFramework::Model::EventType eventType) {
			switch (eventType) {
				case SKSEMenuFramework::Model::kOpenMenu:
					//Log("<SKSE Config HEADER> Register Menu Opened");
					WornObjects = GetPlayerWornObjectList();
					break;
				case SKSEMenuFramework::Model::kCloseMenu:
					//Log("<SKSE Config HEADER> Register Menu Closed");
					SelectedObjects = { nullptr, nullptr };
					SelectedKeyword = nullptr;
					RegisterResult = Waiting;
					break;
				default:
					break;
			}
		}
	}

	namespace TwoPartObjectListMenu {
		void __stdcall Render();

		enum UnregisterResult {
			Success,
			DoesNotExist
		};
	}
}

void RegisterSKSEConfigMenu();