#include "board.h"

void Board:: print() const {
    for (const std::vector<char>& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}