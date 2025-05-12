#include <iostream>

#define PASSENGERS(function) { function(passengers); }

#define INPUT {\
    for (int i = 0; i < 10; ++i) {\
        std::cout << "Enter the number passengers in wagon " << i + 1 << ": ";\
        std::cin >> passengers[i];\
    }\
}

#define CHECK {\
    for (int i = 0; i < 10; ++i) {\
        if (passengers[i] > 20) {\
            std::cout << i + 1 << " wagon is crowded!\n";\
        }\
        else if (passengers[i] == 0) {\
            std::cout << i + 1 << " wagon is empty!\n";\
        }\
    }\
}

#define CALCULATE_TOTAL {\
    for (int i = 0; i < 10; ++i) { \
        totalPassengers += passengers[i]; \
    } \
}

void analyze(int* passengers) {
    int totalPassengers = 0;
    CHECK;
    CALCULATE_TOTAL;
    std::cout << "Total passengers in wagons is " << totalPassengers << ".\n";
}

int main() {
    std::cout << "Counting the number of passengers\n";

    int passengers[10];

    INPUT;
    PASSENGERS(analyze);
}