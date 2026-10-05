// CSCE 306 | Week 4 • Example 12: Interface vs. implementation -- Rectangle.h (Ch. 13.5)
// The HEADER is the interface: what clients may use. No function bodies (except trivial inline).
#ifndef RECTANGLE_H        // include guard: prevents double inclusion
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double length;

public:
    Rectangle();                          // default 1 x 1
    Rectangle(double w, double l);

    void   setWidth(double w);
    void   setLength(double l);
    double getWidth() const  { return width; }    // short accessors may stay inline
    double getLength() const { return length; }
    double getArea() const;
    double getPerimeter() const;
};

#endif // RECTANGLE_H
