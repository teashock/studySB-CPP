#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "");
    std::cout << "Добро пожаловать на зимнюю серию игр \"Что? Где? Когда?\"!\n";

    bool sectorsTotal[13];
    for (int i = 0; i < 13; ++i) {
        sectorsTotal[i] = true;
    }

    int winnerScore = 6;
    int sector = 1;
    int expertsScore = 0;
    int viewerScore = 0;

    while (expertsScore < winnerScore && viewerScore < winnerScore) {
        std::cout << "\nПозиция волчка на секторе " << sector << "!\n";
        std::cout << "Счет игры: знатоки - " << expertsScore << "; зрители - " << viewerScore << ".\n";
        
        int spin;
        std::cout << "Введите число секторов, на которые смещается волчок?\n";
        std::cin >> spin;
        sector += spin;
        sector = (sector - 1) % 13 + 1;
        bool chooseSector = false;
        while (!chooseSector) {
            if (sectorsTotal[sector - 1]) {
                chooseSector = true;
            } else {
                std::cout << "Вопрос на секторе " << sector << " уже был в игре!\n";
                std::cout << "Волчок перемещается на следующий доступный сектор!\n";
                sector = (sector % 13) + 1;
            }
        }
        std::cout << "Волчок на секторе " << sector << "!\n";

        std::ifstream question;
        std::ifstream answer;
        question.open("C:\\develop\\skillbox\\profession-c-plus-plus\\lesson-19-read-from-a-files\\task-5\\game\\questions\\" + std::to_string(sector) + ".txt");
        answer.open("C:\\develop\\skillbox\\profession-c-plus-plus\\lesson-19-read-from-a-files\\task-5\\game\\answers\\" + std::to_string(sector) + ".txt");

        if (!question.is_open() || !answer.is_open()) {
            std::cout << "Путь к файлу не найден!\n";
            return 0;
        }
        std::cout << "Вопрос на сектроре " << sector << " следующий!\n";
        std::string questionLine;
        while (std::getline(question, questionLine)) {
            std::cout << questionLine << std::endl;
        } 
        
        std::string correctAnswer;
        answer >> correctAnswer;
        std::cout << "Введите свой ответ (строчными буквами): ";
        std::string playerAnswer;
        std::cin >> playerAnswer;

        if (playerAnswer == correctAnswer) { 
            std::cout << "Поздравляем! Вы дали верный ответ! Плюс 1 балл к вашему счету!\n";
            ++expertsScore;
        } else {
            std::cout << "О нет! Это неверный ответ! Балл достается телезрителям!\n";
            ++viewerScore;
            std::cout << "Правильный ответ: " << correctAnswer << "!\n";
        }
        sectorsTotal[sector - 1] = false;
    }

    if (expertsScore = winnerScore) {
        std::cout << "Победа знатоков!\n";
        std::cout << "Счет игры: знатоки - " << expertsScore << "; зрители - " << viewerScore << ".\n";
    } else if (viewerScore = winnerScore) {
        std::cout << "Победа телезрителей!\n";\
        std::cout << "Счет игры: знатоки - " << expertsScore << "; зрители - " << viewerScore << ".\n";
    }
    return 0;
}