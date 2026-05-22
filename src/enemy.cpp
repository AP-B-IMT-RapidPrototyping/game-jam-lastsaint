#include "enemy.h"
#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include "raylib.h"
#include "../player.h"

int spawnRange = 200;
float enemySize = 20;
int maxEnemy = 2000;

std::vector<Vector2> enemyList;

int spawnDuration = 2;

Vector2 GetPlayerPos()
{
    return Vector2 {100, 100};
}

void Enemy::makeEnemy()
{
    bool insideRange = true;
    Vector2 posEnemy;

    if (enemyList.size() <= maxEnemy)
    {
        posEnemy = {float(GetRandomValue(0, GetScreenWidth())), float(GetRandomValue(0, GetScreenHeight()))};

        if ((p.position.x + spawnRange) >= posEnemy.x
                && (p.position.x <= posEnemy.x + (enemySize/2)))
        {
            if ((p.position.y + spawnRange) >= posEnemy.y
                && p.position.y <= posEnemy.y + (enemySize/2))
            {
                return;
            }
        }
        std::cout << " X1: " << posEnemy.x << " Y1: " << posEnemy.y << std::endl;
        enemyList.push_back(posEnemy);
    }
}

void enemyWander()
{
    int index = 0;
    for (Vector2 enemy : enemyList)
    {
        Vector2 player = GetPlayerPos();

        if (enemy.x < player.x) enemy.x++;
        else if (enemy.x > player.x) enemy.x--;
        if (enemy.y < player.y) enemy.y++;
        else if (enemy.y > player.y) enemy.y--;
    }
}

void Enemy::enemyDraw()
{
    for (Vector2 enemy : enemyList)
    {
        DrawCircleV(enemy, enemySize, RED);
    }
}
