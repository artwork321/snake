#include "food.h"
#include <raylib.h>
#include "constants.h"

Food::Food()
{
    GetNewPosition();

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

Vector2 Food::GetPosition() const
{
    return position;
}

void Food::GetNewPosition()
{
    position = Vector2{
        static_cast<float>(GetRandomValue(1, cellCount - 2)), static_cast<float>(GetRandomValue(1, heightScreen - 1))};
}