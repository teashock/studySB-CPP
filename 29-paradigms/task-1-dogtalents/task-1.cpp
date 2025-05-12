#include <iostream>
#include <vector>

class Talents {
public:
    virtual std::string get_talents() = 0;
};

class Swimming : public Talents {
public:
    std::string get_talents() {
        return "Swim";
    }
};

class Dancing : public Talents {
    std::string get_talents() {
        return "Dance";
    }
};

class Counting : public Talents {
    std::string get_talents() {
        return "Count";
    }
};

class Dog {
    std::string name;
    std::vector<Talents*> talents;
public:
    void setName(std::string _name) {
        name = _name;
    }

    std::string getName() {
        return name;
    }

    void setTalents(std::vector<Talents*> _talents) {
        talents = _talents;
    }

    std::vector<Talents*> getTalents() {
        return talents;
    }

    void show_talents() {
        std::cout << "This is " << name << " and it has some talents:\n";
        for (int i = 0; i < talents.size(); ++i) {
            std::cout << "\tIt can \"" << talents[i]->get_talents() << "\"\n";
        }
    }
};

int main() {
    std::cout << "Talent Competition\n";
    std::vector<Dog> dogs;

    int numDogs;
    std::cout << "Enter number of dogs: ";
    std::cin >> numDogs;
    dogs.resize(numDogs);

    for (int i = 0; i < numDogs; ++i) {
        std::string dogName;
        std::cout << "Enter dog " << (i + 1) << "'s name: ";
        std::cin >> dogName;

        dogs[i].setName(dogName);

        int numTalents;
        std::cout << "Enter number of talents for " << dogName << ": ";
        std::cin >> numTalents;

        std::vector<Talents*> dogTalents;
        for (int j = 0; j < numTalents; ++j) {
            int talentChoice;
            std::cout << "Choose " << j + 1 << " talent (1: Swimming, 2: Dancing, 3: Counting): ";
            std::cin >> talentChoice;
            if (talentChoice == 1) {
                dogTalents.push_back(new Swimming());
            } else if (talentChoice == 2) {
                dogTalents.push_back(new Dancing());
            } else if (talentChoice == 3) {
                dogTalents.push_back(new Counting());
            } else {
                std::cout << "Wrong choice! Talent " << j + 1 << " not added!\n";
            }
        }
        dogs[i].setTalents(dogTalents);
    }

    std::cout << "\nDisplaying talents of all dogs:\n";
    for (int i = 0; i < dogs.size(); ++i) {
        dogs[i].show_talents();
    }
}