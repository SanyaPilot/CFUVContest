#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

int main() {
    int target_pclass;
    double target_age;
    std::cin >> target_pclass >> target_age;

    std::set<std::pair<int, std::string>> answer;

    std::ifstream file("train.csv");
    file.ignore(100, '\r'); // Drop first line
    std::string line;
    while (std::getline(file, line, '\r')) {
        std::istringstream ss(line);
        // Skip first two cols
        ss.ignore(10, ',');
        ss.ignore(10, ',');

        // Pclass
        std::string pclass_s;
        std::getline(ss, pclass_s, ',');
        int pclass = std::stoi(pclass_s);
        if (pclass != target_pclass) {
            continue;
        }
        
        // Name
        ss.ignore(1); // Drop "
        std::string name = "";
        std::getline(ss, name, '"');
        while (ss.peek() == '"') {
            ss.ignore(1); // Drop "
            std::string temp;
            std::getline(ss, temp, '"');
            name += '"' + temp + '"';
            ss.ignore(1); // Drop "

            std::getline(ss, temp, '"');
            name += temp;
        }
        ss.ignore(1); // Drop ,

        // Sex
        std::string sex;
        std::getline(ss, sex, ',');
        if (sex != "female") {
            continue;
        }

        // Age
        std::string age_s;
        std::getline(ss, age_s, ',');
        int age;
        if (age_s == "") {
            age = 0;
        } else {
            age = std::stoi(age_s);
        }
        if (age <= target_age) {
            continue;
        }

        answer.insert({age, name});
    }

    for (auto &it : answer) {
        std::cout << it.second << "\n";
    }
    return 0;
}
