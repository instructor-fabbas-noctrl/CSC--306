// CSCE 306 | Week 7 • Example 08: Polymorphism preview -- virtual, override, slicing (Ch. 15.6)
// Build: g++ -std=c++17 -Wall -Wextra 08_polymorphism_preview.cpp -o poly
// Full treatment (abstract classes, pure virtual) in Week 8.

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;                       // virtual destructor: REQUIRED for polymorphic bases
    virtual double area() const { return 0.0; }       // virtual: decided at RUN time
    string label() const        { return "shape"; }   // non-virtual: decided at compile time
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double radius) : r(radius) {}
    double area() const override { return 3.14159265358979 * r * r; }  // override: compiler checks it
    string label() const         { return "circle"; }
};

class Square : public Shape {
    double s;
public:
    explicit Square(double side) : s(side) {}
    double area() const override { return s * s; }
    string label() const         { return "square"; }
};

void report(const Shape& sh)          // by reference: dynamic binding works
{
    cout << "  " << sh.label() << " area " << sh.area() << '\n';
}

void reportSliced(Shape sh)           // BY VALUE: object is SLICED to a plain Shape
{
    cout << "  sliced area " << sh.area() << '\n';
}

int main()
{
    Circle c(1.0);
    Square q(2.0);

    cout << "Through const Shape&:\n";
    report(c);                        // area() -> Circle::area, label() -> Shape::label
    report(q);

    cout << "By value (slicing):\n";
    reportSliced(c);                  // 0 -- the Circle part was cut off

    cout << "Heterogeneous container:\n";
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(2.0));
    shapes.push_back(make_unique<Square>(3.0));
    double total = 0.0;
    for (const auto& s : shapes) total += s->area();
    cout << "  total area " << total << '\n';
    return 0;                         // unique_ptr deletes each Shape through the virtual dtor
}
