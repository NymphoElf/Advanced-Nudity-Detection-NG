#pragma once

namespace SLSFR_API {
	constexpr const char* PluginName = "SLSFReloaded";

	inline std::array<uint8_t, 3> PluginVerison = { 4, 0, 0 }; //Major | Minor | Patch

	enum class InterfaceVersion : std::uint8_t { V1 };

	class SLSFRInterfaceV1 {
	public:
		[[nodiscard]] virtual std::array<uint8_t, 3> APIGetPluginVersion() const noexcept = 0;
		[[nodiscard]] virtual float APIGetConfigFloat(int FloatIndex) const noexcept = 0;
		[[nodiscard]] virtual bool APIGetConfigBool(int BoolIndex) const noexcept = 0;
		[[nodiscard]] virtual int APIGetConfigInt(int IntIndex) const noexcept = 0;

		[[nodiscard]] virtual std::array<float, 32> APIGetCategoryFameGainMultipliers() const noexcept = 0;
		[[nodiscard]] virtual std::array<float, 32> APIGetCategoryFameDecayMultipliers() const noexcept = 0;
		[[nodiscard]] virtual std::array<float, 32> APIGetCategoryFameSpreadMultipliers() const noexcept = 0;

		[[nodiscard]] virtual std::array<bool, 32> APIGetForbiddenFame(bool Lover) const noexcept = 0;

		[[nodiscard]] virtual bool APIGetIsPublicWhore() const noexcept = 0;

		[[nodiscard]] virtual void APIFameGainRoll() const noexcept = 0;
		
		[[nodiscard]] virtual void APIManualFameGainAll(int MinimumIncrease, int MaximumIncrease) const noexcept = 0;
		[[nodiscard]] virtual void APIManualFameGainAllInLocation(std::string LocationString, int MinimumIncrease, int MaximumIncrease) const noexcept = 0;
		[[nodiscard]] virtual void APIManualFameGain(std::string FameTypeString, std::string LocationString, int MinimumIncrease, int MaximumIncrease) const noexcept = 0;
		
		[[nodiscard]] virtual void APIFameGain(std::string FameTypeString, std::string LocationString, int MinimumFame, int MaximumFame) const noexcept = 0;
		
		[[nodiscard]] virtual void APIFameDecay() const noexcept = 0;
		[[nodiscard]] virtual void APIManualFameDecay(std::string LocationString, std::string FameTypeString, int MinimumDecay, int MaximumDecay) const noexcept = 0;
		[[nodiscard]] virtual void APIManualFameDecayAllInLocation(std::string LocationString, int MinimumDecay, int MaximumDecay) const noexcept = 0;
		[[nodiscard]] virtual void APIManualFameDecayAll(int MinimumDecay, int MaximumDecay) const noexcept = 0;

		[[nodiscard]] virtual void APIFameSpread() const noexcept = 0;

		[[nodiscard]] virtual void APILocationRegister(RE::BGSLocation* Location) const noexcept = 0;
		[[nodiscard]] virtual void APILocationUnregister(RE::BGSLocation* Location) const noexcept = 0;

		[[nodiscard]] virtual void APIModRegister(std::string ModName) const noexcept = 0;
		[[nodiscard]] virtual void APIModUnregister(std::string ModName) const noexcept = 0;

		[[nodiscard]] virtual void APISetPluginFlag(std::string ModName, std::string FameString, bool Enabled) const noexcept = 0;
		[[nodiscard]] virtual void APIEnableFameType(std::string ModName, std::string FameString, bool Enabled) const noexcept = 0;

		[[nodiscard]] virtual std::string APIRequestLocation(bool Strict) const noexcept = 0;

		[[nodiscard]] virtual float APIRequestRecognitionTime(std::string LocationString) const noexcept = 0;

		[[nodiscard]] virtual int APIRequestFame(std::string LocationString, std::string FameString) const noexcept = 0;

		[[nodiscard]] virtual bool APIRequestCumVisibility(std::string CumLocation) const noexcept = 0;

		[[nodiscard]] virtual std::vector<bool> APIRequestFameFlagState(std::string FameFlag) const noexcept = 0;
		[[nodiscard]] virtual std::vector<bool> APIRequestModFameFlagState(std::string ModName, std::string FameFlag) const noexcept = 0;

		[[nodiscard]] virtual bool APIRequestModRegisterState(std::string ModName) const noexcept = 0;

		//[[nodiscard]] virtual bool APIGetDisableNakedCommentsWhilePublicWhore() const noexcept = 0;
	};

	[[nodiscard]] inline void* RequestAPI(InterfaceVersion thisInterface = InterfaceVersion::V1) {
		auto ModuleHandle = GetModuleHandle("sexlab-sexual-fame-reloaded.dll");
		if (!ModuleHandle) {
			return nullptr;
		}
		using RequestFn = void* (*)(InterfaceVersion);
		auto fn = reinterpret_cast<RequestFn>(GetProcAddress(ModuleHandle, "RequestSLSFRAPI"));
		return fn ? fn(thisInterface) : nullptr;
	}
}