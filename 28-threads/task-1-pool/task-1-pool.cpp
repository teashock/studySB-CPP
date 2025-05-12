#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <chrono>

struct Swimmer {
    std::string name;
    double speed;
    double distance = 0;
    int time_spent = 0;
};

std::vector<Swimmer> swimmer_data;
std::mutex swimmer_data_access;

void swim(Swimmer& swimmer) {
    while (swimmer.distance < 100) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        swimmer.distance += swimmer.speed;
        swimmer.time_spent++;

        if (swimmer.distance > 100) {
            swimmer.distance = 100;
        }
        {
            std::lock_guard<std::mutex> lock(swimmer_data_access);
            std::cout << swimmer.name << " swam " << swimmer.distance << " meters. (Thread ID: "  << std::this_thread::get_id() << ").\n";
        }
    }
    {
        std::lock_guard<std::mutex> lock(swimmer_data_access);
        swimmer_data.push_back(swimmer);
    }
}

int main() {
    std::cout << "The swimming championship!\n";

    std::vector<Swimmer> swimmers(6);

    
    for (int i = 0; i < swimmers.size(); ++i) {
        while (true) {
            std::cout << "Enter the name and speed of " << i + 1 << " swimmer: ";
            std::cin >> swimmers[i].name >> swimmers[i].speed;
            if (std::cin.fail() || swimmers[i].speed <= 0) {
                std::cout << "Speed must be greater than 0! Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }

    std::vector<std::thread> th;
    for (int i = 0; i < swimmers.size(); ++i) {
        th.emplace_back(swim, std::ref(swimmers[i]));
    }

    for (int i = 0; i < th.size(); ++i) {
        th[i].join();
    }
    
    std::stable_sort(swimmer_data.begin(), swimmer_data.end(), [](const Swimmer& a, const Swimmer& b) {
        return a.time_spent < b.time_spent;
    });

    std::cout << "\nResults:" << std::endl;
    for (int i = 0; i < swimmer_data.size(); ++i) {
        std::cout << swimmer_data[i].name << " spent " << swimmer_data[i].time_spent << " seconds." << std::endl;
    } 
    return 0;
}