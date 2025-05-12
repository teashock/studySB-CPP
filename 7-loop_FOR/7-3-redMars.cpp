#include <iostream>

int main() {
  std::cout << "Робот-разведчик для Спейс Инжиниринг\n";
  std::cout << "====================================\n";

  int length, width, pointX, pointY;
  std::cout << "\nЗададим параметры комнаты, в которой будет тестироваться робот-разведчик\n";
  std::cout << "Введите ширину помещения (X): ";
  std::cin >> width;
  std::cout << "Введите длину помещения (Y): ";
  std::cin >> length;
  if (width <= 0 || length <= 0) {
    std::cout << "Вы ввели неверные параметры помещения! Длина и ширина должны быть больше 0!\n";
  } else {
    pointX = width/2;
    pointY = length/2;

    std::cout << "\nВнимание!\nУправление передается оператору!\nУправление производится клавишами:\n\tW - перемещение вперед на 1 метр (по оси Y);\n\tS - перемещение назад на 1 метр (по оси Y);\n\tA - перемещение влево на 1 метр (по оси Х);\n\tD - перемещение вправо на 1 метр (по оси Х);\n";
    
    for (;true;) {
      
      std::cout << "\nМарсоход находится на позиции " << pointX << ", " << pointY << ".\nВведите команду:\n";
      std::string answer;
      std::cin >> answer;
      
      if (answer == "A" && pointX == 0) {
        std::cout << "Вы уперлись в стену. Выберете другое направление.\n";
      } else if (answer == "D" && pointX == width) {
        std::cout << "Вы уперлись в стену. Выберете другое направление.\n";
      } else if (answer == "W" && pointY == length) {
        std::cout << "Вы уперлись в стену. Выберете другое направление.\n";
      } else if (answer == "S" && pointY == 0) {
        std::cout << "Вы уперлись в стену. Выберете другое направление.\n";
      } else if (answer == "A") {
        pointX--;
      } else if (answer == "D") {
        pointX++;
      } else if (answer == "W") {
        pointY++;
      } else if (answer == "S") {
        pointY--;
      } else {
        std::cout << "Вы ввели неверную команду!\nДля управления роботом-разведчиком используйте клавиши \"W\", \"A\", \"S\", \"D\".\n";
      }
    } 
  } 
}