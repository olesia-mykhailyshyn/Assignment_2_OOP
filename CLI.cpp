#include "CLI.h"

void CLI::draw() const {}
void CLI::list(Board& board, std::string shapeName, int x, int y, int parametr) const {} //for triangle, circle, line
void CLI::list(Board& board, std::string shapeName, int x, int y, int width, int height) const {} //for rectangle
void CLI::shapes() const {}
void CLI::add(Board& board, std::string shapeName, int x, int y, int parametr) const {} //for triangle, circle, line
void CLI::add(Board& board, std::string shapeName, int x, int y, int width, int height) const {} //for rectangle
void CLI::redo() const {}
void CLI::save(std::string filePath) const {}
void CLI::load(std::string filePath) const {}

void CLI::clear() const{
    system("cls");
    std::cout << "All shapes are removed from the blackboard." << std::endl;
}