#include <iostream>

int main() {
    std::cout << "Duplicates search!\n";
    
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    
    int sumNumbers = 0;

    for (int i = 0; i < 15; i++) {
        sumNumbers += numbers[i];
    }

    int minNumber = numbers[0];
    
    for (int i = 0; i < 15; i++) {
        if (numbers[i] < minNumber) {
            minNumber = numbers[i];
        }
    }

    std::cout << "Min number (X) is " << minNumber << ".\n";
    int realSum = 14 * (minNumber + (minNumber + 13)) / 2;
    int duplicate = sumNumbers - realSum;
    std::cout << "Duplicate number is " << duplicate << ".\n";
}