#include <iostream>

int main() {
  std::cout << "Маятник!\n";
  std::cout << "Рассчитем количество колебаний маятника.\n";

  float initialAmplitude, finalAmplitude;

  do {
    std::cout << "Введите начальную амплитуду маятника: ";
    std::cin >> initialAmplitude;
    std::cout << "Введите конечную амплитуду маятника: ";
    std::cin >> finalAmplitude;
    if (initialAmplitude <= 0) {
      std::cout << "Начальная амплитуда маятника должна быть больше 0!\n";
    } else if (finalAmplitude < 0) {
      std::cout << "Конечная амплитуда маятника не может быть меньше 0!\n";
    } else if (finalAmplitude >= initialAmplitude)
    { std::cout << "Начальная амплитуда маятника должна быть больше конечной амплитуды!\n";
    }
  } while (initialAmplitude <= 0 || finalAmplitude < 0 || finalAmplitude >= initialAmplitude);

  int count = 0;
  while (initialAmplitude > finalAmplitude) {
    initialAmplitude = initialAmplitude - initialAmplitude * (8.4f / 100);
    count++;
  }
  std::cout << "Количество колебаний маятника " << count << "\n";
}