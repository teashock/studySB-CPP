#include <iostream>
#include <cmath>

bool checkOctet(std::string octet) {
    
    if (octet.length() == 0 || octet.length() > 3 || (octet.length() > 1 && octet[0] == '0')) {
        return false;
    }
        
    int value = 0;
    for (char c : octet) {
        if (c <'0' || c >'9') {
                return false;              
            } 
            value = value * 10 + (c - '0');
        }
    return value >= 0 && value <= 255;
}
        

bool checkIP(std::string ip) {
    if (ip.length() < 7 || ip.length() > 15 || ip[0] == '.' || ip[ip.length()-1] == '.') {
        return false;
    }

    std::string octet;
    int octetCount = 0;
    for (char c : ip) {
        if (c =='.') {
            if (octet.length() == 0 || !checkOctet(octet)) {
                return false;
            }
            octet.clear();
            octetCount++;
        } else {
            octet += c;
        }
    }
    
    if (octet.length() != 0 && !checkOctet(octet)) {
        return false;
    }
    octetCount++;
    return octetCount == 4;
}

int main() {
    std::cout << "IP validation!" << std::endl;
    std::string ipv4;
    std::cout << "Input IPv4 address for validation:" << std::endl;
    std::cin >> ipv4;

    std::cout << (checkIP(ipv4) ? "Valid!\n" : "Invalid!\n") << std::endl;

    return 0;
}