#include <iostream>
#include <fstream>
#include <map>
#include <set>

int main() {
    std::ifstream file("data.txt");
    std::string target;
    std::cin >> target;

    std::map<std::string, int> answers;
    std::string temp;
    file >> temp;
    while (temp != "stopword") {
        if (temp == target) {
            file >> temp;
            if (temp == "stopword") {
                break;
            }
            answers[temp]++;
        }
        file >> temp;
    }

    if (answers.empty()) {
        std::cout << "-" << "\n";
        return 0;
    }

    std::map<int, std::set<std::string>> final;
    for (auto& [word, count] : answers) {
        final[count].insert(word);
    }

    int count = 0;
    for (auto it = final.rbegin(); it != final.rend(); ++it) {
        for (auto word : it->second) {
            std::cout << word << " ";
            if (++count >= 3) {
                break;
            }
        }
        if (count >= 3) {
            break;
        }
    }

    std::cout << "\n";
    return 0;
}
