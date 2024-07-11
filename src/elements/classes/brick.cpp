#include "raylib.h"
#include "headers/brick.h"

void Brick::drawBrick(Color brickColor, Vector2 brickPosition)
{
    m_color = brickColor;
    m_position = brickPosition;
    
    DrawRectangle(brickPosition.x, brickPosition.y, m_width, m_height, brickColor);
}

void Brick::isBrickTouchedByTheBall(Vector2 ballPosition)
{};

Vector2 Brick::getBrickPosition()
{
    return m_position;
}