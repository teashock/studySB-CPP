#include <iostream>
#include <vector>

const int vectorSize = 8;

template < typename T >
void input(std::vector<T>& vec, int n) {
    vec.resize(n);
    std::cout << "Fill the vector (8 elements):\n";
    for (int i = 0; i < n; ++i) {
        while (true) {
            std::cout << "Element " << i + 1 << ": ";
            std::cin >> vec[i];
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Please enter a valid value.\n";
            } else {
                break;
            }
        }
    }
}

template <typename T>
T average(const std::vector<T>& vec) {
    T sum = 0;
    for (const auto& element : vec) {
        sum += element;
    }
    return sum / vec.size();
}

int main() {
    std::string type;
    std::cout << "Enter type vector (int, double, float): ";
    std::cin >> type;

    while (true) {
        if (type == "int") {
            std::vector<int> vec;
            input(vec, vectorSize);
            std::cout << "Average of int vector: " << average(vec) << std::endl;
            break;
        } else if (type == "double") {
            std::vector<double> vec;
            input(vec, vectorSize);
            std::cout << "Average of double vector: " << average(vec) << std::endl;
            break;
        } else if (type == "float") {
            std::vector<float> vec;
            input(vec, vectorSize);
            std::cout << "Average of float vector: " << average(vec) << std::endl;
            break;
        } else {
            std::cout << "Unknown data type!\n";
        }
    }
    return 0;
}