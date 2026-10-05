// CSCE 306 | Week 1 • Example 07: const, constexpr, and auto
// Build: g++ -std=c++17 -Wall -Wextra 07_constants_and_auto.cpp -o consts

#include <iostream>
#include <string>
using namespace std;

constexpr double TAX_RATE = 0.0825;   // known at compile time
const int MAX_STUDENTS = 17;          // cannot be modified after initialization

int main()
{
    // MAX_STUDENTS = 20;   // ERROR: assignment of read-only variable

    auto price = 19.99;          // auto deduces double
    auto qty   = 3;              // auto deduces int
    auto label = string("Lab kit");  // std::string (a bare "..." would be const char*)

    auto subtotal = price * qty;
    auto tax      = subtotal * TAX_RATE;

    cout << label << " x" << qty << '\n';
    cout << "Subtotal: $" << subtotal << '\n';
    cout << "Tax:      $" << tax << '\n';
    cout << "Total:    $" << subtotal + tax << '\n';
    cout << "Seats available: " << MAX_STUDENTS << '\n';
    return 0;
}
