#include "raylib.h"
#include "headers/ball.h"

void Ball::drawBall()
{
    DrawCircle(position.x, position.y, radius, color);
}

void Ball::updateBallPosition(bool isBallBeingHeld, float padXPosition)
{
    if (isBallBeingHeld)
    {
        position.x = padXPosition;
    }
}

bool Ball::didBallTouchTheBottomWall()
{
    return false;
}