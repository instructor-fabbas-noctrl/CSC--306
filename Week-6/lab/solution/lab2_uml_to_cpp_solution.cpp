// CSCE 306 | Week 6 • Lab Part 2: Implement a UML class diagram exactly (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab2_uml_to_cpp_solution.cpp -o lab2

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Thermostat {
private:
    string location;
    double currentF = 68.0;
    double targetF  = 68.0;
    static constexpr double MIN_F = 50.0;     // underlined + {readOnly}
    static constexpr double MAX_F = 90.0;
    static int units;                         // underlined (static)

    double clamp(double f) const              // private helper, {query}
    {
        if (f < MIN_F) return MIN_F;
        if (f > MAX_F) return MAX_F;
        return f;
    }

public:
    explicit Thermostat(const string& location) : location(location) { ++units; }
    ~Thermostat() { --units; }

    bool setTarget(double f)
    {
        if (f < MIN_F || f > MAX_F) return false;
        targetF = f;
        return true;
    }

    void tick()
    {
        double diff = targetF - currentF;
        if (fabs(diff) <= 1.0) currentF = targetF;
        else                   currentF = clamp(currentF + (diff > 0 ? 1.0 : -1.0));
    }

    bool   isHeating() const   { return currentF < targetF; }
    double getCurrent() const  { return currentF; }
    string getLocation() const { return location; }
    static int unitCount()     { return units; }
};

int Thermostat::units = 0;

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
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
    return 0;
}
