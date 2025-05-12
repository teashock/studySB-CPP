#include <iostream>

int main() {
  std::cout << "Сокращение дробей!\n";

  int numerator, denominator;
  std::cout << "Введите числитель дроби: ";
  std::cin >> numerator;
  std::cout << "Введите знаменатель дроби: ";
  std::cin >> denominator;
  std::cout << "Сокращение дроби: " << numerator << "/" << denominator << ".\n"; 
  std::cout << "..................\n";
  
  int var = abs(numerator);
  int divider = 2;
  if (denominator == 0) {
    std::cout << "Ошибка! Знаменатель не может быть 0";
  } else {
    while (divider < var){
      if (numerator % divider == 0 && denominator % divider == 0){
        numerator /= divider;
        denominator /= divider;
      } else {
        divider++;
      }    
    }
    if (numerator < 0 && denominator < 0) {
      std::cout << "Сокращенная дробь: " << abs(numerator) << "/" << abs(denominator);
    } else if (numerator < 0 || denominator < 0) {
        std::cout << "Сокращенная дробь: -" << abs(numerator) << "/" << abs(denominator);
    } else
    std::cout << "Сокращенная дробь: " << numerator << "/" << denominator;
  }
}



