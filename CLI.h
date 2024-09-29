#pragma once
#include <string>
#include "board.h"

class CLI {
public:
    void draw();
    void list() const;
    void shapes() const;
    static void add(Board& board, const std::string& shapeName, int x, int y, int parameter1, int parameter2 = 0);
    void redo();
    static void clear();
    void save(const std::string& filePath) const;
    void load(const std::string& filePath) const;

    std::string command;
    std::string shapeName;
    int x, y, parameter1, parameter2;
    static Board board;
};