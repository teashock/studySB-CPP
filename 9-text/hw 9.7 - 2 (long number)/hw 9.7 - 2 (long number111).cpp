#include <iostream>

int main() {
    std::cout << "Let's check floating number\n";
    std::cout << "Input number: ";
    std::string number;
    std::cin >> number;

    int dot = 0;
    int digitcount = 0;
    bool right = true;
    for (int i = number[0] == '-' ? 1 : 0; i < number.length(); i++){
        if (number[i] >= '0' && number[i] <= '9') {
            digitcount++;
            continue;
        }
        
        if (number[i] == '.') {
            dot++;
            continue;
        } 
        
        right = false;
        break;
    }

    if (right && digitcount > 0 && dot++ <= 1) {
        std::cout << "Yes! This is the correct entry!\n";
    } else {
        std::cout << "No! This is an incorrect entry!\n";
    }
}