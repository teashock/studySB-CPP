#include <iostream>
#include "ram.h"

void compute(int* buffer) {
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += buffer[i];
    }
    std::cout << "Sum: " << sum << std::endl;
}