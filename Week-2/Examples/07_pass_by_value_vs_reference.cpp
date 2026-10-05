// CSCE 306 | Week 2 • Example 07: Pass by value vs pass by reference (Ch. 6)
// Build: g++ -std=c++17 -Wall -Wextra 07_pass_by_value_vs_reference.cpp -o refs

#include <iostream>
#include <string>
using namespace std;

void tryToDouble(int x)      { x *= 2; }   // works on a COPY
void reallyDouble(int& x)    { x *= 2; }   // works on the caller's variable

void swapValues(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// const reference: no copy, and the function promises not to modify it.
// This is the standard way to pass strings and (later) objects.
size_t countVowels(const string& text)
{
    size_t count = 0;
    for (char c : text)
        if (string("aeiouAEIOU").find(c) != string::npos) ++count;
    return count;
}

int main()
{
    int n = 10;
    tryToDouble(n);
    cout << "after tryToDouble:  " << n << '\n';   // 10
    reallyDouble(n);
    cout << "after reallyDouble: " << n << '\n';   // 20

    int p = 1, q = 2;
    swapValues(p, q);
    cout << "after swap: p=" << p << " q=" << q << '\n';

    cout << "vowels in \"Object Oriented\": " << countVowels("Object Oriented") << '\n';
    return 0;
}
