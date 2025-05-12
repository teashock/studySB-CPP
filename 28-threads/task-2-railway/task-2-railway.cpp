#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <algorithm>

std::mutex station_lock;
 
void trainTravel(char& name, int& time) {
    std::this_thread::sleep_for(std::chrono::seconds(time));

    {
        std::lock_guard<std::mutex> lock(station_lock);
        std::cout << "Train " << name << " has arrived at the station!\n";
        std::cout << "Train " << name << " is now at the station.\n";

        std::string command;
        while (true) {
            std::cout << "Enter the command 'depart' to send train:\n";
            std::cin >> command;
            if (command == "depart") {
                std::cout << "Train " << name << " has left the station!\n";
                break;
            } else {
                std::cout << "Incorrect command! Try again!";
            }
        }
    }
}

int main() {
    std::cout << "Railway station!\n";
    std::vector<std::thread> trains;
    std::vector<std::pair<char, int>> trainData;
    char trainName[3] = {'A', 'B', 'C'};
    int travelTime[3];

    for (int i = 0; i < 3; ++i) {
        while(true) {
            std::cout << "Enter travel time (seconds) for train \"" << trainName[i] << "\".\n";
            std::cin >> travelTime[i];
            if (std::cin.fail() || travelTime[i] <= 0) {
                std::cout << "Travel time must be greater than 0! Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
        trainData.emplace_back(trainName[i], travelTime[i]);
    }

    std::sort(trainData.begin(), trainData.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < 3; ++i) {
        trains.emplace_back(trainTravel, std::ref(trainName[i]), std::ref(travelTime[i]));
    }

    for (int i = 0; i < trains.size(); ++i) {
        trains[i].join();
    }

    std::cout << "All trains have finished their journey!\n";
}