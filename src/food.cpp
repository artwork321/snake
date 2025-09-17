#include "food.h"
#include <raylib.h>
#include "constants.h"

Food::Food()
{
    position = Vector2{
        static_cast<float>(GetRandomValue(0, cellSize - 2)), static_cast<float>(GetRandomValue(0, cellCount - 2))};

    Image image = LoadImage("graphics/food.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::Draw()
{
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}

Vector2 Food::GetPosition()
{
    return position;
}

void Food::GetNewPosition()
{
    position = Vector2{
        static_cast<float>(GetRandomValue(0, cellSize - 2)), static_cast<float>(GetRandomValue(0, cellCount - 2))};
}