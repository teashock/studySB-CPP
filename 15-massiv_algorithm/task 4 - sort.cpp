#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cout << "Task 4. Sort!\n";
    std::vector<int> vec{-100, -50, -5, 1, 10, 15};
    std::cout << "Entered vector: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    int positiveIndex = 0;

    while (positiveIndex < vec.size() && vec[positiveIndex] < 0){
        positiveIndex++;
    }

    int leftIndex = positiveIndex - 1;
    int rightIndex = positiveIndex;
    std::vector<int> result;

    while (leftIndex >= 0 && rightIndex < vec.size()) {
        if (std::abs(vec[leftIndex]) < std::abs(vec[rightIndex])) {
            result.push_back(vec[leftIndex]);
            leftIndex--;
        } else {
            result.push_back(vec[rightIndex]);
            rightIndex++;
        }
    }
    
    while (leftIndex >= 0) {
        result.push_back(vec[leftIndex]);
        leftIndex--;
    }

     while (rightIndex < vec.size()) {
        result.push_back(vec[rightIndex]);
        rightIndex++;
    }
    
    std::cout << "Vector sorted in ascending order of modules: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl;
}