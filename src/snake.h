#pragma once
#include <vector>
#include "raylib.h"

class Snake
{
public:
    Snake();
    void IncreaseBody();
    void Move();
    void Draw();
    void Eat();

private:
    std::vector<Vector2> bodies;
    Vector2 turningPoint;
    Vector2 direction;
    Vector2 previousDirection;
};