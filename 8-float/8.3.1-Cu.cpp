#include <iostream>

int main() {
  std::cout << "Конвертер чатлов в КЦ и грвицапы!\n";

  int chatli;
  std::cout << "Введите Ваше количество чатлов: ";
  std::cin >> chatli;

  float gravicap = float (chatli) / 2200.0f;
  float kc = 0.5f * gravicap;

  std::cout << chatli << " чатлов можно обменять на: \n";
  std::cout << "\t" << kc << " КЦ\n";
  std::cout << "\t" << gravicap << " гравицап\n";
}