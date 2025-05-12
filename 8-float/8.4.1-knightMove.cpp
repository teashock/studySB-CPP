#include <iostream>
#include <cmath>

int main() {
  std::cout << "Машинное зрение!\n";

  while (true) {
    float startX, startY, moveX, moveY;
    std::cout << "Введите местоположение коня: ";
    std::cin >> startX >> startY;
    std::cout << "Введите местоположение точки: ";
    std::cin >> moveX >> moveY;


    if (startX >= 0.8f || startY >= 0.8f || moveX >= 0.8f || moveY >= 0.8f) {
      std::cout << "Ошибка! Размеры доски 0.8 х 0.8 м!";
    } else if (startX < 0.0f || startY < 0.0f || moveX < 0.0f || moveY < 0.0f) {
      std::cout << "Координаты не могут быть отрицательными!";
    } else {
      std::cout << "Конь находится в клетке (" << (int)  (startX * 10.0f) << ", " << (int) (startY * 10.0f) << ")\n";
      std::cout << "Точка для перемещения коня находится в клетке (" << (int)  (moveX * 10.0f) << ", " << (int) (moveY * 10.0f) << ")\n";
      if (((std::abs ((int) (startX * 10.0f) - (int) (moveX * 10.0f)) == 1) || (std::abs ((int) (startX * 10.0f) - (int) (moveX * 10.0f)) == 2)) && ((std::abs ((int) (startY * 10.0f) - (int) (moveY * 10.0f)) == 1) || (std::abs ((int) (startY * 10.0f) - (int) (moveY * 10.0f)) == 2))) {
      std::cout << "Конь может передвинуться на эту точку!\n";
      } else { 
      std::cout << "Конь не может перейти в эту точку!\n";
      }
    }
  }  
}