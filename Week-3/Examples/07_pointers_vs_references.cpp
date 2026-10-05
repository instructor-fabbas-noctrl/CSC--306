// CSCE 306 | Week 3 • Example 07: Pointers vs references as parameters (Ch. 6, 9)
// Build: g++ -std=c++17 -Wall -Wextra 07_pointers_vs_references.cpp -o ptrref

#include <iostream>
using namespace std;

void incrementByPointer(int* n)   { if (n != nullptr) (*n)++; }   // may be null: check!
void incrementByReference(int& n) { n++; }                        // always refers to something

int main()
{
    int a = 1, b = 1;
    incrementByPointer(&a);      // caller must pass an address
    incrementByReference(b);     // looks like pass-by-value at the call site
    cout << "a=" << a << " b=" << b << '\n';

    // A reference is an alias: it must be initialized and cannot be reseated
    int x = 10;
    int& alias = x;
    alias = 20;                  // changes x
    cout << "x=" << x << '\n';

    // Rule of thumb for this course:
    //   - use const T&   to pass objects you only read
    //   - use T&         to pass objects you modify
    //   - use T*         when "no object" (nullptr) is a valid option, or for dynamic memory
    return 0;
}
