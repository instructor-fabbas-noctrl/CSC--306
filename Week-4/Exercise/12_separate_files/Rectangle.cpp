// CSCE 306 | Week 4 • Example 12: Rectangle.cpp -- the IMPLEMENTATION
// Clients never need to see this file; they only #include "Rectangle.h".
#include "Rectangle.h"

Rectangle::Rectangle() : width(1.0), length(1.0) {}

Rectangle::Rectangle(double w, double l) : width(1.0), length(1.0)
{
    setWidth(w);      // reuse validation logic
    setLength(l);
}

void Rectangle::setWidth(double w)  { if (w > 0) width = w; }
void Rectangle::setLength(double l) { if (l > 0) length = l; }

double Rectangle::getArea() const      { return width * length; }
double Rectangle::getPerimeter() const { return 2 * (width + length); }
