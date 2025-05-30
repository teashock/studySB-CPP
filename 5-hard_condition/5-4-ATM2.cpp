#include <iostream>

int main() {
  
  std::cout << "Банкомат - 2!\n";
  std::cout << "=============\n";

  int money;

  std::cout << "Внимание!\n";
  std::cout << "Банкомат выдает купюры номиналом в 100, 200, 500, 1000, 2000 и 5000 рублей!\n";
  std::cout << "Максимальная сумма денежных средств доступная к выдаче 150 000 рублей\n";
  std::cout << "Введите сумму денежных средств, которую необходимо выдать!";
  std::cin >> money;

  if (money > 150000) {
    std::cout << "Ошибка! Сумма не может превышать более 150 000 рублей!";
  } else if (money <= 0) {
    std::cout << "Ошибка! Введена неверная сумма денежных средств!";
  } else if (money % 100 != 0) {
    std::cout << "Внимание! Сумма должна быть кратна 100!"; 
  } else {
    if (money >= 5000) {
      std::cout << "Выдача " << money / 5000 << " купюр номиналом 5000 рублей.\n";
      money %= 5000;
  } if (money >= 2000) {
      std::cout << "Выдача " << money / 2000 << " купюр номиналом 2000 рублей.\n";
      money %= 2000;
  } if (money >= 1000) {
      std::cout << "Выдача " << money / 1000 << " купюр номиналом 1000 рублей.\n";
      money %= 1000;
  } if (money >= 500) {
      std::cout << "Выдача " << money / 500 << " купюр номиналом 500 рублей.\n";
      money %= 500;
    } if (money >= 200) {
      std::cout << "Выдача " << money / 200 << " купюр номиналом 200 рублей.\n";
      money %= 200;
    } if (money >= 100) {
      std::cout << "Выдача " << money / 100 << " купюр номиналом 100 рублей.\n";
      money %= 100;
    }
  }
}