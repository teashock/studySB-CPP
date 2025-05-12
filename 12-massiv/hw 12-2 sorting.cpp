#include <iostream>

int main() {
    std::cout << "Sorting an array!\n";

    int sizeArray = 15;
    float array[sizeArray];
    
    std::cout << "Input 15 float numbers: "; 
    for (int i = 0; i < 15; i++) {
        std::cin >> array[i];
    }

    for (int i = 0; i < sizeArray - 1; i++) {
        int max = i;
        for (int j = i + 1; j < sizeArray; j++) {
            if (array[j] > array[max]) {
                max = j;
            }
        }
        if (max != i) {
            float var = array[i];
            array[i] = array[max];
            array[max] = var;
        }
    }

    std::cout << "Sorted array is: ";
    for (int i = 0; i < sizeArray; i++) {
        std::cout << array[i] << " ";
    }
}