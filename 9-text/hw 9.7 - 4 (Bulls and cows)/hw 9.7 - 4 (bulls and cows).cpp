#include <iostream>

int main() {
    std::string firstNumber, secondNumber;
    std::cout << "Input the hidden number: ";
    std::cin >> firstNumber;
    std::cout << "Input the second number: ";
    std::cin >> secondNumber;

    
    bool check = true;
    do {
        if (firstNumber.length() == 4 && secondNumber.length() == 4) {
            for (int i = 0; i < 4; i++) {
                if (firstNumber[i] < '0' || firstNumber[i] > '9') {
                    check = false; 
               }
                if (secondNumber[i] < '0' || secondNumber[i] > '9') {
                    check = false; 
                }
            }
        }
        if (check == false || (firstNumber.length() != 4 || secondNumber.length() != 4)) {
            std::cout << "Incorrect input! Try again!\n";
            std::cin >> firstNumber;
            std::cin >> secondNumber;
        }
    } while (check == false || (firstNumber.length() != 4 || secondNumber.length() != 4));   

    int bulls = 0, cows = 0;
    
    for (int i = 0; i < 4; i++) {
        if (firstNumber[i] == secondNumber[i]) {
            bulls++;
            firstNumber[i] = 'b';
            secondNumber[i] = 'b';
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < secondNumber.length(); j++) {
            if (i != j && firstNumber[i] == secondNumber[j] && firstNumber[i] != 'b' && firstNumber[i] != 'c') {
                cows++;
                firstNumber[i] = 'c';
                secondNumber[j] = 'c';
            }
        }
    }
    std::cout << "Bulls: " << bulls << ", cows: " << cows << ".\n";

}
