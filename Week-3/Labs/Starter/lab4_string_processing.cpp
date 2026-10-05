// CSCE 306 | Week 3 • Lab 1 Part 4: String Processing (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab4_string_processing.cpp -o lab4
//
// Implement these with std::string and <cctype>. Pass strings by const reference.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Count the words in text (words are separated by one or more spaces)
int wordCount(const string& text)
{
    // TODO
    (void)text;
    return 0;
}

// Return true if text is a palindrome, ignoring case and non-letters.
// "A man, a plan, a canal: Panama" -> true
bool isPalindrome(const string& text)
{
    // TODO
    (void)text;
    return false;
}

// Capitalize the first letter of each word, lowercase the rest. "hELLO wORLD" -> "Hello World"
string titleCase(const string& text)
{
    // TODO
    return text;
}

// Same as wordCount, but for a C-string. Do NOT convert to std::string.
int wordCountC(const char* text)
{
    // TODO  (walk the characters until '\0')
    (void)text;
    return 0;
}

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    check("wordCount 4",          wordCount("  objects   have  state too") == 4);
    check("wordCount empty 0",    wordCount("") == 0);
    check("palindrome Panama",    isPalindrome("A man, a plan, a canal: Panama"));
    check("not palindrome",       !isPalindrome("Object"));
    check("titleCase",            titleCase("hELLO wORLD of c++") == "Hello World Of C++");
    check("wordCountC 3",         wordCountC("a  bc   def ") == 3);
    return 0;
}
