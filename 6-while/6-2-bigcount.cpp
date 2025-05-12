#include <iostream>

int main() {
  std::cout << "Помощь бухгалтеру!\n";
  std::cout << "Расчет количества цифр в числе\n";
  
  int number;
  std::cout << "Введите число!\n";
  std::cin >> number;

  int count = 0;
  if (number == 0) {
    std::cout << "Во введенном числе количесто цифр равно " << count + 1;
  } else { 
    while (number != 0) {
      ++ count;
      number /= 10;
    }
  std::cout << "Во введенном числе количесто цифр равно " << count;
  }
}