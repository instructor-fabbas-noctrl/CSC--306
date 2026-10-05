// CSCE 306 | Week 4 • Vector Lab 1: std::vector basics -- Temperature Log (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra vlab1_vector_basics.cpp -o vlab1
//
// Practice the core std::vector operations: push_back, size, empty, at / [],
// front / back, pop_back, insert, erase, clear, and range-based for loops.
// Implement each function below. Do not change main(); it prints PASS/FAIL per check.
//
// RULES:  * pass vectors you only READ by const reference   (const vector<double>&)
//         * pass vectors you MODIFY by reference              (vector<double>&)
//         * use size_t (or a range-for) for indices -- never compare int with size()

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Returns a vector holding count copies of value, built with push_back in a loop.
vector<double> filled(int count, double value)
{
    // TODO
    (void)count; (void)value; return {};
}

// Average of all readings; 0.0 for an empty vector.
double average(const vector<double>& temps)
{
    // TODO: use a range-based for loop
    (void)temps; return 0.0;
}

// Largest reading. Precondition: temps is not empty.
double highest(const vector<double>& temps)
{
    // TODO: start from temps.front()
    (void)temps; return 0.0;
}

// How many readings are strictly above the threshold.
int countAbove(const vector<double>& temps, double threshold)
{
    // TODO
    (void)temps; (void)threshold; return 0;
}

// Converts every reading from Fahrenheit to Celsius IN PLACE:  C = (F - 32) * 5 / 9
// Hint: a range-for needs a reference (double&) to change the elements.
void toCelsius(vector<double>& temps)
{
    // TODO
    (void)temps;
}

// Removes the LAST reading if there is one; returns false when the vector is empty.
bool undoLast(vector<double>& temps)
{
    // TODO: pop_back on an empty vector is undefined behavior -- check first
    (void)temps; return false;
}

// Inserts value at position index (0 = front). An index past the end appends.
void insertAt(vector<double>& temps, size_t index, double value)
{
    // TODO: use temps.insert(temps.begin() + index, value)
    (void)temps; (void)index; (void)value;
}

// Removes the element at index; returns false if index is out of range.
bool removeAt(vector<double>& temps, size_t index)
{
    // TODO: use temps.erase(temps.begin() + index)
    (void)temps; (void)index; return false;
}

// Returns the readings as text, e.g. "[50, 75, 91]". Readings in this lab are whole numbers,
// so print each one as an int.
string toText(const vector<double>& temps)
{
    // TODO: build the string with += and to_string(static_cast<int>(value))
    (void)temps; return "";
}

// ----------------------------- test driver (do not change) -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }
bool near(double a, double b) { return (a > b ? a - b : b - a) < 1e-9; }

int main()
{
    vector<double> f = filled(3, 70.0);
    check("filled: size 3, all 70",        f.size() == 3 && f[0] == 70.0 && f.back() == 70.0);
    check("filled(0): empty",              filled(0, 1.0).empty());

    vector<double> week = {68, 75, 91, 84, 59, 77, 93};
    check("average of week == 78.142857",  near(average(week), 547.0 / 7));
    check("average of empty == 0",         average({}) == 0.0);
    check("highest == 93",                 highest(week) == 93);
    check("countAbove(80) == 3",           countAbove(week, 80) == 3);

    week.push_back(100);
    check("push_back -> size 8",           week.size() == 8 && week.back() == 100);
    check("undoLast -> size 7",            undoLast(week) && week.size() == 7);
    vector<double> none;
    check("undoLast on empty is false",    !undoLast(none));

    insertAt(week, 0, 50);
    check("insertAt front",                week.front() == 50 && week.size() == 8);
    insertAt(week, 999, 60);
    check("insertAt past end appends",     week.back() == 60);
    check("removeAt(1) removes 68",        removeAt(week, 1) && week[1] == 75);
    check("removeAt(99) is false",         !removeAt(week, 99));
    check("toText",                        toText(week) == "[50, 75, 91, 84, 59, 77, 93, 60]");

    vector<double> f2 = {32, 212, -40};
    toCelsius(f2);
    check("toCelsius 32/212/-40 -> 0/100/-40", near(f2[0], 0) && near(f2[1], 100) && near(f2[2], -40));

    try {
        week.at(100);                       // .at() is bounds-checked; [] is not
        check("at(100) throws", false);
    } catch (const out_of_range&) {
        check("at(100) throws out_of_range", true);
    }
    return 0;
}
