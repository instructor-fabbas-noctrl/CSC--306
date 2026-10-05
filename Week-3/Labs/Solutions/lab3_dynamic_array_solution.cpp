// CSCE 306 | Week 3 • Lab 1 Part 3: Growable Dynamic Array (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab3_dynamic_array_solution.cpp -o lab3

#include <iostream>
#include <string>
using namespace std;

// data is passed as int*& because append may REPLACE the pointer itself
// (point it at a bigger block); the caller must see that change.
void append(int*& data, int& size, int& capacity, int value)
{
    if (size == capacity) {
        int newCap = (capacity == 0) ? 2 : capacity * 2;
        int* bigger = new int[newCap];
        for (int i = 0; i < size; ++i) bigger[i] = data[i];
        delete[] data;          // safe even when data is nullptr
        data = bigger;
        capacity = newCap;
    }
    data[size++] = value;
}

bool removeAt(int* data, int& size, int index)
{
    if (index < 0 || index >= size) return false;
    for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
    --size;
    return true;
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
    print(data, size);

    removeAt(data, size, 0);
    removeAt(data, size, 3);
    cout << "removeAt(99) -> " << boolalpha << removeAt(data, size, 99) << '\n';
    print(data, size);

    delete[] data;
    data = nullptr;
    return 0;
}
