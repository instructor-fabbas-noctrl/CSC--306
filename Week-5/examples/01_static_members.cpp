// CSCE 306 — Object-Oriented Software Development | Fall 2026
// Week 5 • Example 01: Static member variables and functions (Ch. 14.1)
// Build: g++ -std=c++17 -Wall -Wextra 01_static_members.cpp -o static

#include <iostream>
#include <string>
using namespace std;

class Ticket {
private:
    static int nextNumber;      // ONE copy shared by all Ticket objects
    static int liveCount;
    int    number;              // each object has its own copy
    string holder;

public:
    explicit Ticket(const string& who) : number(nextNumber++), holder(who) { ++liveCount; }
    ~Ticket() { --liveCount; }

    int getNumber() const { return number; }

    // A static member function has NO 'this' pointer:
    // it can touch only static members, and is called on the class itself.
    static int getLiveCount() { return liveCount; }

    // C++17 alternative for constants:  inline static / static constexpr in-class
    static constexpr int MAX_TICKETS = 500;
};

// Non-inline static data members must be DEFINED exactly once, outside the class.
int Ticket::nextNumber = 1000;
int Ticket::liveCount  = 0;

int main()
{
    cout << "Live tickets: " << Ticket::getLiveCount() << '\n';
    Ticket a("Ada"), b("Grace");
    {
        Ticket c("Alan");
        cout << "c is #" << c.getNumber() << ", live = " << Ticket::getLiveCount() << '\n';
    }
    cout << "a=#" << a.getNumber() << " b=#" << b.getNumber()
         << ", live = " << Ticket::getLiveCount()
         << " (max " << Ticket::MAX_TICKETS << ")\n";
    return 0;
}
