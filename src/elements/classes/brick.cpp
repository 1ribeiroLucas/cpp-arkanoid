#include "raylib.h"
#include "headers/brick.h"

void Brick::drawBrick(int brickWidth, int brickHeight, Color brickColor, Vector2 brickPosition)
{
    width = brickWidth;
    height = brickHeight;
    color = brickColor;
    position = brickPosition;
    
    DrawRectangle(brickPosition.x, brickPosition.y, brickWidth, brickHeight, brickColor);
}

void Brick::isBrickTouchedByTheBall(Vector2 ballPosition)
{};