#include <iostream>

int BinaryToDecimal(const std::string & binaryValue) {
    int result = 0;
    int factor = 1;


    for (int i = binaryValue.size() - 1; i >= 0; --i) { 
        result += (binaryValue[i] - '0') * factor;
        factor *= 2;
    }


    return result;
}
int main() {
    std::string binaryValue{};
    std::cin >> binaryValue;
    std::cout << BinaryToDecimal(binaryValue) << std::endl;
    return 0;
}