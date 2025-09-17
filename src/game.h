#pragma once
#include "snake.h"
#include "food.h"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void Reset();
    bool CheckCollision();
    void IsGameOver();
    int GetScore() const;

private:
    Snake snake{};
    Food food{};
    int score{};
    Sound eatSound{};
    Sound wallSound{};
};