#include <iostream>
#include "kbd.h"

void input(int value[8]) {
    std::cout << "Input 8 integers numbers: ";
    for (int i = 0; i < 8; ++i) {
        std::cin >> value[i];
    }
}