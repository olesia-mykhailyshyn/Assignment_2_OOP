#pragma once
#include <string>
#include "board.h"

class CLI {
public:
    void draw() const;
    void list(Board& board, std::string shapeName, int x, int y, int parametr) const; //for triangle, circle, line
    void list(Board& board, std::string shapeName, int x, int y, int width, int height) const; //for rectangle
    void shapes() const;
    void add(Board& board, std::string shapeName, int x, int y, int parametr) const; //for triangle, circle, line
    void add(Board& board, std::string shapeName, int x, int y, int width, int height) const; //for rectangle
    void redo() const;
    void clear() const;
    void save(std::string filePath) const;
    void load(std::string filePath) const;

    std::string command;
    Board board;
};