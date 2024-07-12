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
    InitWindow(600, 600, "ArC++anoid");
    SetTargetFPS(60);

    int const ROWS = 5;
    int const COLUMNS = 4;

    Vector2 positions = {180, 60};

    Pad pad(100, 20, GOLD, {40, GetScreenHeight() - 70}, true);
    Ball ball({pad.getPadPosition().x + (pad.getPadSize().x / 2), pad.getPadPosition().y - 10}, 10, LIME);
    Brick brick[COLUMNS][ROWS];

    Vector4 padBoundaries = pad.getPadBoundaries();

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

        DrawText(TextFormat("%i", padBoundaries.x), 50, 300, 24, BLACK);
        DrawText(TextFormat("%i", padBoundaries.y), 50, 332, 24, BLACK);
        DrawText(TextFormat("%i", padBoundaries.z), 50, 364, 24, BLACK);
        DrawText(TextFormat("%i", padBoundaries.w), 50, 418, 24, BLACK);

        drawWalls();

        for (int column = 0; column < COLUMNS; column++)
        {
            for (int row = 0; row < ROWS; row++)
            {
                // FIXME: Why does the column must be first?
                brick[column][row].drawBrick(RED, {(float)(120 * column) + 50.0f, (float)(GetScreenHeight() / 30.0f * row) + (row == 1 ? 30.0f : 40.f)});
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