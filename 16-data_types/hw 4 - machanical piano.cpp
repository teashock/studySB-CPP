#include <iostream>

enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main () {
    std::cout << "Mechanical piano\n";
    std::string chord;
    std::cout << "Input chord (1 (note DO) - 7 (note SI))\n";
    std::cin >> chord;

    if (chord.length() < 2) {
        std::cout << "A chord must contain more than one note!\n";
        return 0;
    } 

    int notes = 0;
    for (char i = 0; i < chord.length(); i++) {
        int index = chord[i] - '1';
        if (index >= 0 && index <= 6) {
            notes |= (1 << index);
        } else {
            std::cout << "Incorrect input!\n";
            return 0;
        }
    }

    if (notes & DO) {
        std::cout << "DO ";
    }
    if (notes & RE) {
        std::cout << "RE ";
    }
    if (notes & MI) {
        std::cout << "MI ";
    }
    if (notes & FA) {
        std::cout << "FA ";
    }
    if (notes & SOL) {
        std::cout << "SOL ";
    }
    if (notes & LA) {
        std::cout << "LA ";
    }
    if (notes & SI) {
        std::cout << "SI ";
    }
}