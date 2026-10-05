// CSCE 306 | Week 5 • Example 05: Copy constructor, copy assignment, Rule of Three (Ch. 14.4–14.5)
// Build: g++ -std=c++17 -Wall -Wextra 05_copy_constructor_rule_of_three.cpp -o rule3
// Try the shallow-copy bug safely with: -fsanitize=address

#include <iostream>
#include <string>
using namespace std;

// A class that OWNS a dynamic array.
// RULE OF THREE: if a class needs a destructor, it almost certainly needs a
// copy constructor and a copy assignment operator too.
class IntBuffer {
private:
    int* data;
    int  size;

public:
    explicit IntBuffer(int n) : data(new int[n]{}), size(n) {}

    // 1) Destructor
    ~IntBuffer() { delete[] data; }

    // 2) Copy constructor: DEEP copy -- allocate our own array, copy values
    IntBuffer(const IntBuffer& other) : data(new int[other.size]), size(other.size)
    {
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
        cout << "  [copy ctor]\n";
    }

    // 3) Copy assignment: guard against self-assignment, free old, deep copy
    IntBuffer& operator=(const IntBuffer& other)
    {
        cout << "  [copy assign]\n";
        if (this != &other) {
            int* fresh = new int[other.size];          // allocate first (exception safety)
            for (int i = 0; i < other.size; ++i) fresh[i] = other.data[i];
            delete[] data;
            data = fresh;
            size = other.size;
        }
        return *this;
    }

    void set(int i, int v) { if (i >= 0 && i < size) data[i] = v; }
    int  get(int i) const  { return (i >= 0 && i < size) ? data[i] : 0; }
};

int main()
{
    IntBuffer a(3);
    a.set(0, 42);

    IntBuffer b = a;          // copy ctor
    b.set(0, 99);             // changes ONLY b because the copy is deep

    IntBuffer c(1);
    c = a;                    // copy assignment
    c = c;                    // self-assignment is handled safely

    cout << "a[0]=" << a.get(0) << " b[0]=" << b.get(0) << " c[0]=" << c.get(0) << '\n';
    // Without (2) and (3): a, b, c would share one array, b.set would change a,
    // and the destructor would delete[] the same memory three times -> crash.
    return 0;
}
