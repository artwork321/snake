#pragma once
#include "raylib.h"

class Food
{
public:
    Food();
    void Draw();
    Vector2 GetPosition();
    void GetNewPosition();

private:
    Vector2 position;
    Texture2D texture;
};