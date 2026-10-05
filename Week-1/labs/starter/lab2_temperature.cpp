// CSCE 306 | Week 1 • Lab 2: Temperature Converter (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab2_temperature.cpp -o lab2
// Test:  echo 98.6 | ./lab2
//
// Read a temperature in Fahrenheit and print Celsius and Kelvin,
// each with exactly 1 digit after the decimal point.
//     C = (F - 32) * 5 / 9        K = C + 273.15
//
// Sample run:
//   Enter temperature in Fahrenheit: 98.6
//   98.6 F = 37.0 C = 310.1 K
//
// WATCH OUT: 5 / 9 in integer math is 0. Make sure your formula uses doubles.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double fahrenheit = 0.0;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;

    // TODO 1: compute celsius
    double celsius = 0.0;

    // TODO 2: compute kelvin
    double kelvin = 0.0;

    // TODO 3: set fixed/1-decimal formatting and print the result line
    cout << fahrenheit << " F = " << celsius << " C = " << kelvin << " K\n";
    return 0;
}
