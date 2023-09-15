#include <iostream>
#include <map>

int main() {
    std::string a_str, b_str;
    std::cin >> a_str;
    std::cin >> b_str;

    std::map<char, int> a_count, b_count;
    for (int i = 0; i < a_str.length(); i++) {
        a_count[a_str[i]]++;
    }
    for (int i = 0; i < b_str.length(); i++) {
        b_count[b_str[i]]++;
    }

    bool ok = true;
    for (auto it = a_count.begin(); it != a_count.end(); ++it) {
        if (b_count[it->first] < it->second) {
            ok = false;
            break;
        }
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
    return 0;
}
