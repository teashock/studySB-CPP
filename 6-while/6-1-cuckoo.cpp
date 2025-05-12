#include <iostream>

int main() {
  std::cout << "Проверка часов с кукушкой!\n";
  std::cout << "Обратите внимание, что часы 12 часового формата!\n";

  int hour;
  std::cout << "Укажите который час?\n";
  std::cin >> hour;

  if (hour >= 1 && hour <= 12) {
    int signal = 0;
    while (signal < hour) {
      std::cout << "Ку-ку!\n";
      ++ signal;
    }
  } else {
    std::cout << "Введен неверный час!";
  }
}