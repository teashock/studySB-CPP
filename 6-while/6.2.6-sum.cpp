#include <iostream>

int main() {
  std::cout << "Посчитаем сумму чисел!\n";
  std::cout << "----------------------\n";

  int count;
  std::cout << "Сколько чисел Вам необходимо сложить?\n";
  std::cin >> count;
  int add = 0;
  int sum = 0;

  while (add < count) {
    int a;
    std::cout << "Введите " << add + 1 << "-е число\n";
    std::cin >> a;
    add += 1;
    sum += a;
  } std::cout << "Сумма чисел равна " << sum << ".\n";  
}