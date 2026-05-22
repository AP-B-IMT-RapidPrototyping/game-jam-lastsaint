#include "raylib.h"

class Player {
public:
    Vector2 position;
    float speed;
    void Init(Vector2 startPos);
    void Update(float dt);
    void Draw();
private:

};

