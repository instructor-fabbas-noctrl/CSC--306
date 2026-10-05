// CSCE 306 | Week 1 • Lab 4: Seconds to H:M:S (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab4_time_converter_solution.cpp -o lab4
// Test:  echo 7384 | ./lab4

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    constexpr int SECONDS_PER_MINUTE = 60;
    constexpr int SECONDS_PER_HOUR   = 3600;

    int totalSeconds = 0;
    cout << "Enter total seconds: ";
    cin >> totalSeconds;

    int hours     = totalSeconds / SECONDS_PER_HOUR;
    int remaining = totalSeconds % SECONDS_PER_HOUR;
    int minutes   = remaining / SECONDS_PER_MINUTE;
    int seconds   = remaining % SECONDS_PER_MINUTE;

    cout << totalSeconds << " seconds = " << hours << " h " << minutes << " m "
         << seconds << " s  (" << setfill('0')
         << setw(2) << hours << ':' << setw(2) << minutes << ':' << setw(2) << seconds
         << ")\n" << setfill(' ');
    return 0;
}
