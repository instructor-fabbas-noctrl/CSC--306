// CSCE 306 | Week 4 • Lab Part 4: Passing and returning objects -- Point2D (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab4_passing_objects.cpp -o lab4
//
// The Point2D class is GIVEN. Write the four NON-member functions below.
// Choose the correct parameter style for each one:
//     const Point2D&   (read only)     Point2D&   (modify caller's object)
// and say in a comment WHY you chose it.

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Point2D {
private:
    double x, y;
public:
    Point2D(double xv = 0.0, double yv = 0.0) : x(xv), y(yv) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void   setX(double v) { x = v; }
    void   setY(double v) { y = v; }
};

// TODO 1: distance between two points  sqrt((x2-x1)^2 + (y2-y1)^2)
// double distance(... a, ... b)

// TODO 2: return a NEW Point2D halfway between a and b
// Point2D midpoint(... a, ... b)

// TODO 3: shift the CALLER's point by (dx, dy); returns nothing
// void translate(... p, double dx, double dy)

// TODO 4: return a copy of the point farthest from the origin (0,0).
//         If the vector is empty, return Point2D() (the origin).
// Point2D farthestFromOrigin(const vector<Point2D>& pts)

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }
bool near(double a, double b) { return fabs(a - b) < 1e-9; }

int main()
{
    /*  Uncomment when ready
    Point2D a(0, 0), b(3, 4);
    check("distance 5",               near(distance(a, b), 5.0));
    Point2D m = midpoint(a, b);
    check("midpoint (1.5, 2)",        near(m.getX(), 1.5) && near(m.getY(), 2.0));
    translate(a, -2, 7);
    check("translate a -> (-2, 7)",   near(a.getX(), -2) && near(a.getY(), 7));
    vector<Point2D> pts = {{1, 1}, {-6, 2}, {3, -4}};
    Point2D far = farthestFromOrigin(pts);
    check("farthest (-6, 2)",         near(far.getX(), -6) && near(far.getY(), 2));
    check("empty -> origin",          near(farthestFromOrigin({}).getX(), 0));
    */
    return 0;
}
