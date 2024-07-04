#include <iostream>

#include "raylib.h"
#include "headers/ball.h"

using namespace std;

int ballXAxisMovement = 3;
int ballYAxisMovement = 3;

void Ball::drawBall()
{
    DrawCircle(position.x, position.y, radius, color);
}

void Ball::updateBallPosition(bool isBallBeingHeld, Vector2 padPosition, Vector2 padSize)
{

    if (isBallBeingHeld)
    {
        position.x = padPosition.x + (padSize.x / 2);
    }
    else
    {
        // FIXME: The ball doesn't go beyond the pad, therefore never touching the bottom
        // The collision calculation needs to be fixed
        // add the radius from the ball, because the positions in the ball
        // are based on the center
        if (((position.y + 10) >= padPosition.y) || ((position.y - 10) <= 30))
        {
            ballYAxisMovement *= -1;
        }

        if ((position.x + 10) >= (GetScreenWidth() - 30) || ((position.x - 10) <= 30))
        {
            ballXAxisMovement *= -1;
        }


        position.x += ballXAxisMovement;
        position.y += ballYAxisMovement;
    }
}

bool Ball::didBallTouchTheBottomWall()
{
    return false;
}