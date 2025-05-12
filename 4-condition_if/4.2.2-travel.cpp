#include <iostream>

int main() {
  std::cout << "Путь до Рязани!\n";

  int speedAverage;
  int time;
  int distance;

  std::cout << "Введите среднюю скорость автомобиля (в километрах в час) на участке Москва - Рязань: ";
  std::cin >> speedAverage;
  std::cout << "Введите время (в часах), за которое должен автомобиль добраться до Рязани: ";
  std::cin >> time;
  std::cout << "Введите расстояние между Москвой и Рязанью: ";
  std::cin >> distance;
  
  int distanceFinal = speedAverage * time;
  
  if (distanceFinal >= distance) {
    std::cout << "Вы приехали!\n";    
  }

  std::cout << "---------------------\n";
  std::cout << "Пройденное расстояние " << distanceFinal <<".\n";
  
}