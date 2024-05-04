#pragma once
#ifndef GAME_H
#define GAME_H
#define BLOCKS_IN_ROW (int)(SCREEN_WIDTH / GRID_BLOCK_LENGTH)
#define BLOCKS_IN_COLUMN (int)(GAME_HEIGHT / GRID_BLOCK_LENGTH)
#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (800)
#define GRID_BLOCK_LENGTH (20)
#define HUD_HEIGHT (200)
#define GAME_HEIGHT (SCREEN_HEIGHT - HUD_HEIGHT)
#include "vec2f.hpp"
class Game
{
public:
    Game();
    void reset();

    // Game(int rows, int columns);
    int score;
    Vec2f foodPos;
    // int rowBlocks, columnBlocks;
    bool game_grid[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN];
};

#endif