#include <iostream>
#include <cmath>

int main() {
  std::cout << "Автопилот!\n";

  float degreeAngle, radianAngle;
  std::cout << "Введите угол тангажа в градусах: ";
  std::cin >> degreeAngle;
  radianAngle = degreeAngle * 180.0f / 3.14f;
  
  if (radianAngle >= - 0.28f && radianAngle <= 0.28f) {
    std::cout << "Угол безопасен!";
  } else {
    std::cout << "Угол небезопасен!";
  }
}