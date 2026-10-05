// CSCE 306 | Week 4 • Example 12: main.cpp -- a CLIENT of the Rectangle class
// Build (compile both .cpp files, never the .h):
//     g++ -std=c++17 -Wall -Wextra main.cpp Rectangle.cpp -o rect
// Or step by step:
//     g++ -std=c++17 -c Rectangle.cpp      -> Rectangle.o
//     g++ -std=c++17 -c main.cpp           -> main.o
//     g++ main.o Rectangle.o -o rect       -> link
#include <iostream>
#include "Rectangle.h"     // quotes = look in this project first
using namespace std;

int main()
{
    Rectangle r(4.0, 2.5);
    cout << "Area:      " << r.getArea() << '\n';
    cout << "Perimeter: " << r.getPerimeter() << '\n';
    r.setWidth(-7);        // ignored by validation
    cout << "Width:     " << r.getWidth() << '\n';
    return 0;
}
