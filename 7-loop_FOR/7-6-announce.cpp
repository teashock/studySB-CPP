#include <iostream>

int main() {
  std::cout << "Важное объявление!\n";
  
  int length;
  std::cout << "Введите длину колонтитула: ";
  std::cin >> length;
  if (length < 1) {
    std::cout << "Длина колонтитула не может быть меньше 1\n";
  } else {
    int sign = 0;
    std::cout << "Введите число восклицательных знаков в колонтитуле: ";
    std::cin >> sign;
    
    if (sign < 0 || sign > length) {
      std::cout << "Количество восклицательных знаков не может быть меньше 0 или больше длины строки.\n";
    } else {
      
      int start = length/2 - sign/2;
      
      for (int col = 0; col < length; col++) {
         if (col >= start && col < start + sign) {
           std::cout << "!";
         } else
         {
           std::cout << "~";
         }
      }
      std::cout <<"\n";
    }
  } 
}