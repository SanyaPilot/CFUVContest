#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int maxHeight = 2;
    int curHeight = 1;
    bool dir = true;
    int i = 1;

    while (i <= n) {
        for (int j = 0; j < curHeight; j++) {
            if (i > n) break;
            std::cout << i++ << " ";
        }
        std::cout << "\n";
        
        if (dir) {
            curHeight++;
        } else {
            curHeight--;
        }

        if (curHeight == maxHeight || curHeight == 1) {
            dir = !dir;
        }

        if (curHeight == 1) {
            maxHeight++;
        }
    }
    return 0;
}
