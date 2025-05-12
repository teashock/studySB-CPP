#include <iostream>
#include <map>
#include <vector>
#include <cpr/cpr.h>

int main() {
    std::map<std::string, std::string> arguments;
    std::string key, value;

    while (true) {
        std::cout << "Enter the key of the argument (get/post to complete the input: ";
        std::cin >> key;
        if (key == "get" || key == "post") {
            break;
        }
        std::cout << "Enter the value of the argument: ";
        std::cin >> value;
        arguments[key] = value;
    }
    if (key == "get") {
        std::string url = "http://httpbin.org/get?";
        std::map<std::string, std::string>::iterator it;
        for (it = arguments.begin(); it != arguments.end(); ++it) {
            std::string keyStr = it->first;
            std::string valueStr = it->second;
            url += keyStr + "=" + valueStr + "&";
        }
        url.pop_back();
        cpr::Response r = cpr::Get(cpr::Url{url});
        std::cout << "___________________\n";
        std::cout << "GET:\n" << r.text;
    } else if (key == "post") {
        std::vector<cpr::Pair> pairs;
        std::map<std::string, std::string>::iterator it;
        for (it = arguments.begin(); it != arguments.end(); ++it) {
            pairs.emplace_back(it->first, it->second);
        }
        cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                         cpr::Payload({pairs.begin(), pairs.end()}));
        std::cout << "__________________\n";
        std::cout << "POST:\n" << r.text;
    }
}