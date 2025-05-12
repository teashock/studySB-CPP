#include <iostream>

int main() {
  std::cout << "Давай проверим, как хорошо ты считешь в уме!\n";
  std::cout << "-------------------------\n";

  int a;
  int b;
  int sum;

  std::cout << "Введите первое число: ";
  std::cin >> a;
  std::cout << "Введите второе число: ";
  std::cin >> b;
  std::cout << "Введите их сумму: ";
  std::cin >> sum;
    std::cout << "----Проверяем----\n";

  if (a+b == sum) {
    std::cout << "Верно!";
    } else {
    sum = a + b;
    std::cout << "Ошибка!\n";
    std::cout << "Верный результат: " << sum;
  }
}