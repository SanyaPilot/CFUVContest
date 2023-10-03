#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> data;

    int userCount;
    std::cin >> userCount;
    std::cin.ignore(1);
    for (int i = 0; i < userCount; i++) {
        std::string login;
        std::getline(std::cin, login, ';');
        
        int money;
        std::cin >> money;
        std::cin.ignore(1);

        data[login] = money;
    }

    int reqCount;
    std::cin >> reqCount;
    for (int i = 0; i < reqCount; i++) {
        std::string login;
        std::cin >> login;
        std::cout << data[login] << " ";
    }
    std::cout << "\n";

    return 0;
}
