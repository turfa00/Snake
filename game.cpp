#include "game.hpp"

Game::Game()
{
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