// CSCE 306 | Week 2 • Example 09: Scope, lifetime, and static local variables (Ch. 6)
// Build: g++ -std=c++17 -Wall -Wextra 09_scope_and_static_locals.cpp -o scope

#include <iostream>
using namespace std;

int globalCounter = 0;   // global: visible everywhere below (use sparingly!)

int nextTicket()
{
    static int ticket = 100;   // initialized ONCE; keeps its value between calls
    return ticket++;
}

int main()
{
    int x = 1;
    {
        int x = 2;   // shadows the outer x inside this block
        cout << "inner x = " << x << '\n';
    }
    cout << "outer x = " << x << '\n';

    for (int i = 0; i < 3; ++i) {
        ++globalCounter;
        cout << "ticket " << nextTicket() << '\n';
    }
    // cout << i;   // ERROR: i only exists inside the for loop
    cout << "globalCounter = " << globalCounter << '\n';
    return 0;
}
