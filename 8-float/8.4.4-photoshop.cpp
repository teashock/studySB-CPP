#include <iostream>

int main() {
  std::cout << "Photoshop killer!\n";

  float leftGradient, rightGradient, point;

  std::cout << "Введите яркость левой границы градиента (от 0 до 255): ";
  std::cin >> leftGradient;
  std::cout << "Введите яркость правой границы градиента (от 0 до 255): ";
  std::cin >> rightGradient;
  std::cout << "Введите положение точки между границами (от 0 до 1): ";
  std::cin >> point;

  if (leftGradient < 0 || leftGradient > 255 || rightGradient < 0 || rightGradient > 255) {
    std::cout << "Вы ввели неверную границу градиента!\n";
  } else if (point < 0 || point > 1) {
    std::cout << "Вы ввели неверное положение точки!\n";
  } else {
    std::cout << "Яркость точки " << leftGradient + (rightGradient - leftGradient) * point << ".\n";
  }
}