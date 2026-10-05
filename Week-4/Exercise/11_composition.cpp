// CSCE 306 | Week 4 • Example 11: Composition -- objects as members ("has-a") (Ch. 13.15 preview of 14)
// Build: g++ -std=c++17 -Wall -Wextra 10_composition.cpp -o compose

#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string street, city, state, zip;
public:
    Address(const string& st, const string& c, const string& s, const string& z)
        : street(st), city(c), state(s), zip(z) {}
    string toString() const { return street + ", " + city + ", " + state + " " + zip; }
};

class Student {
private:
    string  name;
    int     id;
    Address home;     // a Student HAS-AN Address; the Address lives inside the Student
public:
    // Member objects are built in the initializer list, BEFORE the ctor body runs.
    Student(const string& n, int i, const Address& a) : name(n), id(i), home(a) {}

    void print() const
    {
        cout << name << " (#" << id << ")\n  lives at " << home.toString() << '\n';
    }
};

int main()
{
    Address addr("30 N Brainard St", "Naperville", "IL", "60540");
    Student s("Ada Lovelace", 1001, addr);
    s.print();
    // In UML: Student ◆—— Address   (filled diamond = composition)
    return 0;
}
