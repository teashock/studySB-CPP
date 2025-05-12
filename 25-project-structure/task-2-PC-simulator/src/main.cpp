#include <iostream>
#include "cpu.h"
#include "ram.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"

int main() {
    int values[8] = {0};
    std::string command;

    while (true) {
        std::cout << "Input command:\n";
        std::cout << "-sum - to sum integers from RAM;\n";
        std::cout << "-save - to save file with integers;\n";
        std::cout << "-load - to save file with integers;\n";
        std::cout << "-input - to input integers;\n";
        std::cout << "-display - to print integers in the terminal;\n";
        std::cout << "-exit - to close program.\n";
        std::cin >> command;

        if (command == "sum") {
            std::cout << "Calculating the sum..." << std::endl;
            compute(read());
        } else if (command == "save") {
            std::cout << "Saving data...\n";
            save(values);
            std::cout << "The data is saved!\n";
        } else if (command == "load") {
            std::cout << "Loading data...\n";
            load(values);
            write(values);
            std::cout << "The data is uploaded!\n";
        } else if (command == "input") {
            input(values);
            write(values);
            std::cout << "The data is entred!\n";
        } else if (command == "display") {
            std::cout << "Data output from RAM...\n";
            display(read());
        } else if (command == "exit") {
            std::cout << "Closing the program!";
            break;
        } else {
            std::cout << "Incorrect command! Try again!" << std::endl;
            continue;
        }
    }

    return 0;
}