#include <iostream>
#include "raylib.h"

int SCREEN_WIDTH = GetScreenWidth();
int SCREEN_HEIGHT = GetScreenHeight();

int main() {
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "LastSaint");
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}