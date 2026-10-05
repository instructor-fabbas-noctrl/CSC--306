// CSCE 306 | Week 5 • Example 08: Overloading [], ++ (prefix/postfix), and () (Ch. 14.5)
// Build: g++ -std=c++17 -Wall -Wextra 08_overloading_subscript_increment.cpp -o subscript

#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
private:
    static constexpr int CAP = 5;
    int data[CAP] = {};
public:
    // Two versions: non-const returns a reference (assignable), const returns a value
    int& operator[](int i)
    {
        if (i < 0 || i >= CAP) throw out_of_range("SafeArray index");
        return data[i];
    }
    int operator[](int i) const
    {
        if (i < 0 || i >= CAP) throw out_of_range("SafeArray index");
        return data[i];
    }
    int size() const { return CAP; }
};

class Counter {
private:
    int value = 0;
public:
    Counter& operator++()     { ++value; return *this; }                  // prefix  ++c
    Counter  operator++(int)  { Counter old = *this; ++value; return old; } // postfix c++ (dummy int)
    int operator()() const    { return value; }                           // function-call operator
};

int main()
{
    SafeArray a;
    a[2] = 42;                                  // uses int& operator[]
    cout << "a[2] = " << a[2] << '\n';
    try {
        a[9] = 1;
    } catch (const out_of_range& e) {
        cout << "caught: " << e.what() << '\n';  // exceptions in depth in Week 10
    }

    Counter c;
    Counter before = c++;
    ++c;
    cout << "before=" << before() << " now=" << c() << '\n';
    return 0;
}
