#include <iostream>
#include <vector>

void initMatrix (int mtx[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> mtx[i][j];
        }
    }
}

void printMatrix (int mtx[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << mtx[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool comparisson (int mtx1[4][4], int mtx2[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mtx1[i][j] != mtx2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::cout << "Matrix Comparisson!\n";

    int mtx1[4][4], mtx2[4][4];
    std::cout << "Input matrix 1!\n";
    initMatrix(mtx1);
    std::cout << "Input matrix 2!\n";
    initMatrix(mtx2);
    std::cout << "Matrix 1\n";
    printMatrix(mtx1);
    std::cout << "Matrix 2\n";
    printMatrix(mtx2);

    if (comparisson(mtx1, mtx2)) {
        std::cout << "The matrices are equal!\n";
    } else {
        std::cout << "The matrices are not equal!\n";
    }
}