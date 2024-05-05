#include "snake.hpp"

Snake::Snake()
{
    length = 2;
    dir = this->STOP;
    pos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
    // lastPos = Vec2f(pos.x + 1, pos.y);
    tail[0] = pos;
    tail[1] = Vec2f(pos.x + 1, pos.y);
}

void Snake::draw()
{
    // Draw Snake
    DrawRectangleLines(pos.x * GRID_BLOCK_LENGTH,
                       HUD_HEIGHT + pos.y * GRID_BLOCK_LENGTH,
                       GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, DARKBROWN);
    for (int i = 0; i < length; i++)
    {
        DrawRectangleLines(tail[i].x * GRID_BLOCK_LENGTH,
                           HUD_HEIGHT + tail[i].y * GRID_BLOCK_LENGTH,
                           GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, DARKBROWN);
    }
}
void Snake::updateTail()
{
    // Update tail
    for (int i = length; i >= 0; --i)
    {
        if (i == 0)
        {
            tail[i] = pos;
        }
        else
        {
            tail[i] = tail[i - 1];
        }
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
    tail[0] = pos;
    tail[1] = Vec2f(pos.x + 1, pos.y);
}