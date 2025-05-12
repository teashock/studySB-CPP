#include <iostream>


int main() {
  int sumRent = 4000000;
  int entranceSum = 10;
  int apartmentEntranceSum = 40;

  int apartmentRent = sumRent/(entranceSum*apartmentEntranceSum);

  std::cout << "Приветствуем вас в калькуляторе кварплаты!\n";
  std::cout << "========================\n";
  std::cout << "Введите сумму, указанную в квитанции: " << sumRent << "\n";
  std::cout << "Сколько подъездов в вашем доме? " << entranceSum << "\n";
  std::cout << "Сколько квартир в вашем подъезде? " << apartmentEntranceSum << "\n";
  std::cout << "-----Считаем-----\n";
  std::cout << "Каждая квартира должна платить по " << apartmentRent << " руб.\n";
}