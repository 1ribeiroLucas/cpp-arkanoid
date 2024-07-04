#include "raylib.h"

// Se a classe for importada, dá erro de duplicação de declaração
// na compilação.
#include "src/elements/classes/headers/pad.h"

#include "src/utils/index.cpp"

int main()
{
    InitWindow(800, 800, "ArC++anoid");
    SetTargetFPS(60);

    Pad pad(100, 30, GOLD, {40, GetScreenHeight() - 70}, true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        drawWalls();

        pad.drawPad();
        pad.updatePadPosition();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}