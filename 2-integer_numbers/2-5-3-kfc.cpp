#include <iostream>


int main() {
  int shiftTime = 480;
  int customerOrderTime = 2;
  int cashierAssemblyTime = 4;

  int clientsNumber = shiftTime/(customerOrderTime + cashierAssemblyTime);

  std::cout << "========================\n";
  std::cout << "Крылышки и ножки\n";
  std::cout << "========================\n";
  std::cout << "Количество клиентов, обслуживаемых одним кассиром за рабочую смену\n";
  std::cout << "========================\n";
  std::cout << "Введите длительность смены в минутах: " << shiftTime << "\n";
  std::cout << "Сколько минут клиент делает заказ? " << customerOrderTime << "\n";
  std::cout << "Сколько минут кассир собирает заказ? " << cashierAssemblyTime << "\n";
  std::cout << "-----Считаем-----\n";
  std::cout << "За смену длиной " << shiftTime << " минут кассир успеет обслужить " << clientsNumber << " клиентов.\n";
}