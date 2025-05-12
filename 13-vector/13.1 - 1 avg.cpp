#include <iostream>
#include <vector>

int main () {

    std::cout << "Input count of numbers in the array: ";
    int N;
    std::cin >> N;
    std::vector<int> array(N);
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += array[i];
    }

    int avg = sum / N;

    std::cout << "Average sum is " << avg << std::endl;


}