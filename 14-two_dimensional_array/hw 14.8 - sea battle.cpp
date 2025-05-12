#include <iostream>
#include <vector>

void printGameField(bool field[10][10]){
    std::cout << " ";
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkPlaceShips(bool field[10][10], int startX, int startY, int endX, int endY){
    if (startX == endX) {
        for (int i = startY; i <= endY; i++) {
            if (field[i][startX] != false)  {
                return true;
            }
        }
    } else {
        for (int i = startX; i <= endX; i++) {
            if (field[startY][i] != false) {
                return true;
            }
        }
    }
    return false;
}

void placeShip(bool field[10][10], int startX, int startY, int endX, int endY) {
    if (startX == endX) {
        for (int y = std::min(startY, endY); y <= std::max(startY, endY); y++) {
            field[startX][y] = false;
        }
    } else {
        for (int x = std::min(startX, endX); x <= std::max(startX, endX); x++) {
            field[x][startY] = false;
        }
    }
}

void setupPlayer(bool field[10][10], int player) {
    
    std::cout << "Player " << player << ", arrange your ships:" << std::endl;

    int ships[4] = { 4, 3, 2, 1 };
    int sizes[4] = { 1, 2, 3, 4 };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < ships[i]; ++j) {
            int startX, startY, endX, endY;
            bool validPlace = false;

            while (!validPlace) {
                std::cout << "Input coordinates " << sizes[i] << "-cell ship (startX, startY - endX, endY): ";
                std::cin >> startX >> startY >> endX >> endY;

                if (checkPlaceShips(field, startX, startY, endX, endY)) {
                    placeShip(field, startX, startY, endX, endY);
                    validPlace = true;
                } else {
                    std::cout << "It is impossible to place a ship. Repeat!." << std::endl;
                }
            }
            printGameField(field);
        }
    }
}

bool attack(bool enemyField[10][10], int x, int y) {
    if (x < 0 || x > 9 || y < 0 || y > 9) {
        std::cout << "You can't shoot out of bounds!\n" << std::endl;
        return false;
    }
    if (enemyField[x][y] == false) {
        enemyField[x][y] = true;
        std::cout << "Hit!" << std::endl;
        return true;
    }
    std::cout << "Miss!" << std::endl;
    return false;
}

bool checkWinner(bool field[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    bool fieldPlayer1[10][10];
    bool fieldPlayer2[10][10];

    setupPlayer(fieldPlayer1, 1);
    setupPlayer(fieldPlayer2, 2);

    int player = 1;
    while (true) {
        std::cout << "Player " << player << ". Input the coordinates of the shot (x,y): ";
        int x, y;
        std::cin >> x >> y;

        if (player == 1) {
            attack(fieldPlayer1, x, y);
            if (checkWinner(fieldPlayer2)) {
                std::cout << "Player 1 victory!" << std::endl;
                break;
            }
            player = 2;
        } else {
            attack(fieldPlayer1, x, y);
            if (checkWinner(fieldPlayer1)) {
                std::cout << "Player 2 victory!" << std::endl;
                break;
            }
            player = 1;
        }
    }
}
