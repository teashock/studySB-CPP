#include <iostream>
#include <limits>

int main() {

  std::string username;
  std::string answer;

  std::cout << "Как тебя зовут?\n";
  std::getline(std::cin, username);
  std::cout << username << ", купи слона!\n";

  do {
    std::getline(std::cin, answer);
    std::cout << "Все говорят \"" << answer << "\", а ты купи слона!\n";
  } while (answer != "ffjdsuserfyfeLFKJ");
}