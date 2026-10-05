// CSCE 306 | Week 4 • Lab Part 5: Composition -- Student has an Address and a Date (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab5_student_address.cpp -o lab5
//
// UML (◆ = composition: the parts are created and destroyed with the Student)
//
//   Student ◆——— Address          Student ◆——— Date (enrolled)
//
//   Address: street, city, state, zip           + toString() const : string
//   Date:    month, day, year (validate: month 1-12, day 1-31; else 1/1/2026)
//                                               + toString() const : string  "M/D/YYYY"
//   Student: name, id, home : Address, enrolled : Date
//            + Student(name, id, home, enrolled)       (initializer list!)
//            + moveTo(newHome : const Address&)
//            + print() const
//
// Expected output of the provided main():
//   Ada Lovelace (#1001), enrolled 8/24/2026
//     Home: 30 N Brainard St, Naperville, IL 60540
//   Grace Hopper (#1002), enrolled 1/1/2026
//     Home: 1 Main St, Geneva, IL 60134
//   -- after move --
//   Grace Hopper (#1002), enrolled 1/1/2026
//     Home: 450 S Washington St, Naperville, IL 60540

#include <iostream>
#include <string>
using namespace std;

// TODO 1: class Address

// TODO 2: class Date (with validation in the constructor)

// TODO 3: class Student (composition: Address and Date are data members)

int main()
{
    /*  Uncomment when ready
    Student ada("Ada Lovelace", 1001,
                Address("30 N Brainard St", "Naperville", "IL", "60540"),
                Date(8, 24, 2026));
    Student grace("Grace Hopper", 1002,
                  Address("1 Main St", "Geneva", "IL", "60134"),
                  Date(13, 40, 2026));                 // invalid -> 1/1/2026
    ada.print();
    grace.print();
    cout << "-- after move --\n";
    grace.moveTo(Address("450 S Washington St", "Naperville", "IL", "60540"));
    grace.print();
    */
    return 0;
}
