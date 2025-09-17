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
        switch (game.currentState)
        {
        case (PLAYING): // Playing Screen
            BeginDrawing();

            game.Update();

            if (game.IsGameOver())
            {
                break;
            }

            // Drawing
            ClearBackground(screenColor);
            DrawRectangleLinesEx(Rectangle{cellSize, cellSize, cellSize * (cellCount - 2), cellSize * heightScreen}, 4, textColor);
            game.Draw();
            DrawText("Retro Snake", cellSize, heightScreen * (cellSize + 2), 40, textColor);
            DrawText(TextFormat("Score: %i", game.GetScore()), cellSize, heightScreen * (cellSize + 5), 30, textColor);
            EndDrawing();
            break;
        case (GAME_OVER): // End Game Screen
            BeginDrawing();
            ClearBackground(screenColor);

            // Display Text
            DrawText("Game Over!", GetScreenWidth() / 2 - MeasureText("Game Over!", 50) / 2,
                     GetScreenHeight() / 2 - 100, 50, textColor);
            DrawText("Press Enter to Restart", GetScreenWidth() / 2 - MeasureText("Press Enter to Restart", 20) / 2,
                     GetScreenHeight() / 2 - 20 / 2, 20, textColor);

            // Process Input
            if (IsKeyPressed(KEY_ENTER))
            {
                game.Reset();
                game.currentState = PLAYING;
            }

            EndDrawing();
            break;
        }
    }

    CloseWindow();
    return 0;
}
