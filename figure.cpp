#include "figure.h"
#include "board.h"

void Triangle::drawTriangle(Board& board, int x, int y, int height) {
    if (height <= 0) return; // height must be positive and sensible

    for (int i = 0; i < height; ++i) {
        int leftMost = x - i;  // starting left position
        int rightMost = x + i; // ending right position
        int posY = y + i;      // vertical position

        // draw the edges/border of the triangle
        if (posY < board.boardHeight) {
            if (leftMost >= 0 && leftMost < board.boardWidth) {
                board.grid[posY][leftMost] = '*';  // draw the leftmost point
            }
            if (rightMost >= 0 && rightMost < board.boardWidth && leftMost != rightMost) {
                board.grid[posY][rightMost] = '*';  // draw the rightmost point
            }
        }
    }

    // draw the base of the triangle
    for (int j = 0; j < 2 * height - 1; ++j) {
        int baseX = x - height + 1 + j;
        int baseY = y + height - 1;
        if (baseX >= 0 && baseX < board.boardWidth && baseY < board.boardHeight) {
            board.grid[baseY][baseX] = '*';
        }
    }
}

void Rectangle::drawRectangle(Board& board, int xPos, int yPos, int width, int height) {
    if (xPos < 0 || yPos < 0 || width < 1 || height < 1)

    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;

    rectRightXIndex = xPos + width - 1;
    rectLeftXIndex = xPos;
    rectBottomYIndex = yPos + height - 1;
    rectTopYIndex = yPos;
    drawAreaWidth = rectRightXIndex - rectLeftXIndex + 1;
    drawAreaHeight = rectBottomYIndex - rectTopYIndex + 1;

    for (int y = 0; y < drawAreaHeight; y++) {
        for (int x = 0; x < drawAreaWidth; x++) {
            if ((x + xPos >= rectLeftXIndex && x + xPos <= rectRightXIndex) &&
                (y + yPos >= rectTopYIndex && y + yPos <= rectBottomYIndex)) {
                if (y + yPos == rectTopYIndex || y + yPos == rectBottomYIndex ||
                    x + xPos == rectLeftXIndex || x + xPos == rectRightXIndex) {
                    board.grid[y + yPos][x + xPos] = '*';
                }
            }
        }
    }
}