#include "food.h"
#include <raylib.h>
#include "constants.h"

Food::Food()
{
    position = Vector2{
        static_cast<float>(GetRandomValue(0, cellSize - 1)), static_cast<float>(GetRandomValue(0, cellCount - 1))};

    Image image = LoadImage("Graphics/food.png");
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
        static_cast<float>(GetRandomValue(0, cellSize - 1)), static_cast<float>(GetRandomValue(0, cellCount - 1))};
}