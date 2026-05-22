#include "player.h"

void Player::InitPlayer(Player *player, Vector2 startPos)
{
    player->position = startPos;
    player->speed = 300.0f;
}

void Player::UpdatePlayer(Player *player, float dt)
{
    if (IsKeyDown(KEY_W) && player->position.y > 0) player->position.y -= player->speed * dt;
    if (IsKeyDown(KEY_S)&& player->position.y < GetScreenHeight()) player->position.y += player->speed * dt;
    if (IsKeyDown(KEY_A) && player->position.x > 0) player->position.x -= player->speed * dt;
    if (IsKeyDown(KEY_D) && player->position.x < GetScreenWidth()) player->position.x += player->speed * dt;
}

void Player::DrawPlayer(Player player)
{
    DrawCircleV(player.position, 20, BLUE);
}
