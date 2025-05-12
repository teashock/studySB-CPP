#include <iostream>

bool checkUsername(std::string user) {
    std::string lib = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890-.!#$%&'*+-/=?^_`{|}~";
    if (user.length() > 64) return false;
    for (int i = 0; i < user.length(); i++) {
        if (lib.find(user[i]) != std::string::npos) {
               if (user[i] == '.' && (i == 0 || i == user.length() - 1 || (i < (user.length() - 1) && user[i+1] == '.'))) {
                    return false;
                }
            } else {
                return false;
            }
        } 
        return true;
    }

bool checkDomain(std::string dm) {
    if (dm.length() > 63) return false;
    std::string lib = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890-.";
    for (int i = 0; i < dm.length(); i++) {
        if (lib.find(dm[i]) != std::string::npos) {
                if (dm[i] == '.' && (i == 0 || i == dm.length() - 1 || (i < (dm.length() - 1) && dm[i+1] == '.'))) {
                    return false;
                }
            } else {
                return false;
            }
        } 
        return true;
    }

    int main() { 
        std::cout << "E-mail checker!" << std::endl;
        std::string email;
        std::cout << "Input e-mail here: ";
        std::cin >>email;
         
        int position = -1;
        bool matched = true;
         
        for (int i = 0; i< email.length(); i++) {
            if (email[i] == '@')  {
                if (position > -1 || i == 0 || i == email.length() - 1) {
                    matched = false;
                    break;
            } else if (position == -1) {
                position = i;
            }
        }
    }

    if (position != -1) {
        matched = (checkUsername(email.substr(0, position)) &&
                checkDomain(email.substr(position + 1)));
    } else matched = false;

    std::cout << (matched ? "Yes! This is correct!\n" : "No! This is not correct!\n") << std::endl;
    return 0;

}