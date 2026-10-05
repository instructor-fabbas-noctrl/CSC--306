// CSCE 306 | Week 7 • Lab Part 5: Class hierarchy -- Shape -> Rectangle -> Square, Shape -> Circle (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab5_shape_hierarchy.cpp -o lab5
//
//                 Shape          - name : string (protected)
//                   ^            + Shape(name)   + getName() : string {query}
//           +-------+-------+    + describe() : string {query}  -> "<name>"
//       Rectangle         Circle
//           ^
//         Square
//
// Rectangle(width, height)  name "Rectangle";  area(), perimeter()
//                            describe() -> "Rectangle 3 x 4, area 12"   (redefine; reuse getName())
// Square(side)              IS-A Rectangle with width == height; name "Square"
//                            describe() -> "Square 5 x 5, area 25"     (hint: protected ctor
//                            Rectangle(name, w, h) lets Square pass its own name up)
// Circle(radius)            name "Circle";  area() = PI r^2, perimeter() = 2 PI r
//                            describe() -> "Circle r=1.5, area 7.07"   (2 decimals)
//
// Do NOT use 'virtual' yet -- that is Lab Part 6.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class Shape {
protected:
    string name;
public:
    explicit Shape(const string& n) : name(n) {}
    string getName() const  { return name; }
    string describe() const { return name; }
};

// TODO: Rectangle, Square, Circle

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    Rectangle r(3, 4);
    Square    s(5);
    Circle    c(1.5);
    check("rect area 12",        r.area() == 12);
    check("rect perimeter 14",   r.perimeter() == 14);
    check("rect describe",       r.describe() == "Rectangle 3 x 4, area 12");
    check("square is rectangle", s.area() == 25 && s.perimeter() == 20);
    check("square describe",     s.describe() == "Square 5 x 5, area 25");
    check("circle describe",     c.describe() == "Circle r=1.5, area 7.07");
    const Shape& asShape = s;
    check("base describe = name only", asShape.describe() == "Square");
    */
    return 0;
}
