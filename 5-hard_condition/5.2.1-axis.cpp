#include <iostream>

int main() {
  std::cout << "** Координатная плоскость ** \n";
  std::cout << "-----------------------------\n";

  int x, y;

  std::cout << "Введите координату X: ";
  std::cin >> x;
  std::cout << "Введите координату Y: ";
  std::cin >> y;
  std::cout << " ** Расчет плоскости ** \n";
  std::cout << "-----------------------------\n";

  if (x > 0 && y > 0) {
    if (y > 0) {
      std::cout << "Точка лежит в первой четверти плоскости";
    } else if (y < 0) {
      std::cout << "Точка лежит в четвертой четверти плоскости";
    } else {
      std::cout << "Точка лежит на границе I и IV плоскостей";
    }
  } else if (x < 0) {
    if (y > 0) {
      std::cout << "Точка лежит во второй четверти плоскости";
    } else if (y < 0) {
      std::cout << "Точка лежит в третьей четверти плоскости";
    } else {
      std::cout << "Точка лежит на границе II и III плоскостей";
    }
  } else { 
    if (y > 0) {
      std::cout << "Точка лежит на границе I и II плоскостей";
    } else if (y < 0) {
      std::cout << "Точка лежит на границе III и IV плоскостей";
    } else {
      std::cout << "Точка лежит в начале координат";
    }
  }
}