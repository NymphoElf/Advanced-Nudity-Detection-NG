#pragma once

#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>

// =====================================================================================
// SexLab sex-skill helpers
// -------------------------------------------------------------------------------------
// SexLab keeps its sex-skill data private inside SexLabUtil.dll's own SKSE co-save
// serialization. There is no C++ header/API to link against, and the co-save / the
// (deprecated) StorageUtil path are not reliable. The only supported way to read a
// skill is to call SexLab's Papyrus global native through the VM:
//
//      float sslActorStats._GetSkill(Actor akActor, int aiStat)
//
// IMPORTANT the read is ASYNCHRONOUS.
// We call this from contexts where the VM is already running (our own Papyrus-invoked
// natives) or from our native scan thread. DispatchStaticCall QUEUES the call and
// returns true immediately; the new call runs on a later VM update and its
// IStackCallbackFunctor fires only then -- never inline. So there is no synchronous
// result to read: the continuation passed to RequestSexuality() is the only place the
// value lands.
//
//   * RequestSexuality(actor, onResult) fires the call. When the queued call completes
//     on a later VM tick, `onResult` is invoked on the VM thread with the actor's
//     sexuality (0..100; lower = more homosexual, 100 = SexLab's default heterosexual).
// =====================================================================================

namespace Sexlab
{
    // SexLab sslActorStats stat indices. Sexuality lives at index 14 (constant).
    inline constexpr std::int32_t kStatSexuality = 14;

    namespace detail
    {
        // Receives the float from sslActorStats._GetSkill once the queued call runs,
		// converts it the same way SexLab's own GetSexuality does (0 -> 100), and hands
		// the result to the stored continuation. The smart pointer keeps this alive until
		// the VM invokes and releases it.
        class SexualityCallback : public RE::BSScript::IStackCallbackFunctor
        {
        public:
            explicit SexualityCallback(std::function<void(int)> a_onResult) : _onResult(std::move(a_onResult)) {}

            void operator()(RE::BSScript::Variable a_result) override
            {
                //Expected result is float 0..100, but we clamp to 0..100 just in case. SexLab's own code does not clamp, but it should be impossible for it to return out-of-range values.
                const float ratio = a_result.IsFloat() ? a_result.GetFloat() : 0.0f;
                const int sexuality = ratio > 0.0f ? static_cast<int>(ratio) : 100;
                if (_onResult)
                {
                    _onResult(sexuality);
                }
            }

            // We never want this transient callback persisted into a save.
            bool CanSave() const override { return false; }

            void SetObject(const RE::BSTSmartPointer<RE::BSScript::Object> &) override {}

        private:
            std::function<void(int)> _onResult;
        };
    }

    
	// True if SexLab.esm is in the current load order.
	[[nodiscard]] inline bool IsLoaded()
	{
		auto* dataHandler = RE::TESDataHandler::GetSingleton();
		return dataHandler && dataHandler->LookupModByName("SexLab.esm") != nullptr;
	}

    // Fire an asynchronous read of one actor's SexLab sexuality. When the queued call
	// completes on a later VM update, 'onResult' runs on the VM thread with the value
	// (0..100; lower = more homosexual, 100 = default heterosexual). See the header
	// banner for why this can never be read inline. Safe to call from inside a
	// Papyrus-invoked native or from another thread.
	inline void RequestSexuality(RE::Actor* actor, std::function<void(int)> onResult)
	{
		auto* vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (!vm || !actor) {
			return;
		}

		if (!IsLoaded()) {
			SKSE::log::warn("SexLab::RequestSexuality: SexLab.esm not loaded; skipping read");
			return;
		}

		auto* functor = new detail::SexualityCallback(std::move(onResult));
		RE::BSTSmartPointer<RE::BSScript::IStackCallbackFunctor> callback{ functor };

		// callback is passed as an lvalue (not moved) -- DispatchStaticCall takes it by
		// reference. Returns true when the call is accepted/queued, not when it runs.
		const bool dispatched = vm->DispatchStaticCall(
			"sslActorStats",
			"_GetSkill",
			RE::MakeFunctionArguments(std::move(actor), static_cast<std::int32_t>(kStatSexuality)),
			callback);

		if (!dispatched) {
			SKSE::log::warn("SexLab::RequestSexuality: DispatchStaticCall returned false for sslActorStats._GetSkill");
		}
	}
}