#include <iostream>
#include <cmath>

struct myvector{
    double X;
    double Y;
};

myvector add(const myvector& vec1, const myvector& vec2){
    return myvector{vec1.X + vec2.X, vec1.Y + vec2.Y};
}

myvector subtract(const myvector& vec1, const myvector& vec2){
    return myvector{vec1.X - vec2.X, vec1.Y - vec2.Y};
}

myvector scale(const myvector& vec, double mult){
    return myvector{vec.X * mult, vec.Y * mult};
}

double length(const myvector& vec) {
    return sqrt(pow(vec.X, 2) + pow(vec.Y, 2));
}

myvector normalize(const myvector& vec) {
    double len = length(vec);
    if (len == 0) {
        return myvector{0,0};
    } else {
        return scale(vec, 1/len);
    }
}

int main(){
    std::cout << "Actions with vectors!";
    while (true) {
        std::string command;
        std::cout << "Enter command:\n"
        << "'add' - adding vectors;\n" 
        << "'subtract' - vector subtraction;\n"
        << "'scale' - multiplying a vector by a scalar;\n"
        << "'length' -  finding the length of a vector;\n" 
        << "'normalize' - normalization of the vector;\n"
        << "'exit' - exiting the program.\n";
        std::cin >> command;
        
        if (command == "exit") {
            std::cout << "Closing the program!\n";
            break;
        } else if (command == "add" || command == "subtract") {
            double x1, y1, x2, y2;
            std::cout << "Enter the coordinates (x1,y1) of the first vector: ";
            std::cin >> x1 >> y1;
            std::cout << "Enter the coordinates (x2,y2) of the second vector: ";
            std::cin >> x2 >> y2;
            myvector vec1{x1, y1};
            myvector vec2{x2, y2};
            
            myvector result;
            if (command == "add") {
                result = add(vec1,vec2);
            } else {
                result = subtract(vec1,vec2);
            }
            std::cout << "Result: (" << result.X << ", " << result.Y << ").\n";
        } else if (command == "scale") {
            double x, y;
            double mult;
            std::cout << "Enter the coordinates (x,y) of the vector: ";
            std::cin >> x >> y;
            std::cout << "Enter the scale: ";
            std::cin >> mult;
            
            myvector vec{x,y};
            myvector result = scale(vec, mult);
            std::cout << "Result: (" << result.X << ", " << result.Y << ").\n";
        } else if (command == "length") {
            double x, y;
            std::cout << "Enter the coordinates (x,y) of the vector: ";
            std::cin >> x >> y;
            myvector vec{x,y};
            double result = length(vec);
            std::cout << "Result: " << result << ".\n";
        } else if (command == "normalize") {
            double x, y;
            std::cout << "Enter the coordinates (x,y) of the vector: ";
            std::cin >> x >> y;
            myvector vec{x,y};
            myvector result = normalize(vec);
            std::cout << "Result: (" << result.X << ", " << result.Y << ").\n";
        } else {
            std::cout << "Incorrect command! Try again!\n";
        }
    }
}