#include <iostream>
#include <map>
#include_next <exception>

std::map<std::string, int> databaseEntry(std::map<std::string, int>& database)
{
    std::cout << "Fill out the store database!!!" << std::endl;
    std::string vendorСode;
    int quantity;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Enter a pair of article and number of pieces: " << std::endl;
        std::cin >> vendorСode >> quantity;

        database.insert(std::pair<std::string, int> (vendorСode, quantity));
    }

    return database;
}

void print(std::map<std::string, int>& map, std::string name)
{
    std::cout << "__________" << name << "__________" << std::endl;
    for(std::map<std::string, int>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void addProduct(std::map<std::string, int>& database, std::map<std::string, int>& basket)
{
    std::string vendorСode;
    int quantity;
    std::cout << "Enter the article and quantity of the product: " << std::endl;
    std::cin >> vendorСode >> quantity;

    if (database.find(vendorСode) == database.end() || database[vendorСode] - quantity < 0)
    {
        throw std::invalid_argument(database.find(vendorСode) == database.end() ? "incorrect article" : "incorrect quantity");
    } else
    {
        for(std::map<std::string, int>::iterator it = basket.begin(); it != basket.end(); ++it)
        {
            if (it->first == vendorСode)
            it->second += quantity;
        }
        basket.insert(std::pair<std::string, int> (vendorСode, quantity));
        database[vendorСode] -= quantity;
    }

}

void removeProduct(std::map<std::string, int>& database, std::map<std::string, int>& basket)
{
    std::string vendorСode;
    int quantity;
    std::cout << "Enter the article and quantity of the product: " << std::endl;
    std::cin >> vendorСode >> quantity;

    if (basket.find(vendorСode) == basket.end() || basket[vendorСode] - quantity < 0)
    {
        throw std::invalid_argument(basket.find(vendorСode) == basket.end() ? "incorrect article" : "incorrect quantity");
    } else
    {
        basket[vendorСode] -= quantity;
        database[vendorСode] += quantity;
    }
}

int main() {
    std::map<std::string, int> database;
    databaseEntry(database);
    print(database, "Database");

    std::map<std::string, int> basket;
    std::string command;
    while (command != "exit")
    {
        std::cout << "Enter the command (add, remove, exit): " << std::endl;
        std::cin >> command;

        if (command == "add")
        {
            try {
                addProduct(database, basket);
            }
            catch (const std::invalid_argument& x) {
                std::cerr << "Incorrect information: " << x.what() << std::endl;
            }
            catch (std::runtime_error& )
            {
                std::cerr << "Some kind of exception has happened..." << std::endl;
            }
        }

        if (command == "remove")
        {
            try {
                removeProduct(database, basket);
            }
            catch (const std::invalid_argument& x) {
                std::cerr << "Incorrect information: " << x.what() << std::endl;
            }
            catch (std::runtime_error& )
            {
                std::cerr << "Some kind of exception has happened..." << std::endl;
            }
        }
        print(basket, "Basket");
        print(database, "Database");

    }

}
