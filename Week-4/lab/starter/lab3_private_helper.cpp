// CSCE 306 | Week 4 • Lab Part 3: Private helper functions -- Duration (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab3_private_helper.cpp -o lab3
//
// A Duration stores hours, minutes, seconds. INVARIANT: 0 <= minutes < 60 and
// 0 <= seconds < 60 and hours >= 0 at all times.
//
// Instead of repeating the carry logic in every function, write ONE private
// helper  void normalize()  and call it from the constructor and every mutator.
// Any total that would go negative is clamped to 00:00:00.
//
// Public interface:
//   Duration(int h = 0, int m = 0, int s = 0)
//   void addSeconds(int s);  void addMinutes(int m);  void addHours(int h);
//   int  totalSeconds() const;
//   string toString() const;      // "HH:MM:SS" zero-padded (hours may exceed 99)

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Duration {
private:
    int hours = 0, minutes = 0, seconds = 0;
    // TODO 1: void normalize();

public:
    // TODO 2: constructor and public members
};

// TODO 3: definitions

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    Duration d(1, 75, 130);
    check("ctor normalizes 02:17:10",  d.toString() == "02:17:10");
    d.addSeconds(3000);
    check("addSeconds -> 03:07:10",    d.toString() == "03:07:10");
    d.addMinutes(-10);
    check("addMinutes(-10) 02:57:10",  d.toString() == "02:57:10");
    check("totalSeconds 10630",        d.totalSeconds() == 10630);
    d.addHours(-5);
    check("clamped to 00:00:00",       d.toString() == "00:00:00");
    */
    return 0;
}
