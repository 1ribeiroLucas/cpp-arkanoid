#include "raylib.h"

class Pad
{
    private:
        int width = 0;
        int height = 0;
        Color color = { 0 };
        Vector2 position = { 0 };
        bool isHoldingTheBall = true;
    public:
        Pad(int padWidth, int padHeight, Color padColor, Vector2 padPosition, bool padIsHoldingTheBall)
        {
            width = padWidth; 
            height = padHeight;
            color = padColor;
            position = padPosition;
            isHoldingTheBall = padIsHoldingTheBall;
        };
        
        void drawPad();
        void updatePadPosition();
        Vector2 getPadPosition();
        Vector2 getPadSize();
        bool getIsHoldingTheBall();
        void setIsHoldingTheBall(bool value);
};
