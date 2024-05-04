#include <iostream>
#include "vec2f.hpp"

Vec2f::Vec2f()
{
}

Vec2f::Vec2f(float xx, float yy)
{
    x = xx;
    y = yy;
}

float Vec2f::getX()
{
    return x;
}

float Vec2f::getY()
{
    return y;
}

void Vec2f::setX(float xx)
{
    x = xx;
}

void Vec2f::setY(float yy)
{
    y = yy;
}