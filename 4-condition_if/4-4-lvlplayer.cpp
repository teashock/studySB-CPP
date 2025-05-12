#include <iostream>

int main() {
  std::cout << "Расчет уровня игрока!\n";
  std::cout << "---------------------\n";

  int exp;

  std::cout << "Введите полученное количество очков опыта: ";
  std::cin >> exp;
  std::cout << "-----Считаем Ваш уровень!-----\n";

  if (exp >= 5000) {
    std::cout << "Ваш уровень: 4!";
  } else if (exp >= 2500) {
    std::cout << "Ваш уровень: 3!";
  } else if (exp >= 1000) {
    std::cout << "Ваш уровень: 2!";
  } else if (exp == 0) {
    std::cout << "Ты слишком слабый! Возможно самый слабый.";
  } else if (exp < 0) {
    std::cout << "Такого опыта не может быть!!!";
  } else {
    std::cout << "Ваш уровень: 1";
  }
}