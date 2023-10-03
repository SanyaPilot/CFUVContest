#include <iostream>
#include <set>

int main() {
    std::multiset<long> data;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long temp;
        std::cin >> temp;
        data.insert(temp);
    }

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long temp;
        std::cin >> temp;
        data.insert(temp);
    }

    for (auto it : data) {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}
