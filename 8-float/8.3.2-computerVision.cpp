#include <iostream>

int main() {
  std::cout << "Машинное зрение!\n";

  while (true) {
    float locationX, locationY;
    std::cout << "Введите местоположение фигуры: ";
    std::cin >> locationX >> locationY;

    if (locationX >= 0.8f || locationY >= 0.8f) {
      std::cout << "Ошибка! Размеры доски 0.8 х 0.8 м!";
    } else if (locationX < 0.0f || locationY < 0.0f) {
      std::cout << "Координаты не могут быть отрицательными!";
    } else {
      std::cout << "Фигура находится в клетке (" << (int)  (locationX * 10.0f) << ", " << (int) (locationY * 10.0f) << ")\n";
    }
  }  
}