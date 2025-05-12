#include <iostream>

std::string encrypt_caesar (std::string text, int shift) {
    
    std::string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            result += (text[i] - 65 + shift) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            result += (text[i] - 97 + shift) % 26 + 'a';
        } else 
        result += text[i];
    } 
    return result;
}

std::string decrypt(std::string text, int shift) {
    return encrypt_caesar(text, 0);
}

int main() {

    std::string text;
    std::cout << "Enter the encryption text: ";
    std::getline (std::cin, text); 

    int shift;
    std::cout << "How many characters shift the text?\n";
    std::cin >> shift;
    
    while (shift <= 0) {
        std::cout << "Error! The shift is greater than zero!\n";
        std::cout << "Enter the shift again!\n";
        std::cin >> shift;
    } 

    std::cout << "Encrypt text is: " << encrypt_caesar(text, shift) << "\n";
    std::cout << "Decrypt text is: " << decrypt(text, shift) << "\n";
}