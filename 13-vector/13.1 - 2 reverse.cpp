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
    
    int max = array[0];
    int secondMax = array[0];
    for (int i = 0; i < N; i++) {
        if (array[i] > max) {
            secondMax = max;
            max = array[i];
        } else if (array[i] > secondMax && array[i] < max) {
            secondMax = array[i];
        }
    }
    std::cout << "Max number is " << max << std::endl;
    std::cout << "Second max number is " << secondMax << std::endl;
}