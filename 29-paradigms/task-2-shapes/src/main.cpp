#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() {
    Circle c(10);
    Triangle t(3,4,5);
    Rectangle r(5, 4);

    printParams(&c);
    std::cout << "------------------\n";
    printParams(&t);
    std::cout << "------------------\n";
    printParams(&r);
    std::cout << "------------------\n";
    return 0;
}