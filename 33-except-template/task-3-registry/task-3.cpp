#include <iostream>
#include <vector>
#include <string>
#include <limits>

template <typename KeyType, typename ValueType>
class KVPair {
    KeyType key;
    ValueType value;
public:
    KVPair(KeyType _key, ValueType _value) : key(_key), value(_value) {}

    KeyType getKey() const {
        return key;
    }

    ValueType getValue() const {
        return value;
    }
};

template <typename KeyType, typename ValueType>
class Registry {
    std::vector<KVPair<KeyType, ValueType>> registry;
public:
    void add(const KeyType& key, const ValueType& value) {
        registry.push_back(KVPair<KeyType, ValueType>(key, value));
    }

    void remove(const KeyType& key) {
        typename std::vector<KVPair<KeyType, ValueType>>::iterator it = registry.begin();
        while (it != registry.end()) {
            if (it->getKey() == key) {
                it = registry.erase(it);
            } else {
                ++it;
            }
        }
    }

    void print() const {
        for (int i = 0; i < registry.size(); ++i) {
            std::cout << "Key: " << registry[i].getKey() << ", Value: " << registry[i].getValue() << std::endl;           
        }
    }

    void find(const KeyType& key) const {
        bool found = false;
        for (int i = 0; i < registry.size(); ++i) {
            if (registry[i].getKey() == key) {
                std::cout << "Found - Key: " << registry[i].getKey() << ", Value: " << registry[i].getValue() << std::endl;
                found = true;
            }
        }
    }
};

bool isValidIntInput(int& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter an integer.\n";
        return false;
    }
    return true;
}

bool isValidDoubleInput(double& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a valid number.\n";
        return false;
    }
    return true;
}

bool isValidStringInput(std::string& value) {
    std::cin >> value;
    if (value.empty()) {
        std::cout << "Invalid input! Please enter a non-empty string.\n";
        return false;
    }
    return true;
}

int main() {
    Registry<int, int> intIntRegistry;
    Registry<int, double> intDoubleRegistry;
    Registry<int, std::string> intStringRegistry;
    Registry<double, int> doubleIntRegistry;
    Registry<double, double> doubleDoubleRegistry;
    Registry<double, std::string> doubleStringRegistry;
    Registry<std::string, int> stringIntRegistry;
    Registry<std::string, double> stringDoubleRegistry;
    Registry<std::string, std::string> stringStringRegistry;

    std::string command;
    while (true) {
        std::cout << "Enter command:\n"
                  << "\t-'add' - to add elements by key;\n"
                  << "\t-'remove' - to delete all elements by key;\n"
                  << "\t-'print' - to print all elements;\n"
                  << "\t-'find' - to find elements by key;\n"
                  << "\t-'exit' - to exit the program\n";
        std::cin >> command;

        if (command == "add") {
            std::string type;
            bool checkKey = false;
            while (!checkKey) {
                std::cout << "Enter key type (int, double, string): ";
                std::cin >> type;
                if (type == "int") {
                    std::string valueType;
                    bool checkValue = false;
                    while (!checkValue) {
                        std::cout << "Enter value type (int, double, string): ";
                        std::cin >> valueType;
                        if (valueType == "int") {
                            int key, value;
                            std::cout << "Input key (int): ";
                            while (!isValidIntInput(key));
                            std::cout << "Input value (int): ";
                            while (!isValidIntInput(value));
                            intIntRegistry.add(key, value);
                            checkValue = true;
                        } else if (valueType == "double") {
                            int key;
                            double value;
                            std::cout << "Input key (int): ";
                            while (!isValidIntInput(key));
                            std::cout << "Input value (double): ";
                            while (!isValidDoubleInput(value));
                            intDoubleRegistry.add(key, value);
                            checkValue = true;
                        } else if (valueType == "string") {
                            int key;
                            std::string value;
                            std::cout << "Input key (int): ";
                            while (!isValidIntInput(key));
                            std::cout << "Input value (string): ";
                            while (!isValidStringInput(value));
                            intStringRegistry.add(key, value);
                            checkValue = true;
                        } else {
                            std::cout << "Unknown value type! Try again!\n";
                        }
                    }
                    checkKey = true;
                } else if (type == "double") {
                    std::string valueType;
                    bool checkValue = false;
                    while (!checkValue) {
                        std::cout << "Enter value type (int, double, string): ";
                        std::cin >> valueType;
                        if (valueType == "int") {
                            double key;
                            int value;
                            std::cout << "Input key (double): ";
                            while (!isValidDoubleInput(key));
                            std::cout << "Input value (int): ";
                            while (!isValidIntInput(value));
                            doubleIntRegistry.add(key, value);
                            checkValue = true;
                        } else if (valueType == "double") {
                            double key, value;
                            std::cout << "Input key (double): ";
                            while (!isValidDoubleInput(key));
                            std::cout << "Input value (double): ";
                            while (!isValidDoubleInput(value));
                            doubleDoubleRegistry.add(key, value);
                            checkValue = true;
                        } else if (valueType == "string") {
                            double key;
                            std::string value;
                            std::cout << "Input key (double): ";
                            while (!isValidDoubleInput(key));
                            std::cout << "Input value (string): ";
                            while (!isValidStringInput(value));
                            doubleStringRegistry.add(key, value);
                            checkValue = true;
                        } else {
                            std::cout << "Unknown value type! Try again!\n";
                        }
                    }
                    checkKey = true;
                } else if (type == "string") {
                    std::string valueType;
                    bool checkValue = false;
                    while (!checkValue) {
                        std::cout << "Enter value type (int, double, string): ";
                        std::cin >> valueType;
                        if (valueType == "int") {
                            std::string key;
                            int value;
                            std::cout << "Input key (string): ";
                            while (!isValidStringInput(key));
                            std::cout << "Input value (int): ";
                            while (!isValidIntInput(value));
                            stringIntRegistry.add(key, value);
                            checkValue = true;
                        } else if (valueType == "double") {
                            std::string key;
                            double value;
                            std::cout << "Input key (string): ";
                            while (!isValidStringInput(key));
                            std::cout << "Input value (double): ";
                            while (!isValidDoubleInput(value));
                            stringDoubleRegistry.add(key, value);
                            checkValue = true;
                        } else if (valueType == "string") {
                            std::string key, value;
                            std::cout << "Input key (string): ";
                            while (!isValidStringInput(key));
                            std::cout << "Input value (string): ";
                            while (!isValidStringInput(value));
                            stringStringRegistry.add(key, value);
                            checkValue = true;
                        } else {
                            std::cout << "Unknown value type! Try again!\n";
                        }
                    }
                    checkKey = true;
                } else {
                    std::cout << "Unknown key type! Try again!\n";
                }
            }
        } else if (command == "remove") {
            std::string type;
            bool checkType = false;
            while (!checkType) {
                std::cout << "Enter key type to remove (int, double, string): ";
                std::cin >> type;
                if (type == "int") {
                    int key;
                    std::cout << "Enter key to remove: ";
                    while (!isValidIntInput(key));
                    intIntRegistry.remove(key);
                    intDoubleRegistry.remove(key);
                    intStringRegistry.remove(key);
                    checkType = true;
                } else if (type == "double") {
                    double key;
                    std::cout << "Enter key to remove: ";
                    while (!isValidDoubleInput(key));
                    doubleIntRegistry.remove(key);
                    doubleDoubleRegistry.remove(key);
                    doubleStringRegistry.remove(key);
                    checkType = true;
                } else if (type == "string") {
                    std::string key;
                    std::cout << "Enter key to remove: ";
                    while (!isValidStringInput(key));
                    stringIntRegistry.remove(key);
                    stringDoubleRegistry.remove(key);
                    stringStringRegistry.remove(key);
                    checkType = true;
                } else {
                    std::cout << "Unknown key type! Try again!\n";
                }
            }
        } else if (command == "print") {
            std::cout << "Printing all registries:\n";
            intIntRegistry.print();
            intDoubleRegistry.print();
            intStringRegistry.print();
            doubleIntRegistry.print();
            doubleDoubleRegistry.print();
            doubleStringRegistry.print();
            stringIntRegistry.print();
            stringDoubleRegistry.print();
            stringStringRegistry.print();
        } else if (command == "find") {
            std::string type;
            bool checkType = false;
            while (!checkType) {
                std::cout << "Enter key type to find (int, double, string): ";
                std::cin >> type;
                if (type == "int") {
                    int key;
                    std::cout << "Enter key to find: ";
                    while (!isValidIntInput(key));
                    intIntRegistry.find(key);
                    intDoubleRegistry.find(key);
                    intStringRegistry.find(key);
                    checkType = true;
                } else if (type == "double") {
                    double key;
                    std::cout << "Enter key to find: ";
                    while (!isValidDoubleInput(key));
                    doubleIntRegistry.find(key);
                    doubleDoubleRegistry.find(key);
                    doubleStringRegistry.find(key);
                    checkType = true;
                } else if (type == "string") {
                    std::string key;
                    std::cout << "Enter key to find: ";
                    while (!isValidStringInput(key));
                    stringIntRegistry.find(key);
                    stringDoubleRegistry.find(key);
                    stringStringRegistry.find(key);
                    checkType = true;
                } else {
                    std::cout << "Unknown key type! Try again!\n";
                }
            }
        } else if (command == "exit") {
            std::cout << "Exiting program...\n";
            break;
        } else {
            std::cout << "Unknown command! Try again.\n";
        }
    }
    return 0;
}