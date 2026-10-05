// CSCE 306 | Week 5 • Example 10: Aggregation vs composition (Ch. 14.7)
// Build: g++ -std=c++17 -Wall -Wextra 10_aggregation_vs_composition.cpp -o agg

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Instructor {
private:
    string name;
public:
    explicit Instructor(const string& n) : name(n) {}
    string getName() const { return name; }
};

class Syllabus {
private:
    string policy;
public:
    explicit Syllabus(const string& p) : policy(p) {}
    string getPolicy() const { return policy; }
};

class Course {
private:
    string       code;
    Syllabus     syllabus;    // COMPOSITION: Course owns it; same lifetime (UML filled ◆)
    Instructor*  instructor;  // AGGREGATION: Course only refers to it; it lives on
                              // independently (UML hollow ◇). Course must NOT delete it.
public:
    Course(const string& c, const string& policy, Instructor* who)
        : code(c), syllabus(policy), instructor(who) {}

    void setInstructor(Instructor* who) { instructor = who; }

    void print() const
    {
        cout << code << " taught by "
             << (instructor ? instructor->getName() : "TBA")
             << " -- " << syllabus.getPolicy() << '\n';
    }
};

int main()
{
    Instructor abbas("Prof. Abbas"), guest("Dr. Guest");
    {
        Course oop("CSCE 306", "late work -10%/day", &abbas);
        Course ds ("CSCE 310", "no late work", &abbas);   // one instructor, many courses
        oop.print();
        ds.print();
        ds.setInstructor(&guest);
        ds.print();
    }   // courses (and their syllabi) are destroyed here...
    cout << abbas.getName() << " still exists after the courses are gone.\n";   // ...instructors are not
    return 0;
}
