#include <bits/stdc++.h>
using namespace std;
class Student {
private:
    string name;
    int grade;
public:
    Student(string name, int grade) {
        this->name = name;
        this->grade = grade;
    }
    string getName() const { return name; }
    int getGrade() const { return grade; }
    void display() const {
        cout << "Student: " << name << ", grade: " << grade << endl;
    }
};
class StudentGroup {
private:
    vector<Student> students;
public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }
    Student* findByName(const string& name) {
        auto it = find_if(students.begin(), students.end(),
            [&](const Student& s) {
                return s.getName() == name;
            });
        if (it != students.end())
            return &(*it);
        return nullptr;
    }
    Student* findByGrade(int grade) {
        auto it = find_if(students.begin(), students.end(),
            [&](const Student& s) {
                return s.getGrade() == grade;
            });
        if (it != students.end())
            return &(*it);
        return nullptr;
    }
};
int main() {
    StudentGroup group;
    group.addStudent(Student("Ana", 9));
    group.addStudent(Student("Mihai", 10));
    group.addStudent(Student("Ioana", 8));
    string nameToFind = "Mihai";
    Student* s1 = group.findByName(nameToFind);
    if (s1 != nullptr) {
        cout << "Student gasit dupa nume:\n";
        s1->display();
    } else {
        cout << "Studentul " << nameToFind << " NU exista.\n";
    }
    int gradeToFind = 8;
    Student* s2 = group.findByGrade(gradeToFind);
    if (s2 != nullptr) {
        cout << "Student gasit dupa nota:\n";
        s2->display();
    } else {
        cout << "Nu exista student cu nota " << gradeToFind << ".\n";
    }
    return 0;
}
