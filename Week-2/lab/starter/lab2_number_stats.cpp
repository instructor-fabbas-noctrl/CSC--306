// CSCE 306 | Week 2 • Lab 2: Number Statistics -- loops (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab2_number_stats.cpp -o lab2
// Test:  printf "12\n-4\n7\n0\n25\n-999\n" | ./lab2
//
// Read integers until the sentinel -999. Report:
//   count, sum, average (2 decimals), minimum, maximum,
//   how many were even, and how many were negative.
// If no numbers were entered, print "No data." instead.
//
// Sample run (input 12 -4 7 0 25 -999):
//   Count: 5  Sum: 40  Average: 8.00
//   Min: -4  Max: 25  Even: 3  Negative: 1
//
// HINT: initialize min/max from the FIRST value read, not from 0.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    constexpr int SENTINEL = -999;
    int value = 0;
    int count = 0, sum = 0, minVal = 0, maxVal = 0, evens = 0, negatives = 0;

    cout << "Enter integers (" << SENTINEL << " to stop):\n";
    cin >> value;

    // TODO: write the sentinel loop that updates every statistic


    // TODO: print results (or "No data.")
    (void)minVal; (void)maxVal; (void)evens; (void)negatives; (void)sum; (void)count; // remove when used
    return 0;
}
