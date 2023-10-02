#include <iostream>

int main() {
    double weight, height;
    std::cin >> weight;
    std::cin >> height;
    std::cout << weight / (height * height) << "\n";
    return 0;
}
