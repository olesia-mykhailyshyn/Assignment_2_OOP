#include "board.h"
#include "figure.h"

int main() {
    Board board;
    Triangle::drawTriangle(board,10,5,5);
    Rectangle rectangle;
    rectangle.drawRectangle(board, 20, 20, 8, 4);
    board.print();
    return 0;
}