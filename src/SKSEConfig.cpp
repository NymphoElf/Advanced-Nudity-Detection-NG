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

    SKSEMenuFramework::AddSectionItem("Register Two Part Object", RegisterTwoPartObject::Render);
    SKSEMenuFramework::AddSectionItem("Two Part Object List", TwoPartObjectList::Render);

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

void __stdcall RegisterTwoPartObject::Render() {
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
                
                if (SelectedObjects[ItemA]) {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Item A is: " + std::string(SelectedObjects[ItemA]->GetName()), Logger::Core, Logger::info);
                }
                else {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Item A is: NULL", Logger::Core, Logger::info);
                }
            }
        }

        ImGuiMCP::EndMenu();
    }

    if (ImGuiMCP::BeginMenu("Select Item B")) {
        for (UINT32 Index = 0; Index < WornObjects.size(); ++Index) {
            if (ImGuiMCP::MenuItem(WornObjects[Index]->GetName())) {
                SelectedObjects[ItemB] = WornObjects[Index];
                
                if (SelectedObjects[ItemB] == SelectedObjects[ItemA]) {
                    SelectedObjects[ItemA] = nullptr;
                }
                
                if (SelectedObjects[ItemB]) {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Item B is: " + std::string(SelectedObjects[ItemB]->GetName()), Logger::Core, Logger::info);
                }
                else {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Item B is: NULL", Logger::Core, Logger::info);
                }
            }
        }

        ImGuiMCP::EndMenu();
    }

    if (ImGuiMCP::BeginMenu("Select Keyword")) {
        for (UINT32 Index = 0; Index < FemaleKeywords.size(); ++Index) {
            if (ImGuiMCP::MenuItem(FemaleKeywords[Index]->GetFormEditorID())) {
                SelectedKeyword = FemaleKeywords[Index];

                if (SelectedKeyword) {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Keyword is: " + std::string(SelectedKeyword->GetFormEditorID()), Logger::Core, Logger::info);
                }
                else {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Keyword is: NULL", Logger::Core, Logger::info);
                }
            }
        }

        for (UINT32 Index = 0; Index < MaleKeywords.size(); ++Index) {
            if (ImGuiMCP::MenuItem(MaleKeywords[Index]->GetFormEditorID())) {
                SelectedKeyword = MaleKeywords[Index];

                if (SelectedKeyword) {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Keyword is: " + std::string(SelectedKeyword->GetFormEditorID()), Logger::Core, Logger::info);
                }
                else {
                    Log("<SKSE Config> [RegisterTwoPartObject] Selected Keyword is: NULL", Logger::Core, Logger::info);
                }
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

    /*
    if (ImGuiMCP::BeginTable("twopartobjectregister_table", 3, flags)) {
        enum ColumnSlots {
            Left,
            Center,
            Right
        };

        ImGuiMCP::TableSetupColumn("Item A");
        ImGuiMCP::TableSetupColumn("Item B");
        ImGuiMCP::TableSetupColumn("Act As Keyword");
        ImGuiMCP::TableHeadersRow();

        //Only One Row of Menus
        ImGuiMCP::TableNextRow();

        

        ImGuiMCP::TableSetColumnIndex(Left);
        

        ImGuiMCP::TableSetColumnIndex(Center);
        
        
        ImGuiMCP::TableSetColumnIndex(Right);
        
        ImGuiMCP::EndTable();
    }
    */

    if (ImGuiMCP::Button("Register")) {
        Log("<SKSE Config> [RegisterTwoPartObject] DUMMY REGISTER START");
        Log("<SKSE Config> [RegisterTwoPartObject] Item A is: " + std::string(SelectedObjects[ItemA]->GetName()) + " (" + std::format("{:08X}", SelectedObjects[ItemA]->GetFormID()) + ")");
        Log("<SKSE Config> [RegisterTwoPartObject] Item B is: " + std::string(SelectedObjects[ItemB]->GetName()) + " (" + std::format("{:08X}", SelectedObjects[ItemB]->GetFormID()) + ")");
        Log("<SKSE Config> [RegisterTwoPartObject] Keyword is: " + std::string(SelectedKeyword->GetFormEditorID()) + " (" + std::format("{:08X}", SelectedKeyword->GetFormID()) + ")");
        Log("<SKSE Config> [RegisterTwoPartObject] DUMMY REGISTER END");
    }
}

void __stdcall TwoPartObjectList::Render() {
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

        RE::TESBoundObject* CurrentObject;

        for (UINT32 Row = 0; Row < TwoPart_ObjectA.size(); ++Row) {
            ImGuiMCP::TableNextRow();
            for (UINT32 Column = 0; Column < 3; ++Column) {
                ImGuiMCP::TableSetColumnIndex(Column);

                char DisplayText[256];

                if (Column == Left) {
                    //CurrentObject = RE::TESForm::LookupByEditorID<RE::TESBoundObject>(TwoPart_Object_PartA[Row]);
                    CurrentObject = TwoPart_ObjectA[Row];
                    strncpy_s(DisplayText, sizeof(DisplayText), CurrentObject->GetName(), sizeof(DisplayText));
                }
                else if (Column == Center) {
                    CurrentObject = TwoPart_ObjectB[Row];
                    strncpy_s(DisplayText, sizeof(DisplayText), CurrentObject->GetName(), sizeof(DisplayText));
                }
                else if (Column == Right) {
                    RE::BGSKeyword* ThisKeyword = TwoPart_Object_Keyword[Row];
                    strncpy_s(DisplayText, sizeof(DisplayText), ThisKeyword->GetFormEditorID(), sizeof(DisplayText));
                }

                ImGuiMCP::TextUnformatted(DisplayText);
            }
        }
    }
}