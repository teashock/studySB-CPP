#include <iostream>

int main() {
  std::cout << "Определение високосного года!\n";
  std::cout << "-----------------------------\n";

  int year;

  std::cout << "Введите год! ";
  std::cin >> year;
  std::cout << "Вычисляем год\n";
  std::cout << "-------------\n";

  if (year % 4 == 0) {
    if (year % 400 != 0) {
      if (year % 100 == 0) {
        std::cout << "Год не високосный";
      } 
    } 
  } else if (year % 4 != 0) {
        std::cout << "Год високосный!";
    } else {
    std::cout << "Год не високосный!";
  }
}
