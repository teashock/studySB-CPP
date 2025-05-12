#include <iostream>

int main() {
  std::cout << "----Робот-коллектор----\n";
  
  std::cout << "Введите Ваше имя!\n";
  std::string name;
  std::cin >> name;
  
  std::cout << "Какова Ваша сумма долга?\n";
  std::cout << "(Обратите внимание сумма долга не может быть отрицательной!)\n";
  int debt;
  std::cin >> debt;
  
  if (debt < 0) {
    std::cout << name << "! Вы ввели неверную сумму долга!\nСумма долга не может быть отрицательной!\n";
  } else {
    int totalPayment = 0;
    bool repaid = totalPayment >= debt;
    while (!repaid) {
      int payment;
      std::cout << name << "! Какую сумму долга вы вносите?\n";
      std::cin >> payment;
      if (payment <= 0) {
        std::cout << "Вам осталось внести " << debt - totalPayment << ".\n";
      } else {
        totalPayment += payment;
        repaid = totalPayment >= debt;
        std::cout << name << "! Итого вы внесли " << totalPayment << ".\n";
        if (totalPayment < debt) {
          std::cout << name << "! Вам осталось внести " << debt - totalPayment << ".\n";
        }
      }
    }
    std::cout << name << ", поздравляем Вас! У Вас нет долга!\n";
    if (totalPayment - debt > 0) {
      std::cout << name << "! На Вашем счете осталось " << totalPayment - debt << " средств.\n";
    }
  }
}