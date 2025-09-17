#include "snake.h"
#include <raylib.h>
#include "constants.h"

Snake::Snake()
{
    bodies = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    turningPoint = {};
    direction = Right;
}

// Update moving direction
void Snake::Move()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        previousDirection = direction;
        direction = Right;
        turningPoint = bodies[0];
    }
    if (IsKeyDown(KEY_LEFT))
    {
        previousDirection = direction;
        direction = Left;
        turningPoint = bodies[0];
    };
    if (IsKeyDown(KEY_UP))
    {
        previousDirection = direction;
        direction = Up;
        turningPoint = bodies[0];
    };
    if (IsKeyDown(KEY_DOWN))
    {
        previousDirection = direction;
        direction = Down;
        turningPoint = bodies[0];
    };

    for (unsigned int i = 0; i < bodies.size(); ++i)
    {
        if (bodies[i].x < cellCount && bodies[i].y < cellCount)
        {
            float x = bodies[i].x + direction.x * 0.5;
            float y = bodies[i].y + direction.y * 0.5;

            bodies[i] = Vector2{x, y};
        }
    }
}

void Snake::Draw()
{
    for (unsigned int i = 0; i < bodies.size(); ++i)
    {
        DrawRectangle((int)bodies[i].x * cellSize, (int)bodies[i].y * cellSize, cellSize, cellSize, darkGreen);
    }
}

void Snake::Eat()
{
    float x = bodies[bodies.size() - 1].x + previousDirection.x;
    float y = bodies[bodies.size() - 1].y + previousDirection.y;
    bodies.push_back(Vector2{x, y});
}