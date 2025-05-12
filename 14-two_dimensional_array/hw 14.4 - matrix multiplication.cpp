#include <iostream>
#include <vector>

void initMatrix (float mtx[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> mtx[i][j];
        }
    }
}

void initVector (float vec[4]) {
    for (int i = 0; i < 4; i++) {
        std::cin >> vec[i];
    }
}

void printMatrix (float mtx[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << mtx[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printVector(float vec[4]) {
    for (int i = 0; i < 4; i++) {
        std::cout << vec[i] << " ";
        std::cout << std::endl;
    }
}

float multiplication (float mtxA[4][4], float vecB[4], float vecC[4]) {
    for (int i = 0; i < 4; i++) {
        float sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += mtxA[i][j] * vecB[j];                
        }
        vecC[i] = sum;      
    }
    return 0;
}

int main() {
    std::cout << "Matrix Multiplication!\n";

    float mtxA[4][4], vecB[4], vecC[4];
    std::cout << "Input matrix A!\n";
    initMatrix(mtxA);
    std::cout << "Input vector B!\n";
    initVector(vecB);
    std::cout << "Matrix A\n";
    printMatrix(mtxA);
    std::cout << "Vector B!\n";
    printVector(vecB);

    float sum = 0;
    std::cout << "Vector C is:\n";
    multiplication(mtxA, vecB, vecC);
    for (int i = 0; i < 4; i++) {
        std::cout << vecC[i] << " ";
        std::cout << std::endl;
    }
}