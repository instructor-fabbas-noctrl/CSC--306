// CSCE 306 | Week 7 • Lab Part 5: Class hierarchy -- Shape -> Rectangle -> Square, Shape -> Circle (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab5_shape_hierarchy_solution.cpp -o lab5

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

class Rectangle : public Shape {
protected:
    double width, height;
    // Lets a derived class (Square) supply its own name while reusing Rectangle's data.
    Rectangle(const string& n, double w, double h) : Shape(n), width(w), height(h) {}
public:
    Rectangle(double w, double h) : Rectangle("Rectangle", w, h) {}
    double area() const      { return width * height; }
    double perimeter() const { return 2 * (width + height); }
    string describe() const
    {
        ostringstream out;
        out << getName() << ' ' << width << " x " << height << ", area " << area();
        return out.str();
    }
};

class Square : public Rectangle {
public:
    explicit Square(double side) : Rectangle("Square", side, side) {}
    // describe() is inherited and already prints the right name -- no redefinition needed.
};

class Circle : public Shape {
private:
    double radius;
public:
    static constexpr double PI = 3.14159265358979;
    explicit Circle(double r) : Shape("Circle"), radius(r) {}
    double area() const      { return PI * radius * radius; }
    double perimeter() const { return 2 * PI * radius; }
    string describe() const
    {
        ostringstream out;
        out << getName() << " r=" << radius << ", area " << fixed << setprecision(2) << area();
        return out.str();
    }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
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
    return 0;
}
