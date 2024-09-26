#pragma once
#include <vector>
#include "iostream"

class Figure;
class Triangle;
class Rectangle;

class Board {
public:
    Board() : grid(boardHeight, std::vector<char>(boardWidth, ' ')) {}
    //Board(std::vector<std::vector<char>> grid) : grid(grid) {}   ???

    void print() const;

    friend class Figure;
    friend class Triangle;
    friend class Rectangle;

private:
    int boardWidth = 80; //columns
    int boardHeight = 25; //rows
    std::vector<std::vector<char>> grid;
};