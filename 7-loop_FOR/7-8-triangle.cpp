#include <iostream>

int main() {
  std::cout << "Ёлочка!\n";
  
  int height;
  std::cout << "Введите высоту елочки: ";
  std::cin >> height;
  
  int lenght = (height - 1) * 2 + 1;
  if (height <= 0) {
    std::cout << "Недопустимая высота треугольника.\n";
  } else {
    for (int row = 0; row < height; row++) {
      int start = lenght/2 - row;
      int end = lenght/2 + row;
      
      for (int col = 0; col < lenght; col++) {
        if (col < start) {
          std::cout << " ";
        } else if (col > end) {
          std::cout <<  "\n";
          break;
        } else
        {
          std::cout << "#";
        }
      }
    }
    std::cout << "\n";;
  }
}