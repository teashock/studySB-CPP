#include <iostream>
#include <vector>

class Screen {
public:
    static const int screenWidth = 80;
    static const int screenHeight = 50;
    
    void display(const std::vector<std::vector<int>>& buffer) {
        for (size_t i = 0; i < buffer.size(); ++i) {
            for (size_t j = 0; j < buffer[i].size(); ++j) {
                std::cout << buffer[i][j];
            }
            std::cout << "\n";
        }
    }
};

class Window {
    int x, y, width, height;
    Screen& screen;

public:
    Window(Screen& scr, int startX, int startY, int startWidth, int startHeight) 
        : screen(scr), x(startX), y(startY), width(startWidth), height(startHeight) {}

    void moveWindow(int deltaX, int deltaY) {
        int newX = x + deltaX;
        int newY = y + deltaY;
        
        if (newX >= 0 && newX + width <= Screen::screenWidth && 
            newY >= 0 && newY + height <= Screen::screenHeight) {
            x = newX;
            y = newY;
            std::cout << "Window moved to (" << x << ", " << y << ")\n\n";
        } else {
            std::cout << "Wrong coordinates! Move failed.\n";
        }
    }

    void resizeWindow(int newWidth, int newHeight) {
        if (newWidth > 0 && newHeight > 0 && x + newWidth <= Screen::screenWidth && y + newHeight <= Screen::screenHeight) {
            width = newWidth;
            height = newHeight;
            std::cout << "Window resized to " << width << "x" << height << "\n\n";
        } else {
            std::cout << "Invalid size! The window must fit within the screen.\n";
        }
    }

    void display() {
        std::vector<std::vector<int>> buffer(Screen::screenHeight, std::vector<int>(Screen::screenWidth, 0));
        for (int i = y; i < y + height; ++i) {
            for (int j = x; j < x + width; ++j) {
                buffer[i][j] = 1;
            }
        }
        screen.display(buffer);
    }

    void close() {
        std::cout << "Close window! Exiting the program.\n\n";
    }
};

int main() {
    Screen screen;
    int x, y, width, height;
    
    std::cout << "Enter the initial dimensions and coordinates of the window!\n";
    while (true) {
        std::cout << "x, y: ";
        if (!(std::cin >> x >> y)) {
            std::cout << "Invalid input! Please enter integers.\n";
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            continue;
        }
        
        std::cout << "width, height: ";
        if (!(std::cin >> width >> height)) {
            std::cout << "Invalid input! Please enter integers.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
    
        if (x < 0 || y < 0 || width <= 0 || height <= 0 || x + width > Screen::screenWidth || y + height > Screen::screenHeight) {
            std::cout << "Incorrect coordinates or dimensions! The window must fit within the screen.\n";
            continue;
        }
        break;
    }
    
    Window window(screen, x, y, width, height);
    
    std::string command;
    while (true) {
        std::cout << "Enter command (move, resize, display, close): ";
        std::cin >> command;
        
        if (command == "move") {
            int deltaX, deltaY;
            std::cout << "Enter delta x and delta y: ";
            std::cin >> deltaX >> deltaY;
            window.moveWindow(deltaX, deltaY);
        } else if (command == "resize") {
            int newWidth, newHeight;
            std::cout << "Enter new width and height: ";
            std::cin >> newWidth >> newHeight;
            window.resizeWindow(newWidth, newHeight);
        } else if (command == "display") {
            window.display();
        } else if (command == "close") {
            window.close();
            break;
        } else {
            std::cout << "Unknown command!\n";
        }
    }
}