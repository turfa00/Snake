#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include "vec2f.hpp"
#include "game.hpp"
#include "raylib.h"
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

    void move(double refresh_rate, int step, double &time, bool &r);
    void draw();
    void updateTail();
    bool checkCollision();
    void reset();
};

#endif