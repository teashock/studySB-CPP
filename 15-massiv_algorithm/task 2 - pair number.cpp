#include <iostream>
#include <vector>

int main() {
    std::cout << "Find a pair of number!\n";

    std::vector<int> arr = {2, 11, 7, 15};
    int result = 18;

    for (int i = 0; i < arr.size() - 1; i++){
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i]+arr[j] == result){
                std::cout << "The found pair of numbers is " << arr[i] << " and " << arr[j] << "\n";
                return 0;
            }
        }
    }
    std::cout << "A pair not found!" << std::endl;
    return 0;
}