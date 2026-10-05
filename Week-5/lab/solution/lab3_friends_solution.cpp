// CSCE 306 | Week 5 • Lab Part 3: Friend functions -- Thermometer readings (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab3_friends_solution.cpp -o lab3

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Thermometer;

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
    friend double difference(const Thermometer& a, const Thermometer& b);
    friend class Calibrator;
};

double difference(const Thermometer& a, const Thermometer& b)
{
    return a.celsius - b.celsius;
}

void Calibrator::adjust(Thermometer& t, double offset)
{
    t.celsius += offset;
    log.push_back(t.label);
}

// Q3: A friend grants access to exactly ONE trusted function/class, while public
// getters/setters would let ANY code read and change the reading. The downside:
// friends couple tightly to private representation -- if Thermometer switches to
// storing Fahrenheit, every friend must change too.

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Thermometer lab("Lab", 21.5), freezer("Freezer", -18.0);
    check("difference 39.5", difference(lab, freezer) == 39.5);
    Calibrator cal;
    cal.adjust(freezer, 0.5);
    cal.adjust(lab, -1.5);
    check("after calibration 37.5", difference(lab, freezer) == 37.5);
    check("2 adjustments logged", cal.adjustments() == 2);
    return 0;
}
