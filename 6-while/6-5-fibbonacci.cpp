#include <iostream>

int main () {
  std::cout << "===Числа Фибоначчи===\n";

  int N;
  std::cout << "Введите порядковый номер N числа Фибоначчи для его вывода!\n";
  std::cin >> N;

  if (N <= 0) {
  std::cout << "Порядковый номер числа Фибоначчи не может быть отрицательным и равняться 0!\n";
  } else {  
    int count = 1, fib, fib1 = 0, fib2 = 1;
    while (count <= N) {
      fib = fib2;
      fib2 += fib1;
      fib1 = fib;
      ++count;
    }  
    if (count > 47) {
      std::cout << "Значение не может быть выдано!";
    } else {std::cout << "Значение числа Фибаначчи N=" << N <<  " равно " << fib << "\n";
    }
  }
}