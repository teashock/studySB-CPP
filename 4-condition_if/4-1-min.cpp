#include <iostream>

int main() {
  std::cout << "Поиск минимального числа!\n";
  std::cout << "-------------------------\n";

  int a;
  int b;

  std::cout << "Введите первое число: ";
  std::cin >> a;
  std::cout << "Введите второе число: ";
  std::cin >> b;
  std::cout << "----Проверяем----\n";
  
  if (a > b) {
    std::cout << "Наименьшее число: " << b;
    } else if (a == b) {
    std::cout << "Числа равны!\n";
    } else {
    std::cout << "Наименьшее число: " << a;
  }
}