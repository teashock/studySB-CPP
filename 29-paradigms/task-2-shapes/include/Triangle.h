#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <cmath>
#include <iomanip>
#include <sstream>

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};

    std::string parameters() {
        std::ostringstream streamA, streamB, streamC;
        streamA << std::fixed << std::setprecision(2) << a;
        streamB << std::fixed << std::setprecision(2) << b;
        streamC << std::fixed << std::setprecision(2) << c;
        return "a: " + streamA.str() + ", b: " + streamB.str() + ", c: " + streamC.str();
    }

    double square() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    BoundingBoxDimension dimensions(){
        double p = (a + b + c) / 2;
        double radius = (a * b * c)/ (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
        return BoundingBoxDimension{radius * 2, radius * 2};
    }

    std::string type(){
        return "Triangle";
    }
};

#endif
