// CSCE 306 | Week 1 • Lab 3: Campus Café Receipt (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab3_receipt_solution.cpp -o lab3
// Test:  printf "2\n1\n3\n" | ./lab3

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    constexpr double COFFEE = 2.25, BAGEL = 3.10, MUFFIN = 2.75;
    constexpr double TAX_RATE = 0.0825;

    int coffees = 0, bagels = 0, muffins = 0;
    cout << "Coffees: ";  cin >> coffees;
    cout << "Bagels: ";   cin >> bagels;
    cout << "Muffins: ";  cin >> muffins;
    cout << '\n';

    double coffeeAmt = coffees * COFFEE;
    double bagelAmt  = bagels  * BAGEL;
    double muffinAmt = muffins * MUFFIN;
    double subtotal  = coffeeAmt + bagelAmt + muffinAmt;
    double tax       = subtotal * TAX_RATE;
    double total     = subtotal + tax;

    const string rule(29, '-');
    cout << fixed << setprecision(2);
    cout << left << setw(14) << "Item" << right << setw(5) << "Qty" << setw(10) << "Amount" << '\n';
    cout << rule << '\n';
    cout << left << setw(14) << "Coffee" << right << setw(5) << coffees << setw(10) << coffeeAmt << '\n';
    cout << left << setw(14) << "Bagel"  << right << setw(5) << bagels  << setw(10) << bagelAmt  << '\n';
    cout << left << setw(14) << "Muffin" << right << setw(5) << muffins << setw(10) << muffinAmt << '\n';
    cout << rule << '\n';
    cout << left << setw(19) << "Subtotal" << right << setw(10) << subtotal << '\n';
    cout << left << setw(19) << "Tax"      << right << setw(10) << tax      << '\n';
    cout << left << setw(19) << "Total"    << right << setw(10) << total    << '\n';
    return 0;
}
