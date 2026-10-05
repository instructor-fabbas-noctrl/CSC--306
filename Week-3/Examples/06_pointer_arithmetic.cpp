// CSCE 306 | Week 3 • Example 06: Pointers and arrays, pointer arithmetic (Ch. 9)
// Build: g++ -std=c++17 -Wall -Wextra 06_pointer_arithmetic.cpp -o ptrarith

#include <iostream>
using namespace std;

int main()
{
    int nums[] = {10, 20, 30, 40, 50};
    int* p = nums;              // an array name converts to a pointer to element 0

    cout << "*p       = " << *p       << '\n';   // 10
    cout << "*(p + 2) = " << *(p + 2) << '\n';   // 30  -- same as nums[2]
    cout << "p[3]     = " << p[3]     << '\n';   // 40  -- subscript works on pointers

    // p + 1 advances by sizeof(int) bytes, not by 1 byte
    cout << "p     = " << p << "\np + 1 = " << p + 1 << '\n';

    // Walking an array with a pointer
    cout << "walk: ";
    for (int* q = nums; q != nums + 5; ++q)      // nums + 5 is "one past the end"
        cout << *q << ' ';
    cout << '\n';

    // Distance between pointers
    int* last = &nums[4];
    cout << "last - p = " << (last - p) << " elements\n";
    return 0;
}
