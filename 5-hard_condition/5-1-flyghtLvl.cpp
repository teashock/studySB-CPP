#include <iostream>

int main() {
  std::cout << "Проверка правильности эшелона полета самолета!\n";
  std::cout << "      ==================================\n";

  int speed, height;
  std::cout << "Введите скорость самолета: ";
  std::cin >> speed;
  std::cout << "Введите высоту полета самолета: ";
  std::cin >> height;

  if ((speed >= 750 && speed <= 850) && (height >= 9000 && speed <= 9500)) {
    std::cout << "Самолет летит правильным эшелоном!";
  } else {
    std::cout << "Самолет летит не правильным эшелоном!";
  }
  
}