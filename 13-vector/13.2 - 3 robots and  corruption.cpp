#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> vec, int val, int position) {
    std::vector<int> newVec(vec.size() + 1);
    for (int i = 0; i < vec.size(); i++) {
        if (i == (position-1)) {
        newVec[i] = val;
    } else if (i < position) {
        newVec[i] = vec[i];
    } else {
        newVec[i] = vec[i];
    }
    }
    return newVec;
}
    

int main() {
    
    std::vector<int> vec = {13, 12, 11, 10};
    std::cout << "Enter numbers robots\n";
    
    int num = 0;
    int position = 0;
    while (num != -1) {
        std::cout << "Input number of next robot\n";
        std::cin >> num;
        if (num == -1) break;
        std::cout << "Input position of next robot\n";
        std::cin >> position;
        
        if (position < 0 || position > vec.size()) {
            std::cout << "Invalid position!\n";
            continue;  
        }
       
        vec = add(vec, num, position);

    }

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}