#include <iostream>
#include <algorithm>

std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    uint n;
    std::cin >> n;

    std::string buf = "";
    while (n > 0) {
        buf += letters[(n - 1) % 26];
        n = (n - 1) / 26;
    }
    std::reverse(buf.begin(), buf.end());
    std::cout << buf << "\n";
    return 0;
}
