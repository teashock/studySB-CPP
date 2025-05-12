#include <iostream>
#include <fstream>

int main() {
    std::cout << "Reading the payment accounting statement!\n";
    std::ifstream statement;
    statement.open("C:\\develop\\skillbox\\profession-c-plus-plus\\lesson-19-read-from-a-files\\task-3\\task-3-statement.txt");
    if (!statement.is_open()) {
        std::cout << "The file cannot be opened!";
        return 0;
    } else {
        std::string name;
        std::string surname;
        std::string paymentDate;
        int payout;
        int totalPayout = 0;
        int maxPayout = 0;

        while (!statement.eof()) {
            std::string bufferName;
            std::string bufferSurname;
            std::string bufferDate;
            statement >> bufferName >> bufferSurname >> payout >> bufferDate;
            totalPayout += payout;
            
            if (payout > maxPayout) {
                maxPayout = payout;
                name = bufferName;
                surname = bufferSurname;
                paymentDate = bufferDate;
            }
        }
        std::cout << name << " " << surname << " " << paymentDate << " received the maximum payout " << maxPayout << ".\n";
        std::cout << "Total payout is " << totalPayout << ".\n";
    }
    statement.close();
}