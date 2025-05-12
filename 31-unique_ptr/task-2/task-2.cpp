#include <iostream>

class Toy {
    std::string nameToy;
public:
    Toy(const std::string& name) : nameToy(name) {}
    ~Toy() {
        std::cout << "Toy " << nameToy << " was dropped" << std::endl;
    }
    std::string getName() const {
        return nameToy;
    }
};

class shared_ptr_toy {
    Toy* toy;
    int* countToy;
public:
    
    shared_ptr_toy() : toy(nullptr), countToy(new int(0)) {}

    explicit shared_ptr_toy(const std::string& toyName) 
        : toy(new Toy(toyName)), countToy(new int(1)) {}

    shared_ptr_toy(const shared_ptr_toy& oth) : toy(oth.toy), countToy(oth.countToy) {
        (*countToy)++;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& oth) {
        if (this != &oth) {
            if (--(*countToy) == 0) {
                delete toy;
                delete countToy;
            }
            toy = oth.toy;
            countToy = oth.countToy;
            (*countToy)++;
        }
        return *this;
    }

    ~shared_ptr_toy() {
        if (--(*countToy) == 0) {
            delete toy;
            delete countToy;
        }
    }

    void reset() {
        if (--(*countToy) == 0) {
            delete toy;
            delete countToy;
        }
        toy = nullptr;
        countToy = new int(0);
    }

    Toy* get() const {
        return toy;
    }

    int use_count() const {
        return *countToy;
    }

    std::string getToyName() const {
        return (toy ? toy->getName() : "Nothing");
    }
};

shared_ptr_toy make_shared_toy(const std::string& toyName) {
    return shared_ptr_toy(toyName);
}

int main() {
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03("duck");
    
    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    toy_02 = toy_03;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    toy_01.reset();
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    return 0;
}