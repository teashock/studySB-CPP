#include <iostream>

int main() {
  
  std::cout << "Треугольник!\n";
  std::cout << "============\n";

  int A, B, C;

  std::cout << "Введите стороны треугольника: \n";
  std::cin >> A >> B >> C;

  if (A + B <= C || A + C <= B || B + C <= A) {
    std::cout << "По данным длиннам палочек треугольник сложить невозможно!";
  } else {
    std::cout << "Треугольник сложить возможно!";
  }
}