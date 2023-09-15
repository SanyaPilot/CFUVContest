#include <iostream>
#include <string>

int main() {
    std::string data;
    std::string buff = "";
    std::cin >> data;

    for (int i = 0; i < data.length(); i++) {
        if (i > 0 && data[i] == data[i - 1]) continue;

        int curCount = 1;
        for (int j = i + 1; j < data.length(); j++) {
            if (data[i] == data[j]) {
                curCount += 1;
            } else {
                break;
            }
        }
        buff += data[i];
        if (curCount != 1) {
            buff += std::to_string(curCount);
        }
    }
    std::cout << buff << "\n";
    return 0;
}
