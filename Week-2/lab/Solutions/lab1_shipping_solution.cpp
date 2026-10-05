// CSCE 306 | Week 2 • Lab 1: Shipping Calculator -- decisions (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab1_shipping_solution.cpp -o lab1
// Test:  printf "3.5\nE\n" | ./lab1      printf "62\no\n" | ./lab1

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

    if (weight <= 0) {
        cout << "Error: weight must be positive.\n";
        return 1;
    } else if (weight <= 2) {
        base = 5.00;
    } else if (weight <= 10) {
        base = 9.50;
    } else if (weight <= 50) {
        base = 18.00;
    } else {
        base = 18.00 + (weight - 50) * 0.75;
    }

    switch (toupper(service)) {
        case 'S': multiplier = 1.0;  break;
        case 'E': multiplier = 1.5;  break;
        case 'O': multiplier = 2.25; break;
        default:
            cout << "Error: unknown service code '" << service << "'.\n";
            return 1;
    }

    cout << fixed << setprecision(2)
         << "Base rate: $" << base << "  Multiplier: " << multiplier
         << "  Cost: $" << base * multiplier << '\n';
    return 0;
}
