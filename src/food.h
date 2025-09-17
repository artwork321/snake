#pragma once
#include "raylib.h"

class Food
{
public:
    Food();
    void Draw();

private:
    Vector2 position;
    Texture2D texture;
};