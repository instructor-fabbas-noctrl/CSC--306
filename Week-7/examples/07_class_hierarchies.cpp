// CSCE 306 | Week 7 • Example 07: Class hierarchies -- multi-level inheritance (Ch. 15.5)
// Build: g++ -std=c++17 -Wall -Wextra 07_class_hierarchies.cpp -o hierarchy
//
//                Person
//                  ^
//          +-------+--------+
//       Student          Faculty
//          ^
//    GraduateStudent

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    explicit Person(const string& n) : name(n) {}
    string getName() const { return name; }
    string role() const    { return "Person"; }
};

class Student : public Person {
protected:
    double gpa;
public:
    Student(const string& n, double g) : Person(n), gpa(g) {}
    string role() const { return "Student"; }
    double getGpa() const { return gpa; }
};

class GraduateStudent : public Student {
private:
    string advisor;
public:
    GraduateStudent(const string& n, double g, const string& adv) : Student(n, g), advisor(adv) {}
    string role() const { return "Graduate student (advisor: " + advisor + ")"; }
};

class Faculty : public Person {
private:
    string department;
public:
    Faculty(const string& n, const string& d) : Person(n), department(d) {}
    string role() const { return "Faculty, " + department; }
};

int main()
{
    GraduateStudent g("Ada", 3.9, "Prof. Abbas");
    Faculty f("Prof. Abbas", "Computer Science");

    cout << g.getName() << ": " << g.role() << ", GPA " << g.getGpa() << '\n';  // 3 levels of members
    cout << f.getName() << ": " << f.role() << '\n';

    // Every GraduateStudent IS-A Student and IS-A Person:
    const Student& s = g;
    const Person&  p = g;
    cout << "as Student: " << s.role() << "\nas Person:  " << p.role() << '\n';
    // Notice role() changes with the TYPE OF THE REFERENCE, not the real object.
    return 0;
}
