#include <iostream>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> counts;
    for (int i = 0; i < n; i++) {
        std::string temp;
        std::cin >> temp;
        counts[temp] += 1;
    }

    int maxCount = 0;
    std::set<std::string> final;
    for (auto& [word, count] : counts) {
        if (count > maxCount) {
            maxCount = count;
            final.clear();
        }
        if (count == maxCount) {
            final.insert(word);
        }
    }

    for (auto it : final) {
        std::cout << it << " ";
    }
    std::cout << "\n";

    return 0;
}
