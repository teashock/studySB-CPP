#include <iostream>
#include "gpu.h"

void display(int value[8]) {
    std::cout << "Datas from RAM: ";
    for (int i = 0; i < 8; ++i) {
        std::cout << value[i];
    }
}