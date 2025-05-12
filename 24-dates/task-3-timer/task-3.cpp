#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::cout << "Timer!\n";
    std::tm timerInterval;
    while (true){
        std::cout << "Enter timer interval [MM:SS]: ";
        std::cin >> std::get_time(&timerInterval, "%M:%S");
        if (std::cin.fail()) {
            std::cout << "Invalid time format. Please use [MM:SS].\n";
            std::cin.clear();
            continue;
        }
        break;
    }
    std::time_t currentTime = std::time(nullptr);
    std::time_t targetTime = currentTime + timerInterval.tm_min * 60 + timerInterval.tm_sec;

    while (currentTime != targetTime) {
        int diff = std::difftime (targetTime, currentTime);
        currentTime = std::time(nullptr);
        int newDiff = std::difftime(targetTime,currentTime);
        int minutes = diff / 60;
        int seconds = diff % 60; 
        std::cout << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << seconds << std::endl;
    }
    std::cout << "\nDing! Ding! Ding!" << std::endl;
}