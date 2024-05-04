#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include "vec2f.hpp"
#include "game.hpp"
class Snake
{
public:
    Snake();
    Vec2f pos, lastPos;
    Vec2f tail[80];
    int length;

    enum direction
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    direction dir;

    void move();
    void draw();
    void reset();
};

#endif