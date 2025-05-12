#include <iostream>
#include <fstream>

int main() {
    std::cout << "File reader!\n";
    const int fileSize = 1000;
    std::string path;
    std::ifstream file;
    std::cout << "Enter a path to the file: ";
    std::cin >> path;

    file.open(path,std::ios::binary);
    if (!file.is_open()) {
        std::cout << "The file cannot be opened! Incorret path!\n";
    } else {
        while (!file.eof()){
            char buffer[fileSize];
            file.read(buffer, sizeof(buffer));
            
            if (file.gcount() > 0) {
                buffer[file.gcount()] = 0;
                std::cout << buffer;
            }
        }       
    }
    file.close();
}