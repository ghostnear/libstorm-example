#ifndef GAME_RECTANGLE_HPP
#define GAME_RECTANGLE_HPP

struct Vec2
{
    int x;
    int y;
};

struct Rect
{
    Vec2 pos;
    Vec2 size;
};

struct FVec2
{
    double x;
    double y;
};

struct FRect
{
    FVec2 pos;
    FVec2 size;
};

#endif