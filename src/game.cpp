#include "game.h"
#include "constants.h"

Game::Game()
    : snake(), food()
{
    score = 0;
    InitAudioDevice();
    eatSound = LoadSound("sounds/eat.mp3");
    wallSound = LoadSound("sounds/wall.mp3");
}

Game::~Game()
{
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}

void Game::Draw()
{
    food.Draw();
    snake.Draw();
}

void Game::Update()
{
    snake.Move();
    if (snake.Eat(food.GetPosition()))
    {
        food.GetNewPosition();
        score += 1;
        PlaySound(eatSound);
    }

    snake.Grow();
}

void Game::IsGameOver()
{
    // Check for colision
    if (CheckCollision())
    {
        PlaySound(wallSound);
        Reset();
    }
}

void Game::Reset()
{
    snake.Reset();
    food.GetNewPosition();
    score = 0;
}

bool Game::CheckCollision()
{
    if ((snake.GetHead().x >= cellCount - 1) || (snake.GetHead().y > heightScreen) || (snake.GetHead().x <= 0) || (snake.GetHead().y <= 0))
        return true;
    if (snake.IsElementInDeque(snake.GetHead()))
        return true;

    return false;
}

int Game::GetScore() const
{
    return score;
}