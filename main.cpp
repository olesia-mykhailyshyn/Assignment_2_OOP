#include "board.h"
#include "figure.h"
#include "CLI.h"

int main() {
//    Board board;
//    Triangle::drawTriangle(board,10,5,5);
//    Rectangle rectangle;
//    rectangle.drawRectangle(board, 20, 20, 8, 4);
//    Circle circle;
//    circle.drawCircle(board, 3,3,3);
//    Line line;
//    line.drawLine(board, 9,13,9);
//    board.print();
//    CLI cli;
//    cli.clear();

while(true) {
    CLI cli;
    std::cout << "Enter command (draw/list/shapes/add/redo/clear/save/load/exit): " << std::endl;
    std::cin >> cli.command;

    if (cli.command == "draw") {
        cli.draw();
    }
    else if (cli.command == "list") {
    }
    else if (cli.command == "shapes") {
        cli.shapes();
    }
    else if (cli.command == "add") {
    }
    else if (cli.command == "redo") {
        cli.redo();
    }
    else if (cli.command == "clear") {
        cli.clear();
    }
    else if (cli.command == "save") {
        //cli.save();  what type of file????
    }
    else if (cli.command == "load") {
        //cli.load();  what type of file???
    }
    else if (cli.command == "exit") {
        std::cout << "Exiting the program." << std::endl;
        break;
    }
    else {
        std::cout << "Unknown command." << std::endl;
    }
}
    return 0;
}