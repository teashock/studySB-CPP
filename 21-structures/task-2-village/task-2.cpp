#include <iostream>
#include <vector>

enum room_type {
    bedroom,
    kitchen,
    bathroom,
    children,
    living
};

enum building_type{
    house,
    garage,
    barn,
    bathhouse
};

struct room {
    room_type rooms;
    int square = 0;
};

struct floor {
  float heightFloor = 0;
  std::vector<room> rooms;  
};

struct building{
    building_type builds;
    int square = 0;
    std::vector<floor> floors;
    bool furnace = false;
    int totalFurnace = 0;
};

struct plot
{
    int square = 0;
    int numberPlot = 0;
    std::vector<building> buildings;
};

void inputRoomSquare(room& newRoom, room_type type) {
    newRoom.rooms = type;
    switch (type) {
        case room_type::bedroom:
            std::cout << "Enter the bedroom square: ";
            break;
        case room_type::kitchen:
            std::cout << "Enter the kitchen square: ";
            break;
        case room_type::bathroom:
            std::cout << "Enter the bathroom square: ";
            break;
        case room_type::children:
            std::cout << "Enter the children square: ";
            break;
        case room_type::living:
            std::cout << "Enter the living square: ";
            break;
        default:
            std::cout << "Invalid room type!\n";
        return;
    }
    std::cin >> newRoom.square;
    while (true) {
        if (newRoom.square <= 0) {
            std::cout << "Invalid input! Please enter a positive number: ";
            std::cin >> newRoom.square;
        } else {
            break;
        }
    }
}

void inputBuildingSquare(building& newBuilding, building_type type) {
    switch (type) {
        case building_type::garage:
            std::cout << "Enter the garage square: ";
            break;
        case building_type::barn:
            std::cout << "Enter the barn square: ";
            break;
        case building_type::bathhouse:
            std::cout << "Enter the bathhouse square: ";
            break;
        default:
            return;
    }
    std::cin >> newBuilding.square;
    while (true) {
        if (newBuilding.square <= 0) {
            std::cout << "Invalid input! Please enter a positive number: ";
            std::cin >> newBuilding.square;
        } else {
            break;
        }
    }
}

int main() {
    std::cout << "Cadastral calculation!\n";
    int totalArea, countPlots;
    while (true) {
        std::cout << "Enter the total square of the area village: ";
        std::cin >> totalArea;
        if (totalArea <= 0) {
            std::cout << "Invalid input! Please enter a positive number!\n";
            continue;
        } 
        std::cout << "Enter the number of plots in village: ";
        std::cin >> countPlots;
        if (countPlots <= 0) {
            std::cout << "Invalid input! Please enter a positive number!\n";
            continue;
        } 
        break;
    }
    int numberPlot = 1;

    int totalBuildingArea = 0;
    int totalBuildingsWithFurnace = 0;

    for (int i = 0; i < countPlots; ++i){
        plot currentPlot;
        currentPlot.numberPlot = numberPlot;

        int numberBuildings;
        while (true) {
            std::cout << "Enter the count of buildings in " << currentPlot.numberPlot << " plot: \n";
            std::cin >> numberBuildings;
            if (numberBuildings <= 0) {
                std::cout << "Number of buildings must be greatest 0!\n";
                continue;
            } else {
                break;
            }
        }

        for (int j = 0; j < numberBuildings; ++j) {
            std::cout << "Enter number building:\n";
            std::cout << "1 - houses;\n2 - garages;\n3 - barn;\n4 - bathhouse.\n";
            int commandBuilding;
            std::cin >> commandBuilding;

            building newBuilding;
            newBuilding.builds = static_cast<building_type>(commandBuilding - 1);

            switch (newBuilding.builds) {
                case building_type::house:                 
                    std::cout << "Is there furnace available? ('y' - yes, 'n' - no)\n";
                    char answerFurnace;
                    while (true) {
                        std::cin >> answerFurnace;
                        if (answerFurnace == 'y') {
                            newBuilding.furnace = true;
                            std::cout << "Enter the number of furnaces: ";
                            std::cin >> newBuilding.totalFurnace;
                            break;
                        } else if (answerFurnace == 'n') {
                            break;
                        } else { 
                            std::cout << "Incorrect answer! Input 'y'/'n'!\n";
                            continue;
                        }
                    }

                    int countFloors;
                    std::cout << "Enter the number of floors in house: ";
                    std::cin >> countFloors;
                    if (countFloors <= 0) {
                        std::cout << "Invalid number of floors!\n";
                        continue;
                    }

                    for (int k = 0; k < countFloors; ++k) {
                        floor newFloor;
                        std::cout << "Enter the height of the " << k + 1 << " floor: ";
                        std::cin >> newFloor.heightFloor;
                        
                        int countRooms;
                        std::cout << "Enter the number of rooms on the " << k + 1 << " floor:\n";
                        std::cin >> countRooms;
                        if (countRooms <= 0) {
                            std::cout << "Invalid number of rooms!\n";
                            continue;
                        }
                    
                        for (int l = 0; l < countRooms; ++l){
                            std::cout << "Enter type room:\n";
                            std::cout << "1 - bedroom;\n2 - kitchen;\n3 - bathroom;\n4 - children;\n5 - living.\n"; 
                            int commandRoom;
                            std::cin >> commandRoom;
                            room newRoom;
                            inputRoomSquare(newRoom, static_cast<room_type>(commandRoom-1));
                            if (k == 0) {
                                totalBuildingArea += newRoom.square;
                            }
                            newFloor.rooms.push_back(newRoom);
                        }
                        newBuilding.floors.push_back(newFloor);
                    }
                    currentPlot.buildings.push_back(newBuilding);
                    if (newBuilding.furnace) {
                        totalBuildingsWithFurnace++;
                    }
                break;
                
                case building_type::garage:
                case building_type::barn:
                case building_type::bathhouse:
                    inputBuildingSquare(newBuilding, static_cast<building_type>(commandBuilding - 1));
                    if (commandBuilding == 4) {
                        std::cout << "Is there furnace available? ('y' - yes, 'n' - no)\n";
                        char answerFurnace;
                        std::cin >> answerFurnace;
                        if (answerFurnace == 'y') {
                            newBuilding.furnace = true;
                            std::cout << "Enter the number of furnace: ";
                            std::cin >> newBuilding.totalFurnace;
                        } else if (answerFurnace == 'n') {
                            break;
                        } else { 
                            std::cout << "Incorrect answer! Input 'y'/'n'!\n";
                        }
                    }
                    currentPlot.buildings.push_back(newBuilding);
                    if (newBuilding.furnace) {
                        totalBuildingsWithFurnace++;
                    }
                    totalBuildingArea += newBuilding.square;
                break;
            }
        }
        std::cout << "\nPlot number: " << currentPlot.numberPlot << "\n";
        std::cout << "Number of buildings: " << currentPlot.buildings.size() << "\n";
        for (int i = 0; i < currentPlot.buildings.size(); ++i) {
            std::cout << "Building type: " << currentPlot.buildings[i].builds << ", Floors: " << currentPlot.buildings[i].floors.size() << "\n";
            for (int j = 0; j < currentPlot.buildings[i].floors.size(); ++j) {
                std::cout << "Heights floor " << j + 1 << ": " << currentPlot.buildings[i].floors[j].heightFloor << "\n";
                std::cout << "Rooms on " << j + 1 << " floor: " << currentPlot.buildings[i].floors[j].rooms.size() << "\n";
            }
        }
        ++numberPlot;
    }

    std::cout << "\nTotal building area: " << totalBuildingArea << "\n";
    std::cout << "There is an area left: " << totalArea - totalBuildingArea  << "\n";
    if (totalBuildingArea > totalArea) {
        std::cout << "Warning: Total building area exceeds the total area of the village!\n";
    }
    std::cout << "Total buildings with furnace: " << totalBuildingsWithFurnace << "\n";
}