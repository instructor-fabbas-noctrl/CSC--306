// CSCE 306 | Week 1 • Lab 2: Temperature Converter (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab2_temperature_solution.cpp -o lab2
// Test:  echo 98.6 | ./lab2

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    constexpr double KELVIN_OFFSET = 273.15;
    double fahrenheit = 0.0;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;

    // 5.0 / 9.0 keeps the arithmetic in floating point
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    double kelvin  = celsius + KELVIN_OFFSET;

    cout << fixed << setprecision(1);
    cout << fahrenheit << " F = " << celsius << " C = " << kelvin << " K\n";
    return 0;
}
