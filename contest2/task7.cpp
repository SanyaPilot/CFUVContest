#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

// Начало вставленного кода
Student make_student(std::string line) {
    int pos = line.find(';');
    int oldPos = pos;
    Student student;
    // Name
    student.name = line.substr(0, pos);

    // Group
    pos = line.find(';', oldPos + 1);
    student.group = line.substr(oldPos + 1, pos - oldPos - 1);
    oldPos = pos;

    // Cources
    pos = line.find(';', oldPos + 1);
    while (true) {
        Course curCourse;
        // Name
        curCourse.name = line.substr(oldPos + 1, pos - oldPos - 1);
        oldPos = pos;
        pos = line.find(';', oldPos + 1);

        // Semester
        curCourse.semester = std::stoi(line.substr(oldPos + 1, pos - oldPos - 1));
        oldPos = pos;
        pos = line.find(';', oldPos + 1);

        // Finished?
        curCourse.finished = std::stoi(line.substr(oldPos + 1, (pos == std::string::npos ? pos : (pos - oldPos - 1))));
        if (pos == std::string::npos) break;

        oldPos = pos;
        pos = line.find(';', oldPos + 1);

        student.courses.push_back(curCourse);
    }
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

bool is_debtor(Student student, int cur_semester, int max_debt) {
    int debts = 0;
    for (auto course : student.courses) {
        if (course.semester >= cur_semester) continue;
        if (!course.finished) debts++;
    }
    return debts > max_debt;
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
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(stud_count);
    for(auto& student: students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }
    
    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
                 students.end(),
                 std::back_inserter(expulsion_candidates),
                 [cur_semester, max_debt](const Student& student){
                     return is_debtor(student, cur_semester, max_debt);
                 });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}