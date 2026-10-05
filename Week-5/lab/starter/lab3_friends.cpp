// CSCE 306 | Week 5 • Lab Part 3: Friend functions -- Thermometer readings (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab3_friends.cpp -o lab3
//
// Thermometer has PRIVATE data and NO getters (on purpose).
// 1) Declare and define a friend function
//        double difference(const Thermometer& a, const Thermometer& b)
//    returning a.celsius - b.celsius.
// 2) Declare  friend class Calibrator;  and finish Calibrator::adjust, which shifts
//    a thermometer's reading by an offset and records the label in its log.
// 3) Answer in a comment: why is a friend better here than adding public getters/setters?
//    Why might it be worse?

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Thermometer;   // forward declaration

class Calibrator {
private:
    vector<string> log;
public:
    void adjust(Thermometer& t, double offset);
    size_t adjustments() const { return log.size(); }
};

class Thermometer {
private:
    string label;
    double celsius;
public:
    Thermometer(const string& l, double c) : label(l), celsius(c) {}
    // TODO 1: friend declaration for difference
    // TODO 2: friend declaration for Calibrator
};

// TODO 3: define difference(...)

void Calibrator::adjust(Thermometer& t, double offset)
{
    // TODO 4: t.celsius += offset; log.push_back(t.label);
    (void)t; (void)offset;
}

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    Thermometer lab("Lab", 21.5), freezer("Freezer", -18.0);
    check("difference 39.5", difference(lab, freezer) == 39.5);
    Calibrator cal;
    cal.adjust(freezer, 0.5);
    cal.adjust(lab, -1.5);
    check("after calibration 37.5", difference(lab, freezer) == 37.5);
    check("2 adjustments logged", cal.adjustments() == 2);
    */
    return 0;
}
