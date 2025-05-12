#include <iostream>

int main() {
  std::cout << "Отчет начальнику!\n";
  std::cout << "Помните, начальник очень строгий и требует точного ответа \"Да, кончено, сделал!\"\n";
  
  int N = 0;
  for (std::string answer; answer != "Да, конечно, сделал!"; N++) {
    std::cout << "Вы сделали свою работу?\n";
     std::getline (std::cin, answer);
  }
  std::cout << "Ну почему тебя нужно спрашивать " << N << " раз?";
}