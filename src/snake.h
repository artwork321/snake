#pragma once
#include "raylib.h"
#include <deque>

class Snake
{
public:
    Snake();
    void Move();
    void Draw();
    bool Eat(Vector2 foodPos);
    void Grow();
    Vector2 GetHead();
    void Reset();

private:
    std::deque<Vector2> bodies;
    Vector2 direction;
    int frameCounter;
};