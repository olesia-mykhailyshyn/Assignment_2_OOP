#include "board.h"
#include "fstream"
#include <iostream>
#include <iomanip>
#include "shapeType.h"

void Board::print() const {
    std::cout << "   ";
    for (int col = 0; col < boardWidth; ++col) {
        std::cout << std::setw(2) << col << " ";
    }
    std::cout << "\n";

    std::cout << "  +";
    for (int col = 0; col < boardWidth; ++col) {
        std::cout << "---";
    }
    std::cout << "+\n";

    for (int row = 0; row < boardHeight; ++row) {
        std::cout << std::setw(2) << row << "|";
        for (char c : grid[row]) {
            std::cout << " " << c << " ";
        }
        std::cout << "|\n";
    }

    std::cout << "  +";
    for (int col = 0; col < boardWidth; ++col) {
        std::cout << "---";
    }
    std::cout << "+\n";
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

void Board::draw() {
    grid.assign(boardHeight, std::vector<char>(boardWidth, ' '));
    for (const std::shared_ptr<Figure>& figure : getFigures()) {
        figure->draw(*this);
    }
    print();
}

void Board::list() const {
    if (figures.empty()) {
        std::cout << "There are no any figures on the board." << std::endl;
    }
    else {
        std::cout << "Figures on the board:" << std::endl;
        for (const std::shared_ptr<Figure>& figure : getFigures()) {
            if (figure != nullptr) {
                std::cout << figure->getInfo() << std::endl;
            }
        }
    }
}

void Board::shapes() {
    std::cout << "List of available shapes and their parameters:" << std::endl;
    std::cout << "1. Circle: x, y, radius" << std::endl;
    std::cout << "2. Rectangle: x, y, width, height" << std::endl;
    std::cout << "3. Triangle: x, y, height" << std::endl;
    std::cout << "4. Line: x1, y1, x2, y2 (start and end points)" << std::endl;
}

void Board::add(Board& board, const std::string& shapeName, int x, int y, int parameter1, int parameter2) {
    ShapeType shapeType = stringToShapeType(shapeName);
    std::shared_ptr<Figure> newFigure = nullptr;

    switch (shapeType) {
        case ShapeType::Triangle:
            newFigure = std::make_shared<Triangle>(x, y, parameter1);
            break;
        case ShapeType::Rectangle:
            newFigure = std::make_shared<Rectangle>(x, y, parameter1, parameter2);
            break;
        case ShapeType::Circle:
            newFigure = std::make_shared<Circle>(x, y, parameter1);
            break;
        case ShapeType::Line:
            newFigure = std::make_shared<Line>(x, y, parameter1, parameter2);
            break;
        default:
            std::cout << "Invalid shape name." << std::endl;
            return;
    }

    if (newFigure && board.addFigure(newFigure)) {
        std::cout << "Figure added successfully." << std::endl;
    }
}

void Board::undo() {
    if(figures.empty()) {
        std::cout<< "There are no figures. Redo command can not be done." << std::endl;
    }
    else {
        figures.pop_back();
        std::cout<< "The last added figure was deleted." << std::endl;
    }
}

void Board::save(const std::string& filePath) const {
    std::ofstream myFile(filePath, std::ios::out);
    if (myFile.is_open()) {
        if (figures.empty()) {
            std::cout << "There are no figures. An empty file will be saved." << std::endl;
        }
        else {
            for (const std::shared_ptr<Figure>& figure : getFigures()) {
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

void Board::clear(const std::string& filePath) {
    if(figures.empty()) {
        std::cout<< "There are no figures. Clear command cannot be done." << std::endl;
    }
    else {
        figures.clear();
        std::ofstream ofs;
        ofs.open(filePath, std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        std::cout << "All shapes are removed from the blackboard. File is empty as well." << std::endl;
    }
}

std::string Board::getFilePath() const {
    return filePath;
}

void Board::load(const std::string& filePath) {
    std::ifstream input(filePath, std::ios::in);
    if (!input.is_open()) {
        std::cout << "Could not open file " << filePath << " for reading." << std::endl;
        return;
    }

    if (input.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The file " << filePath << " is empty. Nothing to load." << std::endl;
        input.close();
        return;
    }

    figures.clear();
    std::string shapeName;
    bool loadSuccessful = true;

    while (input >> shapeName) {
        int x, y, param1, param2 = 0;

        if (!(input >> x >> y >> param1)) {
            loadSuccessful = false;
            break;
        }

        if (shapeName == "Rectangle" || shapeName == "Line") {
            if (!(input >> param2)) {
                loadSuccessful = false;
                break;
            }
        }

        std::shared_ptr<Figure> newFigure = nullptr;

        if (shapeName == "Triangle") {
            newFigure = std::make_shared<Triangle>(x, y, param1);
        }
        else if (shapeName == "Rectangle") {
            newFigure = std::make_shared<Rectangle>(x, y, param1, param2);
        }
        else if (shapeName == "Circle") {
            newFigure = std::make_shared<Circle>(x, y, param1);
        }
        else if (shapeName == "Line") {
            newFigure = std::make_shared<Line>(x, y, param1, param2);
        }
        else {
            loadSuccessful = false;
            break;
        }

        if (newFigure && !addFigure(newFigure)) {
            loadSuccessful = false;
            break;
        }
    }

    input.close();

    if (loadSuccessful) {
        std::cout << "Figures loaded successfully from " << filePath << std::endl;
    }
    else {
        std::cout << "Invalid data found in file: " << filePath << ". Aborting load." << std::endl;
    }
}