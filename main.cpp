#include <iostream>
// #include <raylib.h>
#include "raylib.h"
#include "snake.hpp"
#include "game.hpp"
// #include "C:/raylib/raylib/src/raylib.h"
using namespace std;

#define NDEBUG

#define MAX_QUEUE_SIZE (BLOCKS_IN_ROW * BLOCKS_IN_COLUMN)

int main()
{
    Game game;
    Snake snake;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");
    SetTargetFPS(60);

    double refresh_rate = 0.2;
    double time = GetTime();
    int speed = 1.f;

    game.reset();
    while (WindowShouldClose() == false)
    {
        snake.move();

        BeginDrawing();

        // In game tick
        if (snake.dir != snake.STOP && GetTime() >= time + refresh_rate)
        {
            time = GetTime();
            snake.lastPos = snake.pos;
            switch (snake.dir)
            {
            case snake.STOP:
                break;
            case snake.LEFT:
                if (snake.pos.x == 0)
                {
                    game.reset();
                    snake.reset();
                }
                else
                    snake.pos.x -= speed;
                break;
            case snake.RIGHT:
                if (snake.pos.x == BLOCKS_IN_ROW - 1)
                {
                    game.reset();
                    snake.reset();
                }
                else
                    snake.pos.x += speed;
                break;
            case snake.UP:
                if (snake.pos.y == 0)
                {
                    game.reset();
                    snake.reset();
                }
                else
                    snake.pos.y -= speed;
                break;
            case snake.DOWN:
                if (snake.pos.y == BLOCKS_IN_COLUMN - 1)
                {
                    game.reset();
                    snake.reset();
                }
                else
                    snake.pos.y += speed;
                break;
            }
        }

        // HUD
        BeginScissorMode(0, 0, SCREEN_WIDTH, HUD_HEIGHT);
        ClearBackground(GOLD);
        EndScissorMode();

        // Game grid
        BeginScissorMode(0, HUD_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT - HUD_HEIGHT);
        ClearBackground(BLACK);
        // Draw Snake
        DrawRectangleLines(snake.pos.x * GRID_BLOCK_LENGTH,
                           HUD_HEIGHT + snake.pos.y * GRID_BLOCK_LENGTH,
                           GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, DARKBROWN);

        // Draw Tail
        for (int i = 0; i < snake.length; i++)
        {
            DrawRectangleLines(snake.lastPos.x * GRID_BLOCK_LENGTH,
                               HUD_HEIGHT + snake.lastPos.y * GRID_BLOCK_LENGTH,
                               GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, DARKBROWN);
        }

        EndScissorMode();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}