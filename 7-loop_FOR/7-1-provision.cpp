#include <iostream>

int main() {
  std::cout << "Расчет продовольствия!\n";

  int weight = 100;
  std::cout << "Всего гречки было на начало подсчета: " << weight << " кг\n";
  
  for (int month = 1; weight > 0; month ++) {
    weight -= 4;
    std::cout << "После " << month << " месяца у вас в запасе останется " << weight << " кг гречки\n";
    if (weight == 0) 
      std::cout << "О НЕТ!!! После " << month << " месяца гречка закончится!!!!\n";
  }
}