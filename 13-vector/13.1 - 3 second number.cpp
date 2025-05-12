#include <iostream>
#include <vector>

int main () {

    std::cout << "Input count of numbers in the array: ";
    int N;
    std::cin >> N;
    std::vector<float> array(N);
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    
    std::cout << "Revers array\n";
    int max = array[N-1];
    for (int i = N - 1; i >= 0; i--) {
        std::cout << array[i] << std::endl;
        
    }
}