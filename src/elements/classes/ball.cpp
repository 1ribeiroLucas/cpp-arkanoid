#include "raylib.h"
#include "headers/ball.h"

void Ball::drawBall()
{
    DrawCircle(position.x, position.y, radius, color);
}

void Ball::updateBallPosition()
{
}

bool Ball::didBallTouchTheBottomWall()
{
    return false;
}