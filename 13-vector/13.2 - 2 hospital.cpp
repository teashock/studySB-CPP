#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> add(std::vector<int> vec, int val) {
    std::vector<int> newVec(vec.size() + 1);

    for (int i = 0; i < vec.size(); i++) {
        newVec[i] = vec[i];
        newVec[vec.size()] = val;
    }
    return newVec;
}

int main() {
    
    std::vector<int> vec = {13, 55, 34};
        
    int num = 0;
    while (num != -1) {
        std::cout << "Enter the ages of the patients\n";
        std::cin >> num;
        vec = add(vec, num);
    }

    int count = 0;
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
        count += 1;
        sum += vec[i];
    }

    std::cout << "Count of the patients is " << count - 1 << std::endl;
    std::cout << "Average the age of the patients is " << (sum + 1) / (vec.size() - 1) << std::endl;

}