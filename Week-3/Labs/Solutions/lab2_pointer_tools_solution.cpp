// CSCE 306 | Week 3 • Lab 1 Part 2: Pointer Tools (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab2_pointer_tools_solution.cpp -o lab2

#include <iostream>
#include <string>
using namespace std;

void swapPtr(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

const int* maxElement(const int* begin, const int* end)
{
    const int* best = begin;
    for (const int* p = begin; p != end; ++p)
        if (*p > *best) best = p;          // strict > keeps the first occurrence
    return best;
}

void iota(int* begin, int* end, int start)
{
    for (int* p = begin; p != end; ++p)
        *p = start++;
}

bool minMax(const int* arr, int size, int* outMin, int* outMax)
{
    if (size <= 0) return false;
    *outMin = *outMax = *arr;
    for (const int* p = arr + 1; p != arr + size; ++p) {
        if (*p < *outMin) *outMin = *p;
        if (*p > *outMax) *outMax = *p;
    }
    return true;
}

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    int x = 1, y = 2;
    swapPtr(&x, &y);
    check("swapPtr", x == 2 && y == 1);

    int vals[] = {4, 11, 2, 11, 8};
    const int* m = maxElement(vals, vals + 5);
    check("maxElement value 11",       *m == 11);
    check("maxElement first occurrence", m == vals + 1);

    int seq[5];
    iota(seq, seq + 5, 10);
    check("iota 10..14", seq[0] == 10 && seq[4] == 14);

    int lo = 0, hi = 0;
    check("minMax returns true", minMax(vals, 5, &lo, &hi));
    check("minMax 2 / 11",       lo == 2 && hi == 11);
    check("minMax empty false",  !minMax(vals, 0, &lo, &hi));
    return 0;
}
