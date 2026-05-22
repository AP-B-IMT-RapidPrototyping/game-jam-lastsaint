//
// Created by Christophe on 22/05/2026.
//

#include "enemy.h"

#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include "raylib.h"

int spawnRange = 200;
int enemySize = 20;
std::vector<Vector2> enemyList;
int spawnDuration = 2;

Vector2 GetPlayerPos()
{
    return Vector2 {100, 100};
}

void Enemy::makeEnemy()
{
    Vector2 player = GetPlayerPos();

    Vector2 posEnemy = {float(GetRandomValue(player.x + spawnRange, GetScreenWidth())), float(GetRandomValue(player.y + spawnRange, GetScreenHeight()))};
    std::cout << " X: " << posEnemy.x << " Y: " << posEnemy.y << std::endl;
    enemyList.push_back(posEnemy);
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
