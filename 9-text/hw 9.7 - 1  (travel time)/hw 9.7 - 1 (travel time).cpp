#include <iostream>

int main () {
    std::cout << "Travel time\n";

    std::cout << "Input departure time in HH:MM format: ";
    std::string departureTime;
    std::cin >> departureTime;
    std::cout << "Input arrival time in HH:MM format: ";
    std::string arrivalTime;
    std::cin >> arrivalTime;

    if (departureTime.length () != 5 || departureTime [2] != ':' || departureTime[0] < '0' || departureTime[0] > '9' || departureTime[1] < '0' || departureTime[1] > '9' || departureTime[3] < '0' || departureTime[3] > '9'
        || departureTime[4] < '0' || departureTime[4] > '9') {
            std::cout << "Error! You entered the wrong departure time!";
        } else if (arrivalTime.length() != 5 || arrivalTime [2] != ':' || arrivalTime[0] < '0' || arrivalTime[0] > '9' || arrivalTime[1] < '0' || arrivalTime[1] > '9' || arrivalTime[3] < '0' || arrivalTime[3] > '9'
        || arrivalTime[4] < '0' || arrivalTime[4] > '9') {
            std::cout << "Error! You entered the wrong arrival time!";
        } else {
            int departureHours = 10 * (departureTime[0] - '0') + (departureTime[1] - '0');
            int departureMinuts = 10 * (departureTime[3] - '0') + (departureTime[4] - '0');
            int arrivalHours = 10 * (arrivalTime[0] - '0') + (arrivalTime[1] - '0');
            int arrivalMinuts = 10 * (arrivalTime[3] - '0') + (arrivalTime[4] - '0');

            int departure = departureHours * 60 + departureMinuts;
            int arrival = arrivalHours * 60 + arrivalMinuts;

            int travelTime;
            if (departure >= arrival){
                travelTime = 24 * 60 - departure + arrival;
            } else {
                travelTime = arrival - departure;
            } 
            
            std::cout << "Travel time is " << travelTime/60 << " hours " << travelTime % 60 << " minutes.\n";
            
        }  
}