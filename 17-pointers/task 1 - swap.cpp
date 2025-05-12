#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    std::cout << "Swap numbers!\n";
    int a = 5, b = 10;
    std::cout << "Befor swap: a = " << a << ", b = " << b << ".\n";
    swap (&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << ".\n";
}