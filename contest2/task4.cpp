#include <iostream>
#include <tuple>

// Начало вставленного кода
#include <utility>
#include <algorithm>
#include <numeric>

std::pair<int, int> reduce(int m, int n) {
    int gcd = std::gcd(m, n);
    return std::make_pair(m / gcd, n / gcd);
}

std::tuple<int, int, int> find_lcm(int m, int n) {
    int lcm = std::lcm(m, n);
    return std::make_tuple(lcm, lcm / m, lcm / n);
}
// Конец

int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto[lcm, c1, c2] = find_lcm(n1, n2);
    auto[m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}