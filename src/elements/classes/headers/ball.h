#include "raylib.h"
class Ball
{
    struct BallBoundaries {
        float topBoundary;
        float rightBoundary;
        float bottomBoundary;
        float leftBoundary;
    };

    private:
        float radius = 0;
        Color color = { 0 };
        Vector2 position = { 0 };
        BallBoundaries ballBoundaries = { 0 };

    public:
        Ball(Vector2 ball_position, float ball_radius, Color ball_color)
        {
            radius = ball_radius;
            position = ball_position;
            color = ball_color;
        };

        void drawBall();
        void updateBallPosition(Vector2 padPosition, Vector4 padBoundaries, Vector2 padSize, bool isPadHoldingTheBall);
        bool didBallTouchTheBottomWall();
};