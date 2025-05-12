#include <iostream>

int main() {
  int number;
  std::cout << "Введите число!\n";
  std::cin >> number;

  while (number != 0) {
    std::cout << number % 10;
    number /= 10;
  }
}