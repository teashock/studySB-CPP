#include <iostream>
#include <cmath>

int main() {
  std::cout << "Кенийский бегун!\n";

  int distance;
  std::cout << "Сколько километров сегодня пробежал бегун? ";
  std::cin >> distance;
  if (distance < 1) {
    std::cout << "Бегун пробежал слишком мало, чтобы расчитать средний темп.\nПовторим попытку затра!\n";
  } else {
    float avgPace = 0.0f;
    for (int count = 0; count < distance; count++)
    { float pace;
      std::cout << "Какой у тебя был темп на километре " << count + 1 << "? ";
      std::cin >> pace;
      if (pace <= 0) {
        std::cout << "Мне кажется или бегун стоял на месте???\n";
      } 
      avgPace += pace;
    }
  std::cout << "Средний темп за тренировку: " << (int) ((avgPace / distance) / 60.f) << " мин. " << std::round(avgPace / distance - ((int) ((avgPace / distance) /60.f)*60)) << " секунд.";
  } 
}