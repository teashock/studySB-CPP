#include <iostream>
#include <cpr/cpr.h>

void getResponse() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
    std::cout << r.text << std::endl;
}

void postResponse() {
    cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"));
    std::cout << r.text << std::endl;
}

void putResponse() {
    cpr::Response r = cpr::Put(cpr::Url("http://httpbin.org/put"));
    std::cout << r.text << std::endl;
}

void deleteResponse() {
    cpr::Response r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
    std::cout << r.text << std::endl;
}

void patchResponse() {
    cpr::Response r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
    std::cout << r.text << std::endl;
}

int main() {
    std::cout << "Http requests!\n";
    std::string command;
    while (true) {
        std::cout << "Enter command:\n"
        << "-get - The request's response parameters;\n"
        << "-post - The request's POST parameters;\n"
        << "-put - The request's PUT parameters;\n"
        << "-delete - The request's DELETE parameters;\n"
        << "-patch - The request's PATCH parameters;\n"
        << "-exit - to close program." << std::endl;
        std::cin >> command;
        if (command == "get") {
            getResponse();
        } else if (command == "post") {
            postResponse();
        } else if (command == "put") {
            putResponse();
        } else if (command == "delete") {
            deleteResponse();
        } else if (command == "patch") {
            patchResponse();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command! Try again!\n";
        }
    }
    std::cout << "Closing..." << std::endl;
    return 0;
}