#include <iostream>
#include <vector>

const int SIZE = 4;

void swapvec (std::vector<int>& vec, int* arr) {

    if (!arr) {
        return;
    }
   
    for (int i = 0; i < vec.size(); ++i) {
        int temp = vec[i];
        vec[i] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    std::cout << "Swap vector and array!\n";
    std::vector<int> a = {1,2,3,4};
    int b[SIZE] = {2,4,6,8};

    std::cout << "Before swap:\n";
    std::cout << "Vector: ";
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    
    std::cout << "\nArray: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << b[i] << " ";
    }

    swapvec(a, b);
    
    std::cout << "\nAfter swap:\n";
    std::cout << "Vector: ";
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a [i] << " ";
    }

    std::cout << "\nArray: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << b [i] << " ";
    }
}