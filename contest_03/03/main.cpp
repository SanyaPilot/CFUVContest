#include <iostream>
#include <stack>

const std::string highPrior = "^";
const std::string midPrior = "*/%";
const std::string lowPrior = "+-";
const std::string operators = highPrior + midPrior + lowPrior;
const std::string numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

enum Prior {LOW, MID, HIGH};
int getPriority(char oper) {
    if (lowPrior.find_first_of(oper) != std::string::npos) {
        return LOW;
    } else if (midPrior.find_first_of(oper) != std::string::npos) {
        return MID;
    } else {
        return HIGH;
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::stack<char> pending;
    for (int i = 0; i < input.length(); i++) {
        if (numbers.find_first_of(input[i]) != std::string::npos) {
            int stopPos = input.find_first_of(operators + "()", i);
            int itemLen = stopPos - i;
            std::string item = input.substr(i, itemLen);
            i += itemLen - 1;
            // Put number to the stdout
            std::cout << item << " ";
        } else if (operators.find_first_of(input[i]) != std::string::npos) {
            // Pull operators from the stack
            char curOper = input[i];
            int curPrior = getPriority(curOper);
            if (curPrior != HIGH) {
                while (pending.size() > 0) {
                    char pendOper = pending.top();
                    if (pendOper == '(') {
                        break;
                    }
                    int pendPrior = getPriority(pendOper);
                    if (pendPrior >= curPrior) {
                        std::cout << pendOper << " ";
                        pending.pop();
                    } else {
                        break;
                    }
                }
            }
            // Push operator to the stack
            pending.push(curOper);
        } else if (input[i] == '(') {
            pending.push(input[i]);
        } else if (input[i] == ')') {
            // Pull all operators before '('
            while (pending.size() > 0) {
                char pendOper = pending.top();
                pending.pop();
                if (pendOper == '(') {
                    break;
                }
                std::cout << pendOper << " ";
            }
        }
    }
    // Push all remaining
    while (pending.size() > 0) {
        char pendOper = pending.top();
        pending.pop();
        std::cout << pendOper << " ";
    }
    std::cout << "\n";
    return 0;
}
