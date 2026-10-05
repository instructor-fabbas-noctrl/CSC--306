// CSCE 306 — Object-Oriented Software Development | Fall 2026
// Week 4 • Example 01: Your first class -- Rectangle (Ch. 13.1–13.3)
// Build: g++ -std=c++17 -Wall -Wextra 01_first_class.cpp -o rect

#include <iostream>
using namespace std;

// A class bundles DATA (member variables) with BEHAVIOR (member functions).
class Rectangle {
private:                       // only Rectangle's own member functions can touch these
    double width  = 0.0;
    double length = 0.0;

public:                        // the INTERFACE: what the rest of the program may use
    void setWidth(double w)  { if (w >= 0) width = w; }
    void setLength(double l) { if (l >= 0) length = l; }
    double getWidth() const  { return width; }
    double getLength() const { return length; }
    double getArea() const   { return width * length; }
};                             // <-- don't forget the semicolon after a class

int main()
{
    Rectangle box;             // an OBJECT (instance) of class Rectangle
    box.setWidth(10.0);
    box.setLength(5.0);
    cout << "Width:  " << box.getWidth()  << '\n'
         << "Length: " << box.getLength() << '\n'
         << "Area:   " << box.getArea()   << '\n';

    box.setWidth(-3);          // rejected by the mutator -- object stays valid
    cout << "After setWidth(-3), width is still " << box.getWidth() << '\n';

    // box.width = -3;         // ERROR: 'width' is private
    Rectangle other;           // every object has its own copy of the data
    other.setWidth(2); other.setLength(2);
    cout << "other area: " << other.getArea() << ", box area: " << box.getArea() << '\n';
    return 0;
}
