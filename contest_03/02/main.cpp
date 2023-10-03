#include <iostream>
#include <stack>

int main() {
    std::string data = "";
    std::getline(std::cin, data, '!');

    std::stack<char> stack;
    for (char i : data) {
        if (i == '(' || i == '[' || i == '{') {
            stack.push(i);
        }
        if (i == ')' || i == ']' || i == '}') {
            if (stack.empty()) {
                std::cout << "NO" << "\n";
                return 0;
            }
            char temp = stack.top();
            if (!((temp == '(' && i == ')') || (temp == '[' && i == ']') || (temp == '{' && i == '}'))) {
                std::cout << "NO" << "\n";
                return 0;
            }
            stack.pop();
        }
    }
    std::cout << "YES" << "\n";
    return 0;
}
