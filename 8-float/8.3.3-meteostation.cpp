#include <iostream>

int main() {
  std::cout << "Метеостанция!\n";

  int lowerBound, upperBound, step;
  std::cout << "Введите нижнюю границу шкалы измерений: ";
  std::cin >> lowerBound;
  std::cout << "Введите верхнюю границу шкалы измерений: ";
  std::cin >> upperBound;
  std::cout << "Введите шаг измерений: ";
  std::cin >> step;
  std::cout << "\nВывод\n";
  std::cout << "\nC" << "\tF\n";
  
  for (int temperatureC = lowerBound; temperatureC <= upperBound; temperatureC += step) {
    float temperatureF = 1.8f * (float) temperatureC + 32.f;
    std::cout << temperatureC << "\t" << temperatureF << "\n";
  }
}