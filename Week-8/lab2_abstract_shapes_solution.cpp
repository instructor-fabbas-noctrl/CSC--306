// CSCE 306 - Week 8 - Lab 2: Abstract base class & pure virtual functions
// Build: g++ -std=c++17 -Wall -Wextra lab2_abstract_shapes.cpp -o lab2
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape {
    string name;
public:
    explicit Shape(const string& n) : name(n) {}
    virtual ~Shape() = default;
    //@@BEGIN Step 1: declare two PURE virtual functions: area() and perimeter() (both const, return double)
    //@@STUB virtual double area() const { return 0; }
    //@@STUB virtual double perimeter() const { return 0; }
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    //@@END
    string getName() const { return name; }
    void print() const {   // non-virtual "template" method that uses the virtual ones
        cout << getName() << ": area=" << area() << " perimeter=" << perimeter() << endl;
    }
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double radius) : Shape("Circle"), r(radius) {}
    //@@BEGIN Step 2: override area() (pi*r*r) and perimeter() (2*pi*r). Use M_PI from <cmath>.
    //@@STUB double area() const override { return 0; }
    //@@STUB double perimeter() const override { return 0; }
    double area() const override { return M_PI * r * r; }
    double perimeter() const override { return 2 * M_PI * r; }
    //@@END
};

class Rectangle : public Shape {
protected:
    double w, h;
public:
    Rectangle(double width, double height, const string& n = "Rectangle") : Shape(n), w(width), h(height) {}
    //@@BEGIN Step 3: override area() and perimeter() for Rectangle
    //@@STUB double area() const override { return 0; }
    //@@STUB double perimeter() const override { return 0; }
    double area() const override { return w * h; }
    double perimeter() const override { return 2 * (w + h); }
    //@@END
};

//@@BEGIN Step 4: write class Square derived from Rectangle (constructor takes ONE side, passes it as width AND height, name "Square"). No new overrides needed - why?
//@@STUB class Square : public Rectangle { public: explicit Square(double side) : Rectangle(side, 1, "Square") {} };  // BUG: fix me
class Square : public Rectangle {
public:
    explicit Square(double side) : Rectangle(side, side, "Square") {}
};
//@@END

int main() {
    // Shape s("x");   // Step 5: uncomment - read the compiler error, then comment it out again.
    Circle c(1.5);
    Rectangle r(3, 4);
    Square sq(2.5);
    c.print();
    r.print();
    sq.print();

    Shape* ptrs[] = { &c, &r, &sq };
    double total = 0;
    for (Shape* p : ptrs) total += p->area();
    cout << "Total area = " << total << endl;
    return 0;
}
