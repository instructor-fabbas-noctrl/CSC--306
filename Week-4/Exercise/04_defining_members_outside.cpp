// CSCE 306 | Week 4 • Example 04: Defining member functions outside the class (Ch. 13.3–13.4)
// Build: g++ -std=c++17 -Wall -Wextra 04_defining_members_outside.cpp -o scope

#include <iostream>
using namespace std;

class Circle {
private:
    double radius = 0.0;
public:
    void   setRadius(double r);      // declarations (prototypes) only
    double getRadius() const;
    double getArea() const;
    double getCircumference() const { return 2 * PI * radius; }   // short ones may stay inline
    static constexpr double PI = 3.14159265358979;
};

// Definitions use the scope resolution operator  ClassName::memberName
void Circle::setRadius(double r)
{
    if (r >= 0) radius = r;
}

double Circle::getRadius() const     // const must be repeated in the definition
{
    return radius;
}

double Circle::getArea() const
{
    return PI * radius * radius;     // members are directly accessible here
}

int main()
{
    Circle c;
    c.setRadius(3.0);
    cout << "r = " << c.getRadius()
         << ", area = " << c.getArea()
         << ", circumference = " << c.getCircumference() << '\n';
    return 0;
}
