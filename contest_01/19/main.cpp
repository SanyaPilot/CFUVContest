#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<std::string> data;
    while (true) {
        std::string buf;
        std::cin >> buf;
        if (buf == "end") break;
        data.push_back(buf);
    }

    std::set<std::string> ordered;
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (std::count(data.begin(), data.end(), *it) > 1) {
            ordered.insert(*it);
        }
    }

    for (auto it = ordered.begin(); it != ordered.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    return 0;
}
