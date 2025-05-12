#include <iostream>
#include <cmath>

int main() {
  std::cout << "Игрушечная история!\n";
  std::cout << "Давайте посчитаем, сколько кубиков будет в наборе из заданного бруска!\n";
  std::cout << "Кубики имеют размеры 5х5х5 см.\n";

  float barX, barY, barZ;

  do {
    std::cout << "Введите размеры бруска: \n\t - ширина (X): ";
    std::cin >> barX;
    if (barX <= 0) {
      std::cout << "Ошибка ширина не может быть меньше либо равняться 0!\n";
    } else if (barX > 0 & barX < 5) {
      std::cout << "Брусок такой ширины нам не подойдет!\n";
    }
  } while (barX < 5);

  do {    
    std::cout << "\t - длина (Y): ";
    std::cin >> barY;
    if (barY <= 0) {
      std::cout << "Ошибка ширина не может быть меньше либо равняться 0!\n";
    } else if (barY > 0 & barY < 5) {
      std::cout << "Брусок такой ширины нам не подойдет!\n";
    }
  } while (barY < 5); 

  do {
    std::cout << "\t - высота (Z): ";
    std::cin >> barZ;
    if (barZ <= 0) {
      std::cout << "Ошибка ширина не может быть меньше либо равняться 0!\n";
    } else if (barZ > 0 & barZ < 5) {
      std::cout << "Брусок такой ширины нам не подойдет!\n";
    }
  } while (barZ < 5);
  
  float sqrBar = (float) ((int) barX/5 * (int) barY/5 * (int) barZ / 5);
  std::cout << "Из бруска можно вырезать " << sqrBar << " кубиков.\n";
  std::cout << "Из " << sqrBar << " кубиков можно сложить набор из " <<  std::pow(std::floor(std::cbrt(sqrBar)),3) << " кубиков!";
} 



