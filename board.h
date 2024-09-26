#pragma once
#include <vector>
#include "iostream"

class Board {
public:
    Board() : grid(boardHeight, std::vector<char>(boardWidth, ' ')) {}
    //Board(std::vector<std::vector<char>> grid) : grid(grid) {}   ???

    void print() const;

    void drawTriangle(int x, int y, int height);

private:
    int boardWidth = 80; //columns
    int boardHeight = 25; //rows
    std::vector<std::vector<char>> grid;
};