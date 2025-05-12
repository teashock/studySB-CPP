#include <iostream>

int main() {
  
  std::cout << "Годен ли ты к призыву и стть летчиком?\n";
  std::cout << "======================================\n";

  int height, weight, handsNumber, legsNumber, fligthTime;
  std::string eyeColor;

  std::cout << "Начнем отбор призывников\n";
  std::cout << "Рост призывника: ";
  std::cin >> height;
  std::cout << "Вес призывника: ";
  std::cin >> weight;
  std::cout << "Количество рук у призыника: ";
  std::cin >> handsNumber;
  std::cout << "Количество ног у призыника: ";
  std::cin >> legsNumber;
  std::cout << "Цвет глаз у призывника: ";
  std::cin >> eyeColor;
  std::cout << "Количество имеющихся у призывника часов налета: ";
  std::cin >> fligthTime;

  if ((height >= 145 && height <= 165) && (weight >= 45 && weight <= 65) && (handsNumber == 2) && (legsNumber == 2) && (fligthTime >= 100)) {
    if (eyeColor == "зеленый") {
      std::cout << "Призывник не годен!";
    } else {
      std::cout << "Годен!";
    }
  } else {
    std::cout << "Призывник не годен!";
  }
}