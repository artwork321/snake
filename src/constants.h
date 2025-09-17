#pragma once
#include <vector>

typedef enum
{
    PLAYING,
    GAME_OVER
} GameScreen;

// Screen colors and dimensions
inline constexpr Color screenColor = {105, 105, 105, 255};
inline constexpr Color textColor = {128, 0, 0, 255};
inline constexpr int cellSize = 30;
inline constexpr int cellCount = 25;
inline constexpr int heightScreen = 18;

// Snake direction vectors and speed
inline constexpr Vector2 initialSpawn = {cellCount / 2, cellCount};
inline constexpr Vector2 Up = {0, -1};
inline constexpr Vector2 Down = {0, 1};
inline constexpr Vector2 Left = {-1, 0};
inline constexpr Vector2 Right = {1, 0};
inline constexpr int framesPerMove = 10;
