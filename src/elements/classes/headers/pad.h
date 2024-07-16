#include "cpp_arkanoid_core.h"
#include "raylib.h"

class Pad
{
    struct PadBoundaries {
        float top;
        float right;
        float bottom;
        float left;
    };
    private:
        int width = 0;
        int height = 0;
        Color color = { 0 };
        Vector2 position = { 0 };
        bool isHoldingTheBall = true;
        ObjectBoundaries padBoundaries = { 0 };   // Clockwise direction, from top to left. 
    public:
        Pad(int padWidth, int padHeight, Color padColor, Vector2 padPosition, bool padIsHoldingTheBall)
        {
            width = padWidth; 
            height = padHeight;
            color = padColor;
            position = padPosition;
            isHoldingTheBall = padIsHoldingTheBall;

            // Semantic's wrong here, but it might work for now.
            padBoundaries.top = position.x + width;           // TOP
            padBoundaries.right = padBoundaries.top + height;     // RIGHT
            padBoundaries.bottom = padBoundaries.right - width;      // BOTTOM
            padBoundaries.left = position.x + height;          // LEFT
        };
        
        // Methods
        void drawPad();
        void updatePadPosition();

        // Getters
        Vector2 getPadPosition();
        Vector2 getPadSize();
        bool getIsHoldingTheBall();
        Vector4 getPadBoundaries();
        
        // Setters
        void setIsHoldingTheBall(bool value);
};
