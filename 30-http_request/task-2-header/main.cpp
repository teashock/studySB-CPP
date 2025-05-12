#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::cout << "Find header!\n";
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"));
    if (r.status_code == 200) {
        std::string header = r.text;
        std::string header_start = "<h1>";
        std::string header_end = "</h1>";
        size_t start_pos = header.find(header_start);
        if (start_pos != std::string::npos) {
            start_pos += header_start.length();
            size_t end_pos = header.find(header_end, start_pos);
            if (end_pos != std::string::npos) {
                std::string print = header.substr(start_pos, end_pos - start_pos);
                std::cout << print << std::endl;
            } else {
                std::cout << "Tah </h1> is not found" << std::endl;
            }
        } else {
            std::cout << "Tah <h1> is not found" << std::endl;
        }
    } else {
        std::cout << "Error getting header!\n";
    }
}