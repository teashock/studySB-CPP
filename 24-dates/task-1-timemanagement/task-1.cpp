#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

std::vector<std::string> taskNames;
std::vector<std::time_t> startTime;
std::vector<std::time_t> endTime;
std::string currentTask;
std::time_t currentTime = 0;


void startTask(std::string& taskName) {
    if (!currentTask.empty()) {
        endTime.push_back(std::time(nullptr));
        taskNames.push_back(currentTask);
        startTime.push_back(currentTime);
    }
    currentTask = taskName;
    currentTime = std::time(nullptr);
}

void endTask(){
    if (!currentTask.empty()) {
        endTime.push_back(std::time(nullptr));
        taskNames.push_back(currentTask);
        startTime.push_back(currentTime);
        currentTask.clear();
    }
}

void status() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nCompleted tasks:\n";
    for (int i = 0; i < taskNames.size(); ++i) {
        double spentTime = difftime(endTime[i], startTime[i]) / 3600.0;
        std::cout << "-task: " << taskNames[i] << ", spent time: " << spentTime << " hours\n";
    }
    if (!currentTask.empty()) {
        std::cout << "Current task: " << currentTask << "\n";
    } else {
        std::cout << "No current task.\n";
    }
}

int main() {
    std::cout << "Time management!\n";
    std::string command, taskName;

    while (true) {
        std::cout << "\nEnter command:\n-'begin' - start task;\n-'end' - end task;\n-'status' - information about all tasks;\n-'exit' - close manager.\n";
        std::cin >> command;
        if (command == "begin") {
            std::cout << "Enter task name: ";
            std::cin.ignore();
            std::getline(std::cin, taskName);
            startTask(taskName);
        } else if (command == "end") {
            endTask();
        } else if (command == "status") {
            status();
        } else if (command == "exit"){
            endTask;
            break;
        } else {
            std::cout << "Incorrect command!\n";
        }
    }
}