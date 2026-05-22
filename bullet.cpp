#include "bullet.h"
#include <iostream>

void Bullet::InitBullets(Bullet bullets[])
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        bullets[i].active = false;
    }
}

void Bullet::ShootBullet(Bullet bullets[], Vector2 startPos, Vector2 direction)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (!bullets[i].active)
        {
            bullets[i].active = true;
            bullets[i].position = startPos;

            bullets[i].velocity = (Vector2){
                direction.x * BULLET_SPEED,
                direction.y * BULLET_SPEED
            };

            break;
        }
    }
}

void Bullet::UpdateBullets(Bullet bullets[], float dt, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active)
        {
            bullets[i].position.x += bullets[i].velocity.x * dt;
            bullets[i].position.y += bullets[i].velocity.y * dt;

            if (bullets[i].position.x < 0 ||
                bullets[i].position.x > SCREEN_WIDTH ||
                bullets[i].position.y < 0 ||
                bullets[i].position.y > SCREEN_HEIGHT)
            {
                bullets[i].active = false;
                std::cout << "" << std::endl;
            }
        }
    }
}

void Bullet::DrawBullets(Bullet bullets[])
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i].active)
        {
            DrawCircleV(bullets[i].position, 5, ORANGE);
        }
    }
}

