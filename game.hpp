#pragma once
#ifndef GAME_H
#define GAME_H
#define BLOCKS_IN_ROW (int)(SCREEN_WIDTH / GRID_BLOCK_LENGTH)
#define BLOCKS_IN_COLUMN (int)(GAME_HEIGHT / GRID_BLOCK_LENGTH)
#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (800)
#define GRID_BLOCK_LENGTH (30)
#define MENU_HEIGHT (50)
#define GAME_HEIGHT (SCREEN_HEIGHT - MENU_HEIGHT)
#include "vec2f.hpp"
#include "snake.hpp"
// #include "raylib.h"
#include <iostream>
#include <ctime>
class Game
{
public:
    Game();
    int score;
    int distance;        // The snake moves one grid at a time
    double refresh_rate; // Corresponds to the level --> A small value means the game refresh at a faster rate so the snake will move faster --> It goes faster with score
    Vec2f foodPos;
    bool r;

    void drawFood(Vec2f snakePos, Vec2f snakeLastPos, Vec2f snakeTailPos[], int &length);
    void drawMenu();
    void reset(); // Reset the snake
};

#endif