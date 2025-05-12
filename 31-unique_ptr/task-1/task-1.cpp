#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Toy { 
    std::string nameToy;
public:
    Toy(const std::string& _nameToy) : nameToy(_nameToy) {}

    std::string getNameToy() const {
        return nameToy;
    }

    ~Toy() {
        std::cout << "The toy " << nameToy << " was put away in the box!" << std::endl;
    }
};

class Dog {
    std::string nameDog;
    std::shared_ptr<Toy> toy;
public:
    Dog(const std::string& _nameDog) : nameDog(_nameDog) {}

    std::string getNameDog() {
        return nameDog;
    }

    void getToy(std::shared_ptr<Toy>& _toy) {
        if (toy == _toy) {
            std::cout << nameDog << " already has this toy!" << std::endl;
                return;
        } else if (_toy.use_count() > 1) {
            std::cout << "Another dog is playing with this toy." << std::endl;
            return;
        } else {
            toy = _toy;
            std::cout << nameDog << " got the toy " << _toy->getNameToy() << "!" << std::endl;
        }
    }

    void dropToy() {
        if (!toy) {
            std::cout << "Nothing to drop!" << std::endl;
            return;
        } else {
            std::cout << nameDog << " dropped toy " << toy->getNameToy() << "!" << std::endl;
            toy.reset();
        }
    }
};

int main() {
    std::vector<std::shared_ptr<Dog>> dogs;
    std::shared_ptr<Toy> toy = std::make_shared<Toy>("Ball");

    int numberDogs;
    do {
        std::cout << "Enter the number of dogs: ";
        std::cin >> numberDogs;
        if (numberDogs < 1) {
            std::cout << "Invalid number! The number of dogs must be more than 0! Try again!\n";
        }
    } while (numberDogs < 1);

    for (int i = 0; i < numberDogs; ++i) {
        std::string nameDog;
        std::cout << "Enter the name of dog " << i + 1 << ": ";
        std::cin >> nameDog;
        dogs.emplace_back(std::make_shared<Dog>(nameDog));
    }

    std::string command;
    while (true) {
        std::string nameDog;
        std::cout << "Let's give toy to the dogs:\n\tget - to get toy;\n\tdrop - to drop toy;\n\texit - to finish the give.\n";
        std::cin >> command;
        if (command == "get") {
            std::cout << "Enter dog name: ";
            std::cin >> nameDog;

            for (int i = 0; i < dogs.size(); ++ i) {
                if (dogs[i]->getNameDog() == nameDog) {
                    dogs[i]->getToy(toy);
                    break;
                }
            }
        } else if (command == "drop") {
            std::cout << "Enter dog name: ";
            std::cin >> nameDog;

            for (int i = 0; i < dogs.size(); ++ i) {
                if (dogs[i]->getNameDog() == nameDog) {
                    dogs[i]->dropToy();
                    break;
                }
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Command not found!\n";
        }
    }
    return 0;
}