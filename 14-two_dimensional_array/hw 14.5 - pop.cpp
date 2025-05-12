#include <iostream>
#include <vector>

void initPop(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            arr[i][j] = true;
        }
    }
}

bool printPop(bool arr[12][12]) {
    bool allPopped = true;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arr[i][j]) {
                std::cout << "O";
                allPopped = false;
            } else {
                std::cout << "X";
            }
        }
        std::cout << std::endl;
    }
    return allPopped;
}

void popZone(int startX, int startY, int endX, int endY, bool arr[12][12]) {
    int startPointX;
    int startPointY;
    int endPointX;
    int endPointY;
    if (startX <= endX) {
        startPointX = startX;
        endPointX = endX;
    } else {
        startPointX = endX;
        endPointX = startX;
    }
    if (startY <= endY) {
        startPointY = startY;
        endPointY = endY;
    } else {
        startPointY = endY;
        endPointY = startY;
    }
    for (int i = startPointY; i <= endPointY; i++) {
        for (int j = startPointX; j <= endPointX; j++) {
            if (arr[i][j]) {
                arr[i][j] = false;
                std::cout << "Pop!\n";
            }
        }
    }
}

int main() {
    std::cout << "Pop It!\n";
    bool pop[12][12];
    initPop(pop);
    
    int startX, startY, endX, endY;

    while (!printPop(pop)) {
        std::cout << "Enter the start coordinates (1-12):";
        std::cin >> startX >> startY;
        std::cout << "Enter the end coordinates (1-12):";
        std::cin >> endX >> endY;

        if (startX < 1 || startX > 12 || startY < 1 || startY > 12
            || endX < 1 || endX > 12 || endY < 1 || endY > 12) {
            std:: cout << "Invalid range!\n";
        } else {
            popZone(--startX, --startY, --endX, --endY, pop);
        }
    }
    std::cout << "Done!";
}