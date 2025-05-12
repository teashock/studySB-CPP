#include <iostream>

int main() {
  std::cout << "Проверка пароля!\n";
  
  int password, check = 0;
  std::cout << "Задайте свой пароль\n";
  std::cin >> password;

  for (; check != password;) {
    std::cout << "Введите пароль: ";
    std::cin >> check;
    if (check != password)  {
      std::cout << "Пароль неверный!\n";
    }
  }
  std::cout << "Пароль верный!\n";
}