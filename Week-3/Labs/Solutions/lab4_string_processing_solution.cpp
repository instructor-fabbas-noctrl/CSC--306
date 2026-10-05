// CSCE 306 | Week 3 • Lab 1 Part 4: String Processing (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab4_string_processing_solution.cpp -o lab4

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int wordCount(const string& text)
{
    int count = 0;
    bool inWord = false;
    for (char c : text) {
        if (c != ' ' && !inWord) { ++count; inWord = true; }   // start of a new word
        else if (c == ' ')       { inWord = false; }
    }
    return count;
}

bool isPalindrome(const string& text)
{
    string letters;
    for (char c : text)
        if (isalpha(static_cast<unsigned char>(c)))
            letters += static_cast<char>(tolower(static_cast<unsigned char>(c)));
    for (size_t i = 0, j = letters.size(); i + 1 < j; ++i, --j)
        if (letters[i] != letters[j - 1]) return false;
    return true;
}

string titleCase(const string& text)
{
    string result = text;
    bool startOfWord = true;
    for (char& c : result) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (c == ' ') { startOfWord = true; continue; }
        c = static_cast<char>(startOfWord ? toupper(uc) : tolower(uc));
        startOfWord = false;
    }
    return result;
}

int wordCountC(const char* text)
{
    int count = 0;
    bool inWord = false;
    for (const char* p = text; *p != '\0'; ++p) {
        if (*p != ' ' && !inWord) { ++count; inWord = true; }
        else if (*p == ' ')       { inWord = false; }
    }
    return count;
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
