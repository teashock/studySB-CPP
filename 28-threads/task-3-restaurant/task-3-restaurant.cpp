#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>

enum class TypeFood {
    PIZZA,
    SOUP,
    STEAK,
    SALAD,
    SUSHI
};

std::string getFoodName(TypeFood food){
    switch (food) {
        case TypeFood::PIZZA: return "pizza";
        case TypeFood::SOUP: return "soup";
        case TypeFood::STEAK: return "steak";
        case TypeFood::SALAD: return "salad";
        case TypeFood::SUSHI: return "sushi";
    }
    return "Unknown!";
}

std::mutex kitchen_mtx;
std::mutex cooking_mtx;
std::vector<TypeFood> orders;
std::vector<TypeFood> readyFood;
const int maxDeliveries = 10;
int deliveries = 0;
bool isCooking = false;

TypeFood getRandomFood(){
    std::srand(std::time(nullptr));
    return static_cast<TypeFood>(std::rand() % 5);
}

void order() {
    std::srand(std::time(nullptr));
    while (deliveries < maxDeliveries) {
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5));
        TypeFood food = getRandomFood();
        {
            std::lock_guard<std::mutex> lock(kitchen_mtx);
            if (deliveries >= maxDeliveries) break;
            orders.push_back(food);
            std::cout << "[ORDER] Order received: " << getFoodName(food) << std::endl;
        }
        {
            std::lock_guard<std::mutex> lock(kitchen_mtx);
            std::cout << "[ORDER] Current order list: ";
            for (int i = 0; i < orders.size(); ++i) {
                std::cout << getFoodName(orders[i]) << " ";
            }
            std::cout << std::endl;
        }
    }
}

void cookFood(TypeFood food) {
    std::srand(std::time(nullptr));
    {
        std::lock_guard<std::mutex> lock(cooking_mtx);
        isCooking = true;
    }
    
    std::cout << "[COOK] The chef starts making " << getFoodName(food) << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11 + 5));
    
    {
        std::lock_guard<std::mutex> lock(kitchen_mtx);
        readyFood.push_back(food);
        std::cout << "[COOK] Dish ready for delivery: " << getFoodName(food) << std::endl;

        std::cout << "[COOK] Ready dishes awaiting courier: ";
        for (int i = 0; i < readyFood.size(); ++i) {
            std::cout << getFoodName(readyFood[i]) << " ";
        }
        std::cout << std::endl;
    }
    
    {
        std::lock_guard<std::mutex> lock(cooking_mtx);
        isCooking = false;
    }
}

void cook() {
    std::srand(std::time(nullptr));
    while (deliveries < maxDeliveries) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (!orders.empty()) {
            std::lock_guard<std::mutex> cookingLock(cooking_mtx);
            if (isCooking) continue;
            
            kitchen_mtx.lock();
            TypeFood food = orders.front();
            orders.erase(orders.begin());
            kitchen_mtx.unlock();
            
            std::thread cookThread(cookFood, food);
            cookThread.detach();
        }
    }
}

void courier() {
    bool firstPickup = true;
    while (deliveries < maxDeliveries) {
        std::vector<TypeFood> foodToDeliver;

        if (firstPickup) {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            firstPickup = false; 
        } 

        {
            std::lock_guard<std::mutex> lock(kitchen_mtx);
            if (!readyFood.empty()) {
                foodToDeliver = std::move(readyFood);
                readyFood.clear();
            }
        }

        if (!foodToDeliver.empty()) {
            std::cout << "[COURIER] Courier picked up: ";
            for (int i = 0; i < foodToDeliver.size(); ++i) {
                std::cout << getFoodName(foodToDeliver[i]) << " ";
            }
            std::cout << std::endl;

            deliveries++;
            std::this_thread::sleep_for(std::chrono::seconds(30));
            std::cout << "[COURIER] Courier delivered: ";
            for (int i = 0; i < foodToDeliver.size(); ++i) {
                std::cout << getFoodName(foodToDeliver[i]) << " ";
            }
            std::cout << std::endl;
            std::cout << "[TOTAL] Total deliveries: " << deliveries << std::endl;
        } else {
            std::cout << "[COURIER] No food ready for delivery." << std::endl;
        }
    }
}


int main() {
    int i = 0;
    std::srand(std::time(nullptr));
    
    std::thread orderThread(order);
    std::thread cookThread(cook);
    std::thread courierThread(courier);

    while (deliveries < maxDeliveries) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ++i << " ";
    }

    orderThread.join();
    cookThread.join();
    courierThread.join();

    std::cout << "All deliveries completed!" << std::endl;
    return 0;
}