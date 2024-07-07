#include <iostream>
#include "raylib.h"

// I still need to figure out why it doesn't work
// when the classes are imported directly. Maybe it's
// because there is a header.
#include "src/elements/classes/headers/pad.h"
#include "src/elements/classes/headers/ball.h"
#include "src/elements/classes/headers/brick.h"

#include "src/utils/index.cpp"

// using namespace std;

int main()
{
    InitWindow(800, 800, "ArC++anoid");
    SetTargetFPS(60);

    int const ROWS = 5;
    int const COLUMNS = 5;
    Vector2 FIRST_BRICK_POSITION = {60, 60};

    Pad pad(100, 20, GOLD, {40, GetScreenHeight() - 70}, true);
    Ball ball({pad.getPadPosition().x + (pad.getPadSize().x / 2), pad.getPadPosition().y - 10}, 10, LIME);
    Brick brick;
    
    while (!WindowShouldClose())
    {
        if (pad.getIsHoldingTheBall() && IsKeyPressed(KEY_SPACE))
        {
            pad.setIsHoldingTheBall(false);
        }
        if (ball.didBallTouchTheBottomWall())
        {
            pad.setIsHoldingTheBall(true);
        }

        BeginDrawing();
        ClearBackground(WHITE);
        
        drawWalls();

        for (int row = 1; row < ROWS; row++)
        {
            for (int column = 1; column < COLUMNS; column++)
            {
                Vector2 brickPosition = {0};
                // std::cout << "row: " << row << std::endl;
                if (row == 1)
                {
                    brick.drawBrick(100, 20, MAROON, {FIRST_BRICK_POSITION.x *= column, FIRST_BRICK_POSITION.y});
                    std::cout << (FIRST_BRICK_POSITION.x) << FIRST_BRICK_POSITION.y << std::endl;
                }
            }
        }

        pad.drawPad();
        pad.updatePadPosition();
        
        ball.drawBall();
        ball.updateBallPosition(pad.getIsHoldingTheBall(), pad.getPadPosition(), pad.getPadSize());
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}