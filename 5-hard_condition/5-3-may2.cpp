#include <iostream>

int main() {

  std::cout << "Майский календарь!\n";
  std::cout << "==================\n";\

  int mayDay;
  int firstDayMonth;

  std::cout << "Введите номер дня недели (от 1 до 7), с которого начинается май!\n";
  std::cin >> firstDayMonth;
  if (firstDayMonth > 7 || firstDayMonth < 1) {
    std::cout << "Ошибка! Вы ввели неверный номер недели!";
  }
  
  std::cout << "Введите день мая, чтобы узнать это выходной или рабочий день!\n";
  std::cin >> mayDay;
  if (mayDay > 31 || mayDay < 0) {
    std::cout << "Ошибка! Вы ввели неверную дату!";
  }

  if ((mayDay >= 1 && mayDay <= 5) || (mayDay >=8 && mayDay <= 10) || ((mayDay + firstDayMonth - 1) % 7 == 0) || ((mayDay + firstDayMonth - 1) % 7 == 6)) {
    std::cout << "Выходной!";
  } else {
    std::cout << "Рабочий день :(";
  }
}