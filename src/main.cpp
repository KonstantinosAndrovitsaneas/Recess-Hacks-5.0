#include <iostream>
//#include "test.cpp"
#include "BankAccount.hpp"
//#include "Investment.h"

#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "imgui.h"
#include "rlImGui.h"

#include "Grid.hpp"


int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    rlImGuiSetup(true);
    Vec3 pos;

    pos.x = 10;
    pos.y = 10;
    pos.z = 10;
    
    Grid grid;

    struct Tile tile;

    tile.id = 1;

    grid.PlaceTile({5, 5, 5}, tile);
    grid.PlaceTile({ 0, 0, 0 }, tile);
    grid.PlaceTile({ 10, 10, 10 }, tile);

    struct Tile* t = grid.GetTile({ 5, 5, 5 });

    std::cout << t->id << "\n";
    t->id = 5;
    std::cout << t->id << "\n";

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

        DrawCircleV(ballPosition, 50, MAROON);

        //grid.RenderTileSet();

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