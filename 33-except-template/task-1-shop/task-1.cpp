#include <iostream>
#include <map>
#include <exception>
#include <string>

class Store{
    std::map<std::string, int> inventory;
public:
    void addArticle(const std::string& article, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be positive integer!");
        }
        inventory[article] += quantity;
    }

    bool remainsInventory(const std::string& article, int quantity) const {
        std::map<std::string, int>::const_iterator it = inventory.find(article);
        if (it != inventory.end() && it->second >= quantity) {
            return true;
        }
        return false;
    }

    void removeArticle(const std::string& article, int quantity) {
        if (!remainsInventory(article, quantity)) {
            throw std::runtime_error("Not enough inventory or article not found");
        }
        inventory[article] -= quantity;
        if (inventory[article] == 0) {
            inventory.erase(article);
        }
    }

    void printInventory() const {
        std::cout << "Store inventory:\n";
        if (inventory.empty()) {
            std::cout << "\tempty.\n";
        }
        for (const auto& item : inventory) {
            std::cout << "\tarticle: " << item.first << ";\tquantity: " << item.second << ".\n";
        }
    }
};

class Basket{
    std::map<std::string, int> basket;
public:
    void addProduct(const std::string& article, int quantity, Store& store) {
        if (!store.remainsInventory(article, quantity)) {
            throw std::runtime_error("Not enough products at the store to add to basket!");
        }
        store.removeArticle(article, quantity);
        basket[article] += quantity;
    }
    
    void removeProduct(const std::string& article, int quantity, Store& store){
        std::map<std::string, int>::const_iterator it = basket.find(article);
        if (it == basket.end() || it->second < quantity) {
            throw std::runtime_error("Not enough items in cart to remove.");
        }
        basket[article] -= quantity;
        if (basket[article] == 0) {
            basket.erase(article);
        }
        store.addArticle(article, quantity);
    }

    void printBasket() {
        std::cout << "Basket contents:\n";
        if (basket.empty()) {
            std::cout << "\tempty.\n";
        }
        for (std::map<std::string, int>::iterator it = basket.begin(); it != basket.end(); ++it) {
            std::cout << "\tarticle: " << it->first << ";\tquantity: " << it->second << ".\n";
        }
    }
};

int main() {
    Store store;
    Basket basket;

    std::cout << "Let's fill up the store's inventory!\n";
    std::string article;
    int quantity;
    while (true) {
        std::cout << "Enter the product article  or 'done' to finish: ";
        std::cin >> article;
        if (article == "done") {
            std::cout << "Great! Lets start shopping!\n";
            break;
        }
        std::cout << "Enter the " << article << " quantity: ";
        while (!(std::cin >> quantity)) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cerr << "Invalid input! Quantity must be a number! Try again!\n";
        }

        try {
            store.addArticle(article, quantity);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    
    std::string command;
    while (true) {
        std::cout << "Enter command\n"
                << "\t- 'add' - to add a product to basket;\n"
                << "\t- 'remove' - to remove product from basket;\n"
                << "\t- 'display' - to print products in basket;\n"
                << "\t- 'store' to print store inventory;\n"
                << "\t- 'exit' - to finish shopping.\n";
        std::cin >> command;
        if (command == "exit") {
            std::cout << "Thank you for shopping with us!\n";
            break;
        }

        if (command == "add" || command == "remove") {
            std::cout << "Enter the product article: ";
            std::cin >> article;
            std::cout << "Enter the " << article << " quantity: ";
            while (!(std::cin >> quantity)) {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cerr << "Invalid input! Quantity must be a number! Try again!\n";
            }

            try {
                if (command == "add") {
                    basket.addProduct(article, quantity, store);
                } else if (command == "remove") {
                    basket.removeProduct(article, quantity, store);
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        } else if (command == "display") {
            basket.printBasket();
        } else if (command == "store") {
            store.printInventory();
        } else {
            std::cerr << "Unknown command!";
        }
    }
    return 0;
}