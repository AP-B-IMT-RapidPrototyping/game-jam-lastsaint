#include "raylib.h"
#include "raymath.h"
#include <string>
#include "player.h"
#include "bullet.h"

int SCREEN_WIDTH = GetScreenWidth();
int SCREEN_HEIGHT = GetScreenHeight();


double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Shooter");
    SetTargetFPS(60);

    Player player;
    Bullet bullet = Bullet();
    player.InitPlayer(&player, (Vector2){ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });

    Bullet bullets[MAX_BULLETS];
    bullet.InitBullets(bullets);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        player.UpdatePlayer(&player, dt);

        Vector2 mouse = {GetMousePosition().x,GetMousePosition().y+15};

        Vector2 direction = Vector2Normalize(
            Vector2Subtract(mouse, player.position)
        );

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            bullet.ShootBullet(bullets, player.position, direction);
        }

        bullet.UpdateBullets(bullets, dt, GetScreenWidth(), GetScreenHeight());

        if (EventTriggered(0.5))
        {
            enemy.makeEnemy();
        }

        BeginDrawing();

        ClearBackground(GREEN);

        player.DrawPlayer(player);
        DrawLineEx(player.position, mouse , 3, YELLOW);
        bullet.DrawBullets(bullets);
        DrawText("WASD to move", 20, 20, 20, WHITE);
        DrawText("Mouse to aim", 20, 50, 20, WHITE);
        DrawText("Left click to shoot", 20, 80, 20, WHITE);
        enemy.enemyDraw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}