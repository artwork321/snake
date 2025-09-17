#include "game.h"
#include "constants.h"

Game::Game()
{
    snake = Snake();
    food = Food();
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
    }

    snake.Grow();
}

void Game::IsGameOver()
{
    // Check for colision
    if (CheckCollision())
        Reset();
}

void Game::Reset()
{
    snake.Reset();
    food.GetNewPosition();
}

bool Game::CheckCollision()
{
    if (snake.GetHead().x >= cellCount || (snake.GetHead().y >= cellCount) || (snake.GetHead().x <= 0) || (snake.GetHead().y <= 0))
        return true;
    if (snake.IsElementInDeque(snake.GetHead()))
        return true;

    return false;
}