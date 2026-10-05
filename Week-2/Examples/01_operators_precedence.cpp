// CSCE 306 — Object-Oriented Software Development | Fall 2026
// Week 2 • Example 01: Operators and precedence (Ch. 3)
// Build: g++ -std=c++17 -Wall -Wextra 01_operators_precedence.cpp -o ops

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // * / % bind tighter than + -  ; parentheses always win
    cout << "2 + 3 * 4     = " << 2 + 3 * 4   << '\n';   // 14
    cout << "(2 + 3) * 4   = " << (2 + 3) * 4 << '\n';   // 20
    cout << "10 - 4 - 3    = " << 10 - 4 - 3  << "  (left-to-right)\n";

    // Relational and logical operators produce bool
    int age = 20; bool hasId = true;
    cout << boolalpha;
    cout << "age >= 18 && hasId : " << (age >= 18 && hasId) << '\n';
    cout << "!(age < 21)        : " << !(age < 21) << '\n';

    // <cmath> functions
    cout << "pow(2, 10)   = " << pow(2, 10)   << '\n';
    cout << "sqrt(144.0)  = " << sqrt(144.0)  << '\n';
    cout << "round(2.5)   = " << round(2.5)   << '\n';

    // Pre vs post increment
    int n = 5;
    int a = n++;   // a gets 5, then n becomes 6
    int b = ++n;   // n becomes 7, then b gets 7
    cout << "a=" << a << " b=" << b << " n=" << n << '\n';
    return 0;
}
