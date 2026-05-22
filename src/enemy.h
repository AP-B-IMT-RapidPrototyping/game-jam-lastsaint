//
// Created by Christophe on 22/05/2026.
//

#ifndef UNIT_TESTING_PROJECT_ENEMY_H
#define UNIT_TESTING_PROJECT_ENEMY_H
#include <vector>
#include "raylib.h"
#include "../player.h"

class Enemy
{
    int spawnRange = 200;
    float enemySize = 20;
    int maxEnemy = 2000;

    std::vector<Vector2> enemyList;

    int spawnDuration = 2;

    //void enemyWander();

public:
    void makeEnemy();

    void enemyDraw();
};


#endif //UNIT_TESTING_PROJECT_ENEMY_H