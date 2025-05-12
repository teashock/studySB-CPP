#include <iostream>

bool substr(const char* x, const char* y) {

    bool found = false;
    int i = 0;
    while (*(x + i) != '\0'){
        if (*(x + i) == *(y)) {
            found = true;
            int j = 0;
            while (*(y + j) != '\0') {
                if (*(x + i + j) != *(y + j)) {
                    found = false;
                    break;
                }
                j++;
            }
            if (found && j > 0) {
                return true;
            }
        }
        i++;    
    }
    return false;
}

int main() {
    std::cout << "Line search!\n";
    const char* A = "Hello world!";
    std::cout << "Line A is \"" << A << "\".\n";
    const char* B = "wor";
    std::cout << "Line B is \"" << B << "\".\n";
    const char* C = "banana";
    std::cout << "Line C is \"" << C << "\".\n";

    std::cout << "Is line B contained in line A?\n";
    if (substr(A,B)) {
        std::cout << "Yes!\n";
    } else {
        std::cout << "No!\n";
    }

    std::cout << "Is line C contained in line A?\n";
    if (substr(A,C)) {
        std::cout << "Yes!\n";
    } else {
        std::cout << "No!\n";
    }
}