#include <iostream>

int main() {
      
  std::cout << "Симулятор маршрутки!\n";
  std::cout << "====================\n";
  std::cout << "Программа для расчета дохода компании от маршрута следования.\n";

  int ticketPrice;
  std::cout << "Введите стоимость билета: ";
  std::cin >> ticketPrice;
  int passengerTotal;
  std::cout << "Введите количество пассажиров в маршрутке, вошедших в начале маршрута: ";
  std::cin >> passengerTotal;
  std::cout << "-------------------\n";

  int passengerEnterNumber;
  int passengerExitNumber;
  int totalIncome = passengerTotal*ticketPrice;
  int passengerAll = passengerTotal;
  
  std::string firstStop = "Улица программистов";
  std::cout << "Прибываем на остановку \"" << firstStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengerExitNumber;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengerEnterNumber;
  passengerTotal = passengerTotal + passengerEnterNumber - passengerExitNumber;
  std::cout << "Отправляемся с остановки \"" << firstStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  totalIncome += passengerEnterNumber*ticketPrice;
  passengerAll += passengerEnterNumber;
  std::cout << "------Едем------\n";
  
  std::string secondStop = "Проспект алгоримов";
  std::cout << "Прибываем на остановку \"" << secondStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengerExitNumber;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengerEnterNumber;
  passengerTotal = passengerTotal + passengerEnterNumber - passengerExitNumber;;
  std::cout << "Отправляемся с остановки \"" << secondStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  totalIncome += passengerEnterNumber*ticketPrice;
  passengerAll += passengerEnterNumber;
  std::cout << "------Едем------\n";

  std::string thirdStop = "Поворот на Skillbox";
  std::cout << "Прибываем на остановку \"" << thirdStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengerExitNumber;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengerEnterNumber;
  passengerTotal = passengerTotal + passengerEnterNumber - passengerExitNumber;;
  std::cout << "Отправляемся с остановки \"" << thirdStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  totalIncome += passengerEnterNumber*ticketPrice;
  passengerAll += passengerEnterNumber;
  std::cout << "------Едем------\n";

  std::string fourthStop = "Путь к разработчику";
  std::cout << "Прибываем на остановку \"" << fourthStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengerExitNumber;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengerEnterNumber;
  passengerTotal = passengerTotal + passengerEnterNumber - passengerExitNumber;;
  std::cout << "Отправляемся с остановки \"" << fourthStop << "\".\n";
  std::cout << "В салоне пассажиров: " << passengerTotal << ".\n";
  totalIncome += passengerEnterNumber*ticketPrice;
  passengerAll += passengerEnterNumber;
  std::cout << "------Едем на конечную остановку------\n";

  int driveSalary = 0.25 * totalIncome;
  int gasCost = 0.2 * totalIncome;
  int taxes = 0.2 * totalIncome;
  int repairBusCost = 0.2 * totalIncome;
  int netIncome = totalIncome - driveSalary -  gasCost - taxes - repairBusCost;

  std::cout << "Всего пассажиров перевезено: " << passengerAll << ".\n";
  std::cout << "Всего заработали: " << totalIncome << " руб.\n";
  std::cout << "Зарплата водителя: " << driveSalary << " руб.\n";
  std::cout << "Расходы на топливо: " << gasCost << " руб.\n";
  std::cout << "Налоги: " << taxes << " руб.\n";
  std::cout << "Расходы на ремонт машины: " << repairBusCost << " руб.\n";
  std::cout << "Итого доход: " << netIncome << " руб.\n";
 
}