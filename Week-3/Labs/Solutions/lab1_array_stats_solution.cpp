// CSCE 306 | Week 3 • Lab 1 Part 1: Array Statistics (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab1_array_stats_solution.cpp -o lab1

#include <iostream>
#include <string>
using namespace std;

int sum(const int a[], int size)
{
    int total = 0;
    for (int i = 0; i < size; ++i) total += a[i];
    return total;
}

int minimum(const int a[], int size)
{
    int smallest = a[0];
    for (int i = 1; i < size; ++i)
        if (a[i] < smallest) smallest = a[i];
    return smallest;
}

int find(const int a[], int size, int target)
{
    for (int i = 0; i < size; ++i)
        if (a[i] == target) return i;
    return -1;
}

void reverseInPlace(int a[], int size)
{
    for (int left = 0, right = size - 1; left < right; ++left, --right) {
        int temp = a[left];
        a[left]  = a[right];
        a[right] = temp;
    }
}

int countAboveAverage(const int a[], int size)
{
    if (size == 0) return 0;
    double avg = static_cast<double>(sum(a, size)) / size;
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (a[i] > avg) ++count;
    return count;
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
    check("countAboveAverage == 3",   countAboveAverage(data, n) == 3);
    reverseInPlace(data, n);
    check("reverse -> 6 5 1 9 3 7",   data[0] == 6 && data[2] == 1 && data[5] == 7);
    return 0;
}
