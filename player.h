#include "raylib.h"

typedef struct Player {
    Vector2 position;
    float speed;
} Player;

void InitPlayer(Player *player, Vector2 startPos);
void UpdatePlayer(Player *player, float dt);
void DrawPlayer(Player player);
Vector2 PlayerPos();