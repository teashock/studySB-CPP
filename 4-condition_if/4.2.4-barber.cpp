#include <iostream>

int main() {
  int mansCount;
  int barberWork;
  int clientTime = 1;
  int barberShift = 8;

  std::cout << "Барбершоп калькулятор!";
  std::cout << "----------------------";
  std::cout << "Введите количество мужчин, проживающих в городе: ";
  std::cin >> mansCount;
  std::cout << "Введите количество барберов, работающих в сети: ";
  std::cin >> barberWork;

  int mansPerDay = mansCount/30;
  int mansPerBarber = clientTime * barberShift;
  int dayBarberCount = mansPerDay/mansPerBarber;
  std::cout << "Необходимое число барберов в день: " << dayBarberCount << ".\n";
  if (dayBarberCount > barberWork) {
    std::cout << "Нужно больше барберов!!!\n";
  }
  if (dayBarberCount <= barberWork) {
    std::cout << "Барберов хватает!!!\n";
  }
}