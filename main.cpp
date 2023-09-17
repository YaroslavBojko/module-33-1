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

void print(std::map<std::string, int>& database)
{
    for(std::map<std::string, int>::iterator it = database.begin(); it != database.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

std::map<std::string, int> addProduct(std::map<std::string, int>& database)
{
    std::string vendorСode;
    int quantity;
    std::cout << "Enter the article and quantity of the product: " << std::endl;
    std::cin >> vendorСode >> quantity;

    if (database.find(vendorСode) == database.end())
    {
        throw std::invalid_argument(database.find(vendorСode) == database.end() ? "incorrect article" : "&&&");
    } else
    {
        database[vendorСode] += quantity;
    }
    return database;
}

std::map<std::string, int> removeProduct(std::map<std::string, int>& database)
{
    std::string vendorСode;
    int quantity;
    std::cout << "Enter the article and quantity of the product: " << std::endl;
    std::cin >> vendorСode >> quantity;

    if (database.find(vendorСode) == database.end())
    {
        throw std::invalid_argument(database.find(vendorСode) == database.end() ? "incorrect article" : "&&&");
    } else
    {
        database[vendorСode] -= quantity;
    }
    return database;
}

int main() {
    std::map<std::string, int> database;
    databaseEntry(database);
    print(database);


    std::string command;
    while (command != "exit")
    {
        std::cout << "Enter the command (add, remove, exit): " << std::endl;
        std::cin >> command;

        if (command == "add")
        {
            try {
                addProduct(database);
            }
            catch (const std::invalid_argument& x) {
                std::cerr << "Incorrect information: " << x.what() << std::endl;
            }
        }

        if (command == "remove")
        {
            try {
                removeProduct(database);
            }
            catch (const std::invalid_argument& x) {
                std::cerr << "Incorrect information: " << x.what() << std::endl;
            }
        }
        print(database);
    }

}
