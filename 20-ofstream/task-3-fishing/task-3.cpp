#include <iostream>
#include <fstream>

bool validFish(std::string fish) {
    for (int i = 0; i < fish.length(); i++) {
        if (!((fish[i] >= 'A' && fish[i] <= 'Z') || (fish[i] >= 'a' && fish[i] <= 'z'))) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Fishing!";
    std::string pathRiver;
    std::string pathBasket;
    std::cout << "Enter path to river file: ";
    std::cin >> pathRiver;
    std::cout << "Enter path to basket file: ";
    std::cin >> pathBasket;
    std::ifstream river (pathRiver, std::ios::binary);
    std::ofstream basket (pathBasket, std::ios::app);
    if (!river.is_open()) {
        std::cout << "Could not open the river file!\n";
        return 1;
    }
    if (!basket.is_open()) {
        std::cout << "Could not open the basket file!\n";
        return 1;
    }
    std::string fish;
    while (true) {
        std::cout << "What kind of fish would you like to catch?\nEnter fish (Latin letters): ";
        std::cin >> fish;

        if (validFish(fish)) {
            break;
        } else {
            std::cout << "Incorrect input! Pleas enter a valid fish name.\n";
            continue;
        }
    }
    int countFish = 0;
    while (!river.eof()) {
        std::string bufferFish;
        river >> bufferFish;
        if (fish == bufferFish) {
            basket << fish << "\n";
            ++countFish;
        }
    }
    basket << "\n";
    std::cout << "You have caught " << countFish << " fish!" << std::endl;
    river.close();
    basket.close();
}