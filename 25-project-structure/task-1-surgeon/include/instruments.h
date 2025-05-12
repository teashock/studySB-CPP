#include <iostream>

struct coordinates {
    double x, y;

    void input() {
        std::cout << "input coordinates (x, y): ";
        std::cin >> x >> y;
    }

    void print() {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

void scalpel (coordinates& start, coordinates& end) {
    std::cout << "The incision should be made between:\n-start: ";
    start.input();
    std::cout << "-end: ";
    end.input();
    std::cout << "The incision is made:\n-start: ";
    start.print();
    std::cout << "-end: ";
    end.print();
}

void hemostat (coordinates& point) {
    std::cout << "The hemostat must be used in ";
    point.input();
    std::cout << "The hemostat used ";
    point.print();
}

void tweezers (coordinates& point) {
    std::cout << "The tweezers must be used in ";
    point.input();
    std::cout << "The tweezers used ";
    point.print();
}

void suture (coordinates& start, coordinates& end) {
    std::cout << "The seam should be made between:\n-start: ";
    start.input();
    std::cout << "-end: ";
    end.input();
    std::cout << "The seam is made:\n-start: ";
    start.print();
    std::cout << "-end: ";
    end.print();
}

bool isEqual(coordinates& a, coordinates& b) {
    return a.x == b.x && a.y == b.y;
}