#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "food.h"
#include "snake.h"

void Reset(Snake &snake, Food &food);
bool CheckCollision(Snake &snake);

int main()
{
    std::cout << "Starting the game...\n";
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Food food = Food();
    Snake snake = Snake();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(green);

        food.Draw();

        snake.Move();
        if (snake.Eat(food.GetPosition()))
        {
            food.GetNewPosition();
        }

        snake.Grow();
        snake.Draw();

        // Check for colision
        if (CheckCollision(snake))
            Reset(snake, food);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

bool CheckCollision(Snake &snake)
{
    return (snake.GetHead().x >= cellCount) || (snake.GetHead().y >= cellCount) || (snake.GetHead().x <= 0) || (snake.GetHead().y <= 0);
}

void Reset(Snake &snake, Food &food)
{
    snake.Reset();
    food.GetNewPosition();
}
