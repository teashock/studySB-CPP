#include <iostream>

const int SIZE = 10;

void reverse(int* arr) {

    if (!arr) {
        return;
    }

    for (int i = 0; i < SIZE/2; ++i) {
        int temp = arr[i];
        arr[i] = arr[9 - i];
        arr[9 - i] = temp;
    }
}

int main() {
    std::cout << "Reverse array!\n";
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Array befor reverse: ";

    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    reverse(arr);
    std::cout << "Array after reverse: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
}