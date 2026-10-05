// CSCE 306 | Week 4 • Lab Part 3: Private helper functions -- Duration (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab3_private_helper_solution.cpp -o lab3

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Duration {
private:
    int hours = 0, minutes = 0, seconds = 0;
    void normalize();

public:
    Duration(int h = 0, int m = 0, int s = 0);
    void   addSeconds(int s) { seconds += s; normalize(); }
    void   addMinutes(int m) { minutes += m; normalize(); }
    void   addHours(int h)   { hours   += h; normalize(); }
    int    totalSeconds() const { return hours * 3600 + minutes * 60 + seconds; }
    string toString() const;
};

Duration::Duration(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
    normalize();
}

// Single source of truth for the invariant: collapse to seconds, then rebuild.
void Duration::normalize()
{
    int total = hours * 3600 + minutes * 60 + seconds;
    if (total < 0) total = 0;
    hours   = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
}

string Duration::toString() const
{
    ostringstream out;
    out << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes << ':' << setw(2) << seconds;
    return out.str();
}

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Duration d(1, 75, 130);
    check("ctor normalizes 02:17:10",  d.toString() == "02:17:10");
    d.addSeconds(3000);
    check("addSeconds -> 03:07:10",    d.toString() == "03:07:10");
    d.addMinutes(-10);
    check("addMinutes(-10) 02:57:10",  d.toString() == "02:57:10");
    check("totalSeconds 10630",        d.totalSeconds() == 10630);
    d.addHours(-5);
    check("clamped to 00:00:00",       d.toString() == "00:00:00");
    return 0;
}
