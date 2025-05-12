#include <iostream>
#include <vector>

int main() {
    std::cout << "Task 2! The total cost of purchases!\n";

    std::cout << "The price of the products: ";
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
    for (int i = 0; i < prices.size(); i++) {
        std::cout << prices[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "The index of the cost: ";
    std::vector<int> index {1, 1, 0, 3};
    for (int i = 0; i < index.size(); i++) {
        std::cout << index[i] << " ";
    }
    std::cout << std::endl;

    float sum = 0.f;

    for (int i = 0; i < index.size(); i++) {
        sum += prices[index[i]];
    }

    std::cout << "The total cost of purchases is " << sum << std::endl;

}