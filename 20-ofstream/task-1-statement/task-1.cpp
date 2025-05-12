#include <iostream>
#include <fstream>

bool validName(std::string name) {
    for (int i = 0; i < name.length(); i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))) {
            return false;
        }
    }
    return true;
}

bool validDate(std::string date) {
    if (date.size() != 10 || date[2] != '.' || date[5] != '.') {
        std::cout << "Incorrect date format!\n"; 
        return false;
    }
    int day = std::stoi(date.substr(0,2));
    int month = std::stoi(date.substr(3,2));
    int year = std::stoi(date.substr(6,4));
    
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1){
        std::cout << "Incorrect date!\n";
        return false;
    }
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        std::cout << "There are less than 31 days in this month!\n";
        return false;
    }
    
    if (month == 2) {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leapyear && day > 29) {
            std::cout << "February has 29 days in a leap year!\n";
            return false;
        } else if (!leapyear && day > 28) {
            std::cout << "February has 28 days in a non-leap year!\n";
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Recording data in the payout statement!\n";
     std::string pathFile;
    std::cout << "Enter path to statement file: ";
    std::cin >> pathFile;
    std::ofstream statement (pathFile, std::ios::app);
    if (!statement.is_open()) {
        std::cout << "Could not open the file\n";
        return 1;
    }
    std::string name;
    std::string surname;
    int payout;
    std::string date;
    
    while (true) {
        std::cout << "Enter the employee's name and surname (name and surname must consist of Latin letters), payout (more than 0) and payout date[dd.mm.yyyy]: ";
        std::cin >> name >> surname >> payout >> date;
        if (!validName(name) || !validName(surname)) {
            std::cout << "Incorrect name or surname!.\nTry again!\n";
            continue;
        }
        if (payout <= 0) {
            std::cout << "Payout mast be greater then 0.\nTry again!\n";
            continue;
        }
        if (!validDate(date)) {
            std::cout << "Try again!\n";
            continue;
        }
        break;
    }
    statement << name << " " << surname << " " << payout << " " << date << std::endl;
    statement.close();
    std::cout << "Data recorded successfully!\n";
}