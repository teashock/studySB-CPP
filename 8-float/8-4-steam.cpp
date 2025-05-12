#include <iostream>
#include <cmath>

int main() {
  std::cout << "Убийца Steam!\n";

  float fileSize, internetSpeed, uploadSize;
 
  do {
    std::cout << "Укажите размер файла для скачивания в Мб: ";
    std::cin >> fileSize;
    if (fileSize <= 0) {
      std::cout << "Размер файла должен быть больше 0!\n";
    }
  } while (fileSize <= 0); 
  
  do {
    std::cout << "Введите скорость интернета МБ/с: ";
    std::cin >> internetSpeed;
    if (internetSpeed <= 0) {
      std::cout << "Проверьте подключение к интернету!\n";
    }
  } while (internetSpeed <= 0);
  uploadSize = fileSize;
  
  for (int count = 1; uploadSize > 0; count++) {
    uploadSize -= internetSpeed;
    if (uploadSize > 0) {
      std::cout << "Прошло " << count << " сек. Скачано " << fileSize - uploadSize << " из " << fileSize << " Мб (" << int ((fileSize - uploadSize)/fileSize*100) << "%).\n";
    } else {
      std::cout << "Прошло " << count << " сек. Скачано " << fileSize << " из " << fileSize << " Мб (" << int (fileSize/fileSize*100) << "%).\n";
    }
  } std::cout << "Загрузка завершена! Наслаждайся игрой!";
}