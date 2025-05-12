#include <iostream>

int main() {
  std::cout << "Пора обедать\n";
  std::cout << "=============\n";

  int N;
  
  std::cout << "Введите количество наггетсов, которое хочет купить Вася: ";
  std::cin >> N;

  if (N % 6 == 0 || N % 9 == 0 || N % 6 == 3) {
    std::cout << "Заказ принят!";
  } else {
    std::cout << "Заказ не принят!";
  }
}