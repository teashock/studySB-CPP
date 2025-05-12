# include <iostream>

int main() {
  std::cout << "Проверка числа на четность!\n";
  std::cout << "-------------------------\n";

  int x;

  std::cout << "Введите четное число: ";
  std::cin >> x;
  std::cout << "----Проверяем----\n";

  if (x % 2 == 0) {
    std::cout << "Число: " << x << " - четное!";
    } else {
    std::cout << "Число: " << x << " - нечетное!";
  }
}