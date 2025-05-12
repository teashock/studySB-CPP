#include <iostream>
#include <string>

int main() {
    std::cout << "Who lives in the apartment?";

    std::string surname[] = { "SidorovA", "IvanovA", "PetrovA", "SidorovB", "IvanovB", "PetrovB",
                               "SidorovC", "IvanovC", "PetrovC", "SidorovD" };
    
    int apartment;
    
    bool checkApartment = true;
    std::string answer;
    do {
        std::cout << "\nInput number apartment (1-10): ";
        std::cin >> apartment;
        
        if (apartment >= 1 && apartment <= 10) {
            std::cout << surname [apartment - 1] << "\n";
        } else {
            std::cout << "Error! Invalid data!\n";
        }

        bool  checkAnswer = false;
        do {
            std::cout << "\nDo you want check another apartment? (Y/N)\n";
            std::cin >> answer;
            if (answer == "Y" || answer == "y") {
                checkAnswer = true;
            } else if (answer == "N" || answer == "n") {
                checkApartment = false;
                checkAnswer = true;
            } else {
                std::cout << "Error! Repeat the input!\n";
                checkAnswer = false;
            }
        } while (!checkAnswer);
    } while (checkApartment);
    return 0;
}    
