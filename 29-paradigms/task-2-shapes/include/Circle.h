#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>
#include <iomanip>
#include <sstream>

class Circle : public Shape {
    double radius;
public:
    Circle(double _radius) : radius(_radius) {};

    std::string parameters() {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(2) << radius;
        return "radius: " + stream.str();
    }

    double square() {
        return M_PI * radius * radius;
    }

    BoundingBoxDimension dimensions(){
      return BoundingBoxDimension{radius * 2 + 1, radius * 2 + 1};
    }

    std::string type(){
      return "Circle";
    }
};

#endif
