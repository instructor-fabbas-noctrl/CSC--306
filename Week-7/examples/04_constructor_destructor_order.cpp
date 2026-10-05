// CSCE 306 | Week 7 • Example 04: Constructor and destructor order in hierarchies (Ch. 15.3)
// Build: g++ -std=c++17 -Wall -Wextra 04_constructor_destructor_order.cpp -o order

#include <iostream>
using namespace std;

class Part {
public:
    Part()  { cout << "  Part ctor (member of Derived)\n"; }
    ~Part() { cout << "  Part dtor\n"; }
};

class Base {
public:
    Base()  { cout << "  Base ctor\n"; }
    ~Base() { cout << "  Base dtor\n"; }
};

class Derived : public Base {
    Part part;
public:
    Derived()  { cout << "  Derived ctor body\n"; }
    ~Derived() { cout << "  Derived dtor body\n"; }
};

int main()
{
    cout << "Creating:\n";
    {
        Derived d;
        cout << "Destroying:\n";
    }
    // Construction: BASE first, then members (in declaration order), then the derived body.
    // Destruction:  exactly the REVERSE -- derived body, members, then base.
    // Intuition: a derived object is built "on top of" a finished base object.
    return 0;
}
