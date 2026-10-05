// CSCE 306 | Week 4 • Lab Part 1: Rectangle class skeleton (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab1_rectangle_class_solution.cpp -o lab1

#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    double width  = 1.0;
    double length = 1.0;

public:
    bool   setWidth(double w);
    bool   setLength(double l);
    double getWidth() const  { return width; }
    double getLength() const { return length; }
    double getArea() const;
    double getPerimeter() const;
    bool   isSquare() const;
};

bool Rectangle::setWidth(double w)
{
    if (w <= 0) return false;
    width = w;
    return true;
}

bool Rectangle::setLength(double l)
{
    if (l <= 0) return false;
    length = l;
    return true;
}

double Rectangle::getArea() const      { return width * length; }
double Rectangle::getPerimeter() const { return 2 * (width + length); }
bool   Rectangle::isSquare() const     { return width == length; }

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
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
    return 0;
}
