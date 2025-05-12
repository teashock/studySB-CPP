#include <iostream>
#include <vector>

int main() {
    std::cout << "The maximum amount in the array!\n";

    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = arr[0];
    int sum = 0;
    int startIndex = 0, endIndex = 0, newStart = 0;

    if (arr.size() == 0) {
        std::cout << "Array is empty!" << std::endl;
        return 0;
    }

    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];

        if (sum > maxSum) {
            maxSum = sum;
            startIndex = newStart;
            endIndex = i;
        }

        if (sum < 0) {
            sum = 0;
            newStart = i + 1;
        }   
    }
    std::cout << "Max sum: " << maxSum << std::endl;
    std::cout << "Index: " << startIndex << " and " << endIndex << std::endl;
    std::cout << "Vector maximum sum: ";
    for (int i = startIndex; i <= endIndex; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}