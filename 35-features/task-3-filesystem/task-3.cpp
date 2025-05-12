#include <iostream>
#include <filesystem>

int main() {
    std::string enterPath;
    std::cout << "Input path: ";
    std::cin >> enterPath;
    std::filesystem::path path(enterPath);
    std::string extension = ".cpp";

    if (!std::filesystem::exists(path)) {
        std::cerr << "Error: The specified path does not exist." << std::endl;
        return 1;
    }

    auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, const std::string extension) {
        for(auto &p : std::filesystem::recursive_directory_iterator(path))
        {
            if(!p.path().extension().compare(extension)){
                std::cout << p.path() << std::endl;
            }
        }
    };

    recursiveGetFileNamesByExtension(path, extension);
}