#include <iostream>
// #include <raylib.h>
#include "raylib.h"
#include "snake.hpp"
#include "game.hpp"
// #include "C:/raylib/raylib/src/raylib.h"

int main()
{
    Game game;
    Snake snake;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");
    SetTargetFPS(60);

    double time = GetTime(); // Get Time for the game for refresh value (Game speed)
    game.reset();            // Reset all values and the snake
    while (WindowShouldClose() == false)
    {
        snake.move(game.refresh_rate, game.step, time, game.r);
        BeginDrawing();
        if (game.r)
        {
            game.reset();
        }
        // Game menu
        game.drawMenu();

        // Playing screen
        BeginScissorMode(0, MENU_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT - MENU_HEIGHT);
        ClearBackground(BLACK);

        snake.draw();
        game.drawFood(snake.pos, snake.lastPos, snake.tail, snake.length);
        EndScissorMode();
        EndDrawing();
    }
    // Close rayLib and application
    CloseWindow();
    return 0;
}