#include "game.hpp"

Game::Game()
{
    score = -1;
    distance = 1;
    refresh_rate = 0.2;
    foodPos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
    r = false;
}

void Game::reset()
{
    score = -1;
    distance = 1;
    refresh_rate = 0.2;
    foodPos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
    r = false;
}

void Game::drawMenu()
{
    BeginScissorMode(0, 0, SCREEN_WIDTH, MENU_HEIGHT);
    ClearBackground(BLACK);

    DrawText("Score:", SCREEN_WIDTH * 0,
             MENU_HEIGHT * 0.1, 20, WHITE);
    DrawText(std::to_string(score).c_str(), SCREEN_WIDTH * 0.1,
             MENU_HEIGHT * 0.1, 20, WHITE);
    EndScissorMode();
}
void Game::drawFood(Vec2f snakePos, Vec2f snakeLastPos, Vec2f snakeTailPos[], int &length)
{
    std::srand(std::time(nullptr)); // Initialise random generator
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
            // If the random position on the grid doesn't contain the initial or the tail's position then put the food there. Else continue searching for a free spot
            foodPos.x = rand() % BLOCKS_IN_ROW - 1;
            foodPos.y = rand() % BLOCKS_IN_COLUMN - 1;
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

    // Draw food with the grid size
    DrawRectangle(foodPos.x * GRID_BLOCK_LENGTH,
                  MENU_HEIGHT + foodPos.y * GRID_BLOCK_LENGTH,
                  GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, BLUE);
}