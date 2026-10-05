// CSCE 306 | Week 6 • Lab Part 1: CRC cards -> class skeletons (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab1_crc_to_classes_solution.cpp -o lab1

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class MenuItem {                                   // "know name, know price"
private:
    string name;
    double price;
public:
    MenuItem(const string& n, double p) : name(n), price(p) {}
    string getName() const  { return name; }
    double getPrice() const { return price; }
};

class Order {                                      // "hold items, compute total"
private:
    vector<MenuItem> items;                        // collaborator: MenuItem
public:
    void   add(const MenuItem& item) { items.push_back(item); }
    double total() const
    {
        double t = 0.0;
        for (const MenuItem& m : items) t += m.getPrice();
        return t;
    }
};

class Customer {                                   // "know name, track/earn/redeem points"
private:
    string name;
    int    points = 0;
public:
    static constexpr int REWARD_COST = 10;
    explicit Customer(const string& n) : name(n) {}
    string getName() const   { return name; }
    int    getPoints() const { return points; }

    void earnPoints(const Order& order)            // collaborator: Order (dependency)
    {
        points += static_cast<int>(floor(order.total()));
    }
    bool redeem()
    {
        if (points < REWARD_COST) return false;
        points -= REWARD_COST;
        return true;
    }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    MenuItem latte("Latte", 4.75), scone("Scone", 3.50);
    Order o;
    o.add(latte); o.add(latte); o.add(scone);
    check("order total 13.00",   fabs(o.total() - 13.00) < 1e-9);
    Customer c("Ada");
    c.earnPoints(o);
    check("13 points earned",    c.getPoints() == 13);
    check("redeem succeeds",     c.redeem());
    check("3 points left",       c.getPoints() == 3);
    check("second redeem fails", !c.redeem());
    return 0;
}
