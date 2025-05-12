#include <iostream>

int main() {
  std::cout << "Помощь Араику!\n";

  float money, weight, cost;
  std::cout << "Введите цену товара за 100 грамм: ";
  std::cin >> money;
  std::cout << "Введите итоговый вес покупки (грамм): ";
  std::cin >> weight;
  
  cost = money * weight / 100;

  std::cout << "Стоимость покупки составляет " << cost << " рублей";
  
}