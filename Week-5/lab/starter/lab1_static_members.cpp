// CSCE 306 | Week 5 • Lab Part 1: Static members -- Order IDs and a running total (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab1_static_members.cpp -o lab1
//
// Every Order gets a unique id from a shared counter starting at 5001.
// The class also tracks, across ALL orders ever created:
//   * how many orders currently exist (decrement in the destructor)
//   * the grand total revenue of every order ever created (never decremented)
// Provide static accessors  activeOrders()  and  totalRevenue().

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Order {
private:
    // TODO 1: static int nextId; static int active; static double revenue;
    int    id;
    double amount;

public:
    explicit Order(double amt) : id(0), amount(amt)
    {
        // TODO 2: assign id from nextId (then advance it), update active and revenue
    }
    ~Order()
    {
        // TODO 3
    }
    int    getId() const     { return id; }
    double getAmount() const { return amount; }

    // TODO 4: static int activeOrders();  static double totalRevenue();
};

// TODO 5: define (initialize) the static data members here

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    check("starts with 0 active",        Order::activeOrders() == 0);
    Order a(20.0), b(15.5);
    check("ids 5001, 5002",              a.getId() == 5001 && b.getId() == 5002);
    {
        Order c(4.5);
        check("c id 5003, 3 active",     c.getId() == 5003 && Order::activeOrders() == 3);
    }
    check("2 active after scope",        Order::activeOrders() == 2);
    check("revenue 40.0 (keeps c)",      fabs(Order::totalRevenue() - 40.0) < 1e-9);
    Order d(1.0);
    check("ids never reused: 5004",      d.getId() == 5004);
    */
    return 0;
}
