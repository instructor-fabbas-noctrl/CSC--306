// CSCE 306 | Week 1 • Example 06: Arithmetic, integer division, and static_cast
// Build: g++ -std=c++17 -Wall -Wextra 06_arithmetic_and_casts.cpp -o arith

#include <iostream>
using namespace std;

int main()
{
    int total = 17, groups = 5;

    cout << "17 / 5   = " << total / groups << "   (integer division truncates)\n";
    cout << "17 % 5   = " << total % groups << "   (remainder)\n";

    // Promote ONE operand to double to get real division
    double avg = static_cast<double>(total) / groups;
    cout << "17.0 / 5 = " << avg << '\n';

    // A classic bug: the cast happens AFTER integer division
    double wrong = static_cast<double>(total / groups);
    cout << "static_cast<double>(17 / 5) = " << wrong << "  <- still 3!\n";

    // Compound assignment and increment
    int x = 10;
    x += 5;   // 15
    x *= 2;   // 30
    x--;      // 29
    cout << "x after += 5, *= 2, -- : " << x << '\n';
    return 0;
}
