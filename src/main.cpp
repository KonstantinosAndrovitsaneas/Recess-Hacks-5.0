#include <iostream>
#include "BankAccount.hpp"
#include "Investment.h"
#include "raylib/raylib.h"
#include "raylib/raymath.h"
#include <string>
#include "imgui.h"
#include "rlImGui.h"
#include "Grid.hpp"
#include "Shop.hpp"


int main() {
    //Uncommenting the statement below will cause a linker error - i dont know how to fix it - i've spent too many hours trying - help me please. - Waheed
   //FOR SOME REASON INVENTORY IS ALSO CAUSING A LINKER ERROR SO FUCK THAT IM NOT USING IT ANYMORE - Waheed
    
    //Investment* nike =  new Investment(1000.0, 0.07, "Nike");

    
    
    const int screenWidth = 1200;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    SetWindowState(FLAG_WINDOW_RESIZABLE);


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    rlImGuiSetup(true);
    Vec3 pos;

    pos.x = 10;
    pos.y = 10;
    pos.z = 10;
    
    Grid grid;

    Tile tile;

    Tile offices;

    offices.id = 1;

    offices.name = "Nike";

    tile.id = 2;

    grid.PlaceTile({1,1,1}, tile);
    grid.PlaceTile({ 2,2,1 }, offices);

    Tile* t = grid.GetTile({ 5,5,5 });
    if (t != nullptr) {
        std::cout << t->id << "\n";
        t->id = 5;
        std::cout << t->id << "\n";
    }
    else {
        std::cout << "Tile not found!\n";
    }
    std::vector<int> tilemap = LoadTileMap((char*)"resources/map.csv");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //CalculateGridPosition();
        grid.RenderTileSet();

       // RenderTileLayer((char*)"resources/tile.png", tilemap, { 0, 0 }, { 30, 20 });

        rlImGuiBegin();
        Tile* clickedTile = grid.GetClickedTile();


        // show ImGui Content
        bool open = true;
        ImGui::ShowDemoWindow(&open);

        ImVec2 windowPos;

        open = true;

        if (clickedTile != nullptr) {

            ImVec2 windowPos;
            windowPos.x = clickedTile->position.x * 80.0 + 10;
            windowPos.y = clickedTile->position.y * 80.0 + 10;

            ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);

            if (ImGui::Begin("Test Window", &open))
            {

                ImGui::Text("Tile ID: %d", clickedTile->id);
                ImGui::Text("Position: (%d, %d, %d)",
                    clickedTile->position.x,
                    clickedTile->position.y,
                    clickedTile->position.z);
                
                
                if (ImGui::Button("Buy")) {
                                    
                    //clickedTile->name;
    
                
                }
                
          
                
                
                
                ImGui::End();

            

            
            
            }

            else {
            
                windowPos.x = 1000;
                windowPos.y = 1000;
				ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);
            
            }

            /*ImGui::TextUnformatted(ICON_FA_JEDI);

            rlImGuiImage(&image);*/
        }

        RenderShop();
        RenderBankAccounts();
    
        // end ImGui Content
        rlImGuiEnd();

        EndDrawing();
       /* ImGui::InputText("string", buf, IM_ARRAYSIZE(buf));
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);*/

        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}