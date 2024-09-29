#include "CLI.h"
#include <memory>

void CLI::draw() const {
    board.print();
}
void CLI::list() const {
    std::cout << "Figures on the board:" << std::endl;
    for (const std::shared_ptr<Figure>& figure : board.getFigures()) {
        if (figure != nullptr) {
            std::cout << figure->getInfo() << std::endl;
        }
    }
}

void CLI::shapes() const {}

void CLI::add(Board& board, const std::string& shapeName, int x, int y, int parameter1, int parameter2) {
    std::shared_ptr<Figure> newFigure = nullptr;

    if (shapeName == "triangle") {
        newFigure = std::make_shared<Triangle>(x, y, parameter1);
    }
    else if (shapeName == "rectangle") {
        newFigure = std::make_shared<Rectangle>(x, y, parameter1, parameter2);
    }
    else if (shapeName == "circle") {
        newFigure = std::make_shared<Circle>(x, y, parameter1);
    }
    else if (shapeName == "line") {
        newFigure = std::make_shared<Line>(x, y, parameter1);
    }

    if (newFigure) {
        board.addFigure(newFigure);
    }
}

void CLI::redo() const {}
void CLI::save(const std::string& filePath) const {}
void CLI::load(const std::string& filePath) const {}

void CLI::clear() {
    system("cls");
    std::cout << "All shapes are removed from the blackboard." << std::endl;
}