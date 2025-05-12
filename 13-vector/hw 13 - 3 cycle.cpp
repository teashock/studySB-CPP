#include <iostream>
#include <vector>

int main() {
    std::cout << "Storage of integer values!\n";
    
    int lengthData = 20;
    int val, count = 0, index = 0;
    std::vector<int> dataBase(lengthData);
    
    while (true) {
        std::cout << "Input number (-1 to stop, -2 to end): ";
        std::cin >>val;
        
        if (val == -2) {
            break;
        }

        if (val == -1) {
            std::cout << "Output: ";
            for (int i = 0; i < count; i++) {
            std::cout << dataBase[(index + i) % lengthData] << " ";
        }
        std::cout << std::endl;
        continue;
        }

        if (count < lengthData) {
            dataBase[count] = val;
            count++;
        } else {
            dataBase[index] = val;
            index = (index + 1) % lengthData;
        }
        
    }
}
       
