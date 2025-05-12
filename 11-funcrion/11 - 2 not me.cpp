#include <iostream>

bool checkUsername(const std::string& user) {
    std::string lib = "!#$%&'*+-/=?^_`{|}~";
    if (user.length() > 64) return false;
    
    for (int i = 0; i < user.length(); i++) {
        if (!((user[i] >= 'A' && user[i] <= 'Z') || 
               (user[i] >= 'a' && user[i] <= 'z') ||
               (user[i] >= '0' && user[i] <= '9') || 
               user[i] == '-' || user[i] == '.' || 
               lib.find(user[i]) != std::string::npos)) ) {
            return false; 
        }
        
        if (user[i] == '.' && (i == 0 || i == user.length() - 1 || 
            (i < (user.length() - 1) && user[i + 1] == '.'))) {
            return false;
        }
    }
    return true;
}

bool checkDomain(const std::string& dm) {
    if (dm.length() > 63) return false;
    
    for (int i = 0; i < dm.length(); i++) {
        if (!((dm[i] >= 'A' && dm[i] <= 'Z') || 
               (dm[i] >= 'a' && dm[i] <= 'z') ||
               (dm[i] >= '0' && dm[i] <= '9') || 
               dm[i] == '-' || dm[i] == '.'))) {
            return false;
        }
        
        if (dm[i] == '.' && (i == 0 || i == dm.length() - 1 || 
            (i < (dm.length() - 1) && dm[i + 1] == '.'))) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "E-mail checker!" << std::endl;
    std::string email;
    std::cout << "Input e-mail here: ";
    std::cin >> email;
    
    int position = -1;
    bool matched = true;
    
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            if (position > -1 || i == 0 || i == email.length() - 1) {
                matched = false;
                break;
            } else {
                position = i;
            }
        }
    }

    if (position != -1) {
        matched = (checkUsername(email.substr(0, position)) &&
                   checkDomain(email.substr(position + 1)));
    } else {
        matched = false;
    }

    std::cout << (matched ? "Yes! This is correct!" : "No! This is not correct!") << std::endl;
    return 0;
}