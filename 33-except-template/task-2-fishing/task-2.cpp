#include <iostream>
#include <cstdlib>
#include <exception>
#include <ctime>

class Fish {};
class Boot {};

class CaughtBoot : public std::exception {
public:
    const char* what() const noexcept override {
        return "Oh no! You've caught a boot!";
    }
};

class CaughtFish : public std::exception {
public:
    const char* what() const noexcept override {
        return "Congratulations! You've caught a fish!\n";
    }
};

class Field {
public:
    Fish* fish = nullptr;
    Boot* boot = nullptr;

    bool hasFish() const {
        return fish != nullptr;
    }

    bool hasBoot() const {
        return boot != nullptr;
    }

    ~Field() {
        delete fish;
        delete boot;
    }
};

void play(Field* field[], int& attempts) {
    while (true) {
        int sector;
        std::cout << "Enter the sector number (0-8): ";
        while (!(std::cin >> sector) || sector < 0 || sector > 8) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cerr << "Invalid input! Try again! The number must be an integer from 0 to 8!\n";
        }

        attempts++;
        
        if (field[sector]->hasFish()) {
            throw CaughtFish();
        }
        if (field[sector]->hasBoot()) {
            throw CaughtBoot();
        }
        std::cout << "You didn't catch anything. Try again!\n";
    }
}

int main() {
    std::srand(std::time(nullptr));
    Field* field[9] = { nullptr };

    for (int i = 0; i < 9; ++i) {
        field[i] = new Field();
    }

    int fishPlaced = 0;
    while (fishPlaced < 3) {
        int fishIndex = std::rand() % 9;
        if (!field[fishIndex]->hasFish()) {
            field[fishIndex]->fish = new Fish();
            fishPlaced++;
        }
    }

    int bootsPlaced = 0;
    while (bootsPlaced < 3) {
        int bootIndex = std::rand() % 9;
        if (!(field[bootIndex]->hasFish()) && !(field[bootIndex]->hasBoot())) {
            field[bootIndex]->boot = new Boot();
            bootsPlaced++;
        }
    }

    bool playing = true;
    int attempts = 0;
    while (playing) {
        try {
            play(field, attempts);
        } catch (const CaughtBoot& e) {
            std::cout << e.what() << "\n";
            std::cout << "Game over!\n";
            playing = false;
        } catch (const CaughtFish& e) {
            std::cout << "Attempts: " << attempts << ".\n";
            std::cout << e.what() << "\n";
            playing = false;
        }
    }

    for (int i = 0; i < 9; ++i) {
        delete field[i];
    }

    return 0;
}