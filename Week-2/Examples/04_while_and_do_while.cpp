// CSCE 306 | Week 2 • Example 04: while, do-while, and input validation (Ch. 5)
// Build: g++ -std=c++17 -Wall -Wextra 04_while_and_do_while.cpp -o loops
// Try:   printf "-3\n150\n42\n10\n20\n-1\n" | ./loops

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    // Input validation loop: keep asking until the value is in range
    int age = -1;
    cout << "Enter age (0-120): ";
    cin >> age;
    while (!cin || age < 0 || age > 120) {
        if (cin.eof()) return 1;                             // no more input at all
        cin.clear();                                         // reset a fail state (e.g., letters typed)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the bad line
        cout << "  Invalid. Enter age (0-120): ";
        cin >> age;
    }
    cout << "Accepted age " << age << "\n\n";

    // Sentinel-controlled loop: -1 ends input
    int value = 0, count = 0, sum = 0;
    cout << "Enter positive numbers (-1 to stop): ";
    cin >> value;
    while (cin && value != -1) {   // also stops at end-of-input
        sum += value;
        ++count;
        cin >> value;
    }
    cout << "Count = " << count << ", sum = " << sum << '\n';

    // do-while: body runs at least once
    int i = 10;
    do {
        cout << "do-while ran with i = " << i << '\n';
    } while (i < 5);
    return 0;
}
