#include <iostream>

int main() {
  
  std::string characterName;
  std::cout << "Введите имя персонажа: ";
  std::cin >> characterName;
 
  std::string species;
  std::cout << "Выберите расу персонажа: ";
  std::cin >> species;
  
  std::cout << "Родился новый " << species << " его зовут " << characterName << ". Добро пожаловать в этот суровый мир!\n";

}