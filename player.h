#include "raylib.h"

class Player {
public:
    Vector2 position;
    float speed;
    void InitPlayer(Player *player, Vector2 startPos);
    void UpdatePlayer(Player *player, float dt);
    void DrawPlayer(Player player);
    Vector2 PlayerPos();
    Rectangle GetRectPlayer(Player *player);
private:
};

