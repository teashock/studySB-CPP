#include <iostream>
#include <vector>

void printField(char field[10][10]) {
    std::cout << "  ";
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

bool ships_crushes(char gameField[10][10], int x1, int x2, int y1, int  y2) {
    if (x1 == x2) {
        for (int i = y1; i <= y2; i++) {
            if (gameField[i][x1] != '-') {
                return true;
            }
        }
    } else {
        for (int i = x1; i <= x2; i++) {
            if (gameField[y1][i] != '-') {
                return true;
            }
        }
    }
    return false;
}

void small_ships_initialization(char gameField[10][10]) {
    int x;
    int y;
    std::cout << "Enter the coordinates (x,y):";
    std::cin >> x >> y;
    while (x < 0 || x > 9 || y < 0 || y > 9 || gameField[y][x] != '-') {
        std::cout << "Invalid data!\nTry again.\n";
        std::cout << "Enter the coordinates (x,y): ";
        std::cin >> x >> y;
    }
    gameField[y][x] = 'o';

    printField(gameField);
}

void large_ships_intitalization(char gameField[10][10], int shipSize) {
    int x1;
    int x2;
    int y1;
    int y2;

    std::cout << "Enter the starting coordinates (x,y)" << std::endl;
    std::cin >> x1 >> y1;
    std::cout << "Enter the ending coordinates (x,y)" << std::endl;
    std::cin >> x2 >> y2;
    std::string direction;
    if (x1 == x2) direction = "vertical";
    else if (y1 == y2) direction = "horizontal";
    while (x1 < 0 || x1 > 9 || x2 < 0 || x2 > 9 || y1 < 0 || y1 > 9 || y2 > 9 || y2 < 0 || x1 != x2 && y1 != y2
    || ships_crushes(gameField, x1, x2, y1, y2) || x1 > x2 || y1 > y2
    || direction == "horizontal" && x2 - x1 != shipSize - 1 || direction == "vertical" && y2 - y1 != shipSize - 1) {
        std::cout << "Invalid data!\nTry again.\n";
        std::cout << "Enter the starting coordinates (x,y)" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Enter the ending coordinates (x,y)" << std::endl;
        std::cin >> x2 >> y2;
        if (x1 == x2) direction = "vertical";
        else if (y1 == y2) direction = "horizontal";
    }


    if (direction == "vertical") {
        for (int i = y1; i <= y2; ++i) {
            gameField[i][x1] = 'o';
        }
    } else {
        for (int i = x1; i <= x2; ++i) {
            gameField[y1][i] = 'o';
        }
    }

    printField(gameField);
}

void gameFieldInit(char gameField[10][10]) {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            gameField[i][j] = '-';
        }
    }
    for (int i = 0; i < 4; i++) {
        std::cout << "Place a 1 square size ship\n";
        small_ships_initialization(gameField);
    }
    for (int i = 0; i < 3; i++) {
        std::cout << "Place a 2 square size ship\n";
        large_ships_intitalization(gameField, 2);
    }
    for (int i = 0; i < 2; i++) {
        std::cout << "Place a 3 square size ship\n";
        large_ships_intitalization(gameField, 3);
    }
    std::cout << "Place a 4 square size ship\n";
    large_ships_intitalization(gameField, 4);
}

void shoot_to (char gameField[10][10]) {
    int x;
    int y;
    std::cout << "Enter the coordinates (x,y): ";
    std::cin >> x >> y;

    while (y < 0 || y > 9 || x < 0 || x > 9) {
        std::cout << "Invalid data!\nTry again.\n";
        std::cin >> x >> y;
    }

    if (gameField[y][x] == 'o') {
        std::cout << "Hit!\n";
        gameField[y][x] = 'x';
    } else {
        std::cout << "Miss!\n";
        gameField[y][x] = '*';
    }
    printField(gameField);
}

bool win_checking(char gameField[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (gameField[i][j] != '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char playerOneField[10][10];
    char playerTwoField[10][10];
    std::cout << "Player 1 placing ships!\n";
    gameFieldInit(playerOneField);
    std::cout << "Player 2 placing ships!\n";
    gameFieldInit(playerTwoField);

    while (true) {
        std::cout << "Player 1 turn!\n";

        shoot_to(playerTwoField);
        if (win_checking(playerTwoField)) {
            std::cout << "Player 1 wins!";
            return 0;
        }
        std::cout << "Player 2 turn!\n";

        shoot_to(playerOneField);
        if (win_checking(playerOneField)) {
            std::cout << "Player 2 wins!";
            return 0;
        }
    }
}