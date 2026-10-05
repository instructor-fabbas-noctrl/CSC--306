// CSCE 306 | Week 2 • Lab 1: Shipping Calculator -- decisions (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab1_shipping.cpp -o lab1
// Test:  printf "3.5\nE\n" | ./lab1
//
// Rate table (per package, by weight in lb):
//     weight <= 0           -> invalid, print error and return 1
//     0  < weight <= 2      -> $5.00
//     2  < weight <= 10     -> $9.50
//     10 < weight <= 50     -> $18.00
//     weight > 50           -> $18.00 + $0.75 for every pound over 50
// Service code (use a switch):  S = standard (x1.0), E = express (x1.5),
//                               O = overnight (x2.25); anything else -> error.
// Lowercase codes must also work.
//
// Sample run:
//   Weight (lb): 3.5
//   Service [S/E/O]: E
//   Base rate: $9.50  Multiplier: 1.50  Cost: $14.25

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main()
{
    double weight = 0.0;
    char service = ' ';
    cout << "Weight (lb): ";      cin >> weight;
    cout << "Service [S/E/O]: ";  cin >> service;

    double base = 0.0;
    double multiplier = 1.0;

    // TODO 1: validate weight, then set base using an if / else if chain


    // TODO 2: set multiplier with a switch on toupper(service); handle invalid codes


    cout << fixed << setprecision(2)
         << "Base rate: $" << base << "  Multiplier: " << multiplier
         << "  Cost: $" << base * multiplier << '\n';
    return 0;
}
