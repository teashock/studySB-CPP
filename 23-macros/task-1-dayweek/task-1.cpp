#include <iostream>

#define DAY(day) (((day) == 1) ? "Monday" :\
            ((day) == 2) ? "Tuesday" :\
            ((day) == 3) ? "Wednesday" :\
            ((day) == 4) ? "Thursday" :\
            ((day) == 5) ? "Friday" :\
            ((day) == 6) ? "Saturday" :\
            ((day) == 7) ? "Sunday" : "ERROR")

int main() {
    int day;
    std::cout << "Enter the number day of the week: ";
    std::cin >> day;
    std::cout << DAY(day) << std::endl;
}