#include <iostream>
#include <raylib.h>

int main()
{
    std::cout << "Starting the game...\n";
    InitWindow(750, 750, "Retro Snake");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}