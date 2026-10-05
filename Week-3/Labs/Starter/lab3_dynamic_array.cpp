// CSCE 306 | Week 3 • Lab 1 Part 3: Growable Dynamic Array (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab3_dynamic_array.cpp -o lab3
// Leak check (Linux/macOS): g++ -std=c++17 -g -fsanitize=address lab3_dynamic_array.cpp -o lab3 && ./lab3
//
// You will build by hand what std::vector does for you, using new[] / delete[].
// A "dynamic array" is described by three things: a pointer, a size, a capacity.

#include <iostream>
#include <string>
using namespace std;

// Append value. If size == capacity, first grow:
//   newCap = (capacity == 0) ? 2 : capacity * 2
//   allocate a new array, copy the old elements, delete[] the old one, re-point data.
void append(int*& data, int& size, int& capacity, int value)   // note: int*& -- why?
{
    // TODO
    (void)data; (void)size; (void)capacity; (void)value;
}

// Remove the element at index (shift later elements left). Return false if index invalid.
bool removeAt(int* data, int& size, int index)
{
    // TODO
    (void)data; (void)size; (void)index;
    return false;
}

void print(const int* data, int size)
{
    cout << '[';
    for (int i = 0; i < size; ++i) cout << data[i] << (i + 1 < size ? ", " : "");
    cout << "]\n";
}

int main()
{
    int* data = nullptr;
    int size = 0, capacity = 0;

    for (int v = 1; v <= 9; ++v) {
        append(data, size, capacity, v * 10);
        cout << "size=" << size << " capacity=" << capacity << '\n';
    }
    print(data, size);                        // [10, 20, ..., 90]

    removeAt(data, size, 0);
    removeAt(data, size, 3);
    cout << "removeAt(99) -> " << boolalpha << removeAt(data, size, 99) << '\n';
    print(data, size);                        // [20, 30, 40, 60, 70, 80, 90]

    // TODO: release the memory and null the pointer
    return 0;
}
