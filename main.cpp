#include <iostream>
#include <raylib.h>

const Color green = {173, 204, 96, 255};
const Color darkGreen = {43, 51, 24, 255};
const int cellSize = 30;
const int cellCount = 25;

class Food
{
public:
    Vector2 position = {5, 6};
    Texture2D texture;

    Food()
    {
        Image image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }
};

int main()
{
    std::cout << "Starting the game...\n";
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Food food = Food();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(green);

        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}