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
        position.y = padPosition.y - 10;
    }
    else
    {

        // add the radius from the ball, because ball's position
        // are calculated by the center
        float ballTopBoundary = position.y - 10;
        float ballBottomBoundary = position.y + 10;
        float ballLeftBoundary = position.x - 10;
        float ballRightBoundary = position.x + 10;

        float wallWidth = 30;

        bool isBallTouchingPadTopBoundary = ballBottomBoundary >= padPosition.y
            && position.x >= padPosition.x && position.x <= (padPosition.x + padSize.x); 
        if (isBallTouchingPadTopBoundary || (ballTopBoundary <= wallWidth))
        {
            ballYAxisMovement *= -1;
        }

        if ((ballRightBoundary >= (GetScreenWidth() - wallWidth)) || (ballLeftBoundary <= wallWidth))
        {
            ballXAxisMovement *= -1;
        }


        position.x += ballXAxisMovement;
        position.y += ballYAxisMovement;
    }
}

bool Ball::didBallTouchTheBottomWall()
{
    if (position.y + 10 >= GetScreenHeight() - 30) return true;
    return false;
}