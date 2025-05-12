#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int val) {
    std::vector<int> newVec(vec.size() + 1);

    for (int i = 0; i < vec.size(); i++) {
        newVec[i] = vec[i];
        newVec[vec.size()] = val;
    }
    return newVec;
}

int main() {
    
    std::vector<int> vec = {13, 12, 11, 10};
    std::cout << "Enter numbers robots\n";
    
    int num = 0;
    while (num != -1) {
        std::cout << "Input number of next robot\n";
        std::cin >> num;
        vec = add(vec, num);
    }

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }


}