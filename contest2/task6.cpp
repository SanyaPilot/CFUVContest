#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

// Начало вставленного кода
Student make_student(std::string line) {
    int pos = line.find(';');
    Student student;
    student.name = line.substr(0, pos);
    student.group = line.substr(pos + 1, std::string::npos);
    return student;
}

bool is_upper(Student a, Student b) {
    if (a.group != b.group) {
        std::vector<std::string> groups;
        groups.push_back(a.group);
        groups.push_back(b.group);

        std::sort(groups.begin(), groups.end());

        return a.group == groups[0];
    } else {
        std::vector<std::string> names;
        names.push_back(a.name);
        names.push_back(b.name);

        std::sort(names.begin(), names.end());

        return a.name == names[0];
    }
}

void print(std::vector<Student> data) {
    if (data.size() == 0) {
        std::cout << "Empty list!" << "\n";
        return;
    }

    std::string prevGroup = "";
    for (auto st : data) {
        if (st.group != prevGroup) {
            prevGroup = st.group;
            std::cout << st.group << "\n";
        }
        std::cout << "- " << st.name << "\n";
    }
}
// Конец

int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline
    
    std::vector<Student> students(count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::sort(students.begin(), students.end(), is_upper);
    
    print(students);
}
