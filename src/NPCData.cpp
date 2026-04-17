#include "NPCData.h"

bool FemaleExists(RE::Actor* akFemale) {
	int FemaleForm = akFemale->GetFormID();
	std::string FemaleBaseEditorID = akFemale->GetActorBase()->GetFormEditorID();
	
	int index = 0;
	while (index < std::size(ActorFormID)) {
		if (FemaleForm == ActorFormID.at(index)) {
			return true;
		}
		index++;
	}
	return false;
}

void RegisterFemale(RE::Actor* akFemale) {
	int FemaleForm = akFemale->GetFormID();
	int FemaleBaseForm = akFemale->GetActorBase()->GetFormID();
	std::string FemaleEditorID = akFemale->GetFormEditorID();
	std::string FemaleBaseEditorID = akFemale->GetActorBase()->GetFormEditorID();
	std::string FemaleName = akFemale->GetName();
	std::string FemaleBaseName = akFemale->GetActorBase()->GetName();

	logs::critical("Female Form ID: {}", FemaleForm);
	logs::critical("Female Base Form ID: {}", FemaleBaseForm);
	logs::critical("Female Editor ID: {}", FemaleEditorID);
	logs::critical("Female Base Editor ID: {}", FemaleBaseEditorID);
	logs::critical("Female Name: {}", FemaleName);
	logs::critical("Female base Name: {}", FemaleBaseName);

	//ActorFormID.emplace_back(FemaleForm);
}