#include <iostream>
#include <vector>

void init(int arr[5][5]) {
    int number = 0;

    for (int i = 0; i < 5; i++) {
        int multiplier = i % 2 ? 1 : -1;
        for (int j = 0; j < 5; j++) {
            arr[i][(multiplier == 1) ? (4 - j): j] = number;
            number++;
        }
    }
}

void print(int arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Snake Matrix!\n";
    int arr[5][5];
    init(arr);
    print(arr);
}