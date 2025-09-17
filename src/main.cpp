#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "food.h"
#include "snake.h"

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

        EndDrawing();
    }

    CloseWindow();
    return 0;
}