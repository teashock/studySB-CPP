#include <iostream>

int main() {
  int productPrice;
  int deliveryPrice;
  int discount;
  
  std::cout << "Введите стоимость товара в рублях\n";
  std::cin >> productPrice;
  std::cout << "Введите стоимость доставки в рублях\n";
  std::cin >> deliveryPrice;
  std::cout << "Введите скидку в рублях\n";
  std::cin >> discount;

  int fullPrice = productPrice + deliveryPrice - discount;

  std::cout << "_______________________\n";
  std::cout << "Стоимость товара: " << productPrice << " руб.\n";
  std::cout << "Стоимость доставки: " << deliveryPrice << " руб.\n";
  std::cout << "Скидка: " << discount << " руб.\n";
  std::cout << "_______________________\n";
  std::cout << "Итоговая стоимость товара: " << fullPrice << " руб.\n";
}