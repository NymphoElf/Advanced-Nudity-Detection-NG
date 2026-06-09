#pragma once

#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>

// =====================================================================================
// OSLAroused arousal read
// -------------------------------------------------------------------------------------
// OSLAroused exposes C-style DLL exports for consumption by other SKSE plugins (see its
// ArousalManager.h: GetArousalExt / SetArousalExt / ModifyArousalExt). We resolve
// GetArousalExt once via GetProcAddress and cache the pointer.
//
// GetArousalExt is a near-pure read: it calls GetArousal(actor, bUpdateState=false), so
// it returns the actor's current arousal (0..100) WITHOUT advancing the arousal
// simulation or firing the arousal-changed event -- ideal for just caching the value.
// The one exception is the very first query for an actor (lastCheckTime == 0), where
// OSLAroused initialises state and writes faction ranks. Because of that init path it
// MUST be called on the main thread, same as any other faction-rank mutation.
//
// This mirrors the old Papyrus path (OSLAroused_ModInterface.GetArousal) that
// AND_Core.UpdateArousalValue used.
// =====================================================================================

namespace Aroused
{
    // True if OSLAroused.esp is in the current load order.
    [[nodiscard]] inline bool IsLoaded()
    {
        auto* dataHandler = RE::TESDataHandler::GetSingleton();
        return dataHandler && dataHandler->LookupModByName("OSLAroused.esp") != nullptr;
    }

    // Read an actor's OSLAroused arousal (0..100). Returns -1.0f if the export cannot be
    // resolved (OSLAroused absent or an older build without the Ext exports). Resolved
    // and cached on first call; the DLL is loaded by kPostLoad, well before any scan.
    [[nodiscard]] inline float GetArousal(RE::Actor* actor)
    {
        using GetArousalFn = float (*)(RE::Actor*);
        static GetArousalFn s_getArousal = []() -> GetArousalFn {
            if (auto* handle = GetModuleHandleA("OSLAroused.dll")) {
                return reinterpret_cast<GetArousalFn>(GetProcAddress(handle, "GetArousalExt"));
            }
            return nullptr;
        }();

        if (!s_getArousal || !actor) {
            return -1.0f;
        }
        return s_getArousal(actor);
    }
}
