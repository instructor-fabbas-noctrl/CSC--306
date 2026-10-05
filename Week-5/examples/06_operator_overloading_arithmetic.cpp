// CSCE 306 | Week 5 • Example 06: Overloading arithmetic operators -- Money (Ch. 14.5)
// Build: g++ -std=c++17 -Wall -Wextra 06_operator_overloading_arithmetic.cpp -o money

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Money {
private:
    long cents;     // store in cents: no floating-point rounding errors
public:
    explicit Money(long c = 0) : cents(c) {}
    Money(long dollars, int c) : cents(dollars * 100 + c) {}

    // Member operators: left operand is *this
    Money operator+(const Money& rhs) const { return Money(cents + rhs.cents); }
    Money operator-(const Money& rhs) const { return Money(cents - rhs.cents); }
    Money operator*(int factor) const       { return Money(cents * factor); }
    Money operator-() const                 { return Money(-cents); }      // unary minus

    Money& operator+=(const Money& rhs)     { cents += rhs.cents; return *this; }

    long getCents() const { return cents; }
    void print() const
    {
        long a = labs(cents);
        cout << (cents < 0 ? "-$" : "$") << a / 100 << '.' << setfill('0') << setw(2) << a % 100 << setfill(' ');
    }
};

// Non-member: allows  int * Money  (left operand is not a Money)
Money operator*(int factor, const Money& m) { return m * factor; }

int main()
{
    Money lunch(12, 50), coffee(3, 75);
    Money total = lunch + coffee;           // lunch.operator+(coffee)
    total += Money(0, 99);
    Money week = 5 * lunch;                 // non-member operator*
    Money refund = -coffee;

    cout << "total:  "; total.print();  cout << '\n';
    cout << "week:   "; week.print();   cout << '\n';
    cout << "refund: "; refund.print(); cout << '\n';
    return 0;
}
