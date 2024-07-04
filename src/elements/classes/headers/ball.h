#include "raylib.h"

class Ball
{
    private:
        float radius = 0;

        Color color = { 0 };
        Vector2 position = { 0 };
    public:
        Ball(Vector2 ball_position, float ball_radius, Color ball_color)
        {
            radius = ball_radius;
            position = ball_position;
            color = ball_color;
        };

        void drawBall();
        void updateBallPosition(bool isBallBeingHeld, float padXPosition = 0);
        bool didBallTouchTheBottomWall();
};