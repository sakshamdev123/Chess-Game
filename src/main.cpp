#include "raylib.h"
#include "Game.hpp"

const int WINDOW_SIZE = 720;

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Hello Raylib!");
    SetTargetFPS(60);
    Game game;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLUE);
        game.HandleEvents();
        game.SetDisplay();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
