// CSCE 306 | Week 5 • Example 02: The this pointer and method chaining (Ch. 14.5)
// Build: g++ -std=c++17 -Wall -Wextra 02_this_pointer_and_chaining.cpp -o this

#include <iostream>
#include <string>
using namespace std;

class Pizza {
private:
    string size = "medium";
    string toppings;
    int    slices = 8;

public:
    // 'this' points to the object the function was called on.
    // Use 1: disambiguate a parameter that shadows a member.
    Pizza& setSize(const string& size)
    {
        this->size = size;           // member = parameter
        return *this;                // Use 2: return the object itself for chaining
    }
    Pizza& addTopping(const string& t)
    {
        toppings += (toppings.empty() ? "" : ", ") + t;
        return *this;
    }
    Pizza& setSlices(int slices)
    {
        if (slices > 0) this->slices = slices;
        return *this;
    }
    // Use 3: compare against another object
    bool isSameAs(const Pizza& other) const { return this == &other; }

    void print() const
    {
        cout << size << " pizza, " << slices << " slices: " << (toppings.empty() ? "plain" : toppings) << '\n';
    }
};

int main()
{
    Pizza order;
    order.setSize("large").addTopping("mushroom").addTopping("olive").setSlices(10);   // chained
    order.print();

    Pizza& alias = order;
    cout << boolalpha << "alias is same object? " << order.isSameAs(alias) << '\n';
    return 0;
}
