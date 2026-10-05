// CSCE 306 | Week 5 • Lab Part 5: Operator overloading -- Fraction (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab5_fraction_operators.cpp -o lab5
//
// INVARIANTS (enforce in a private normalize() called by the constructor):
//   * always in lowest terms          (use std::gcd from <numeric>)
//   * denominator is always positive  (move the sign to the numerator)
//   * a zero denominator is replaced by 1
//
// Overload:  + - * /  (members, const)      == <  (members, const)
//            +=        (member, returns *this)
//            <<        (friend non-member, prints "n/d", or just "n" when d == 1)
//            explicit operator double() const

#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
using namespace std;

class Fraction {
private:
    long num, den;
    void normalize()
    {
        // TODO 1
    }
public:
    Fraction(long n = 0, long d = 1) : num(n), den(d) { normalize(); }
    long numerator() const   { return num; }
    long denominator() const { return den; }

    // TODO 2: arithmetic operators
    // TODO 3: comparison operators
    // TODO 4: operator+=
    // TODO 5: friend operator<<
    // TODO 6: explicit operator double
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }
// Helper (uncomment with main): renders a Fraction via your operator<<
// string str(const Fraction& f) { ostringstream o; o << f; return o.str(); }

int main()
{
    /*  Uncomment when ready
    Fraction half(1, 2), third(1, 3);
    check("normalize 6/-8 -> -3/4",  str(Fraction(6, -8)) == "-3/4");
    check("zero denom -> 5",         str(Fraction(5, 0)) == "5");
    check("1/2 + 1/3 = 5/6",         str(half + third) == "5/6");
    check("1/2 - 1/3 = 1/6",         str(half - third) == "1/6");
    check("1/2 * 1/3 = 1/6",         str(half * third) == "1/6");
    check("1/2 / 1/3 = 3/2",         str(half / third) == "3/2");
    check("2/4 == 1/2",              Fraction(2, 4) == half);
    check("1/3 < 1/2",               third < half);
    Fraction acc;
    for (int i = 0; i < 4; ++i) acc += Fraction(1, 4);
    check("4 x 1/4 = 1",             str(acc) == "1");
    check("double(3/4) = 0.75",      static_cast<double>(Fraction(3, 4)) == 0.75);
    */
    return 0;
}
