// CSCE 306 | Week 6 • Lab Part 3: Relationship notation -> code (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab3_relationship_notation.cpp -o lab3
//
//                       0..*                       1
//   PhoneStore ◇—————————————— Smartphone ◆——————————— Battery
//                                  |
//                             0..1 |                    Smartphone - - - -> Charger
//                                  v                         (dependency)
//                                Owner   (association, navigable Smartphone -> Owner)
//
// Implement so the relationship TYPE is visible in the code:
//   Battery     : int percent (0..100); drain(int), charge(int) clamp to 0..100
//   Charger     : int wattage; percentPerMinute() const = wattage / 5
//   Owner       : string name
//   Smartphone  : model; Battery battery (starts 50%); Owner* owner = nullptr
//                 setOwner(Owner*), ownerName() const ("unowned" if none)
//                 use(int minutes)                      -> battery drains 2% per minute
//                 plugIn(const Charger& c, int minutes) -> charges c.percentPerMinute()*minutes
//                 batteryLevel() const
//   PhoneStore  : vector<Smartphone*> display; stock(Smartphone*), count() const
//                 The store must NOT delete phones.
//
// In a comment above each member that implements a relationship, name the relationship.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TODO: Battery, Charger, Owner, Smartphone, PhoneStore

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    Smartphone p("Pixel");
    check("starts 50%",        p.batteryLevel() == 50);
    check("unowned",           p.ownerName() == "unowned");
    Owner ada("Ada");
    p.setOwner(&ada);
    check("owner Ada",         p.ownerName() == "Ada");
    p.use(10);
    check("drains to 30%",     p.batteryLevel() == 30);
    Charger fast(25);          // 5% per minute
    p.plugIn(fast, 20);
    check("clamps at 100%",    p.batteryLevel() == 100);
    p.use(80);
    check("clamps at 0%",      p.batteryLevel() == 0);
    {
        PhoneStore store;
        store.stock(&p);
        check("store has 1",   store.count() == 1);
    }
    check("phone outlives store", p.ownerName() == "Ada");
    */
    return 0;
}
