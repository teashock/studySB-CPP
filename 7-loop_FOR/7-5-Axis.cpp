#include <iostream>

int main() {
  std::cout << "Координатная плоскость!\n";
  
  int X, Y;
  std::cout << "Введите координаты плоскости X и Y: ";
  std::cin >> X >> Y;

  for (int row = 0; row < Y; row++) {
    for (int col = 0; col < X; col++) {
      if (row == 0 && ((col == X / 2 - 1 && X % 2 == 0) || (col == X / 2 && X % 2 == 1))) {
        std::cout << "^";
      } else if (col == X - 1 && row == Y / 2) {
        std::cout << ">";
      } else if (((col == X / 2 - 1 && X % 2 == 0) || (col == X / 2 && X % 2 == 1)) && row != Y / 2)  {
        std::cout << "|";
      } else if (row == Y / 2 && ((col == X / 2 - 1 && X % 2 == 0) || (col == X / 2 && X % 2 == 1))) {
        std::cout << "+";
      } else if (row == Y / 2) {
        std::cout << "-";
      } else std::cout << " ";
    } std::cout << "\n";
  } 
}