#include <iostream>

int main() {
    std::cout << "Counting the number of words!\n";
    std::cout << "Input your text: ";
    std::string text;
    std::getline(std::cin, text);
    
    int words = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            words++;
            while (text[i] != ' ' && i < text.length())
                i++;
            }
        }
   std::cout << "Your text contains " << words << " words!\n";
}