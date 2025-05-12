#include <fstream>
#include <iostream>

int main() {
    std::cout << "Fruits search! \n";
    std::ifstream words;
    words.open("C:\\develop\\skillbox\\profession-c-plus-plus\\lesson-19-read-from-a-files\\task-1\\task-1-words.txt");
    if (!words.is_open()) {
        std::cout << "The file cannot be opened!";
        return 0;
    } else {
        std::string fruits;
        std::cout << "Input a word to find a fruits: ";
        std::cin >> fruits;
        
        int count = 0;
        std::string word;
        while (words >> word) {
            if (word == fruits) {
                ++count;
            }
        }
    std::cout << "The word \"" << fruits << "\" appears in the text " << count << " times.";
    }
    words.close();
}