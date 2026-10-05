// CSCE 306 | Week 3 • Lab 1 Part 2: Pointer Tools (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab2_pointer_tools.cpp -o lab2
//
// RULE FOR THIS PART: inside the TODO functions, do NOT use the [] operator.
// Use pointer arithmetic and dereferencing only (*p, p + i, ++p).

#include <iostream>
#include <string>
using namespace std;

// Swap two ints through POINTERS (not references)
void swapPtr(int* a, int* b)
{
    // TODO
    (void)a; (void)b;
}

// Return a pointer to the largest element of [begin, end)  -- end is one past the last
const int* maxElement(const int* begin, const int* end)
{
    // TODO
    (void)end;
    return begin;
}

// Fill [begin, end) with start, start+1, start+2, ...
void iota(int* begin, int* end, int start)
{
    // TODO
    (void)begin; (void)end; (void)start;
}

// Compute both min and max in ONE pass, returning them through pointer out-parameters.
// If size == 0, leave *outMin / *outMax unchanged and return false.
bool minMax(const int* arr, int size, int* outMin, int* outMax)
{
    // TODO
    (void)arr; (void)size; (void)outMin; (void)outMax;
    return false;
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
