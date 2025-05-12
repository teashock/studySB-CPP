#include <iostream>

int main() {
    int manCount;
    int barbersCount;
    int shiftTime = 8;
    
    std::cout << "**** Барбершоп-калькулятор ****\n";
    std::cout << "*******************************\n";
    std::cout << "Введите число мужчин в городе: ";
    std::cin >> manCount;
    std::cout << "Сколько барберов уже работает: ";
    std::cin >> barbersCount;
    
    int manPerDay = manCount/30;
        if (manCount % 30 != 0) { 
        manPerDay += 1;
    }
    std::cout << manPerDay << " мужчин должно обслуживаться в барбершопе ежедневно.\n";
    int manPerBarbers = shiftTime * barbersCount;
    std::cout << manPerBarbers << " мужчин обслуживается в настоящее время ежедневно.\n";
    if (manPerBarbers >= manPerDay)
  {
    std::cout << "Барберов достаточно!\n";
  } else {
      int barbersNeeds = manPerDay / shiftTime;
      if (manPerDay % shiftTime != 0) {
        barbersNeeds += 1;
    }
        int barbersNeed = barbersNeeds - barbersCount;
    std:: cout << "Увы. Но Вам нехватает еще "  << barbersNeed << " барберов!!!\n";
  }
}