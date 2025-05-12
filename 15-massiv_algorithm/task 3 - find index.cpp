#include <iostream>
#include <vector>

int main() {
    std::cout << "Task 3. Find number\n";
    std::vector<int> vec;
    int number;

    std::cout << "Input number of vector (exit with -2, display 5th number with -1):\n";

    while (true) {
        std::cin >> number;
        
        if (number == -2) {
            break;
        }

        if (number == -1) {
            if (vec.size() < 5) {
                std::cout << "Not enough numbers!\n";
            } else {
                std::cout << "Fifth number: " << vec[4] << std::endl;
            }
            continue;
        }

        if (vec.size() < 5) {
            vec.push_back(number);
            for (int i = vec.size() - 1; i > 0; i--) {
                if (vec[i] < vec[i-1]) {
                    std::swap(vec[i], vec[i-1]);
                } else {
                    break;
                }
            }
        } else if (number < vec[4]) {
            vec[4] = number;
            for (int i = 4; i > 0; --i) {
                if (vec[i] < vec[i - 1]) {
                    std::swap(vec[i], vec[i - 1]);
                }
                else {
                    break;
                }
            }
        }
    }
}
