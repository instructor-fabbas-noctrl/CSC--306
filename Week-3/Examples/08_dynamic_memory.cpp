// CSCE 306 | Week 3 • Example 08: Dynamic memory -- new / delete / delete[] (Ch. 9)
// Build: g++ -std=c++17 -Wall -Wextra 08_dynamic_memory.cpp -o dyn

#include <iostream>
using namespace std;

int* makeFilledArray(int size, int value)
{
    int* arr = new int[size];   // lives on the HEAP until explicitly deleted
    for (int i = 0; i < size; ++i) arr[i] = value;
    return arr;                 // safe: heap memory outlives this function
}

int main()
{
    // Single object
    double* price = new double(19.99);
    cout << "*price = " << *price << '\n';
    delete price;               // matching delete
    price = nullptr;            // avoid a dangling pointer

    // Array whose size is decided at run time
    int n = 6;
    int* data = makeFilledArray(n, 7);
    for (int i = 0; i < n; ++i) cout << data[i] << ' ';
    cout << '\n';
    delete[] data;              // new[] MUST be paired with delete[]
    data = nullptr;

    // Common bugs (do NOT do these):
    //   - forgetting delete             -> memory leak
    //   - using memory after delete      -> dangling pointer / undefined behavior
    //   - delete on a new[] array        -> undefined behavior (use delete[])
    // Later in the course: classes with destructors and smart pointers manage this for us.
    return 0;
}
