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

bool Board::addFigure(const std::shared_ptr<Figure>& figure) {
    if (isDuplicate(figure)) {
        std::cout << "Figure with the same parameters already exists at the same position!" << std::endl;
        return false;
    }
    else if (figure->isOutOfBounds(boardWidth, boardHeight)) {
        std::cout << "Figure is out of bounds or larger than the board!" << std::endl;
        return false;
    }
    else {
        figures.push_back(figure);
        return true;
    }
}

bool Board::isDuplicate(const std::shared_ptr<Figure>& figure) const {
    for (const std::shared_ptr<Figure>& existingFigure : figures) {
        if (figure->getSaveFormat() == existingFigure->getSaveFormat()) {
            return true;
        }
    }
    return false;
}