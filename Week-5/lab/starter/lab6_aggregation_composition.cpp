// CSCE 306 | Week 5 • Lab Part 6: Aggregation vs composition -- Course and Student (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab6_aggregation_composition.cpp -o lab6
//
// UML:
//   Course ◆——— 1 Room            (composition: a Course owns its Room record)
//   Course ◇——— 0..* Student      (aggregation: Students exist independently;
//                                  a Student may be in many Courses)
//
// Implement Course:
//   Course(code, building, roomNumber, capacity)  -- builds its Room member
//   bool enroll(Student* s)   -- false if s is nullptr, already enrolled, or room is full
//   bool drop(int studentId)  -- false if not enrolled
//   int  enrolledCount() const
//   void printRoster() const  -- see expected output
// Course must NOT delete any Student (it does not own them).
//
// Expected output:
//   enroll Barbara when full -> false
//   enroll Ada twice -> false
//   CSCE 306 @ Wentz 156 (3/3)
//     1001 Ada
//     1003 Alan
//     1004 Barbara
//   CSCE 310 @ Wentz 110 (1/30)
//     1001 Ada
//   Ada is still enrolled in 2 course(s)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Room {
private:
    string building;
    int    number;
    int    capacity;
public:
    Room(const string& b, int n, int cap) : building(b), number(n), capacity(cap) {}
    int    getCapacity() const { return capacity; }
    string toString() const    { return building + " " + to_string(number); }
};

class Student {
private:
    int    id;
    string name;
    int    courseCount = 0;
public:
    Student(int i, const string& n) : id(i), name(n) {}
    int    getId() const    { return id; }
    string getName() const  { return name; }
    int    getCourseCount() const { return courseCount; }
    void   joinedCourse()   { ++courseCount; }
    void   leftCourse()     { if (courseCount > 0) --courseCount; }
};

class Course {
    // TODO: string code; Room room; vector<Student*> roster; + members described above
};

int main()
{
    Student ada(1001, "Ada"), grace(1002, "Grace"), alan(1003, "Alan"), barbara(1004, "Barbara");
    /*  Uncomment when ready
    Course oop("CSCE 306", "Wentz", 156, 3);
    Course ds ("CSCE 310", "Wentz", 110, 30);

    oop.enroll(&ada); oop.enroll(&grace); oop.enroll(&alan);
    cout << boolalpha << "enroll Barbara when full -> " << oop.enroll(&barbara) << '\n';
    cout << "enroll Ada twice -> " << oop.enroll(&ada) << '\n';
    oop.drop(1002);
    oop.enroll(&barbara);
    ds.enroll(&ada);

    oop.printRoster();
    ds.printRoster();
    cout << ada.getName() << " is still enrolled in " << ada.getCourseCount() << " course(s)\n";
    */
    (void)ada; (void)grace; (void)alan; (void)barbara;
    return 0;
}
