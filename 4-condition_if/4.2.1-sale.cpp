#include <iostream>

int main() {
  
  int firstProductCost;
  int secondProductCost;
  int thirdProductCost;
  int discount;

  std::cout << "Введите стоимость первого товара: ";
  std::cin >> firstProductCost;
  std::cout << "Введите стоимость второго товара: ";
  std::cin >> secondProductCost;
  std::cout << "Введите стоимость третьего товара: ";
  std::cin >> thirdProductCost;
  int productCost = firstProductCost + secondProductCost + thirdProductCost;
  std::cout << "----------------------\n";
  std::cout << "Стоимость товаров: " << productCost << ".\n";

   if (productCost > 10000) {
     discount = productCost / 10;
     productCost = productCost - discount;
     std::cout << "Стоимость товаров превышает 10000 рублей.\n";
     std::cout << "Поэтому вы получается скидку 10%! Скидка равняется " << discount << ".\n";
  }

  std::cout << "----------------------\n";
  int totalCost = productCost;
  std::cout << "Итоговая стоимость товаров: " << totalCost << "\n";
  
}