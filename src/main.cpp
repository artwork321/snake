#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "food.h"
#include "snake.h"
#include "game.h"

int main()
{
    std::cout << "Starting the game...\n";
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();
    // Food food = Food();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // food.Draw();
        game.Update();
        game.IsGameOver();

        ClearBackground(green);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
