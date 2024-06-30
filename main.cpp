#include "raylib.h"

// Se a classe for importada, dá erro de duplicação de declaração
// na compilação.
#include "src/elements/classes/headers/pad.h"

int main()
{

    InitWindow(800, 800, "ArC++anoid");
    SetTargetFPS(60);

    Pad pad(100, 30, VIOLET, {30, 500}, true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        pad.drawPad();
        pad.updatePadPosition();
        // DrawTriangle(top-vertex, right-vertex, left-vertex)
        // DrawTriangle({100, 10}, {10, 100}, {200, 100}, MAROON);
        // DrawCircle(160, 160, 64, PURPLE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}