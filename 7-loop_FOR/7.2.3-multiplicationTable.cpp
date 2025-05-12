#include <iostream>

int main() {
  std::cout << "Таблица умножения\n";

  int number, multiplication;
  std::cout << "Введите число, для которого необходимо составить таблицу умножния";
  std::cin >> number;

  for (int count = 1; count <= 10; count ++) {
    multiplication = number * count;
    std::cout << number << " x " << count <<  " = " << multiplication << "\n";
  }
}