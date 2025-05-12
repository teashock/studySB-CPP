#include <iostream>

int main() {

  int dayBirthday, monthBithday, yearBirthday;
  int dayToday, monthToday, yearToday;
  
  std::cout << "Давай поможем бармену узнать возраст покупателя!\n";
  std::cout << "Введите дату рождения покупателя по форме (день, месяц, год):\n";
  std::cin >> dayBirthday >> monthBithday >> yearBirthday;
  std::cout << "Введите сегоднящнюю дату (день, месяц, год):\n";
  std::cin >> dayToday >> monthToday >> yearToday;

  if (yearToday - yearBirthday > 18) {
    std::cout << "Продажа алкоголя разрешена!";
  } else if (yearToday - yearBirthday == 18) {
    if (monthToday - monthBithday > 0) {
       std::cout << "Продажа алкоголя разрешена!";
    } else if (monthToday - monthBithday == 0) {
      if (dayToday - dayBirthday > 0) {
        std::cout << "Продажа алкоголя разрешена!";
      } else {
        std::cout << "Продажа алкоголя запрещена! Покупатель несовершеннолетний!";
      }
    } else {
      std::cout << "Продажа алкоголя запрещена! Покупатель несовершеннолетний!";
    }
  } else {
    std::cout << "Продажа алкоголя запрещена! Покупатель несовершеннолетний!";
  }
}