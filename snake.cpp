#include "snake.hpp"

Snake::Snake()
{
    length = 2;
    dir = this->STOP;
    pos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
    tail[0] = pos;
    tail[1] = Vec2f(pos.x + 1, pos.y);
}

void Snake::draw()
{
    // Draw Snake and borders
    DrawRectangle(pos.x * GRID_BLOCK_LENGTH,
                  MENU_HEIGHT + pos.y * GRID_BLOCK_LENGTH,
                  GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, GOLD);
    DrawRectangleLines(pos.x * GRID_BLOCK_LENGTH,
                       MENU_HEIGHT + pos.y * GRID_BLOCK_LENGTH,
                       GRID_BLOCK_LENGTH, GRID_BLOCK_LENGTH, DARKBROWN);
    // Draw tail
    for (int i = 0; i < length; i++)
    {
        DrawRectangleLines(tail[i].x * GRID_BLOCK_LENGTH,
                           MENU_HEIGHT + tail[i].y * GRID_BLOCK_LENGTH,
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
bool Snake::checkCollision()
{
    // Search for head-tail collision
    if (length > 3)
    {
        for (int i = 2; i < length; ++i)
        {
            if (tail[0].x == tail[i].x && tail[0].y == tail[i].y)
            {
                reset();
                return true;
            }
        }
    }
    return false;
}
void Snake::move(double refresh_rate, int step, double &time, bool &r)
{
    // Change the direction value according to the arrow key pressed
    /*
        The snake can start in any direction.
        When going in any given axis(x or y), it can only move in the other axis and cannot move in the opposite direction
        For example when going left, the only options are up or down.
    */
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
    // Movement in game
    if (dir != STOP && GetTime() >= time + refresh_rate)
    {
        time = GetTime();

        lastPos = pos; // Remove comment
        switch (dir)
        {
        case STOP:
            break;
        case LEFT:
            if (pos.x == 0)
            {
                r = true;
                reset();
            }
            else
                pos.x -= step;
            break;
        case RIGHT:
            if (pos.x == BLOCKS_IN_ROW - 1)
            {
                r = true;
                reset();
            }
            else
                pos.x += step;
            break;
        case UP:
            if (pos.y == 0)
            {
                r = true;
                reset();
            }
            else
                pos.y -= step;
            break;
        case DOWN:
            if (pos.y == BLOCKS_IN_COLUMN - 1)
            {
                r = true;
                reset();
            }
            else
                pos.y += step;
            break;
        }
        tail[0] = pos;
        // Update the tail's length, position and check for collisions
        updateTail();
        checkCollision();
        if (checkCollision())
        {
            r = true;
            reset();
        }
    }
}

void Snake::reset() // Same variable's values as the constructor
{
    length = 2;
    dir = this->STOP;
    pos = Vec2f(BLOCKS_IN_ROW / 2, BLOCKS_IN_COLUMN / 2);
    tail[0] = pos;
    tail[1] = Vec2f(pos.x + 1, pos.y);
}