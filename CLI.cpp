#include "CLI.h"
#include <memory>
#include "board.h"

void CLI::draw() {
    board.grid.assign(board.boardHeight, std::vector<char>(board.boardWidth, ' '));
    for (const auto& figure : board.getFigures()) {
        figure->draw(board);
    }
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

void CLI::redo() {
    if(board.figures.empty()) {
        std::cout<< "There are no figures. Redo command can not be done." << std::endl;
    }
    else {
        board.figures.pop_back();
        std::cout<< "The last added figure was deleted." << std::endl;
    }
}

void CLI::save(const std::string& filePath) const {}
void CLI::load(const std::string& filePath) const {}

void CLI::clear() {
    //system("cls");
    if(board.figures.empty()) {
        std::cout<< "There are no figures. Clear command can not be done - nothing will change." << std::endl;
    }
    else{
        board.figures.clear();
        std::cout << "All shapes are removed from the blackboard." << std::endl;
    }
}