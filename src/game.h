#pragma once
#include "snake.h"
#include "food.h"
#include "constants.h"

class Game
{
public:
    Game();
    ~Game();
    GameScreen currentState{};
    void Draw();
    void Update();
    void Reset();
    bool CheckCollision();
    bool IsGameOver();
    int GetScore() const;

private:
    Snake snake{};
    Food food{};
    int score{};
    Sound eatSound{};
    Sound wallSound{};
};