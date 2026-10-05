// CSCE 306 | Week 7 • Example 09: Inheriting constructors and final (C++11)
// Build: g++ -std=c++17 -Wall -Wextra 09_inheriting_constructors.cpp -o inherit_ctor

#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string name;
    double price;
public:
    Item(const string& n, double p) : name(n), price(p) {}
    explicit Item(const string& n) : Item(n, 0.0) {}
    void print() const { cout << name << " $" << price << '\n'; }
};

// 'using Base::Base' makes Item's constructors available for TaxFreeItem,
// useful when the derived class adds behavior but no new data.
class TaxFreeItem final : public Item {     // 'final': nothing may derive from this class
public:
    using Item::Item;
    double totalWithTax(double) const { return price; }   // ignores the rate
};

// class Special : public TaxFreeItem {};  // ERROR: TaxFreeItem is final

int main()
{
    TaxFreeItem bread("Bread", 3.49);   // uses the inherited Item(const string&, double)
    TaxFreeItem sample("Sample");       // uses the inherited Item(const string&)
    bread.print();
    sample.print();
    cout << "bread with tax: $" << bread.totalWithTax(0.0825) << '\n';
    return 0;
}
