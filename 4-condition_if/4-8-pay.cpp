#include <iostream>

int main() {
  std::cout << "****** Расчет зарплаты в отделе ******\n";
  std::cout << "--------------------------------------\n";

  int firstEmployeeSalary;
  int secondEmployerSalary;
  int thirdEmployerSalary;

  std::cout << "Введите зарплату первого сотрудника: ";
  std::cin >> firstEmployeeSalary;
  std::cout << "Введите зарплату второго сотрудника: ";
  std::cin >> secondEmployerSalary;
  std::cout << "Введите зарплату третьего сотрудника: ";
  std::cin >> thirdEmployerSalary;
  std::cout << "--------------------------------------\n";
  std::cout << "******  Ведется расчет ******\n";
  std::cout << "--------------------------------------\n";

  if (firstEmployeeSalary >= secondEmployerSalary) {
    if (secondEmployerSalary >= thirdEmployerSalary) {
      std::cout << "Самая высокая зарплата в отделе у первого сотрудника: " << firstEmployeeSalary << " рублей.\n";
      std::cout << "Разница между максимальной и минимальной зарплатой: " << firstEmployeeSalary -  thirdEmployerSalary << " рублей\n";
    } else {
      if (firstEmployeeSalary >= thirdEmployerSalary) {   
      std::cout << "Самая высокая зарплата в отделе у первого сотруднки: " << firstEmployeeSalary << " рублей.\n";
      std::cout << "Разница между максимальной и минимальной зарплатой: " << firstEmployeeSalary - secondEmployerSalary << " рублей\n";
    } 
    else {
        std::cout << "Самая высокая зарплата в отделе у третьего сотрудника: " << thirdEmployerSalary << " рублей.\n";
        std::cout << "Разница между максимальной и минимальной зарплатой: " << thirdEmployerSalary - secondEmployerSalary << " рублей\n";
      }
    } 
  }
  else { 
    if (firstEmployeeSalary >= thirdEmployerSalary) {
      std::cout << "Самая высокая зарплата в отделе у второго сотрудника: " << secondEmployerSalary << " рублей.\n";
      std::cout << "Разница между максимальной и минимальной зарплатой: " << secondEmployerSalary - thirdEmployerSalary << " рублей\n";
  } else {
      if (thirdEmployerSalary > secondEmployerSalary) {
      std::cout << "Самая высокая зарплата в отделе у третьего сотрудника: " << thirdEmployerSalary << " рублей.\n";
      std::cout << "Разница между максимальной и минимальной зарплатой: " << thirdEmployerSalary - firstEmployeeSalary << " рублей\n";
    } else {
        std::cout << "Самая высокая зарплата в отделе у второго сотрудника: " << secondEmployerSalary << " рублей.\n";
        std::cout << "Разница между максимальной и минимальной зарплатой: " << secondEmployerSalary - firstEmployeeSalary << " рублей\n";
      }
    }
  }
      
int SalaryAverage = (firstEmployeeSalary + secondEmployerSalary + thirdEmployerSalary)/3;
  if (SalaryAverage % 3 != 0) {
    SalaryAverage += 1;
  }
std::cout << "Средняя зарплата в отделе: " << SalaryAverage << " рублей\n";

}