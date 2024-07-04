#include "raylib.h"

// Se a classe for importada, dá erro de duplicação de declaração
// na compilação.
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