// CSCE 306 | Week 1 • Lab 4: Seconds to H:M:S (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab4_time_converter.cpp -o lab4
// Test:  echo 7384 | ./lab4
//
// Read a whole number of seconds and print it as hours, minutes, seconds
// using ONLY integer division (/) and remainder (%).
//
// Sample run:
//   Enter total seconds: 7384
//   7384 seconds = 2 h 3 m 4 s  (02:03:04)
//
// BONUS: print the zero-padded form using setw(2) and setfill('0').

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

    // TODO 1: hours   = ?
    int hours = 0;
    // TODO 2: minutes = ?   (hint: use the remainder after removing hours)
    int minutes = 0;
    // TODO 3: seconds = ?
    int seconds = 0;

    (void)SECONDS_PER_MINUTE; (void)SECONDS_PER_HOUR;   // delete this line once you use the constants

    cout << totalSeconds << " seconds = " << hours << " h " << minutes << " m "
         << seconds << " s\n";
    return 0;
}
