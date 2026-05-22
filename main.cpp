#include "raylib.h"
#include "player.h"
#include "bullet.h"

int WINDOW_WIDTH = GetScreenWidth();
int WINDOW_HEIGHT = GetScreenHeight();

Player player = Player();

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LastSaint");
    SetTargetFPS(60);

    //Game Loop
    while (WindowShouldClose() == false) {
        //updates
        

        //drawing
        BeginDrawing();
        ClearBackground(BLUE);
        player.Draw(player);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}
