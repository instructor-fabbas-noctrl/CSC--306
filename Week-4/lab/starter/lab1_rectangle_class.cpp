// CSCE 306 | Week 4 • Lab Part 1: Rectangle class skeleton (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab1_rectangle_class.cpp -o lab1
//
// UML:
//   +----------------------------------+
//   | Rectangle                        |
//   +----------------------------------+
//   | - width : double                 |
//   | - length : double                |
//   +----------------------------------+
//   | + setWidth(w : double) : bool    |   returns false (and changes nothing) if w <= 0
//   | + setLength(l : double) : bool   |   returns false (and changes nothing) if l <= 0
//   | + getWidth() : double  {query}   |
//   | + getLength() : double {query}   |
//   | + getArea() : double   {query}   |
//   | + getPerimeter() : double {query}|
//   | + isSquare() : bool    {query}   |
//   +----------------------------------+
// {query} means the member function is const.
// Members should default to 1.0 so a new Rectangle is always valid.
// Define the longer functions OUTSIDE the class using Rectangle::

#include <iostream>
#include <string>
using namespace std;

class Rectangle {
    // TODO 1: private data members with default member initializers

public:
    // TODO 2: declare the seven public member functions (const where appropriate)
};

// TODO 3: define the member functions here using Rectangle::


// ----------------------------- test driver -----------------------------
// Uncomment the body of main() once your class is complete.
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*
    Rectangle r;
    check("default 1x1",           r.getWidth() == 1.0 && r.getLength() == 1.0);
    check("setWidth(4) true",      r.setWidth(4));
    check("setLength(2.5) true",   r.setLength(2.5));
    check("area 10",               r.getArea() == 10.0);
    check("perimeter 13",          r.getPerimeter() == 13.0);
    check("setWidth(-1) false",    !r.setWidth(-1));
    check("width unchanged",       r.getWidth() == 4.0);
    check("not square",            !r.isSquare());
    r.setLength(4);
    check("now square",            r.isSquare());
    const Rectangle& cr = r;
    check("const access compiles", cr.getArea() == 16.0);
    */
    return 0;
}
