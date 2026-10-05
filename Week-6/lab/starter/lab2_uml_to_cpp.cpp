// CSCE 306 | Week 6 • Lab Part 2: Implement a UML class diagram exactly (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab2_uml_to_cpp.cpp -o lab2
//
//   +--------------------------------------------------+
//   | Thermostat                                       |
//   +--------------------------------------------------+
//   | - location : string                              |
//   | - currentF : double = 68.0                       |
//   | - targetF : double = 68.0                        |
//   | - _MIN_F : double = 50.0_   {readOnly}           |   underlined = static
//   | - _MAX_F : double = 90.0_   {readOnly}           |   {readOnly} = constexpr/const
//   | - _units : int = 0_                              |
//   +--------------------------------------------------+
//   | + Thermostat(location : string)                  |
//   | + ~Thermostat()                                  |
//   | + setTarget(f : double) : bool                   |   false if outside MIN..MAX
//   | + tick() : void                                  |   move currentF 1.0 toward targetF
//   | + isHeating() : bool {query}                     |   currentF < targetF
//   | + getCurrent() : double {query}                  |
//   | + getLocation() : string {query}                 |
//   | + _unitCount() : int_                            |   number of live Thermostats
//   | - clamp(f : double) : double {query}             |   private helper used by tick()
//   +--------------------------------------------------+
//
// RULES: match every name, type, visibility, const-ness, and static-ness in the diagram.
// tick(): if |target - current| <= 1.0, current = target; otherwise step by 1.0 toward target.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// TODO: class Thermostat

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    check("0 units at start", Thermostat::unitCount() == 0);
    Thermostat t("Lab");
    {
        Thermostat u("Office");
        check("2 units", Thermostat::unitCount() == 2);
    }
    check("1 unit after scope", Thermostat::unitCount() == 1);
    check("reject 95",  !t.setTarget(95));
    check("accept 70.5", t.setTarget(70.5));
    check("heating",     t.isHeating());
    t.tick(); t.tick();
    check("current 70.0", t.getCurrent() == 70.0);
    t.tick();
    check("reaches 70.5, not heating", t.getCurrent() == 70.5 && !t.isHeating());
    t.setTarget(68);
    t.tick();
    check("cools to 69.5", t.getCurrent() == 69.5);
    */
    return 0;
}
