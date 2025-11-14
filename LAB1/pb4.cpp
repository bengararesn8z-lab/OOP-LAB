#include <bits/stdc++.h>
using namespace std;
class Person {
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(move(n)), age(a) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    void print() const {
        cout << name << " (" << age << " ani)" << endl;
    }
};
class PeopleList {
private:
    vector<Person> people;
public:
    void addPerson(const Person& p) {
        people.push_back(p);
    }
    void printAll() const {
        for (const auto& p : people)
            p.print();
        cout << "----------------------" << endl;
    }
    // sortare dupa varsta descrescator
    void sortByAgeDesc() {
        sort(people.begin(), people.end(),
             [](const Person& p1, const Person& p2) {
                 return p1.getAge() > p2.getAge();
             });
    }
    // sortare dupa nume crescator
    void sortByNameAsc() {
        sort(people.begin(), people.end(),
             [](const Person& p1, const Person& p2) {
                 return p1.getName() < p2.getName();
             });
    }
};
int main() {
    PeopleList list;
    list.addPerson(Person("Andrei", 22));
    list.addPerson(Person("Maria", 19));
    list.addPerson(Person("Ioana", 25));
    list.addPerson(Person("Paul", 22));
    list.addPerson(Person("Diana", 20));
    cout << "Lista originală:\n";
    list.printAll();
    cout << "Sortare după vârstă (descrescător):\n";
    list.sortByAgeDesc();
    list.printAll();
    cout << "Sortare după nume (alfabetic crescător):\n";
    list.sortByNameAsc();
    list.printAll();
    return 0;
}
