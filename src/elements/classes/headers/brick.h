#include "raylib.h"

class Brick
{
    private:
        //  The "m" stands for "member", therefore represeting
        //  a private property of the class.
        int m_width = 100;
        int m_height = 20;
        Color m_color = { 0 };
        Vector2 m_position = { 0 };
        bool m_isBrickDestroyed = false;
    public:
        Brick() {};

        void drawBrick(Color brickColor, Vector2 brickPosition);
        void isBrickTouchedByTheBall(Vector2 ballPosition);
        Vector2 getBrickPosition();


};