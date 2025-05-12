#include <iostream>
#include <vector>
/* В решении нет перемещений и расширений вектора*/
int main() {
  std::cout << "Task 3!\n";
  const int datalength=20;
  int val, count=0, index=0;
  std::vector<int> data(datalength);

  while (val != -1) {
    std::cout << "Enter value: ";
    std::cin >>val;
    if (count < datalength) {
      data[count] = val;
      count++;
    } else {
      data[index] = val;
      index++;
      if (index==20) {index = 0;}
    }
  }
  
  if (index == 0) {
    for (int i=0; i<count; i++) {
      std::cout << data[i] << " ";
    }
  } else {
    for (int i=index; i<count; i++) {
      std::cout << data[i] << " ";
    }
    for (int i=0; i<index; i++){
      std::cout << data[i] << " ";
    }
  }
  
}