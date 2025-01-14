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

    int const ROWS = 3;
    int const COLUMNS = 6;

    Vector2 positions = {180, 60};

    Pad pad(100, 20, GOLD, {40, GetScreenHeight() - 70}, true);
    Ball ball({pad.getPadPosition().x + (pad.getPadSize().x / 2), pad.getPadPosition().y - 10}, 10, LIME);
    Brick brick[COLUMNS][ROWS];

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
        // ====================================================================================================
        ClearBackground(DARKGRAY);

        drawWalls();

        // brick[0].drawBrick(RED, {(float)60 * (rowLoop + 2), 60});

        for (int column = 0; column < COLUMNS; column++)
        {
            for (int row = 0; row < ROWS; row++)
            {
                // brick[column][row].drawBrick(RED, {(float)(120 * column) + 50.0f, (float)(60 * row) + (row == 0 ? 30.0f : 0)});
                // brick[column][row].drawBrick(RED, {(float)(120 * column) + 50.0f, (float)(GetScreenHeight() / 30.0f * row) + 30.0f});
                brick[column][row].drawBrick(RED, {(float)(120 * column) + 50.0f, (float)(GetScreenHeight() / 30.0f * row) + 30.0f});


            }
        }

        pad.drawPad();
        pad.updatePadPosition();

        ball.drawBall();
        ball.updateBallPosition(pad.getIsHoldingTheBall(), pad.getPadPosition(), pad.getPadSize());
        // ====================================================================================================
        EndDrawing();
    }

    CloseWindow();
    return 0;
}