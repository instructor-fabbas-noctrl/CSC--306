// CSCE 306 | Week 5 • Example 09: Object conversion -- converting ctors and conversion operators (Ch. 14.6)
// Build: g++ -std=c++17 -Wall -Wextra 09_conversion_operators.cpp -o convert

#include <iostream>
using namespace std;

class Percent {
private:
    double value;    // 0..100
public:
    // Converting constructor: double -> Percent. 'explicit' prevents surprise conversions.
    explicit Percent(double v) : value(v < 0 ? 0 : (v > 100 ? 100 : v)) {}

    // Conversion operator: Percent -> double. explicit requires static_cast.
    explicit operator double() const { return value / 100.0; }

    // Conversion to bool (explicit still works in if-conditions)
    explicit operator bool() const { return value > 0; }

    double get() const { return value; }
};

int main()
{
    Percent tax(8.25);
    double price = 200.0;
    double fraction = static_cast<double>(tax);   // explicit conversion
    cout << "tax on $200 = $" << price * fraction << '\n';

    Percent none(0);
    if (!none) cout << "no discount\n";             // explicit operator bool allowed here
    if (tax)   cout << "tax applies (" << tax.get() << "%)\n";

    // Percent p = 5.0;      // ERROR: constructor is explicit
    // double d = tax;       // ERROR: conversion operator is explicit
    return 0;
}
