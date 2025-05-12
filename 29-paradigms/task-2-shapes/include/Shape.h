#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

struct BoundingBoxDimension {
  double width, height;
};

class Shape {
public:

    virtual std::string parameters() = 0;
    virtual double square() = 0;
    virtual BoundingBoxDimension dimensions() = 0;
    virtual std::string type() = 0;
};

void printParams(Shape* shape) {
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Parameters: " << shape->parameters() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    BoundingBoxDimension dim = shape->dimensions();
    std::cout << "Box Dimensions (width, height): " << dim.width << ", "<< dim.height << std::endl;
}

#endif