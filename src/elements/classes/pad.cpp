#include "raylib.h"
#include "headers/pad.h"

bool Pad::isPadTouchingBoundaries()
{
    bool isTouching = false;
    
    if ((position.x <= 1) || (position.x + width) == GetScreenWidth())
    {
        isTouching = true;
    }
    
    return isTouching;
}

void Pad::drawPad()
{
    DrawRectangle(position.x, position.y, width, height, color);
}

void Pad::updatePadPosition()
{
    bool isTouchingLeftBoundary = position.x <= 1;
    bool isTouchingRightBoundary = position.x + width >= GetScreenWidth();

    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && !isTouchingLeftBoundary)
    {
        position.x -= 5;
    }

    if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && !isTouchingRightBoundary)
    {
        position.x += 5;
    }
}
