#include <iostream>
#include <cmath>
#include <vector>

enum class ShapeColor{
    NONE = 0,
    RED,
    BLUE,
    GREEN
};

enum class ShapeType {
    CIRCLE,
    SQUARE,
    TRIANGLE,
    RECTANGLE
};

std::string getColorName(ShapeColor color){
    switch (color) {
        case ShapeColor::RED: return "Red";
        case ShapeColor::BLUE: return "Blue";
        case ShapeColor::GREEN: return "Green";
    default: return "No color";
    }
}

class Shape{
    double x,y;
    ShapeColor color;
    ShapeType type;
    
public:
    Shape(double valueX, double valueY, ShapeColor valueColor, ShapeType valueType) : x(valueX), y(valueY), color(valueColor), type(valueType) {};
    ShapeType getType() {
        return type;
    }

    void printShapeInfo() const {
        std::cout << "- Color: " << getColorName(color) << std::endl;
        std::cout << "- Center: (" << x << ", " << y << ")\n";
    }
};

class Circle : public Shape {
    double radius;

public:
    Circle(double valueX, double valueY, ShapeColor valueColor, double valueRadius) : Shape(valueX , valueY, valueColor, ShapeType::CIRCLE), radius(valueRadius){};
    
    double calculateArea() const { 
        return M_PI * radius * radius;
    }
    
    double calculateOuterRectangle() const {
        return pow(2 * (radius + 1), 2);
    }

    void printCircleInfo() const {
        std::cout << "Circle:\n";
        printShapeInfo();
        std::cout << "- radius: " << radius << std::endl;
        std::cout << "- area: " << calculateArea() << std::endl;
        std::cout << "- bounding rectangle area: " << calculateOuterRectangle() << std::endl;
    }
};

class Square : public Shape {
    double lengthEdge;

public:
    Square(double valueX, double valueY, ShapeColor valueColor, double valuelengthEdge) : Shape(valueX , valueY, valueColor, ShapeType::SQUARE), lengthEdge(valuelengthEdge){};
    
    double calculateArea() const { 
        return pow(lengthEdge, 2);
    }
    
    double calculateOuterRectangle() const {
        return pow((lengthEdge + 1), 2);
    }

    void printSquareInfo() const {
        std::cout << "Square:\n";
        printShapeInfo();
        std::cout << "- the length of the edge of the square: " << lengthEdge << std::endl;
        std::cout << "- area: " << calculateArea() << std::endl;
        std::cout << "- bounding rectangle area: " << calculateOuterRectangle() << std::endl;
    }
};

class Triangle : public Shape {
    double lengthEdge;

public:
    Triangle(double valueX, double valueY, ShapeColor valueColor, double valuelengthEdge) : Shape(valueX , valueY, valueColor, ShapeType::TRIANGLE), lengthEdge(valuelengthEdge){};
    
    double calculateArea() const { 
        return (pow((lengthEdge + 1), 2)*sqrt(3)) / 4;
    }
    
    double calculateOuterRectangle() const {
        return pow((lengthEdge + 1), 2);
    }

    void printTriangleInfo() const {
        std::cout << "Triangle:\n";
        printShapeInfo();
        std::cout << "- the length of the edge of the triangle: " << lengthEdge << std::endl;
        std::cout << "- area: " << calculateArea() << std::endl;
        std::cout << "- bounding rectangle area: " << calculateOuterRectangle() << std::endl;
    }
};

class Rectangle : public Shape {
    double width, height;

public:
    Rectangle(double valueX, double valueY, ShapeColor valueColor, double valueWidth, double valueHeight) : Shape(valueX , valueY, valueColor, ShapeType::RECTANGLE), width(valueWidth), height(valueHeight) {};
    
    double calculateArea() const { 
        return width * height;
    }
    
    double calculateOuterRectangle() const {
        return (width + 1)*(height + 1);
    }

    void printRectangleInfo() const {
        std::cout << "Rectangle:\n";
        printShapeInfo();
        std::cout << "- the width: " << width << "; the height: " << height << std::endl;
        std::cout << "- area: " << calculateArea() << std::endl;
        std::cout << "- bounding rectangle area: " << calculateOuterRectangle() << std::endl;
    }
};

std::vector<Shape*> shapes;

void createShape() {
    while(true){
        std::string typeShape;
        std::cout << "Input command to create shape:\n";
        std::cout << "-'circle' - to create circle;\n";
        std::cout << "-'square' - to create square;\n";
        std::cout << "-'triangle' - to create an equilateral triangle;\n";
        std::cout << "-'rectangle' - to create rectangle;\n";
        std::cout << "-'exit' - to ended create shapes.\n";
        std::cin >> typeShape;

        if (typeShape == "exit") break;
        
        if (typeShape == "circle") {
            double x, y, radius;
            int colorInput;
            std::cout << "Enter the coordinates of the center of the shape (x, y): ";
            std::cin >> x >> y;
            std::cout << "Enter the number color of the shape (0 - none, 1 - red, 2 - blue, 3 - green): ";
            std::cin >> colorInput;
            if (colorInput < 0 || colorInput > 3) {
                std::cout << "Invalid color choice!\n";
                continue;
            }
            std::cout << "Enter the radius of the circle: ";
            std::cin >> radius;
            if (radius <= 0) {
                std::cout << "Radius must be greater than zero!\n";
                continue;
            }
            Circle* circle = new Circle(x, y, ShapeColor(colorInput), radius); 
            shapes.push_back(circle);
            std::cout << "Added circle:\n";
            circle->printCircleInfo();
        } else if (typeShape == "square") {
            double x, y, lengthEdge;
            int colorInput;
            std::cout << "Enter the coordinates of the center of the shape (x, y): ";
            std::cin >> x >> y;
            std::cout << "Enter the number color of the shape (0 - none, 1 - red, 2 - blue, 3 - green): ";
            std::cin >> colorInput;
            if (colorInput < 0 || colorInput > 3) {
                std::cout << "Invalid color choice!\n";
                continue;
            }
            std::cout << "Enter the length of the edge of the square: ";
            std::cin >> lengthEdge;
            if (lengthEdge <= 0) {
                std::cout << "Length must be greater than zero!\n";
                continue;
            }
            Square* square = new Square(x, y, ShapeColor(colorInput), lengthEdge); 
            shapes.push_back(square);
            std::cout << "Added square:\n";
            square->printSquareInfo();
        } else if (typeShape == "triangle") {
            double x, y, lengthEdge;
            int colorInput;
            std::cout << "Enter the coordinates of the center of the shape (x, y): ";
            std::cin >> x >> y;
            std::cout << "Enter the number color of the shape (0 - none, 1 - red, 2 - blue, 3 - green): ";
            std::cin >> colorInput;
            if (colorInput < 0 || colorInput > 3) {
                std::cout << "Invalid color choice!\n";
                continue;
            }
            std::cout << "Enter the length of the edge of the triangle: ";
            std::cin >> lengthEdge;
            if (lengthEdge <= 0) {
                std::cout << "Length must be greater than zero!\n";
                continue;
            }
            Triangle* triangle = new Triangle(x, y, ShapeColor(colorInput), lengthEdge); 
            shapes.push_back(triangle);
            std::cout << "Added triangle:\n";
            triangle->printTriangleInfo();
        } else if (typeShape == "rectangle") {
            double x, y, width, height;
            int colorInput;
            std::cout << "Enter the coordinates of the center of the shape (x, y): ";
            std::cin >> x >> y;
            std::cout << "Enter the number color of the shape (0 - none, 1 - red, 2 - blue, 3 - green): ";
            std::cin >> colorInput;
            if (colorInput < 0 || colorInput > 3) {
                std::cout << "Invalid color choice!\n";
                continue;
            }
            std::cout << "Enter the width and the height of the rectangle: ";
            std::cin >> width >> height;
            if (width <= 0 || height <= 0) {
                std::cout << "Width and height must be greater than zero!\n";
                continue;
            }
            Rectangle* rectangle = new Rectangle(x, y, ShapeColor(colorInput), width, height); 
            shapes.push_back(rectangle);
            std::cout << "Added rectangle:\n";
            rectangle->printRectangleInfo();
        } else {
            std::cout << "Incorrect command!" << std::endl;
        }
    }
}

void listShapes() {
    if (shapes.empty()) {
        std::cout << "No shapes created yet!\n";
        return;
    }

    std::cout << "List of created shapes:\n";
    for (size_t i = 0; i < shapes.size(); ++i) {
        switch (shapes[i]->getType()) {
            case ShapeType::CIRCLE:
                static_cast<Circle*>(shapes[i])->printCircleInfo();
                break;
            case ShapeType::SQUARE:
                static_cast<Square*>(shapes[i])->printSquareInfo();
                break;
            case ShapeType::TRIANGLE:
                static_cast<Triangle*>(shapes[i])->printTriangleInfo();
                break;
            case ShapeType::RECTANGLE:
                static_cast<Rectangle*>(shapes[i])->printRectangleInfo();
                break;
        }
    }
}

int main() {
    std::cout << "Geometry!\n";
    std::string command;
    while (true) {
        std::cout << "Enter command:\n";
        std::cout << "-'add' - to add new shape;\n";
        std::cout << "-'list' - to print information about shapes;\n";
        std::cout << "-'exit' - to close programm.\n";
        std::cin >> command;
        if (command == "add") {
            createShape();
        } else if (command == "list") {
            listShapes();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Incorrect command! Try again!\n";
            continue;
        }
    }
    return 0;
}