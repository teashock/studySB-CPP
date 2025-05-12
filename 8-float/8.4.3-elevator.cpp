#include <iostream>
#include <cmath>

int main() {
  std::cout << "Где лифт Burj Khalifa!?\n";

  float H;
  std::cout << "На какой высоте находится лифт: ";
  std::cin >> H;

  if (H <= 0) {
  std::cout << "Вы ввели неверную высоту!\n"; 
  } else{
  std::cout << "Лифт находится на " << std::round(H / 3.975) << " этаже";
  }
}