#include "raylib.h"
#include "headers/pad.h"

bool Pad::isPadTouchingBoundaries()
{
    bool isTouching = false;
    if ((position.x = 1))
    {
        isTouching = true;
    }

    // FIXME: 800 é o número mágico da largura da janela
    // Refatorar para considerar a parede (Wall) quando for implementada.
    if ((position.x + width) == 800)
    {
        isTouching = true;
    }
    
    return isTouching;
}

void Pad::drawPad()
{
    DrawRectangle(position.x, position.y, width, height, color);
}

void Pad::updatePadPosition()
{
    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && !isPadTouchingBoundaries())
    {
        position.x -= 1;
    }

    if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && !isPadTouchingBoundaries())
    {
        position.x += 1;
    }
}
