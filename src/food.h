#pragma once
#include "raylib.h"

class Food
{
public:
    Food();
    ~Food();
    void Draw();
    Vector2 GetPosition() const;
    void GetNewPosition();

private:
    Vector2 position{};
    Texture2D texture{};
};