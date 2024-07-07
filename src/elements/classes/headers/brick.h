#include "raylib.h"

class Brick
{
    private:
        int width = 0;
        int height = 0;
        Color color = { 0 };
        Vector2 position = { 0 };
        bool isBrickDestroyed = false;
    public:
        Brick() {};

        void drawBrick(int brickWidth, int brickHeight, Color brickColor, Vector2 brickPosition);
        void isBrickTouchedByTheBall(Vector2 ballPosition);


};