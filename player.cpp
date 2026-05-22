#include "player.h"

void InitPlayer(Player *player, Vector2 startPos)
{
    player->position = startPos;
    player->speed = 300.0f;
}

void UpdatePlayer(Player *player, float dt)
{
    if (IsKeyDown(KEY_W) && player->position.y > 0) player->position.y -= player->speed * dt;
    if (IsKeyDown(KEY_S)&& player->position.y < GetScreenHeight()) player->position.y += player->speed * dt;
    if (IsKeyDown(KEY_A) && player->position.x > 0) player->position.x -= player->speed * dt;
    if (IsKeyDown(KEY_D) && player->position.x < GetScreenWidth()) player->position.x += player->speed * dt;
}

void DrawPlayer(Player player)
{
    DrawCircleV(player.position, 20, GREEN);
}

Vector2 PlayerPos(Player *player) {
    return player->position;
}

Rectangle GetRect(Player *player) {
    return {player->position.x,player->position.y,
        int(5),
        int(5)
    };
}
