#include <iostream>

int main() {
  std::cout << "Биолаборатория.\n";
  
  int bacteria, drop;
  std::cout << "Сколько бактерий в чашке Петри: ";
  std::cin >> bacteria;
  std::cout << "Сколько капель антибиотика добавим: ";
  std::cin >> drop;
  
  for (int count = 0; count < drop && bacteria > 0; count++){
    bacteria *= 2;
    bacteria -= (drop * (10-count));
    if (bacteria < 0) {
      bacteria = 0;
    } 
    std::cout << "После " << count + 1 << " часа бактерий осталось " << bacteria << "\n"; 
  }
  
  if (bacteria <= 0) {
    std::cout << "Поздравляем Вы избавились от бактериий!";
  } else {
    std::cout << "Антибиотиков больше не осталось! Бактерии продолжают размножаться!";
  }
}