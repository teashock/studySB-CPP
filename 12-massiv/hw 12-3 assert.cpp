#include <iostream>
#include <cassert>

float travelTime (float distance, float speed) {
    assert(speed > 0 && "Speed must be greatest than 0");
    return distance/speed;
}

int main() {
    float distance, speed;
    std::cout << "Input distance (km): ";
    std::cin >> distance;
    std::cout << "Input speed (km/h): ";
    std::cin >> speed;

    float time = travelTime(distance, speed);

    std::cout << "Travel time is (h): " << time << ".\n";
}

