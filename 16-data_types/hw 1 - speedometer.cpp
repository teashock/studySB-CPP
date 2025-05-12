#include <iostream>

int main() {
    std::cout << "Digital speedometer (0 - 150 km/h)!\n";
    float speed_value = 0.0f;
    float delta;
    char speed_str[10];

    do {
        std::cout << "Input delta speed km/h: ";
        std::cin >> delta;
        
        speed_value += delta;

        if (speed_value < 0) { 
            std::cout << "Wrong delta! The speed is less than 0 km/h.\n";
            std::cout << "The speed is equal to 0 km/h!\n";
            speed_value = 0;
        } else if (speed_value > 150) {
            std::cout << "Wrong delta! The speed is over 150 km/h.\n";
            std::cout << "The speed is equal to 150 km/h!\n";
            speed_value = 150;
        }
        std::sprintf(speed_str, "%.1f", speed_value);
        std::cout << "Speed: " << speed_str << std::endl;
    } while (speed_value >= 0.01);
}