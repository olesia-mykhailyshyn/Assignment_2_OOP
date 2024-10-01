#include <cmath>
#include "figure.h"
#include "board.h"

void Triangle::draw(Board& board) {
    if (height <= 0 || isOutOfBounds(board.boardWidth, board.boardHeight)) return;

    for (int i = 0; i < height; ++i) {
        int leftMost = x - i;
        int rightMost = x + i;
        int posY = y + i;

        if (posY >= board.boardHeight) {
            break;
        }

        if (posY >= 0) {
            if (leftMost >= 0 && leftMost < board.boardWidth) {
                board.grid[posY][leftMost] = '*';
            }
            if (rightMost >= 0 && rightMost < board.boardWidth) {
                board.grid[posY][rightMost] = '*';
            }
        }
    }

    int baseY = y + height - 1;
    if (baseY >= 0 && baseY < board.boardHeight) {
        for (int j = -height + 1; j < height; ++j) {
            int baseX = x + j;
            if (baseX >= 0 && baseX < board.boardWidth) {
                board.grid[baseY][baseX] = '*';
            }
        }
    }
}

std::string Triangle::getInfo() const {
    return "Triangle at (" + std::to_string(x) + ", " + std::to_string(y) + "), height: " + std::to_string(height);
}

std::string Triangle::getSaveFormat() const {
    return "Triangle " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(height) + " 0";
}

bool Triangle::isOutOfBounds(int boardWidth, int boardHeight) const {
    return height > boardHeight || 2 * height > boardWidth || y < 0 || y >= boardHeight || x < 0 || x >= boardWidth;
}

// Rectangle Implementation
void Rectangle::draw(Board& board) {
    if (width <= 0 || height <= 0 || isOutOfBounds(board.boardWidth, board.boardHeight)) return;

    int right = std::min(x + width - 1, board.boardWidth - 1);
    int bottom = std::min(y + height - 1, board.boardHeight - 1);

    for (int row = std::max(0, y); row <= bottom; ++row) {
        for (int col = std::max(0, x); col <= right; ++col) {
            if (row == y || row == bottom || col == x || col == right) {
                board.grid[row][col] = '*';
            }
        }
    }
}

std::string Rectangle::getInfo() const {
    return "Rectangle at (" + std::to_string(x) + ", " + std::to_string(y) + "), width: " + std::to_string(width) + ", height: " + std::to_string(height);
}

std::string Rectangle::getSaveFormat() const {
    return "Rectangle " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(width) + " " + std::to_string(height);
}

bool Rectangle::isOutOfBounds(int boardWidth, int boardHeight) const {
    return width > boardWidth || height > boardHeight || x < 0 || y < 0 || x >= boardWidth || y >= boardHeight;
}

// Circle Implementation
void Circle::draw(Board& board) {
    if (radius <= 0 || isOutOfBounds(board.boardWidth, board.boardHeight)) return;

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

std::string Circle::getInfo() const {
    return "Circle at (" + std::to_string(x) + ", " + std::to_string(y) + "), radius: " + std::to_string(radius);
}

std::string Circle::getSaveFormat() const {
    return "Circle " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(radius) + " 0";
}

bool Circle::isOutOfBounds(int boardWidth, int boardHeight) const {
    return radius > boardWidth / 2 || radius > boardHeight / 2 || x < 0 || y < 0 || x >= boardWidth || y >= boardHeight;
}

void Line::draw(Board& board) {
    if (size <= 0 || isOutOfBounds(board.boardWidth, board.boardHeight)) return;

    int x1 = x, y1 = y;
    int x2 = std::min(x + size - 1, board.boardWidth - 1);
    int y2 = y1;
    int dx = std::abs(x2 - x1), dy = 0;
    int sx = (x1 < x2) ? 1 : -1, sy = 0;
    int err = dx - dy;

    while (true) {
        if (x1 >= 0 && x1 < board.boardWidth && y1 >= 0 && y1 < board.boardHeight) {
            board.grid[y1][x1] = '*';
        }
        if (x1 == x2 && y1 == y2) {
            break;
        }
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
    }
}

std::string Line::getInfo() const {
    return "Line at (" + std::to_string(x) + ", " + std::to_string(y) + "), length: " + std::to_string(size);
}

std::string Line::getSaveFormat() const {
    return "Line " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(size) + " 0";
}

bool Line::isOutOfBounds(int boardWidth, int boardHeight) const {
    return size > boardWidth || x < 0 || y < 0 || x + size > boardWidth || y >= boardHeight;
}