#include "raylib.h"
#include "headers/pad.h"

/**
 * METHODS
 */
void Pad::drawPad()
{
    DrawRectangle(position.x, position.y, width, height, color);
}

void Pad::updatePadPosition()
{
    // 30 = Wall's width
    bool isTouchingLeftBoundary = position.x <= 30;
    bool isTouchingRightBoundary = position.x + width >= GetScreenWidth() - 30;

    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && !isTouchingLeftBoundary)
    {
        position.x -= 5;
    }

    if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && !isTouchingRightBoundary)
    {
        position.x += 5;
    }

    padBoundaries.top = position.x + width;           // TOP
    padBoundaries.right = padBoundaries.top + height;     // RIGHT
    padBoundaries.bottom = padBoundaries.right - width;      // BOTTOM
    padBoundaries.left = position.x + height;          // LEFT
}


/**
 * GETTERS
 */
Vector2 Pad::getPadPosition()
{
    return position;
}

Vector2 Pad::getPadSize()
{
    // FIXME: convert width and height to float
    return {(float)width, (float)height};
}

bool Pad::getIsHoldingTheBall()
{
    return isHoldingTheBall;
}

ObjectBoundaries Pad::getPadBoundaries()
{
    return padBoundaries;
}

/**
 * SETTERS
 */
void Pad::setIsHoldingTheBall(bool value)
{
    isHoldingTheBall = value;
}
