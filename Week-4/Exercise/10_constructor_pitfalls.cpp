// CSCE 306 | Week 4 • Example 10: Constructor pitfalls -- default ctor, explicit, init order
// Build: g++ -std=c++17 -Wall -Wextra 10_constructor_pitfalls.cpp -o pitfalls

#include <iostream>
#include <string>
using namespace std;

class Temperature {
private:
    double kelvin;
public:
    // explicit blocks silent conversions like  Temperature t = 300.0;
    explicit Temperature(double k) : kelvin(k < 0 ? 0 : k) {}
    double get() const { return kelvin; }
};

void report(const Temperature& t) { cout << "Temperature: " << t.get() << " K\n"; }

class Span {
private:
    // Members are initialized in DECLARATION order, not initializer-list order.
    int first;
    int second;
public:
    // If this list were written  : second(v), first(second + 1)  -- first would read an
    // uninitialized 'second'. -Wall warns with -Wreorder. Keep the list in declaration order.
    explicit Span(int v) : first(v), second(first + 1) {}
    void print() const { cout << "first=" << first << " second=" << second << '\n'; }
};

class NoDefault {
public:
    explicit NoDefault(int) {}
    // Once you write ANY constructor, the compiler no longer generates a default one.
    // Add  NoDefault() = default;  if you want it back.
};

int main()
{
    report(Temperature(300.0));
    // report(300.0);          // ERROR because the constructor is explicit -- good!

    Span s(10);
    s.print();

    NoDefault ok(5);
    (void)ok;
    // NoDefault bad;          // ERROR: no default constructor
    return 0;
}
