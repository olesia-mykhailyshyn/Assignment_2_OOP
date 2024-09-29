#include "board.h"

void Board::print() const {
    for (const std::vector<char>& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}

std::vector<std::shared_ptr<Figure>> Board::getFigures() const {
    return figures;
}

void Board::addFigure(const std::shared_ptr<Figure>& figure) {
    figures.push_back(figure);
}