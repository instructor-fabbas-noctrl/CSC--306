// CSCE 306 | Week 3 • Example 10: Structured data -- struct (Ch. 11)
// Build: g++ -std=c++17 -Wall -Wextra 10_structs.cpp -o structs

#include <iostream>
#include <string>
using namespace std;

struct Date {
    int month = 1;          // default member initializers (C++11)
    int day   = 1;
    int year  = 2026;
};

struct Student {
    string name;
    int    id = 0;
    double gpa = 0.0;
    Date   enrolled;        // a struct can contain another struct (nesting)
};

void printStudent(const Student& s)      // pass structs by const reference
{
    cout << s.name << " (#" << s.id << ") GPA " << s.gpa
         << ", enrolled " << s.enrolled.month << '/' << s.enrolled.day
         << '/' << s.enrolled.year << '\n';
}

void applyBonus(Student& s, double bonus) // non-const reference: modifies the caller's struct
{
    s.gpa += bonus;
    if (s.gpa > 4.0) s.gpa = 4.0;
}

int main()
{
    Student a;                                   // members get their defaults
    a.name = "Ada";
    a.id = 1001;
    a.gpa = 3.8;

    Student b{"Grace", 1002, 3.95, {8, 24, 2026}};  // aggregate initialization

    printStudent(a);
    applyBonus(b, 0.1);
    printStudent(b);

    // Pointer to a struct: use -> instead of (*p).
    Student* p = &a;
    p->gpa = 3.9;
    cout << "via pointer: " << p->name << " now " << a.gpa << '\n';
    return 0;
}
