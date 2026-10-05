// CSCE 306 | Week 7 • Example 05: Passing arguments to base class constructors (Ch. 15.3)
// Build: g++ -std=c++17 -Wall -Wextra 05_passing_args_to_base_ctor.cpp -o basector

#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    double width, length;
public:
    Rectangle(double w, double l) : width(w), length(l) {}   // NO default constructor
    double getWidth() const  { return width; }
    double getLength() const { return length; }
    double getArea() const   { return width * length; }
};

class Cube : public Rectangle {
private:
    double height;
public:
    // The base part MUST be constructed through the initializer list.
    // Without ": Rectangle(side, side)" this would not compile, because
    // Rectangle has no default constructor to fall back on.
    explicit Cube(double side) : Rectangle(side, side), height(side) {}
    double getVolume() const { return getArea() * height; }
};

class LabeledCube : public Cube {
private:
    string label;
public:
    // Each class initializes ONLY its direct base; the chain continues upward.
    LabeledCube(const string& l, double side) : Cube(side), label(l) {}
    void print() const
    {
        cout << label << ": side " << getWidth() << ", area of base " << getArea()
             << ", volume " << getVolume() << '\n';
    }
};

int main()
{
    LabeledCube box("Shipping box", 3.0);
    box.print();
    return 0;
}
