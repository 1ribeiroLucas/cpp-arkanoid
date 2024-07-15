#include "raylib.h"

class Pad
{
    private:
        int width = 0;
        int height = 0;
        Color color = { 0 };
        Vector2 position = { 0 };
        bool isHoldingTheBall = true;
        Vector4 padBoundaries = { 0 };   // Clockwise direction, from top to left. 
    public:
        Pad(int padWidth, int padHeight, Color padColor, Vector2 padPosition, bool padIsHoldingTheBall)
        {
            width = padWidth; 
            height = padHeight;
            color = padColor;
            position = padPosition;
            isHoldingTheBall = padIsHoldingTheBall;

            padBoundaries.x = position.x + width;           // TOP
            padBoundaries.y = padBoundaries.x + height;     // RIGHT
            padBoundaries.z = padBoundaries.y - width;      // BOTTOM
            padBoundaries.w = position.x + height;          // LEFT
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
