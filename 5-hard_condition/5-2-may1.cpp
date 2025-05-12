#include <iostream>

int main() {
  
  std::cout << "Майский календарь!\n";
  std::cout << "==================\n";\

  int mayDay;

  std::cout << "Введите день мая, чтобы узнать это выходной или рабочий день!\n";
  std::cin >> mayDay;

  if ((mayDay >= 1 && mayDay <= 5) || (mayDay >=8 && mayDay <= 10) || (mayDay % 7 == 0) || (mayDay % 7 == 6)) {
    std::cout << "Выходной!";
  } else {
    std::cout << "Рабочий день :(";
  }
}