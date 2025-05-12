#include <iostream>

int main() {
  
  std::cout << "Мост и перегрузка!\n";
  std::cout << "------------------\n";

  int firstVehicleWeight;
  int secondVehicleWeight;
  int thirdVehicleWeight;
  int fourthVehicleWeight;
  
  std::cout << "Введите массу первого автомобиля: ";
  std::cin >> firstVehicleWeight;
  std::cout << "Введите массу второго автомобиля: ";
  std::cin >> secondVehicleWeight;
  std::cout << "Введите массу третьего автомобиля: ";
  std::cin >> thirdVehicleWeight;
  std::cout << "Введите массу четвертого автомобиля: ";
  std::cin >> fourthVehicleWeight;

  if (firstVehicleWeight > 1200 || secondVehicleWeight > 1200 || thirdVehicleWeight > 1200 || fourthVehicleWeight > 1200) {
    std::cout << "Есть машина с недопустимой массой";
  } else {
    std::cout << "Масса автомобилей допустимая!";
  }
} 
