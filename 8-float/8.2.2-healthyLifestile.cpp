#include <iostream>

int main() {
  std::cout << "ЗОЖ!\n";

  std::cout << "Подсчиитаем количество потребляемых белков и углеводов\n";

  float weight, squirrels, carb, totalSquirrels, totalCarb;
  std::cout << "Укажите массу нетто продукта (в граммах): ";
  std::cin >> weight;
  std::cout << "Укажите количество белков на 100 гр продукта: ";
  std::cin >> squirrels;
  std::cout << "Укажите количество углеводов на 100 гр продукта: ";
  std::cin >> carb;
  std::cout << "=======Расчет=======\n";

  totalSquirrels = squirrels * weight / 100;
  totalCarb = carb * weight / 100;

  std::cout << "Количество белков в продукте: " << totalSquirrels << ".\n";
  std::cout << "Количество углеводов в продукте: " << totalCarb << ".\n";
  
}