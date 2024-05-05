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
#include "snake.hpp"
#include <iostream>
#include <ctime>
class Game
{
public:
    Game();
    void reset();

    int score;
    double refresh_rate = 0.2; // Level
    Vec2f foodPos;
    bool game_grid[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN];

    void drawFood(Vec2f snakePos, Vec2f snakeLastPos, Vec2f snakeTailPos[], int &length);
};

#endif