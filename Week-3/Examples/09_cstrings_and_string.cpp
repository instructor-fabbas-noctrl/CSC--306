// CSCE 306 | Week 3 • Example 09: Characters, C-strings, and std::string (Ch. 10)
// Build: g++ -std=c++17 -Wall -Wextra 09_cstrings_and_string.cpp -o strings

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    // ----- C-string: char array terminated by '\0' -----
    char cstr[20] = "Hello";        // 5 chars + '\0', rest zero
    cout << "strlen(cstr) = " << strlen(cstr) << '\n';
    strncat(cstr, ", C!", sizeof(cstr) - strlen(cstr) - 1);   // careful with sizes
    cout << cstr << '\n';
    cout << "strcmp(\"abc\",\"abd\") = " << strcmp("abc", "abd") << "  (<0 means less)\n";

    // ----- Character functions from <cctype> -----
    int upper = 0, digits = 0;
    for (char c : string("CSCE306 Fall")) {
        if (isupper(static_cast<unsigned char>(c))) ++upper;
        if (isdigit(static_cast<unsigned char>(c))) ++digits;
    }
    cout << "uppercase: " << upper << ", digits: " << digits << '\n';

    // ----- std::string: manages its own memory; prefer it -----
    string course = "Object-Oriented";
    course += " Software";                       // concatenation
    cout << course << " (" << course.length() << " chars)\n";
    cout << "find(\"Software\") = " << course.find("Software") << '\n';
    cout << "substr(0, 6)     = " << course.substr(0, 6) << '\n';
    if (course == "Object-Oriented Software") cout << "== compares contents\n";

    // Converting between the two worlds
    const char* raw = course.c_str();            // string -> C-string (read-only)
    string back(raw);                            // C-string -> string
    cout << "stoi(\"306\") + 1 = " << stoi("306") + 1 << ", to_string(3.5) = " << to_string(3.5) << '\n';
    (void)back;
    return 0;
}
