#include <iostream>

int main() {
  
  std::cout << "О чем бы вы хотели не забыть?\n";
  std::string reminder;
  std::getline(std::cin, reminder);

  int count;
  std::cout << "Сколько раз Вам об этом напомнить?\n";
  std::cin >> count;
  int add = 0;

  do { 
  std::cout << reminder << "\n";
      add += 1;
  } while (add <= count);
}