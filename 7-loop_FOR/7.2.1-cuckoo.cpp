#include <iostream>

int main() {
  std::cout << "Часы с кукушков FOR!\n";
  
  int hours;
  std::cout << "Введите, который час должна пробить кукушка? (Обратите внимние! Часы имеют 12-ти часовой формат!\n";
  std::cin >> hours;

  if (hours <= 0 || hours > 12) {
    std::cout << "Вы ввели неверное время! Время не может быть отрицательным, равняться 0 и больше 12 часов!";
  }
  for (int count = 0; count < hours; count++) {
    std::cout << "Ку-ку\n";
  }
  
}