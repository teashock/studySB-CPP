#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Birthday calendar!\n";
    std::vector<std::string> allFriends;
    std::vector<std::tm> allBirthdays;
    std::string friendName;
    int nextBirthdayIndex = -1;

    std::cout << "Enter friend's names and bithdays [yyyy/mm/dd]. Type 'end' to finish list:\n";
    while (true) {
        std::cin >> friendName;
        if (friendName == "end") {
            break;
        }

        std::tm birthday {};
        std::cin >> std::get_time(&birthday, "%Y/%m/%d");

        if (std::cin.fail()) {
            std::cout << "Invalid date format. Please use yyyy/mm/dd.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        allFriends.push_back(friendName);
        allBirthdays.push_back(birthday);
    }

    if (allFriends.empty()) {
        std::cout << "No friends entered.\n";
        return 0;
    }

    std::time_t currentTime = std::time(nullptr);
    std::tm* local = std::localtime(&currentTime);
    std::tm nextBirthday{};
    bool foundNextBirthday = false;
    int yearDays = 365;
    
    for (int i = 0; i < allFriends.size(); ++i) {
        allBirthdays[i].tm_year = local->tm_year;
        
        if (std::difftime(std::mktime(&allBirthdays[i]),currentTime) < 0) {
            allBirthdays[i].tm_year += 1;
        }

        if (local->tm_mon == allBirthdays[i].tm_mon && local->tm_mday == allBirthdays[i].tm_mday) {
            std::cout << "Today Birthday " << allFriends[i] << "!\n";
        }

        int daysUntilBirthday = std::difftime(std::mktime(&allBirthdays[i]), currentTime) / (60 * 60 * 24);
        if (daysUntilBirthday >= 0 && daysUntilBirthday < yearDays) {
            yearDays = daysUntilBirthday;
            nextBirthday = allBirthdays[i];
            nextBirthdayIndex = i;
            foundNextBirthday = true;
        }
    }
    if (foundNextBirthday) {
        std::cout << "Next birthday is " << std::put_time(&nextBirthday, "%Y/%m/%d") << " for " << allFriends[nextBirthdayIndex] << std::endl;
    } else {
        std::cout << "No upcoming birthdays found.!\n";
    }
    return 0;
}