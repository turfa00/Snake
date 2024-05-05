#include "game.hpp"

Game::Game()
{
    score = -1;
    foodPos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
}

void Game::reset()
{
    for (int i = 0; i < BLOCKS_IN_ROW; i++)
    {
        for (int j = 0; j < BLOCKS_IN_COLUMN; j++)
        {
            game_grid[i][j] = false;
        }
    }
}

void Game::drawFood(Vec2f snakePos, Vec2f snakeLastPos, Vec2f snakeTailPos[], int &length)
{
    std::srand(std::time(nullptr));
    int rangeX = BLOCKS_IN_ROW - 1;
    int rangeY = BLOCKS_IN_COLUMN - 1;

    if (snakePos.x == foodPos.x && snakePos.y == foodPos.y)
    {
        score++;
        length++;
        // Increase Level (Speed)
        if (score % 10 == 0)
        {
            refresh_rate -= 0.01;
        }
        // Search for free space on the grid
        while (1)
        {
            foodPos.x = rand() % rangeX;
            foodPos.y = rand() % rangeY;
            if (foodPos.x == snakePos.x && foodPos.y == snakePos.y || foodPos.x == snakeLastPos.x && foodPos.y == snakeLastPos.y)
            {
                continue;
            }
            for (int i = 0; i < length; i++)
            {
                if (snakePos.x == snakeTailPos[i].x && snakePos.y == snakeTailPos[i].y)
                {
                    continue;
                }
            }
            break;
        }
    }

    // Draw food
    DrawRectangle(foodPos.x * GRID_BLOCK_LENGTH,
                  HUD_HEIGHT + foodPos.y * GRID_BLOCK_LENGTH,
                  GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, RAYWHITE);
}