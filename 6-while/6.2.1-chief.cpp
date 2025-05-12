#include <iostream>

int main() {
  std::string answer;
  do {
    std::cout << "Выполнили ли вы свои задания на сегодня?\n";
    std::getline (std::cin, answer);
  } while (answer != "Да, конечно сделал!");
  std::cout << "Молодец!";
}