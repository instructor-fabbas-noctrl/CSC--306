// CSCE 306 — Object-Oriented Software Development | Fall 2026
// Week 3 • Example 01: Arrays -- declaration, initialization, range-for (Ch. 7)
// Build: g++ -std=c++17 -Wall -Wextra 01_arrays_basics.cpp -o arrays

#include <iostream>
using namespace std;

int main()
{
    constexpr int SIZE = 5;
    int scores[SIZE] = {88, 92, 75, 64, 99};   // size must be a compile-time constant
    int zeros[SIZE]  = {};                      // all elements value-initialized to 0
    double partial[4] = {1.5, 2.5};             // remaining elements become 0.0

    // Indexed loop: valid indices are 0 .. SIZE-1
    for (int i = 0; i < SIZE; ++i)
        cout << "scores[" << i << "] = " << scores[i] << '\n';

    // Range-based for (C++11): read-only copy of each element
    int total = 0;
    for (int s : scores) total += s;
    cout << "Total = " << total << '\n';

    // Range-for by reference to MODIFY elements
    for (int& s : scores) s += 1;               // curve everyone by 1 point
    cout << "After curve, scores[0] = " << scores[0] << '\n';

    cout << "zeros[3] = " << zeros[3] << ", partial[3] = " << partial[3] << '\n';
    cout << "sizeof(scores) / sizeof(scores[0]) = " << sizeof(scores) / sizeof(scores[0]) << '\n';

    // DANGER: C++ does NOT bounds-check. scores[5] is undefined behavior.
    return 0;
}
