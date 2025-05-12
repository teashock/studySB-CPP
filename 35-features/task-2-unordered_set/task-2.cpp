#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 1, 5, 3, 2, 6};
    std::cout << "Original vector: ";
    for (auto it : vec) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    auto uniqueVec = [] (const std::vector<int> integers) -> std::unique_ptr<std::vector<int>> {
        auto value = new std::unordered_set<int>();
        auto result = std::make_unique<std::vector<int>>();
        for (auto &i : integers) {
            if (value->insert(i).second) {
                result->push_back(i);
            } else {
                std::cout << "Number " << i << " is repeated!\n";
            }
        }
        return result;
    };

    auto newVec = uniqueVec(vec);
    std::cout << "Modified vector: ";
    for (auto i : *newVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}