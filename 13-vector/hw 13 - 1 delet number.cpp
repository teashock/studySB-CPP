#include <iostream>
#include <vector>

int main() {
    std::cout << "Removing a number from a vector.\n";

    int n;
    std::cout << "Input vector size: ";
    std::cin >> n;

    std::vector<int> vec(n);

    std::cout << "Input numbers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    
    int number;
    std::cout << "Input number to delete: ";
    std::cin >> number;
    
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == number) {
            for (int j = i; j < vec.size() - 1; j++) {
                vec[j] = vec[j+1];
            }
            vec.pop_back();
            i -= 1;
        }
    }

    std::cout << "Result: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

}