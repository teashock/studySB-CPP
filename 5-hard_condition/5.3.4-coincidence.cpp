#include <iostream>

int main() {
  
  std::cout << "Совпадение чисел.\n";
  std::cout << "=================\n";

  int a, b, c;

  std::cout << "Введите три числа!\n";
  std::cin >> a >> b >> c;

  if (a == b && b == c) {
    std::cout << "3 совпадающих числа";
  } else if (a == b || a == c || b == c) {
    std::cout << "2 совпадающих числа";
  } else {
    std::cout << "0 cовпадающих числа";
  }
}