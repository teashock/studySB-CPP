#include <iostream>
#include <initializer_list>

int main() {
    std::initializer_list<int> integers = {1, 2, 3, 4, 5};
        for (auto integer : integers) {
            std::cout << integer << " ";
        }
    std::cout << std::endl;
}