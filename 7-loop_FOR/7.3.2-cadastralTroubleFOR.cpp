#include <iostream>

int main() {
  std::cout << "Кадастровые проблемы!\n";
  
  int sqr, number = 0, check = 0;
  std::cout << "Введите площадь участка: ";
  std::cin >> sqr;

  for (; check < sqr; number++) {
    check = number * number;
  }
  if (check == sqr) {
    std::cout << "На этот участок есть скидка!";
  } else {
    std::cout << "Скидка на этот участок отсутствует!";
  }
 }