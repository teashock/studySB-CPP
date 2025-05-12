#include <iostream>

int main () {
  std::cout << "===Счастливый билетик===\n";

  int digit;
  int digitCount;
  std::cout << "Введите количество цифр в билете.\n";
  std::cin >> digitCount;
  std::cout << "Введите номер билета, состоящего из " << digitCount << " цифр: \n";
    std::cin >> digit;

    int a = 1;
    int RightDigits = 0;
    int LeftDigits = 0;

    while (a <= digitCount) {
        if (a <= digitCount / 2) {
          RightDigits += digit % 10;
        } else {
          LeftDigits += digit % 10;
        }
        digit = digit / 10;
      ++a;
    }
    if (RightDigits == LeftDigits) {
      std::cout << "Билет счастливый!\n";
    } else {
      std::cout << "Повезет в следующий раз!\n";
    }
}