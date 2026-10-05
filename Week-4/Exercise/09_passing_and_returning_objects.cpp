// CSCE 306 | Week 4 • Example 09: Passing objects to and returning objects from functions (Ch. 13)
// Build: g++ -std=c++17 -Wall -Wextra 09_passing_and_returning_objects.cpp -o passobj

#include <iostream>
using namespace std;

class Rectangle {
private:
    double width, length;
public:
    Rectangle(double w = 0, double l = 0) : width(w), length(l) {}
    double getWidth() const  { return width; }
    double getLength() const { return length; }
    double getArea() const   { return width * length; }
    void   scale(double f)   { width *= f; length *= f; }
};

// By value: the function gets a COPY (changes are lost; copying may be expensive)
void scaleCopy(Rectangle r)          { r.scale(2); }

// By reference: the function changes the caller's object
void scaleInPlace(Rectangle& r)      { r.scale(2); }

// By const reference: no copy, no changes -- the default for read-only object params
bool isSquare(const Rectangle& r)    { return r.getWidth() == r.getLength(); }

// Returning an object by value (the compiler elides the copy in modern C++)
Rectangle larger(const Rectangle& a, const Rectangle& b)
{
    return (a.getArea() >= b.getArea()) ? a : b;
}

Rectangle makeSquare(double side)    { return Rectangle(side, side); }

int main()
{
    Rectangle r(3, 4);
    scaleCopy(r);
    cout << "after scaleCopy:    " << r.getWidth() << "x" << r.getLength() << '\n';
    scaleInPlace(r);
    cout << "after scaleInPlace: " << r.getWidth() << "x" << r.getLength() << '\n';

    Rectangle sq = makeSquare(5);
    cout << boolalpha << "sq is square? " << isSquare(sq) << '\n';
    Rectangle big = larger(r, sq);
    cout << "larger area: " << big.getArea() << '\n';
    return 0;
}
