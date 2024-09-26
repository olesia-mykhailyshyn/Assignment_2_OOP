#include <cmath>
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

void Rectangle::drawRectangle(Board& board, int xPos, int y, int width, int height) {
    if (width <=0) { return;}
    if (height <=0) { return;}
    if (xPos < 0 || y < 0 || width < 1 || height < 1)

    this->x = xPos;
    this->y = y;
    this->width = width;
    this->height = height;

    rectRightXIndex = xPos + width - 1;
    rectLeftXIndex = xPos;
    rectBottomYIndex = y + height - 1;
    rectTopYIndex = y;
    drawAreaWidth = rectRightXIndex - rectLeftXIndex + 1;
    drawAreaHeight = rectBottomYIndex - rectTopYIndex + 1;

    for (int y = 0; y < drawAreaHeight; y++) {
        for (int x = 0; x < drawAreaWidth; x++) {
            if ((x + xPos >= rectLeftXIndex && x + xPos <= rectRightXIndex) &&
                (y + y >= rectTopYIndex && y + y <= rectBottomYIndex)) {
                if (y + y == rectTopYIndex || y + y == rectBottomYIndex ||
                    x + xPos == rectLeftXIndex || x + xPos == rectRightXIndex) {
                    board.grid[y + y][x + xPos] = '*';
                }
            }
        }
    }
}

void Circle::drawCircle(Board& board, int x, int y, int radius) {
    if (radius <=0) { return;}
    if (radius < 1 || x - radius < 0 || x + radius >= board.boardWidth ||
        y - radius < 0 || y + radius >= board.boardHeight) {
        std::cerr << "Invalid circle parameters!" << std::endl;
        return;
    }

    //for horisontal movement
    for (int i = 0; i <= 2 * radius; i++) {
        //for vertical movement
        for (int j = 0; j <= 2 * radius; j++ ) {
            dist = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
            // dist should be in the range (radius - 0.5)
            // and (radius + 0.5) to print stars(*)
            if (dist > radius - 0.5 && dist < radius + 0.5)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
}

void Line::drawLine(Board& board, int x, int y, int size) {
    if (size <= 0) return;
    for (int i = 0; i < size; ++i) {
        int drawX = x + i;
        if (drawX >= 0 && drawX < board.boardWidth && y >= 0 && y < board.boardHeight) {
            board.grid[y][drawX] = '*';
        }
    }
}