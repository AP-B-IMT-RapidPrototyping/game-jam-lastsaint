#include "player.h"

void Player::Init(Vector2 startPos)
{
    this->position = startPos;
    this->speed = 300.0f;
}

void Player::Update(float dt)
{
    if (IsKeyDown(KEY_W)) this->position.y -= this->speed * dt;
    if (IsKeyDown(KEY_S)) this->position.y += this->speed * dt;
    if (IsKeyDown(KEY_A)) this->position.x -= this->speed * dt;
    if (IsKeyDown(KEY_D)) this->position.x += this->speed * dt;
}

void Player::Draw()
{
    DrawCircleV(player.position, 20, GREEN);
}