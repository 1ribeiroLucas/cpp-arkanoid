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

void Ball::updateBallPosition(Vector2 padPosition, ObjectBoundaries padBoundaries, Vector2 padSize, bool isPadHoldingTheBall)
{
    if (isPadHoldingTheBall)
    {
        position.x = padPosition.x + (padSize.x / 2);
        position.y = padPosition.y - 10;
    }
    else
    {

        // add the radius from the ball, because ball's position
        // are calculated from the center
        ballBoundaries.top = position.y - 10;
        ballBoundaries.right = position.x + 10;
        ballBoundaries.bottom = position.y + 10;
        ballBoundaries.left  = position.x - 10;

        float wallWidth = 30;

        bool isBallCollidingWithPadTop = ballBoundaries.bottom >= padPosition.y && position.x <= padBoundaries.top
            && position.x >= padPosition.x;

        if (isBallCollidingWithPadTop || (ballBoundaries.top <= wallWidth))
        {
            ballYAxisMovement *= -1;
        }

        if ((ballBoundaries.right >= (GetScreenWidth() - wallWidth)) || (ballBoundaries.left <= wallWidth))
        {
            ballXAxisMovement *= -1;
        }


        position.x += ballXAxisMovement;
        position.y += ballYAxisMovement;
    }

    DrawText(TextFormat("position.x: %02.0f", position.x), 50, 330, 24, BLACK);
    DrawText(TextFormat("position.y: %02.0f", position.y), 50, 360, 24, BLACK);
    DrawText(TextFormat("ballBoundaries.bottom: %02.0f", ballBoundaries.bottom), 50, 390, 24, BLACK);
    DrawText(TextFormat("padBoundaries.top: %02.0f", padBoundaries.top), 50, 420, 24, BLACK);
    DrawText(TextFormat("padPosition.x: %02.0f", padPosition.x), 50, 450, 24, BLACK);
    DrawText(TextFormat("padPosition.y: %02.0f", padPosition.y), 50, 480, 24, BLACK);
}

bool Ball::didBallTouchTheBottomWall()
{
    if (position.y + 10 >= GetScreenHeight() - 30) return true;
    return false;
}
