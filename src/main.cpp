#include "raylib.h"
#include "Game.hpp"

const int WINDOW_SIZE = 640;

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Chess");
    SetTargetFPS(60);
    Game game;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        game.HandleEvents();
        game.SetDisplay();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
