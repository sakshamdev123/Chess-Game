#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Hello Raylib!");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("Hello", 300, 300, 16, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}