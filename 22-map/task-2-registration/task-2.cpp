#include<iostream>
#include<map>

int main() {
    std::cout << "Registration office!\n";
    std::map<std::string, int> patient;
    std::string input;
    std::cout << "Enter the patient's surname to add to the queue or \"Next\" to call patient: ";
    while (true) {
        std::cin >> input;
        if (input == "Next") {
            if (!patient.empty()) {
                std::map<std::string, int> :: iterator it = patient.begin();
                std::cout << "->" << it->first << std::endl;
                if (--it->second == 0) {
                    patient.erase(it);
                }
            } else {
                std::cout << "The queue is empty!\n";
            }
        } else {
            patient[input]++;
            std::cout << "<-" << input << std::endl;
        }
    }
}