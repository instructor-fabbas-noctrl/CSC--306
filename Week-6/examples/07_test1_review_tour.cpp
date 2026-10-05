// CSCE 306 | Week 6 • Example 07: Test 1 review -- one program, Weeks 1-6 in one place
// Build: g++ -std=c++17 -Wall -Wextra 07_test1_review_tour.cpp -o review
//
// Each numbered comment marks a concept that is fair game on Test 1.
// Before running, PREDICT the output line by line. Then check yourself.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Gadget {
private:
    string name;                       // (1) encapsulation: private data
    int*   readings;                   // (2) owns dynamic memory
    int    count;
    static int alive;                  // (3) static data member

public:
    Gadget(const string& n, int c)     // (4) constructor + initializer list
        : name(n), readings(new int[c]{}), count(c) { ++alive; cout << "+" << name << ' '; }

    Gadget(const Gadget& o)            // (5) copy constructor (deep copy)
        : name(o.name + "'"), readings(new int[o.count]), count(o.count)
    {
        for (int i = 0; i < count; ++i) readings[i] = o.readings[i];
        ++alive; cout << "+" << name << ' ';
    }

    Gadget& operator=(const Gadget&) = delete;   // (6) explicitly forbid assignment

    ~Gadget() { delete[] readings; --alive; cout << "-" << name << ' '; }   // (7) destructor

    Gadget& set(int i, int v) { if (i >= 0 && i < count) readings[i] = v; return *this; } // (8) this
    int sum() const                    // (9) const member function
    {
        int s = 0;
        for (int i = 0; i < count; ++i) s += readings[i];
        return s;
    }
    bool operator<(const Gadget& o) const { return sum() < o.sum(); }   // (10) operator overload
    friend ostream& operator<<(ostream& out, const Gadget& g)           // (11) friend <<
    {
        return out << g.name << "=" << g.sum();
    }
    static int alive_count() { return alive; }                          // (12) static function
};
int Gadget::alive = 0;

void show(Gadget g) { cout << "[show " << g << "] "; }   // (13) pass BY VALUE -> copy ctor runs

int main()
{
    Gadget a("A", 3);
    a.set(0, 5).set(2, 7);                         // chaining
    {
        Gadget b = a;                              // copy ctor
        b.set(1, 10);
        cout << "\n" << a << " " << b << " less? " << (a < b) << '\n';
        show(a);
        cout << "\nalive=" << Gadget::alive_count() << '\n';
    }                                              // b destroyed here
    cout << "\nalive=" << Gadget::alive_count() << '\n';
    return 0;
}
