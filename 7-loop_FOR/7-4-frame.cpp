#include <iostream>

int main() {
  std::cout << "Нарисуй рамку!\n";

  int width, height;
  std::cout << "Введите ширину и высоту рамки: ";
  std::cin >> width >> height;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      if (col == 0) {
        std::cout << "|";
      } else if (col == width - 1) {
        std::cout << "|\n";
      } else if (row == 0 || row == height - 1) {
        std::cout << "-";
      } else {
        std::cout << " ";
      }
    }
  }
}