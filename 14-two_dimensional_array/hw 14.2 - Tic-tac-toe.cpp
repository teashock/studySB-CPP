#include <iostream>
#include <vector>

void displayBoard(char board[3][3]) {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
        (board[0][i] == player && board[1][i] == player && board[2][i] == player) ||
        (board[0][0] == player && board[1][1] == player && board[2][2] == player)){
        return true; 
        }
    } return false;
}

bool boardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::cout << "Task 2. Tic-tac-toe!" << std::endl;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int moves = 9;
    while (moves >= 0){
        int x,y;
        displayBoard(board);
        std::cout << "Player " << player << " input your x, y coordinates (from 0 to 2): "; 
        std::cin >> x >> y;

        if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ') {
            std::cout << "Error! Incorrected input!\n";
            continue;
        }

        board[x][y] = player;
        moves--;

        if (checkWin(board, player)) {
            displayBoard(board);
            std::cout << "Congratulations! Player " << player << " is win!\n";
            return 0;
        }

        if (boardFull(board)) {
            displayBoard(board);
            std::cout << "It's a draw!" << std::endl;
            return 0;
         }

        player = (player == 'X') ? 'O' : 'X';
    }
    
}