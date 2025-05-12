#include <iostream>

int main() {
  int productPrice = 4990;
  int deliveryPrice = 300;
  int discount = 500;
  
  int fullPrice = productPrice + deliveryPrice - discount;
  
  std::cout << "Стоимость товара: " << productPrice << " руб.\n";
  std::cout << "Стоимость доставки: " << deliveryPrice << " руб.\n";
  std::cout << "Скидка: " << discount << " руб.\n";
  std::cout << "_______________________\n";
  std::cout << "Итоговая стоимость товара: " << fullPrice << " руб.\n";
}