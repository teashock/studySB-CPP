#include <iostream>

int main() {
  
  std::cout << "Злостные вредители!\n";
  std::cout << "====================\n";
  std::cout << "Расчет роста бамбука\n";
  std::cout << "--------------------\n";
  
  int startBambooHeight;
  int dailyGrowth;
  int nightFade;

  std::cout << "Введите начальную высоту бамбука (в см): ";
  std::cin >> startBambooHeight;
  std::cout << "Введите скорость роста бамбука (см в день):";
  std::cin >> dailyGrowth;
  std::cout << "Введите скорость уничтожения бамбука гусеницами (см за ночь): ";
  std::cin >> nightFade;
  std::cout << "--------------------\n";
 
  int endBambooHeight = startBambooHeight + dailyGrowth * 2 - nightFade*2; 
  std::cout << "Высота бамбука к третьему дню " << endBambooHeight << " см.\n";

 }