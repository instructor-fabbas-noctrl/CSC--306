// CSCE 306 | Week 1 • Example 04: How big is each type? (sizeof and numeric_limits)
// Build: g++ -std=c++17 -Wall -Wextra 04_sizeof_and_limits.cpp -o limits

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    // sizeof reports bytes. Exact sizes are platform-dependent (only minimums are guaranteed).
    cout << "char:        " << sizeof(char)        << " byte(s)\n";
    cout << "short:       " << sizeof(short)       << " byte(s)\n";
    cout << "int:         " << sizeof(int)         << " byte(s)\n";
    cout << "long long:   " << sizeof(long long)   << " byte(s)\n";
    cout << "float:       " << sizeof(float)       << " byte(s)\n";
    cout << "double:      " << sizeof(double)      << " byte(s)\n";
    cout << "bool:        " << sizeof(bool)        << " byte(s)\n\n";

    cout << "int range:   " << numeric_limits<int>::min() << " .. "
         << numeric_limits<int>::max() << '\n';
    cout << "double max:  " << numeric_limits<double>::max() << '\n';

    // Overflow demo: unsigned arithmetic wraps around (well-defined);
    // signed overflow is UNDEFINED behavior -- never rely on it.
    unsigned int u = 0;
    u = u - 1;
    cout << "unsigned 0 - 1 = " << u << "  (wraps to max)\n";
    return 0;
}
