#include <iostream>

int main() {
  std::cout << "------Программа-гадалка----!\n";
  std::cout << "Загадайте число от 0 до 63!\n";
  std::cout << "Готовы?\n";
  std::cout << "Приступим!\n";

  int min = 0, max = 63, mid;
  std::string answer;
  while (min < max) {
    mid = (min + max) / 2;
    std::cout << "Ваше число больше " << mid << "? (да/нет)\n";
    std::cin >> answer;
    if (min == max) {
      break;
    } else if (answer == "да") {
      min = mid + 1;
    } else if (answer == "нет") {
      max = mid;
    } 
  } 
  if (answer == "да") {
    std::cout << "Вы загадали число " << mid+1;
  } else
  std::cout << "Вы загадали число " << mid;
}