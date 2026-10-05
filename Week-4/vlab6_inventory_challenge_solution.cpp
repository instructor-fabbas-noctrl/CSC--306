// CSCE 306 | Week 4 • Vector Lab 6 (challenge): Inventory -- iterators, lambdas, filtered views (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra vlab6_inventory_challenge.cpp -o vlab6
//
// Inventory keeps a PRIVATE vector<Item>. This lab practices the vector skills you need for the
// rest of the semester: erasing safely while iterating, filtering into a new vector,
// sorting with different lambdas, and returning results without exposing the data member.
//
// THE CLASSIC BUG:  for (auto it = v.begin(); it != v.end(); ++it) if (...) v.erase(it);
// erase() invalidates 'it'. Correct pattern:   it = v.erase(it);   (and do NOT ++it that time)
// -- or use the erase-remove idiom.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Item {
private:
    string sku;
    string name;
    double price;
    int    qty;
    bool   discontinued;
public:
    Item(const string& s, const string& n, double p, int q, bool d = false)
        : sku(s), name(n), price(p), qty(q), discontinued(d) {}
    string getSku() const   { return sku; }
    string getName() const  { return name; }
    double getPrice() const { return price; }
    int    getQty() const   { return qty; }
    bool   isDiscontinued() const { return discontinued; }
    void   changeQty(int delta) { qty += delta; }
    void   discontinue() { discontinued = true; }
};

enum class SortKey { Name, Price, Value };   // Value = price * qty, highest first

class Inventory {
private:
    vector<Item> items;
    Item* findMutable(const string& sku);      // helper for the non-const members
public:
    bool add(const Item& item);                // false if the SKU already exists
    bool sell(const string& sku, int amount);  // false: unknown SKU, amount <= 0, or not enough stock
    bool restock(const string& sku, int amount);   // false: unknown SKU, amount <= 0, or discontinued
    bool discontinue(const string& sku);
    int  purgeDiscontinuedSoldOut();           // erase items that are discontinued AND qty == 0; return count
    vector<Item> lowStock(int threshold) const;    // active items with qty < threshold, in stored order
    void sortBy(SortKey key);
    double totalValue() const;                 // sum of price * qty
    string skus() const;                       // "A1 B2 C3" -- SKUs in stored order, space separated
    void report() const;
};

Item* Inventory::findMutable(const string& sku)
{
    for (Item& it : items)
        if (it.getSku() == sku) return &it;
    return nullptr;
}

bool Inventory::add(const Item& item)
{
    if (findMutable(item.getSku()) != nullptr) return false;
    items.push_back(item);
    return true;
}

bool Inventory::sell(const string& sku, int amount)
{
    Item* it = findMutable(sku);
    if (it == nullptr || amount <= 0 || amount > it->getQty()) return false;
    it->changeQty(-amount);
    return true;
}

bool Inventory::restock(const string& sku, int amount)
{
    Item* it = findMutable(sku);
    if (it == nullptr || amount <= 0 || it->isDiscontinued()) return false;
    it->changeQty(amount);
    return true;
}

bool Inventory::discontinue(const string& sku)
{
    Item* it = findMutable(sku);
    if (it == nullptr) return false;
    it->discontinue();
    return true;
}

int Inventory::purgeDiscontinuedSoldOut()
{
    int removed = 0;
    for (auto it = items.begin(); it != items.end(); ) {
        if (it->isDiscontinued() && it->getQty() == 0) {
            it = items.erase(it);          // erase returns the next valid iterator
            ++removed;
        } else {
            ++it;
        }
    }
    return removed;
}

vector<Item> Inventory::lowStock(int threshold) const
{
    vector<Item> result;
    copy_if(items.begin(), items.end(), back_inserter(result),
            [threshold](const Item& it) { return !it.isDiscontinued() && it.getQty() < threshold; });
    return result;
}

void Inventory::sortBy(SortKey key)
{
    switch (key) {
        case SortKey::Name:
            sort(items.begin(), items.end(),
                 [](const Item& a, const Item& b) { return a.getName() < b.getName(); });
            break;
        case SortKey::Price:
            sort(items.begin(), items.end(),
                 [](const Item& a, const Item& b) { return a.getPrice() < b.getPrice(); });
            break;
        case SortKey::Value:
            sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                return a.getPrice() * a.getQty() > b.getPrice() * b.getQty();
            });
            break;
    }
}

double Inventory::totalValue() const
{
    double total = 0.0;
    for (const Item& it : items) total += it.getPrice() * it.getQty();
    return total;
}

string Inventory::skus() const
{
    string out;
    for (const Item& it : items) out += (out.empty() ? "" : " ") + it.getSku();
    return out;
}

void Inventory::report() const
{
    for (const Item& it : items) {
        cout << "  " << left << setw(5) << it.getSku() << setw(14) << it.getName() << right
             << setw(4) << it.getQty() << setw(8) << fixed << setprecision(2) << it.getPrice()
             << (it.isDiscontinued() ? "  (discontinued)" : "") << '\n';
    }
    cout << "  total value: $" << fixed << setprecision(2) << totalValue() << '\n';
}

// ----------------------------- test driver (do not change) -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Inventory inv;
    inv.add(Item("K10", "Keyboard", 49.99, 12));
    inv.add(Item("M20", "Mouse", 19.95, 3));
    inv.add(Item("C30", "USB-C cable", 9.50, 40));
    inv.add(Item("W40", "Webcam", 64.00, 2));
    inv.add(Item("H50", "Headset", 79.00, 1));
    check("duplicate SKU rejected",     !inv.add(Item("M20", "Other mouse", 5.00, 1)));

    check("sell 2 mice",                inv.sell("M20", 2));
    check("cannot oversell",            !inv.sell("W40", 3));
    check("cannot sell unknown",        !inv.sell("ZZZ", 1));
    check("restock keyboards",          inv.restock("K10", 8));

    vector<Item> low = inv.lowStock(5);
    check("lowStock(5): M20 W40 H50",   low.size() == 3 && low[0].getSku() == "M20" && low[2].getSku() == "H50");

    inv.discontinue("H50");
    check("cannot restock discontinued", !inv.restock("H50", 5));
    check("lowStock skips discontinued", inv.lowStock(5).size() == 2);
    inv.sell("H50", 1);                  // last headset sold
    inv.discontinue("W40");              // discontinued but still has stock: keep it
    check("purge removed 1",            inv.purgeDiscontinuedSoldOut() == 1);
    check("H50 gone, W40 kept",         inv.skus() == "K10 M20 C30 W40");

    inv.sortBy(SortKey::Name);
    check("sort by name",               inv.skus() == "K10 M20 C30 W40");
    inv.sortBy(SortKey::Price);
    check("sort by price",              inv.skus() == "C30 M20 K10 W40");
    inv.sortBy(SortKey::Value);
    check("sort by value (high first)", inv.skus() == "K10 C30 W40 M20");
    check("total value 1527.75",        inv.totalValue() > 1527.74 && inv.totalValue() < 1527.76);
    inv.report();
    return 0;
}
