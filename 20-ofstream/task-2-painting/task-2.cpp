#include <iostream>
#include <fstream>
#include <ctime>

int main() {
    std::cout << "The binary picture!\n";
    std::srand(std::time(nullptr));
    std::string pathFile;
    int height, width;
    std::cout << "Enter height and width picture: ";
    std::cin >> height >> width;
    if (height <= 0 || width <= 0) {
        std::cout << "Height and width must be positive integers.\n";
    }
    std::cout << "Enter path to picture file: ";
    std::cin >> pathFile;
    std::ofstream picture (pathFile, std::ios::app);
    if (!picture.is_open()) {
        std::cout << "Could not open the file\n";
        return 0;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int count = std::rand() % 2;
            picture << count << " ";
        }
        picture << "\n";
    }
    picture << "\n";
    picture.close();
}