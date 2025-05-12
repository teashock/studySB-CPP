#include "ram.h"

int buffer[8] = {0};

void write(int values[8]) {
    for (int i = 0; i < 8; ++i) {
        buffer[i] = values[i];
    }
}

int* read() {
    return buffer;
}