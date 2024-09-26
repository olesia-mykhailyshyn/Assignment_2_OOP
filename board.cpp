#include "board.h"

void Board:: print() const {
    for (const std::vector<char>& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}

void Board::drawTriangle(int x, int y, int height) {
    if (height <= 0) return; // height must be positive and sensible

    for (int i = 0; i < height; ++i) {
        int leftMost = x - i;  // starting left position
        int rightMost = x + i; // ending right position
        int posY = y + i;      // vertical position

        // draw the edges/border of the triangle
        if (posY < boardHeight) {
            if (leftMost >= 0 && leftMost < boardWidth) {
                grid[posY][leftMost] = '*';  // draw the leftmost point
            }
            if (rightMost >= 0 && rightMost < boardWidth && leftMost != rightMost) {
                grid[posY][rightMost] = '*';  // draw the rightmost point
            }
        }
    }

    // draw the base of the triangle
    for (int j = 0; j < 2 * height - 1; ++j) {
        int baseX = x - height + 1 + j;
        int baseY = y + height - 1;
        if (baseX >= 0 && baseX < boardWidth && baseY < boardHeight) {
            grid[baseY][baseX] = '*';
        }
    }
}