#include <iostream>

int main() {
  
  std::cout << "Двай проверим поймет ли робот вашу программу?\n";

  int program;
  std::cout << "Введите число состоящее из 0 и 1.\n";
  std::cin >> program;

  int number;

  while (program != 0) {
    number = program % 10;
    program /= 10;
  } if (number == 0 || number == 1) {
    std::cout << "Робот прочтет программу!";
  } else {
    std::cout << "Робот не сможет прочитать вашу программу!";
  }
}