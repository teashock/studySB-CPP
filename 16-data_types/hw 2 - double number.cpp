#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Two number in to Double\n";
    std::string integer, fraction;
    std::cout << "Input integer part of the number: ";
    std::cin >> integer;
    std::cout << "Input fractional part of the number: ";
    std::cin >> fraction;

    std::string combined = integer + "." + fraction;
    double result = std::stod(combined);
    std::cout << std::setprecision(15) << "Combined double number is " << result;
}