#include <iostream>

int main() {
  int a;
  int b;
  
  std::cout << "Введите число, в отношении которого необходимо найти модуль: ";
  std::cin >> a;
  b = a;
  
  if (b < 0) {
    b = - b;
  }

  std::cout << "Модуль числа " << a << " равняется " << b << ".\n";
  
}