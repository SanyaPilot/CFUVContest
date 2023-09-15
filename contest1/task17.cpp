// Test #10 failed
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int hills[n];
    for (int i = 0; i < n; i++) {
        std::cin >> hills[i];
    }

    int waterCount = 0;

    // Find start pos
    for (int i = 0; i < n - 1; i++) {
        if (hills[i + 1] >= hills[i]) continue;
        // Find end pos
        int stop = -1;
        int maxFound = 1;
        for (int j = i + 1; j < n; j++) {
            if (hills[j] >= hills[i]) {
                stop = j;
                break;
            } else if (hills[j] > maxFound) {
                stop = j;
                maxFound = hills[j];
            }
        }
        if (stop == -1) continue;

        int height = std::min(hills[i], hills[stop]);
        // Count water
        for (int k = i + 1; k < stop; k++) {
            waterCount += height - hills[k];
        }
        i = stop - 1;
    }
    std::cout << waterCount << "\n";
    return 0;
}
