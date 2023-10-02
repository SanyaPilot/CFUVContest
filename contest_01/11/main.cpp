#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    
    int bDist = abs(a - b);
    int cDist = abs(a - c);
    std::cout << ((bDist < cDist) ? "B " : "C ") << std::min(bDist, cDist) << "\n";
    return 0;
}
