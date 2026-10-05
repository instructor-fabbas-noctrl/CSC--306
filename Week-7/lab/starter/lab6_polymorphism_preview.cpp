// CSCE 306 | Week 7 • Lab Part 6: Polymorphism preview -- virtual, override, slicing (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab6_polymorphism_preview.cpp -o lab6
//
// This file compiles and runs as given, but the output is WRONG: every shape reports
// area 0 and "shape". Your job, one step at a time (run after each step):
//
// STEP 1: Make area() and describe() in Shape 'virtual'. Add 'override' in each
//         derived class. Run: which lines are fixed? Which one is still wrong, and why?
// STEP 2: printByValue takes a Shape BY VALUE. Explain slicing in a comment, then change
//         it to printByRef(const Shape&), print "by reference: ", and observe the difference.
// STEP 3: Add a virtual destructor to Shape. Uncomment the "~Circle" line and the
//         raw-pointer block. Without the virtual destructor, ~Circle would NOT run.
// STEP 4: Replace the raw-pointer block with vector<unique_ptr<Shape>> (no delete needed)
//         and print the total area.
//
// Expected final output:
//   Rectangle area 12.00
//   Circle area 3.14
//   by reference: Circle area 3.14
//   ~Circle
//   total area 15.14
//   ~Circle

#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Shape {
public:
    double area() const     { return 0.0; }
    string describe() const
    {
        ostringstream out;
        out << kind() << " area " << fixed << setprecision(2) << area();
        return out.str();
    }
    string kind() const     { return "shape"; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() const { return w * h; }
    string kind() const { return "Rectangle"; }
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double radius) : r(radius) {}
    // ~Circle() { cout << "~Circle\n"; }        // STEP 3
    double area() const { return 3.14159265358979 * r * r; }
    string kind() const { return "Circle"; }
};

void printByValue(Shape s) { cout << "by value: " << s.describe() << '\n'; }   // STEP 2

int main()
{
    Rectangle rect(3, 4);
    Circle    unit(1);
    Shape* shapes[] = {&rect, &unit};
    for (Shape* s : shapes) cout << s->describe() << '\n';
    printByValue(unit);

    // STEP 3 raw-pointer block:
    // Shape* p = new Circle(1);
    // cout << "total area " << fixed << setprecision(2) << rect.area() + p->area() << '\n';
    // delete p;

    // STEP 4: replace the block above with vector<unique_ptr<Shape>>
    return 0;
}
