#include <iostream>
#include <fstream>
#include <ctime>

const int maxNotes = 1000;
const int notes[] = {100, 200, 500, 1000, 2000, 5000};
const int countNotes = 6;
int billCounts[countNotes] = {0};

void readATMfile() {
    std::ifstream infile("atm.bin", std::ios::binary);
    if (infile) {
        infile.read((char*)billCounts, sizeof(billCounts));
        infile.close();
    } else {
        std::cout << "The ATM is empty or file not found!\n";
    }
}

void writeATMfile() {
    std::ofstream outfile("atm.bin", std::ios::binary);
    if (outfile) {
        outfile.write((char*)billCounts, sizeof(billCounts));
        outfile.close();
    }
}

void displayATM() {
    int totalSum = 0;
    int totalNotes = 0;
    std::cout << "At the ATM now:\n";
    for (int i = 0; i < countNotes; ++i) {
        std::cout << notes[i] << " RUB - " << billCounts[i] << " bills" << std::endl;
        totalSum += notes[i] * billCounts[i];
        totalNotes += billCounts[i];
    }
    std::cout << "Total amount in ATM: " << totalSum << " RUB.\n";
    std::cout << "At the ATM " << totalNotes << " bills!\n";
}

void refill() {
    int totalNotes = 0;
    for (int i = 0; i < countNotes; ++i) {
        totalNotes += billCounts[i];
    }
    if (totalNotes >= maxNotes) {
        std::cout << "The ATM is already full!\n";
        return;
    }
    std::srand(std::time(nullptr));
    int notesToAdd = maxNotes - totalNotes;
    int remainingNotes = notesToAdd;
    int notesAdded[countNotes] = {0};

    for (int i = 0; i < countNotes - 1; ++i) {
        int notesToAddStep = std::rand() % (remainingNotes + 1);
        notesAdded[i] = notesToAddStep;
        remainingNotes -= notesToAddStep;
    } 
    notesAdded[countNotes - 1] = remainingNotes;

    for (int i = 0; i < countNotes; ++i) {
        billCounts[i] += notesAdded[i];
    }
    std::cout << "The ATM has been refilled!\n";
}

bool withdraw(int amount) {
    if (amount % 100 != 0) {
        std::cout << "The amount must be a multiple of 100!\n";
        return false;    
    }

    if (amount < 0) {
        std::cout << "Amount must be greater then 0!\n";
        return false;
    }

    int totalAvaliable = 0;
    for (int i = 0; i < countNotes; ++i) {
        totalAvaliable += notes[i] * billCounts[i];
    }
    if (amount > totalAvaliable) {
        std::cout << "The entered amount is more than available for issue!\n";
        return false;
    }

    int originalAmount = amount;
    for (int i = countNotes - 1; i >= 0; --i) {
        while (amount >= notes[i] && billCounts[i] > 0) {
            amount -= notes[i];
            --billCounts[i];
        }
    }
    
    if(amount == 0) {
        std::cout << "Withdrawal successful!\n";
        return true;
    } else {
        std::cout << "Unable to dispense the exact amount. Please try a different amount.\n";
        amount = originalAmount;
        for (int i = countNotes - 1; i >= 0; --i) {
            while (originalAmount >= notes[i] && billCounts[i] < maxNotes) {
                originalAmount -= notes[i];
                ++billCounts[i];
            }
        }
        return false;
    }
}

int main(){
    std::cout << "Wellcome to the ATM!\n";
    readATMfile();
    displayATM();

    char command;
    while (true) {
        std::cout << "\nEnter command ('+' - refill; '-' - withdraw; 'q' - exit): ";
        std::cin >> command;

        if (command == '+') {
            refill();
        } else if (command == '-') {
            int amount;
            std::cout << "Enter the amount to withdraw: ";
            std::cin >> amount;
            withdraw(amount);
        } else if (command == 'q') {
            writeATMfile();
            std::cout << "Thank you for using our the ATM!\n";
            break;
        } else {
            std::cout << "Incorrect command!Try again!\n";
        }
        displayATM();
    }
}