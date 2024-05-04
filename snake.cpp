#include "snake.hpp"
#include "raylib.h"

Snake::Snake()
{
    length = 2;
    dir = this->STOP;
    pos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
    lastPos = Vec2f(pos.x + 1, pos.y);
}

void Snake::draw()
{
    for (int i = 0; i < length; i++)
    {
    }
}
void Snake::move()
{
    switch (this->dir)
    {
    case STOP:
        if (IsKeyPressed(KEY_LEFT))
        {
            dir = LEFT;
        }
        else if (IsKeyPressed(KEY_RIGHT))
        {
            dir = RIGHT;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            dir = UP;
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            dir = DOWN;
        }
        break;
    case LEFT:
        dir = LEFT;
        if (IsKeyPressed(KEY_UP))
        {
            dir = UP;
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            dir = DOWN;
        }
        break;
    case RIGHT:
        dir = RIGHT;
        if (IsKeyPressed(KEY_UP))
        {
            dir = UP;
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            dir = DOWN;
        }
        break;
    case UP:
        dir = UP;
        if (IsKeyPressed(KEY_LEFT))
        {
            dir = LEFT;
        }
        else if (IsKeyPressed(KEY_RIGHT))
        {
            dir = RIGHT;
        }
        break;
    case DOWN:
        dir = DOWN;
        if (IsKeyPressed(KEY_LEFT))
        {
            dir = LEFT;
        }
        else if (IsKeyPressed(KEY_RIGHT))
        {
            dir = RIGHT;
        }
        break;
    }
}

void Snake::reset()
{
    length = 2;
    dir = this->STOP;
    pos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
    lastPos = Vec2f(pos.x + 1, pos.y);
}