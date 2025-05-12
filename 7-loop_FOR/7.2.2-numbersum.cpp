#include <iostream>

int main() {
  std::cout << "Помощь бухгалтеру!\n";

  int N, money, sum = 0;
  std::cout << "Введите количество чисел подлежащих суммированию ";
  std::cin >> N;

  for (int count = 1; count <= N; count++) {
    std::cout << "Введите " << count << " число: ";
    std::cin >> money;
    sum += money;
  }
  std::cout << "Cумма чисел равна: " << sum;
}