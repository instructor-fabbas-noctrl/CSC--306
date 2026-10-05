// CSCE 306 | Week 2 • Lab 2: Number Statistics -- loops (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab2_number_stats_solution.cpp -o lab2
// Test:  printf "12\n-4\n7\n0\n25\n-999\n" | ./lab2

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

    while (cin && value != SENTINEL) {      // also stop on bad input / EOF
        if (count == 0) {
            minVal = maxVal = value;          // first value seeds min and max
        } else {
            if (value < minVal) minVal = value;
            if (value > maxVal) maxVal = value;
        }
        sum += value;
        ++count;
        if (value % 2 == 0) ++evens;
        if (value < 0)      ++negatives;
        cin >> value;
    }

    if (count == 0) {
        cout << "No data.\n";
        return 0;
    }
    cout << fixed << setprecision(2)
         << "Count: " << count << "  Sum: " << sum
         << "  Average: " << static_cast<double>(sum) / count << '\n'
         << "Min: " << minVal << "  Max: " << maxVal
         << "  Even: " << evens << "  Negative: " << negatives << '\n';
    return 0;
}
