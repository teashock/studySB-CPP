#include <iostream>

#define SPRING 0
#define SUMMER 1
#define AUTUMN 2
#define WINTER 3
#define SEASON SPRING

int main() {
    #if SEASON == SPRING
        std::cout << "Spring\n";
    #elif SEASON == SUMMER
        std::cout << "Summer\n";
    #elif SEASON == AUTUMN
        std::cout << "Autumn\n";
    #elif SEASON == WINTER
        std::cout << "Winter\n";
    #else
        std::cout << "The season is not defined!\n";
    #endif
}