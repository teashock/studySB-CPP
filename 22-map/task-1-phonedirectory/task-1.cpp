#include<iostream>
#include<map>
#include<string>
#include<vector>

int main() {
    std::cout << "Number book!";
    std::map<std::string, std::string> mPhones;
    std::map<std::string, std::vector<std::string>> mSurname;

    while (true) {
        std::string command;
        std::cout << "Input request type:\n"
                  << "1 - add data to the number book;\n"
                  << "2 - find surname by phone number;\n"
                  << "3 - find a phone number by surname;\n"
                  << "4 - exit.\n";
        std::cin >> command;
        if (command == "1") {
            std::string addNumber, addSurname;
            std::cout << "Enter number phone and surname to add them to the book: ";
            std::cin >> addNumber >> addSurname;
            mPhones.emplace(addNumber, addSurname);
            mSurname[addSurname].push_back(addNumber);
            std::cout << "The data is entered in the number book!";
        } else if (command == "2") {
            std::string number;
            std::cout << "Enter phone number: ";
            std::cin >> number;
            if (mPhones.find(number) != mPhones.end()) {
                std::cout << mPhones[number] << std::endl;
            } else {
                std::cout << "Number not found!" << std::endl;
            }
        } else if (command == "3") {
            std::string surname;
            std::cout << "Enter surname: ";
            std::cin >> surname;
            std::cout << "Phone number for " << surname << ": ";
            if (mSurname.find(surname) != mSurname.end()) {
                for (std::vector<std::string>::iterator it = mSurname[surname].begin(); it != mSurname[surname].end(); ++it) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
            } else {
                std::cout << "Surname not found!" << std::endl;
            }          
        } else if (command == "4") {
            break;
        } else {
            std::cout << "Incorrect command!\n";
        }
    }
}