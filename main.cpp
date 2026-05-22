#include "raylib.h"
#include "raymath.h"

#include "player.h"
#include "bullet.h"

int SCREEN_WIDTH = GetScreenWidth();
int SCREEN_HEIGHT = GetScreenHeight();

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Shooter");
    SetTargetFPS(60);

    Player player;
    InitPlayer(&player, (Vector2){ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });

    Bullet bullets[MAX_BULLETS];
    InitBullets(bullets);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        UpdatePlayer(&player, dt);

        Vector2 mouse = GetMousePosition();

        Vector2 direction = Vector2Normalize(
            Vector2Subtract(mouse, player.position)
        );

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            ShootBullet(bullets, player.position, direction);
        }

        UpdateBullets(bullets, dt, GetScreenWidth(), GetScreenHeight());

        BeginDrawing();

        ClearBackground(BLUE);

        DrawPlayer(player);
        DrawBullets(bullets);

        DrawLineEx(player.position, mouse, 3, YELLOW);

        DrawText("WASD to move", 20, 20, 20, WHITE);
        DrawText("Mouse to aim", 20, 50, 20, WHITE);
        DrawText("Left click to shoot", 20, 80, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}