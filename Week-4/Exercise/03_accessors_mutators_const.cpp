// CSCE 306 | Week 4 • Example 03: Accessors, mutators, and const member functions (Ch. 13.3)
// Build: g++ -std=c++17 -Wall -Wextra 03_accessors_mutators_const.cpp -o const

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int    pages = 0;

public:
    // Mutators ("setters") change state -- NOT const
    void setTitle(const string& t) { if (!t.empty()) title = t; }
    void setPages(int p)           { if (p > 0) pages = p; }

    // Accessors ("getters") only read state -- mark them const
    string getTitle() const { return title; }
    int    getPages() const { return pages; }

    // A const member function cannot modify members:
    // void broken() const { pages = 0; }   // ERROR: assignment in read-only object
};

// A const reference can only call const member functions.
void describe(const Book& b)
{
    cout << '"' << b.getTitle() << "\" has " << b.getPages() << " pages\n";
    // b.setPages(10);   // ERROR: setPages is not const
}

int main()
{
    Book b;
    b.setTitle("Starting Out with C++");
    b.setPages(1200);
    describe(b);

    const Book frozen = b;   // a const object: only const members are callable
    cout << "frozen title: " << frozen.getTitle() << '\n';
    return 0;
}
