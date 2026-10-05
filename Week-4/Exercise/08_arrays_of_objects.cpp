// CSCE 306 | Week 4 • Example 08: Arrays and vectors of objects (Ch. 13.12)
// Build: g++ -std=c++17 -Wall -Wextra 08_arrays_of_objects.cpp -o objarr

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle() : radius(1.0) {}                 // needed for "Circle arr[3];"
    explicit Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }
    double getArea() const   { return 3.14159265358979 * radius * radius; }
};

int main()
{
    Circle defaults[3];                        // default ctor runs 3 times
    Circle sized[3] = {Circle(1.5), Circle(2.0), Circle(3.5)};   // initializer list

    for (const Circle& c : defaults) cout << c.getRadius() << ' ';
    cout << '\n';
    for (int i = 0; i < 3; ++i)
        cout << "sized[" << i << "] area = " << sized[i].getArea() << '\n';

    // vector of objects grows as needed
    vector<Circle> circles;
    for (double r = 0.5; r <= 2.0; r += 0.5) circles.emplace_back(r);   // constructs in place
    double total = 0;
    for (const Circle& c : circles) total += c.getArea();
    cout << circles.size() << " circles, total area " << total << '\n';
    return 0;
}
