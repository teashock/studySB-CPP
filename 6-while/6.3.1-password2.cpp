#include <iostream>

int main() {

  int password;
  std::cout << "Введите пароль любой длины!\n";
  std::cout << "Обратите внимание, что сумма чисел в пароле должна равняться 42!\n";
  std::cin >> password;

  int sum = 0;
  while (password != 0) {
    sum += password % 10;
    password /= 10;
  } 
  if (sum == 42) std::cout << "Пароль корректный!";
  else std::cout << "Пароль некорректный!";  
}