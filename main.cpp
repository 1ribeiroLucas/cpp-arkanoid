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
    // Ball ball({(float)(GetScreenHeight() - 100), (float)(pad.getPadPosition().y) + (float)(pad.getPadSize().x / 2)}, 30, LIME);
    Ball ball({pad.getPadPosition().x + (pad.getPadSize().x / 2), pad.getPadPosition().y - 10}, 10, LIME);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        drawWalls();

        pad.drawPad();
        
        if (pad.getIsHoldingTheBall())
        {
            ball.drawBall();
        }
        pad.updatePadPosition();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}