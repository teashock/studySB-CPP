#include <iostream>

int main () {
    std::cout << "Task 1. Banquet table!\n";
    
    int cutlery[2][6] {{4, 3, 3, 3, 3, 3}, {4, 3, 3, 3, 3, 3}};
    int plates[2][6] {{3, 2, 2, 2, 2, 2}, {3, 2, 2, 2, 2, 2}};
    int chairs[2][6] {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}}; 

    chairs[0][4] += 1;
    cutlery[1][2] -= 1;
    cutlery[1][0] -= 1;
    cutlery[1][2] += 1;
    plates[1][0] -= 1;

    std::cout << "Cutlery: " << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << cutlery[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Dishes:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << plates[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Chairs:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << chairs[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}