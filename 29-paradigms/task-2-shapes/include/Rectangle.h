#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iomanip>
#include <sstream>

class Rectangle : public Shape {
    double widthR, heightR;
public:
    Rectangle(double _w, double _h) : widthR(_w), heightR(_h) {};

    std::string parameters() {
        std::ostringstream streamW, streamH;
        streamW << std::fixed << std::setprecision(2) << widthR;
        streamH << std::fixed << std::setprecision(2) << heightR;
        return "width: " + streamW.str() + " height: " + streamH.str();
    }

    double square() {
        return widthR * heightR;
    }

    BoundingBoxDimension dimensions(){
        return BoundingBoxDimension{widthR + 1, heightR + 1};
    }

    std::string type(){
        return "Rectangle";
    }
};

#endif
