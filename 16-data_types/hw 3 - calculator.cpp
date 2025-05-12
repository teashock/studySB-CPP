#include <iostream>
#include <sstream>

int main() {
    std::cout << "Calculator!\n";

    std::string buffer;
    std::cout << "Input the expression in the format <number_1><+,-,*,/><number_2>\n";
    std::getline(std::cin, buffer);

    std::stringstream buffer_stream(buffer);
    double a, b;
    char operation;
    buffer_stream >> a >> operation >> b;
    double result = 0;

    if (operation == '+') {
        result = a + b;
    } else if (operation == '-') {
        result = a - b;
    } else if (operation == '*') {
        result = a * b;
    } else if (operation == '/') {
        if (b != 0) {
        result = a / b;
        } else { 
            std::cout << "Error! Division by zero!\n";
            return 1;
        }
    } else {
        std::cout << "Wrong operation!\n";
        return 1;
    }
    std::cout << "Result: " << result << std::endl;
}