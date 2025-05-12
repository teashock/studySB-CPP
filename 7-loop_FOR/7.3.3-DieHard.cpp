#include <iostream>

int main() {
  std::cout << "Крепкий орешек!\n";

  std::cout << "Внимание скоро взорвется бомба!!!\n";
  std::cout << "Скорее сделайте что нибудь!\n";

  std::string answer;
  int N = 10, time = 0;

  for (; time < 10; time++) {
    std::cout << "Вы хотите обезвредить бомбу?\n";
    std::cin >> answer;
    N--;
    if (answer == "да") {
      break;
    } else {
      std::cout << "У вас осталось " << N << " шагов до взрыва\n";
    } 
    ;
  }
  
  if (answer == "нет") {
    std::cout << "Увы вы взорвались!";
  } else
  std::cout << "Ура! бомба обезврежена!\n";
  std::cout << "До взрыва осталось " << N << " шагов\n";
}