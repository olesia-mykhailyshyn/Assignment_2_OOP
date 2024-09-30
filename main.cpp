#include "board.h"
#include "figure.h"
#include "CLI.h"

int main() {
    CLI cli;
    while (true) {
        std::cout << "\nEnter command (draw/list/shapes/add/redo/clear/save/load/exit): " << std::endl;
        std::cin >> cli.command;

        if (cli.command == "draw") {
            CLI::draw();
        }
        else if (cli.command == "list") {
            CLI::list();
        }
        else if (cli.command == "shapes") {
            CLI::shapes();
        }
        else if (cli.command == "add") {
            std::cout << "Enter shapeName (triangle/rectangle/circle/line): " << std::endl;
            std::cin >> cli.shapeName;
            std::cout << "Enter x: " << std::endl;
            std::cin >> cli.x;
            std::cout << "Enter y: " << std::endl;
            std::cin >> cli.y;

            if (cli.shapeName == "rectangle") {
                std::cout << "Enter width: " << std::endl;
                std::cin >> cli.parameter1;
                std::cout << "Enter height: " << std::endl;
                std::cin >> cli.parameter2;

                CLI::add(CLI::board, cli.shapeName, cli.x, cli.y, cli.parameter1, cli.parameter2);
            }
            else {
                std::cout << "Enter height/radius/size: " << std::endl;
                std::cin >> cli.parameter1;

                CLI::add(CLI::board, cli.shapeName, cli.x, cli.y, cli.parameter1);
            }
        }
        else if (cli.command == "redo") {
            CLI::redo();
        }
        else if (cli.command == "clear") {
            CLI::clear(cli.filePath);
        }
        else if (cli.command == "save") {
            CLI::save(cli.filePath);
        }
        else if (cli.command == "load") {
            CLI::load(cli.filePath);
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