#pragma once
#include <string>
#include "board.h"

class CLI {
public:
    static void draw();
    static void list() ;
    static void shapes() ;
    static void add(Board& board, const std::string& shapeName, int x, int y, int parameter1, int parameter2 = 0);
    static void redo();
    static void clear(const std::string& filePath);
    static void save(const std::string& filePath) ;
    static void load(const std::string& filePath);

    std::string command;
    std::string shapeName;
    int x, y, parameter1, parameter2;
    static Board board;
    std::string filePath = R"(C:\KSE\OOP_design\Assignment_2\myFile.txt)";
};