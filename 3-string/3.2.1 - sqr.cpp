#include <iostream>

int main() {
  int a;
 
  std::cout << "Введите число, которое необходимо возвести в квадрат\n";
  std::cin >> a;

  int sqr = a * a;
  
  std::cout << "Квадрат числа " << a << " равен " << sqr << "\n";
}
