// CSCE 306 | Week 3 • Example 02: Passing arrays to functions (Ch. 7)
// Build: g++ -std=c++17 -Wall -Wextra 02_arrays_and_functions.cpp -o arrfunc

#include <iostream>
using namespace std;

// An array parameter decays to a pointer: the function cannot know the size,
// so we ALWAYS pass the size separately.
double average(const int values[], int size)   // const: function will not modify
{
    if (size == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += values[i];
    return static_cast<double>(sum) / size;
}

void doubleAll(int values[], int size)         // no const: modifies the caller's array
{
    for (int i = 0; i < size; ++i) values[i] *= 2;
}

int indexOfMax(const int values[], int size)   // linear search for the maximum
{
    int best = 0;
    for (int i = 1; i < size; ++i)
        if (values[i] > values[best]) best = i;
    return best;
}

int main()
{
    int data[] = {4, 8, 15, 16, 23, 42};
    const int n = sizeof(data) / sizeof(data[0]);

    cout << "average = " << average(data, n) << '\n';
    cout << "max at index " << indexOfMax(data, n) << '\n';
    doubleAll(data, n);                         // arrays are effectively passed "by reference"
    cout << "after doubleAll, data[0] = " << data[0] << '\n';
    return 0;
}
