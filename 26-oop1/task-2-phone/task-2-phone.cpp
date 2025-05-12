#include <iostream>
#include <map>
#include <cctype>
#include <vector>

class PhoneNumber{
    std::string number;

public:
    void setNumberPhone(const std::string& number){
        if (numberIsValid(number)) {
            PhoneNumber::number = number;
        } else {
            std::cout << "Invalid phone number format!\n";
        }
    }

    std::string getNumberPhone() {
        return number;
    }

  private:
    bool numberIsValid (const std::string& number) {
        if (number.length() == 12 && number[0] == '+' && number[1] == '7') {
            for (int i = 2; i < number.length(); ++i) {
                if (!isdigit(number[i])){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

class ContactBook{
    std::map<std::string, PhoneNumber> contacts;

public:
    void addContact(const std::string& name, const std::string& number) {
        PhoneNumber phone;
        phone.setNumberPhone(number);
        if (!phone.getNumberPhone().empty()) {
            contacts[name] = phone;
            std::cout << "Contact " << name << " added with number " << phone.getNumberPhone() << std::endl;
        } else {
            std::cout << "Contact could not be added due to invalid phone number.\n";
        }
    }  

    PhoneNumber* findContactByName(const std::string& name) {
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    std::string findContactByNumber(const std::string& number) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->second.getNumberPhone() == number) {
                return it->first;
            }
        }
        return "";
    }
};

class MobilePhone{
    ContactBook contactBook;

public:
    void addContact() {
        std::string name, number;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter phone number (format: +7XXXXXXXXXX): ";
        std::cin >> number;
        contactBook.addContact(name, number);
    }

    void call() {
        std::string identifier;
        std::cout << "Enter contact name or phone number: ";
        std::cin >> identifier;
        PhoneNumber* phone = contactBook.findContactByName(identifier);
        if (phone) {
            std::cout << "Calling " << identifier << " (" << phone->getNumberPhone() << ")...\n";
            return;
        }
        std::string name = contactBook.findContactByNumber(identifier);
        if (!name.empty()) {
            std::cout << "Calling " << name << " (" << identifier << ")...\n";
        } else {
            std::cout << "Contact not found!\n";
        }
    }

    void sms() {
        std::string identifier, message;
        std::cout << "Enter contact name or phone number: ";
        std::cin >> identifier;
        PhoneNumber* phone = contactBook.findContactByName(identifier);
        if (phone) {
            std::cout << "Sending SMS to " << phone->getNumberPhone() << "...\n";
            std::cin.ignore();
            std::cout << "Enter your message: ";
            std::getline(std::cin, message);
            std::cout << "SMS to " << identifier << " " << phone->getNumberPhone() << ": " << message << std::endl;
            return;
        }
        
        std::string name = contactBook.findContactByNumber(identifier);
        if (!name.empty()) {
            std::cout << "Sending SMS to " << identifier << "...\n";
            std::cin.ignore();
            std::cout << "Enter your message: ";
            std::getline(std::cin, message);
            std::cout << "SMS to " << name << " " << identifier << ": " << message << std::endl;
        } else {
            std::cout << "Contact not found!\n";
        }
    }

    void exit() {
        std::cout << "Exiting the program.\n";
    }
};

int main(){
    MobilePhone mobile;
    std::string command;

    while (true) {
        std::cout << "Enter command (add, call, sms, exit): ";
        std::cin >> command;

        if (command == "add") {
            mobile.addContact();
        } else if (command == "call") {
            mobile.call();
        } else if (command == "sms") {
            mobile.sms();
        } else if (command == "exit") {
            mobile.exit();
            break;
        } else {
            std::cout << "Unknown command!\n";
        }
    }
}