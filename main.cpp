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

    double time = GetTime();
    int speed = 1.f;

    game.reset();
    while (WindowShouldClose() == false)
    {
        snake.move();

        BeginDrawing();

        // In game tick
        if (snake.dir != snake.STOP && GetTime() >= time + game.refresh_rate)
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
            snake.tail[0] = snake.pos;
            snake.updateTail();
        }
        // HUD
        BeginScissorMode(0, 0, SCREEN_WIDTH, HUD_HEIGHT);
        ClearBackground(GOLD);
        DrawText("Score:", SCREEN_WIDTH * 0,
                 HUD_HEIGHT * 0.1, 20, BLACK);
        DrawText(to_string(game.score).c_str(), SCREEN_WIDTH * 0.1,
                 HUD_HEIGHT * 0.1, 20, BLACK);
        EndScissorMode();

        // Game grid
        BeginScissorMode(0, HUD_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT - HUD_HEIGHT);
        ClearBackground(BLACK);

        snake.draw();
        game.drawFood(snake.pos, snake.lastPos, snake.tail, snake.length);
        EndScissorMode();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}