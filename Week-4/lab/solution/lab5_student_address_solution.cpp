// CSCE 306 | Week 4 • Lab Part 5: Composition -- Student has an Address and a Date (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab5_student_address_solution.cpp -o lab5

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

class Date {
private:
    int month, day, year;
public:
    Date(int m, int d, int y) : month(1), day(1), year(2026)
    {
        if (m >= 1 && m <= 12 && d >= 1 && d <= 31) {
            month = m; day = d; year = y;
        }
    }
    string toString() const
    {
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }
};

class Student {
private:
    string  name;
    int     id;
    Address home;
    Date    enrolled;
public:
    // Address and Date have no default constructors, so they MUST be built
    // in the initializer list -- assigning in the body would not compile.
    Student(const string& n, int i, const Address& h, const Date& e)
        : name(n), id(i), home(h), enrolled(e) {}

    void moveTo(const Address& newHome) { home = newHome; }

    void print() const
    {
        cout << name << " (#" << id << "), enrolled " << enrolled.toString() << '\n'
             << "  Home: " << home.toString() << '\n';
    }
};

int main()
{
    Student ada("Ada Lovelace", 1001,
                Address("30 N Brainard St", "Naperville", "IL", "60540"),
                Date(8, 24, 2026));
    Student grace("Grace Hopper", 1002,
                  Address("1 Main St", "Geneva", "IL", "60134"),
                  Date(13, 40, 2026));
    ada.print();
    grace.print();
    cout << "-- after move --\n";
    grace.moveTo(Address("450 S Washington St", "Naperville", "IL", "60540"));
    grace.print();
    return 0;
}
