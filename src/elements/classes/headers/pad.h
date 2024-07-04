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
        Pad(int pad_width, int pad_height, Color pad_color, Vector2 pad_position, bool pad_isHoldingTheBall)
        {
            width = pad_width; 
            height = pad_height;
            color = pad_color;
            position = pad_position;
            isHoldingTheBall = pad_isHoldingTheBall;
        };
        
        void drawPad();
        void updatePadPosition();
        Vector2 getPadPosition();
        Vector2 getPadSize();
        bool getIsHoldingTheBall();
        void setIsHoldingTheBall(bool value);
};
