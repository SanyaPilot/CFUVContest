#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<std::string> seq1, final;
    for (int i = 0; i < n; i++) {
        std::string temp;
        std::cin >> temp;
        seq1.insert(temp);
    }

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string temp;
        std::cin >> temp;
        if (seq1.count(temp) > 0) {
            final.insert(temp);
        }
    }

    if (final.empty()) {
        std::cout << -1 << "\n";
        return 0;
    }

    for (auto it : final) {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}
