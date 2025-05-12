#include <fstream>
#include "disk.h"

void save(int value[8]){
    std::ofstream file("data.txt");
    for (int i = 0; i < 8; ++i) {
        file << value[i] << std::endl;
    }
    file.close();
}

void load(int value[8]){
    std::ifstream file("data.txt");
    for (int i = 0; i < 8; ++i) {
        file >> value[i];
    }
    file.close();
}