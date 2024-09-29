#include <cmath>
#include "figure.h"
#include "board.h"

void Triangle::draw(Board& board) {
    if (height <= 0) return; // height must be positive and sensible

    for (int i = 0; i < height; ++i) {
        int leftMost = x - i;  // starting left position
        int rightMost = x + i; // ending right position
        int posY = y + i;      // vertical position

        if (posY < board.boardHeight) {
            if (leftMost >= 0 && leftMost < board.boardWidth) {
                board.grid[posY][leftMost] = '*';  // draw the leftmost point
            }
            if (rightMost >= 0 && rightMost < board.boardWidth && leftMost != rightMost) {
                board.grid[posY][rightMost] = '*';  // draw the rightmost point
            }
        }
    }

    for (int j = 0; j < 2 * height - 1; ++j) {
        int baseX = x - height + 1 + j;
        int baseY = y + height - 1;
        if (baseX >= 0 && baseX < board.boardWidth && baseY < board.boardHeight) {
            board.grid[baseY][baseX] = '*';
        }
    }
}

void Rectangle::draw(Board& board) {
    if (width <= 0 || height <= 0 || x < 0 || y < 0) return;

    int right = std::min(x + width - 1, board.boardWidth - 1);
    int bottom = std::min(y + height - 1, board.boardHeight - 1);

    for (int row = y; row <= bottom; ++row) {
        for (int col = x; col <= right; ++col) {
            if (row == y || row == bottom || col == x || col == right) {
                if (col >= 0 && row >= 0) {
                    board.grid[row][col] = '*';
                }
            }
        }
    }
}

void Circle::draw(Board& board) {
    if (radius <= 0) return;

    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            if (i * i + j * j <= radius * radius) {
                int drawX = x + j;
                int drawY = y + i;
                if (drawX >= 0 && drawX < board.boardWidth && drawY >= 0 && drawY < board.boardHeight) {
                    board.grid[drawY][drawX] = '*';
                }
            }
        }
    }
}

void Line::draw(Board& board) {
    if (size <= 0) return;

    int x1 = x, y1 = y;
    int x2 = x + size - 1, y2 = y + size - 1;
    int dx = std::abs(x2 - x1), dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        if (x1 >= 0 && x1 < board.boardWidth && y1 >= 0 && y1 < board.boardHeight) {
            board.grid[y1][x1] = '*';
        }
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}


std::string Triangle::getInfo() const {
    return "Triangle at (" + std::to_string(x) + ", " + std::to_string(y) + "), height: " + std::to_string(height);
}

std::string Rectangle::getInfo() const {
    return "Rectangle at (" + std::to_string(x) + ", " + std::to_string(y) + "), width: " + std::to_string(width) + ", height: " + std::to_string(height);
}

std::string Circle::getInfo() const {
    return "Circle at (" + std::to_string(x) + ", " + std::to_string(y) + "), radius: " + std::to_string(radius);
}

std::string Line::getInfo() const {
    return "Line at (" + std::to_string(x) + ", " + std::to_string(y) + "), length: " + std::to_string(size);
}