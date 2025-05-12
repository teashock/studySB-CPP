#include <iostream>
#include <fstream>

int main() {
    std::cout << "PNG file detector!\n";
    std::string path;
    std::ifstream file;
    const int bufSize = 1000;
    std::cout << "Enter a path to the file: ";
    std::cin >> path;
    file.open(path, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "The file cannot be opened! Incorret path, file not found!\n";
    } else {
        char buffer[bufSize];
        file.read(buffer, sizeof(buffer));
        if ((buffer[0] == (char)-119) && (buffer[1] == 'P') && (buffer[2] == 'N') && (buffer[3] == 'G') && (path.substr(path.length() - 4, 4) == ".png")) {
            std::cout << "Yes! This is PNG file!\n";
        } else {
            std::cout << "Oh no! This is not PNG file!\n";
        }
    }
    file.close();    
}