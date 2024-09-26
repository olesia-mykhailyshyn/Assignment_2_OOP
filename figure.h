#pragma once
#include <string>
#include "board.h"

class Figure {
public:
    virtual void draw(Board& board) const = 0;

protected:
};

class Triangle: public Figure {
public:
    static void drawTriangle(Board& board, int x, int y, int height);
};

class Rectangle: public Figure {
public:
    Rectangle() : x(0), y(0), width(0), height(0), rectRightXIndex(0), rectLeftXIndex(0),
                  rectBottomYIndex(0), rectTopYIndex(0), drawAreaWidth(0), drawAreaHeight(0) {}

    void drawRectangle(Board& board, int x, int y, int width, int height);
private:
    int x;
    int y;
    int width;
    int height;
    int rectRightXIndex;
    int rectLeftXIndex;
    int rectBottomYIndex;
    int rectTopYIndex;
    int drawAreaWidth;
    int drawAreaHeight;
};

class Circle: public Figure {
public:
    void drawCircle(Board& board, int x, int y, int radius);
private:
    float dist; //distance to the centre
};

class Line: public Figure {
public:
    void drawLine(Board& board, int x, int y, int size);
private:
};