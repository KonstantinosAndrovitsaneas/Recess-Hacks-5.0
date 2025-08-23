#include <iostream>
//#include "test.cpp"
#include "BankAccount.hpp"
//#include "Investment.h"

#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "imgui.h"
#include "rlImGui.h"


int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

   
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

 
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    rlImGuiSetup(true);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
    
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        rlImGuiBegin();

        // show ImGui Content
        bool open = true;
        ImGui::ShowDemoWindow(&open);

        open = true;
        if (ImGui::Begin("Test Window", &open))
        {
            /*ImGui::TextUnformatted(ICON_FA_JEDI);

            rlImGuiImage(&image);*/
        }
        ImGui::End();

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