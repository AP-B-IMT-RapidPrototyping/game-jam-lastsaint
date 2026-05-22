//
// Created by Christophe on 22/05/2026.
//

#include "enemy.h"
#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include "raylib.h"




void Enemy::makeEnemy()
{
    bool insideRange = true;
    Vector2 posEnemy;

    if (enemyList.size() <= maxEnemy)
    {
        posEnemy = {float(GetRandomValue(0, GetScreenWidth())), float(GetRandomValue(0, GetScreenHeight()))};

        /*if ((p.position.x + spawnRange) >= posEnemy.x
                && (p.position.x <= posEnemy.x + (enemySize/2)))
        {
            if ((p.position.y + spawnRange) >= posEnemy.y           //player werkt niet dus midden van scherm
                && p.position.y <= posEnemy.y + (enemySize/2))
            {
                return;
            }
        }*/

        if ((GetScreenWidth()/2 + spawnRange) >= posEnemy.x
                && (GetScreenWidth()/2 <= posEnemy.x + (enemySize/2)))
        {
            if ((GetScreenHeight()/2 + spawnRange) >= posEnemy.y           //player werkt niet dus midden van scherm
                && GetScreenHeight()/2 <= posEnemy.y + (enemySize/2))
            {
                return;
            }
        }
        std::cout << " X1: " << posEnemy.x << " Y1: " << posEnemy.y << std::endl;
        enemyList.push_back(posEnemy);
    }
}

/*void enemyWander()
{
    int index = 0;
    for (Vector2 enemy : enemyList)
    {
        Vector2 player = player;

        if (enemy.x < player.x) enemy.x++;
        else if (enemy.x > player.x) enemy.x--;
        if (enemy.y < player.y) enemy.y++;
        else if (enemy.y > player.y) enemy.y--;
    }
}*/

void Enemy::enemyDraw()
{
    for (Vector2 enemy : enemyList)
    {
        DrawCircleV(enemy, enemySize, RED);
    }
}
