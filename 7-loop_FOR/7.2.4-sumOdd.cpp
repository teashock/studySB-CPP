#include <iostream>

int main() {
  std::cout << "Сумма нечетных чисел!\n";

  int number, sum = 0;
  std::cout << "Введите число, до которого необходимо посчитать сумму нечетных чисел ";
  std::cin >> number;

  for (int count = 1; count <= number; count ++) {
    if (count % 2 != 0) 
      sum += count;
      }
  std::cout << "Сумма равна " << sum << "\n";
}