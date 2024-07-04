#include "raylib.h"

void drawWalls(Color wallColor = VIOLET)
{
    DrawRectangle(0, 0, GetScreenWidth(), 30, wallColor);                       // TOP
    DrawRectangle(GetScreenWidth() - 30, 0, 30, GetScreenHeight(), wallColor);  // RIGHT
    DrawRectangle(0, GetScreenHeight() - 30, GetScreenWidth(), 30, wallColor);  // BOTTOM
    DrawRectangle(0, 0, 30, GetScreenHeight(), wallColor);                      // LEFT
}