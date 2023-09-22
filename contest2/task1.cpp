#include <iostream>

// Начало вставленного кода
#include <cmath>

bool is_prime(int num) {
    for (int i = 2; i <= (sqrt(num) + 1); i++) {
        if (num % i == 0) return false;
    }
    return true;
}
// Конец

int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
