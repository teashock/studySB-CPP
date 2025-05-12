#include <iostream>
#include <fstream>

struct data {
    std::string name;
    std::string surname;
    std::string date;
    int payout;
};

void read(const std::string& filepath, data& record) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Could not open the file.\n";
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The file is empty!";
        file.close();
    }
    while (true) {
        file >> record.name;
        if (file.eof()) {
            break;
        } 
        file >> record.surname >> record.payout >> record.date;
        std::cout << record.name << " " << record.surname << " " << record.payout << " " << record.date << "\n";
    }
    file.close();
}

void add(const std::string& filepath, data& record) {
    std::ofstream file(filepath, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Could not open the file\n";
        return;
    }
    file << record.name << " " << record.surname << " " << record.payout << " " << record.date << "\n";
    std::cout << "The data is recorded!\n";
    file.close();
}
    
bool validName(const std::string& name) {
    for (int i = 0; i < name.length(); i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))) {
            return false;
        }
    }
    return true;
}

bool validDate(const std::string& date) {
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
    std::cout << "Recording and checking data in the payout statement!\n";
    data person;
    std::string command;
    std::string pathFile;
    std::cout << "Enter path to statement file: ";
    std::cin >> pathFile;
    std::cout << "Enter command:\n - 'list' to read statement;\n - 'add' to add the data.\n";
    std::cin >> command;

    if (command == "list"){
        read(pathFile, person);
    } else if (command == "add") {
        std::cout << "Enter the employee's name and surname (name and surname must consist of Latin letters), payout (more than 0) and payout date[dd.mm.yyyy]: ";
        while (true) {
            std::cin >> person.name >> person.surname >> person.payout >> person.date;
            if (!validName(person.name) || !validName(person.surname)) {
                std::cout << "Incorrect name or surname!.\nTry again!\n";
                continue;
            }
            if (person.payout <= 0) {
                std::cout << "Payout mast be greater then 0.\nTry again!\n";
                continue;
            }
            if (!validDate(person.date)) {
                std::cout << "Try again!\n";
                continue;
            } 
            break;
        }
        add(pathFile, person);
    }
}