// CSCE 306 | Week 1 • Example 02: Output with cout and escape sequences
// Build: g++ -std=c++17 -Wall -Wextra 02_cout_and_escapes.cpp -o cout_demo

#include <iostream>
using namespace std;   // acceptable in small .cpp programs; NEVER in a header file

int main()
{
    // The << operator can be chained; each piece is sent to the stream in order.
    cout << "Course: " << "CSCE " << 306 << '\n';

    // Common escape sequences
    cout << "Tab:\t[" << "x" << "]\n";
    cout << "Quote: \"OOP\" is the theme\n";
    cout << "Backslash: C:\\Users\\student\n";

    // A multi-line message built from adjacent string literals (concatenated at compile time)
    cout << "Line one\n"
            "Line two\n"
            "Line three\n";
    return 0;
}
