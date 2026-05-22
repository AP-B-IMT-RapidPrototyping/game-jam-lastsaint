#define BULLET_H

#include "raylib.h"
#include <stdbool.h>

#define MAX_BULLETS 100
#define BULLET_SPEED 800.0f

typedef struct Bullet {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Bullet;

void InitBullets(Bullet bullets[]);
void ShootBullet(Bullet bullets[], Vector2 startPos, Vector2 direction);
void UpdateBullets(Bullet bullets[], float dt, int SCREEN_WIDTH, int SCREEN_HEIGHT);
void DrawBullets(Bullet bullets[]);
