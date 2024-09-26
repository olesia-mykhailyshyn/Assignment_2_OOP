#include "board.h"
#include "figure.h"

int main() {
    Board board;
    Triangle::drawTriangle(board,10,5,5);
    Rectangle rectangle;
    rectangle.drawRectangle(board, 20, 20, 8, 4);
    Circle circle;
    circle.drawCircle(board, 3,3,3);
    Line line;
    line.drawLine(board, 9,13,9);
    board.print();
    return 0;
}