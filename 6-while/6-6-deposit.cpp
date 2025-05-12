#include <iostream>

int main() {
  std::cout << "Выголный вклад в нашем банке!\n";
  std::cout << "Давайте рассчитаем, за какой срок Вы накопиите желаемую сумму!\n";
    
  int deposit, percent, capital, year = 0;
  std::cout << "Введите сумму первоначального вклада: ";
  std::cin >> deposit;
  std::cout << "Введите процентную ставку: ";
  std::cin >> percent;
  std::cout << "Введите желаемую сумму: ";
  std::cin >> capital;


  while (deposit < capital) {
    deposit += (deposit * percent / 100);
    year += 1;
  }
  std::cout << "Для получения желаемой суммы необходимо подождать " << year << " (года) лет";
}