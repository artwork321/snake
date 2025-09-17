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

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        game.Update();
        game.IsGameOver();

        // Drawing
        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{cellSize, cellSize, cellSize * (cellCount - 2), cellSize * heightScreen}, 4, darkGreen);
        game.Draw();
        DrawText("Retro Snake", cellSize, heightScreen * (cellSize + 2), 40, darkGreen);
        DrawText(TextFormat("Score: %i", game.GetScore()), cellSize, heightScreen * (cellSize + 5), 30, darkGreen);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
