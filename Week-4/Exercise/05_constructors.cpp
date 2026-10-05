// CSCE 306 | Week 4 • Example 05: Constructors (Ch. 13.6–13.8)
// Build: g++ -std=c++17 -Wall -Wextra 05_constructors.cpp -o ctors

#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
private:
    string description;
    double cost;
    int    units;

public:
    // Default constructor: runs when no arguments are given
    InventoryItem() : description("(none)"), cost(0.0), units(0)
    {
        cout << "  [default ctor]\n";
    }

    // Overloaded constructor with a MEMBER INITIALIZER LIST (preferred over assignment in body)
    InventoryItem(const string& desc, double c, int u)
        : description(desc), cost(c >= 0 ? c : 0), units(u >= 0 ? u : 0)
    {
        cout << "  [3-arg ctor] " << description << '\n';
    }

    // Constructor with a default argument -- covers 1- and 2-argument calls
    explicit InventoryItem(const string& desc, double c = 0.0)
        : InventoryItem(desc, c, 0)          // DELEGATING constructor (C++11)
    {
        cout << "  [desc ctor]  delegated\n";
    }

    void print() const
    {
        cout << description << ": $" << cost << " x " << units << '\n';
    }
};

int main()
{
    cout << "a:\n"; InventoryItem a;                     // default
    cout << "b:\n"; InventoryItem b("Hammer", 6.95, 12);  // 3-arg
    cout << "c:\n"; InventoryItem c("Wrench");            // desc ctor (cost defaults)
    cout << "d:\n"; InventoryItem d{"Pliers", 4.50, 7};   // brace init calls a ctor too

    // Pitfall: "most vexing parse" -- this declares a FUNCTION, not an object:
    // InventoryItem e();
    a.print(); b.print(); c.print(); d.print();
    return 0;
}
