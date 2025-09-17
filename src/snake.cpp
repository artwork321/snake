#include "snake.h"
#include <raylib.h>
#include "constants.h"
#include "raymath.h"

Snake::Snake()
{
    bodies = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = Right;
    frameCounter = 0;
}

// Update moving direction
void Snake::Move()
{
    if (IsKeyDown(KEY_RIGHT) && direction != Left)
    {
        direction = Right;
    }
    if (IsKeyDown(KEY_LEFT) && direction != Right)
    {
        direction = Left;
    };
    if (IsKeyDown(KEY_UP) && direction != Down)
    {
        direction = Up;
    };
    if (IsKeyDown(KEY_DOWN) && direction != Up)
    {
        direction = Down;
    };
}

void Snake::Grow()
{
    ++frameCounter;

    // move every n frames
    if (frameCounter >= framesPerMove)
    {
        frameCounter = 0;

        bodies.pop_back();
        bodies.push_front(Vector2Add(bodies[0], direction));
    }
}

void Snake::Draw()
{
    for (unsigned int i = 0; i < bodies.size(); ++i)
    {
        float x = bodies[i].x;
        float y = bodies[i].y;

        Rectangle segment = Rectangle{x * cellSize, y * cellSize, cellSize, cellSize};
        DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
}

bool Snake::Eat(Vector2 foodPos)
{
    if (bodies[0].x == foodPos.x && bodies[0].y == foodPos.y)
    {
        bodies.push_back(bodies.back() - direction);
        return true;
    }

    return false;
}

Vector2 Snake::GetHead()
{
    return bodies[0];
}

bool Snake::IsElementInDeque(Vector2 element)
{
    for (unsigned int i = 1; i < bodies.size(); ++i)
    {
        if (Vector2Equals(bodies[i], element))
            return true;
    }

    return false;
}

void Snake::Reset()
{
    bodies = {Vector2{6, 9}};
    direction = Right;
    frameCounter = 0;
}