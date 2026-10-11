// CSCE 306 - Week 8 - Lab 4: Why base classes need virtual destructors
// Build: g++ -std=c++17 -Wall -Wextra lab4_virtual_destructor.cpp -o lab4
// Run, read the output, add `virtual`, run again. (Tip: valgrind or -fsanitize=address shows the leak.)
#include <iostream>
using namespace std;

class Resource {
public:
    Resource()  { cout << "  Resource acquired\n"; }
    // TODO: Step 1: run once as-is and note which destructors print. Then make this destructor virtual and run again.
    ~Resource() { cout << "  Resource released\n"; }
};

class Buffer : public Resource {
    int* data;
public:
    Buffer() : data(new int[1000]) { cout << "  Buffer allocated 1000 ints\n"; }
    ~Buffer() { delete[] data; cout << "  Buffer freed\n"; }
};

int main() {
    cout << "Deleting Buffer through Resource*:\n";
    Resource* r = new Buffer();
    delete r;
    cout << "Done.\n";
    // TODO: Step 2: repeat with a Buffer on the stack (no pointer). Does virtual matter there? Why / why not?
    return 0;
}
