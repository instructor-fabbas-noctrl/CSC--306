// CSCE 306 | Week 4 • Example 07: Private member functions (helpers) (Ch. 13.10)
// Build: g++ -std=c++17 -Wall -Wextra 07_private_member_functions.cpp -o helpers

#include <iostream>
#include <iomanip>
using namespace std;

class Clock {
private:
    int hours = 0, minutes = 0;

    // Helper used by several public members; not part of the interface.
    void normalize()
    {
        hours  += minutes / 60;
        minutes = minutes % 60;
        if (minutes < 0) { minutes += 60; --hours; }
        hours = ((hours % 24) + 24) % 24;
    }

public:
    Clock(int h, int m) : hours(h), minutes(m) { normalize(); }

    void addMinutes(int m) { minutes += m; normalize(); }
    void addHours(int h)   { hours += h;   normalize(); }

    void print() const
    {
        cout << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes
             << setfill(' ') << '\n';
    }
};

int main()
{
    Clock c(23, 30);
    c.print();              // 23:30
    c.addMinutes(45);
    c.print();              // 00:15
    c.addMinutes(-30);
    c.print();              // 23:45
    Clock odd(5, 125);      // constructor normalizes too
    odd.print();            // 07:05
    // c.normalize();       // ERROR: private
    return 0;
}
