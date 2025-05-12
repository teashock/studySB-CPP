#include <iostream>
#include <vector>

void init(int landscape[5][5][10]){
    int height;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            while (true) {
                std::cout << "Input the height of the sectors (0 - 10): ";
                std::cin >> height;
                if (height < 0 || height > 10) {
                    std::cout << "Wrong height! Repeat the input!\n";
                } else {
                    for (int k = 0; k < height; k++) {
                        landscape[i][j][k] = 1;
                    }
                    break;
                }
            } 
        }
    }
}

void print(int landscape[5][5][10]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int height = 0;
            for (int k = 0; k < 10; k++) {
                if (landscape [i][j][k] == 1) {
                    height++;
                }
            }
            std::cout << height << " ";
        }
        std::cout << std::endl;
    }
}

void sliceLevelAndPrint(int landscape[5][5][10]) {
    int level;
    while (true) {
        std::cout << "Input cut level (1 - 10): ";
        std::cin >> level;
        if (level < 1 || level > 10) {
            std::cout << "Wrong slice level!\n";
        } else {
            std::cout << "A slice at the level " << level << ":\n";
            break;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int height = 0;
            for (int k = 0; k < 10; k++) {
                if (landscape[i][j][k] == 1) {
                    height++;
                } 
            }
            if (height >= level) {
                std::cout << "1 ";
            } else {
                std::cout << "0 "; 
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Minecraft alpha 0.0.0.1\n";
    int landscape[5][5][10];
    init (landscape);
    print (landscape);
    sliceLevelAndPrint(landscape);
}