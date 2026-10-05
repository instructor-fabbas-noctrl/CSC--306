// CSCE 306 | Week 2 • Example 06: Functions -- prototypes, parameters, return values (Ch. 6)
// Build: g++ -std=c++17 -Wall -Wextra 06_functions_basics.cpp -o funcs

#include <iostream>
using namespace std;

// Prototypes (declarations) let main() call functions defined later.
double circleArea(double radius);
bool   isEven(int n);
void   printBanner(const char* title);   // void = returns nothing

int main()
{
    printBanner("Function demo");
    cout << "Area r=2.0: " << circleArea(2.0) << '\n';
    for (int n = 3; n <= 6; ++n)
        cout << n << (isEven(n) ? " is even\n" : " is odd\n");
    return 0;
}

// Definitions
double circleArea(double radius)
{
    constexpr double PI = 3.14159265358979;
    return PI * radius * radius;
}

bool isEven(int n)
{
    return n % 2 == 0;
}

void printBanner(const char* title)
{
    cout << "==== " << title << " ====\n";
}
