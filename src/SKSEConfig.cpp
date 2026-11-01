#include "SKSEConfig.h"

using namespace SKSEConfig;

void RegisterSKSEConfigMenu() {
    if (!SKSEMenuFramework::IsInstalled()) {
        return;
    }
    SKSEMenuFramework::SetSection(ModName);

    SKSEMenuFramework::AddEvent(RegisterTwoPartObjectMenu::OnMenuEvent, 0.0f);

    SKSEMenuFramework::AddSectionItem("TwoPartObjects/Register Two Part Object", RegisterTwoPartObjectMenu::Render);
    SKSEMenuFramework::AddSectionItem("TwoPartObjects/Two Part Object List", TwoPartObjectListMenu::Render);
}

void __stdcall RegisterTwoPartObjectMenu::Render() {
    static ImGuiMCP::ImGuiTableFlags flags = ImGuiMCP::ImGuiTableFlags_Resizable | ImGuiMCP::ImGuiTableFlags_Reorderable | ImGuiMCP::ImGuiTableFlags_Hideable | ImGuiMCP::ImGuiTableFlags_RowBg | ImGuiMCP::ImGuiTableFlags_BordersOuter |
        ImGuiMCP::ImGuiTableFlags_BordersV | ImGuiMCP::ImGuiTableFlags_NoBordersInBody | ImGuiMCP::ImGuiTableFlags_ScrollY;

    enum Items {
        ItemA,
        ItemB
    };

    if (ImGuiMCP::BeginMenu("Select Item A")) {
        for (UINT32 Index = 0; Index < WornObjects.size(); ++Index) {
            if (ImGuiMCP::MenuItem(WornObjects[Index]->GetName())) {
                if (WornObjects[Index] == SelectedObjects[ItemB]) {
                    SelectedObjects[ItemB] = SelectedObjects[ItemA];
                }
                SelectedObjects[ItemA] = WornObjects[Index];
                
                Log("<SKSE Config> [RegisterTwoPartObject] Selected Item A is: " + GetFormLogData(SelectedObjects[ItemA]), Logger::Core, Logger::info);
            }
        }

        ImGuiMCP::EndMenu();
    }

    if (ImGuiMCP::BeginMenu("Select Item B")) {
        for (UINT32 Index = 0; Index < WornObjects.size(); ++Index) {
            if (ImGuiMCP::MenuItem(WornObjects[Index]->GetName())) {
                if (WornObjects[Index] == SelectedObjects[ItemA]) {
                    SelectedObjects[ItemA] = SelectedObjects[ItemB];
                }
                SelectedObjects[ItemB] = WornObjects[Index];
                
                Log("<SKSE Config> [RegisterTwoPartObject] Selected Item B is: " + GetFormLogData(SelectedObjects[ItemB]), Logger::Core, Logger::info);
            }
        }

        ImGuiMCP::EndMenu();
    }

    if (ImGuiMCP::BeginMenu("Select Keyword")) {
        for (UINT32 Index = 0; Index < FemaleKeywords.size(); ++Index) {
            if (!IsFlashRiskKeyword(FemaleKeywords[Index]) && ImGuiMCP::MenuItem(FemaleKeywords[Index]->GetFormEditorID())) {
                SelectedKeyword = FemaleKeywords[Index];

                Log("<SKSE Config> [RegisterTwoPartObject] Selected Keyword is: " + GetFormLogData(SelectedKeyword), Logger::Core, Logger::info);
            }
        }

        for (UINT32 Index = 0; Index < MaleKeywords.size(); ++Index) {
            if (!IsFlashRiskKeyword(MaleKeywords[Index]) && ImGuiMCP::MenuItem(MaleKeywords[Index]->GetFormEditorID())) {
                SelectedKeyword = MaleKeywords[Index];

                Log("<SKSE Config> [RegisterTwoPartObject] Selected Keyword is: " + GetFormLogData(SelectedKeyword), Logger::Core, Logger::info);
            }
        }

        ImGuiMCP::EndMenu();
    }

    if (SelectedObjects[ItemA]) {
        std::string DisplayText = "Selected Object A: " + std::string(SelectedObjects[ItemA]->GetName());
        ImGuiMCP::Text(DisplayText.c_str());
    }
    else {
        ImGuiMCP::Text("Selected Object A: NONE");
    }

    if (SelectedObjects[ItemB]) {
        std::string DisplayText = "Selected Object B: " + std::string(SelectedObjects[ItemB]->GetName());
        ImGuiMCP::Text(DisplayText.c_str());
    }
    else {
        ImGuiMCP::Text("Selected Object B: NONE");
    }

    if (SelectedKeyword) {
        std::string DisplayText = "Selected Keyword: " + std::string(SelectedKeyword->GetFormEditorID());
        ImGuiMCP::Text(DisplayText.c_str());
    }
    else {
        ImGuiMCP::Text("Selected Keyword: NONE");
    }

    if (ImGuiMCP::Button("Register")) {
        /*Log("<SKSE Config> [RegisterTwoPartObject] REGISTER START");
        Log("<SKSE Config> [RegisterTwoPartObject] Item A is: " + GetFormLogData(SelectedObjects[ItemA]));
        Log("<SKSE Config> [RegisterTwoPartObject] Item B is: " + GetFormLogData(SelectedObjects[ItemB]));
        Log("<SKSE Config> [RegisterTwoPartObject] Keyword is: " + GetFormLogData(SelectedKeyword));
        Log("<SKSE Config> [RegisterTwoPartObject] REGISTER END");*/

        RegisterResult = RegisterTwoPartObject(SelectedObjects[ItemA], SelectedObjects[ItemB], SelectedKeyword);
    }

    switch (RegisterResult) {
        case Success:
            ImGuiMCP::Text("Registration Succeeded!");
            break;
        case AlreadyExists:
            ImGuiMCP::Text("This combination already exists.");
            break;
        case TooManyObjects:
            ImGuiMCP::Text("Too many objects registered! Registration Rejected!");
            break;
        case InvalidSelection:
            ImGuiMCP::Text("Invalid Selection! Registration Rejected!");
            break;
        default:
            ImGuiMCP::Text("Ready to Register...");
            break;
    }
}

void __stdcall TwoPartObjectListMenu::Render() {
    static ImGuiMCP::ImGuiTableFlags flags = ImGuiMCP::ImGuiTableFlags_Resizable | ImGuiMCP::ImGuiTableFlags_Reorderable | ImGuiMCP::ImGuiTableFlags_Hideable | ImGuiMCP::ImGuiTableFlags_RowBg | ImGuiMCP::ImGuiTableFlags_BordersOuter |
        ImGuiMCP::ImGuiTableFlags_BordersV | ImGuiMCP::ImGuiTableFlags_NoBordersInBody | ImGuiMCP::ImGuiTableFlags_ScrollY;

    if (ImGuiMCP::BeginTable("twopartobjectlist_table", 4, flags)) {
        enum ColumnSlots {
            FarLeft,
            CenterLeft,
            CenterRight,
            FarRight
        };
        
        ImGuiMCP::TableSetupColumn("Item A");
        ImGuiMCP::TableSetupColumn("Item B");
        ImGuiMCP::TableSetupColumn("Act As Keyword");
        ImGuiMCP::TableHeadersRow();

        for (UINT32 Row = 0; Row < TwoPartObjects.size(); ++Row) {
            ImGuiMCP::TableNextRow();
            for (UINT32 Column = 0; Column < 4; ++Column) {
                ImGuiMCP::TableSetColumnIndex(Column);

                std::string DisplayText;

                if (Column == FarLeft) {
                    DisplayText = std::string(TwoPartObjects[Row].ObjectA->GetName());
                    ImGuiMCP::Text(DisplayText.c_str());
                }
                else if (Column == CenterLeft) {
                    DisplayText = std::string(TwoPartObjects[Row].ObjectB->GetName());
                    ImGuiMCP::Text(DisplayText.c_str());
                }
                else if (Column == CenterRight) {
                    DisplayText = std::string(TwoPartObjects[Row].Keyword->GetFormEditorID());
                    ImGuiMCP::Text(DisplayText.c_str());
                }
                else if (Column == FarRight) {
                    if (ImGuiMCP::Button("Unregister")) {
                        /*Log("<SKSE Config> [TwoPartObjectListMenu | UnregisterTwoPartObject] UNREGISTER START");
                        Log("<SKSE Config> [TwoPartObjectListMenu | UnregisterTwoPartObject] Item A is: " + GetFormLogData(TwoPartObjects[Row].ObjectA));
                        Log("<SKSE Config> [TwoPartObjectListMenu | UnregisterTwoPartObject] Item B is: " + GetFormLogData(TwoPartObjects[Row].ObjectB));
                        Log("<SKSE Config> [TwoPartObjectListMenu | UnregisterTwoPartObject] Keyword is: " + GetFormLogData(TwoPartObjects[Row].Keyword));
                        Log("<SKSE Config> [TwoPartObjectListMenu | UnregisterTwoPartObject] UNREGISTER END");*/

                        UINT8 Result = UnregisterTwoPartObject(TwoPartObjects[Row].ObjectA, TwoPartObjects[Row].ObjectB);
                        if (Result == DoesNotExist) {
                            Log("<SKSE Config> [TwoPartObjectListMenu | UnregisterTwoPartObject] ERROR: Unregister failed! This should not be possible!", Logger::Core, Logger::error);
                        }
                    }
                }
            }
        }
        ImGuiMCP::EndTable();
    }
    
}