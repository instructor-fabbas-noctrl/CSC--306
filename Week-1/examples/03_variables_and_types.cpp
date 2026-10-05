// CSCE 306 | Week 1 • Example 03: Variables and fundamental data types
// Build: g++ -std=c++17 -Wall -Wextra 03_variables_and_types.cpp -o types

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int    credits   = 4;          // whole numbers
    double gpa       = 3.67;       // floating point (prefer double over float)
    char   section   = 'A';        // single character, single quotes
    bool   isEnrolled = true;      // true / false
    string course    = "CSCE 306"; // std::string lives in <string>, double quotes

    // Brace (uniform) initialization -- C++11 and later. It refuses narrowing:
    int students{17};
    // int bad{3.9};   // ERROR: narrowing double -> int is rejected with braces

    cout << boolalpha;   // print bools as true/false instead of 1/0
    cout << "Course:     " << course     << '\n'
         << "Section:    " << section    << '\n'
         << "Credits:    " << credits    << '\n'
         << "Students:   " << students   << '\n'
         << "Sample GPA: " << gpa        << '\n'
         << "Enrolled?   " << isEnrolled << '\n';

    // Assignment changes the stored value; the type never changes.
    credits = credits + 1;
    cout << "After credits = credits + 1 -> " << credits << '\n';
    return 0;
}
