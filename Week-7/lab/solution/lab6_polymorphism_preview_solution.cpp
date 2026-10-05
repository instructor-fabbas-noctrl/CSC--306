// CSCE 306 | Week 7 • Lab Part 6: Polymorphism preview -- virtual, override, slicing (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab6_polymorphism_preview_solution.cpp -o lab6
//
// STEP 1: With area() virtual, describe() calls the derived area() -- but kind() was
//         ALSO called from inside describe(), so kind() must be virtual too or every
//         line still says "shape". A non-virtual call is bound at compile time inside
//         Shape::describe, where 'this' is a Shape*.
// STEP 2: Passing a Circle BY VALUE to a Shape parameter copies only the Shape part
//         (the object is "sliced"); the copy's dynamic type is Shape, so virtual calls
//         reach Shape's versions. A const Shape& refers to the original Circle.
// STEP 3: delete through a Shape* runs only ~Shape unless ~Shape is virtual -- the
//         Circle part is never destroyed (undefined behavior; leaks in real code).
// STEP 4: unique_ptr<Shape> calls delete for us through the virtual destructor.

#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const { return 0.0; }
    virtual string kind() const { return "shape"; }
    string describe() const                 // non-virtual "template" that calls virtuals
    {
        ostringstream out;
        out << kind() << " area " << fixed << setprecision(2) << area();
        return out.str();
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() const override { return w * h; }
    string kind() const override { return "Rectangle"; }
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double radius) : r(radius) {}
    ~Circle() override { cout << "~Circle\n"; }
    double area() const override { return 3.14159265358979 * r * r; }
    string kind() const override { return "Circle"; }
};

void printByRef(const Shape& s) { cout << "by reference: " << s.describe() << '\n'; }

int main()
{
    Rectangle rect(3, 4);
    Circle    unit(1);
    Shape* shapes[] = {&rect, &unit};
    for (Shape* s : shapes) cout << s->describe() << '\n';
    printByRef(unit);

    {
        vector<unique_ptr<Shape>> owned;
        owned.push_back(make_unique<Circle>(1));
        double total = rect.area();
        for (const auto& s : owned) total += s->area();
        cout << fixed << setprecision(2);
        owned.clear();                           // unique_ptr deletes the Circle -> ~Circle
        cout << "total area " << total << '\n';
    }
    return 0;                                    // 'unit' destroyed here -> second ~Circle
}
