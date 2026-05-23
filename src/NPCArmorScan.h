#pragma once
namespace NPCFemaleScan {
	void NPCFemaleAnalyze(RE::Actor* akFemale);
}

namespace NPCMaleScan {
	void NPCMaleAnalyze(RE::Actor* akMale);
}

void ExternalNPCFemaleAnalyze(RE::StaticFunctionTag*, RE::Actor* akFemale);
void ExternalNPCMaleAnalyze(RE::StaticFunctionTag*, RE::Actor* akMale);