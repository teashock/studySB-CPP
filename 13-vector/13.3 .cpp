#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int val) {
    vec.resize (vec.size() + 1);
    vec[vec.size() - 1] = val;

    return vec;
}

std::vector<int> remove_last(std::vector<int> vec) {
    vec.resize (vec.size() - 1);
    
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

    for (int i =)

    while (val != - 2) {
        if (val == -1) {
            float sum = 0;
            for (int i = 0; i < realSize; i++) {
                sum = vec[i];
            }
        float avg = sum / vec.size();  

        std::cout << std::endl << "AVG = " << avg << std::endl;  

        for (int i = realSize - 1; i >= 0; --i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl << "Realsize = " << realSize << " Size = " << vec.size() << std::endl;
        }
        else {
            if (realSize == vec.size()) 
                  vec.resize(vec.size() + 10);
            vec[realSize] = val;
            ++realSize;
        }
        std::cin >> val;    
    }
}