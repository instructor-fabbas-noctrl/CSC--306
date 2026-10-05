// CSCE 306 | Week 5 • Example 04: Memberwise assignment and default copying (Ch. 14.4)
// Build: g++ -std=c++17 -Wall -Wextra 04_memberwise_assignment.cpp -o memberwise

#include <iostream>
#include <string>
using namespace std;

class Settings {
public:
    string theme = "dark";
    int    fontSize = 12;
};

int main()
{
    Settings a;
    Settings b = a;          // copy CONSTRUCTION (a new object made from a)
    b.theme = "light";

    Settings c;
    c = b;                   // copy ASSIGNMENT (an existing object overwritten)

    // The compiler-generated versions copy each member, one by one ("memberwise").
    cout << "a: " << a.theme << ' ' << a.fontSize << '\n';
    cout << "b: " << b.theme << ' ' << b.fontSize << '\n';
    cout << "c: " << c.theme << ' ' << c.fontSize << '\n';

    // For members like string, int, vector this is exactly right.
    // For a raw POINTER member it is WRONG: both objects end up pointing at the
    // same memory (a shallow copy). Example 05 shows the bug and the fix.
    return 0;
}
