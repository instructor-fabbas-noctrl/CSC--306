// CSCE 306 | Week 5 • Lab Part 1: Static members -- Order IDs and a running total (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab1_static_members_solution.cpp -o lab1

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Order {
private:
    static int    nextId;
    static int    active;
    static double revenue;
    int    id;
    double amount;

public:
    explicit Order(double amt) : id(nextId++), amount(amt)
    {
        ++active;
        revenue += amount;
    }
    ~Order() { --active; }

    int    getId() const     { return id; }
    double getAmount() const { return amount; }

    static int    activeOrders() { return active; }
    static double totalRevenue() { return revenue; }
};

int    Order::nextId  = 5001;
int    Order::active  = 0;
double Order::revenue = 0.0;

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
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
    return 0;
}
