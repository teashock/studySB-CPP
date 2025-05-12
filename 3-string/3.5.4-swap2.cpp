#include <iostream>

int main() {

  std::cout << "Задача 2. Обмен местами.\n";
  std::cout << "------------------------\n";

  int a;
  int b;

  std::cout << "Введите значения переменных, которые необходимо поменять местами!\n";
  std::cout << "a: ";
  std::cin >> a;
  std::cout << "b: ";
  std::cin >> b;

  a = a + b;
  b = a - b;
  a = - b + a;

  std::cout << "------------------\n";
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n"; 

}