#include <iostream>

int main() {
  std::cout << "Винни-Пух и день забот!\n";
  std::cout << "=======================\n";

  int a, b, c, x, y;

  std::cout << "Введите 3 размера кирпича:\n";
  std::cin >> a >> b >> c;
  std::cout << "Введите размеры отверстия в стене:\n";
  std::cin >> x >> y;

  if (x >= a && (y >= b || y >= c)) {
    std::cout << "Кирпич входит!";
  } else if (x >= b && (y >= a || y >= c)) {
     std::cout << "Кирпич входит!";
  } else if (x >= c && (y >= a || y >= b)) {
     std::cout << "Кирпич входит!";
  } else {
     std::cout << "Кирпич не входит!";
  }
}