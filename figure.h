#pragma once
#include <string>
#include "board.h"

class Figure {
public:

protected:
};

class Triangle: public Figure {
public:
    static void drawTriangle(Board& board, int x, int y, int height);
};

class Rectangle: public Figure {
public:
    Rectangle() : xPos(0), yPos(0), width(0), height(0), rectRightXIndex(0), rectLeftXIndex(0),
              rectBottomYIndex(0), rectTopYIndex(0), drawAreaWidth(0), drawAreaHeight(0) {}

    void drawRectangle(Board& board, int xPos, int yPos, int width, int height);
private:
    int xPos;
    int yPos;
    int width;
    int height;
    int rectRightXIndex;
    int rectLeftXIndex;
    int rectBottomYIndex;
    int rectTopYIndex;
    int drawAreaWidth;
    int drawAreaHeight;
};