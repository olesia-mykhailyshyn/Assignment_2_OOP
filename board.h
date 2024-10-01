#pragma once
#include <vector>
#include "iostream"
#include "figure.h"
#include "memory"

class Figure;
class Triangle;
class Circle;
class Line;

class Board {
public:
    Board() : grid(boardHeight, std::vector<char>(boardWidth, ' ')) {}

    void print() const;

    [[nodiscard]] std::vector<std::shared_ptr<Figure>> getFigures() const;

    void addFigure(const std::shared_ptr<Figure>& figure);

    [[nodiscard]] bool isDuplicate(const std::shared_ptr<Figure>& figure) const;
    [[nodiscard]] bool isOutOfBounds(const std::shared_ptr<Figure>& figure) const;

    friend class Triangle;
    friend class Rectangle;
    friend class Circle;
    friend class Line;
    friend class CLI;

private:
    int boardWidth = 80; //columns
    int boardHeight = 25; //rows
    std::vector<std::vector<char>> grid;
    std::vector<std::shared_ptr<Figure>> figures;
};