// CSCE 306 | Week 6 • Lab Part 1: CRC cards -> class skeletons (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab1_crc_to_classes.cpp -o lab1
//
// SCENARIO: "A coffee shop takes ORDERS from CUSTOMERS. An order contains one or more
// MENU ITEMS, each with a name and price. Customers earn one LOYALTY point per whole
// dollar spent; 10 points can be redeemed for a free item."
//
// CRC cards (Class / Responsibilities / Collaborators):
//   +--------------------------------------------------------------+
//   | MenuItem                                                     |
//   |   Responsibilities: know name, know price                    |
//   |   Collaborators: --                                          |
//   +--------------------------------------------------------------+
//   | Order                                                        |
//   |   Responsibilities: hold items, compute total                |
//   |   Collaborators: MenuItem                                    |
//   +--------------------------------------------------------------+
//   | Customer                                                     |
//   |   Responsibilities: know name, track points,                 |
//   |                     earn points for an order, redeem points  |
//   |   Collaborators: Order                                       |
//   +--------------------------------------------------------------+
//
// TODO: turn each card into a class. Responsibilities that START with "know" become
// private data + const accessors; action verbs become member functions.
//   * Order::total() const -> double
//   * Customer::earnPoints(const Order&)   adds floor(total) points
//   * Customer::redeem() -> bool           subtracts 10 points if available
// Then make the test driver pass.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// TODO 1: class MenuItem

// TODO 2: class Order

// TODO 3: class Customer

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
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
    */
    return 0;
}
