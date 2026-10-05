// CSCE 306 | Week 1 • Lab 3: Campus Café Receipt (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab3_receipt.cpp -o lab3
// Test:  printf "2\n1\n3\n" | ./lab3
//
// Prices are fixed: Coffee $2.25, Bagel $3.10, Muffin $2.75. Tax rate 8.25%.
// Ask how many of each item, then print an aligned receipt using <iomanip>.
//
// Sample run (input 2, 1, 3):
//   Item            Qty    Amount
//   -----------------------------
//   Coffee            2      4.50
//   Bagel             1      3.10
//   Muffin            3      8.25
//   -----------------------------
//   Subtotal                15.85
//   Tax                      1.31
//   Total                   17.16

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // TODO 1: declare constexpr prices and the tax rate


    int coffees = 0, bagels = 0, muffins = 0;
    cout << "Coffees: ";  cin >> coffees;
    cout << "Bagels: ";   cin >> bagels;
    cout << "Muffins: ";  cin >> muffins;
    cout << '\n';

    // TODO 2: compute each line amount, subtotal, tax, total


    // TODO 3: print the receipt -- columns: left setw(14), right setw(5), right setw(10)

    return 0;
}
