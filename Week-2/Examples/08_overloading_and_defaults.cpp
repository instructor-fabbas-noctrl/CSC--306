// CSCE 306 | Week 2 • Example 08: Function overloading and default arguments (Ch. 6)
// Build: g++ -std=c++17 -Wall -Wextra 08_overloading_and_defaults.cpp -o overload

#include <iostream>
#include <string>
using namespace std;

// Overloads: same name, different parameter lists. The compiler picks by argument types.
int    maxOf(int a, int b)          { return a > b ? a : b; }
double maxOf(double a, double b)    { return a > b ? a : b; }
int    maxOf(int a, int b, int c)   { return maxOf(maxOf(a, b), c); }

// Default arguments: must be the trailing parameters.
void greet(const string& name, const string& greeting = "Hello", int times = 1)
{
    for (int i = 0; i < times; ++i)
        cout << greeting << ", " << name << "!\n";
}

int main()
{
    cout << maxOf(3, 9)        << '\n';   // int version
    cout << maxOf(2.5, 1.5)    << '\n';   // double version
    cout << maxOf(4, 11, 7)    << '\n';   // three-arg version

    greet("Grace");                       // uses both defaults
    greet("Linus", "Welcome");            // uses default times
    greet("Bjarne", "Hi", 2);
    return 0;
}
