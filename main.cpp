#include "raylib.h"

// I still need to figure out why it doesn't work
// when the classes are imported directly. Maybe it's
// because there is a header.
#include "src/elements/classes/headers/pad.h"
#include "src/elements/classes/headers/ball.h"

#include "src/utils/index.cpp"

int main()
{
    InitWindow(800, 800, "ArC++anoid");
    SetTargetFPS(60);

    Pad pad(100, 20, GOLD, {40, GetScreenHeight() - 70}, true);
    Ball ball({pad.getPadPosition().x + (pad.getPadSize().x / 2), pad.getPadPosition().y - 10}, 10, LIME);
    
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

        pad.drawPad();
        pad.updatePadPosition();
        
        ball.drawBall();
        ball.updateBallPosition(pad.getIsHoldingTheBall(), pad.getPadPosition(), pad.getPadSize());
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}