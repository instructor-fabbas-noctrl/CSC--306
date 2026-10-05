// CSCE 306 | Week 3 • Example 05: Pointer basics -- &, *, nullptr (Ch. 9)
// Build: g++ -std=c++17 -Wall -Wextra 05_pointers_basics.cpp -o ptr

#include <iostream>
using namespace std;

int main()
{
    int value = 42;
    int* ptr = &value;          // ptr holds the ADDRESS of value

    cout << "value          = " << value << '\n';
    cout << "&value         = " << &value << '\n';
    cout << "ptr            = " << ptr << "   (same address)\n";
    cout << "*ptr           = " << *ptr << "   (dereference: the value AT that address)\n";

    *ptr = 100;                 // writing through the pointer changes value
    cout << "after *ptr=100, value = " << value << '\n';

    int other = 7;
    ptr = &other;               // a pointer can be re-pointed
    cout << "ptr now points to other: *ptr = " << *ptr << '\n';

    int* nothing = nullptr;     // C++11: use nullptr, not NULL or 0
    if (nothing == nullptr)
        cout << "nothing is null -- never dereference it!\n";

    // Pointer to const vs const pointer
    const int* readOnly = &value;   // cannot change *readOnly
    int* const fixed    = &value;   // cannot change where fixed points
    *fixed = 5;
    cout << "*readOnly = " << *readOnly << '\n';
    return 0;
}
