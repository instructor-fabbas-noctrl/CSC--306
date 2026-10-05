// CSCE 306 | Week 3 • Lab 1 Part 1: Array Statistics (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab1_array_stats.cpp -o lab1
//
// Implement each function. Arrays are passed with an explicit size.
// Do NOT change main(); it prints PASS/FAIL for each test.

#include <iostream>
#include <string>
using namespace std;

// Sum of all elements
int sum(const int a[], int size)
{
    // TODO
    (void)a; (void)size;
    return 0;
}

// Smallest element (assume size >= 1)
int minimum(const int a[], int size)
{
    // TODO
    (void)a; (void)size;
    return 0;
}

// Index of the first occurrence of target, or -1 if not present (linear search)
int find(const int a[], int size, int target)
{
    // TODO
    (void)a; (void)size; (void)target;
    return -1;
}

// Reverse the array IN PLACE (swap ends, move inward)
void reverseInPlace(int a[], int size)
{
    // TODO
    (void)a; (void)size;
}

// Count how many elements are strictly greater than the average
int countAboveAverage(const int a[], int size)
{
    // TODO  (hint: reuse sum(); watch out for integer division)
    (void)a; (void)size;
    return 0;
}

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    int data[] = {7, 3, 9, 1, 5, 6};
    const int n = 6;
    check("sum == 31",                sum(data, n) == 31);
    check("minimum == 1",             minimum(data, n) == 1);
    check("find(9) == 2",             find(data, n, 9) == 2);
    check("find(42) == -1",           find(data, n, 42) == -1);
    check("countAboveAverage == 3",   countAboveAverage(data, n) == 3);   // avg 5.17 -> 7, 9, 6
    reverseInPlace(data, n);
    check("reverse -> 6 5 1 9 3 7",   data[0] == 6 && data[2] == 1 && data[5] == 7);
    return 0;
}
