#pragma once
#include "snake.h"
#include "food.h"

class Game
{
public:
    Game();
    void Draw();
    void Update();
    bool CheckCollision();
    void Reset();
    void IsGameOver();

private:
    Snake snake;
    Food food;
};