// CSCE 306 | Week 3 • Example 11: Arrays/vectors of structs (Ch. 11)
// Build: g++ -std=c++17 -Wall -Wextra 11_array_of_structs.cpp -o structarr

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Product {
    string name;
    double price;
    int    quantity;
};

double inventoryValue(const vector<Product>& items)
{
    double total = 0.0;
    for (const Product& p : items) total += p.price * p.quantity;
    return total;
}

const Product* findByName(const vector<Product>& items, const string& name)
{
    for (const Product& p : items)
        if (p.name == name) return &p;          // address of the element
    return nullptr;                              // not found
}

int main()
{
    vector<Product> stock = {
        {"Keyboard", 49.99, 10},
        {"Mouse",    19.95, 25},
        {"Monitor", 189.00, 4}
    };

    cout << fixed << setprecision(2);
    for (const Product& p : stock)
        cout << left << setw(10) << p.name << right << setw(8) << p.price
             << setw(5) << p.quantity << '\n';
    cout << "Inventory value: $" << inventoryValue(stock) << '\n';

    if (const Product* hit = findByName(stock, "Mouse"))
        cout << "Found " << hit->name << " at $" << hit->price << '\n';
    if (findByName(stock, "Webcam") == nullptr)
        cout << "Webcam not stocked\n";
    return 0;
}
