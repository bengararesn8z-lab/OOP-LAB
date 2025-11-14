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
    vector<Student> getStudentsWithMaxGrade() {
        if (students.empty())
            return {};
        int maxGrade = max_element(
            students.begin(),
            students.end(),
            [](const Student& a, const Student& b) {
                return a.getGrade() < b.getGrade();
            }
        )->getGrade();
        vector<Student> result;
        for (const auto& s : students)
            if (s.getGrade() == maxGrade)
                result.push_back(s);
        return result;
    }
};
int main() {
    StudentGroup group;
    group.addStudent(Student("Ana", 9));
    group.addStudent(Student("Mihai", 10));
    group.addStudent(Student("Ioana", 8));
    group.addStudent(Student("Victor", 10));  
    vector<Student> topStudents = group.getStudentsWithMaxGrade();
    cout << "Studentii cu cea mai mare nota sunt:\n";
    for (const auto& s : topStudents)
        s.display();
    return 0;
}
