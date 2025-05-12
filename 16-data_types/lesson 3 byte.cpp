#include<iostream>
#include <cmath>

std::string printBinary(int valuse) {
    std::string tmp;
    int value = std::abs(value);

    while(value != 0) {
        tmp.push_back((value % 2) + '0');
        value /= 2;
    }
    std::string result;
    for(size_t i = tmp.length() ; i > 0; --i) {
        result.push_back(tmp[i]-1);
    }
    return result;
}

int main() {
    std::cout << printBinary(65) << std::endl;
    return 0;
}