// CSCE 306 | Week 6 • Lab Part 3: Relationship notation -> code (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab3_relationship_notation_solution.cpp -o lab3

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Battery {
private:
    int percent;
    static int clamp(int v) { return v < 0 ? 0 : (v > 100 ? 100 : v); }
public:
    explicit Battery(int p) : percent(clamp(p)) {}
    void drain(int amount)  { percent = clamp(percent - amount); }
    void charge(int amount) { percent = clamp(percent + amount); }
    int  level() const      { return percent; }
};

class Charger {
private:
    int wattage;
public:
    explicit Charger(int w) : wattage(w) {}
    int percentPerMinute() const { return wattage / 5; }
};

class Owner {
private:
    string name;
public:
    explicit Owner(const string& n) : name(n) {}
    string getName() const { return name; }
};

class Smartphone {
private:
    string model;
    // COMPOSITION (◆, 1): the Battery is a value member; it lives and dies with the phone
    Battery battery{50};
    // ASSOCIATION (0..1, navigable phone -> owner): non-owning pointer, may be null
    Owner* owner = nullptr;
public:
    explicit Smartphone(const string& m) : model(m) {}
    void   setOwner(Owner* o)  { owner = o; }
    string ownerName() const   { return owner ? owner->getName() : "unowned"; }
    void   use(int minutes)    { battery.drain(2 * minutes); }
    // DEPENDENCY (- - ->): Charger appears only as a parameter; nothing is stored
    void   plugIn(const Charger& c, int minutes) { battery.charge(c.percentPerMinute() * minutes); }
    int    batteryLevel() const { return battery.level(); }
    string getModel() const    { return model; }
};

class PhoneStore {
private:
    // AGGREGATION (◇, 0..*): holds pointers to phones it does not own -- never deletes them
    vector<Smartphone*> display;
public:
    void stock(Smartphone* p) { if (p) display.push_back(p); }
    int  count() const        { return static_cast<int>(display.size()); }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Smartphone p("Pixel");
    check("starts 50%",        p.batteryLevel() == 50);
    check("unowned",           p.ownerName() == "unowned");
    Owner ada("Ada");
    p.setOwner(&ada);
    check("owner Ada",         p.ownerName() == "Ada");
    p.use(10);
    check("drains to 30%",     p.batteryLevel() == 30);
    Charger fast(25);
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
    return 0;
}
