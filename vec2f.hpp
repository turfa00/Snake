#pragma once
#ifndef VEC2_H
#define VEC2_H

class Vec2f
{
public:
    Vec2f();
    Vec2f(float xx, float yy);

    float getX();
    float getY();

    void setX(float xx);
    void setY(float yy);

    float x, y, z;
};

#endif