#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int index) {
    
    vec.resize (vec.size() - 1);
    
    for (int i = index - 1; i < vec.size(); i++) {
        vec[i] = vec [i + 1];
    }
    
    return vec;
}

int main() {
    
    int N;
    std::cout << "Input the number of robots in the store: "; 
    std::cin >> N;

    std::vector<int> vec(N);
    for (int i = 0; i < N; i++){
        std::cout << "Input the robot numbers: \n";
        std::cin >> vec[i];
    }

    int M;
    std::cout << "How many robots are you going to buy?";
    std::cin >> M;

    for (int i = 0; i < M; i++) {
        int index;
        std::cout << "Enter the index of the robot you want to buy: \n";
        std::cin >> index;
        if (index > vec.size() || index < 1) {
            std::cout << "Incorrect index!\n";
        } else {
           vec = add(vec, index);
        }
        std::cout << "Remaining robots: ";
        for (int num : vec) {
        std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}