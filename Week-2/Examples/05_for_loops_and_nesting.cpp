// CSCE 306 | Week 2 • Example 05: for loops, nested loops, break/continue (Ch. 5)
// Build: g++ -std=c++17 -Wall -Wextra 05_for_loops_and_nesting.cpp -o forloops

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Counting loop
    for (int i = 1; i <= 5; ++i)
        cout << i << (i < 5 ? ", " : "\n");

    // Nested loops: a multiplication table
    const int N = 5;
    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= N; ++col)
            cout << setw(4) << row * col;
        cout << '\n';
    }

    // continue skips the rest of this iteration; break leaves the loop
    cout << "Odd numbers until we pass 12: ";
    for (int k = 1; ; ++k) {
        if (k > 12) break;
        if (k % 2 == 0) continue;
        cout << k << ' ';
    }
    cout << '\n';
    return 0;
}
