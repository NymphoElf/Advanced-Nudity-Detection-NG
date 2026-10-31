#include "SKSEConfig.h"

#include "Core.h"
#include "Logger.h"

using namespace SKSEConfig;

void RegisterSKSEConfigMenu() {
    if (!SKSEMenuFramework::IsInstalled()) {
        return;
    }
    //Example3::filter = new ImGuiMCP::ImGuiTextFilter();
    //Configuration::Example2::Buffer[0] = '\0';
    SKSEMenuFramework::SetSection(ModName);

    SKSEMenuFramework::AddEvent(RegisterTwoPartObjectMenu::OnMenuEvent, 0.0f);

    SKSEMenuFramework::AddSectionItem("Register Two Part Object", RegisterTwoPartObjectMenu::Render);
    SKSEMenuFramework::AddSectionItem("Two Part Object List", TwoPartObjectListMenu::Render);

    //RegisterTwoPartObject::filter = new ImGuiMCP::ImGuiTextFilter();
    //TwoPartObjectList::filter = new ImGuiMCP::ImGuiTextFilter();

    /*
    SKSEMenuFramework::AddSectionItem("Font Awesome", Example4::Render);
    SKSEMenuFramework::AddSectionItem("Add Item", Example1::Render);
    SKSEMenuFramework::AddSectionItem("Folder Example/Example 2", Example2::Render);
    UI::Example2::ExampleWindow = SKSEMenuFramework::AddWindow(Example2::RenderWindow, true);
    SKSEMenuFramework::AddSectionItem("Folder Example/Example 3", Example3::Render);

    SKSEMenuFramework::AddSectionItem("Example 5", Example5::Render);
    SKSEMenuFramework::AddSectionItem("Example 6", Example6::Render);
    SKSEMenuFramework::AddSectionItem("Example 7", Example7::Render);
    SKSEMenuFramework::AddSectionItem("Example 8 \\/ Test", Example8::Render);
    SKSEMenuFramework::AddHudElement(Example5::RenderOverlay);
    SKSEMenuFramework::AddInputEvent(Example5::OnInput);
    UI::Example5::NonPausingWindow = SKSEMenuFramework::AddWindow(Example5::RenderWindow, false);

    SKSEMenuFramework::AddEvent(UI::Example6::OnEvent, 0);
    */
}

void __stdcall RegisterTwoPartObjectMenu::Render() {
    static ImGuiMCP::ImGuiTableFlags flags = ImGuiMCP::ImGuiTableFlags_Resizable | ImGuiMCP::ImGuiTableFlags_Reorderable | ImGuiMCP::ImGuiTableFlags_Hideable | ImGuiMCP::ImGuiTableFlags_RowBg | ImGuiMCP::ImGuiTableFlags_BordersOuter |
        ImGuiMCP::ImGuiTableFlags_BordersV | ImGuiMCP::ImGuiTableFlags_NoBordersInBody | ImGuiMCP::ImGuiTableFlags_ScrollY;

    //filter->Draw();

    enum Items {
        ItemA,
        ItemB
    };

    if (ImGuiMCP::Button("Refresh Worn Objects")) {
        WornObjects = GetPlayerWornObjectList();
    }

    if (ImGuiMCP::BeginMenu("Select Item A")) {
        for (UINT32 Index = 0; Index < WornObjects.size(); ++Index) {
            if (ImGuiMCP::MenuItem(WornObjects[Index]->GetName())) {
                if (WornObjects[Index] == SelectedObjects[ItemB]) {
                    SelectedObjects[ItemB] = SelectedObjects[ItemA];
                    SelectedObjects[ItemA] = WornObjects[Index];
                }
                
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
                    SelectedObjects[ItemB] = WornObjects[Index];
                }
                
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
        Log("<SKSE Config> [RegisterTwoPartObject] REGISTER START");
        Log("<SKSE Config> [RegisterTwoPartObject] Item A is: " + GetFormLogData(SelectedObjects[ItemA]));
        Log("<SKSE Config> [RegisterTwoPartObject] Item B is: " + GetFormLogData(SelectedObjects[ItemB]));
        Log("<SKSE Config> [RegisterTwoPartObject] Keyword is: " + GetFormLogData(SelectedKeyword));
        Log("<SKSE Config> [RegisterTwoPartObject] REGISTER END");

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

    //filter->Draw();

    if (ImGuiMCP::BeginTable("twopartobjectlist_table", 3, flags)) {
        enum ColumnSlots {
            Left,
            Center,
            Right
        };
        
        ImGuiMCP::TableSetupColumn("Item A");
        ImGuiMCP::TableSetupColumn("Item B");
        ImGuiMCP::TableSetupColumn("Act As Keyword");
        ImGuiMCP::TableHeadersRow();

        for (UINT32 Row = 0; Row < TwoPartObjectA.size(); ++Row) {
            ImGuiMCP::TableNextRow();
            for (UINT32 Column = 0; Column < 3; ++Column) {
                ImGuiMCP::TableSetColumnIndex(Column);

                char DisplayText[256];

                if (Column == Left) {
                    strncpy_s(DisplayText, sizeof(DisplayText), TwoPartObjectA[Row]->GetName(), sizeof(DisplayText));
                }
                else if (Column == Center) {
                    strncpy_s(DisplayText, sizeof(DisplayText), TwoPartObjectB[Row]->GetName(), sizeof(DisplayText));
                }
                else if (Column == Right) {
                    strncpy_s(DisplayText, sizeof(DisplayText), TwoPartObjectKeyword[Row]->GetFormEditorID(), sizeof(DisplayText));
                }

                ImGuiMCP::TextUnformatted(DisplayText);
            }
        }
    }
}