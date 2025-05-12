#include <iostream>

int main() {
  int productCost;
  int deliveryCost;
  int discount;
  std::cout << "Введите стоимость товара: ";
  std::cin >> productCost;
  std::cout << "Введите стоимость доставки: ";
  std::cin >> deliveryCost;
  std::cout << "Скидка: ";
  std::cin >> discount;

  if (productCost > 10000) {
    deliveryCost /= 2;
  std::cout << "Стоимость товара превышает 10000 рублей.\n";
  std::cout << "Поэтому вы получается скидку на доставку!\n";
  }
  
  int price = productCost + deliveryCost - discount;
  std::cout << "----------------------\n";
  std::cout << "Полная стоимость товаара:" << price << "\n";

  
  
}