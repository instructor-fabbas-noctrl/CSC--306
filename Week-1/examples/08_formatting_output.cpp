// CSCE 306 | Week 1 • Example 08: Formatting output with <iomanip>
// Build: g++ -std=c++17 -Wall -Wextra 08_formatting_output.cpp -o fmt

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);     // 2 decimal places from here on (sticky)

    cout << left  << setw(14) << "Item"
         << right << setw(8)  << "Qty"
         << setw(10) << "Price" << '\n';
    cout << string(32, '-') << '\n';

    cout << left  << setw(14) << "Notebook" << right << setw(8) << 3 << setw(10) << 4.5   << '\n';
    cout << left  << setw(14) << "USB drive" << right << setw(8) << 1 << setw(10) << 12.0 << '\n';
    cout << left  << setw(14) << "Coffee"   << right << setw(8) << 12 << setw(10) << 2.25 << '\n';

    // setw is NOT sticky -- it applies only to the next item
    cout << '\n' << setfill('*') << setw(10) << 42 << setfill(' ') << '\n';
    return 0;
}
