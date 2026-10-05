// CSCE 306 | Week 5 • Lab Part 5: Operator overloading -- Fraction (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab5_fraction_operators_solution.cpp -o lab5

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
        if (den == 0) den = 1;
        if (den < 0) { num = -num; den = -den; }
        long g = gcd(num, den);          // std::gcd handles negatives; gcd(0, d) == d
        if (g != 0) { num /= g; den /= g; }
    }
public:
    Fraction(long n = 0, long d = 1) : num(n), den(d) { normalize(); }
    long numerator() const   { return num; }
    long denominator() const { return den; }

    Fraction operator+(const Fraction& r) const { return Fraction(num * r.den + r.num * den, den * r.den); }
    Fraction operator-(const Fraction& r) const { return Fraction(num * r.den - r.num * den, den * r.den); }
    Fraction operator*(const Fraction& r) const { return Fraction(num * r.num, den * r.den); }
    Fraction operator/(const Fraction& r) const { return Fraction(num * r.den, den * r.num); }

    // Because every Fraction is normalized, equal values have identical members.
    bool operator==(const Fraction& r) const { return num == r.num && den == r.den; }
    bool operator<(const Fraction& r) const  { return num * r.den < r.num * den; }   // dens > 0

    Fraction& operator+=(const Fraction& r) { *this = *this + r; return *this; }

    friend ostream& operator<<(ostream& out, const Fraction& f)
    {
        out << f.num;
        if (f.den != 1) out << '/' << f.den;
        return out;
    }

    explicit operator double() const { return static_cast<double>(num) / den; }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }
string str(const Fraction& f) { ostringstream o; o << f; return o.str(); }

int main()
{
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
    return 0;
}
