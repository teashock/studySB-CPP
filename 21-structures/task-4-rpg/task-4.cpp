#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

struct character {
    std::string name;
    int health;
    int damage;
    int armor;
    int X, Y;
};

const int sizeMap = 20;

character createplayer() {
    character player;
    while(true) {
        std::cout << "\nCreate player.\n";
        std::cout << "-name: ";
        std::cin >> player.name;
        if (player.name.empty()) {
            std::cout << "Name must include symbols! Try again!\n";
            continue;
        }
        std::cout << "-health: ";
        std::cin >> player.health;
        if (player.health <= 0) {
            std::cout << "Health must be greatest than 0! Try again!\n";
            continue;
        }
        std::cout << "-damage: "; 
        std::cin >> player.damage;
        if (player.damage <= 0) {
            std::cout << "Damage must be greatest than 0! Try again!\n";
            continue;
        }
        std::cout << "-armor: ";
        std::cin >> player.armor;
        if (player.armor < 0) {
            std::cout << "Armor cannot be negative! Try again!\n";
            continue;
        }
        player.X = std::rand() % sizeMap + 1;
        player.Y = std::rand() % sizeMap + 1;
        break;
    }
    return player;
}

std::vector<character> createnemy(character& player) {
    std::vector<character> enemies;
    int countEnemy = 5;
    while (enemies.size() < countEnemy){
        character enemy;
        enemy.name = "Enemy " + std::to_string(enemies.size() + 1);
        enemy.health = std::rand() % 101 + 50;
        enemy.damage = std::rand() % 16 + 15;
        enemy.armor = std::rand() % 51;

        bool uniquePosition;
        do {
            uniquePosition = true;
            enemy.X = std::rand() % sizeMap + 1;
            enemy.Y = std::rand() % sizeMap + 1;
            if (enemy.X == player.X && enemy.Y == player.Y) {
                uniquePosition = false;
            }
            for (int i = 0; i < enemies.size(); ++i) {
                if (enemies[i].X == enemy.X && enemies[i].Y == enemy.Y) {
                    uniquePosition = false;
                    break;
                }
            }
        } while (!uniquePosition);
        enemies.push_back(enemy);
    }

    for (int i = 0; i < enemies.size(); ++i) {
        std::cout << "\nEnemy " << i + 1 << " stats:\n"
                << "-name: " << enemies[i].name << ";\n"
                << "-health: " << enemies[i].health << ";\n"
                << "-damage: " << enemies[i].damage << ";\n"
                << "-armor: " << enemies[i].armor << ".\n"; 
    }
    return enemies;
}

void printGameMap (character& player, std::vector<character>& enemies) {
    for (int i = 0; i <= sizeMap + 1; ++i) {
        for (int j = 0; j <= sizeMap + 1; ++j) {
            if (i == 0 || i == sizeMap + 1) {
                std::cout << "-";
            } else if (j == 0 || j == sizeMap + 1) {
                std::cout << "|";
            } else if (i == player.Y && j == player.X) {
                std::cout << "P";
            } else {
                bool isEnemy = false;
                for (int k = 0; k < enemies.size(); ++k) {
                    if (i == enemies[k].Y && j == enemies[k].X && enemies[k].health > 0) {
                        std::cout << "E";
                        isEnemy = true;
                        break;
                    }
                }
                if (!isEnemy) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}

void savegame(character& player, std::vector<character>& enemies) {
    std::ofstream file("save.bin", std::ios::binary);
    if (!file) {
        std::cout << "Error saving game!" << std::endl;
        return;
    }

    size_t nameSize = player.name.size();
    file.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    file.write(player.name.c_str(), nameSize);
    file.write(reinterpret_cast<const char*>(&player.health), sizeof(player.health));
    file.write(reinterpret_cast<const char*>(&player.damage), sizeof(player.damage));
    file.write(reinterpret_cast<const char*>(&player.armor), sizeof(player.armor));
    file.write(reinterpret_cast<const char*>(&player.X), sizeof(player.X));
    file.write(reinterpret_cast<const char*>(&player.Y), sizeof(player.Y));

    size_t enemyCount = enemies.size();
    file.write(reinterpret_cast<const char*>(&enemyCount), sizeof(enemyCount));
    for (int i = 0; i < enemyCount; ++i) {
        size_t enemyNameSize = enemies[i].name.size();
        file.write(reinterpret_cast<const char*>(&enemyNameSize), sizeof(enemyNameSize));
        file.write(enemies[i].name.c_str(), enemyNameSize);
        file.write(reinterpret_cast<const char*>(&enemies[i].health), sizeof(enemies[i].health));
        file.write(reinterpret_cast<const char*>(&enemies[i].damage), sizeof(enemies[i].damage));
        file.write(reinterpret_cast<const char*>(&enemies[i].armor), sizeof(enemies[i].armor));
        file.write(reinterpret_cast<const char*>(&enemies[i].X), sizeof(enemies[i].X));
        file.write(reinterpret_cast<const char*>(&enemies[i].Y), sizeof(enemies[i].Y));
    }
    file.close();
    std::cout << "Game saved!" << std::endl;
}

void loadgame(character& player, std::vector<character>& enemies) {
    std::ifstream file("save.bin", std::ios::binary);
    if (!file) {
        std::cout << "File not found! Starting a new game!\n" << std::endl;
        return;
    }

    size_t nameSize;
    file.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    player.name.resize(nameSize);
    file.read(&player.name[0], nameSize);
    file.read(reinterpret_cast<char*>(&player.health), sizeof(player.health));
    file.read(reinterpret_cast<char*>(&player.damage), sizeof(player.damage));
    file.read(reinterpret_cast<char*>(&player.armor), sizeof(player.armor));
    file.read(reinterpret_cast<char*>(&player.X), sizeof(player.X));
    file.read(reinterpret_cast<char*>(&player.Y), sizeof(player.Y));

    size_t enemyCount;
    file.read(reinterpret_cast<char*>(&enemyCount), sizeof(enemyCount));
    enemies.resize(enemyCount);
    for (int i = 0; i < enemies.size(); ++i) {
        size_t enemyNameSize;
        file.read(reinterpret_cast<char*>(&enemyNameSize), sizeof(enemyNameSize));
        enemies[i].name.resize(enemyNameSize);
        file.read(&enemies[i].name[0], enemyNameSize);
        file.read(reinterpret_cast<char*>(&enemies[i].health), sizeof(enemies[i].health));
        file.read(reinterpret_cast<char*>(&enemies[i].damage), sizeof(enemies[i].damage));
        file.read(reinterpret_cast<char*>(&enemies[i].armor), sizeof(enemies[i].armor));
        file.read(reinterpret_cast<char*>(&enemies[i].X), sizeof(enemies[i].X));
        file.read(reinterpret_cast<char*>(&enemies[i].Y), sizeof(enemies[i].Y));
    }
    file.close();
    std::cout << "Game loaded!" << std::endl;
    std::cout << "\nPlayer " << player.name << " stats: \n";
    std::cout << "-health: " << player.health << ";\n" << "-damage: " << player.damage << ";\n" << "-armor: " << player.armor << ".\n";
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i].health > 0) {
            std::cout << "\nEnemy " << i + 1 << " stats:\n"
            << "-health: " << enemies[i].health << ";\n"
            << "-damage: " << enemies[i].damage << ";\n"
            << "-armor: " << enemies[i].armor << ".\n";
        } else {
            std::cout << "\nEnemy " << i + 1 << " is dead!\n";
        }
    }
}

void movePlayer(character& player, int newX, int newY, std::vector<character>& enemies) {
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i].X == newX && enemies[i].Y == newY) {
            int damageDealt = player.damage - enemies[i].armor;
            if (damageDealt > 0) {
                enemies[i].health -= damageDealt;
                if (enemies[i].health <= 0) {
                    std::cout << "\n" << enemies[i].name << " has been defeated!\n";
                } else {
                    std::cout << "\n" << player.name << " attacks " << enemies[i].name << " for " << damageDealt << " damage!\n";
                    std::cout << "Enemy " << i + 1 << " stats:\n"
                        << "-health: " << enemies[i].health << ";\n"
                        << "-damage: " << enemies[i].damage << ";\n"
                        << "-armor: " << enemies[i].armor << ".\n"; 
                }
            } 
        }
    }

    if (newX > 0 && newX <= sizeMap && newY > 0 && newY <= sizeMap) {
        player.X = newX;
        player.Y = newY;
    } else {
        std::cout << "Move out of bounds! Try again.\n";
    }
}

void moveEnemies(character& player, std::vector<character>& enemies) {
    for (int i = 0; i < enemies.size(); ++i) {
        int direction = std::rand() % 4;
        int newX = enemies[i].X, newY = enemies[i].Y;

        if (direction == 0) {
            newY++;
        } else if (direction == 1) {
            newY--;
        } else if (direction == 2) {
            newX--;
        } else if (direction == 3) {
            newX++;
        }
        
        if (enemies[i].X == player.X && enemies[i].Y == player.Y) {
            int damageDealt = enemies[i].damage - player.armor;
            if (damageDealt < 0) {
                std::cout << "\nThe enemy did not penetrate the player's armor!\n";
            } else {
                player.health -= damageDealt;
                std::cout << "\n" << enemies[i].name << " attacks " << player.name << " for " << damageDealt << " damage!\n";
                std::cout << player.name << " has " << player.health << " health.\n";
            }    
        }

        if (newX > 0 && newX <= sizeMap && newY > 0 && newY <= sizeMap) {
            bool collision = false;
            for (int j = 0; j < enemies.size(); ++j) {
                if (j != i && enemies[j].X == newX && enemies[j].Y == newY) {
                    collision = true;
                    break;
                }
            }
            if (!collision) {
                enemies[i].X = newX;
                enemies[i].Y = newY;
            }
        } else {
            break;
        }
    }
}

bool allEnemiesDefeated(std::vector<character>& enemies) {
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i].health > 0) {
            return false;
        }
    }
    return true;
}

bool isPlayerAlive(character& player) {
    return player.health > 0;
}

void inputcommand(character& player, std::vector<character>& enemies) {
    std::string command;
    while (isPlayerAlive(player) && !allEnemiesDefeated(enemies)) {
        printGameMap(player, enemies);
        std::cout << "Enter command (L, R, U, D, save, load, exit): ";
        std::cin >> command;
        
        if (command == "save") {
            savegame(player, enemies);
        } else if (command == "load") {
            loadgame(player, enemies);
        } else if (command == "exit") {
            break;
        } else {
            int newX = player.X;
            int newY = player.Y;
        
            if (command == "L") {
                newX--;
            } else if (command == "R") {
                newX++;
            } else if (command == "U") {
                newY--;
            } else if (command == "D") {
                newY++;
            } else {
                std::cout << "Incorrect command!";
                continue;
            }
            movePlayer(player, newX, newY, enemies);
            moveEnemies(player, enemies);
        }
    }
    if (allEnemiesDefeated(enemies)) {
        std::cout << "\nCongratulations! You have defeated all enemies!\n";
    } else if (!isPlayerAlive) {
        std::cout << "\nGame Over! You have been defeated!\n";
    } else {
        return;
    }
}

int main() {
    std::srand(std::time(nullptr));
    std::cout << "Dungeons & Dragons!\n";

    character player;
    std::vector<character> enemies;
    
    std::string startCommand;
    std::cout << "Do you want to start a new game(1), load a saved game(2) or exit(3)? (1-3): ";
    std::cin >> startCommand;
    
    while (true) {
        if (startCommand == "1") {
            player = createplayer();
            enemies = createnemy(player);
            inputcommand(player, enemies);
        } else if (startCommand == "2") {
            loadgame(player, enemies);
            inputcommand(player, enemies);
        } else if (startCommand == "3") {
            break;
        } else {
            std::cout << "Incorrect command! Try again!\n";
        }
        std::cout << "Do you want to start a new game(1), load a saved game(2) or exit(3)? (1-3): ";
        std::cin >> startCommand; 
    }
}    