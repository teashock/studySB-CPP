#include <iostream>

int main() {
    std::string number;
    std::cout << "Enter your number: ";
    std::cin >> number;
    bool firstMinus = false;
    bool allNumber = false;
    int dotCount = 0;

if(number[0] == '-')
    firstMinus = true;

for(int i = firstMinus ? 1 : 0; i < number.length(); i++) {
    if(number[i] >= '0' && number[i] <= '9')
        allNumber = true;
    else
        allNumber = false;
        break;
    std::cout << " [" << number[i] <<"] "<< "allNumber = " << allNumber << std::endl;

    if(number[i] == '.')
        dotCount++;
    std::cout << " [" << number[i] <<"] "<< "dotCount = " << allNumber << std::endl;
}

if(allNumber && dotCount <= 1)
    std::cout << "Your number is float" << std::endl;
else
    std::cout << "Error number is not float" << std::endl;
}