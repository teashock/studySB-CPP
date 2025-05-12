#include <iostream>

int main() {

  std::cout << "Immolate Improved!\n";

  float pointHealth, resistanceMagic, fireBall;
  
  do {
    std::cout << "Введите количество здоровья орка от 0 до 1: ";
    std::cin >> pointHealth;
    if (pointHealth <= 0 || pointHealth > 1) {
      std::cout << "Проверьте внимательно введенные параметры!\nЗдоровье орка не может быть меньше или равняться 0 и больше 1!\n";
    }
  } while (pointHealth <= 0 || pointHealth > 1);
    
    do {
    std::cout << "Введите сопротивляемость магии орка от 0 до 1: ";
    std::cin >> resistanceMagic; 
      if (resistanceMagic < 0 || resistanceMagic > 1) {
      std::cout << "Проверьте внимательно введенные параметры!\nСопротивляемость орка не может быть меньше 0 и больше 1!\n";
    }
  } while (resistanceMagic < 0 || resistanceMagic > 1);

  while (pointHealth > 0) {
    std::cout << "Введите мощность огненного шара от 0 до 1: ";
    std::cin >> fireBall;
    if (fireBall < 0 || fireBall > 1) {
      std::cout << "Внимание!\nМощность огненного шара не может быть меньше 0 и больше 1!\n";
    } else {
      float lostHealth = fireBall - fireBall * resistanceMagic;
      std::cout << "Урон " << fireBall << ", сопротивляемость " << resistanceMagic << ", по орку будет нанесено " << lostHealth << " урона!\n";
      pointHealth -= lostHealth;
      if (pointHealth > 0) {
        std::cout << "У орка осталось " << pointHealth << " здоровья!\n";
      } else {
        std::cout << "Поздравляем герой! Мерзкий орк сгорел живьем!\n";
      }
    }
  } 
}