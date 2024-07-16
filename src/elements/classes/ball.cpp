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

void Ball::updateBallPosition(Vector2 padPosition, Vector4 padBoundaries, Vector2 padSize, bool isPadHoldingTheBall)
{
    if (isPadHoldingTheBall)
    {
        position.x = padPosition.x + (padSize.x / 2);
        position.y = padPosition.y - 10;
        // position.x = padBoundaries.x + (padBoundaries.y / 2);
        // position.y = padBoundaries.z - 10;
    }
    else
    {

        // add the radius from the ball, because ball's position
        // are calculated by the center
        ballBoundaries.topBoundary = position.y - 10;
        ballBoundaries.rightBoundary = position.x + 10;
        ballBoundaries.bottomBoundary = position.y + 10;
        ballBoundaries.leftBoundary  = position.x - 10;

        float wallWidth = 30;

        // bool isBallCollidingWithPadTop = ballBoundaries.bottomBoundary >= padBoundaries

        // bool isBallTouchingPadTopBoundary = ballBottomBoundary >= padBoundaries.x
        //     && position.x >= padBoundaries.x && position.x <= (padBoundaries.x + padPosition.x); 
        // if (isBallTouchingPadTopBoundary || (ballTopBoundary <= wallWidth))
        // {
        //     ballYAxisMovement *= -1;
        // }

        // if ((ballRightBoundary >= (GetScreenWidth() - wallWidth)) || (ballLeftBoundary <= wallWidth))
        // {
        //     ballXAxisMovement *= -1;
        // }


        position.x += ballXAxisMovement;
        position.y += ballYAxisMovement;
    }
}

bool Ball::didBallTouchTheBottomWall()
{
    if (position.y + 10 >= GetScreenHeight() - 30) return true;
    return false;
}