#include <iostream>
#include <cmath>

int main() {

  int K, N;
  int variable = 0;
  int result = 1; 
  
  std::cout << "Введите число которое необходимо возвести в степень!\n";
  std::cin >> K;
  std::cout << "Введите показтель степени\n";
  std::cin >> N;

  while (variable < N) {
    result *= K;
    variable += 1;
  }
  std::cout << "Результат равен " << result;
}