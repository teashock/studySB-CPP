#include <iostream>
#include "instruments.h"

int main () {
    std::cout << "Beginning surgery!\n";
    coordinates scalpelStart, scalpelEnd, hemostatPoint, tweezersPoint, sutureStart, sutureEnd;
    bool surgeryStart = false;
    bool surgeryEnd = false;

    while (!surgeryEnd) {
        std::string command;
        std::cout << "Enter command:\n-scalpel - to start surgery;\n-hemostat - to stop the blood;\n-tweezers - to incision processing;\n-suture - to end surgery.\n";
        std::cin >> command;
        
        if (command != "scalpel" && !surgeryStart){
            std::cout << "Operation must started  with \"scalpel\" command!\n";
            continue;
        } else if (command == "scalpel"){
            if (surgeryStart) {
                std::cout << "Surgery already is beginning!\n";
                continue;
            } else {
                scalpel(scalpelStart, scalpelEnd);
                surgeryStart = true;
            }
        } else if (command == "hemostat") {
            hemostat(hemostatPoint);
        }else if (command == "tweezers") {
            tweezers(tweezersPoint);
        } else if (command == "suture"){
            do {
                suture(sutureStart, sutureEnd);
                if (isEqual(scalpelStart, sutureStart) && isEqual(scalpelEnd, sutureEnd)) {
                    std::cout << "Coordinates match!\n";
                    surgeryEnd = true;
                } else {
                    std::cout << "Coordinates are not equal! Please enter coordinates again.\n";
                }
            } while (!surgeryEnd);
        } else {
            std::cout << "Icorrect command! Try again!";
            continue;
        }
    }
    std::cout << "Operation completed successfully.\n"; 
    return 0;
}