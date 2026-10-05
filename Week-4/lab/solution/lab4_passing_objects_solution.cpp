// CSCE 306 | Week 4 • Lab Part 4: Passing and returning objects -- Point2D (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab4_passing_objects_solution.cpp -o lab4

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

// const& : only reads both points; avoids copying
double distance(const Point2D& a, const Point2D& b)
{
    double dx = b.getX() - a.getX();
    double dy = b.getY() - a.getY();
    return sqrt(dx * dx + dy * dy);
}

// const& in, return BY VALUE: the result is a brand-new object
Point2D midpoint(const Point2D& a, const Point2D& b)
{
    return Point2D((a.getX() + b.getX()) / 2, (a.getY() + b.getY()) / 2);
}

// non-const & : must modify the caller's object
void translate(Point2D& p, double dx, double dy)
{
    p.setX(p.getX() + dx);
    p.setY(p.getY() + dy);
}

// return by value -- NEVER return a reference to a local object
Point2D farthestFromOrigin(const vector<Point2D>& pts)
{
    if (pts.empty()) return Point2D();
    const Point2D origin;
    Point2D best = pts[0];
    for (const Point2D& p : pts)
        if (distance(origin, p) > distance(origin, best)) best = p;
    return best;
}

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }
bool near(double a, double b) { return fabs(a - b) < 1e-9; }

int main()
{
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
    return 0;
}
