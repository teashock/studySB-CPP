#include <iostream>

int main() {

  std::string userName;
  std::cout << "Введите логин: ";
  std::cin >> userName;

  std::string userPassword;
  std::cout << "Введите пароль: ";
  std::cin >> userPassword;

  std::cout << "----------------\n";
  std::cout << userName << ", вы успешно зашли!\n";

}