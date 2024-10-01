#include "CLI.h"
#include <memory>
#include "board.h"
#include <fstream>

Board CLI::board;

void CLI::draw() {
    board.grid.assign(board.boardHeight, std::vector<char>(board.boardWidth, ' '));
    for (const std::shared_ptr<Figure>& figure : board.getFigures()) {
        figure->draw(board);
    }
    board.print();
}

void CLI::list() {
    if (board.figures.empty()) {
        std::cout << "There are no any figures on the board." << std::endl;
    }
    else {
        std::cout << "Figures on the board:" << std::endl;
        for (const std::shared_ptr<Figure>& figure : board.getFigures()) {
            if (figure != nullptr) {
                std::cout << figure->getInfo() << std::endl;
            }
        }
    }
}

void CLI::shapes() {
    std::cout << "List of available shapes and their parameters:" << std::endl;
    std::cout << "1. Circle: x, y, radius" << std::endl;
    std::cout << "2. Rectangle: x, y, width, height" << std::endl;
    std::cout << "3. Triangle: x, y, height" << std::endl;
    std::cout << "4. Line: x, y, length" << std::endl;
}

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

void CLI::undo() {
    if(board.figures.empty()) {
        std::cout<< "There are no figures. Redo command can not be done." << std::endl;
    }
    else {
        board.figures.pop_back();
        std::cout<< "The last added figure was deleted." << std::endl;
    }
}

void CLI::save(const std::string& filePath) {
    std::ofstream myFile(filePath, std::ios::out);
    if (myFile.is_open()) {
        if (board.figures.empty()) {
            std::cout << "There are no figures. An empty file will be saved." << std::endl;
        }
        else {
            for (const std::shared_ptr<Figure>& figure : board.getFigures()) {
                if (figure != nullptr) {
                    myFile << figure->getSaveFormat() << std::endl;
                }
            }
            myFile.close();
            std::cout << "Figures saved to " << filePath << std::endl;
        }
    }
    else {
        std::cout << "Could not open file " << filePath << " for writing." << std::endl;
    }
}

void CLI::load(const std::string& filePath) {
    std::ifstream input(filePath, std::ios::in);
    if (input.is_open()) {
        board.figures.clear();
        std::string shapeName;
        while (input >> shapeName) {
            int x, y, param1, param2;
            input >> x >> y >> param1 >> param2;

            if (shapeName == "Triangle") {
                add(board, "triangle", x, y, param1);
            }
            else if (shapeName == "Rectangle") {
                add(board, "rectangle", x, y, param1, param2);
            }
            else if (shapeName == "Circle") {
                add(board, "circle", x, y, param1);
            }
            else if (shapeName == "Line") {
                add(board, "line", x, y, param1);
            }
        }
        input.close();
        std::cout << "Figures loaded from " << filePath << std::endl;
    }
    else {
        std::cout << "Could not open file " << filePath << " for reading." << std::endl;
    }
}

void CLI::clear(const std::string& filePath) {
    if(board.figures.empty()) {
        std::cout<< "There are no figures. Clear command cannot be done." << std::endl;
    } else {
        board.figures.clear();
        std::ofstream ofs;
        ofs.open(filePath, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        std::cout << "All shapes are removed from the blackboard. File is empty as well." << std::endl;
    }
}