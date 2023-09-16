#include <iostream>
#include <map>

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

int main() {
    std::map<std::string, int> database;

    databaseEntry(database);
    print(database);

}
